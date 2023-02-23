#include "Vecteur.h"
using namespace std;

Vecteur::Vecteur(int n, const double *tab)
{
    N = n;
    t = new double[N];
    if (tab != NULL)
        for (int i = 0; i < N; i++)
            t[i] = tab[i];
    else
        for (int i = 0; i < N; i++)
            t[i] = 0;
}

Vecteur::Vecteur(const Vecteur &v)
{
    N = v.getN();
    t = new double[N];
    for (int i = 0; i < N; i++)
        t[i] = v[i];
}

Vecteur::~Vecteur()
{
    if (t != NULL)
        delete[] t;
}

double *Vecteur::toArray() const
{
    return t;
}

void Vecteur::affiche() const
{
    cout << "(";
    for (int i = 0; i < N; i++)
        cout << t[i] << " ";
    cout << ")" << endl;
}

double Vecteur::operator[](int i) const
{
    return t[i];
}

void Vecteur::setT(int i, double f)
{
    t[i] = f;
}

int Vecteur::getN() const
{
    return N;
}

Vecteur operator*(Vecteur const &v, double a)
{
    int n = v.getN();
    Vecteur ans(n);
    for (int i = 0; i < n; i++)
        ans.setT(i, a * v[i]);
    return ans;
}
/*Adaptation au cas où on écrit le scalaire avant le Vecteur*/
Vecteur operator*(double a, Vecteur const &v)
{
    return v * a;
}

Vecteur operator+(Vecteur const &v, Vecteur const &w)
{
    // if (v.getN() != w.getN());
    // {
    //     cout<<"Dimensions incompatibles"<<": "<<v.getN()<<" "<<w.getN()<<endl;
    //     v.affiche(); w.affiche();
    //     return Vecteur(v.getN());
    // }
    // else{
    int n = v.getN();
    Vecteur ans(n);
    for (int i = 0; i < n; i++)
        ans.setT(i, v[i] + w[i]);
    return ans;
    // }
}

void Vecteur::operator=(Vecteur const &v)
{
    if (N != v.getN())
    {
        if (t != NULL)
            delete[] t;
        t = new double[v.getN()];
    }
    for (int i = 0; i < N; i++)
        setT(i, v[i]);
}

void operator+=(Vecteur &ans, Vecteur const v)
{
    for (int i = 0; i < ans.getN(); i++)
        ans.setT(i, ans[i] + v[i]);
}