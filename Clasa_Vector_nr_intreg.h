#ifndef CLASA_VECTOR_NR_INTREG_H_INCLUDED
#define CLASA_VECTOR_NR_INTREG_H_INCLUDED
#include <iostream>
#include "Clasa_Nr_intreg.h"
#pragma once

using namespace std;

class vector_nr_intregi
{
    unsigned int nr_elem;
    nr_intreg *v;
    public:
    vector_nr_intregi(int);
    friend istream & operator>>(istream &, vector_nr_intregi &);
    friend ostream & operator<<(ostream &, const vector_nr_intregi &);
    nr_intreg operator*(vector_nr_intregi &);
    nr_intreg max_abs();
};

#endif // CLASA_VECTOR_NR_INTREG_H_INCLUDED
