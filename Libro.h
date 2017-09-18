#ifndef LIBRO_H
#define LIBRO_H

#include <iostream>

using namespace std;

class Libro
{
public:

    int existencias;
    string nombre;
    string autor;

    Libro(string nombre, string autor, int existencias);
    virtual ~Libro();
protected:
private:
};

#endif // LIBRO_H
