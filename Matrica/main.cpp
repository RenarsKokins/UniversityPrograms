#include "Matrica.h"
#include <iostream>
using namespace std;

int main()
{
    Matrica mat(5, 7);

    mat.sumrin(2);
    // mat.drukat();

    Matrica *mat1 = new Matrica(5, 7);
    // mat1->drukat();

    delete mat1;

    return 0;
}
