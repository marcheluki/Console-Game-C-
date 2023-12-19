#include "Personaje.hpp"
#include "Mundo.hpp"

Personaje::Personaje(const std::string& nombre, const std::string& descripcion, Mundo* ubicacion)
    : nombre(nombre), descripcion(descripcion), ubicacion(ubicacion) {
}

Personaje::~Personaje() {
}

std::string Personaje::getNombre() const {
    return nombre;
}

std::string Personaje::getDescripcion() const {
    return descripcion;
}

Mundo* Personaje::getUbicacion() const {
    return ubicacion;
}

void Personaje::imprime() {
    std::cout << "Nombre: " << nombre << std::endl;
    std::cout << "Ubicación: " << ubicacion->getNombre() << std::endl;
}
