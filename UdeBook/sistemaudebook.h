#ifndef SISTEMAUDEBOOK_H
#define SISTEMAUDEBOOK_H
#include "usuario.h"
#include "solicitudamistad.h"

class SistemaUdeBook
{
private:
    Usuario** usuarios;
    int cantidadUsuarios;
    int capacidadUsuarios;
    bool** matrizAmistad;
    int tamanoMatriz;
    SolicitudAmistad** solicitudes;
    int cantidadSolicitudes;
    int capacidadSolicitudes;

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
    int buscarIndiceUsuario(std::string nombreBuscado,long long &iteraciones);
    void hacerAmigosPorNombre(std::string nombre1, std::string nombre2);
    void sugerirAmistades(int indiceUsuario, int K, long long &iteraciones);;
    int contarAmigosEnComun(int i, int j, long long &iteraciones);
    long long calcularMemoriaEstructural();
    int obtenerMejorSugerencia(int indiceUsuario, long long &iteraciones);
    Usuario* getUsuarioPorIndice(int indice);
    bool enviarSolicitud(std::string emisor, std::string receptor,long long &iteraciones);
    void mostrarSolicitudesPendientes(std::string receptor);
    bool aceptarSolicitud(std::string receptor, std::string emisor);
    bool aceptarSolicitud(std::string receptor,std::string emisor,long long &iteraciones);
    bool enviarSolicitud(std::string emisor, std::string receptor);

};

#endif // SISTEMAUDEBOOK_H
