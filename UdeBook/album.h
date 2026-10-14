#ifndef ALBUM_H
#define ALBUM_H
#include <string>

class Album
{
private:
std::string nombre;
int cantidadFotos;

public:
Album();
Album(std::string nombreNuevo, int cantidadInicial);

std::string getNombre();
int getCantidadFotos();

void setNombre(std::string nombreNuevo);
};

#endif // ALBUM_H
