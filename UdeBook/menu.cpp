#include "menu.h"
#include "demostracion.h"
#include <iostream>
#include <limits>

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

void ejecutarMenuPrincipal()
{
    int opcion;

    do
    {
        cout << "\n========== UDE@BOOK ==========" << endl;
        cout << "1. Demostracion con 1000 usuarios" << endl;
        cout << "0. Salir" << endl;
        cout << "Seleccione una opcion: ";

        if (!(cin >> opcion))
        {
            cin.clear();
            cin.ignore(
                numeric_limits<streamsize>::max(), '\n'
                );

            cout << "Debe ingresar un numero." << endl;
            continue;
        }

        switch (opcion)
        {
        case 1:
            demostrarSugerencias1000();
            break;

        case 0:
            cout << "Hasta pronto." << endl;
            break;

        default:
            cout << "Opcion no valida." << endl;
            break;
        }

    } while (opcion != 0);
}