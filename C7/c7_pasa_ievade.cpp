/*******************************************
Renārs Kokins, rk20055

C7. Dots masīvs A(m,n), kas sastāv no veseliem skaitļiem. Atrast četrus skaitļus h,i,j,k, kas apzīmē apakšmatricu,
kuras elementu kopsumma ir vislielākā (h,i apzīmē apakšmatricas kreiso augšējo stūri, bet j,k - labo apakšējo).

Programma izveidota: 2020/11/12
Programma modificēta: 2020/11/17
*******************************************/

#include <iostream>
#include <vector>
using namespace std;

long long Sum(int a, int b, int c, int d, vector<vector<int>> &A)
{
    long long current_sum = 0;

    for (int y = b; y <= d; y++)
    { // for cikls y pozīcijai
        for (int x = a; x <= c; x++)
        {                           // for cikls x pozīcijai
            current_sum += A[x][y]; // Pieskaita summai apakšmatricas elementu
        }
    }
    return current_sum; // Atgriež pašreizējo summu
}

long long calculate_brute(int x, int y, vector<vector<int>> &A, int &h, int &i, int &j, int &k)
{
    /*
    Funkcija iziet cauri visām iespējamām apakšmatricām un patur
    vislielākās apakšmatricas summu un atrašanās vietu masīvā.
    Tā kā tā pārbauda visas iespējamās pozīcijas, tas aizņem daudz
    laika pie lielākiem masīvu izmēriem.
    */
    long long biggest_sum = A[0][0];

    for (int a = 0; a < y; a++)
    { // for cikli iziet cauri visām iespējamām apakšmatricām
        for (int b = 0; b < x; b++)
        {
            for (int c = a; c < y; c++)
            {
                for (int d = b; d < x; d++)
                {
                    long long current_sum = Sum(a, b, c, d, A); // Aprēķina apakšmatricas summu
                    if (current_sum > biggest_sum)
                    {
                        /*
                        Ja iegūtā summa apakšmatricai ir lielāka par iepriekšējo lielāko summu,
                        tad to pārraksta un izmaina h, i, j, k mainīgos, kuri apzīmē augšējo kreiso
                        un apakšējo labo stūri apakšmatricai
                        */
                        biggest_sum = current_sum;
                        h = a;
                        i = b;
                        j = c;
                        k = d;
                    }
                }
            }
        }
    }
    return biggest_sum;
}

int main()
{
    int ok = 1;
    while (ok == 1) // While cikls, kamēr lietotājs vairs nevēlas palaist programmu
    {
        int x_size, y_size, // Mainīgie, kuros glabāsies masīva lielums
            h, i, j, k;     // Mainīgie augšējo kreiso un apakšējo labo stūru glabāšanai

        cout << "Ievadiet masiva lielumu(x, y): ";
        cin >> x_size >> y_size; // Ievada izmērus masīvam

        if (x_size > 0 && y_size > 0)
        {
            vector<vector<int>> arr(y_size, vector<int>(x_size)); // Izveido vector masīvu ar ievadīto izmēru

            cout << "Ievadiet masiva elementus: ";
            for (int i = 0; i < y_size; i++)
            {
                for (int q = 0; q < x_size; q++)
                {
                    int cip;
                    cin >> cip;
                    arr[i][q] = cip; // Lietotājs ievada masīva A(y,x) elementus atsevišķi
                }
            }
            cout << endl;

            long long biggest_sum = calculate_brute(x_size, y_size, arr, h, i, j, k); // Aprēķina vislielāko apakšmatricu

            cout << endl;
            cout << "Masivaa A tika atrasta lielaka apaksmatrica ar summu "
                 << biggest_sum
                 << " sakuma pozicija (h: "
                 << h
                 << " i: "
                 << i
                 << "), beigu pozicija (j: "
                 << j
                 << " k: "
                 << k
                 << ")";
        }
        else
            cout << "Ievadiet pozitivu masiva lielumu!" << endl;

        ok = 0;
        cout << endl
             << "Vai velaties turpinat (1) vai beigt (0)?" << endl; // Paprasa lietotājam, vai viņš vēlas palaist programmu atkārtoti
        cin >> ok;
    }
    return 0;
}

/********************************************************************************************************
Ievads:
X    Y    Masīvs                                    Programmas vēlamā reakcija                                                          Rezultāts C++

3    3    10 -2 8 -23 33 5 77 -12 -34               Masivaa A tika atrasta lielaka apaksmatrica ar summu 83 sakuma                      +
                                                    pozicija (h: 0 i: 0), beigu pozicija (j: 2 k: 1)

4    3    -10 -2 8 -23 33 5 77 -12 -34 13 5 12      Masivaa A tika atrasta lielaka apaksmatrica ar summu 115 sakuma                     +
                                                    pozicija (h: 1 i: 0), beigu pozicija (j: 1 k: 2)

3    4    -4 -3 -7 -2 -56 -12 -35 -55 -1 -2 -3 -9   Masivaa A tika atrasta lielaka apaksmatrica ar summu -1 sakuma                      +
                                                    pozicija (h: 2 i: 2), beigu pozicija (j: 2 k: 2)

0    0                                              Kļūda. Masīva lielumam jābūt lielākam par 0                                         Izdod paziņojumu "Ievadiet pozitivu masiva lielumu!"

-2   3                                              Kļūda. Masīva lielumam jābūt lielākam par 0                                         Izdod paziņojumu "Ievadiet pozitivu masiva lielumu!"

*********************************************************************************************************/