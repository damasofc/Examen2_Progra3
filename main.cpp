#include <iostream>
#include <list>
#include <fstream>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include "Libro.h"
#include "Evaluador.h"
#include "NodoBinario.h"

using namespace std;
int TAMANO_REGISTRO = 64;


//Escribe todos los datos del libro en un archivo con nombre nombre_archivo en la posicion dada
void escribir(string nombre_archivo, Libro*libro, int posicion)
{
    ofstream out(nombre_archivo.c_str(),ios::in | ios::out);
    if(!out.is_open())
    {
        out.open(nombre_archivo.c_str());
    }
    out.seekp(TAMANO_REGISTRO*posicion);
    out.write(libro->nombre.c_str(),30);
    out.write(libro->autor.c_str(),30);
    out.write((char*)&libro->existencias,4);
    out.close();

}

//Devuelve el libro guardado en el archivo en la posicion dada
Libro* leer(string nombre_archivo, int posicion)
{
    Libro* lib = new Libro("","",-1);
    ifstream in(nombre_archivo.c_str(), ios::in | ios::out | ios::binary);
    in.seekg(TAMANO_REGISTRO*posicion);
    char nombre[30];
    char autor[30];
    int existencias;
    in.read(nombre,30);
    in.read(autor,30);
    in.read((char*)&existencias,4);
    in.close();
    lib->nombre = nombre;
    lib->autor = autor;
    lib->existencias = existencias;
    return lib;
}

//Crea un mapa en base a las llaves y valores dados, asocia cada llave con los valores en la misma posicion
map<string, int> convertirEnMapa(set<string> llaves, set<int> valores)
{
    map<string, int> respuesta;
    set<string>::iterator it = llaves.begin();;
    set<int>::iterator it2 = valores.begin();
    while(!(it == llaves.end()))
    {
        respuesta[*it] = *it2;
        it++;
        it2++;   
    }
    
    return respuesta;
}

//Devuelve una cola con los mismos valores que el parametro exepto que no tiene el ultimo valor
queue<int> popBack(queue<int> cola)
{
    queue<int> respuesta;
    while(!cola.empty())
    {
        cola.pop();
        respuesta.push(cola.back());
    }
    
    return respuesta;
}

//Reemplaza todos los valores del arbol
void reemplazarValores(NodoBinario* raiz, int valor)
{
    if(raiz == NULL)
        return;
    else
    {
        raiz->valor = valor;
        reemplazarValores(raiz->izquierdo,valor);
        reemplazarValores(raiz->derecho,valor);
    }
}

//Devuelve la cantidad de bits "encendidos" o con el valores de 1
int contarBits(char byte)
{
    return -1;
}

int main ()
{
    //Funcion evaluadora
    evaluar();
    return 0;
}

