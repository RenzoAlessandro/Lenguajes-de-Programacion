'''
 * Copyright 2020 Renzo Alessandro Sucari Velasquez
 * Solución : Lista Enlazada con Cola / Linked List with Queue
 * Usando   : Herencia y Templates / Heritage and Template
 * Resultado: OK
 * Lenguaje : Python3
'''

'''
 * Una lista enlazada de nodos
 * cada nodo almacena un valor de varios tipos (string, int, etc.) 
 * Se puede expandir para almacenar varios datos
'''
class Nodo():
    def __init__(self, valor):
        self.valor = valor  # Se almacena el valor del dato
        self.siguiente = None  # Puntero al siguiente nodo de la lista
    
    def __str__(self):
        return ("{}".format(self.valor)) 

    __repr__ = __str__


class LinkedList():
    def __init__(self): #Constructor
        self.count = 0
        self.head = None # Puntero a la cabeza de la Lista
        self.tail = None # Puntero a la cola de la Lista

    def __del__(self): #Destructor
      self.DestruirLista()

    def ImprimirLista(self):
      temp = self.head
      print("HEAD-> ", end='') 
      while (temp):
          print(temp.valor, end=' -> ')  
          temp = temp.siguiente
      print("NULL", end='') 
      print("\nTAIL->", self.tail) 

    def AgregarNodo(self, item): 
      # Insertar al final
      # Creamos un nuevo nodo
      new_Nodo= Nodo(item)
      # 2 Casos: Lista esta vacia
      if self.head== None:
        self.head= new_Nodo
        self.tail= new_Nodo
      else:
        # Lista no esta vacia
        self.tail.siguiente= new_Nodo
        self.tail= new_Nodo

    def EliminarHead(self):
      # Comprobar para asegurarse de que haya algo para eliminar
      if self.head== None:
          return "Queue is empty"
      else:
          val= self.head.valor
          self.head= self.head.siguiente
          return val
    
    def DestruirLista(self):
      self.__init__()
    
    
  # Herencias de LinkedList

class Queue(LinkedList):

  # Operaciones de cola comunes
  def enqueue(self, item):
    LinkedList.AgregarNodo(self, item)

  def dequeue (self):
    LinkedList.EliminarHead(self)

  def peek(self):
    return self.head.data

  # Dos formas de limpiar la Cola
  # 1ra Forma: Usando el dequeue propio de la Cola
  def clearQ(self):
    while self.isEmpty()==False:
      self.dequeue()
    self.tail = None

  # 2da Forma: Usando el destructor del Linked List
  def clearL(self):
    LinkedList.DestruirLista(self)

  def isEmpty(self):
    if self.head== None:
        return True
    else:
        return False
    
  def size(self):
      count= 0
      temp= self.head
      while temp!= None:
          count+=1
          temp= temp.siguiente
      return count

print("\n\t    LISTA ENLAZADA") 
print("\t  -------------------\n") 
print("\t1. INSERTAR (INT - STRING):\n") 
list_ = LinkedList()
list_.AgregarNodo("Renzo")
list_.AgregarNodo(12)
list_.AgregarNodo("Aly")
list_.AgregarNodo(34)
list_.AgregarNodo("Nidia")
list_.AgregarNodo("Maria")
list_.AgregarNodo(30)
list_.AgregarNodo(10)
list_.ImprimirLista()
print("") 

print("\t2. ELIMINAR (INT - STRING):\n") 
list_.EliminarHead()
list_.ImprimirLista()
print("")


print("\t3. DESTRUCTOR (INT - STRING):\n") 
list_.__del__()  # o list.DestruirLista()
list_.ImprimirLista()
print("")


print("\n\t    COLA") 
print("\t  --------\n") 
print("\t1. ENQUEUE (INT - STRING):\n") 
Queue_ = Queue()
Queue_.enqueue("Renzo")
Queue_.enqueue(27)
Queue_.enqueue("Aly")
Queue_.enqueue(54)
Queue_.enqueue("Nidia")
Queue_.enqueue("Maria")
Queue_.enqueue(60)
Queue_.enqueue(40)
Queue_.ImprimirLista()
print("")

print("\t2. DEQUEUE (INT - STRING):\n") 
Queue_.dequeue()
Queue_.ImprimirLista()
print("")

print("\t3. DESTRUCTOR (INT - STRING):\n") 
Queue_.clearQ() # o QQueue_.clearL()
Queue_.ImprimirLista()
print("")
