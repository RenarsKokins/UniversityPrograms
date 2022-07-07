#include <iostream>
#include <fstream>

using namespace std;

int addToArr(char **&iArr, ifstream &input, char *file)
{
    char vieta[255];
    int wordCount = 0;

    input.open(file);
    while (input >> (char *)vieta)
    {
        wordCount += 1;
    }
    if (wordCount == 0)
        return 0;

    iArr = new char *[wordCount];
    for (int i = 0; i < wordCount; i++)
    {
        iArr[i] = new char[255];
    }

    input.clear();
    input.seekg(0, input.beg);

    for (int i = 0; i < wordCount; i++)
    {
        input >> (char *)vieta;
        for (int j = 0; j < 255; j++)
        {
            if (vieta[j] == '\0')
                break;
            iArr[wordCount - 1 - i][j] = vieta[j];
        }
    }
    input.close();
    return wordCount;
}

void sortAndWrite(char **iArr, ofstream &output, char *file, int wordCount)
{
    output.open(file);

    for (int i = 97; i < 123; i++)
    {
        for (int j = 0; j < wordCount; j++)
        {
            if (iArr[j][0] == i)
            {
                output << iArr[j] << " ";
            }
        }
    }
    output.close();
}

int main(int argc, char *argv[])
{
    if (argc > 3 || argc < 3)
        return 1;

    ifstream input;
    ofstream output;
    char **iArr;
    int wordCount;

    wordCount = addToArr(iArr, input, argv[1]);

    if (wordCount == 0)
    {
        cout << "nothing";
        return 0;
    }
    sortAndWrite(iArr, output, argv[2], wordCount);

    for (int i = 0; i < wordCount; i++)
    {
        delete[] iArr[i];
    }
    delete[] iArr;

    return 0;
}
