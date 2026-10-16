#ifndef FOTO_H
#define FOTO_H
#include <iostream>
#include <string>

class Foto

{
private:
    std::string ruta;
    int likes;

public:
    Foto();
    Foto(std::string rutaNueva, int cantidadLikes);

    std::string getRuta() const;
    int getLikes() const;

    void setRuta(std::string rutaNueva);
    void setLikes(int cantidadLikes);

};


std::ostream& operator<<(std::ostream& salida, const Foto& foto);

#endif