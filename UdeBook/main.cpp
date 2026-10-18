#include <iostream>
#include "usuario.h"
//#include "foto.h"
//#include "mensaje.h"
#include "solicitudamistad.h"
//#include "album.h"
#include "sistemaudebook.h"

using namespace std;

int main()
{

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

    sistema.crearMatrizAmistad( sistema.getCantidadUsuarios() );


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

 //s
    int indiceAna = sistema.buscarIndiceUsuario("Ana");

    long long iteraciones = 0;

    cout << "12 sugerencias para Ana:" << endl;

    sistema.sugerirAmistades(indiceAna,12,iteraciones );

    cout << "Iteraciones requeridas: "<< iteraciones<< endl;

 //ms

    long long iteracionesMejor = 0;

    int mejor =sistema.obtenerMejorSugerencia(indiceAna,iteracionesMejor);

    Usuario* mejorUsuario =
        sistema.getUsuarioPorIndice(mejor);

    if (mejorUsuario != nullptr)
    {
        cout << "Mejor sugerencia: "<< mejorUsuario->getNombreUsuario()<< endl;
        bool enviada = sistema.enviarSolicitud("Ana",mejorUsuario->getNombreUsuario());

        if (enviada)
        {
            cout << "Solicitud enviada de Ana a "<< mejorUsuario->getNombreUsuario()<< endl;
        }
        else
        {
        cout << "No se pudo enviar la solicitud."<< endl;
        }


    }

//1000
    SistemaUdeBook sistema1000;

    Usuario* usuariosPrueba =
        new Usuario[1000];

    for (int i = 0; i < 1000; i++)
    {
        std::string nombre ="Usuario" + std::to_string(i);

        std::string correo ="usuario" + std::to_string(i)+ "@email.com";

        usuariosPrueba[i].setNombreUsuario(nombre);
        usuariosPrueba[i].setCorreo(correo);
        usuariosPrueba[i].setContrasena("1234");

        sistema1000.agregarUsuario( &usuariosPrueba[i]);
    }

    //pruebasolam

    cout << "Usuarios entorno de prueba: "<< sistema1000.getCantidadUsuarios()<< endl;

    sistema1000.crearMatrizAmistad(sistema1000.getCantidadUsuarios());

    cout << "Memoria estructural SistemaUdeBook: "<< sistema1000.calcularMemoriaEstructural()<< " bytes"<< endl;

    long long memoriaUsuarios =1000LL * sizeof(Usuario);

    cout << "Memoria base de 1000 objetos Usuario: " << memoriaUsuarios<< " bytes"<< endl;

    delete[] usuariosPrueba;

    std::cout << "\n--- PRUEBA DE SOLICITUDES ---\n";

    bool enviada = sistema.enviarSolicitud("Ana", "Candidato1");

    std::cout << "Solicitud enviada: " << enviada << std::endl;

    sistema.mostrarSolicitudesPendientes("Candidato1");

    bool aceptada = sistema.aceptarSolicitud("Candidato1", "Ana");

    std::cout << "Solicitud aceptada: " << aceptada << std::endl;

    int i = sistema.buscarIndiceUsuario("Ana");
    int j = sistema.buscarIndiceUsuario("Candidato1");

    std::cout << "Ahora son amigos: " << sistema.sonAmigos(i, j) << std::endl;

    std::cout << "Solicitud entre amigos: " << sistema.enviarSolicitud("Ana", "Candidato1") << std::endl;

    // No debe permitirse una solicitud a uno mismo.
    std::cout << "Solicitud a si mismo: " << sistema.enviarSolicitud("Ana", "Ana")<< std::endl;

    std::cout << "Usuario inexistente: "<< sistema.enviarSolicitud("Ana", "Pedro") << std::endl;

    // Primera solicitud valida.
    std::cout << "Primera solicitud: "<< sistema.enviarSolicitud("Ana", "Candidato2")<< std::endl;

    // No debe permitirse duplicarla.
    std::cout << "Solicitud duplicada: "<< sistema.enviarSolicitud("Ana", "Candidato2") << std::endl;

    std::cout << "Solicitud inversa: "<< sistema.enviarSolicitud("Candidato2", "Ana") << std::endl;




    return 0;
}