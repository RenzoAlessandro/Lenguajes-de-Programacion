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

template <class T>
struct Nodo {
    T valor; // Se almacena el valor del dato
    struct Nodo<T>* siguiente; // puntero al siguiente nodo de la lista
};

template <class T>
class LinkedList {
protected:
    Nodo<T>* head; // Puntero a la cabeza de la Lista
    Nodo<T>* tail; // Puntero a la cola de la Lista

public:
    LinkedList()
    { // Constructor
        head = NULL;
        tail = NULL;
    }

    ~LinkedList()
    { // Destructor
        DestruirLista();
    }

    void ImprimirLista()
    {
        Nodo<T>* NodoActual = head;

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

    void AgregarNodo(T NuevoValor)
    { // Insertar al final
        // Creamos un nuevo nodo
        Nodo<T>* NuevoNodo = new Nodo<T>;
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

    T EliminarHead()
    {
        // Comprobar para asegurarse de que haya algo para eliminar
        T valor;
        if (head != NULL) {
            Nodo<T>* NodoToDelete = head;
            head = head->siguiente;
            valor = NodoToDelete->valor;
            delete NodoToDelete;
            if (head == NULL) {
                tail = NULL;
            }
        }
        return valor;
    }

    void DestruirLista()
    {
        // Liberamos la memoria de cada nodo en la lista
        Nodo<T>* NodoActual = head;
        Nodo<T>* siguienteNodo = NULL;

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

template <class T>
class Queue : public LinkedList<T> {
    // No se necesitan atributos específicos de la cola
public:
    // Operaciones de cola comunes
    virtual void enqueue(T NuevoValor)
    {
        LinkedList<T>::AgregarNodo(NuevoValor);
    }

    T dequeue()
    {
        return LinkedList<T>::EliminarHead();
    }

    int peek()
    {
        if (LinkedList<T>::head != NULL) {
            return LinkedList<T>::head->valor;
        }
        return -1;
    }

    // Dos formas de limpiar la Cola
    // 1ra Forma: Usando el dequeue propio de la Cola
    void clearQ()
    {
        while (!isEmpty()) {
            dequeue();
        }
    }

    // 2da Forma: Usando el destructor del Linked List
    void clearL()
    {
        LinkedList<T>::DestruirLista();
    }

    bool isEmpty()
    {
        if (LinkedList<T>::head != NULL) {
            return false;
        }
        return true;
    }

    // Recorrer la lista enlazada y contamos
    // el número de nodos O(N)
    int size()
    {
        int count = 0;
        Nodo<T>* NodoActual = LinkedList<T>::head;
        while (NodoActual != NULL) {
            count++;
            NodoActual = NodoActual->siguiente;
        }
        return count;
    }
};

int main()
{
	cout << endl;
	cout << "\t    LISTA ENLAZADA" << endl;
	cout << "\t  -------------------" << endl << endl;
	cout << "\t1. INSERTAR (INT):" << endl << endl;
	LinkedList<int> list_int;
	list_int.AgregarNodo(12);
	list_int.AgregarNodo(5);
	list_int.AgregarNodo(3);
	list_int.ImprimirLista();
	cout << endl;

	cout << "\t2. INSERTAR (STRING):" << endl << endl;
	LinkedList<string> list_string;
	list_string.AgregarNodo("Renzo");
	list_string.AgregarNodo("Aly");
	list_string.AgregarNodo("Nidia");
	list_string.AgregarNodo("Maria");
	list_string.AgregarNodo("James");
	list_string.ImprimirLista();
	cout << endl;

	cout << "\t3. ELIMINAR (INT):" << endl << endl;
	list_int.EliminarHead();
	list_int.ImprimirLista();
	cout << endl;

	cout << "\t4. ELIMINAR (STRING):" << endl << endl;
	list_string.EliminarHead();
	list_string.ImprimirLista();
	cout << endl;

	cout << "\t5. DESTRUCTOR (INT):" << endl << endl;
	list_int.DestruirLista();
	list_int.ImprimirLista();
	cout << endl;

	cout << "\t6. DESTRUCTOR (STRING):" << endl << endl;
	list_string.DestruirLista();
	list_string.ImprimirLista();
	cout << endl;


	cout << endl;
	cout << "\t       COLA " << endl;
	cout << "\t     --------" << endl << endl;
	cout << "\t1. ENQUEUE (INT):" << endl << endl;
	Queue<int> Queue_int;
	Queue_int.enqueue(9);
	Queue_int.enqueue(23);
	Queue_int.enqueue(56);
	Queue_int.enqueue(8);
	Queue_int.ImprimirLista();
	cout << endl;

	cout << "\t2. ENQUEUE (STRING):" << endl << endl;
	Queue<string> Cola_string;
	Cola_string.enqueue("Renzo");
	Cola_string.enqueue("Aly");
	Cola_string.enqueue("Nidia");
	Cola_string.enqueue("Maria");
	Cola_string.enqueue("James");
	Cola_string.enqueue("Wilber");
	Cola_string.ImprimirLista();
	cout << endl;

	cout << "\t3. DEQUEUE (INT):" << endl << endl;
	Queue_int.dequeue();
	Queue_int.ImprimirLista();
	cout << endl;

	cout << "\t4. DEQUEUE (STRING):" << endl << endl;
	Cola_string.dequeue();
	Cola_string.ImprimirLista();
	cout << endl;

	cout << "\t5. DESTRUCTOR (INT):" << endl << endl;
	Queue_int.clearQ();
	Queue_int.ImprimirLista();
	cout << endl;

	cout << "\t6. DESTRUCTOR (STRING):" << endl << endl;
	Cola_string.clearQ();
	Cola_string.ImprimirLista();
	cout << endl;

	return 0;
}