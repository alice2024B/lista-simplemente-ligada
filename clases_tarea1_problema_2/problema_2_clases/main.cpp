// main.cpp
#include <iostream>
#include <unordered_map>
#include "Empleado.h"

int main() {
    // Crear dos empleados
    Empleado JefePlanta("JP01", "Carlos López", "Av. Reforma 123", 50000, "Director General");
    Empleado JefePersonal("JP02", "Ana Martínez", "Calle 5 de Febrero 456", 45000, "Director de Recursos Humanos");

    // Mapa para buscar empleados por clave
    std::unordered_map<std::string, Empleado*> empleados;
    empleados[JefePlanta.getClave()] = &JefePlanta;
    empleados[JefePersonal.getClave()] = &JefePersonal;

    int opcion;
    do {
        std::cout << "\nMenu:\n";
        std::cout << "1. Cambiar el domicilio de un empleado\n";
        std::cout << "2. Actualizar el sueldo de un empleado\n";
        std::cout << "3. Imprimir los datos de un empleado\n";
        std::cout << "4. Cambiar el nombre de la persona a quien reporta un empleado\n";
        std::cout << "5. Salir\n";
        std::cout << "Seleccione una opción: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1: {
                std::string clave, nuevoDomicilio;
                std::cout << "Ingrese la clave del empleado: ";
                std::cin >> clave;
                if (empleados.find(clave) != empleados.end()) {
                    std::cout << "Ingrese el nuevo domicilio: ";
                    std::cin.ignore();  // Limpiar el buffer de entrada
                    std::getline(std::cin, nuevoDomicilio);
                    empleados[clave]->setDomicilio(nuevoDomicilio);
                } else {
                    std::cout << "Empleado no encontrado.\n";
                }
                break;
            }
            case 2: {
                std::string clave;
                double incremento;
                std::cout << "Ingrese la clave del empleado: ";
                std::cin >> clave;
                if (empleados.find(clave) != empleados.end()) {
                    std::cout << "Ingrese el porcentaje de incremento (por ejemplo, 10 para 10%): ";
                    std::cin >> incremento;
                    double nuevoSueldo = empleados[clave]->getSueldo() * (1 + incremento / 100);
                    empleados[clave]->setSueldo(nuevoSueldo);
                } else {
                    std::cout << "Empleado no encontrado.\n";
                }
                break;
            }
            case 3: {
                std::string clave;
                std::cout << "Ingrese la clave del empleado: ";
                std::cin >> clave;
                if (empleados.find(clave) != empleados.end()) {
                    std::cout << *empleados[clave];
                } else {
                    std::cout << "Empleado no encontrado.\n";
                }
                break;
            }
            case 4: {
                std::string clave, nuevaPersonaReporta;
                std::cout << "Ingrese la clave del empleado: ";
                std::cin >> clave;
                if (empleados.find(clave) != empleados.end()) {
                    std::cout << "Ingrese el nuevo nombre de la persona a quien reporta: ";
                    std::cin.ignore();  // Limpiar el buffer de entrada
                    std::getline(std::cin, nuevaPersonaReporta);
                    empleados[clave]->setPersonaReporta(nuevaPersonaReporta);
                } else {
                    std::cout << "Empleado no encontrado.\n";
                }
                break;
            }
            case 5:
                std::cout << "Saliendo del programa.\n";
                break;
            default:
                std::cout << "Opción no válida. Intente nuevamente.\n";
        }
    } while (opcion != 5);

    return 0;
}
