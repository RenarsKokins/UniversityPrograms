/*
Veidoja: Renārs Kokins, rk20055
Datums: 3/14/2022
*/

#include <fstream>
using namespace std;

struct Node
{
    Node *left;
    Node *right;
    int value;
};

void addToTree(Node *&node, int &number)
{
    // Ja nav sākuma kokam, tas tiek izveidots
    if (node == NULL)
    {
        node = new Node();
        node->value = number;
        return;
    }
    if (number < node->value)
    {
        addToTree(node->left, number);
    }
    else
    {
        addToTree(node->right, number);
    }
}

void printTree(Node *&node, ofstream &file)
{
    if (node == NULL)
        return;
    printTree(node->left, file);
    file << node->value << "\n";
    printTree(node->right, file);
}

void deleteTree(Node *&node)
{
    if (node == NULL)
        return;
    deleteTree(node->left);
    deleteTree(node->right);
    delete node;
}

int main()
{
    Node *start = NULL;
    ifstream data;
    ofstream out;
    int number, size;

    data.open("kartosan.dat");
    data >> number;
    size = number;

    for (int i = 0; i < size; i++)
    {
        data >> number;
        addToTree(start, number);
    }
    data.close();
    out.open("kartosan.rez");
    printTree(start, out);
    out.close();
    deleteTree(start);

    return 0;
}

// Quicksort algoritma implementācija

// #include <fstream>
// using namespace std;

// int readFile(int& size, int*& array) {
//     ifstream data;
//     int number;

//     data.open("kartosan.dat");
//     if(!data) {
//         return -1;
//     }

//     // Get count of numbers in file and create array
//     data >> number;
//     size = number;
//     array = new int[size];

//     for(int i=0; i<size; i++) {
//         data >> number;
//         array[i] = number;
//     }

//     data.close();
//     return 1;
// }

// void writeToFile(int& size, int*& array) {
//     ofstream file;
//     file.open("kartosan.rez");

//     for(int i=0; i<size; i++) {
//         file << array[i];
//         if(i < size-1) file << "\n";
//     }
// }

// void swap(int x, int y, int*& array) {
//     int temp = array[x];
//     array[x] = array[y];
//     array[y] = temp;
// }

// int partition(int start, int end, int*& array) {
//     int pivot = array[end];
//     int i = start - 1;

//     for (int j = start; j < end; j++) {
//         if (array[j] <= pivot) {
//             i++;
//             swap(i, j, array);
//         }
//     }
//     i++;
//     swap(i, end, array);

//     return i;
// }

// void sort(int start, int end, int*& array) {
//     if(start >= end || start < 0) return;

//     int p = partition(start, end, array);
//     sort(start, p-1, array);
//     sort(p+1, end, array);
// }

// int main() {
//     int size, *array;
//     readFile(size, array);
//     sort(0, size-1, array);
//     writeToFile(size, array);

//     delete[] array;

//     return 0;
// }
