#include "Clasa_Lista.h"

lista :: lista()
{
    unitati = new cifra;
    unitati = NULL;
    dominanta = new cifra;
    dominanta = NULL;
}

lista :: ~lista()
{
    stergere();
}

void lista :: adaugare(int x)
{
    struct cifra *p = new cifra;
    p->val = x;
    p->ant = NULL;
    p->urm = NULL;
    if(unitati == NULL)
        unitati = dominanta = p;
    else
    {
        p->urm = unitati;
        unitati->ant = p;
        unitati = p;
    }
}

void lista :: adaugare_sf(int x)
{
    struct cifra *p = new cifra;
    p->val = x;
    p->urm = NULL;
    p->ant = NULL;
    if(unitati == NULL)
        unitati = dominanta = p;
    else
    {
        p->ant = dominanta;
        dominanta->urm = p;
        dominanta = p;
    }
}

void lista :: stergere()
{
    struct cifra *p = unitati;
    while(p != NULL && p->urm != NULL)
    {
        p = p->urm;
        delete p->ant;
    }
    delete p;
    unitati = dominanta = NULL;
}
