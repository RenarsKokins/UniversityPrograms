/*******************************************
Renārs Kokins, rk20055

C7. Dots masīvs A(m,n), kas sastāv no veseliem skaitļiem. Atrast četrus skaitļus h,i,j,k, kas apzīmē apakšmatricu,
kuras elementu kopsumma ir vislielākā (h,i apzīmē apakšmatricas kreiso augšējo stūri, bet j,k - labo apakšējo).

Programma izveidota: 2020/11/03
*******************************************/

#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

int ok = 1, h, i, j, k; // mainīgais while ciklam, mainīgie augšējo kreiso un apakšējo labo stūru glabāšanai
long long biggest_sum;  // Mainīgias, kurā glabāsies vislielākā apakšmatricu summa
vector<vector<int>> A;  // Masīvs, kurā meklēs apakšmatricu

void Sum(int a, int b, int c, int d)
{
    long long current_sum = 0;

    for (int y = b; y <= d; y++)
    { // for cikls y pozīcijai
        for (int x = a; x <= c; x++)
        {                           // for cikls x pozīcijai
            current_sum += A[x][y]; // Pieskaita summai apakšmatricas elementu
        }
    }

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

void calculate_brute(int x, int y)
{
    /*
    Funkcija iziet cauri visām iespējamām apakšmatricām un patur
    vislielākās apakšmatricas summu un atrašanās vietu masīvā.
    Tā kā tā pārbauda visas iespējamās pozīcijas, tas aizņem daudz
    laika pie lielākiem masīvu izmēriem.
    */

    for (int a = 0; a < y; a++)
    { // for cikli iziet cauri visām iespējamām apakšmatricām.
        for (int b = 0; b < x; b++)
        {
            for (int c = a; c < y; c++)
            {
                for (int d = b; d < x; d++)
                {
                    Sum(a, b, c, d); // Aprēķina apakšmatricas summu
                }
            }
            cout << A[a][b] << " "; // Izvada masīva elementus, lai attēlotu masīvu
        }
        cout << endl;
    }
}

void init_array(int s, int x, int y)
{
    srand(s);                                           // Inicializē nejaušus skaitļus ar ievadīto sēklu
    vector<vector<int>> tukss_array(y, vector<int>(x)); // Izveido vector masīvu ar ievadīto izmēru
    A = tukss_array;                                    // Pārveido masīva izmēru

    for (int a = 0; a < y; a++)
    { // for cikli iziet cauri visiem A masīva elementiem
        for (int b = 0; b < x; b++)
        {
            A[a][b] = (rand() % 200) - 100; // Pievieno masīvam nejaušu skaitli intervālā [-100, 100]
        }
    }
}

int main()
{
    while (ok == 1) // While cikls, kamēr lietotājs vairs nevēlas palaist programmu
    {
        int x_size, y_size, seed;

        cout << "Ievadiet masiva lielumu un seklu(x, y, sekla): ";
        cin >> x_size >> y_size; // Ievada izmērus masīvam
        cin >> seed;             // Ievada sēklu rezultātu atkārtošanai, lai nevajadzētu ievadīt visu masīvu katru reizi no jauna
        cout << endl;

        if (x_size > 0 && y_size > 0)
        {
            init_array(seed, x_size, y_size); // Izveido masīvu pēc ievadītajiem datiem
            calculate_brute(x_size, y_size);  // Aprēķina vislielāko apakšmatricu

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
        biggest_sum = 0;
        cout << endl
             << "Vai velaties turpinat (1) vai beigt (0)?" << endl; // Paprasa lietotājam, vai viņš vēlas palaist programmu atkārtoti
        cin >> ok;
    }
    return 0;
}

/********************************************************************************************************
Ievads                      Programmas vēlamā reakcija                                      Rezultāts C++

10 10 1                     Masivā A tika atrasta lielakā apakšmatrica ar summu 700         +
                            sākuma pozīcijā (h: 0 i: 2), beigu pozīcijā (j: 9 k: 8)

4 5 2                       Masivā A tika atrasta lielakā apakšmatrica ar summu 361         +
                            sākuma pozīcijā (h: 0 i: 2), beigu pozīcijā (j: 4 k: 3)

-7 3 5                      Kļūda. Masīva lielumam jābūt lielākam par 0                     Izdod paziņojumu "Ievadiet pozitivu masiva lielumu!"

*********************************************************************************************************/