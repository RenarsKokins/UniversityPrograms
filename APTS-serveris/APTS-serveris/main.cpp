#include <iostream>
#include <fstream>

using namespace std;

void createMatrix(bool *&Mat, char *path, int &compCount)
{
    ifstream input;
    char var[9];
    char in[9];
    char out[9];
    input.open(path);
    input.getline(var, 9);
    compCount = atoi(var);

    long mCompCount = compCount * compCount;

    Mat = new bool[mCompCount];
    for (long i = 0; i < mCompCount; i++)
    {
        Mat[i] = false;
    }

    while (true)
    {
        input >> in;
        if (in[0] == '0')
            break;
        input >> out;
        Mat[(atoi(in) - 1) * compCount + (atoi(out) - 1)] = true;
        Mat[(atoi(out) - 1) * compCount + (atoi(in) - 1)] = true;
    }
    input.close();
}

int isServer(int current, bool *&Mat, int &maxHops, bool *&reachedArr, int compCount, bool *&cameFrom, int hops = 0)
{
    cameFrom[current] = true;
    bool setMax = false;
    reachedArr[current] = true;
    for (int j = 0; j < compCount; j++)
    {
        if (reachedArr[j] == false)
        {
            reachedArr[j] = Mat[(current * compCount) + j];
        }
    }
    for (int i = 0; i < compCount; i++)
    {
        bool reachesEvery = true;
        for (int j = 0; j < compCount; j++)
        {
            if (reachedArr[j] == false)
            {
                reachesEvery = false;
                break;
            }
        }
        if (reachesEvery)
            return max(hops, maxHops);

        if (reachedArr[i] == true && cameFrom[i] != true && Mat[((long)current * compCount) + i] == true)
        {
            setMax = true;
            int currentHops = isServer(i, Mat, maxHops, reachedArr, compCount, cameFrom, hops + 1);
            if (currentHops != 0)
            {
                hops = currentHops;
            }
        }

        reachesEvery = true;
        for (int j = 0; j < compCount; j++)
        {
            if (reachedArr[j] == false)
            {
                reachesEvery = false;
                break;
            }
        }
        if (reachesEvery)
            return hops;
    }
    if (setMax)
        maxHops = max(hops, maxHops);
    return 0;
}

void findServer(bool *&Mat, int compCount, int *&serverResults)
{
    int maxHops = 0;

    bool *reachedArr = new bool[compCount];
    bool *cameFrom = new bool[compCount];
    serverResults = new int[compCount];

    for (int i = 0; i < compCount; i++)
    {
        for (int i = 0; i < compCount; i++)
        {
            cameFrom[i] = false;
        }
        for (int i = 0; i < compCount; i++)
        {
            reachedArr[i] = false;
        }
        serverResults[i] = isServer(i, Mat, maxHops, reachedArr, compCount, cameFrom);
    }

    delete[] reachedArr;
    delete[] cameFrom;
}

void writeResults(char *path, int &compCount, int *&serverResults)
{
    ofstream output;
    output.open(path);

    int smallest = serverResults[0], sCount = 0;

    for (int i = 0; i < compCount; i++)
    {
        if (serverResults[i] < smallest)
            smallest = serverResults[i];
    }

    for (int i = 0; i < compCount; i++)
    {
        if (serverResults[i] == smallest)
            sCount++;
    }
    cout << sCount << endl;
    output << sCount << endl;

    for (int i = 0; i < compCount; i++)
    {
        if (serverResults[i] == smallest)
        {
            cout << i + 1 << " ";

            if (i != compCount - 1)
                output << i + 1 << " ";
            else
                output << i + 1;
        }
    }
    output.close();
}

int main(int argc, char *argv[])
{
    if (argc > 4 || argc < 3)
        return 1;

    bool *connMatrix;
    int *serverResults;
    int compCount = 0;

    createMatrix(connMatrix, argv[1], compCount);
    findServer(connMatrix, compCount, serverResults);
    writeResults(argv[2], compCount, serverResults);

    delete[] serverResults;
    delete[] connMatrix;

    return 0;
}
