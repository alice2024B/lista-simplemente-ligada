#include <iostream>
#include <string>
using namespace std;

// Definici�n de la clase Empleado
class Empleado {
public:
    std::string nombre;
    int id;

    Empleado() : nombre(""), id(0) {}
    Empleado(std::string n, int i) : nombre(n), id(i) {}

    bool operator==(const Empleado& other) const {
        return id == other.id; // Comparar por ID
    }

    friend std::ostream& operator<<(std::ostream& os, const Empleado& emp) {
        os << "Nombre: " << emp.nombre << ", ID: " << emp.id;
        return os;
    }
};

// Definici�n de la clase Pila
#define MAX 100

class Pila {
private:
    Empleado datos[MAX];
    int tope;

public:
    Pila() : tope(-1) {} // Inicialmente, la pila est� vac�a

    // Inserta un nuevo elemento en la pila
    int Push(Empleado e) {
        if (Llena()) return -1; // Pila llena
        datos[++tope] = e;
        return 0;
    }

    // Elimina el elemento superior de la pila
    int Pop() {
        if (Vacia()) return -1; // Pila vac�a
        --tope;
        return 0;
    }

    // Muestra el elemento superior de la pila
    int Top(Empleado& e) const {
        if (Vacia()) return -1; // Pila vac�a
        e = datos[tope];
        return 0;
    }

    // Verifica si la pila est� vac�a
    int Vacia() const {
        return tope == -1; // Pila vac�a
    }

    // Verifica si la pila est� llena
    int Llena() const {
        return tope == MAX - 1; // Pila llena
    }
};

// Funci�n para mostrar el men�
void mostrarMenu() {
    cout << "1. Push" << endl;
    cout << "2. Pop" << endl;
    cout << "3. Top" << endl;
    cout << "4. Salir" << endl;
}

// Funci�n principal
int main() {
    Pila pila;
    int opcion;
    string nombre;
    int id;
    Empleado emp;

    do {
        mostrarMenu();
        cout << "Ingrese una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: // Push
                cout << "\nIngrese nombre: ";
                cin >> nombre;
                cout << "Ingrese ID: ";
                cin >> id;
                if (pila.Push(Empleado(nombre, id)) == -1)
                    cout << "Pila llena. No se puede agregar." << endl;
                else
                    cout << "\nEmpleado agregado a la pila." << endl;
                break;
            case 2: // Pop
                if (pila.Pop() == -1)
                    cout << "Pila vac�a. No se puede eliminar." << endl;
                else
                    cout << "\nEmpleado eliminado de la pila." << endl;
                break;
            case 3: // Top
                if (pila.Top(emp) == -1)
                    cout << "Pila vac�a." << endl;
                else
                    cout << "\nElemento en la parte superior de la pila: " << emp << endl;
                break;
            case 4:
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Opci�n inv�lida." << endl;
                break;
        }
    } while (opcion != 4);

    return 0;
}
