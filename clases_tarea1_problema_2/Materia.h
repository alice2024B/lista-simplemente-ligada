#ifndef MATERIA_H
#define MATERIA_H

#include <iostream>
#include <string>

class Materia {
private:
    std::string clave;
    std::string nombre;
    std::string maestro;
    int creditos;

public:
    // Constructor por defecto
    Materia();

    // Constructor con par�metros
    Materia(const std::string& c, const std::string& n, const std::string& m, int cr);

    // M�todos de acceso y modificaci�n
    void setClave(const std::string& c);
    void setMaestro(const std::string& m);

    std::string getClave() const;
    std::string getNombre() const;
    std::string getMaestro() const;
    int getCreditos() const;

    // M�todo para imprimir los datos de la materia
    void imprimirDatos() const;

    // Operadores de entrada y salida
    friend std::ostream& operator<<(std::ostream& os, const Materia& m);
    friend std::istream& operator>>(std::istream& is, Materia& m);
};

#endif // MATERIA_H
