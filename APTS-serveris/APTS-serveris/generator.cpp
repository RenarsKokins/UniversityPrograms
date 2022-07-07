#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char *argv[])
{
    ofstream output;
    output.open(argv[3]);

    output << "10003" << endl;

    for (int i = 1; i <= 5000; i++)
    {
        output << 5001 << " ";
        output << i << endl;
    }

    for (int i = 5002; i <= 10002; i++)
    {
        output << 10003 << " ";
        output << i << endl;
    }

    output << "5001 10003" << endl;
    output << "0 0";

    output.close();
    return 0;
}
