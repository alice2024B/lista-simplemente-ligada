// Empleado.h
#ifndef EMPLEADO_H
#define EMPLEADO_H

#include <iostream>
#include <string>

class Empleado {
private:
    std::string clave;
    std::string nombre;
    std::string domicilio;
    double sueldo;
    std::string personaReporta;

public:
    // Constructor por defecto
    Empleado();

    // Constructor con parámetros
    Empleado(const std::string& c, const std::string& n, const std::string& d, double s, const std::string& p);

    // Métodos de acceso y modificación
    void setDomicilio(const std::string& d);
    void setSueldo(double s);
    void setPersonaReporta(const std::string& p);

    std::string getClave() const;
    std::string getNombre() const;
    std::string getDomicilio() const;
    double getSueldo() const;
    std::string getPersonaReporta() const;

    // Método para imprimir los datos del empleado
    void imprimirDatos() const;

    // Operador para comparar claves
    bool operator==(const Empleado& other) const;
};

// Operadores de entrada y salida
std::ostream& operator<<(std::ostream& os, const Empleado& e);
std::istream& operator>>(std::istream& is, Empleado& e);

#endif // EMPLEADO_H
