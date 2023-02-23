#include "Vecteur3d.h"
using namespace std;

Vecteur3d::Vecteur3d(int n, const double *tab)
{
    N = n;
    t = new double[N];
    if (tab != NULL)
        for (int i = 0; i<N; i++)  t[i] = tab[i];
    else
        for (int i = 0; i < N; i++) t[i] = 0;
}

Vecteur3d::Vecteur3d(const Vecteur3d & v)
{
    N = v.getN();
    t = new double[N];
    for (int i = 0; i < N; i++) t[i] = v[i];
}

Vecteur3d::~Vecteur3d()
{
    if (t != NULL) delete[] t;
}

double* Vecteur3d::toArray() const
{
    return t;
}

void Vecteur3d::affiche() const
{
    cout<<"(";
    for (int i = 0; i < N; i++)
        cout<<t[i]<<" ";
    cout<<")"<<endl;
}

double Vecteur3d::operator[](int i) const
{
    return t[i];
}

void Vecteur3d::setT(int i, double f)
{
    t[i] = f;
}

int Vecteur3d::getN() const
{
    return N;
}

Vecteur3d operator*(Vecteur3d const& v, double a)
{
    int n = v.getN();
    Vecteur3d ans(n);
    for (int i = 0; i < n; i++) ans.setT(i, a*v[i]);
    return ans;
}
/*Adaptation au cas où on écrit le scalaire avant le Vecteur3d*/
Vecteur3d operator*(double a, Vecteur3d const& v)
{
    return v*a;
}

Vecteur3d operator+(Vecteur3d const& v, Vecteur3d const& w)
{
    // if (v.getN() != w.getN());
    // {
    //     cout<<"Dimensions incompatibles"<<": "<<v.getN()<<" "<<w.getN()<<endl;
    //     v.affiche(); w.affiche();
    //     return Vecteur3d(v.getN());
    // }
    // else{
        int n = v.getN();
        Vecteur3d ans(n);
        for (int i = 0; i < n; i++) ans.setT(i, v[i] + w[i]);
        return ans;
    // }
}

void Vecteur3d::operator=(Vecteur3d const& v)
{
    if (N != v.getN())
    {
        if (t!=NULL) delete[] t;
        t = new double[v.getN()];
    }
    for (int i = 0; i < N; i++) setT(i, v[i]);
}

void operator+=(Vecteur3d& ans, Vecteur3d const v)
{
    for (int i = 0; i < ans.getN(); i++) ans.setT(i, ans[i]+v[i]);
}