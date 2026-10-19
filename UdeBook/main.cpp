#include <iostream>
#include "usuario.h"
//#include "foto.h"
//#include "mensaje.h"
#include "solicitudamistad.h"
//#include "album.h"
#include "sistemaudebook.h"

using namespace std;

void mostrarMenuAmistades()
{
    cout << "\n===== Ude@Book =====" << endl;
    cout << "1. Enviar solicitud de amistad" << endl;
    cout << "2. Ver solicitudes pendientes" << endl;
    cout << "3. Aceptar solicitud" << endl;
    cout << "4. Ver sugerencias de amistad" << endl;
    cout << "0. Salir" << endl;
    cout << "Seleccione una opcion: ";
}


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

    for (int i = 1; i <= 3; i++)
    {
        sistema1000.hacerAmigos(0, i);
    }

    for (int i = 4; i <= 15; i++)
    {
        sistema1000.hacerAmigos(1, i);
    }

    for (int i = 4; i <= 11; i++)
    {
        sistema1000.hacerAmigos(2, i);
    }

    for (int i = 4; i <= 7; i++)
    {
        sistema1000.hacerAmigos(3, i);
    }

    cout << "\n--- SUGERENCIAS CON 1000 USUARIOS ---" << endl;

    long long iteraciones1000 = 0;

    int indicePrincipal = sistema1000.buscarIndiceUsuario("Usuario0", iteraciones1000);

    if (indicePrincipal != -1)
    {
        sistema1000.sugerirAmistades(indicePrincipal, 12, iteraciones1000 );

        cout << "Iteraciones totales: "<< iteraciones1000 << endl;
    }

    cout << "\n--- SOLICITUD AL MEJOR CANDIDATO ---" << endl;

    long long iteracionesMejor1000 = 0;

    int mejor1000 = sistema1000.obtenerMejorSugerencia(indicePrincipal, iteracionesMejor1000 );

    Usuario* candidatoMejor =
        sistema1000.getUsuarioPorIndice(mejor1000);

    if (candidatoMejor != nullptr)
    {
        cout << "Mejor candidato: "<< candidatoMejor->getNombreUsuario()<< endl;

        long long iteracionesEnvio1000 = 0;

        bool enviada1000 = sistema1000.enviarSolicitud( "Usuario0", candidatoMejor->getNombreUsuario(), iteracionesEnvio1000);

        cout << "Solicitud enviada: "<< enviada1000 << endl;

        cout << "Iteraciones para encontrar candidato: "<< iteracionesMejor1000 << endl;

        cout << "Iteraciones del envio: " << iteracionesEnvio1000 << endl;
    }

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


    std::cout << "Solicitud a si mismo: " << sistema.enviarSolicitud("Ana", "Ana")<< std::endl;

    std::cout << "Usuario inexistente: "<< sistema.enviarSolicitud("Ana", "Pedro") << std::endl;


    std::cout << "Primera solicitud: "<< sistema.enviarSolicitud("Ana", "Candidato2")<< std::endl;


    std::cout << "Solicitud duplicada: "<< sistema.enviarSolicitud("Ana", "Candidato2") << std::endl;

    std::cout << "Solicitud inversa: "<< sistema.enviarSolicitud("Candidato2", "Ana") << std::endl;

    cout << "\n--- MEMORIA DEL SISTEMA ---" << endl;

    cout << "Usuarios registrados: "<< sistema.getCantidadUsuarios()<< endl;

    cout << "Memoria estructural contabilizada: " << sistema.calcularMemoriaEstructural()<< " bytes" << endl;

    long long iteracionesSolicitud = 0;

    bool resultado = sistema.enviarSolicitud("Marta","Candidato12",iteracionesSolicitud);

    cout << "\n--- MEDICION DE SOLICITUD ---" << endl;

    cout << "Solicitud enviada: " << resultado << endl;

    cout << "Iteraciones realizadas: " << iteracionesSolicitud << endl;

    long long iteracionesAceptar = 0;

    bool aceptadaMedicion = sistema.aceptarSolicitud("Candidato12","Marta",iteracionesAceptar);

    cout << "Solicitud aceptada: "<< aceptadaMedicion << endl;

    cout << "Iteraciones al aceptar: "<< iteracionesAceptar << endl;

    int indiceMarta = sistema.buscarIndiceUsuario("Marta");
    int indiceCandidato12 = sistema.buscarIndiceUsuario("Candidato12");

    cout << "Ahora son amigos: "<< sistema.sonAmigos(indiceMarta, indiceCandidato12)<< endl;


    int opcion;

    do
    {
        mostrarMenuAmistades();

        cin >> opcion;

        switch (opcion)
        {
        case 1:
        {
            string emisor;
            string receptor;
            long long iteraciones = 0;

            cout << "Nombre del usuario que envia: ";
            cin >> emisor;

            cout << "Nombre del usuario que recibe: ";
            cin >> receptor;

            bool enviada = sistema.enviarSolicitud(emisor, receptor, iteraciones);

            if (enviada)
            {
                cout << "Solicitud enviada correctamente." << endl;
            }
            else
            {
                cout << "No se pudo enviar la solicitud." << endl;
            }

            cout << "Iteraciones realizadas: "<< iteraciones << endl;

            break;
        }
        case 2:
        {
            string receptor;

            cout << "Ingrese el nombre del usuario: ";
            cin >> receptor;

            cout << "\n--- SOLICITUDES PENDIENTES ---" << endl;

            sistema.mostrarSolicitudesPendientes(receptor);

            break;
        }
        case 3:
        {
            string receptor;
            string emisor;
            long long iteraciones = 0;

            cout << "Nombre del usuario que acepta: ";
            cin >> receptor;

            cout << "Nombre del usuario que envio la solicitud: ";
            cin >> emisor;

            bool aceptada = sistema.aceptarSolicitud(receptor, emisor, iteraciones);

            if (aceptada)
            {
                cout << "Solicitud aceptada correctamente." << endl;
            }
            else
            {
                cout << "No se pudo aceptar la solicitud." << endl;
            }

            cout << "Iteraciones realizadas: "<< iteraciones << endl;

            break;
        }

        case 4:
        {
            string nombre;
            int K;
            long long iteraciones = 0;

            cout << "Ingrese el nombre del usuario: ";
            cin >> nombre;

            int indice = sistema.buscarIndiceUsuario(nombre, iteraciones );

            if (indice == -1)
            {
                cout << "El usuario no existe." << endl;
                break;
            }

            cout << "Cuantas sugerencias desea ver (1 a 20): ";
            cin >> K;

            if (K < 1 || K > 20)
            {
                cout << "La cantidad debe estar entre 1 y 20." << endl;
                break;
            }

            cout << "\n--- SUGERENCIAS DE AMISTAD ---" << endl;

            sistema.sugerirAmistades(indice, K, iteraciones);

            cout << "Iteraciones realizadas: "
                 << iteraciones << endl;

            break;
        }

        case 0:
            cout << "Saliendo de Ude@Book..." << endl;
            break;

        default:
            cout << "Opcion no valida." << endl;
            break;
        }


    } while (opcion != 0);


    return 0;
}