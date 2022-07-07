/*******************************************
Renārs Kokins, rk20055

B8. Doti trīs naturāli skaitļi. Noteikt, vai starp dotajiem skaitļiem ir tāds, kura ciparu summa ir vienāda ar pārējo divu skaitļu starpību.
Ja ir, izdrukāt šo skaitli. Skaitļu dalīšana ciparos jāveic skaitliski. Risinājumā izmantot funkciju, kas aprēķina skaitļa ciparu summu.

Programma izveidota: 2020/10/22
*******************************************/

#include <iostream>
#include <string>
using namespace std;

int Sum(int n)
{
    int sum = 0;
    while (n >= 10)
    {
        sum += n % 10; // Iegūst pēdējo ciparu no ievadītā skaitļa un pievieno to ciparu summai
        n /= 10;       // Atņem pēdējo ciparu no skaitļa
    }
    sum += n;
    return sum; // Atgriež ciparu summu
}

int main()
{
    int ok = 1;       // While cikla mainīgais, kuru izmainīs, ja vēlēsies beigt programmu
    int a, b, c, cik; // Mainīgie, kuros ievadīs naturālos skaitļus, kā arī uzskaitīs, cik reizes izvada naturālo skaitli

    while (ok == 1) // While cikls, kamēr lietotājs vairs nevēlas palaist programmu
    {
        cik = 0;
        cout << "Ievadiet naturalos skaitlus(pirmais, otrais, tresais): ";
        cin >> a >> b >> c;

        if (a >= 0 & b >= 0 & c >= 0)
        { // Pārbauda, vai ievadītie skaitļi ir naturāli
            if ((Sum(a) == (int)b - c) || (Sum(a) == (int)c - b))
            {
                cout << a << endl;
                cik++;
            } // Pārbauda, vai a mainīgā skaitļu summa nav veināda ar pārējo skaitļu starpību. Ja ir, izdrukā šo skaitli.
            if ((Sum(b) == (int)a - c) || (Sum(b) == (int)c - a))
            {
                cout << b << endl;
                cik++;
            } // Pārbauda, vai b mainīgā skaitļu summa nav veināda ar pārējo skaitļu starpību. Ja ir, izdrukā šo skaitli.
            if ((Sum(c) == (int)a - b) || (Sum(c) == (int)b - a))
            {
                cout << c << endl;
                cik++;
            } // Pārbauda, vai c mainīgā skaitļu summa nav veināda ar pārējo skaitļu starpību. Ja ir, izdrukā šo skaitli.
            if (cik == 0)
                cout << "Nav tada skaitla, kura ciparu summa ir vienada ar parejo divu skaitlu starpibu" << endl; // Ja neizdrukā nevienu skaitli, izdrukā šo paziņojumu
        }
        else
        {
            cout << "Kluda. Ievadiet naturalu skaitli!";
        }

        ok = 0;
        cout << endl
             << "Vai velaties turpinat (1) vai beigt (0)?" << endl; // Paprasa lietotājam, vai viņš vēlas palaist programmu atkārtoti
        cin >> ok;
    }
    return 0;
}

/********************************************************
 Ievads       Programmas vēlamā reakcija                                                                            Rezultāts C++
 8 0 8        8 0 8                                                                                                 +

 1 2 3        1 2                                                                                                   +

 16 14 7      16                                                                                                    +

 31 4 6       Paziņojums. Netika ievadīts skaitlis, kura ciparu summa ir vienāda ar pārējo divu skaitļu starpību    Izdod paziņojumu "Nav tada skaitla, kura ciparu summa ir vienada ar parejo divu skaitlu starpibu"

 -3 4 -5      Kļūda. Netika ievadīti naturāli skaitļi                                                               Izdod paziņojumu "Kluda. Ievadiet pozitivu, naturalu skaitli!"
 ********************************************************/