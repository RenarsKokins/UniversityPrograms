#include <fstream>
using namespace std;

struct leaf
{
    int data;
    struct leaf *left = NULL;
    struct leaf *right = NULL;
};

leaf *searchParent(int key, leaf *leaf)
{
    if (leaf == NULL)
        return NULL;
    if (leaf->left != NULL && key == leaf->left->data)
        return leaf;
    if (leaf->right != NULL && key == leaf->right->data)
        return leaf;
    struct leaf *ptr1 = searchParent(key, leaf->left);
    if (ptr1 != NULL)
        return ptr1;
    struct leaf *ptr2 = searchParent(key, leaf->right);
    if (ptr2 != NULL)
        return ptr2;
    return NULL;
}

void elementCounter(ifstream &fin, int &elementCount)
{
    int r, c1, c2;
    while (fin >> r >> c1 >> c2)
        elementCount++;
    elementCount--;
}

int createTree(ifstream &fin, leaf *&start, int elementCount)
{
    int r, c1 = -1337, c2 = -1337, index = 0;
    struct leaf *leaf;
    struct leaf **leafArray;
    leafArray = new struct leaf *[elementCount]();

    while (fin >> r >> c1 >> c2)
    {
        if (r == 0)
            break;
        leaf = new struct leaf;
        leaf->data = r;
        if (c1 != 0)
        {
            leaf->left = new struct leaf;
            leaf->left->data = c1;
        }
        if (c2 != 0)
        {
            leaf->right = new struct leaf;
            leaf->right->data = c2;
        }
        leafArray[index] = leaf;
        index++;
    }
    if (c1 == -1337 || c2 == -1337)
        return -1;

    leaf = NULL;
    bool foundRoot = true;
    for (int i = 0; i < elementCount; i++)
    {
        foundRoot = true;
        for (int j = 0; j < elementCount; j++)
        {
            if (i == j)
            {
                if (leafArray[i] == NULL)
                    foundRoot = false;
                continue;
            }
            leaf = searchParent(leafArray[i]->data, leafArray[j]);
            if (leaf != NULL)
            {
                if (leaf->right != NULL && leaf->right->data == leafArray[i]->data)
                {
                    delete leaf->right;
                    leaf->right = leafArray[i];
                }
                if (leaf->left != NULL && leaf->left->data == leafArray[i]->data)
                {
                    delete leaf->left;
                    leaf->left = leafArray[i];
                }
                foundRoot = false;
                break;
            }
        }
        if (foundRoot)
            start = leafArray[i];
    }
    return 0;
}

void printGivenLevel(leaf *root, int level, ofstream &fout);
int height(leaf *leaf);
leaf *newleaf(int data);

void writeTree(leaf *root, ofstream &fout)
{
    int h = height(root);
    int i;
    for (i = h; i >= 1; i--)
    {
        fout << i - 1 << ": ";
        printGivenLevel(root, i, fout);
        fout << endl;
    }
}

void printGivenLevel(leaf *root, int level, ofstream &fout)
{
    if (root == NULL)
        return;
    if (level == 1)
        fout << root->data << " ";
    else if (level > 1)
    {
        printGivenLevel(root->left, level - 1, fout);
        printGivenLevel(root->right, level - 1, fout);
    }
}

int height(leaf *leaf)
{
    if (leaf == NULL)
        return 0;
    else
    {
        int lheight = height(leaf->left);
        int rheight = height(leaf->right);

        if (lheight > rheight)
            return (lheight + 1);
        else
            return (rheight + 1);
    }
}

int main()
{
    ifstream fin;
    ofstream fout;
    leaf *start = NULL;
    int elementCount = 0, ok;

    fin.open("team.in");
    elementCounter(fin, elementCount);
    fin.clear();
    fin.seekg(0);
    ok = createTree(fin, start, elementCount);
    fin.close();
    fout.open("team.out");
    if (ok == -1)
    {
        fout << 0;
        return -1;
    }
    writeTree(start, fout);
    fout.close();
    return 0;
}