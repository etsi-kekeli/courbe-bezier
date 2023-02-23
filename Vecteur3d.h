#pragma once
#include <iostream>

class Vecteur3d
{
    public:
        Vecteur3d(int n = 3, const double* tab = NULL);
        Vecteur3d(const Vecteur3d&);
        ~Vecteur3d();
        friend bool coincide(Vecteur3d v1, Vecteur3d v2);
        /*Cette fonction transforme un objet Vecteur3d en tableau de double*/
        double* toArray() const;
        void setT(int, double);
        int getN() const;
        /*Affichage de vecteur3d*/
        void affiche() const;
        /*Cette fonction joue le rôle de getteur des attributs x, y, z
        Elle retourne x, y ou z en fonction de l'entier en argument*/
        double operator[](int) const;
        void operator=(Vecteur3d const&);

    private:
        double* t;
        int N;
};
Vecteur3d operator*(Vecteur3d const& v, double a);
// Pour que la multiplication garde son sens si écrit le scalaire avant le Vecteur3d
Vecteur3d operator*(double a, Vecteur3d const& v);
Vecteur3d operator+(Vecteur3d const&, Vecteur3d const&);
void operator+=(Vecteur3d& , Vecteur3d const);