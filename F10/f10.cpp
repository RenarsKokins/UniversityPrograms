/*
Renārs Kokins, rk20055

F10. Dots teksta fails f. Uzrakstīt programmu, kura atrod failā f visus vārdus, kas ir simetriski.
Izvadīt šos vārdus failā f1. Par vārdu uzskatīt patvaļīgu simbolu virkni, kas atdalīta ar tukšumiem
vai pieturas zīmēm (punkts, komats, apaļās iekavas, izsaukuma zīme, jautājuma zīme.) Simetrisks ir vārds,
kas no abām pusēm lasāms vienādi (aka, 1221). Drīkst uzskatīt, ka vārda garums nepārsniedz 40.

Veidoja: 26/2/2021
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool checkSymmetry(string str)
{
    bool symmetric = true; // Tiek izveidots bool mainīgais ar vērtību "true". Ja vārds nebūs simetrisks, tā vērtība izmainīsies uz "false"
    for (int i = 0; i < (int)str.size() / 2; i++)
    {                                        // For cikls iziet cauri pusei no vārda
        char first = str[i];                 // Pievieno first mainīgajam i-to simbolu no vārda
        char last = str[str.size() - i - 1]; // Pievieno last mainīgajam simbolu, kuru iegūst no vārda izmēra, atņemot i-1

        if (isalpha(first))
            first = tolower(first); // Pārveido par mazo burtu, ja tas ir lielais
        if (isalpha(last))
            last = tolower(last); // Pārveido par mazo burtu, ja tas ir lielais

        if (first != last)
        {                      // Pārbauda, vai i-tais simbols nav vienāds ar simbolu no vārda izmēra, atņemot i-1
            symmetric = false; // Izmaina bool mainīgā vērību uz false
            break;             // Beidz for ciklu
        }
    }
    return symmetric; // Atgriež bool vērtību
}

int main()
{
    ifstream fin;               // Izveidots faila ievads
    ofstream fout;              // Izveidots faila izvads
    char letter;                // char mainīgais, kurā glabāsies vārda simbols
    string rin = "", word = ""; // string mainīgie, kuros glabāsies rindiņas vārdi un pats vārds atsevišķi
    int atkartot = 1;           // int mainīgais, lai palaistu programmu atkārtoti

    do
    {
        fin.open("f.txt");   // Tiek atvērts ievades fails "f.txt"
        fout.open("f1.txt"); // Tiek atvērts izvades fails "f1.txt"

        if (!fin.is_open())
            return 1; // Tiek pārbaudīts, vai var atvērt failu "f.txt". Ja nav, atgriež skaitli 1 un beidz darbību

        getline(fin, rin); // Iegūst pirmo rindiņu no faila un ievieto to rin mainīgajā
        while (fin)
        {                 // While cikls, kamēr ir iespējams nolasīt rindiņu failā
            word.clear(); // Attīra mainīgo "word" no vārdiem

            for (int i = 0; i < (int)rin.size() + 1; i++)
            {                    // for cikls, kurš iziet cauri visiem simboliem "rin" mainīgajā (nolasītajā rindiņā)
                letter = rin[i]; // Saglabā pašreizējo simbolu "letter" mainīgajā

                if (letter == ' ' || letter == '.' || letter == ',' || letter == '(' || letter == ')' || letter == '!' || letter == '?' || rin.size() == i)
                { // Pārbauda, vai pašreizējais simbols ir tukšums vai pieturas zīme, kā arī to, vai tas ir pēdējais simbols rindiņā
                    if (word.size() > 0)
                    { // Pārbauda, vai saglabātā simbolu virknīte satur vārdu (simbolus)
                        if (checkSymmetry(word))
                        {                        // Pārbauda, vai vārds ir simetrisks, izsaucot funkciju "CheckSymmmetry()"
                            fout << word << " "; // Ja vārds ir simetrisks, izvada to failā
                        }
                    }
                    word.clear(); // Attīra mainīgo "word" no vārdiem
                }
                else
                {
                    word.push_back(letter); // Pievieno simbolu mainīgajam "word", veidojot vārdu
                }
            }
            getline(fin, rin); // Iegūst nākamo rindiņu no faila
        }

        fin.close();  // Aizver ievada failu
        fout.close(); // Aizver izvada failu

        cout << "Ja velaties palaist programmu atkartoti, rakstiet (1), ja ne, tad (0): ";
        cin >> atkartot;

    } while (atkartot == 1);

    return 0; // Atgriež 0 main funkcijai
}

/*
Ievada fails                                Izvada fails                            Rezultāts C++
----------------------------------------------------------------------------------------------------
Asa sajuta vedera, sss, wow!                Asa sss wow                             +
----------------------------------------------------------------------------------------------------
teksts 1234321 ,! tenet.                    1234321 tenet                           +
----------------------------------------------------------------------------------------------------
nav simetrisku vardu.                                                               +
----------------------------------------------------------------------------------------------------
                                                                                    +
----------------------------------------------------------------------------------------------------
*/