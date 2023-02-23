#pragma once
#include <iostream>

class Vecteur
{
public:
    Vecteur(int n = 3, const double *tab = NULL);
    Vecteur(const Vecteur &);
    ~Vecteur();
    friend bool coincide(Vecteur v1, Vecteur v2);
    /*Cette fonction transforme un objet Vecteur en tableau de double*/
    double *toArray() const;
    void setT(int, double);
    int getN() const;
    /*Affichage de Vecteur*/
    void affiche() const;
    /*Cette fonction joue le rôle de getteur des attributs x, y, z
    Elle retourne x, y ou z en fonction de l'entier en argument*/
    double operator[](int) const;
    void operator=(Vecteur const &);

private:
    double *t;
    int N;
};
Vecteur operator*(Vecteur const &v, double a);
// Pour que la multiplication garde son sens si écrit le scalaire avant le Vecteur
Vecteur operator*(double a, Vecteur const &v);
Vecteur operator+(Vecteur const &, Vecteur const &);
void operator+=(Vecteur &, Vecteur const);