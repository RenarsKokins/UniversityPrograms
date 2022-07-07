/*
Renārs Kokins, rk20055

Izveidot programmu valodā C++.  Ar faila komponenti tiek saprasts fiksēta garuma ieraksts. Sīkākās prasības sk. Laboratorijas darbu noteikumos.

H10. Doti divi bināri faili f1 un f2, kuru komponentes ir ieraksti ar struktūru: atslēga (int), vārds (nepārsniedz 30 simbolus).
Failu komponentes sakārtotas pēc atslēgām dilstošā secībā. Uzrakstīt programmu, kas apvieno failus f1 un f2 failā f3 tā, lai arī f3 komponentes būtu
dilstošā secībā (failos nedrīkst parādīties divas komponentes ar vienādu atslēgu vērtību).

Programmu veidot tā, lai pilns faila saturs netiktu ielādēts operatīvajā atmiņā. Uzrakstīt arī palīgprogrammas, kas ļauj izveidot failus f1 un f2 un izdrukā failu saturu.

Programmu veidoja: 3/5/2021.
Programmu uzlaboja: 5/5/2021.
*/

#include <iostream>
#include <fstream>
#include <map>
#include <cstring>
#include "ieraksts.h"
using namespace std;

int populateFile(fstream &outfile, Ieraksts &ieraksts)
{
    outfile.clear();
    outfile.seekp(0);
    Ieraksts readIeraksts;
    bool irTads = false;

    while (true)
    {
        printf("Ievadiet atslegu: ");
        cin >> ieraksts.atslega; // pieprasa ievadīt atslēgu
        if (ieraksts.atslega < 0)
            break; // ja atslēga ir <0, beidz ierakstīšanu

        irTads = false;
        outfile.clear();
        outfile.seekg(0);
        outfile.read((char *)&readIeraksts, sizeof(readIeraksts));
        while (outfile)
        {
            // pārbauda, vai šajā failā, kurā raksta, jau ir tāds ieraksts ar tādu pašu atslēgu. Ja ir, parāda paziņojumu un pieprasa ievadīt citu atslēgu
            if (readIeraksts.atslega == ieraksts.atslega)
            {
                irTads = true;
                break;
            };
            outfile.read((char *)&readIeraksts, sizeof(readIeraksts));
        }
        if (irTads)
        {
            printf("Tada atslega jau pastav failaa! Ievadiet citu atslegu!\n");
            continue;
        }
        outfile.clear();

        printf("Ievadiet vardu(ne vairak par 30 simboliem!): ");
        memset(ieraksts.vards, 0, sizeof(ieraksts.vards));  // visā char[30] masīvā ieraksta 0
        cin >> ieraksts.vards;                              // pieprasa ievadīt vārdu
        outfile.write((char *)&ieraksts, sizeof(ieraksts)); // ieraksta ierakstu failā
    }
    cout << endl;
    return 0;
}

int printFile(fstream &infile, Ieraksts &ieraksts)
{
    infile.clear();
    infile.seekg(0);

    infile.read((char *)&ieraksts, sizeof(ieraksts));
    while (infile)
    {
        printf("Atslega: %i\n", ieraksts.atslega);
        printf("Vards: %s\n", ieraksts.vards);
        infile.read((char *)&ieraksts, sizeof(ieraksts));
    }
    return 0;
}

int main()
{
    Ieraksts ieraksts;
    fstream file;
    char filename[7] = "f1.bin";

    for (int i = 0; i < 2; i++)
    { // cikls, kurš automātiski izmaina faila nosaukumu
        filename[1] = '1' + i;
        printf("Lai beigtu ievadi, ierakstiet -1 pie atslegas\n");
        printf("Tiks rakstits %s faila!\n", filename);
        file.open(filename, ios::binary | ios::in | ios::out | ofstream::trunc); // atver failu, izdzēš visu no tā
        populateFile(file, ieraksts);                                            // funkcija, kura ieraksta failā ievadītos datus
        printFile(file, ieraksts);                                               // izvada faila saturu
        file.close();                                                            // aizver failu
        cout << endl;
    }
    return 0;
}

/*
Ievads                                                  Programmas vēlamā reakcija                                      Rezultāts C++

1 renars 2 rudolfs 3 artis -1 9 aaa 8 bbb 7 ccc -1      Izveido f1 un f2 failus ar tiem ierakstiem dilstošā secībā      +

1 renars 2 rudolfs 1 -1 9 aaa 8 bbb 7 ccc -1            Kļūda. Divas vienādas atslēgas. Ievdadiet jaunu atslēgu.        Pieprasa ievadīt atslēgu atkārtoti

1 dilstosi 2 sakartots 3 bus -1 1 aaa 2 bbb 3 ccc -1    Izveido f1 un f2 failus ar tiem ierakstiem dilstošā secībā      +

*/