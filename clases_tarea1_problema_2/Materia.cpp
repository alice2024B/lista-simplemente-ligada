#include "Materia.h"

// Constructor por defecto
Materia::Materia() : clave(""), nombre(""), maestro(""), creditos(0) {}

// Constructor con parámetros
Materia::Materia(const std::string& c, const std::string& n, const std::string& m, int cr)
    : clave(c), nombre(n), maestro(m), creditos(cr) {}

// Métodos de acceso y modificación
void Materia::setClave(const std::string& c) { clave = c; }
void Materia::setMaestro(const std::string& m) { maestro = m; }

std::string Materia::getClave() const { return clave; }
std::string Materia::getNombre() const { return nombre; }
std::string Materia::getMaestro() const { return maestro; }
int Materia::getCreditos() const { return creditos; }

// Método para imprimir los datos de la materia
void Materia::imprimirDatos() const {
    std::cout << "Clave: " << clave << "\n";
    std::cout << "Nombre: " << nombre << "\n";
    std::cout << "Maestro: " << maestro << "\n";
    std::cout << "Creditos: " << creditos << "\n";
}

// Operador de salida
std::ostream& operator<<(std::ostream& os, const Materia& m) {
    m.imprimirDatos();
    return os;
}

// Operador de entrada
std::istream& operator>>(std::istream& is, Materia& m) {
    std::cout << "Ingrese clave: ";
    is >> m.clave;
    std::cout << "Ingrese nombre: ";
    is.ignore();  // Limpiar el buffer de entrada
    std::getline(is, m.nombre);
    std::cout << "Ingrese maestro: ";
    std::getline(is, m.maestro);
    std::cout << "Ingrese creditos: ";
    is >> m.creditos;
    return is;
}
