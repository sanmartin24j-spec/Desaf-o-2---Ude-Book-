#include "sistemaudebook.h"
#include <iostream>

SistemaUdeBook::SistemaUdeBook() {
    usuarios = nullptr;
    cantidadUsuarios = 0;
    capacidadUsuarios = 0;
    matrizAmistad = nullptr;
    tamanoMatriz = 0;
    solicitudes = nullptr;
    cantidadSolicitudes = 0;
    capacidadSolicitudes = 0;
}


void SistemaUdeBook::agregarUsuario(Usuario* usuarioNuevo)
{
    if (cantidadUsuarios >= capacidadUsuarios)
    {
        int nuevaCapacidad;

        if (capacidadUsuarios == 0)
            nuevaCapacidad = 10;
        else
            nuevaCapacidad = capacidadUsuarios * 2;

        Usuario** nuevosUsuarios = new Usuario*[nuevaCapacidad]{};

        for (int i = 0; i < cantidadUsuarios; i++)
        {
            nuevosUsuarios[i] = usuarios[i];
        }

        delete[] usuarios;

        usuarios = nuevosUsuarios;
        capacidadUsuarios = nuevaCapacidad;
    }

    usuarios[cantidadUsuarios] = usuarioNuevo;
    cantidadUsuarios++;
}

int SistemaUdeBook::getCantidadUsuarios()
{
    return cantidadUsuarios;
}

Usuario* SistemaUdeBook::buscarUsuario(std::string nombreBuscado)
{
    for (int i = 0; i < cantidadUsuarios; i++)
    {
        if (usuarios[i]->getNombreUsuario() == nombreBuscado)
        {
            return usuarios[i];
        }
    }

    return nullptr;
}


void SistemaUdeBook::crearMatrizAmistad(int tamano)
{
    matrizAmistad = new bool*[tamano];

    for (int i = 0; i < tamano; i++)
    {
        matrizAmistad[i] = new bool[tamano];

        for (int j = 0; j < tamano; j++)
        {
            matrizAmistad[i][j] = false;
        }
    }

    tamanoMatriz = tamano;
}

void SistemaUdeBook::hacerAmigos(int i, int j)
{
    if (i >= 0 && i < tamanoMatriz &&
        j >= 0 && j < tamanoMatriz &&
        i != j)
    {
        matrizAmistad[i][j] = true;
        matrizAmistad[j][i] = true;
    }
}

bool SistemaUdeBook::sonAmigos(int i, int j)
{
    if (i >= 0 && i < tamanoMatriz &&
        j >= 0 && j < tamanoMatriz)
    {
        return matrizAmistad[i][j];
    }

    return false;
}

int SistemaUdeBook::buscarIndiceUsuario(std::string nombreBuscado)
{
    for (int i = 0; i < cantidadUsuarios; i++)
    {
        if (usuarios[i]->getNombreUsuario() == nombreBuscado)
        {
            return i;
        }
    }

    return -1;
}

void SistemaUdeBook::hacerAmigosPorNombre(std::string nombre1, std::string nombre2)
{
    int i = buscarIndiceUsuario(nombre1);
    int j = buscarIndiceUsuario(nombre2);

    if (i != -1 && j != -1)
    {
        hacerAmigos(i, j);
    }
}

void SistemaUdeBook::sugerirAmistades(int indiceUsuario,int K,long long &iteraciones)
{
    if (indiceUsuario < 0 || indiceUsuario >= cantidadUsuarios)
        return;

    if (K < 1)
        return;

    if (K > 20)
        K = 20;

    int* indicesCandidatos = new int[cantidadUsuarios];
    int* coincidencias = new int[cantidadUsuarios];

    int cantidadCandidatos = 0;

    // Buscar candidatos
    for (int candidato = 0; candidato < cantidadUsuarios; candidato++)
    {
        iteraciones++;
        // No sugerirse a sí mismo
        if (candidato == indiceUsuario)
            continue;

        // No sugerir amigos actuales
        if (matrizAmistad[indiceUsuario][candidato])
            continue;

        int comunes = contarAmigosEnComun(indiceUsuario, candidato, iteraciones);

        // Solo sugerimos amigos de amigos
        if (comunes > 0)
        {
            indicesCandidatos[cantidadCandidatos] = candidato;
            coincidencias[cantidadCandidatos] = comunes;

            cantidadCandidatos++;
        }
    }

    // Ordenar de mayor a menor por amigos en común
    for (int i = 0; i < cantidadCandidatos - 1; i++)
    {
        iteraciones++;
        for (int j = i + 1; j < cantidadCandidatos; j++)
        {
            iteraciones++;
            if (coincidencias[j] > coincidencias[i])
            {
                int tempCoincidencia = coincidencias[i];
                coincidencias[i] = coincidencias[j];
                coincidencias[j] = tempCoincidencia;

                int tempIndice = indicesCandidatos[i];
                indicesCandidatos[i] = indicesCandidatos[j];
                indicesCandidatos[j] = tempIndice;
            }
        }
    }

    // Decidir cuántos mostrar
    int cantidadMostrar = K;

    if (cantidadMostrar > cantidadCandidatos)
    {
        cantidadMostrar = cantidadCandidatos;
    }

    // Mostrar sugerencias
    for (int i = 0; i < cantidadMostrar; i++)
    {
        iteraciones++;
        std::cout << i + 1 << ". "
                  << usuarios[indicesCandidatos[i]]->getNombreUsuario()
                  << " - amigos en comun: "
                  << coincidencias[i]
                  << std::endl;
    }
    long long memoriaSugerencias = cantidadUsuarios * sizeof(int) * 2;

    std::cout << "Memoria temporal usada: "<< memoriaSugerencias<< " bytes"<< std::endl;

    delete[] indicesCandidatos;
    delete[] coincidencias;
}

