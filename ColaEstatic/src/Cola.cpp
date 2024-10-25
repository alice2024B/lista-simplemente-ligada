#include "Cola.h"

persona::persona(): nombre("juanito"), carrera(""), materiasAprobadas(0), promedio(0.0) {}

persona::persona(std::string n, std::string c, int m, float p)
    : nombre(n), carrera(c), materiasAprobadas(m), promedio(p) {}
void persona::operator=(persona& x)
{
    nombre=x.nombre;
    carrera=x.carrera;
    materiasAprobadas=x.materiasAprobadas;
    promedio=x.promedio;
}

std::ostream& operator<<( std::ostream& o, persona& p)
{
    o<<"Nombre: "<<p.nombre<<"\tCarrera: "<<p.carrera
     <<"\tMaterias Aprobadas: "<<p.materiasAprobadas
     <<"\tPromedio: "<<p.promedio;
    return o;
}
std::istream& operator>>( std::istream& o, persona& p)
{
    std::cout << "\nInserta nombre: ";
    o >> p.nombre;
    std::cout << "Inserta carrera: ";
    o >> p.carrera;
    std::cout << "Inserta materias aprobadas: ";
    o >> p.materiasAprobadas;
    std::cout << "Inserta promedio: ";
    o >> p.promedio;
    return o;
}

bool Cola::vacia()const
{
    return ult == -1;
}
bool Cola::llena()const
{
    return ult == TAM - 1;
}

int Cola::ultimo()const
{
    return ult;
}

std::ostream& operator<<(std::ostream & o, Cola& L)
{
    for (int i = 0; i <= L.ultimo(); i++) {
        o << L.datos[i]<<std::endl;
    }
    return o;
}

void Cola::enqueue(persona& elem)
{
    inserta(elem,ult + 1);
}

persona Cola::dequeue()
{
    if(vacia()){
        std::cout<<"\n La cola esta vacia"<<std::endl;
        return persona(); // Retorna un objeto vacío en caso de cola vacía
    }
    persona elem = datos[0];
    elimina(0);
    return elem;
}

bool Cola::elimina(int pos)
{
    if(vacia() || pos<0 || pos>ult)
    {
        std::cout<<"\n error de eliminacion"<< std::endl;
        return true;
    }
    for (int i = pos; i < ult; i++) {
        datos[i] = datos[i + 1];
    }
    ult--;
    return false;
}
int Cola::inserta(persona& elem, int pos)
{
    if(llena()|| pos<0 || pos>ult+1)
    {
        std::cout<<"\n Error de insercion"<< std::endl;
        return 0;
    }
    for (int i = ult + 1; i > pos; i--) {
        datos[i] = datos[i - 1];
    }
    datos[pos] = elem;
    ult++;
    return 1;
}
