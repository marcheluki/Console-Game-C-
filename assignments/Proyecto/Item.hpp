#pragma once
#include <string>

class Item {
private:
    std::string nombre;
    std::string descripcion;
    int puntosSalud;

public:
    Item(const std::string& nombre, const std::string& descripcion,int puntosSalud);

    std::string getNombre() const;
    std::string getDescripcion() const;
    int getPuntosSalud() const;
    void imprime() const;
};
