//problema 1: sobre carga de operadores, clase Empleado.

#include <iostream>
#include <string>
#include <map>

using namespace std;

//Definición de la clase Empleado
class Empleado {
private:
    int clave;
    string nombre;
    string domicilio;
    float sueldo;
    string jefeDirecto;

public:
    // Constructor
    Empleado(int c = 0, const string& n = "", const string& d = "", float s = 0.0, const string& j = "")
        : clave(c), nombre(n), domicilio(d), sueldo(s), jefeDirecto(j) {}

    // Sobrecarga del operador ==
    bool operator==(const Empleado& other) const {
        return clave == other.clave;
    }

    // Sobrecarga del operador !=
    bool operator!=(const Empleado& other) const {
        return clave != other.clave;
    }

    // Sobrecarga del operador <
    bool operator<(const Empleado& other) const {
        return clave < other.clave;
    }

    // Sobrecarga del operador >
    bool operator>(const Empleado& other) const {
        return clave > other.clave;
    }

    // Sobrecarga del operador +
    Empleado operator+(const Empleado& other) const {
        return Empleado(clave + other.clave, nombre + " & " + other.nombre,
                        domicilio + " / " + other.domicilio, sueldo + other.sueldo,
                        jefeDirecto + " & " + other.jefeDirecto);
    }

    // Sobrecarga del operador <<
    friend ostream& operator<<(ostream& os, const Empleado& emp) {
        os << "Clave: " << emp.clave << ", Nombre: " << emp.nombre
           << ", Domicilio: " << emp.domicilio << ", Sueldo: " << emp.sueldo
           << ", Jefe Directo: " << emp.jefeDirecto;
        return os;
    }

    // Sobrecarga del operador >>
    friend istream& operator>>(istream& is, Empleado& emp) {
        cout << "Ingrese clave: ";
        is >> emp.clave;
        cout << "Ingrese nombre: ";
        is.ignore(); // Ignorar el newline residual
        getline(is, emp.nombre);
        cout << "Ingrese domicilio: ";
        getline(is, emp.domicilio);
        cout << "Ingrese sueldo: ";
        is >> emp.sueldo;
        cout << "Ingrese jefe directo: ";
        is.ignore(); // Ignorar el newline residual
        getline(is, emp.jefeDirecto);
        return is;
    }

    // Métodos para obtener y modificar atributos
    int getClave() const { return clave; }
    float getSueldo() const { return sueldo; }
    void setDomicilio(const string& d) { domicilio = d; }
    void setSueldo(float s) { sueldo = s; }
    void setJefeDirecto(const string& j) { jefeDirecto = j; }

    void imprimir() const {
        cout << *this << endl;
    }
};

// Definición de la aplicación principal
int main() {
    // Crear un mapa para almacenar los empleados
    map<int, Empleado> empleados;
    empleados[1] = Empleado(1, "Juan", "Calle A", 5000.0, "Luis");
    empleados[2] = Empleado(2, "Ana", "Calle B", 6000.0, "Maria");

    int opcion;
    while (true) {
        cout << "\n Menu:\n";
        cout << "1. Cambiar domicilio\n";
        cout << "2. Actualizar sueldo\n";
        cout << "3. Imprimir datos\n";
        cout << "4. Cambiar nombre de quien reporta\n";
        cout << "5. Operaciones con operadores sobrecargados\n";
        cout << "6. Salir\n";
        cout << "Ingrese una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                int clave;
                string nuevoDomicilio;
                cout << "Ingrese clave del empleado: ";
                cin >> clave;
                cout << "Ingrese nuevo domicilio: ";
                cin.ignore(); // Ignorar el newline residual
                getline(cin, nuevoDomicilio);
                if (empleados.find(clave) != empleados.end()) {
                    empleados[clave].setDomicilio(nuevoDomicilio);
                    cout << "Domicilio actualizado con exito.\n";
                } else {
                    cout << "Empleado no encontrado.\n";
                }
                break;
            }
            case 2: {
                int clave;
                float porcentaje;
                cout << "Ingrese clave del empleado: ";
                cin >> clave;
                cout << "Ingrese porcentaje de incremento: ";
                cin >> porcentaje;
                if (empleados.find(clave) != empleados.end()) {
                    float incremento = empleados[clave].getSueldo() * (porcentaje / 100.0);
                    empleados[clave].setSueldo(empleados[clave].getSueldo() + incremento);
                    cout << "Sueldo actualizado con exito.\n";
                } else {
                    cout << "Empleado no encontrado.\n";
                }
                break;
            }
            case 3: {
                int clave;
                cout << "Ingrese clave del empleado: ";
                cin >> clave;
                if (empleados.find(clave) != empleados.end()) {
                    empleados[clave].imprimir();
                } else {
                    cout << "Empleado no encontrado.\n";
                }
                break;
            }
            case 4: {
                int clave;
                string nuevoJefeDirecto;
                cout << "Ingrese clave del empleado: ";
                cin >> clave;
                cout << "Ingrese nuevo jefe directo: ";
                cin.ignore(); // Ignorar el newline residual
                getline(cin, nuevoJefeDirecto);
                if (empleados.find(clave) != empleados.end()) {
                    empleados[clave].setJefeDirecto(nuevoJefeDirecto);
                    cout << "Nombre de quien reporta actualizado con exito.\n";
                } else {
                    cout << "Empleado no encontrado.\n";
                }
                break;
            }
            case 5: {
                // Ejemplo de uso de operadores sobrecargados
                Empleado emp1(1, "Juan", "Calle A", 5000.0, "Luis");
                Empleado emp2(2, "Ana", "Calle B", 6000.0, "Maria");

                // Comparaciones
                cout << "\n Comparaciones:\n";
                cout << "emp1 == emp2: " << (emp1 == emp2) << endl;
                cout << "emp1 != emp2: " << (emp1 != emp2) << endl;
                cout << "emp1 < emp2: " << (emp1 < emp2) << endl;
                cout << "emp1 > emp2: " << (emp1 > emp2) << endl;

                // Suma
                Empleado emp3 = emp1 + emp2;
                cout << "Resultado de emp1 + emp2:\n";
                emp3.imprimir();

                break;
            }
            case 6:
                return 0;
            default:
                cout << "Opción no valida. Intente de nuevo.\n";
        }
    }

    return 0;
}
