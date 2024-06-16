//
//  llist.h
//

#ifndef llist_h
#define llist_h

// Nodos de la lista:
template <typename T>
class llnode
{
public:
  // Esta clase es para ser usada por otras clases. Por eficiencia los atributos se dejan publicos.
  T key;
  llnode<T> *prev, *next;
  
  // Constructor por omision.
  llnode() {
  };
  
  // Inicializacion de los datos miembro.
  llnode (const T& k, llnode<T> *w = nullptr, llnode<T> *y = nullptr):key(k), prev(w), next(y)  {};
  
  ~llnode() {
  };
};

// Lista enlazada con nodo centinela:
template <typename T>
class llist
{
public:
  llnode<T> *nil;        // nodo centinela

  llist() {
    // Constructor (crea una lista vacia)
    nil = new llnode<T>();
    nil->next = nil; // el nodo siguiente apunta a si mismo
    nil->prev = nil; // el nodo anterior apunta a si mismo
  };
  
  ~llist() {
    // Destructor (borra la lista)
    llnode<T>* current = nil->next; // obtener la cabeza
    while (current != nil) { // si es distinto al centinela
      llnode<T>* to_delete = current; // guardar el puntero a borrar
      current = current->next; // guardar el siguiente
      delete to_delete; // borrar el actual
    }
    delete nil; // borrar el centinela
  };
  
  void Insert(llnode<T>* x) {
    // Inserta el nodo x en la lista.
    x->next = nil->next; // asignar el siguiente del nuevo nodo
    x->prev = nil; // asignar el anterior del nuevo nodo
    nil->next->prev = x; // hacer que el prev de la cabeza anterior ya no apunte a nil sino al nodo que estamos insertando
    nil->next = x; // ahora la caebza es nuestro nuevo nodo
  };

  llnode<T>* Search(const T& k) {
    // Busca la llave iterativamente. Si la encuentra, devuelve un apuntador al nodo que la contiene; sino devuelve el nodo nil (el centinela).
    llnode<T>* current = nil->next; // obtener la cabeza
    while (current != nil && current->key != k) { // buscar hasta que el current sea el centinela o se encuentre la llave
        current = current->next;
    }
    return current; // y retornar el valor encontrado
  };
      
  void Delete(llnode<T>* x) {
    // Saca de la lista la llave contenida en el nodo apuntado por x.
    if (x != nil) { // si no se esta pidiendo eliminar el centinela 
      // se va a explicar con un ejemplo en vez de palabras con una lista de 
      // ejemplo en el que cada nodo se representa por (direccion, k=a) con a
      // el valor de la llave del nodo. -> representa el siguiente nodo.
      // <- representa el antarior
      // Nodo centinela, k vacio: (0x2, k=9) <- (0x0, k) -> (0x5, k=2)
      // Lista: (0x5, k=13) <--> (0x7, k=12) <--> (0x3, k=3) <--> (0x9, k=7) 
      // Supongamos que se quiere eliminar 0x7
      x->prev->next = x->next; // x->prev: (0x5, k=13)
                               // x->next: (0x3, k=3)
                               // x->prev->next = x->next significa
                               // (0x5, k=13) -> (0x3, k=3)
      x->next->prev = x->prev; // x->next: (0x3, k=3)
                               // x->prev: (0x5, k=13)
                               // x->next->prev = x->prev significa
                               // (0x5, k=13) <- (0x3, k=3)
      // Con esto conseguimos la conexion (0x5, k=13) <--> (0x3, k=3)
      delete x; // como ya reubicamos las conexiones podemos borrar el nodo en cuestion
    }
  };    
};

#endif /* llist_h */
