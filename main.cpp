#include <iostream>
#include <string>
#include <fstream>
#include "Clasa_Lista.h"
#include "Clasa_Nr_intreg.h"
#include "Clasa_Vector_nr_intreg.h"

using namespace std;

int main()
{
    ifstream f;
    f.open("citire.in");
    ofstream g;
    g.open("citire.out");
    nr_intreg x,y,z;
    f >> x >> y;
    g<<x+y<<endl;
    g<<x-y<<endl;
    g<<x*y<<endl;
    vector_nr_intregi A(3),B(3);
    f >> A >> B;
    g << A*B << endl;
    g << A.max_abs();
    return 0;
}
