#pragma once
#define NODO_H
#ifdef NODO_H

using namespace std;
#include<string>

class Nodo
{
private:
	Nodo* sig;
	int id;
	string nombre;
public:
	Nodo() {};
	Nodo* insertar(Nodo*& __lista, int __id, string __nombre);
	void mostrar(Nodo* __lista);
	void buscar(Nodo* __lista, int __id);
	Nodo* completar(Nodo*& __lista, int __id);
	Nodo* eliminar(Nodo* __lista, int __id);
};

#endif //NODO_H
