#ifndef MENSAJE_H
#define MENSAJE_H

#include <string>

class Mensaje
{
private:
    std::string texto;
    bool leido;
    std::string fecha;

public:

    Mensaje();

    Mensaje(std::string textoNuevo, std::string fechaNueva);

    std::string getTexto();
    bool getLeido();
    std::string getFecha();

    void setTexto(std::string textoNuevo);
    void setFecha(std::string fechaNueva);

    void marcarLeido();


};

#endif // MENSAJE_H
