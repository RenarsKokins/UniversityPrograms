#include "Matrica.h"
#include <iostream>
using namespace std;

Matrica::Matrica(int m, int n)
{
    mat = new int *[m];

    for (int a = 0; a < n; a++)
    {
        mat[a] = new int[n];
        for (int b = 0; b < m; b++)
        {
            this->mat[a][b] = 0;
            cout << "xx ";
        }
    }
}

Matrica::Matrica(const Matrica &obj)
{
    m = obj.m;
    n = obj.n;

    mat = new int *[m];
    for (int i = 0; i < m; ++i)
        mat[i] = new int[n];

    for (int a = 0; a < n; a++)
    {
        for (int b = 0; b < m; b++)
        {
            this->mat[a][b] = obj.mat[a][b];
        }
    }
}

int Matrica::sumrin(int r)
{
    int sum = 0;
    if (r < 0 || r > n)
        return -1;

    for (int a = 0; a < m; a++)
    {
        sum += this->mat[n][a];
    }
    return sum;
}

void Matrica::mainit(int r, int k, int v)
{
    if ((r >= 0 || r <= m) && (k >= 0 || k <= n))
    {
        mat[k][r] = v;
    }
}

Matrica::~Matrica()
{
    for (int i = 0; i < m; i++)
    {
        delete[] mat[i];
    }
    delete[] mat;
}
