#include <iostream>
#include <string>

template<class T>
class LSLSE;

template<class T>
class node {
private:
    T data;
    node<T>* sig;
public:
    node() : sig(nullptr) {}
    friend class LSLSE<T>;

    T getData() const {
        return data;
    }
};

class SocioClub {
public:
    int numeroSocio;
    std::string nombreSocio;
    std::string domicilio;
    int anioIngreso;

    // Constructor por defecto
    SocioClub() : numeroSocio(0), anioIngreso(0) {}

    // Constructor parametrizado
    SocioClub(int ns, const std::string& nom, const std::string& dom, int anio)
        : numeroSocio(ns), nombreSocio(nom), domicilio(dom), anioIngreso(anio) {}

    friend std::ostream& operator<<(std::ostream& os, const SocioClub& socio) {
        os << "Numero de Socio: " << socio.numeroSocio
           << ", Nombre: " << socio.nombreSocio
           << ", Domicilio: " << socio.domicilio
           << ", Anio de Ingreso: " << socio.anioIngreso;
        return os;
    }

    bool operator==(const SocioClub& other) const {
        return numeroSocio == other.numeroSocio;
    }
};

template<class T>
class LSLSE {
private:
    node<T>* lista;
public:
    LSLSE() : lista(nullptr) {}
    bool vacia() const;
    void insertar(T elem);
    bool eliminar(int numeroSocio);
    void imprimir() const;
    int total() const;
    node<T>* buscarPorNombreYDomicilio(const std::string& nombre, const std::string& domicilio) const;
    node<T>* buscarPorNumero(int numeroSocio) const;
};

template<class T>
void LSLSE<T>::imprimir() const {
    node<T>* aux = lista;
    while (aux != nullptr) {
        std::cout << aux->getData() << " -> ";
        aux = aux->sig;
    }
    std::cout << "nullptr" << std::endl;
}

template<class T>
bool LSLSE<T>::eliminar(int numeroSocio) {
    node<T>* aux = lista;
    node<T>* anterior = nullptr;

    while (aux != nullptr && aux->getData().numeroSocio != numeroSocio) {
        anterior = aux;
        aux = aux->sig;
    }

    if (aux == nullptr) return false; // No se encontró

    if (anterior == nullptr) {
        lista = lista->sig; // Eliminar el primer nodo
    } else {
        anterior->sig = aux->sig; // Eliminar nodo intermedio o final
    }
    delete aux;
    return true;
}

template<class T>
void LSLSE<T>::insertar(T elem) {
    node<T>* nuevo = new node<T>;
    nuevo->data = elem;
    nuevo->sig = nullptr;

    if (vacia() || lista->getData().numeroSocio > elem.numeroSocio) {
        nuevo->sig = lista;
        lista = nuevo;
    } else {
        node<T>* aux = lista;
        while (aux->sig != nullptr && aux->sig->getData().numeroSocio < elem.numeroSocio) {
            aux = aux->sig;
        }
        nuevo->sig = aux->sig;
        aux->sig = nuevo;
    }
}

template<class T>
bool LSLSE<T>::vacia() const {
    return lista == nullptr;
}

template<class T>
int LSLSE<T>::total() const {
    int contador = 0;
    node<T>* aux = lista;
    while (aux != nullptr) {
        contador++;
        aux = aux->sig;
    }
    return contador;
}

template<class T>
node<T>* LSLSE<T>::buscarPorNumero(int numeroSocio) const {
    node<T>* aux = lista;
    while (aux != nullptr) {
        if (aux->getData().numeroSocio == numeroSocio) {
            return aux; // Retornar el nodo encontrado
        }
        aux = aux->sig;
    }
    return nullptr; // No se encontró
}

template<class T>
node<T>* LSLSE<T>::buscarPorNombreYDomicilio(const std::string& nombre, const std::string& domicilio) const {
    node<T>* aux = lista;
    while (aux != nullptr) {
        if (aux->getData().nombreSocio == nombre &&
            aux->getData().domicilio == domicilio) {
            return aux; // Retornar el nodo encontrado
        }
        aux = aux->sig;
    }
    return nullptr; // No se encontró
}

void menu() {
    std::cout << "\nMenu:\n";
    std::cout << "1. Registrar un nuevo socio\n";
    std::cout << "2. Dar de baja un socio\n";
    std::cout << "3. Generar reporte de socios\n";
    std::cout << "4. Buscar socio por nombre y domicilio\n";
    std::cout << "5. Total de socios registrados\n";
    std::cout << "6. Salir\n";
}

int main() {
    LSLSE<SocioClub> milista;
    int opcion;

    while (true) {
        menu();
        std::cout << "Seleccione una opcion: ";
        std::cin >> opcion;

        if (opcion == 1) { // Registrar un nuevo socio
            int numeroSocio;
            std::string nombreSocio;
            std::string domicilio;
            int anioIngreso;

            std::cout << "Numero de socio: ";
            std::cin >> numeroSocio;
            std::cout << "Nombre: ";
            std::cin.ignore();
            std::getline(std::cin, nombreSocio);
            std::cout << "Domicilio: ";
            std::getline(std::cin, domicilio);
            std::cout << "Anio de ingreso: ";
            std::cin >> anioIngreso;

            SocioClub nuevo_socio(numeroSocio, nombreSocio, domicilio, anioIngreso);
            if (milista.buscarPorNumero(numeroSocio) == nullptr) {
                milista.insertar(nuevo_socio);
                std::cout << "Socio registrado con exito.\n";
            } else {
                std::cout << "Error: Ya existe un socio con ese numero.\n";
            }
        }
        else if (opcion == 2) { // Dar de baja un socio
            int numeroSocio;
            std::cout << "Numero de socio a dar de baja: ";
            std::cin >> numeroSocio;
            if (milista.eliminar(numeroSocio)) {
                std::cout << "Socio dado de baja con exito.\n";
            } else {
                std::cout << "No se encontro el socio.\n";
            }
        }
        else if (opcion == 3) { // Generar reporte
            std::cout << "\nReporte de socios:\n";
            milista.imprimir();
        }
        else if (opcion == 4) { // Buscar socio por nombre y domicilio
            std::string nombreSocio;
            std::string domicilio;
            std::cout << "Nombre del socio a buscar: ";
            std::cin.ignore();
            std::getline(std::cin, nombreSocio);
            std::cout << "Domicilio del socio a buscar: ";
            std::getline(std::cin, domicilio);
            node<SocioClub>* socio = milista.buscarPorNombreYDomicilio(nombreSocio, domicilio);
            if (socio) {
                std::cout << "Socio encontrado: " << socio->getData() << "\n";
            } else {
                std::cout << "No se encontro el socio.\n";
            }
        }
        else if (opcion == 5) { // Total de socios
            std::cout << "Total de socios registrados: " << milista.total() << "\n";
        }
        else if (opcion == 6) { // Salir
            std::cout << "Saliendo del programa.\n";
            break;
        }
        else {
            std::cout << "Opcion no valida, intente de nuevo.\n";
        }
    }
    return 0;
}


