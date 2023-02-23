#include "CourbeBezier.h"
#include "ConstruitCourbe.h"

int main(int argc, char const *argv[])
{
    // CourbeBezier b(3,3);
    int nbr;
    cout<<"Entrez le nombre de points : ";
    cin>>nbr;
    cin.ignore();
    Vecteur3d points[nbr], ans[nbr];
    for (int  i = 0; i < nbr; i++)
    {
        double e1, e2, e3;
        cout << "Entrez les "<<i+1<<"e coordonnées des points de la courbe"<<endl;
        cin>>e1>>e2>>e3;
        cin.ignore();
        points[i].setT(0, e1);
        points[i].setT(1, e2);
        points[i].setT(2, e3);
    }
    double x[3];
    ConstruitCourbe construction(nbr-1, nbr, 3, points);
    CourbeBezier b = construction.getCourbe();
    // CourbeBezier b = CourbeBezier(nbr-1, nbr, points);
    cout<<b;
    b.dessine();
    // double t;
    // cout<<"Entrer un t pour évaluer un point de la courbe :"<<endl;
    // cin>>t;
    // b.evalue(t, x);
    // for(int i = 0; i < 3; i++) cout<<x[i]<<" ";
    cout<<endl;
    return 0;
}