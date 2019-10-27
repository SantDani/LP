//Insertar un elemento en una lista

#include<iostream>
#include<conio.h>
#include <cstdlib> //random
#include"Node.h"
using namespace std;



//FUNCIONES: prototipos
void addNodo(Nodo *&nodo, int num);
void addNodoOrdenado(Nodo*& nodo, int num);
void mostrarLista(Nodo * lista);
void addNumRandom(Nodo *&lista , int nodo);
bool encontrar(Nodo* lista, int numEncontrar);
void eliminar(Nodo*& lista, int n);
void eliminarLista(Nodo*& lista);


int main()
{
	Nodo* lista = NULL;

	//addNumRandom(lista, 50);

	addNodo(lista, 2);
	addNodo(lista, 3);
	addNodo(lista, 10);
	addNodo(lista, 50);
	mostrarLista(lista);

	eliminar(lista, 2);
	eliminar(lista, 50);
	mostrarLista(lista);

	cout << "n\Mostrar lista despues de borrar" << endl;
	eliminarLista(lista);
	mostrarLista(lista);

	return 0;
}

//FUNCIONES: definicion
void addNodo(Nodo*& ultimoNodo_lista, int num) 
{
	Nodo *nuevo_nodo = new Nodo();

	nuevo_nodo->setValor(num);

	Nodo *aux1  = ultimoNodo_lista;
	Nodo *aux2;

	if (aux1 == NULL)
		aux1 = nuevo_nodo;
	else 
	{
		nuevo_nodo->setNext(ultimoNodo_lista);
	}
	ultimoNodo_lista = nuevo_nodo;
}

void addNodoOrdenado(Nodo*& ultimoNodo_lista, int num)
{
	Nodo* nuevo_nodo = new Nodo();

	nuevo_nodo->setValor(num);

	Nodo* aux1 = ultimoNodo_lista;
	Nodo* aux2 = NULL;

	while ((aux1 != NULL) && (aux1->getValor() < num))
	{
		aux2 = aux1;
		aux1 = aux1->getNext(); 

	}

	if (ultimoNodo_lista == aux1) // condicional que se cumple cuando no ha entrado en while
	{
		// insertamos el nodo al inicio de nuestra lista
		ultimoNodo_lista = nuevo_nodo;
		
	}
	else {//ha entrado en el while. Por lo tanto se han ordenado los nodos
		aux2->setNext(nuevo_nodo);
	}

	nuevo_nodo->setNext(aux1);

	cout << "add correctamente" << endl;
}

void mostrarLista(Nodo *lista)
{
	Nodo *actual = new Nodo();

	actual = lista;
	int i = 0;
	while (actual != NULL)
	{
		i++;
		int num = actual->getValor();
		cout << "num " << i <<" : " << num << endl;
		actual = actual->getNext();
	}

}

void addNumRandom(Nodo *&lista,int cant)
{
	for (int i = 0; i < cant; i++)
	{
		int num = rand() % 100; // num in the range 0 to 99
		addNodo(lista, num);

	}
}

bool encontrar(Nodo* lista, int numEncontrar)
{
	Nodo* actual = new Nodo();
	actual = lista;

	bool encontrado = false;
	while (actual != NULL)
	{
		if (actual->getValor() == numEncontrar)
			encontrado = true;
		actual = actual->getNext();
	}

	if (encontrado)
		cout << "Elemento " << numEncontrar << " encontrado en la lista" << endl;
	else
		cout << "Elemento " << numEncontrar << " NO encontrado en la lista" << endl;
	return encontrado;
}

void eliminar(Nodo*& lista, int numEncontrar)
{

	if (lista != NULL)
	{
		Nodo* aux_borrar = new Nodo();
		Nodo* anterior = NULL;

		//aux_borrar = lista;
		aux_borrar->setNext(lista);
		

		while ((aux_borrar != NULL) && (aux_borrar->getValor() != numEncontrar))
		{
			anterior = aux_borrar;
			aux_borrar = aux_borrar->getNext();
		}

		/*
		Ahora tenemos dos casos
		1- NO encontramos el elemento a borrar
		2- Elemento a borrar es el primero
		3- Elemento a borrar esta en medio de los nodos*/

		// no encontramos elemento que hay que borrar
		if (aux_borrar == NULL) 
			cout << "Elemento no encontrado" << endl;
		// el elemento a borrar es el primero
		else if (anterior == NULL)
		{
			lista = lista->getNext();
			delete aux_borrar;
		}
		// el elemento esta en medio de los nodos
		else 
		{
			anterior->setNext(aux_borrar->getNext());
			delete aux_borrar;
		}
	}
}

void eliminarLista(Nodo*& lista)
{
	Nodo* aux = new Nodo();

	while (lista != NULL)
	{
		aux = lista;
		lista = aux->getNext();
		delete aux;
	}
	
}