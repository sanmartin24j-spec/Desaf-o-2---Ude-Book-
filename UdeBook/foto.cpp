#include "foto.h"
#include <string>
#include <iostream>

Foto::Foto()
{
}

Foto::Foto(std::string rutaNueva, int cantidadLikes)
{
    ruta = rutaNueva;
    likes = cantidadLikes;
}

std::string Foto::getRuta() const
{
    return ruta;
}

int Foto::getLikes() const
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


std::ostream& operator<<(std::ostream& salida, const Foto& foto)
{
    salida << foto.getRuta()
    << " Likes: "
    << foto.getLikes();

    return salida;
}