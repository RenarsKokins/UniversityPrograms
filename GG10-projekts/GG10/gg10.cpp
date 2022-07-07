/*
Renārs Kokins, rk20055

Izveidot divas programmas valodā C++, kas strādā ar vērtību virkni divos dažādos veidos:
  1) to realizējot kā vienvirziena saistīto sarakstu, izmantojot dinamiskas datu struktūras,
  2) izmantojot STL::list konteineru.
Abās realizācijās ir jāizveido prasītā specifiskā vērtību virknes apstrādes funkcija un jānodemonstrē tā darbībā, cita starpā parādot gan sākotnējās,
gan rezultējošās vērtības. Saistītā saraksta gadījumā jāuzraksta arī nepieciešamās palīgfunkcijas (piemēram, elementu pievienošanai), kā arī pēc tā
izmantošanas korekti jāatbrīvo izdalītā atmiņa.

GG10. Uzrakstīt funkciju, kas izmet no saraksta tos elementus, kas seko aiz elementa ar vērtību n un kuri nav vienādi ar n.

Programmu veidoja: 5/5/2021.
*/

#include <iostream>
#include "funkcija.h"
using namespace std;

void addElements(node *&first)
{
    int in = 0;
    node *n, *last = NULL;

    while (true)
    {
        cout << "Ievadiet skaitli(ja nevelaties turpinat ievadit, ierakstiet 0): ";
        cin >> in;

        if (in == 0)
            break; // Ja ievadītais skaitlis ir 0, beigt ievades ciklu

        n = new node; // Tiek izveidota jauns elements ar struktūru "node"
        n->val = in;
        n->next = NULL;

        if (first == NULL)
            first = n;
        if (last == NULL)
            last = n;
        else
        {
            last->next = n;
            last = n;
        }
    }
}

void printElements(node *&first)
{
    node *current = first;
    if (first == NULL)
        throw "navFirst";

    while (true)
    {
        cout << current->val << " ";
        if (current->next != NULL)
            current = current->next;
        else
            break; // Ja nākamā elementa norāde ir NULL, beigt printēšanas ciklu
    }
    cout << endl;
}

void deleteElements(node *&first)
{
    node *current = first; // Norāde, kurā glabājas pašreizējā norāde
    node *next = NULL;     // Norāde, kurā glabājas nākamā norāde

    while (current != NULL)
    {
        next = current->next;
        free(current); // Abrīvo pašreizējo elementu no atmiņas
        current = next;
    }
}

int main()
{
    int n = 0;          // Mainīgais, kurā glabāsies skaitlis, pēc kura metīs ārā pārējos skaitļus
    node *first = NULL; // Norāde, kurā vienmēr glabāsies pirmā norāde

    addElements(first); // Tiek izveidotas struktūras ar ievadītajiem skaitļiem
    cout << "Ievadiet skaitli, pec kura citi tiks mesti ara: ";
    cin >> n; // Tiek ievadīts skaitlis, pēc kura tiks mesti ārā pārējie skaitļi
    cout << endl
         << "Elementi pirms atmesanas:" << endl;
    try
    {
        printElements(first);    // Izvada visus elementus
        throwElements(first, n); // Izmet elementus pēc ievadītā skaitļa
    }
    catch (const char *z)
    {
        if (z == "navFirst")
        {
            cout << "Kluda. Nav ievadits neviens skaitlis.";
            return -1;
        }
        else if (z == "navN")
        {
            cout << "Kluda. Nav ievadits skaitlis, pec kura mest ara.";
            return -2;
        }
    }
    catch (...)
    {
        cout << "Kluda. Nav iznemumsituacija.";
        return -3;
    }

    cout << "Elementi pec atmesanas:" << endl;
    printElements(first);  // Izvada visus elementus
    deleteElements(first); // Izdzēš visus elementus
    cout << "atbrivoja atminu!";

    return 0;
}

/*
Ievads                          Programmas vēlamā reakcija                                  Rezultāts C++

1 2 3 4 5 4 3 2 1 0 3           Izvada skaitļus: 1 2 3 3                                    +

1 2 3 4 5 4 3 2 1 0 6           Izvada skaitļus: 1 2 3 4 5 4 3 2 1                          +

1 2 3 4 5 4 3 -80 -3 0 3        Izvada skaitļus: 1 2 3 3                                    +

0                               Kļūda. Netika ievadīti skaitļi                              Izvada paziņojumu: "Kluda. Netika ievadits neviens skaitlis!"

3 0 3                           Izvada skaitli: 3                                           +
*/
