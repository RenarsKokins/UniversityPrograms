#include <iostream>
#include <cstring>
#include <string>
using namespace std;

char *burti(char *v)
{
    int gar = 0;
    char[81] jv;
    for (int i = 0; i < strlen(v); i++)
    {
        if (isalpha(v[i]))
            jv[i] = v[i];
    }
}

string burti(string v)
{
    string jv = "";
    for (int i = 0; i < v.length(); i++)
    {
        if (isalpha(v[i]))
            jv += v[i];
    }
    return jv;
}

int main()
{
    char[81] v, jv;
    string sv;

    cin.getline(v, 81);
    jv = burti(v);
    delete[] jv;
    getline(cin, sv);
    cout << burti(sv);
    return 0;
}
