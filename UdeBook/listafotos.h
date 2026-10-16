#ifndef LISTAFOTOS_H
#define LISTAFOTOS_H

#include "nodofoto.h"

class ListaFotos
{
private:
    NodoFoto* primero;

public:
    ListaFotos();
    ~ListaFotos();

    void agregar(Foto* fotoNueva);
    void mostrar();

};

#endif