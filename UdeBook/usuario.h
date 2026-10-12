#ifndef USUARIO_H
#define USUARIO_H
#include <string>
class Usuario
{

private:
std::string nombreUsuario;
std::string fechaNacimiento;
std::string correo;
std::string fotoPerfil;
std::string contrasena;
std::string ciudad;
std::string pais;
std::string fechaInscripcion;

public:
Usuario();
Usuario(std::string nombre, std::string correoNuevo, std::string clave);

std::string getNombreUsuario();
void setNombreUsuario(std::string nuevoNombre);

std::string getCorreo();
void setCorreo(std::string nuevoCorreo);

std::string getContrasena();
void setContrasena(std::string nuevaContrasena);


};

#endif // USUARIO_H
