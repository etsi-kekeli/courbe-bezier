#include "CourbeBezier.h"
#include "gnuplot-iostream.h"
// g++ main.cpp -std=c++11 -DWITHOUT_NUMPY -I/usr/local/include/python2.7 -lpython2.7

CourbeBezier::CourbeBezier(int deg, int dim, Vecteur pol[])
{
    degre = deg;
    dimension = dim;
    ordre = deg + 1;
    poles = new Vecteur[ordre];
    if (pol == NULL)
        for (int i = 0; i < ordre; i++)
            poles[i] = Vecteur(dim);
    else
        for (int i = 0; i < ordre; i++)
            poles[i] = pol[i];
}

CourbeBezier::CourbeBezier(int deg, int dim, double P[][3])
{
    degre = deg;
    dimension = dim;
    ordre = deg + 1;
    poles = new Vecteur[ordre];
    for (int i = 0; i < 3; i++)
        poles[i] = Vecteur(dimension, P[i]);
}

CourbeBezier::~CourbeBezier()
{
    delete[] poles;
}

CourbeBezier::CourbeBezier(CourbeBezier const &b)
{
    degre = b.degre;
    dimension = b.dimension;
    ordre = degre + 1;
    poles = new Vecteur[ordre];
    for (int i = 0; i < ordre; i++)
        poles[i] = b.poles[i];
}

void CourbeBezier::operator=(CourbeBezier const &b)
{
    degre = b.degre;
    dimension = b.dimension;
    if (ordre != b.ordre)
    {
        delete[] poles;
        ordre = b.ordre;
        poles = new Vecteur[ordre];
    }
    for (int i = 0; i < ordre; i++)
        poles[i] = b.poles[i];
}

void CourbeBezier::evalue(double t, double A[]) const
{
    Vecteur *P = new Vecteur[degre];
    for (int i = 0; i < degre; i++)
        P[i] = (1 - t) * poles[i] + t * poles[i + 1];
    for (int i = degre - 1; i >= 0; i--)
        for (int j = 0; j < i; j++)
            P[j] = (1 - t) * P[j] + t * P[j + 1];
    double *temp = P[0].toArray();
    for (int i = 0; i < 3; i++)
        A[i] = temp[i];
}

ostream &operator<<(ostream &flux, const CourbeBezier &b)
{
    flux << "Degré : " << b.degre << " dimension : " << b.dimension << endl;
    for (int i = 0; i < b.ordre; i++)
    {
        flux << "Point de contrôle " << i + 1 << " ";
        b.poles[i].affiche();
    }
    return flux;
}

void CourbeBezier::dessine()
{
    double *temp = new double[3];
    Gnuplot gp;
    gp << "set border 4095\n";
    // Calcul et formatage des coordonnées des points de la courbe
    gp << "$COURBE << EOD\n";
    for (double t = 0; t <= 1; t += 0.01)
    {
        evalue(t, temp);
        gp << to_string(temp[0]) + " " + to_string(temp[1]) + " " + to_string(temp[2]) + "\n";
    }
    delete[] temp;
    gp << "EOD\n";
    // Formatage et stokages des coordonnées des points de contrôle
    gp << "$POLES << EOD\n";
    for (int i = 0; i < ordre; i++)
    {
        gp << to_string(poles[i][0]) + " " + to_string(poles[i][1]) + " " + to_string(poles[i][2]) + "\n";
    }
    gp << "EOD\n";
    // Mise en place du graphe
    gp << "splot $POLES with points pt 7,"
       << " $COURBE with lines\n";
}