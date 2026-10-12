#include "mensaje.h"

Mensaje::Mensaje() {leido = false;}

void Mensaje::marcarLeido()
{
    leido = true;
}
Mensaje::Mensaje(std::string textoNuevo, std::string fechaNueva)
{
    texto = textoNuevo;
    fecha = fechaNueva;
    leido = false;
}

std::string Mensaje::getTexto()
{
    return texto;
}

bool Mensaje::getLeido()
{
    return leido;
}

std::string Mensaje::getFecha()
{
    return fecha;
}

void Mensaje::setTexto(std::string textoNuevo)
{
    texto = textoNuevo;
}

void Mensaje::setFecha(std::string fechaNueva)
{
    fecha = fechaNueva;
}