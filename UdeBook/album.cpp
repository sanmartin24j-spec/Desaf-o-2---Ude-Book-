#include "album.h"

Album::Album()
{
    cantidadFotos = 0;
}

Album::Album(std::string nombreNuevo, int cantidadInicial)
{
    nombre = nombreNuevo;
    cantidadFotos = cantidadInicial;
}

std::string Album::getNombre()
{
    return nombre;
}

int Album::getCantidadFotos()
{
    return cantidadFotos;
}

void Album::setNombre(std::string nombreNuevo)
{
    nombre = nombreNuevo;
}