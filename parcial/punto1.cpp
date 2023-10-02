#include <iostream>
#include <conio.h>
using namespace std;

struct nodo
{
    int valor;
    nodo* NodoIzquierda;
    nodo* NodoDerecha;
};

void FormaArbol(nodo*arbol, int n){
        if(arbol==NULL)
            return;
            FormaArbol(arbol->NodoDerecha, n+1);

        for(int i=0; i<n; i++)
            cout<<"   ";

        cout<< arbol->valor <<endl;

        FormaArbol(arbol->NodoIzquierda, n+1);
}

nodo* insertar(nodo* arbol, int valor) {
    if (arbol == nullptr) {
        nodo* nuevo = new nodo;
        nuevo->valor = valor;
        nuevo->NodoIzquierda = nullptr;
        nuevo->NodoDerecha = nullptr;
        return nuevo;
    }

    if (valor < arbol->valor) {
        arbol->NodoIzquierda = insertar(arbol->NodoIzquierda, valor);
    } else if (valor > arbol->valor) {
        arbol->NodoDerecha = insertar(arbol->NodoDerecha, valor);
    }

    return arbol;
}

int Niveles(nodo* arbol) {
    if (arbol == nullptr)
        return 0;
    
    int NivelesIzquierda = Niveles(arbol->NodoIzquierda);
    int NivelesDerecha = Niveles(arbol->NodoDerecha);

    return max(NivelesIzquierda, NivelesDerecha) + 1;
}


int main() {
    int valor;
    char respuesta;
    nodo* arbol = nullptr;
    system("color 0B");

    do {
        cout << "Ingresar nodo al arbol: ";
        cin >> valor;
        arbol = insertar(arbol, valor);
        cout << "Deseas seguir ingresando nodos al arbol? (s/n): ";
        respuesta = getch();
        cout << endl;
    } while (respuesta == 's');

    cout<<"\n Arbol con forma de arbol"<<endl;
    FormaArbol( arbol, 0);

        int NivelesArbol = Niveles(arbol);
        cout << "El Arbol tiene  " << NivelesArbol <<" niveles"<< endl;
    
    return 0;
}