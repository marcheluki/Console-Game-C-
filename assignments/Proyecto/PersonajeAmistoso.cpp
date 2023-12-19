#include "PersonajeAmistoso.hpp"

PersonajeAmistoso::PersonajeAmistoso(std::string nombre, std::string descripcion, std::string historia, Mundo* ubicacion, bool dispuestoHablar)
    : Personaje(nombre, descripcion, ubicacion), dispuestoHablar(dispuestoHablar), historia(historia) {
}

PersonajeAmistoso::~PersonajeAmistoso() {
}

bool PersonajeAmistoso::estaDispuestoHablar() const {
    return dispuestoHablar;
}

std::string PersonajeAmistoso::getHistoria() const {
    return historia;
}

int PersonajeAmistoso::juega() {
    if (dispuestoHablar) {
        std::cout << nombre << " cuenta una historia: " << historia << std::endl;
        Item* item = ubicacion->getItem();
        std::cout << "Hay un objeto en este cuarto." << std::endl;
        std::cout << "Nombre: " << item->getNombre() << std::endl;
        std::cout << "Descripcion: " << item->getDescripcion() << std::endl;
        std::cout << "Proporciona " << item->getPuntosSalud() << " puntos de salud." << std::endl;
        return item->getPuntosSalud();
    } else {
        std::cout << nombre << " no está dispuesto a hablar." << std::endl;
    }
    return 0;
}

void PersonajeAmistoso::recibeInteraccion(int cantidad) {
    std::cout << nombre << " no sufre daño." << std::endl;
}

void PersonajeAmistoso::imprimeBarraVida() {
    std::cout << nombre << " no tiene barra de vida." << std::endl;
}

bool PersonajeAmistoso::estaVivo() {
    return true;  // Los personajes amistosos siempre están vivos
}
