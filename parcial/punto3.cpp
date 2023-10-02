#include <iostream>
#include <conio.h>
using namespace std;

struct Elmto {
    int num;
    Elmto* siguiente;
};

Elmto* pi = nullptr;
Elmto* pa = nullptr;
Elmto* pf = nullptr;

typedef struct Elmto* Tlista;

void insertar_dato(int dato) {
    if (pi == nullptr) {
        pi = new Elmto;
        pi->num = dato;
        pf = pi;
    } else {
        pa = new Elmto;
        pf->siguiente = pa;
        pa->num = dato;
        pf = pa;
    }
    pf->siguiente = nullptr;
}

void mostrar_lista() {
    int i = 0, band = 0;
    pa = pi;
    cout << endl << endl << "elementos de la lista " << endl << endl;
    while (pa != nullptr) {
        cout << "elemento " << i << ": " << pa->num << endl << endl;
        band = 1;
        pa = pa->siguiente;
        i++;
    }
}

int contar_elementos() {
    int contador = 0;
    pa = pi;
    while (pa != nullptr) {
        contador++;
        pa = pa->siguiente;
    }
    return contador;
}

int busquedaBinaria(int objetivo, int inicio, int fin) {
    int izquierda = inicio;
    int derecha = fin;

    while (izquierda <= derecha) {
        int medio = izquierda + (derecha - izquierda) / 2;
        int valorMedio = 0;

        pa = pi;
        for (int i = 0; i < medio; i++) {
            pa = pa->siguiente;
        }
        valorMedio = pa->num;

        if (valorMedio == objetivo) {
            return medio;
        } else if (valorMedio < objetivo) {
            izquierda = medio + 1;
        } else {
            derecha = medio - 1;
        }
    }

    return -1;
}

int main() {
    int dato;
    char respuesta;
    int n = 0;

    do {
        cout << endl << "*******************************************";
        cout << endl << "Ingrese un dato: ";
        cin >> dato;
        insertar_dato(dato);
        n++; 
        cout << endl << "Seguir ingresando datos? (s/n)";
        respuesta = getch();

    } while (respuesta == 's');
    mostrar_lista();

    do {
        cout << endl << "*******************************************";
        cout << endl << "Deseas buscar elementos? (s/n): ";
        respuesta = getch();
        if (respuesta == 's') {
            int objetivo;
            cout << "\nIngrese el valor a buscar en la lista: ";
            cin >> objetivo;

            pa = pi; 
            int indiceEncontrado = busquedaBinaria(objetivo, 0, n - 1);

            if (indiceEncontrado != -1) {
                cout << "*****************************************" << endl;
                cout << "El valor " << objetivo << " se encuentra en la posicion " << indiceEncontrado << endl;
                cout << "*****************************************" << endl;
            } else {
                cout << "*****************************************" << endl;
                cout << "-1" << endl;
                cout << "*****************************************" << endl;
            }
        }
    } while (respuesta == 's');

    return 0;
}
