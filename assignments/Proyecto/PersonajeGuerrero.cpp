#include "PersonajeGuerrero.hpp"
#include <iostream>

PersonajeGuerrero::PersonajeGuerrero(const std::string nombre, const std::string descripcion, Mundo* ubicacion, int saludTotal, int ataqueMax)
    : Personaje(nombre, descripcion, ubicacion), puntosSaludTotales(saludTotal), puntosSaludActuales(saludTotal), maximoAtaque(ataqueMax) {
}

PersonajeGuerrero::~PersonajeGuerrero() {
}

int PersonajeGuerrero::getPuntosSaludTotales() const {
    return puntosSaludTotales;
}

int PersonajeGuerrero::getPuntosSaludActuales() {
    return puntosSaludActuales;
}

int PersonajeGuerrero::getMaximoAtaque() const {
    return maximoAtaque;
}

bool PersonajeGuerrero::estaVivo() {
    return puntosSaludActuales > 0;
}

int PersonajeGuerrero::calcularPorcentajeSalud() {
    return (puntosSaludActuales * 100) / puntosSaludTotales;
}

void PersonajeGuerrero::imprimeBarraVida() {
    int porcentajeSalud = calcularPorcentajeSalud();
    int numCaracteresVida = (porcentajeSalud * 20) / 100;
    int numCaracteresPerdidos = 20 - numCaracteresVida;

    std::cout << "Vida: ";
    for (int i = 0; i < numCaracteresVida; i++) {
        std::cout << "%";
    }
    for (int i = 0; i < numCaracteresPerdidos; i++) {
        std::cout << "=";
    }
    std::cout << std::endl;
}

int PersonajeGuerrero::juega() {
    int puntosAtaque = rand() % (maximoAtaque + 1);
    std::cout << nombre << " ataca!" << std::endl;
    return puntosAtaque;
}

void PersonajeGuerrero::usar(int cantidad) {
    puntosSaludActuales += cantidad;
}

void PersonajeGuerrero::recibeInteraccion(int danio) {
    std::cout << nombre << " recibió " << danio << " puntos de daño." << std::endl;
    puntosSaludActuales -= danio;
    if (puntosSaludActuales < 0) {
        puntosSaludActuales = 0;
    }
}

PersonajeGuerrero& PersonajeGuerrero::operator-=(int danio) {
    recibeInteraccion(danio);
    return *this;
}