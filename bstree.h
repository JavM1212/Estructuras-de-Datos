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

  bstree() : root(nullptr) {}; // settear la raiz en nulo
  
  ~bstree() {
    clear(root); // borrado recursivo
  };

  void clear(bstnode<T> *node) {
    if (node != nullptr) { // si el nodo no es nulo
      clear(node->left); // borre el izquierdo
      clear(node->right); // y el derecho
      delete node; // cuando se terminen los llamados recursivos va a ir eliminando cada 1
    }
  }
  
  void Insert(bstnode<T>* z) {
    bstnode<T> *y = nullptr; // auxiliar
    bstnode<T> *x = root;

    while (x != nullptr) {
      y = x;
      if (z->key < x->key) { // menores a la izquierda
        x = x->left;
      } else { // mayores o iguales a la derecha
        x = x->right;
      }
    }

    z->p = y;
    if (y == nullptr) {
      root = z; // el árbol estaba vacío
    } else if (z->key < y->key) { // menores a la izquierda
      y->left = z;
    } else {
      y->right = z; // mayores a la derecha
    }
  };
  
  void InorderWalk(bstnode<T> *x) {
    if (x != nullptr) {
      InorderWalk(x->left);
      std::cout << x->key << std::endl;
      InorderWalk(x->right);
    }
  };
  
  bstnode<T>* Search(bstnode<T> *x, const T& k) {
    if (x == nullptr || k == x->key) { // ya no hay mas elementos por buscar o ya se encontro el deseado
      return x;
    }

    if (k < x->key) { // si es menor busque a la izquierda
      return Search(x->left, k); 
    } else { // si es mayor o igual busque a la derecha
      return Search(x->right, k);
    }
  };
  
  bstnode<T>* IterativeSearch(bstnode<T> *x, const T& k) {
    while (x != nullptr && k != x->key) { // deja de buscar cuando se le acaben los elemtnos por buscar o ya haya encontrado el deseado
      if (k < x->key) {
        x = x->left; // buscar la izquierda los menores
      } else {
        x = x->right; // buscar a la derecha los mayores o iguales
      }
    }
    return x;
  };
  
  bstnode<T>* Minimum(bstnode<T> *x) {
    while (x->left != nullptr) {
      x = x->left; // los menores siempre van a estar a la izquierda
                   // entonces busque hasta el ultimo
    }
    return x;
  };
  
  bstnode<T>* Maximum(bstnode<T> *x) {
    while (x->right != nullptr) {
        x = x->right; // Los mayores o iguales siempre van a estar a la
                      // derecha entonces busque hasta el ultimo
    }
    return x;
  };
  
  bstnode<T>* Successor(bstnode<T> *x) {
    if (x->right != nullptr) { // si el derecho no esta vacio, el sucesor va a
                               // estar en su lado derecho, que es como un subarbol
      return Minimum(x->right); // entonces basta con buscar el minimo de ese subarbol
    }

    // si el elemento que se le busca el sucesor no tiene nodo derecho, significa que
    // no tiene sucesor o esta arriba de el

    bstnode<T> *y = x->p; // guardar en y el padre de x
    while (y != nullptr && x == y->right) { // cuando esta condicion ya no se cumpla, va a retornar nullptr por que no encontro sucesor o el sucesor en y
      x = y; // ir recorriendo hacia arriba
      y = y->p; // ir recorriendo hacia arriba
    }
    return y;
  };
  
  void Delete(bstnode<T>* z) {
    bstnode<T> *y; // auxiliar
    bstnode<T> *x;

    if (z->left == nullptr) { // subarbol izquierdo vacio
      exchange(z, z->right);
    } else if (z->right == nullptr) { // subarbol derecho vacio
      exchange(z, z->left);
    } else { // tiene ambos subarboles
      y = Minimum(z->right); // hallar el minimo del arbol derecho de z
      if (y->p != z) { // si el papa del minimo del arbol derecho de z no es z
        exchange(y, y->right); // remplaza y con su subarbol derecho
        y->right = z->right; // conecta el subarbol derecho de z con y
        y->right->p = y; // padre del subarbo derecho de z a y
      }
      exchange(z, y); // remplazar z con y
      y->left = z->left; // conectar el subarbol izquierdo con z y y
      y->left->p = y; // actualizar el apdre del subarbol izquierdo de z a y
    }

    delete z; // liberar el elemento que se queria eliminar
  };  

  void exchange(bstnode<T>* u, bstnode<T>* v) {
    if (u->p == nullptr) { // si u es la raiz
      root = v; // remplaza la raiz por v
    } else if (u == u->p->left) { // si u es el hijo izquierdo de su padre
      u->p->left = v; // remplaza el izquierdo con el v
    } else { // si u es el hijo derechod e su padre
      u->p->right = v; // lo remplaza con el derecho
    }
    if (v != nullptr) { 
      v->p = u->p; // el padre de v ahora es el padre de u
    }
  }
};

#endif /* bstree_h */

