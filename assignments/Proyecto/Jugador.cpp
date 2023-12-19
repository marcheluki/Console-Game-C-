#include <iostream>
#include <cmath>
#include "Jugador.hpp"

Jugador::Jugador(const std::string nombre, const std::string descripcion, Mundo* ubicacion, int saludTotal, int ataqueMax)
    : PersonajeGuerrero(nombre, descripcion, ubicacion, saludTotal, ataqueMax) {
}

bool Jugador::estaVivo() {
    return puntosSaludActuales > 0;
}

int Jugador::juega() {
    int numMagico = rand() % (100);
    std::cout << "Adivina mi número mágico (0-99): ";
    int adivinanza;
    std::cin >> adivinanza;
    int diferencia = abs(numMagico - adivinanza);
    int puntosAtaque = (exp(-(float)diferencia/30) * maximoAtaque);
    std::cout << "Mi número mágico era " << numMagico << std::endl;
    std::cout << "Has atacado con " << puntosAtaque << " puntos de daño!" << std::endl;
    return puntosAtaque;
}

void Jugador::recibeInteraccion(int danio) {
    puntosSaludActuales -= danio;
    std::cout << "Recibiste " << danio << " puntos de daño. Salud: " << puntosSaludActuales << std::endl;
    if (puntosSaludActuales < 0) {
        puntosSaludActuales = 0;
    }
}
