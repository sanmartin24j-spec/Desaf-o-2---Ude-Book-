#include "sistemaudebook.h"
#include <iostream>

SistemaUdeBook::SistemaUdeBook() {
    usuarios = nullptr;
    cantidadUsuarios = 0;
    capacidadUsuarios = 0;
    matrizAmistad = nullptr;
    tamanoMatriz = 0;
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

void SistemaUdeBook::sugerirAmistades(int indiceUsuario, int K)
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
        // No sugerirse a sí mismo
        if (candidato == indiceUsuario)
            continue;

        // No sugerir amigos actuales
        if (matrizAmistad[indiceUsuario][candidato])
            continue;

        int comunes = contarAmigosEnComun(indiceUsuario, candidato);

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
        for (int j = i + 1; j < cantidadCandidatos; j++)
        {
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
        std::cout << i + 1 << ". "
                  << usuarios[indicesCandidatos[i]]->getNombreUsuario()
                  << " - amigos en comun: "
                  << coincidencias[i]
                  << std::endl;
    }

    delete[] indicesCandidatos;
    delete[] coincidencias;
}

int SistemaUdeBook::contarAmigosEnComun(int i, int j)
{
    int contador = 0;

    for (int k = 0; k < cantidadUsuarios; k++)
    {
        if (matrizAmistad[i][k] && matrizAmistad[j][k])
        {
            contador++;
        }
    }

    return contador;
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