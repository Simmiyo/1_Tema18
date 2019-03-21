#include "Clasa_Vector_nr_intreg.h"

vector_nr_intregi :: vector_nr_intregi(int n)
{
    nr_elem = n;
    v = new nr_intreg[n];
}

istream & operator>>(istream &intrare, vector_nr_intregi &vec)
{
    nr_intreg x;
    for(int i=0;i<vec.nr_elem;i++)
    {
        intrare >> x;
        vec.v[i] = x;
    }
    return intrare;
}

ostream & operator<<(ostream &iesire, const vector_nr_intregi &vec)
{
    for(int i=0;i<vec.nr_elem;i++)
    {
        iesire << vec.v[i] ;
        iesire << " ";
    }
    iesire << endl;
    return iesire;
}

nr_intreg vector_nr_intregi :: operator*(vector_nr_intregi &vec)
{
    nr_intreg produs;
    if((*this).nr_elem != vec.nr_elem)
    {
        cout << "Vectorii nu au lungimi egale.";
        return produs;
    }
    for(int i=0;i<nr_elem;i++)
    {
        produs = produs + (*this).v[i] * vec.v[i];
    }
    return produs;
}

nr_intreg vector_nr_intregi :: max_abs()
{
    nr_intreg x;
    if(nr_elem == 0)
        return x;
    x = v[0];
    for(int i=1;i<nr_elem;i++)
        x = (*this).v[i].max_abs(x);
    return x;
}
