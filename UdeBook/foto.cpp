#include "foto.h"

Foto::Foto()
{
}

Foto::Foto(std::string rutaNueva, int cantidadLikes)
{
    ruta = rutaNueva;
    likes = cantidadLikes;
}

std::string Foto::getRuta()
{
    return ruta;
}

int Foto::getLikes()
{
    return likes;
}

void Foto::setRuta(std::string rutaNueva)
{
    ruta = rutaNueva;
}

void Foto::setLikes(int cantidadLikes)
{
    likes = cantidadLikes;
}