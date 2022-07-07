#include <iostream>
#include <fstream>
#include <stdio.h>

using namespace std;

int main()
{
    ifstream fin;
    int id, left, right;
    fin.open("team.in");
    while (fin >> id >> left >> right)
    {
        cerr << id << " " << left << " " << right << endl;
    }
    fin.close();
    return 0;
}