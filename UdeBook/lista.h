#ifndef LISTA_H
#define LISTA_H

#include "nodo.h"
#include <iostream>

template <typename T>
class Lista
{
private:
    Nodo<T>* primero;

public:
    Lista()
    {
        primero = nullptr;
    }
    void agregar(T valor)
    {
        Nodo<T>* nuevo = new Nodo<T>(valor);

        if (primero == nullptr)
        {
            primero = nuevo;
        }
        else
        {
            Nodo<T>* actual = primero;

            while (actual->getSiguiente() != nullptr)
            {
                actual = actual->getSiguiente();
            }

            actual->setSiguiente(nuevo);
        }

    }
    ~Lista()
    {
        Nodo<T>* actual = primero;

        while (actual != nullptr)
        {
            Nodo<T>* siguiente = actual->getSiguiente();

            delete actual;

            actual = siguiente;
        }
    }

    void mostrar()
    {
        Nodo<T>* actual = primero;

        while (actual != nullptr)
        {
            std::cout << actual->getDato() << " ";
            actual = actual->getSiguiente();
        }

        std::cout << std::endl;
    }

};

#endif