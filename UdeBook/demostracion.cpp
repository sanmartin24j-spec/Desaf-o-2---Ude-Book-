#include "demostracion.h"
#include "sistemaudebook.h"
#include "usuario.h"
#include <iostream>
#include <string>

using namespace std;

void demostrarSugerencias1000()
{
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

    long long memoriaUsuarios = 1000LL * sizeof(Usuario);

    long long memoriaEstructural =sistema1000.calcularMemoriaEstructural();
    cout << "Memoria estructural SistemaUdeBook: "<< memoriaEstructural << " bytes" << endl;

    long long memoriaBaseContabilizada =memoriaEstructural + memoriaUsuarios;

    cout << "Memoria base contabilizada: "
         << memoriaBaseContabilizada
         << " bytes" << endl;


    cout << "Memoria base de 1000 objetos Usuario: " << memoriaUsuarios<< " bytes"<< endl;

    cout << "\n========== RESUMEN UDE@BOOK ==========" << endl;

    cout << "Usuarios registrados: "
         << sistema1000.getCantidadUsuarios() << endl;

    cout << "Usuario evaluado: Usuario0" << endl;

    cout << "Sugerencias solicitadas: 12" << endl;

    cout << "Mejor candidato: ";

    if (candidatoMejor != nullptr)
    {
        cout << candidatoMejor->getNombreUsuario() << endl;
    }
    else
    {
        cout << "No encontrado" << endl;
    }

    cout << "Iteraciones para generar sugerencias: "<< iteraciones1000 << endl;

    cout << "Iteraciones para encontrar mejor candidato: "<< iteracionesMejor1000 << endl;

    cout << "Memoria estructural contabilizada: "<< sistema1000.calcularMemoriaEstructural()<< " bytes" << endl;

    cout << "Memoria base de usuarios: "<< memoriaUsuarios << " bytes" << endl;

    cout << "======================================" << endl;


    delete[] usuariosPrueba;
}
