#include "ConstruitCourbe.h"
#include <math.h>

void ConstruitCourbe::construitParametre(Vecteur3d pointsControles[])
{
    /*Pour trouver les pôles on résout M.t * P = Q où M.t est la transposée de 
    la matrice M, P et Q respectivement les vecteurs pôles et points de passage*/
    Matrice invM(nbPoints), mT(nbPoints);
    Vecteur3d *V = new Vecteur3d[nbPoints];
    if(V->getN() != dimension) 
        for (int i = 0; i <  nbPoints; i++) V[i] = Vecteur3d(dimension);
    mT = M.transpose();
    bool inversible = mT.inverse(invM);
    if (inversible == false) 
    {
        cout<<"La matrice M n'est pas inversible"<<endl;
        exit(EXIT_FAILURE);
    }
    /*On copie les colonnes de Q dans un vecteur de Vecteur3d*/
    for (int i = 0; i < nbPoints; i++)
    {
        V[i] = Vecteur3d(dimension, Q[i]);
    }
    invM.prod(V, pointsControles);
    delete[] V;
}

double distanceEuclidienne(double a[], double b[], int n)
{
    double res = 0;
    for (int i = 0; i<n; i++) res += pow(a[i] - b[i], 2);
    return sqrt(res);
}

double ConstruitCourbe::evalBernstein(int i, int k, double t)
{
    if (i <= k && i > 0) return (1-t)*evalBernstein(i,k-1,t) + t*evalBernstein(i-1,k-1,t);
    else if (i == 0 && k > 0) return pow(1-t, k);
    else if (i == 0 && k == 0) return 1;
    else return 0;
}

void ConstruitCourbe::construitMatriceBernstein()
{
    double t, maxi; //maxi contientra la valeur maximale de t
    for (int i=1; i <nbPoints; i++) 
        maxi += distanceEuclidienne(Q[i-1], Q[i], dimension);
    for (int j = 0; j < nbPoints; j++)
    {
        if (j == 0) t=0;
        else t += distanceEuclidienne(Q[j-1], Q[j], dimension)/maxi;
        for (int i = 0; i < nbPoints; i++) 
        {
            M.setM(i,j, evalBernstein(i, nbPoints-1, t));
        }
    }
}

ConstruitCourbe::ConstruitCourbe(int deg, int nb, int dim, Vecteur3d* V)
{
    nbPoints = nb;
    degree = deg;
    dimension = dim;
    Q = Matrice(nbPoints);
    M = Matrice(nbPoints);
    for (int i = 0; i < nb; i++)
    {
        for (int j = 0; j < dim; j++)
        {
            Q.setM(i, j, V[i][j]);
        }
    }
    Vecteur3d *p = new Vecteur3d[nbPoints]; //Pour le stockage des pôles à calculer
    construitMatriceBernstein();
    cout<<M;
    construitParametre(p); // Calcul des pôles
    courbe = CourbeBezier(deg, dim, p);
    delete[] p;
}

CourbeBezier ConstruitCourbe::getCourbe()
{
    return courbe;
} 