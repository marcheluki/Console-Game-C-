#include "Personaje.hpp"
#include "Item.hpp"
#include "Mundo.hpp"

class PersonajeAmistoso : public Personaje {
    private:
        bool dispuestoHablar;
        std::string historia;

    public:
        PersonajeAmistoso(std::string nombre, std::string descripcion, std::string historia, Mundo* ubicacion, bool dispuestoHablar);
        ~PersonajeAmistoso();

        bool estaDispuestoHablar() const;
        std::string getHistoria() const;
        int juega() override;
        void recibeInteraccion(int cantidad) override;
        void imprimeBarraVida() override;
        bool estaVivo() override;
};
