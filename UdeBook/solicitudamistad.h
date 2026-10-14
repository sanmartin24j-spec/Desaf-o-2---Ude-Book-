#ifndef SOLICITUDAMISTAD_H
#define SOLICITUDAMISTAD_H
#include <string>
class SolicitudAmistad
{
private:
    std::string emisor;
    std::string receptor;
    std::string estado;
public:
    SolicitudAmistad();

    SolicitudAmistad(std::string emisorNuevo,std::string receptorNuevo);

    std::string getEmisor();
    std::string getEstado();
    std::string getReceptor();


    void marcarAceptada();
    void marcarRechazada();

};

#endif // SOLICITUDAMISTAD_H
