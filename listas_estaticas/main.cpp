//listas estaticas

#include <iostream>
#include <string>
using namespace std;

// Definición de la clase Empleado
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

// Definición de la clase ListaEstatica
#define MAX 100

class ListaEstatica {
private:
    Empleado datos[MAX];
    int tam;

public:
    ListaEstatica() : tam(0) {}

    int Inserta(Empleado e, int pos) {
        if (pos < 0 || pos > tam || Llena()) return -1; // Posición inválida o lista llena
        for (int i = tam; i > pos; --i) {
            datos[i] = datos[i - 1];
        }
        datos[pos] = e;
        tam++;
        return 0;
    }

    int Agrega(Empleado e) {
        if (Llena()) return -1; // Lista llena
        datos[tam++] = e;
        return 0;
    }

    int Busca(Empleado e) {
        for (int i = 0; i < tam; ++i) {
            if (datos[i] == e) return i; // Encuentra la posición del elemento
        }
        return -1; // No encontrado
    }

    int Elimina(int pos) {
        if (pos < 0 || pos >= tam) return -1; // Posición inválida
        for (int i = pos; i < tam - 1; ++i) {
            datos[i] = datos[i + 1];
        }
        tam--;
        return 0;
    }

    int Vacia() const {
        return tam == 0; // Lista vacía
    }

    int Llena() const {
        return tam == MAX; // Lista llena
    }

    void Muestra() const {
        if (Vacia()) {
            std::cout << "La lista está vacía." << std::endl;
            return;
        }
        for (int i = 0; i < tam; ++i) {
            std::cout << datos[i] << std::endl;
        }
    }
};

// Función para mostrar el menú
void mostrarMenu() {
    cout << "1. Agregar" << endl;
    cout << "2. Buscar" << endl;
    cout << "3. Eliminar" << endl;
    cout << "4. Insertar" << endl;
    cout << "5. Mostrar" << endl;
    cout << "6. Salir" << endl;
}

// Función principal
int main() {
    ListaEstatica lista;
    int opcion;
    string nombre;
    int id, pos;

    do {
        mostrarMenu();
        cout << "Ingrese una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "\n Ingrese nombre: ";
                cin >> nombre;
                cout << "Ingrese ID: ";
                cin >> id;
                if (lista.Agrega(Empleado(nombre, id)) == -1)
                    cout << "Lista llena. No se puede agregar." << endl;
                break;
            case 2:
                cout << "Ingrese ID a buscar: ";
                cin >> id;
                pos = lista.Busca(Empleado("", id));
                if (pos == -1)
                    cout << "Empleado no encontrado." << endl;
                else
                    cout << "Empleado encontrado en la posicion: " << pos << endl;
                break;
            case 3:
                cout << "Ingrese posicion a eliminar: ";
                cin >> pos;
                if (lista.Elimina(pos) == -1)
                    cout << "Posicion invalida." << endl;
                else
                    cout << "Empleado eliminado." << endl;
                break;
            case 4:
                cout << "Ingrese nombre: ";
                cin >> nombre;
                cout << "Ingrese ID: ";
                cin >> id;
                cout << "Ingrese posicion: ";
                cin >> pos;
                if (lista.Inserta(Empleado(nombre, id), pos) == -1)
                    cout << "Error en la insercion." << endl;
                else
                    cout << "Empleado insertado." << endl;
                break;
            case 5:
                lista.Muestra();
                break;
            case 6:
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Opcion invalida." << endl;
                break;
        }
    } while (opcion != 6);

    return 0;
}

