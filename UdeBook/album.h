#ifndef ALBUM_H
#define ALBUM_H
#include "foto.h"
#include "listafotos.h"
#include <string>

class Album
{
private:
std::string nombre;
int cantidadFotos;
ListaFotos fotos;
public:
Album();
Album(std::string nombreNuevo, int cantidadInicial);

std::string getNombre();
int getCantidadFotos();

void setNombre(std::string nombreNuevo);
void agregarFoto(Foto* fotoNueva);
void mostrarFotos();
};

#endif // ALBUM_H
