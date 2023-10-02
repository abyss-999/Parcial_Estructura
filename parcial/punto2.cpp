#include <iostream>
#include <conio.h>
using namespace std;

struct nodo {
    int dato;
    struct nodo* siguiente;
};
void insertar(nodo*& lista, int n);
void mostrarLista(nodo* lista);
void quickSort(nodo*& lista);
int main() {
    nodo* lista = NULL;
    int nro, m;
    cout << "Cantidad de la lista\n";
    cin >> m;
    for (int i = 0; i < m; i++) {
        cout << "Ingrese el valor\n";
        cin >> nro;
        insertar(lista, nro);
    }
    int opc;
    do {
        cout << "OPCIONES\n";
        cout << "1. Mostrar lista en desorden\n";
        cout << "2. Mostrar lista organizada por QuickSort\n";
        cin >> opc;
        switch (opc) {
            case 1:
                cout << "Lista en desorden: ";
                mostrarLista(lista);
                system("pause");
                break;
            case 2:
                quickSort(lista);
                cout << "Lista ordenada por QuickSort: ";
                mostrarLista(lista);
                system("pause");
                break;
        }
        system("cls");
    } while (opc != 3);
    return 0;
}
void insertar(nodo*& lista, int n) {
    nodo* Nlista = new nodo();
    Nlista->dato = n;
    Nlista->siguiente = lista;
    lista = Nlista;
}
void mostrarLista(nodo* lista) {
    nodo* actual = lista;
    while (actual != NULL) {
        cout << actual->dato << " ";
        actual = actual->siguiente;
    }
    cout << endl;
}
void quickSort(nodo*& lista) {
    if (lista == NULL || lista->siguiente == NULL) {
        return;
    }
    nodo* pivote = lista;
    lista = lista->siguiente;
    nodo* menos = NULL;
    nodo* mayor = NULL;
    while (lista != NULL) {
        nodo* siguiente = lista->siguiente;
        if (lista->dato < pivote->dato) {
            lista->siguiente = menos;
            menos = lista;
        } else {
            lista->siguiente = mayor;
            mayor = lista;
        }
        lista = siguiente;
    }
    quickSort(menos);
    quickSort(mayor);
    if (menos == NULL) {
        lista = pivote;
    } else {
        nodo* cola = menos;
        while (cola->siguiente != NULL) {
            cola = cola->siguiente;
        }
        cola->siguiente = pivote;
        lista = menos;
    }
    pivote->siguiente = mayor;
}
















