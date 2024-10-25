//problema 2: sobre carga de operadores, clase Materia.

#include <iostream>
#include <string>

using namespace std;

// Definición de la clase Materia
class Materia {
private:
    int clave;
    string nombreMateria;
    string nombreMaestro;

public:
    // Constructor
    Materia(int c = 0, const string& nm = "", const string& nmMaestro = "")
        : clave(c), nombreMateria(nm), nombreMaestro(nmMaestro) {}

    // Sobrecarga del operador ==
    bool operator==(const Materia& other) const {
        return clave == other.clave;
    }

    // Sobrecarga del operador !=
    bool operator!=(const Materia& other) const {
        return clave != other.clave;
    }

    // Sobrecarga del operador <
    bool operator<(const Materia& other) const {
        return clave < other.clave;
    }

    // Sobrecarga del operador >
    bool operator>(const Materia& other) const {
        return clave > other.clave;
    }

    // Sobrecarga del operador +
    Materia operator+(const Materia& other) const {
        return Materia(clave + other.clave, nombreMateria + " & " + other.nombreMateria,
                       nombreMaestro + " / " + other.nombreMaestro);
    }

    // Sobrecarga del operador <<
    friend ostream& operator<<(ostream& os, const Materia& m) {
        os << "Clave: " << m.clave << ", Nombre de Materia: " << m.nombreMateria
           << ", Nombre del Maestro: " << m.nombreMaestro;
        return os;
    }

    // Sobrecarga del operador >>
    friend istream& operator>>(istream& is, Materia& m) {
        cout << "Ingrese clave: ";
        is >> m.clave;
        cout << "Ingrese nombre de la materia: ";
        is.ignore(); // Ignorar el newline residual
        getline(is, m.nombreMateria);
        cout << "Ingrese nombre del maestro: ";
        getline(is, m.nombreMaestro);
        return is;
    }

    // Métodos para obtener y modificar atributos
    void setClave(int c) { clave = c; }
    void setNombreMaestro(const string& nm) { nombreMaestro = nm; }
    void imprimir() const {
        cout << *this << endl;
    }
};

// Funciones para manejar las opciones del menú
void cambiarClave(Materia& materia) {
    int nuevaClave;
    cout << "Ingrese nueva clave: ";
    cin >> nuevaClave;
    materia.setClave(nuevaClave);
    cout << "Clave actualizada con éxito.\n";
}

void cambiarNombreMaestro(Materia& materia) {
    string nuevoMaestro;
    cout << "Ingrese nuevo nombre del maestro: ";
    cin.ignore(); // Ignorar el newline residual
    getline(cin, nuevoMaestro);
    materia.setNombreMaestro(nuevoMaestro);
    cout << "Nombre del maestro actualizado con exito.\n";
}

void imprimirDatos(const Materia& materia) {
    cout << "Datos de la materia:\n";
    materia.imprimir();
}

void mostrarOperadores(const Materia& m1, const Materia& m2) {
    // Mostrar el uso de los operadores sobrecargados
    cout << "\nDemostracion de operadores sobrecargados:\n";

    // Sobrecarga del operador <<
    cout << "Materia 1: " << m1 << endl;
    cout << "Materia 2: " << m2 << endl;

    // Sobrecarga del operador +
    Materia combinada = m1 + m2;
    cout << "Materia combinada (Materia 1 + Materia 2): " << combinada << endl;

    // Sobrecarga de los operadores de comparación
    cout << "\nComparaciones:\n";
    cout << "Materia 1 == Materia 2: " << (m1 == m2 ? "Si" : "No") << endl;
    cout << "Materia 1 != Materia 2: " << (m1 != m2 ? "Si" : "No") << endl;
    cout << "Materia 1 < Materia 2: " << (m1 < m2 ? "Si" : "No") << endl;
    cout << "Materia 1 > Materia 2: " << (m1 > m2 ? "Si" : "No") << endl;
}

int main() {
    // Declarar y mostrar objetos Materia
    Materia Programacion(101, "Programacion", "Dr. Perez");
    Materia BasesDatos(102, "Bases de Datos", "Dra. Lopez");

    int opcion;
    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Cambiar la clave de la materia Programacion\n";
        cout << "2. Cambiar el nombre del maestro que imparte la materia BasesDatos\n";
        cout << "3. Imprimir todos los datos de la materia BasesDatos\n";
        cout << "4. Mostrar demostracion de operadores sobrecargados\n";
        cout << "5. Salir\n";
        cout << "Ingrese una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cambiarClave(Programacion);
                break;
            case 2:
                cambiarNombreMaestro(BasesDatos);
                break;
            case 3:
                imprimirDatos(BasesDatos);
                break;
            case 4:
                mostrarOperadores(Programacion, BasesDatos);
                break;
            case 5:
                return 0;
            default:
                cout << "Opcion no valida. Intente de nuevo.\n";
        }
    }

    return 0;
}
