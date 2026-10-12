#include "usuario.h"

Usuario::Usuario() {}

std::string Usuario::getNombreUsuario()
{
    return nombreUsuario;
}

void Usuario::setNombreUsuario(std::string nuevoNombre)
{
    nombreUsuario = nuevoNombre;
}

std::string Usuario::getCorreo()
{
    return correo;
}

void Usuario::setCorreo(std::string nuevoCorreo)
{
    correo = nuevoCorreo;
}

std::string Usuario::getContrasena()
{
    return contrasena;
}

void Usuario::setContrasena(std::string nuevaContrasena)
{
    contrasena = nuevaContrasena;
}

Usuario::Usuario(std::string nombre, std::string correoNuevo, std::string clave)
{
    nombreUsuario = nombre;
    correo = correoNuevo;
    contrasena = clave;
}