/*******************************************

Renārs Kokins, rk20055

MD4. Lietotājs ievada veselu pozitīvu skaitli. Izdrukā tā pirmspēdējo ciparu.

Programma izveidota: 2020/09/17

*******************************************/

#include <iostream>
#include <string>
using namespace std;

int main()
{
    int ok = 1;   // While cikla mainīgais, kuru izmainīs, ja vēlēsies beigt programmu
    string input; // Mainīgais ievadīšanai
    int n = 0;

    while (ok == 1) // While cikls, kamēr lietotājs vairs nevēlas palaist programmu
    {
        cout << "Ievadiet veselu, pozitīvu skaitli: ";
        cin >> input;

        if (input.length() < 2)
        {
            cout << "Kļūda. Ievadiet veselu, pozitīvu skaitli!";
        }
        else if (stoll(input) > 0)
        {
            cout << input[input.length() - 2]; // Iegūst pirmspēdējo ciparu
        }
        else
        {
            cout << "Kļūda. Ievadiet veselu, pozitīvu skaitli!";
        }

        ok = 0;
        cout << endl
             << "Vai vēlaties turpināt (1) vai beigt (0)?" << endl; // Paprasa lietotājam, vai viņš vēlas palaist programmu atkārtoti
        cin >> ok;
    }
    return 0;
}

/***************
Ievads              Programmas vēlamā reakcija                              Rezultāts C++
160                 6                                                       +

987654              5                                                       +

-345                Kļūda. Tas nav pozitīvs skaitlis                        Izdod paziņojumu "Kļūda. Ievadiet pozitīvu, veselu skaitli!"

0                   Kļūda. Tam nav pirmspēdējā locekļa                      Izdod paziņojumu "Kļūda. Ievadiet pozitīvu, veselu skaitli!"

0
****************/