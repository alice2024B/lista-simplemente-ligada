// Empleado.cpp
#include "Empleado.h"

// Constructor por defecto
Empleado::Empleado() : clave(""), nombre(""), domicilio(""), sueldo(0.0), personaReporta("") {}

// Constructor con parámetros
Empleado::Empleado(const std::string& c, const std::string& n, const std::string& d, double s, const std::string& p)
    : clave(c), nombre(n), domicilio(d), sueldo(s), personaReporta(p) {}

// Métodos de acceso y modificación
void Empleado::setDomicilio(const std::string& d) { domicilio = d; }
void Empleado::setSueldo(double s) { sueldo = s; }
void Empleado::setPersonaReporta(const std::string& p) { personaReporta = p; }

std::string Empleado::getClave() const { return clave; }
std::string Empleado::getNombre() const { return nombre; }
std::string Empleado::getDomicilio() const { return domicilio; }
double Empleado::getSueldo() const { return sueldo; }
std::string Empleado::getPersonaReporta() const { return personaReporta; }

// Método para imprimir los datos del empleado
void Empleado::imprimirDatos() const {
    std::cout << "Clave: " << clave << "\n";
    std::cout << "Nombre: " << nombre << "\n";
    std::cout << "Domicilio: " << domicilio << "\n";
    std::cout << "Sueldo: " << sueldo << "\n";
    std::cout << "Reporta a: " << personaReporta << "\n";
}

// Operador para comparar claves
bool Empleado::operator==(const Empleado& other) const {
    return clave == other.clave;
}

// Operador de salida
std::ostream& operator<<(std::ostream& os, const Empleado& e) {
    e.imprimirDatos();
    return os;
}

// Operador de entrada
std::istream& operator>>(std::istream& is, Empleado& e) {
    std::cout << "Ingrese clave: ";
    is >> e.clave;
    is.ignore();  // Limpiar el buffer de entrada
    std::cout << "Ingrese nombre: ";
    std::getline(is, e.nombre);
    std::cout << "Ingrese domicilio: ";
    std::getline(is, e.domicilio);
    std::cout << "Ingrese sueldo: ";
    is >> e.sueldo;
    is.ignore();  // Limpiar el buffer de entrada
    std::cout << "Ingrese persona a quien reporta: ";
    std::getline(is, e.personaReporta);
    return is;
}

