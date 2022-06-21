#include "Nodo.h"

using namespace std;
#include <string>
#include <iostream>
#include <stdio.h>

Nodo* Nodo::insertar(Nodo*& __lista, int __id, string __nombre) {
	Nodo* nuevo_nodo = new Nodo();
	nuevo_nodo->id = __id;
	nuevo_nodo->nombre = __nombre;

	Nodo* _lista = NULL;
	if (__lista != NULL) {
		_lista = __lista;
	}
	Nodo* aux1 = _lista;
	Nodo* aux2 = NULL;

	while ((aux1 != NULL) && (aux1->id < __id)) {
		aux2 = aux1;
		aux1 = aux1->sig;
	}

	if (_lista == aux1) {
		_lista = nuevo_nodo;
	}
	else {
		aux2->sig = nuevo_nodo;
	}

	nuevo_nodo->sig = aux1;

	//cout << "id: " << __id << " de: " << __nombre <<" agregado correctamente\n";
	return _lista;
}

void Nodo::mostrar(Nodo* __lista) {
	Nodo* actual = new Nodo();
	actual = __lista;

	while (actual != NULL) {
		cout << actual->id << ": " << actual->nombre << endl;
		actual = actual->sig;
	}
}

void Nodo::buscar(Nodo* __lista, int __id) {
	bool encontrado = false;
	Nodo* actual = __lista;
	while (actual != NULL) {
		if (actual->id == __id) {
			cout << "Es: " << actual->nombre << endl;
			encontrado = true;
		}
		actual = actual->sig;
	}

	if (encontrado) {
		cout << __id << ": encontrado" << endl;
	}
	else {
		cout << __id << ": no fue encontrado" << endl;
	}
}

Nodo* Nodo::completar(Nodo*& __lista, int __id) {
	bool encontrado = false;
	Nodo* temp = NULL;
	Nodo* actual = __lista;
	while (actual != NULL) {
		if (actual->id == __id) {
			// it works... -> cout << actual->nombre << " - listo" << endl;
			temp = temp->insertar(temp, actual->id, actual->nombre + " - listo");
			encontrado = true;
		}
		else {
			temp = temp->insertar(temp, actual->id, actual->nombre);
		}
		actual = actual->sig;
	}

	if (encontrado) {
		cout << __id << ": modificado" << endl;
	}
	else {
		cout << __id << ": no fue modificado" << endl;
	}

	return temp;
}

Nodo* Nodo::eliminar(Nodo* __lista, int __id) {
	bool encontrado = false;
	Nodo* actual = __lista;
	Nodo* temp = NULL;
	while (actual != NULL) {
		if (actual->id != __id) {
			temp = temp->insertar(temp, actual->id, actual->nombre);
		}
		else {
			encontrado = true;
		}
		actual = actual->sig;
	}

	if (encontrado) {
		cout << __id << ": eliminado" << endl;
	}
	else {
		cout << __id << ": no fue eliminado" << endl;
	}
	return temp;
}