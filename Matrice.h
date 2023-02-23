#pragma once
#include <iostream>
#include "Vecteur3d.h"
using namespace std;

class Matrice
{
    private:
    int N;
    double **M;

    public:
    Matrice(int n=0, double** mat=NULL);
    Matrice(Matrice const& mat);
    void operator=(Matrice const& mat);
    ~Matrice();
    double* operator[](int i);
    friend ostream& operator<<(ostream& flux, Matrice);
    void LU(Matrice& L, Matrice& U) const;
    void descente(double b[], double x[]) const;
    void montee(double b[], double x[]) const;
    bool inverse(Matrice& inv) const;
    void setM(int i, int j, double v);
    double* vect(int) const;
    Matrice transpose();
    Matrice prod(Matrice& B) const;
    void prod(Vecteur3d* const v, Vecteur3d* ans) const;
    int getN();
    void interchange(int row1, int row2, int axis = 0);
    /* La fonction précédente interchange les rangées dont les numéros sont 
    ** sont passées en paramètre suivant l'axe choisi.
    ** axis = 0 -> interchangement de lignes
    ** axis = 1 -> interchangement de colonnes
    */ 
};

void remplir(double**M, const double** mat, int N);
void remplirAvec(double**M, double m, int N);