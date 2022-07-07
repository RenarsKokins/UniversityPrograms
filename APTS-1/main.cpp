#include <fstream>
using namespace std;

struct Ieraksts
{
    unsigned int time;
    char action;
    char persKods[12];
    char cd[100];
    Ieraksts *last = NULL;
    Ieraksts *next = NULL;
};

int compare(char a[], char b[])
{
    for (int i = 0; a[i] != '\0' | b[i] != '\0'; i++)
    {
        if (a[i] != b[i])
            return 0;
    }
    return 1;
}

void deleteNode(Ieraksts **head_ref, Ieraksts *del)
{
    if (*head_ref == NULL || del == NULL)
    {
        return;
    }
    if (*head_ref == del)
    {
        *head_ref = del->next;
    }
    if (del->next != NULL)
    {
        del->next->last = del->last;
    }
    if (del->last != NULL)
    {
        del->last->next = del->next;
    }
    free(del);
    return;
}

void createEntries(ifstream &fin, Ieraksts *&aStart, Ieraksts *&bStart)
{
    Ieraksts entry, *current, *aLast = NULL, *bLast = NULL;
    while (fin >> entry.time >> entry.action >> entry.persKods >> entry.cd)
    {
        if (entry.action == 'A')
        {
            current = new Ieraksts;
            *current = entry;
            if (aStart == NULL)
                aStart = current;
            if (aLast == NULL)
                aLast = current;
            else
            {
                aLast->next = current;
                current->last = aLast;
                aLast = current;
            }
        }
        else
        {
            current = new Ieraksts;
            *current = entry;
            if (bStart == NULL)
                bStart = current;
            if (bLast == NULL)
                bLast = current;
            else
            {
                bLast->next = current;
                current->last = bLast;
                bLast = current;
            }
        }
    }
}

void writeToFile(ofstream &fout, Ieraksts *&aStart, Ieraksts *&bStart)
{
    Ieraksts *aCurrent = aStart, *bCurrent = bStart, *temp = NULL;
    bool atleastOne = false, didTheThing = false;

    while (true)
    {
        if (aCurrent == NULL)
            break;
        bCurrent = bStart;
        didTheThing = false;
        while (true)
        {
            if (bCurrent == NULL)
                break;
            if (compare(aCurrent->cd, bCurrent->cd))
            {
                fout << max(aCurrent->time, bCurrent->time) << " " << aCurrent->persKods << " " << bCurrent->persKods << endl;
                deleteNode(&aStart, aCurrent);
                deleteNode(&bStart, bCurrent);
                aCurrent = aStart;
                bCurrent = bStart;

                atleastOne = true;
                didTheThing = true;
                break;
            }
            bCurrent = bCurrent->next;
        }
        if (!didTheThing)
            aCurrent = aCurrent->next;
    }
    if (!atleastOne)
        fout << 0;
}

int main()
{
    ifstream fin;
    ofstream fout;
    Ieraksts *aStart = NULL;
    Ieraksts *bStart = NULL;
    fin.open("exchange.in");
    createEntries(fin, aStart, bStart);
    fin.close();

    fout.open("exchange.out");
    writeToFile(fout, aStart, bStart);
    fout.close();

    return 0;
}