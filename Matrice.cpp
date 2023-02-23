#include "Matrice.h"

void remplir(double**M, double**mat, int N)
{
    for (int i = 0; i < N; i++) 
        for (int j = 0; j < N; j++) M[i][j] = mat[i][j];
}

void remplirAvec(double**M, double m, int N)
{
    for (int i = 0; i < N; i++)    
        for (int j = 0; j < N; j++) M[i][j] = m;
}

Matrice::Matrice(int n, double** mat)
{
    N = n;
    if(mat == NULL && n == 0) M = mat;
    else if (n != 0)   
    {
        M = new double*[N];
        for (int i = 0; i < N; i++) M[i] = new double[N];
        if (mat != NULL) remplir(M, mat, N);
        else remplirAvec(M, 0, N);
    }
}

Matrice::Matrice(Matrice const& mat)
{
    N = mat.N;
    if(mat.M == NULL && N == 0) M = NULL;
    else if (N != 0)   
    {
        M = new double*[N];
        for (int i = 0; i < N; i++) M[i] = new double[N];
        remplir(M, mat.M, N);
    }
}

void Matrice::operator=(Matrice const& mat)
{
    if(N == 0) 
    {
        if(mat.N == 0) M = NULL;
        else
        {
            N = mat.N;
            M = new double*[N];
            for (int i = 0; i < N; i++) M[i] = new double[N];
            remplir(M, mat.M, N);
        }
    }
    else
    {
        for (int i = 0; i < N; i++) delete[] M[i];
        delete[] M;
        N = mat.N;
        M = new double*[N];
        for (int i = 0; i < N; i++) M[i] = new double[N];
        remplir(M, mat.M, N);
    }
}

double* Matrice::operator[](int i)
{
    return M[i];
}

Matrice::~Matrice()
{
    if(M != NULL)
    {
        for (int i = 0; i < N; i++)
            delete[] M[i];
        delete[] M;
    }
}

ostream& operator<<(ostream& flux, Matrice mat)
{
    for (int i=0; i<mat.N; i++)
    {
        for (int j=0; j<mat.N; j++) flux<<mat[i][j]<<"\t";
        cout<<endl;
    }
    return flux;       
}
void Matrice::setM(int i, int j, double v)
{
    M[i][j] = v;
}

void Matrice::LU(Matrice& L, Matrice& U) const
{
    Matrice copie(*this);
    for (int k = 0; k < N-1; k++)
    {
        for (int i = k+1; i < N; i++)
        {
            copie.setM(i, k, M[i][k]/M[k][k]);
            for (int j = k+1; j < N; j++)
                copie.setM(i, j, copie.M[i][j] - copie.M[i][k]*copie.M[k][j]);            
        }
    }
    // Remplissage des matrices L et U
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (i > j) L.setM(i, j, copie.M[i][j]);
            else U.setM(i, j, copie.M[i][j]);
        } 
    }
}

double* Matrice::vect(int j) const
{
    double *t = new double[N];
    for (int i = 0; i < N; i++) t[j] = M[i][j];
    return t;
}

Matrice Matrice::transpose()
{
    Matrice T(N);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) T.setM(j,i, M[i][j]);
    return T;
}

Matrice Matrice::prod(Matrice& B) const
{
    Matrice P(N);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            for (int k = 0; k < N; k++) P.setM(i,j, P.M[i][j] + M[i][k]*B.M[k][j]);
    return P;
}

void Matrice::prod(Vecteur3d* const v, Vecteur3d* ans) const
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            ans[i] += M[i][j] * v[j];
        }
    }
}

void Matrice::descente(double b[], double x[]) const
{
    x[0] = b[0];
    double s;
    for (int i = 1; i < N; i++)
    {
        s = 0;
        for (int j = 0; j < i ; j++) s += M[i][j]* x[j];
        x[i] = b[i] - s;
    }
}

void Matrice::montee(double b[], double x[]) const
{
    x[N-1] = b[N-1]/M[N-1][N-1];
    double s;
    for (int i = N -2; i >= 0; i--)
    {
        s = 0;
        for (int j = N-1; j > i; j--) s += M[i][j]* x[j];
        x[i] = (b[i] - s)/M[i][i];
    }
}

bool Matrice::inverse(Matrice& inv) const
{
    Matrice L(N),U(N);
    LU(L, U);
    double det;
    for (int i = 0; i < N; i++) det *= U[i][i];
    if (det ==  0) return false;

    Matrice b(N);
    double *x = new double[N], *y = new double[N];
    for (int i = 0; i < N; i++)
    {
        b.setM(i, i, 1.0); // Pour que b devienne la matrice identité
        L.descente(b[i], y); // L*y = b[i]
        U.montee(y, x); // Ux =  y = (L^-1)*b[i] <==> LU.x = b[i] or A = LU
        // Stockage de x dans le vecteur colonne i de l'inverse
        for (int k = 0; k < N; k++) inv.setM(k, i, x[k]);
    }
    cout<<inv;
    delete[] x;
    delete[] y;
    return true;
}

int Matrice::getN()
{
    return N;
}

void Matrice::interchange(int row1, int row2, int axis)
{
    double temp;
    if (axis == 0)
        for (int i  = 0; i < N; i++)
        {
            temp = M[row1][i];
            M[row1][i] = M[row2][i];
            M[row2][i] = temp;
        }
    else
    {
        for (int i  = 0; i < N; i++)
        {
            temp = M[i][row1];
            M[i][row1] = M[i][row2];
            M[i][row2] = temp;
        }
    }
}