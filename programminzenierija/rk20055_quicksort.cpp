#include <fstream>
using namespace std;

int readFile(int &size, int *&array)
{
    ifstream data;
    int number;

    data.open("kartosan.dat");

    // Get count of numbers in file and create array
    data >> number;
    size = number;
    array = new int[size];

    for (int i = 0; i < size; i++)
    {
        data >> number;
        array[i] = number;
    }

    data.close();
    return 1;
}

void writeToFile(int &size, int *&array)
{
    ofstream file;
    file.open("kartosan.rez");

    for (int i = 0; i < size; i++)
    {
        file << array[i];
        if (i < size - 1)
            file << "\n";
    }
}

void swap(int x, int y, int *&array)
{
    int temp = array[x];
    array[x] = array[y];
    array[y] = temp;
}

int partition(int start, int end, int *&array)
{
    int pivot = array[end];
    int i = start - 1;

    for (int j = start; j < end; j++)
    {
        if (array[j] <= pivot)
        {
            i++;
            swap(i, j, array);
        }
    }
    i++;
    swap(i, end, array);

    return i;
}

void sort(int start, int end, int *&array)
{
    if (start >= end || start < 0)
        return;
    int p = partition(start, end, array);
    sort(start, p - 1, array);
    sort(p + 1, end, array);
}

int main()
{
    int size, *array;
    readFile(size, array);
    sort(0, size - 1, array);
    writeToFile(size, array);

    delete[] array;

    return 0;
}
