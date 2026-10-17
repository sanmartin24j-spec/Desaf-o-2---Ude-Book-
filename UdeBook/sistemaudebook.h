#ifndef SISTEMAUDEBOOK_H
#define SISTEMAUDEBOOK_H
#include "usuario.h"

class SistemaUdeBook
{
private:
    Usuario** usuarios;
    int cantidadUsuarios;
    int capacidadUsuarios;
    bool** matrizAmistad;
    int tamanoMatriz;

public:
    SistemaUdeBook();
    ~SistemaUdeBook();
    void agregarUsuario(Usuario* usuarioNuevo);
    int getCantidadUsuarios();
    Usuario* buscarUsuario(std::string nombreBuscado);
    void crearMatrizAmistad(int tamano);
    void hacerAmigos(int i, int j);
    bool sonAmigos(int i, int j);
    int buscarIndiceUsuario(std::string nombreBuscado);
    void hacerAmigosPorNombre(std::string nombre1, std::string nombre2);
    void sugerirAmistades(int indiceUsuario, int K);
    int contarAmigosEnComun(int i, int j);
};

#endif // SISTEMAUDEBOOK_H
