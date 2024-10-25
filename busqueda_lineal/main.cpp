#include <iostream>
#include "Cola.h"

int main() {
    Cola MiCola;
    persona x;
    int opcion;

    do {
        std::cout << "\nMenu:\n";
        std::cout << "1. Dar de alta solicitud\n";
        std::cout << "2. Elaborar constancia\n";
        std::cout << "3. Buscar solicitud\n";
        std::cout << "4. Salir\n";
        std::cout << "Ingrese una opcion: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1:
                std::cin >> x;
                MiCola.enqueue(x);
                break;
            case 2:
                std::cout << "\nConstancias:\n";
                if (!MiCola.vacia()) {
                    persona constancia = MiCola.dequeue();
                    std::cout << constancia << std::endl;
                } else {
                    std::cout << "No hay solicitudes en espera." << std::endl;
                }
                break;
            case 3: {
                std::string nombre;
                std::cout << "Ingrese el nombre del alumno a buscar: ";
                std::cin >> nombre;
                int posicion = MiCola.buscarSolicitud(nombre);
                if (posicion != -1) {
                    std::cout << "La solicitud de " << nombre << " esta en la posicion " << posicion + 1 << " de la cola." << std::endl;
                    std::cout << "Se deben elaborar " << posicion << " constancias antes de su turno." << std::endl;
                } else {
                    std::cout << "No se encontro la solicitud de " << nombre << ". Debe dar de alta una solicitud." << std::endl;
                }
                break;
            }
            case 4:
                std::cout << "Saliendo del programa." << std::endl;
                break;
            default:
                std::cout << "Opcion invalida. Intente nuevamente." << std::endl;
        }
    } while (opcion != 4);

    return 0;
}
