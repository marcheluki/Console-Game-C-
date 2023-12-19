#include "Mundo.hpp"
#include <iostream>

const Mundo MUNDO_NULO = Mundo("NULO");

Mundo::Mundo(const std::string& nombre, Mundo* mundoSiguiente, Personaje* personaje)
    : nombre(nombre), mundoSiguiente(mundoSiguiente), item(nullptr), personaje(personaje) {
    this->valido = true;
}

Mundo::Mundo(const std::string& nombre){
    this->nombre = nombre;
    this->mundoSiguiente = nullptr;
    this->item = nullptr;
    this->personaje = nullptr;
    this->valido = false;
}

Mundo::~Mundo() {
    delete item;
    delete personaje;
}

std::string Mundo::getNombre() const {
    return nombre;
}

Mundo* Mundo::getMundoSiguiente() {
    return mundoSiguiente;
}

Item* Mundo::getItem() {
    return item;
}

Personaje* Mundo::getPersonaje() {
    return personaje;
}

void Mundo::imprime() {
    std::cout << "Mundo: " << nombre << std::endl;
    std::cout << "Descripción: " << personaje->getDescripcion() << std::endl;
}

void Mundo::agregarItem(Item* nuevoItem) {
    item = nuevoItem;
    validar();
}

void Mundo::agregarPersonaje(Personaje* nuevoPersonaje) {
    personaje = nuevoPersonaje;
    validar();
}

void Mundo::agregarMundoSiguiente(Mundo* nuevoMundo) {
    mundoSiguiente = nuevoMundo;
    validar();
}

void Mundo::validar() {
    valido = item && personaje && mundoSiguiente;
}

bool Mundo::esValido() {
    return valido;
}
