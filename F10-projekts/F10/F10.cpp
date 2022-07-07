/*
F10. Dots teksta fails f. Uzrakstīt programmu, kura atrod failā f visus vārdus, kas ir simetriski.
Izvadīt šos vārdus failā f1. Par vārdu uzskatīt patvaļīgu simbolu virkni, kas atdalīta ar tukšumiem
vai pieturas zīmēm (punkts, komats, apaļās iekavas, izsaukuma zīme, jautājuma zīme.) Simetrisks ir vārds,
kas no abām pusēm lasāms vienādi (aka, 1221). Drīkst uzskatīt, ka vārda garums nepārsniedz 40.

Veidoja:
Renārs Kokins
rk20055
19/2/2021

*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool checkSymmetry(string str)
{
    bool symmetric = true;

    if (str.size() % 2 == 0)
    {
        for (int i = 0; i < (int)str.size() / 2; i++)
        {
            if (str[i] != str[str.size() - i - 1])
            {
                symmetric = false;
                break;
            }
        }
    }
    else
    {
        for (int i = 0; i < (int)str.size() / 2; i++)
        {
            if (str[i] != str[str.size() - i - 1])
            {
                symmetric = false;
                break;
            }
        }
    }
    return symmetric;
}

int main()
{
    ifstream fin;
    ofstream fout;
    char letter;
    string rin = "", word = "";

    fin.open("f.txt");
    fout.open("f1.txt");

    if (!fin.is_open())
        return 1;

    getline(fin, rin);
    while (fin)
    {
        word = "";
        for (int i = 0; i < (int)rin.size() + 1; i++)
        {
            letter = rin[i];
            if (letter == ' ' || letter == '.' || letter == ',' || letter == '(' || letter == ')' || letter == '!' || letter == '?' || rin.size() == i)
            {
                if (word.size() > 0)
                {
                    if (checkSymmetry(word))
                    {
                        fout << word << " ";
                    }
                }
                word = "";
            }
            else
            {
                word.push_back(letter);
            }
        }
        getline(fin, rin);
    }

    fin.close();
    fout.close();

    return 0;
}
