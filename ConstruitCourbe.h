#pragma once
#include "CourbeBezier.h"
#include "Matrice.h"

class ConstruitCourbe
{
private:
    int nbPoints, degree, dimension;
    Matrice M, Q; //M : Matrice du système, Q matrice des points Qi (colonnes)
    CourbeBezier courbe;
    /*Calule les coordonnées des points de contrôles de la courbe de bezier
    tels que cette courbe passe par les points Qi
    *arg <-- poles à calculer. Chaque pole est une colonne de arg si on voit arg comme une matrice*/
    void construitParametre(Vecteur3d V[]);
    double evalBernstein(int i, int k, double t);
    void construitMatriceBernstein();
public:
    ConstruitCourbe(int deg, int nb, int dim, Vecteur3d*);
    CourbeBezier getCourbe();
    
};
// Évalue la distance euclidienne entre a et b
double distanceEuclidienne(double a[], double b[], int n);
