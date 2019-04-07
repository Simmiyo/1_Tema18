#include "Clasa_Nr_intreg.h"

nr_intreg :: nr_intreg()
{
    semn = 1;
}

nr_intreg :: ~nr_intreg()
{
    semn = 1;
    modul.stergere();
}

nr_intreg :: nr_intreg(const nr_intreg &original)
{
    semn = original.semn;
    struct cifra *p = original.modul.unitati;
    while(p!= NULL)
    {
        modul.adaugare_sf(p->val);
        p = p->urm;
    }
}

bool nr_intreg :: operator==(const nr_intreg &num)
{
    if(num.semn != (*this).semn)
        return 0;
    struct cifra *p = modul.dominanta;
    struct cifra *q = num.modul.dominanta;
    while(p != NULL && q != NULL)
    {
        if(p->val != q->val)
            return 0;
        p = p->ant;
        q = q->ant;
    }
    if((p != NULL && q == NULL) || (p == NULL && q != NULL))
        return 0;
    return 1;
}


nr_intreg nr_intreg :: operator=(const nr_intreg &original)
{
    if((*this) == original)
        return *this;
    (*this).modul.stergere();
    semn = original.semn;
    struct cifra *p = original.modul.unitati;
    while( p!= NULL)
    {
        modul.adaugare_sf(p->val);
        p = p->urm;
    }
    return *this;
}

istream & operator>>(istream &intrare, nr_intreg &num)
{
    num.modul.stergere();
    string s; int i;
    intrare >> s;
    if(s[0] == '-')
    {
        num.semn = 0;
        i = 1;
    }
    else
    {
        num.semn = 1;
        i = 0;
    }
    for(int j=i;j<s.length();j++)
    {
        if(s[j]-'0' <= 9 && s[j]-'0' > -1)
            num.modul.adaugare(s[j]-'0');
        else
        {
            cout<<"Numar incorect. Introduceti alt numar:"<<endl;
            num.modul.stergere();
            return intrare>>num;
        }
    }
    return intrare;
}

ostream & operator<<(ostream &iesire,const nr_intreg &num)
{
    if(num.semn == 0)
        iesire << '-';
    struct cifra *p = num.modul.dominanta;
    while(p != NULL)
    {
        iesire << p->val;
        p = p->ant;
    }
    return iesire;
}

nr_intreg nr_intreg :: operator+(nr_intreg num)
{
    if(semn != num.semn)
    {
        if(semn == 0)
        {
            semn = 1;
            return num - *this;
        }
        else
        {
            num.semn = 1;
            return *this - num;
        }
    }
    else
    {
        struct cifra *p = modul.unitati, *q = num.modul.unitati;
        nr_intreg suma;
        suma.semn = semn;
        unsigned short int i = 0;
        while(p != NULL && q != NULL)
        {
            suma.modul.adaugare_sf((p->val + q->val + i) % 10);
            i = (p->val + q->val + i) / 10;
            p = p->urm;
            q = q->urm;
        }
        if(p == NULL && q == NULL)
        {
            if(i > 0)
                suma.modul.adaugare_sf(i);
        }
        else
        {
            if(p == NULL) p = q;
            while(p != NULL)
            {
                suma.modul.adaugare_sf((p->val + i) % 10);
                i = (p->val + i) / 10;
                p = p->urm;
            }
            if(i > 0)
                suma.modul.adaugare_sf(i);
        }
        return suma;
    }
}

nr_intreg nr_intreg :: max_abs(nr_intreg &num)
{
    struct cifra *p = this->modul.dominanta;
    struct cifra *q = num.modul.dominanta;
    while(p != NULL && q != NULL)
    {
        p = p->ant;
        q = q->ant;
    }
    if(p == NULL && q !=NULL)
        return num;
    else if(p != NULL && q == NULL)
        return *this;
    p = this->modul.dominanta;
    q = num.modul.dominanta;
    while (p !=NULL && p->val == q->val)
    {
        p = p->ant;
        q = q->ant;
    }
    if(p != NULL && p->val > q->val)
        return *this;
    else return num;
}

nr_intreg nr_intreg :: operator-(nr_intreg num)
{
    if(semn != num.semn)
    {
        if(num.semn == 0)
            num.semn = 1;
        else num.semn = 0;
        return *this + num;
    }
    else
    {
        if(num.semn == 0)
            num.semn = 1;
        else num.semn = 0;
        nr_intreg diferenta;
        struct cifra *p = new cifra, *q = new cifra;
        nr_intreg a = (*this).max_abs(num);
        if(a == num)
        {
            p = num.modul.unitati;
            q = modul.unitati;
            diferenta.semn = num.semn;
        }
        else
        {
            p = modul.unitati;
            q = num.modul.unitati;
            diferenta.semn = (*this).semn;
        }
        unsigned short int i = 0;
        while(p != NULL && q != NULL)
        {
            diferenta.modul.adaugare_sf((p->val + 10 - i - q->val) % 10);
            if(p->val < q->val)
                i = 1;
            else i = 0;
            p = p->urm;
            q = q->urm;
        }
        if(p == NULL && q == NULL)
        {
            struct cifra *z = diferenta.modul.dominanta;
            while(z->val == 0 && z->ant != NULL)
            {
                diferenta.modul.dominanta = diferenta.modul.dominanta->ant;
                delete z;
                diferenta.modul.dominanta->urm = NULL;
                z = diferenta.modul.dominanta;
            }
            diferenta.modul.dominanta = z;
        }
        else
        {
            while(p != NULL)
            {
                diferenta.modul.adaugare_sf((p->val + 10 - i) % 10);
                if(p->val - i < 0)
                    i = 1;
                else i = 0;
                p = p->urm;
            }
            if(diferenta.modul.dominanta->val == 0)
            {
                diferenta.modul.dominanta = diferenta.modul.dominanta->ant;
                delete diferenta.modul.dominanta->urm;
                diferenta.modul.dominanta->urm = NULL;
            }
        }
        if(diferenta.modul.dominanta->val == 0)
            diferenta.semn = 1;
        return diferenta;
    }
}

nr_intreg nr_intreg :: operator*(nr_intreg &num)
{
    nr_intreg produs, termen, temp;
    unsigned short int i = 0, contor = 0, j;
    produs.modul.adaugare(0);
    struct cifra *p = num.modul.unitati, *q;
    while(p != NULL)
    {
        q = (*this).modul.unitati;
        while(q != NULL)
        {
            termen.modul.adaugare_sf((p->val * q->val + i) % 10);
            i = (p->val * q->val + i) / 10;
            q = q->urm;
        }
        if(i > 0)
            termen.modul.adaugare_sf(i);
        for(j=1;j<=contor;j++)
            termen.modul.adaugare(0);
        contor++;
        produs = produs + termen;
        termen.modul.stergere();
        p = p->urm;
    }
    if(((*this).semn == 0 && num.semn == 0) || ((*this).semn == 1 && num.semn == 1))
        produs.semn = 1;
    if(((*this).semn == 0 && num.semn == 1) || ((*this).semn == 1 && num.semn == 0))
        produs.semn = 0;
    return produs;
}
unsigned short int nr_intreg :: operator[](int poz)
{
    cifra *p = modul.dominanta;
    while(p != NULL && poz > 1)
    {
        p = p->ant;
        poz--;
    }
    if(p != NULL)
        return p->val;
    else return 10;
}
