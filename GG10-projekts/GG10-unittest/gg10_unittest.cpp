#include <iostream>
#include <stdio.h>
#include <string.h>
#include "../GG10/funkcija.h"

using namespace std;

int test1()
{
    // Tests, kad atrod elementus, kurus mest ārā
    node *third = new node;
    third->next = NULL;
    third->val = 3;
    node *second = new node;
    second->next = third;
    second->val = 2;
    node *first = new node;
    first->next = second;
    first->val = 1;
    int n = 2;
    try
    {
        throwElements(first, n);
    }
    catch (char const *z)
    {
        cout << z << endl;
        free(first);
        free(second);
        free(third);
        return 0;
    }
    free(first);
    free(second);
    free(third);
    return 1;
}

int test2()
{
    // Tests, kad neatrod elementus, kurus mest ārā
    node *third = new node;
    third->next = NULL;
    third->val = 3;
    node *second = new node;
    second->next = third;
    second->val = 2;
    node *first = new node;
    first->next = second;
    first->val = 1;
    int n = 4;
    try
    {
        throwElements(first, n);
    }
    catch (char const *z)
    {
        cout << z << endl;
        free(first);
        free(second);
        free(third);
        return 0;
    }
    free(first);
    free(second);
    free(third);
    return 1;
}

int test3()
{
    // Tests, kad pirmā norāde ir NULL (tukša)
    node *first = NULL;
    int n = 8;
    try
    {
        throwElements(first, n);
    }
    catch (char const *z)
    {
        if (!strcmp("navFirst", z))
        {
            // cout << "Test 3 iznemums. Nav ievadits neviens skaitlis."<< endl;
            return 1;
        }
    }
    return 0;
}

int test4()
{
    // Tests, kad skaitlis, pēc kura mest ārā, ir nulle (tukšs)
    node *first = new node;
    int n = 0;
    try
    {
        throwElements(first, n);
    }
    catch (char const *z)
    {
        free(first);
        if (!strcmp("navN", z))
        {
            // cout << "Test 4 iznemums. Nav ievadits skaitlis, pec kura mest ara."<< endl;
            return 1;
        }
    }
    free(first);
    return 0;
}

int main()
{
    cout << "tests1: " << test1() << endl;
    cout << "tests2: " << test2() << endl;
    cout << "tests3: " << test3() << endl;
    cout << "tests4: " << test4() << endl;
    return 0;
}
/*
Testa plāns:
Tests1 - tiek iziets
Tests2 - tiek iziets
Tests3 - tiek iziets
Tests4 - tiek iziets
*/
