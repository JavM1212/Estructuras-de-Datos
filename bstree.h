//
//  bstree.h
//

#ifndef bstree_h
#define bstree_h

#include <iostream>

// Nodos del arbol:
template <typename T>
class bstnode
{
public:
    // Esta clase es usada por otras clases. Para mayor eficiencia, los atributos se hacen publicos.
    T key;
    bstnode<T> *p, *left, *right;
    
    // Constructor por omision
    bstnode() {
    };
    
    // Inicializacion de datos miembro
    bstnode(const T& k, bstnode<T> *w = nullptr, bstnode<T> *y = nullptr, bstnode<T> *z = nullptr):key(k), p(w), left(y), right(z) {};
    
    ~bstnode() {
    };
};

// Arbol de busqueda binario:
template <typename T>
class bstree
{
public:
    bstnode<T> *root;    // raiz del arbol

    bstree() {
        // Constructor (crea un arbol vacio)
    };
    
    ~bstree() {
        // Destructor (borra el arbol)
    };
    
    void Insert(bstnode<T>* z) {
        // Inserta el nodo z en la posicion que le corresponde en el arbol.
    };
    
    void InorderWalk(bstnode<T> *x) {
        // Recorre en orden el sub‡arbol con raiz x, imprimiendo la llave de cada nodo en en una nueva linea de la salida estandar despues de recorrido el subarbol izquierdo y antes de recorrer el subarbol derecho.
    };
    
    bstnode<T>* Search(bstnode<T> *x, const T& k) {
        // Busca la llave k recursivamente en el subarbol con raiz x. Si la encuentra devuelve un apuntador al nodo que la contiene, sino devuelve nullptr.
    };
    
    bstnode<T>* IterativeSearch(bstnode<T> *x, const T& k) {
        // Busca la llave k iterativamente en el subarbol con raiz x. Si la encuentra devuelve un apuntador al nodo que la contiene, sino devuelve nullptr.
    };
    
    bstnode<T>* Minimum(bstnode<T> *x) {
        // Devuelve el nodo que tiene la llave menor. Si el arbol esta‡ vacio, devuelve nullptr.
    };
    
    bstnode<T>* Maximum(bstnode<T> *x) {
        // Devuelve el nodo que tiene la llave mayor. Si el arbol esta vacio devuelve nullptr.
    };
    
    bstnode<T>* Successor(bstnode<T> *x) {
        // Devuelve el nodo cuya llave es la que le sigue a la del nodo x. Si no existe el nodo, devuelve nullptr.
    };
    
    void Delete(bstnode<T>* z) {
        // Saca del arbol la llave contenida en el nodo apuntado por z.
    };  
};

#endif /* bstree_h */

