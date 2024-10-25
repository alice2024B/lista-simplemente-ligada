#include <iostream>
#include <string>
#include <vector>

class Solicitud {
public:
    std::string nombre;
    std::string carrera;
    std::string preparatoria;
    float promedio;

    Solicitud(std::string n, std::string c, std::string p, float pr)
        : nombre(n), carrera(c), preparatoria(p), promedio(pr) {}

    friend std::ostream& operator<<(std::ostream& os, const Solicitud& s) {
        os << "Nombre: " << s.nombre
           << ", Carrera: " << s.carrera
           << ", Preparatoria: " << s.preparatoria
           << ", Promedio: " << s.promedio;
        return os;
    }
};

class Lista {
private:
    std::vector<Solicitud> solicitudes;

public:
    void darDeAlta(const Solicitud& sol) {
        solicitudes.push_back(sol);
        ordenarPorPromedio();
    }

    void ordenarPorPromedio() {
        // Función: inserción
        int ultind = solicitudes.size() - 1; // última posición
        for (int i = 1; i <= ultind; i++) {
            Solicitud aux = solicitudes[i]; // aux = arr[i]
            int j = i; // j = i
            while (j > 0 && aux.promedio > solicitudes[j - 1].promedio) { // Cambiado a mayor que
                solicitudes[j] = solicitudes[j - 1]; // arr[j] = arr[j-1]
                j = j - 1; // j = j - 1
            }
            if (i != j) // si i ≠ j
                solicitudes[j] = aux; // arr[j] = aux
        }
    }

    int buscarSolicitud(const std::string& nombre) {
        // Función: búsqueda binaria
        int i = 0;
        int j = solicitudes.size() - 1;

        while (i <= j) { // mientras i ≤ j
            int medio = (i + j) / 2; // medio = (i + j) / 2
            if (solicitudes[medio].nombre == nombre) { // si arr[m] = elem
                return medio; // regresar medio
            }
            if (nombre < solicitudes[medio].nombre) { // si elem < arr[medio]
                j = medio - 1; // j = medio - 1
            } else {
                i = medio + 1; // i = medio + 1
            }
        }
        return -1; // regresar -1 si no se encuentra
    }

    void mostrarSolicitudes() {
        for (const auto& sol : solicitudes) {
            std::cout << sol << std::endl;
        }
    }

    const Solicitud& getSolicitud(int index) const {
        return solicitudes[index];
    }
};

int main() {
    Lista listaSolicitudes;
    int opcion;

    do {
        std::cout << "\nMenu:\n";
        std::cout << "1. Dar de alta solicitud\n";
        std::cout << "2. Buscar solicitud\n";
        std::cout << "3. Mostrar todas las solicitudes\n";
        std::cout << "4. Salir\n";
        std::cout << "\nIngrese una opcion: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1: {
                std::string nombre, carrera, preparatoria;
                float promedio;

                std::cout << "Inserte nombre: ";
                std::cin >> nombre;
                std::cout << "Inserte carrera: ";
                std::cin >> carrera;
                std::cout << "Inserte preparatoria: ";
                std::cin >> preparatoria;
                std::cout << "Inserte promedio: ";
                std::cin >> promedio;

                Solicitud nuevaSolicitud(nombre, carrera, preparatoria, promedio);
                listaSolicitudes.darDeAlta(nuevaSolicitud);
                break;
            }
            case 2: {
                std::string nombre;
                std::cout << "Ingrese el nombre del alumno a buscar: ";
                std::cin >> nombre;
                int posicion = listaSolicitudes.buscarSolicitud(nombre);
                if (posicion != -1) {
                    std::cout << "Solicitud encontrada: " << listaSolicitudes.getSolicitud(posicion) << std::endl;
                    std::cout << "Posicion en la lista (basado en promedio): " << posicion + 1 << std::endl;
                } else {
                    std::cout << "No se encontro la solicitud de " << nombre << ".\n";
                }
                break;
            }
            case 3:
                listaSolicitudes.mostrarSolicitudes();
                break;
            case 4:
                std::cout << "Saliendo del programa." << std::endl;
                break;
            default:
                std::cout << "Opcion invalida. Intente nuevamente." << std::endl;
        }
    } while (opcion != 4);

    return 0;
}



