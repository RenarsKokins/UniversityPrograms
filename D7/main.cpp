/*******************************************
Renārs Kokins, rk20055

D7. Izveidot klasi ""Skaitļu masīvs"", kurā glabājas masīvs ar skaitļiem (double) garumā 5. Klasei izveidot šādas metodes: (1) konstruktors, kas aizpilda masīvu ar 0, (2)
destruktors, kurš paziņo par objekta likvidēšanu, (3) metode ""Mainīt"" ar maināmā elementa indeksu (0..4) un jauno vērtību, kas izmaina maināmā masīva elementa vērtību, (4)
metode ""Mainīt vietām"" ar vienu parametru - indeksu (0..3), kas apmaina vietām divus blakus elementus, (5) metode ""Drukāt"", kas izdrukā elementu vērtības,
(6) metode ""Drukāt no beigām"", kas izdrukā elementus no beigām uz sākumu.

Programma izveidota: 2020/11/19
*******************************************/

#include <iostream>
#include "program.h"
using namespace std;

int main()
{
    SkMasivs *ma;
    ma = new SkMasivs(); // Izveido objektu SkMasivs

    ma->Drukat();       // Izdrukā masīvu, kuram jābūt piepildītam ar skaitli 0
    ma->Mainit(2, 545); // Izmaina vērtību elementam ar indeksu 2 uz 545
    ma->Mainit(1, 13);  // Izmaina vērtību elementam ar indeksu 1 uz 13

    ma->Drukat(); // Izdrukā masīvu

    ma->Mainit(5, 64);   // Cenšas izmainīt vērtību elementam ar indeksu 5, bet to nespēj izdarīt, jo tas ir ārpus masīva izmēra
    ma->MainitVietam(1); // Samainīs vērtību 1. elementam uz 2. elementa vērtību, un 2. elementam tiks piešķirta 1. elementa vērtība
    ma->MainitVietam(0); // Samainīs vērtību 0. elementam uz 1. elementa vērtību, un 1. elementam tiks piešķirta 0. elementa vērtība

    ma->Drukat(); // Izdrukā masīvu

    ma->MainitVietam(4); // Cenšas samainīt elementus ar indeksiem 4 un 5 vietām, bet to nespēj izdarīt, jo tie ir ārpus masīva izmēra

    ma->DrukatNoBeigam(); // Izdrukā masīvu no beigām
    return 0;
}
