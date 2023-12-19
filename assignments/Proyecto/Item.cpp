#include "Item.hpp"
#include <iostream>

Item::Item(const std::string& nombre, const std::string& descripcion, int puntosSalud)
    : nombre(nombre), descripcion(descripcion),puntosSalud(puntosSalud) {
}

std::string Item::getNombre() const {
    return nombre;
}

std::string Item::getDescripcion() const {
    return descripcion;
}

int Item::getPuntosSalud() const {
    return puntosSalud;
}

void Item::imprime() const {
    std::cout << "Item: " << nombre << ", descripción: " << descripcion << ", puntos de salud: " << puntosSalud << std::endl;
}

