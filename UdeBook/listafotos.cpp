#include "listafotos.h"
#include <iostream>

ListaFotos::ListaFotos()
{
    primero = nullptr;
}

void ListaFotos::agregar(Foto* fotoNueva)
{
    NodoFoto* nuevo = new NodoFoto(fotoNueva);

    if (primero == nullptr)
    {
        primero = nuevo;
    }
    else
    {
        NodoFoto* actual = primero;

        while (actual->getSiguiente() != nullptr)
        {
            actual = actual->getSiguiente();
        }

        actual->setSiguiente(nuevo);
    }
}

ListaFotos::~ListaFotos()
{
    NodoFoto* actual = primero;

    while (actual != nullptr)
    {
        NodoFoto* siguiente = actual->getSiguiente();

        delete actual;

        actual = siguiente;
    }
}

void ListaFotos::mostrar()
{
    NodoFoto* actual = primero;

    while (actual != nullptr)
    {
        Foto* fotoActual = actual->getDato();

        std::cout << fotoActual->getRuta()
                  << " Likes: "
                  << fotoActual->getLikes()
                  << std::endl;

        actual = actual->getSiguiente();
    }
}