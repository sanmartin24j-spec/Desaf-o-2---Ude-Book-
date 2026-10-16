#ifndef NODOFOTO_H
#define NODOFOTO_H

#include "foto.h"

class NodoFoto
{
private:
    Foto* dato;
    NodoFoto* siguiente;

public:
    NodoFoto(Foto* fotoNueva);

    Foto* getDato();
    NodoFoto* getSiguiente();

    void setSiguiente(NodoFoto* siguienteNuevo);
};

#endif