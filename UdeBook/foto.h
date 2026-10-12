#ifndef FOTO_H
#define FOTO_H

#include <string>

class Foto
{
private:
    std::string ruta;
    int likes;

public:
    Foto();
    Foto(std::string rutaNueva, int cantidadLikes);

    std::string getRuta();
    int getLikes();

    void setRuta(std::string rutaNueva);
    void setLikes(int cantidadLikes);
};

#endif