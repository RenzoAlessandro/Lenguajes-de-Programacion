/**
 * Copyright 2020 Renzo Alessandro Sucari Velasquez
 * Solución : Lista Enlazada con Cola / Linked List with Queue
 * Usando   : Herencia y Templates / Heritage and Template
 * Resultado: OK
**/

#include <iostream>

using namespace std;

/**
 * Una lista enlazada de nodos
 * cada nodo almacena un valor de tipo T 
 * Se puede expandir para almacenar varios datos
**/

template<class T>
struct Nodo {
	T valor; 			   // Se almacena el valor del dato
	struct Nodo<T> * siguiente; // puntero al siguiente nodo de la lista
}; 

template<class T>
class LinkedList {
	protected:
		Nodo<T> * head; // Puntero a la cabeza de la Lista
		Nodo<T> * tail; // Puntero a la cola de la Lista

	public:
		LinkedList(){ // Constructor
		head = NULL;
		tail = NULL;
	}

	~LinkedList(){ // Destructor
		DestruirLista();
	} 

	void ImprimirLista(){
		Nodo<T> * NodoActual = head;

		cout << "HEAD-> ";
		while (NodoActual != NULL) {
			cout << NodoActual->valor << " -> ";
			NodoActual = NodoActual->siguiente;
		}
		cout << "NULL" << endl;
		if (tail != NULL) {
			cout << "TAIL-> " << tail->valor << endl;
		}
		else {
			cout << "TAIL-> NULL" << endl;
		}
	}
	
	void AgregarNodo(T NuevoValor){ // Insertar al final
	// Creamos un nuevo nodo
		Nodo<T> * NuevoNodo = new Nodo<T>;
		NuevoNodo->valor = NuevoValor;
		NuevoNodo->siguiente = NULL;

		// 2 Casos: Lista esta vacia
		if (head == NULL) {
			head = NuevoNodo;
			tail = NuevoNodo;
		}
		else {
			// Lista no esta vacia
			tail->siguiente = NuevoNodo;
			tail = NuevoNodo;
		}
	}

	int EliminarHead(){
		// Comprobar para asegurarse de que haya algo para eliminar
		int valor = -1;
		if (head != NULL) {
			Nodo<T> * NodoToDelete = head;
			head = head->siguiente;
			valor = NodoToDelete->valor;
			delete NodoToDelete;
			if (head == NULL) {
				tail = NULL;
			}
		}
		return valor;
	}

	void DestruirLista(){
		// Liberamos la memoria de cada nodo en la lista
		Nodo<T> * NodoActual = head;
		Nodo<T> * siguienteNodo = NULL;

		while (NodoActual != NULL) {
			// Guarda el enlace al siguiente nodo
			siguienteNodo = NodoActual->siguiente;
			// Se puede eliminar NodoActual de forma segura
			delete NodoActual;
			NodoActual = siguienteNodo;
		}
		head = NULL;
		tail = NULL;
	}
};

template<class T>
class Queue : public LinkedList<T> {
	// No se necesitan atributos específicos de la cola
	public:
		// Operaciones de cola comunes
		virtual void enqueue(T NuevoValor) {
			LinkedList<T>::AgregarNodo(NuevoValor);
		}

		int dequeue() {
			return LinkedList<T>::EliminarHead();
		}

		int peek(){
			if (LinkedList<T>::head != NULL) {
				return LinkedList<T>::head->valor;
			}
			return -1;
		}

	// Dos formas de limpiar la Cola
	// 1ra Forma: Usando el dequeue propio de la Cola
	void clearQ(){	
		while (!isEmpty()) {
			dequeue();
		}
	}

	// 2da Forma: Usando el destructor del Linked List
	void clearL(){	
		LinkedList<T>::DestruirLista();	
	}

	bool isEmpty(){
		if (LinkedList<T>::head != NULL) {
			return false;
		}
		return true;
	}

	// Recorrer la lista enlazada y contamos 
	// el número de nodos O(N)
	int size(){
		int count = 0;
		Nodo<T> * NodoActual = LinkedList<T>::head;
		while (NodoActual != NULL) {
			count++;
			NodoActual = NodoActual->siguiente;
		}	
		return count;
	}
};

int main() {
	
	LinkedList<int> list_int; // start out empty list

	list_int.AgregarNodo(12);
	list_int.AgregarNodo(5);
	list_int.AgregarNodo(3);
	list_int.ImprimirLista();


	LinkedList<string> list_string; // start out empty list

	list_string.AgregarNodo("Renzo");
	list_string.AgregarNodo("Nidia");
	list_string.AgregarNodo("Maria");
	list_string.AgregarNodo("Aly");
	list_string.AgregarNodo("James");
	list_string.ImprimirLista();

	Queue<int> Cola_int;
	Cola_int.enqueue(9);
	Cola_int.enqueue(23);
	Cola_int.enqueue(56);
	Cola_int.enqueue(8);
	Cola_int.ImprimirLista();

	Cola_int.dequeue();
	Cola_int.ImprimirLista();

	Cola_int.clearQ();
	Cola_int.ImprimirLista();

	Queue<string> Cola_string;
	Cola_string.enqueue("a");
	Cola_string.enqueue("g");
	Cola_string.enqueue("e");
	Cola_string.enqueue("y");
	Cola_string.enqueue("q");
	Cola_string.enqueue("i");
	Cola_string.ImprimirLista();

	return 0;
}