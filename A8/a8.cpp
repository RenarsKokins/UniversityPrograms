/*******************************************

Renārs Kokins, rk20055
A8. Dots naturāls skaitlis n. Izdrukāt tos skaitļa n reizinātājus, kuri ir kāda naturāla skaitļa kvadrāti.
Programma izveidota: 2020/09/27

*******************************************/

#include<iostream>
#include <string>
using namespace std;

int main(){
    int ok = 1;        // While cikla mainīgais, kuru izmainīs, ja vēlēsies beigt programmu
    long long int n;   // Mainīgais, kurā ievadīs naturālu skaitli
    string input;      // Mainīgais ievades glabāšanai string formātā
    
    while (ok == 1)    // While cikls, kamēr lietotājs vairs nevēlas palaist programmu
    {
        cout << "Ievadiet naturalu skaitli: ";
        cin >> input;
        n = stoll(input);   // Pārveido ievadīto string par skaitli
        cout << endl;

        if(n > 0)           // Pārbauda, vai skiatlis ir pozitīvs
        {
            for(long long int a=1; a*a<=n; a++) // Sāk for ciklu ar 1^2 un turpina, līdz šis kvadrāts nepārsniedz ievadīto naturālo skaitli
            {
                long long int kvadrats = a*a;   // Aprēķina naturāla skaitļa kvadrātu
                if(n % kvadrats == 0)           // Pārbauda, vai kvadrāts ir skaitļa n reizinātājs
                {
                    cout << kvadrats << endl;   // Izdrukā skaitļa n reizinātāju
                }
            }
        } 
        else 
        {
            cout << "Kluda. Ievadiet pozitivu, naturalu skaitli!" << endl;
        }

        ok = 0;
        cout << endl << "Vai velaties turpinat (1) vai beigt (0)?" << endl; // Paprasa lietotājam, vai viņš vēlas palaist programmu atkārtoti
        cin >> ok;
    }
    return 0;
}

/***************
Ievads              Programmas vēlamā reakcija                              Rezultāts C++
16                  1, 4, 16                                                +

100                 1, 4, 25, 100                                           +

4096                1, 4, 16, 64, 256, 1024, 4096                           +

0                   Kļūda. Nullei nav reizinātāju                           Izdod paziņojumu "Kļūda. Ievadiet pozitīvu, naturālu skaitli!"

-3                  Kļūda. Nav kvadrātu reizinātāju negatīvam skaitlim      Izdod paziņojumu "Kļūda. Ievadiet pozitīvu, naturālu skaitli!"
****************/