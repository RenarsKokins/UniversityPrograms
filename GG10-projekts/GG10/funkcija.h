#ifndef _GG10
#define _GG10
struct node
{
    int val;
    node *next;
};
void throwElements(node *&first, int &n);
#endif