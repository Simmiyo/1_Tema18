#ifndef CLASA_LISTA_H_INCLUDED
#define CLASA_LISTA_H_INCLUDED
#include <iostream>
#pragma once

using namespace std;

struct cifra
{
    int val;
    cifra *urm;
    cifra *ant;
};

class nr_intreg;
class vector_nr_intregi;

class lista
{
    struct cifra *unitati, *dominanta;
    public:
    lista();
    ~lista();
    void adaugare(int);
    void adaugare_sf(int);
    void stergere();
    friend ostream & operator<<(ostream &, const nr_intreg &);
    friend class nr_intreg;
};

#endif // CLASA_LISTA_H_INCLUDED
