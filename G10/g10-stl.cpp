/*
Renārs Kokins, rk20055

Izveidot divas programmas valodā C++, kas strādā ar vērtību virkni divos dažādos veidos:
  1) to realizējot kā vienvirziena saistīto sarakstu, izmantojot dinamiskas datu struktūras,
  2) izmantojot STL::list konteineru.
Abās realizācijās ir jāizveido prasītā specifiskā vērtību virknes apstrādes funkcija un jānodemonstrē tā darbībā, cita starpā parādot gan sākotnējās,
gan rezultējošās vērtības. Saistītā saraksta gadījumā jāuzraksta arī nepieciešamās palīgfunkcijas (piemēram, elementu pievienošanai), kā arī pēc tā
izmantošanas korekti jāatbrīvo izdalītā atmiņa.

G10. Uzrakstīt funkciju, kas izmet no saraksta tos elementus, kas seko aiz elementa ar vērtību n un kuri nav vienādi ar n.

Programmu veidoja: 1/3/2021.
Pievienoja testa rezultātus un komentārus: 1/4/2021.
*/

#include <iostream>
#include <list>
using namespace std;

void addElements(list<int> &list)
{
    int in = 0;

    while (true)
    {
        cout << "Ievadiet skaitli(ja nevelaties turpinat vadit, ierakstiet 0): ";
        cin >> in;

        if (in == 0)
            break;
        list.push_back(in);
    }
}

void printElements(list<int> &list)
{
    for (auto a : list)
        cout << a << " ";
    cout << endl;
}

void throwElements(list<int> &list, int &n)
{
    bool found = false;

    for (auto itr = list.cbegin(); itr != list.end(); itr++)
    {
        if (*itr == n)
            found = true;
        if (*itr != n && found == true)
            list.erase(itr--);
    }
}

int main()
{
    int n = 0;
    list<int> list;

    addElements(list);
    if (list.empty())
    {
        cout << "Netika ievadits neviens skaitlis!" << endl;
        return 0;
    }

    cout << "Ievadiet skaitli, pec kura citi tiks mesti ara: ";
    cin >> n;

    cout << endl
         << "Elementi pirms atmesanas:" << endl;
    printElements(list);
    throwElements(list, n);
    cout << "Elementi pec atmesanas:" << endl;
    printElements(list);

    return 0;
}

/*
Ievads                          Programmas vēlamā reakcija                                  Rezultāts C++

1 2 3 4 5 4 3 2 1 0 3           Izvada skaitļus: 1 2 3 3                                    +

1 2 3 4 5 4 3 2 1 0 6           Izvada skaitļus: 1 2 3 4 5 4 3 2 1                          +

1 2 3 4 5 4 3 -80 -3 0 3        Izvada skaitļus: 1 2 3 3                                    +

0                               Kļūda. Netika ievadīti skaitļi                              Izvada paziņojumu: "Netika ievadits neviens skaitlis!"

3 0 3                           Izvada skaitli: 3                                           +
*/