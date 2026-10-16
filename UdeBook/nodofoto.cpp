#include "nodofoto.h"

NodoFoto::NodoFoto(Foto* fotoNueva)
{
    dato = fotoNueva;
    siguiente = nullptr;
}

Foto* NodoFoto::getDato()
{
    return dato;
}

NodoFoto* NodoFoto::getSiguiente()
{
    return siguiente;
}

void NodoFoto::setSiguiente(NodoFoto* siguienteNuevo)
{
    siguiente = siguienteNuevo;
}