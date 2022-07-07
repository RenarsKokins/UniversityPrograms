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

void throwElements(node *&first, int &n)
{
    node *current = first; // Norāde, kurā glabāsies pašreizējā norāde
    node *next = NULL;     // Norāde, kurā glabāsies nākamā norāde
    node *last = NULL;     // Norāde, kurā glabāsies iepriekšējā norāde
    bool found = false;

    if (first == NULL)
        throw "navFirst";
    else if (n == 0)
        throw "navN";

    while (true)
    {
        if (current->val == n)
            found = true; // Pārbauda, vai elementa skaitlis ir vienāds ar to, pēc kura mest ārā pārējos elementus
        if (found)
        {
            if (current->val != n)
            { // Ja elementa skaitlis nav vienāds ar ievadīto skaitli, to elemetu dzēš ārā
                if (last != NULL)
                    last->next = current->next;
                next = current->next;
                delete current;
            }
            else
            { // Ja elementa skaitlis ir vienāds ar ievadīto skaitli, to elemetu atstāj
                if (last != NULL)
                    last->next = current;
                last = current;
                next = current->next;
                last->next = NULL;
            }
        }
        else
        {
            next = current->next;
            last = current;
        }

        if (next != NULL)
            current = next;
        else
            break;
    }
}
