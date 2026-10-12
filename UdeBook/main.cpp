#include <iostream>
#include "usuario.h"
#include "foto.h"
#include "mensaje.h"
using namespace std;

int main()
{
Usuario u1;

u1.setNombreUsuario("Jonathan");

cout << u1.getNombreUsuario() << endl;

u1.setCorreo("jonathan@email.com");

cout << u1.getCorreo() << endl;

u1.setContrasena("desafio2");

cout <<u1.getContrasena() <<endl;

Usuario u2("Maria", "maria@email.com", "clave123");

cout << u2.getNombreUsuario() << endl;
cout << u2.getCorreo() << endl;
cout << u2.getContrasena() << endl;

Foto foto1("perfil.jpg", 10);

cout << foto1.getRuta() << endl;
cout << foto1.getLikes() << endl;

Mensaje m1("Hola", "12/10/2026");

cout << m1.getTexto() << endl;
cout << m1.getFecha() << endl;
cout << m1.getLeido() << endl;

m1.marcarLeido();

cout << m1.getLeido() << endl;



return 0;
}
