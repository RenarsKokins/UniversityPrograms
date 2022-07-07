#include <iostream>
#include "program.h"
using namespace std;

SkMasivs::SkMasivs()
{
    for (int i = 0; i < 5; i++)
    {
        mas[i] = 0; // Piešķir masīva elementam 0 vērtību
    }
}

void SkMasivs::Mainit(int i, double n)
{
    if ((i >= 0) && (i < 5))
    {
        mas[i] = n; // Piešķir masīva elementam jauno skaitli
    }
    else
        cout << "Ievadiet indeksu ar vertibu no 0 lidz 4!" << endl
             << endl; // Izdod paziņojumu, ja indekss ir nepareizs
}

void SkMasivs::MainitVietam(int i)
{
    if ((i >= 0) && (i < 4))
    {
        double vecais = mas[i]; // Patur atmiņā veco masīva elementu
        mas[i] = mas[i + 1];    // Piešķir masīva elementam nākamo masīva elementu
        mas[i + 1] = vecais;    // Piešķir nākamajam elementam veco masīva elementu
    }
    else
        cout << "Ievadiet indeksu ar vertibu no 0 lidz 3!" << endl
             << endl; // Izdod paziņojumu, ja indekss ir nepareizs
}

void SkMasivs::Drukat()
{
    for (int i = 0; i < 5; i++)
    { // For cikls, kurš skaita no 0 līdz 4
        wcout << "Masīva " << i + 1 << ". elements āčēūīā ir: " << mas[i] << endl;
    }
    wcout << endl;
}

void SkMasivs::DrukatNoBeigam()
{
    for (int i = 4; i >= 0; i--)
    { // For cikls, kurš skaita no 4 līdz 0
        cout << "Masiva " << i + 1 << ". elements ir: " << mas[i] << endl;
    }
    cout << endl;
}

SkMasivs::~SkMasivs()
{
    cout << "Objekts " << mas << " ir likvidets" << endl;
}
