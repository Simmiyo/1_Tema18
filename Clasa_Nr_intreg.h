#ifndef CLASA_NR_INTREG_H_INCLUDED
#define CLASA_NR_INTREG_H_INCLUDED
#include <iostream>
#include "Clasa_Lista.h"
#pragma once

class vector_nr_intregi;

class nr_intreg
{
    bool semn;
    lista modul;
    public:
    nr_intreg();
    ~nr_intreg();
    nr_intreg(const nr_intreg &); //constructor de copiere
    friend istream & operator>>(istream &, nr_intreg &);
    friend ostream & operator<<(ostream &, const nr_intreg &);
    nr_intreg operator=(const nr_intreg &);
    bool operator==(const nr_intreg &);
    nr_intreg operator+(nr_intreg );
    nr_intreg operator-(nr_intreg );
    nr_intreg operator*(nr_intreg &);
    nr_intreg max_abs(nr_intreg &);
    friend class vector_nr_intregi;
    friend istream & operator>>(istream &, vector_nr_intregi &);
    friend ostream & operator<<(ostream &, const vector_nr_intregi &);
};

#endif // CLASA_NR_INTREG_H_INCLUDED
