#include <iostream>
#include "usuario.h"
#include "foto.h"
#include "mensaje.h"
#include "solicitudamistad.h"
#include "album.h"
#include "sistemaudebook.h"

using namespace std;

int main()
{

    Usuario u1;

    u1.setNombreUsuario("Jonathan");
    u1.setCorreo("jonathan@email.com");
    u1.setContrasena("desafio2");

    cout << "Usuario: " << u1.getNombreUsuario() << endl;
    cout << "Correo: " << u1.getCorreo() << endl;


    Mensaje m1("Hola", "12/10/2026");

    cout << "Mensaje: " << m1.getTexto() << endl;
    cout << "Leido antes: " << m1.getLeido() << endl;

    m1.marcarLeido();

    cout << "Leido despues: " << m1.getLeido() << endl;


    SolicitudAmistad s1("Jonathan", "Maria");

    cout << "Solicitud: " << s1.getEstado() << endl;

    s1.marcarAceptada();

    cout << "Solicitud despues: " << s1.getEstado() << endl;




    Album album("Familia", 0);

    Foto f1("foto1.jpg", 3);
    Foto f2("foto2.jpg", 7);

    album.agregarFoto(&f1);
    album.agregarFoto(&f2);

    cout << endl;
    cout << "Album: " << album.getNombre() << endl;
    cout << "Cantidad de fotos: "
         << album.getCantidadFotos() << endl;

    album.mostrarFotos();




    SistemaUdeBook sistema;

    Usuario ana("Ana", "ana@email.com", "111");
    Usuario luis("Luis", "luis@email.com", "222");
    Usuario marta("Marta", "marta@email.com", "333");
    Usuario diego("Diego", "diego@email.com", "444");

    Usuario c1("Candidato1", "c1@email.com", "1");
    Usuario c2("Candidato2", "c2@email.com", "2");
    Usuario c3("Candidato3", "c3@email.com", "3");
    Usuario c4("Candidato4", "c4@email.com", "4");
    Usuario c5("Candidato5", "c5@email.com", "5");
    Usuario c6("Candidato6", "c6@email.com", "6");
    Usuario c7("Candidato7", "c7@email.com", "7");
    Usuario c8("Candidato8", "c8@email.com", "8");
    Usuario c9("Candidato9", "c9@email.com", "9");
    Usuario c10("Candidato10", "c10@email.com", "10");
    Usuario c11("Candidato11", "c11@email.com", "11");
    Usuario c12("Candidato12", "c12@email.com", "12");



    sistema.agregarUsuario(&ana);
    sistema.agregarUsuario(&luis);
    sistema.agregarUsuario(&marta);
    sistema.agregarUsuario(&diego);

    sistema.agregarUsuario(&c1);
    sistema.agregarUsuario(&c2);
    sistema.agregarUsuario(&c3);
    sistema.agregarUsuario(&c4);
    sistema.agregarUsuario(&c5);
    sistema.agregarUsuario(&c6);
    sistema.agregarUsuario(&c7);
    sistema.agregarUsuario(&c8);
    sistema.agregarUsuario(&c9);
    sistema.agregarUsuario(&c10);
    sistema.agregarUsuario(&c11);
    sistema.agregarUsuario(&c12);


    cout << endl;
    cout << "Usuarios registrados: "
         << sistema.getCantidadUsuarios() << endl;




    sistema.crearMatrizAmistad(
        sistema.getCantidadUsuarios()
        );




    sistema.hacerAmigosPorNombre("Ana", "Luis");
    sistema.hacerAmigosPorNombre("Ana", "Marta");
    sistema.hacerAmigosPorNombre("Ana", "Diego");



    sistema.hacerAmigosPorNombre("Luis", "Candidato1");
    sistema.hacerAmigosPorNombre("Luis", "Candidato2");
    sistema.hacerAmigosPorNombre("Luis", "Candidato3");
    sistema.hacerAmigosPorNombre("Luis", "Candidato4");
    sistema.hacerAmigosPorNombre("Luis", "Candidato5");
    sistema.hacerAmigosPorNombre("Luis", "Candidato6");
    sistema.hacerAmigosPorNombre("Luis", "Candidato7");
    sistema.hacerAmigosPorNombre("Luis", "Candidato8");
    sistema.hacerAmigosPorNombre("Luis", "Candidato9");
    sistema.hacerAmigosPorNombre("Luis", "Candidato10");
    sistema.hacerAmigosPorNombre("Luis", "Candidato11");
    sistema.hacerAmigosPorNombre("Luis", "Candidato12");




    sistema.hacerAmigosPorNombre("Marta", "Candidato1");
    sistema.hacerAmigosPorNombre("Marta", "Candidato2");
    sistema.hacerAmigosPorNombre("Marta", "Candidato3");
    sistema.hacerAmigosPorNombre("Marta", "Candidato4");
    sistema.hacerAmigosPorNombre("Marta", "Candidato5");
    sistema.hacerAmigosPorNombre("Marta", "Candidato6");
    sistema.hacerAmigosPorNombre("Marta", "Candidato7");
    sistema.hacerAmigosPorNombre("Marta", "Candidato8");




    sistema.hacerAmigosPorNombre("Diego", "Candidato1");
    sistema.hacerAmigosPorNombre("Diego", "Candidato2");
    sistema.hacerAmigosPorNombre("Diego", "Candidato3");
    sistema.hacerAmigosPorNombre("Diego", "Candidato4");




    Usuario* encontrado = sistema.buscarUsuario("Ana");

    if (encontrado != nullptr)
    {
        cout << endl;
        cout << "Usuario encontrado: "
             << encontrado->getNombreUsuario()
             << endl;
    }



    int indiceAna =
        sistema.buscarIndiceUsuario("Ana");

    cout << endl;
    cout << "12 sugerencias para Ana:" << endl;

    sistema.sugerirAmistades(indiceAna, 12);


    return 0;
}