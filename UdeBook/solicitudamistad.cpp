#include "solicitudamistad.h"

SolicitudAmistad::SolicitudAmistad()
{
    estado = "pendiente";
}

SolicitudAmistad::SolicitudAmistad(std::string emisorNuevo, std::string receptorNuevo)
{
    emisor = emisorNuevo;
    receptor = receptorNuevo;
    estado = "pendiente";
}
void SolicitudAmistad::marcarAceptada()
{
    estado = "aceptada";
}

void SolicitudAmistad::marcarRechazada()
{
    estado = "rechazada";
}

std::string SolicitudAmistad::getEmisor()
{
    return emisor;
}

std::string SolicitudAmistad::getReceptor()
{
    return receptor;
}

std::string SolicitudAmistad::getEstado()
{
    return estado;
}