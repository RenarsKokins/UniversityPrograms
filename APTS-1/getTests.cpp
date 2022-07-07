#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>

using namespace std;

int main()
{
    ifstream fin;
    int time, code;
    string cd, action;
    fin.open("exchange.in");
    while (fin >> time >> action >> code >> cd)
    {
        cerr << time << " " << action << " " << code << " " << cd << endl;
    }
    fin.close();
    return 0;
}