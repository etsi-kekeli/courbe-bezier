#pragma once
#include "Vecteur3d.h"
#include "Matrice.h"
#include <iostream>
using namespace std;

class CourbeBezier
{
    public:
    CourbeBezier(int deg = 0, int dim = 0, Vecteur3d P[] = NULL);
    CourbeBezier(int, int, double P[][3]);
    CourbeBezier(CourbeBezier const&);
    ~CourbeBezier();
    /*Implémentation de l'algorithme de Casteljau. Les coordonnées du point final sont
    rangés dans le tableau A*/
    void evalue(double, double A[]) const;
    /*Fonction d'affichage des information de la courbe*/
    friend ostream& operator<<(ostream & , const CourbeBezier &);
    /*Fonction d'affichage graphique*/
    void dessine();
    void operator=(CourbeBezier const&);

    private:
    int degre, dimension, ordre;
    Vecteur3d *poles;
};