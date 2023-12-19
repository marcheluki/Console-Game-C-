#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "string"
#include "Mundo.hpp"
#include "Personaje.hpp"
#include "PersonajeGuerrero.hpp"
#include "PersonajeAmistoso.hpp"
#include "Jugador.hpp"
#include "Item.hpp"

int main() {
    // Semilla para generar números aleatorios
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    // Crear los items
    Item* item1 = new Item("Espada", "el legado final de la montaña", 50);
    Item* item2 = new Item("Poción", "una poción mágica", 30);
    Item* item3 = new Item("Escudo", "un resistente escudo", 40);
    Item* item4 = new Item("Amuleto", "un amuleto místico", 60);

    // Crear los mundos
    Mundo* mundo1 = new Mundo("Mundo 1 - Anyla");
    Mundo* mundo2 = new Mundo("Mundo 2 - Matoril");
    Mundo* mundo3 = new Mundo("Mundo 3 - Garta");
    Mundo* mundo4 = new Mundo("Mundo 4 - Fulmopia");

    mundo1->agregarMundoSiguiente(mundo2);
    mundo2->agregarMundoSiguiente(mundo3);
    mundo3->agregarMundoSiguiente(mundo4);

    // Agregar los items a los mundos correspondientes
    mundo1->agregarItem(item1);
    mundo2->agregarItem(item2);
    mundo3->agregarItem(item3);
    mundo4->agregarItem(item4);

    // Crear los personajes guerreros
    PersonajeGuerrero* guerrero1 = new PersonajeGuerrero("Guerrero 1 - Luques", "Un misterioso ladrón que le roba a los pobres y le da dinero a los ricos", mundo1, 80, 10);
    PersonajeGuerrero* guerrero2 = new PersonajeGuerrero("Guerrero 4 - Emiliane", "Un terrorista que destruyó una montaña por diversión", mundo4, 120, 30);

    // Crear los personajes amistosos
    PersonajeAmistoso* amistoso1 = new PersonajeAmistoso("Hipolito [amistoso]", "Un monje desamparado", "Yo solía ser un monje en una montaña muy lejana de este mundo, pero la montaña se derrumbó debido a una bomba y ahora camino en busca de un alma dulce que quiera recibir mi último legado, una espada.", mundo1, true);
    PersonajeAmistoso* amistoso2 = new PersonajeAmistoso("Rigoberto [amistoso]", "Un viejo amigo", "Amigo, hace mucho tiempo no te veía, espero te encuentres bien y me hayas extrañado, no pensé encontrarte pronto por estos rumbos, no tengo nada para ofrecerte más que un simple escudo.", mundo4, true);

    // Agregar los personajes a los mundos correspondientes
    mundo1->agregarPersonaje(guerrero1);
    mundo2->agregarPersonaje(amistoso1);
    mundo3->agregarPersonaje(amistoso2);
    mundo4->agregarPersonaje(guerrero2);

    // Crear el jugador principal
    Jugador* jugador = new Jugador("Jugador", "El héroe de la historia", mundo1, 200, 50);
    std::cout << (jugador->estaVivo()) << std::endl;

    // Inicio del juego
    std::cout << "*** BIENVENIDO AL JUEGO ***" << std::endl;
    std::cout << "Tu aventura comienza en el " << mundo1->getNombre() << std::endl;
    std::cout << "Explora los mundos, interactúa con personajes amables y derrota a los enemigos que se presenten en tu camino." << std::endl;
    std::cout << std::endl;

    // Variable para controlar el mundo actual
    Mundo* mundoActual = mundo1;

    // Bucle principal del juego
    while (mundoActual != nullptr) {
        std::cout << "Estás en " << mundoActual->getNombre() << std::endl;
        std::cout << std::endl;

        // Obtener personaje del mundo actual
        Personaje* personaje = mundoActual->getPersonaje();
        try {
            personaje->imprime();
        } catch (std::runtime_error& e) {
            std::cout << "Error consiguiendo el personaje del mundo: ";
            std::cout << e.what() << std::endl;
            std::cout << std::endl;
            mundoActual = mundoActual->getMundoSiguiente();
            continue;
        }

        // Si el personaje es amistoso
        if (PersonajeAmistoso* amistoso = dynamic_cast<PersonajeAmistoso*>(personaje)) {
            if (amistoso->estaDispuestoHablar()) {
                std::cout << "¡" << amistoso->getNombre() << " te quiere contar una historia!" << std::endl;
                amistoso->juega();
                std::cout << std::endl;
                std::cout << "¡Toma el item del mundo!" << std::endl;
                if (Item* item = mundoActual->getItem()) {
                    item->imprime();
                    std::cout<<"¿Deseas obtener este objeto valioso? te podría ayudar en el futuro... (s/n)"<<std::endl;
                    std::string respuesta;
                    std::cin>>respuesta;
                    if (respuesta== "s"){
                        jugador->usar(item->getPuntosSalud());
                    } else if (respuesta== "n"){
                        std::cout<<"Una verdadera lástima, me quedo con el objeto"<<std::endl;
                    } else{
                        std::cout<<"Respuesta no válida, ingrese de nuevo (s= si, n=no): ";
                        std::cin>>respuesta;
                    }
                }
                std::cout << std::endl;
            } else {
                std::cout << "¡" << amistoso->getNombre() << " no está dispuesto a hablar!" << std::endl;
                std::cout << std::endl;
            }
        }
        // Si el personaje es guerrero
        else if (PersonajeGuerrero* guerrero = dynamic_cast<PersonajeGuerrero*>(personaje)) {
            std::cout << "¡Te encuentras con el enemigo " << guerrero->getNombre() << "!" << std::endl;
            std::cout << std::endl;

            while (jugador->estaVivo() && guerrero->estaVivo()) {
                int ataqueJugador = jugador->juega();
                *guerrero -= ataqueJugador;
                guerrero->imprimeBarraVida();
                if (guerrero->estaVivo()) {
                    int ataqueEnemigo = guerrero->juega();
                    *jugador -= ataqueEnemigo;
                }

                std::cout << std::endl;
            }

            if (!jugador->estaVivo()) {
                std::cout << "¡Has perdido contra " << guerrero->getNombre() << " en " << mundoActual->getNombre() << "!" << std::endl;
                break;
            } else {
                std::cout << "¡Has derrotado a " << guerrero->getNombre() << " en " << mundoActual->getNombre() << "!" << std::endl;
                std::cout << std::endl;
            }
        }

        // Avanzar al siguiente mundo
        mundoActual = mundoActual->getMundoSiguiente();
    }

    // Fin del juego
    std::cout << "*** FIN DEL JUEGO ***" << std::endl;

    return 0;
}

