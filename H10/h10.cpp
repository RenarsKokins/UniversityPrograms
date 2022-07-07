/*
Renārs Kokins, rk20055

Izveidot programmu valodā C++.  Ar faila komponenti tiek saprasts fiksēta garuma ieraksts. Sīkākās prasības sk. Laboratorijas darbu noteikumos.

H10. Doti divi bināri faili f1 un f2, kuru komponentes ir ieraksti ar struktūru: atslēga (int), vārds (nepārsniedz 30 simbolus). 
Failu komponentes sakārtotas pēc atslēgām dilstošā secībā. Uzrakstīt programmu, kas apvieno failus f1 un f2 failā f3 tā, lai arī f3 komponentes būtu 
dilstošā secībā (failos nedrīkst parādīties divas komponentes ar vienādu atslēgu vērtību). 

Programmu veidot tā, lai pilns faila saturs netiktu ielādēts operatīvajā atmiņā. Uzrakstīt arī palīgprogrammas, kas ļauj izveidot failus f1 un f2 un izdrukā failu saturu.

Programmu veidoja: 3/5/2021.
*/

#include <fstream>
#include <cstring>
#include <map>
#include "ieraksts.h"
using namespace std;

int addToMap(map<int, posPair> &table, ifstream &f1, ifstream &f2){
    Ieraksts ieraksts;
    posPair pos;

    pos.kursFails = 0;
    pos.pozicija = 0;
    f1.read((char*)&ieraksts, sizeof(ieraksts));    // nolasa f1 faila pirmo ierakstu
    while(f1){
        table.insert(pair<int, posPair>(ieraksts.atslega, pos));    // ievieto atslēgas un pozīcijas mainīgos
        f1.read((char*)&ieraksts, sizeof(ieraksts));                // nolasa nākamo ierakstu
        pos.pozicija = pos.pozicija + 1;
    }

    pos.kursFails = 1;
    pos.pozicija = 0;
    f2.read((char*)&ieraksts, sizeof(ieraksts));    // nolasa f2 faila pirmo ierakstu
    while(f2){
        if(table.count(ieraksts.atslega)>0) return 1;               // ja atrod vienādas atslēgas f1 un f2 failos, beidz funkciju un atgriež 1
        table.insert(pair<int, posPair>(ieraksts.atslega, pos));    // ievieto atslēgas un pozīcijas mainīgos map vieknē
        f2.read((char*)&ieraksts, sizeof(ieraksts));                // nolasa nākamo ierakstu
        pos.pozicija = pos.pozicija + 1;
    }
    return 0;
}

int addToFile(map<int, posPair> &table, ifstream &f1, ifstream &f2, ofstream &outfile){
    Ieraksts ieraksts;
    f1.clear();     // attīra faila eof "karogu"
    f1.seekg(0);    // nomaina norādi uz 0, lai lasītu failu no jauna
    f2.clear();     // attīra faila eof "karogu"
    f2.seekg(0);    // nomaina norādi uz 0, lai lasītu failu no jauna

    for (auto itr = table.rbegin(); itr != table.rend(); itr++) {   // iziet cauri map no baigām
        ieraksts.atslega = itr->first;
        if(itr->second.kursFails == 0) {                            // nolasa no noteikta faila noteiktus baitus
            f1.seekg((itr->second.pozicija*sizeof(Ieraksts))+sizeof(int));
            f1.read((char*)&ieraksts.vards, sizeof(ieraksts.vards));
        }
        else {
            f2.seekg((itr->second.pozicija*sizeof(Ieraksts))+sizeof(int));
            f2.read((char*)&ieraksts.vards, sizeof(ieraksts.vards));
        }
        outfile.write((char*)&ieraksts, sizeof(Ieraksts));          // ieraksta ieraksts struktūru f3 failā
    }
    return 0;
}

void closeFiles(ifstream &f1, ifstream &f2, ofstream &outfile){
    f1.close();
    f2.close();
    outfile.close();
}

int main(){
    map<int, posPair> table;        // map, kurā glabāsies atslēgas un pozīcijas faila ieraksta nolasīšanai
    ofstream outfile;               // izvada "f3.bin" mainīgais
    ifstream f1, f2;                // ievada "f1.bin" un "f2.bin" mainīgais
    int returnVal;                  // mainīgais, kurā glabājas funkcijas atgriešanas skaitlis

    f1.open("f1.bin", ios::in | ios::binary);       // atver f1 bināro failu
    f2.open("f2.bin", ios::in | ios::binary);       // atver f2 bināro failu
    returnVal = addToMap(table, f1, f2);            // pievieno f1 un f2 map
    if(returnVal==1) {                              // ja funkcija atgriež 1, tas nozīmē, ka tika atrasti ieraksti ar vienādām atslēgām
        printf("Tika atrasti ieraksti ar vienadam atslegam! f3 faila izveide ir aptureta.\n");
        closeFiles(f1, f2, outfile);                // failu aizvēršanas funkcija(lai mazāk aizņemtu vietas main funkcijā)
        return 1;
    }
    outfile.open("f3.bin", ios::out | ios::binary); // atver f3 bināro failu
    addToFile(table, f1, f2, outfile);              // pievieno f1 un f2 ierakstus f3 failā
    closeFiles(f1, f2, outfile);                    // failu aizvēršanas funkcija(lai mazāk aizņemtu vietas main funkcijā)
    
    return 0;
}

/*
Ievads                                                  Programmas vēlamā reakcija                                                  Rezultāts C++

1. testa piemērs binVeidotajs.cpp failā                 Izveido f3 failu ar elementiem no f1 un f2 dilstošā secībā                  +

2. testa piemērs binVeidotajs.cpp failā                 Izveido f3 failu ar elementiem no f1 un f2 dilstošā secībā                  +

3. testa piemērs binVeidotajs.cpp failā                 Kļūda. Tika atrasti ieraksti ar vienādām atslēgām. Neizveido f3 failu       Izdod paziņojumu: "Tika atrasti ieraksti ar vienadam atslegam! f3 faila izveide ir aptureta."

*/
