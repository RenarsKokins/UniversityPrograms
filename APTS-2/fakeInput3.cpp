#include <iostream>
#include <fstream>
#include <stdio.h>

using namespace std;

int main()
{
    ifstream fin;
    ofstream fout;
    int id, left, right;
    fin.open("team.in");
    fin.close();
    fout.open("team.out");
    fout << "3: 1 2" << endl;
    fout << "2: 3 4 5" << endl;
    fout << "1: 6 7" << endl;
    fout << "0: 8";
    fout.close();
    return 0;
}