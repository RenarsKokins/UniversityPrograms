#include <fstream>
#include <string>
#include <map>
#include <list>
#include <stdio.h>
using namespace std;

struct Node
{
    int id;
    int uzticiba = 0;
    struct Node *left;
    struct Node *right;
    Node(int val)
    {
        id = val;
        left = NULL;
        right = NULL;
    }
};

Node *findElementOfTree(int id, Node *treeElement, map<int, list<int>> &table, int depth)
{
    if (treeElement != NULL)
    {
        if (treeElement->id == id)
        {
            table[depth].push_back(id);
            return treeElement;
        }
        Node *left;
        Node *right;
        left = findElementOfTree(id, treeElement->left, table, depth + 1);
        if (left != nullptr)
            return left;
        else
            right = findElementOfTree(id, treeElement->right, table, depth + 1);
        if (right != nullptr)
            return right;
        else
            return nullptr;
    }
    else
        return NULL;
}

bool loadData(map<int, int[2]> &sortedInput, ifstream &fin)
{
    int id, left, right;
    fin.clear();
    fin.seekg(0);
    while (fin >> id >> left >> right)
    {
        if (id == 0)
            continue;
        sortedInput[id][0] = left;
        sortedInput[id][1] = right;
    }
    auto itr = sortedInput.begin();
    if (itr->second[0] == 0 & itr->second[1] == 0)
        return true;
    else
        return false;
}

void createTreeSorted(Node *&treeStart, map<int, int[2]> &sortedInput, map<int, list<int>> &table, bool &reverse)
{
    int id, left, right;
    bool firstTime = true;
    Node *element;

    if (!reverse)
    {
        for (auto itr = sortedInput.begin(); itr != sortedInput.end(); ++itr)
        {
            if (firstTime)
                treeStart = new Node(itr->first);
            firstTime = false;
            element = findElementOfTree(itr->first, treeStart, table, 0);

            if (element == NULL)
                continue;
            if (itr->second[0] != 0)
                element->left = new Node(itr->second[0]);
            else
                element->left = NULL;
            if (itr->second[1] != 0)
                element->right = new Node(itr->second[1]);
            else
                element->right = NULL;
        }
    }
    else
    {
        for (auto itr = sortedInput.rbegin(); itr != sortedInput.rend(); ++itr)
        {
            if (firstTime)
                treeStart = new Node(itr->first);
            firstTime = false;
            element = findElementOfTree(itr->first, treeStart, table, 0);

            if (element == NULL)
                continue;
            if (itr->second[0] != 0)
                element->left = new Node(itr->second[0]);
            else
                element->left = NULL;
            if (itr->second[1] != 0)
                element->right = new Node(itr->second[1]);
            else
                element->right = NULL;
        }
    }
}

bool createTree(Node *&treeStart, ifstream &fin, map<int, list<int>> &table)
{
    int id, left, right;
    bool firstTime = true;
    Node *element;
    while (fin >> id >> left >> right)
    {
        if (id == 0)
            break;
        if (firstTime)
            treeStart = new Node(id);
        firstTime = false;
        element = findElementOfTree(id, treeStart, table, 0);

        if (element == NULL)
            return true;
        if (left != 0)
            element->left = new Node(left);
        else
            element->left = NULL;
        if (right != 0)
            element->right = new Node(right);
        else
            element->right = NULL;
    }
    return false;
}

void writeTree(map<int, list<int>> &table, ofstream &fout, bool &reverse)
{
    for (auto itr = table.rbegin(); itr != table.rend(); ++itr)
    {
        fout << itr->first << ": ";
        if (!reverse)
        {
            for (auto itr2 = itr->second.begin(); itr2 != itr->second.end(); ++itr2)
                fout << *itr2 << " ";
        }
        else
        {
            for (auto itr2 = itr->second.rbegin(); itr2 != itr->second.rend(); ++itr2)
                fout << *itr2 << " ";
        }
        fout << endl;
    }
}

int main()
{
    ifstream fin;
    ofstream fout;
    Node *treeStart = NULL;
    map<int, list<int>> table;
    map<int, int[2]> sortedInput;
    bool reverse = false;
    fin.open("team.in");

    if (createTree(treeStart, fin, table))
    {
        table.clear();
        reverse = loadData(sortedInput, fin);
        createTreeSorted(treeStart, sortedInput, table, reverse);
    }

    fin.close();
    fout.open("team.out");
    writeTree(table, fout, reverse);
    fout.close();
    return 0;
}
