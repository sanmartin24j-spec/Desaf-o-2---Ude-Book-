#ifndef NODO_H
#define NODO_H

template <typename T>
class Nodo
{
private:
    T dato;
    Nodo<T>* siguiente;

public:
    Nodo(T valor)
    {
        dato = valor;
        siguiente = nullptr;
    }

    T getDato()
    {
        return dato;
    }

    Nodo<T>* getSiguiente()
    {
        return siguiente;
    }

    void setSiguiente(Nodo<T>* siguienteNuevo)
    {
        siguiente = siguienteNuevo;
    }
};

#endif