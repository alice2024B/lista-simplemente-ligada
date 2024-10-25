#include <iostream>
#include "Materia.h"

int main() {
    // Crear dos objetos de Materia
    Materia Programacion("P01", "Programacion", "Dr. Perez", 4);
    Materia BasesDatos("B02", "Bases de Datos", "Dr. Gomez", 3);

    int opcion;
    do {
        std::cout << "\nMenu:\n";
        std::cout << "1. Cambiar la clave de la materia Programacion\n";
        std::cout << "2. Cambiar el nombre del maestro que imparte la materia BasesDatos\n";
        std::cout << "3. Imprimir todos los datos de la materia BasesDatos\n";
        std::cout << "4. Salir\n";
        std::cout << "Seleccione una opcion: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1: {
                std::string nuevaClave;
                std::cout << "Ingrese la nueva clave para la materia Programacion: ";
                std::cin >> nuevaClave;
                Programacion.setClave(nuevaClave);
                break;
            }
            case 2: {
                std::string nuevoMaestro;
                std::cout << "Ingrese el nuevo nombre del maestro para la materia BasesDatos: ";
                std::cin.ignore();  // Limpiar el buffer de entrada
                std::getline(std::cin, nuevoMaestro);
                BasesDatos.setMaestro(nuevoMaestro);
                break;
            }
            case 3: {
                std::cout << "\nDatos de la materia BasesDatos:\n";
                std::cout << BasesDatos;
                break;
            }
            case 4:
                std::cout << "Saliendo del programa.\n";
                break;
            default:
                std::cout << "Opcion no valida. Intente nuevamente.\n";
        }
    } while (opcion != 4);

    return 0;
}