int SistemaUdeBook::contarAmigosEnComun(int i, int j, long long &iteraciones)
{
    int contador = 0;

    for (int k = 0; k < cantidadUsuarios; k++)
    {
        iteraciones++;

        if (matrizAmistad[i][k] && matrizAmistad[j][k])
        {
            contador++;
        }
    }

    return contador;
}


long long SistemaUdeBook::calcularMemoriaEstructural()
{
    long long memoria = 0;

    // Arreglo dinámico de punteros a Usuario
    memoria += capacidadUsuarios * sizeof(Usuario*);

    // Arreglo de punteros a las filas de la matriz
    memoria += tamanoMatriz * sizeof(bool*);

    // Contenido de todas las filas de la matriz
    memoria += tamanoMatriz * tamanoMatriz * sizeof(bool);

    return memoria;
}

int SistemaUdeBook::obtenerMejorSugerencia(int indiceUsuario, long long &iteraciones)
{
    if (indiceUsuario < 0 || indiceUsuario >= cantidadUsuarios)
    {
        return -1;
    }

    int mejorIndice = -1;
    int mayorCoincidencia = 0;

    for (int candidato = 0;candidato < cantidadUsuarios;candidato++)
    {
        iteraciones++;

        if (candidato == indiceUsuario)
        {
            continue;
        }

        if (matrizAmistad[indiceUsuario][candidato])
        {
            continue;
        }

        int comunes =contarAmigosEnComun(indiceUsuario, candidato, iteraciones);

        if (comunes > mayorCoincidencia)
        {
            mayorCoincidencia = comunes;
            mejorIndice = candidato;
        }
    }

    return mejorIndice;
}

Usuario* SistemaUdeBook::getUsuarioPorIndice(int indice)
{
    if (indice >= 0 && indice < cantidadUsuarios)
    {
        return usuarios[indice];
    }

    return nullptr;
}

bool SistemaUdeBook::enviarSolicitud( std::string emisor, std::string receptor)
{
    int i = buscarIndiceUsuario(emisor);
    int j = buscarIndiceUsuario(receptor);

    if (i == -1 || j == -1 || i == j)
    {
        return false;
    }

    if (sonAmigos(i, j))
    {
        return false;
    }

    for (int k = 0; k < cantidadSolicitudes; k++)
    {
        if (solicitudes[k]->getEstado() == "pendiente")
        {
            if ((solicitudes[k]->getEmisor() == emisor &&solicitudes[k]->getReceptor() == receptor) ||(solicitudes[k]->getEmisor() == receptor &&solicitudes[k]->getReceptor() == emisor))
            {
                return false;
            }
        }
    }

    if (cantidadSolicitudes >= capacidadSolicitudes)
    {
        int nuevaCapacidad;

        if (capacidadSolicitudes == 0)
            nuevaCapacidad = 10;
        else
            nuevaCapacidad = capacidadSolicitudes * 2;

        SolicitudAmistad** nuevasSolicitudes =
            new SolicitudAmistad*[nuevaCapacidad];

        for (int k = 0; k < cantidadSolicitudes; k++)
        {
            nuevasSolicitudes[k] = solicitudes[k];
        }

        delete[] solicitudes;

        solicitudes = nuevasSolicitudes;
        capacidadSolicitudes = nuevaCapacidad;
    }

    solicitudes[cantidadSolicitudes] =
        new SolicitudAmistad(emisor, receptor);

    cantidadSolicitudes++;

    return true;
}

void SistemaUdeBook::mostrarSolicitudesPendientes(std::string receptor)
{
    int indice = buscarIndiceUsuario(receptor);

    if (indice == -1)
    {
        std::cout << "El usuario no existe." << std::endl;
        return;
    }

    int contador = 0;

    for (int i = 0; i < cantidadSolicitudes; i++)
    {
        if (solicitudes[i]->getReceptor() == receptor && solicitudes[i]->getEstado() == "pendiente")
        {
            contador++;

            std::cout << contador << " Solicitud de: "<< solicitudes[i]->getEmisor()<< std::endl;
        }
    }

    if (contador == 0)
    {
        std::cout << "No tienes solicitudes pendientes." << std::endl;
    }
}

bool SistemaUdeBook::aceptarSolicitud(std::string receptor,std::string emisor)
{
    int i = buscarIndiceUsuario(receptor);
    int j = buscarIndiceUsuario(emisor);

    if (i == -1 || j == -1 || i == j)
    {
        return false;
    }

    for (int k = 0; k < cantidadSolicitudes; k++)
    {
        if (solicitudes[k]->getReceptor() == receptor &&solicitudes[k]->getEmisor() == emisor &&solicitudes[k]->getEstado() == "pendiente")
        {
            if (sonAmigos(i, j))
            {
                return false;
            }

            hacerAmigos(i, j);

            solicitudes[k]->marcarAceptada();

            return true;
        }
    }

    return false;
}


SistemaUdeBook::~SistemaUdeBook()
{
    delete[] usuarios;

    if (matrizAmistad != nullptr)
    {
        for (int i = 0; i < tamanoMatriz; i++)
        {
            delete[] matrizAmistad[i];
        }

        delete[] matrizAmistad;
    }
}