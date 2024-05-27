// main.cpp

#include <iostream>
#include "llist.h"

int main() {
    llist<int> list;

    // Insertar elementos
    list.Insert(new llnode<int>(10));
    list.Insert(new llnode<int>(20));
    list.Insert(new llnode<int>(30));
    list.Insert(new llnode<int>(40));

    // Mostrar la lista
    std::cout << "Lista después de las inserciones:" << std::endl;
    llnode<int>* current = list.nil->next;
    while (current != list.nil) {
        std::cout << current->key << " ";
        current = current->next;
    }
    std::cout << std::endl;

    // Búsqueda de elementos
    std::cout << "Buscar 30: " << (list.Search(30) != list.nil ? "Encontrado" : "No encontrado") << std::endl;
    std::cout << "Buscar 50: " << (list.Search(50) != list.nil ? "Encontrado" : "No encontrado") << std::endl;

    // Borrado de elementos
    llnode<int>* node_to_delete = list.Search(20);
    if (node_to_delete != list.nil) {
        list.Delete(node_to_delete);
    }

    std::cout << "Lista después de borrar 20:" << std::endl;
    current = list.nil->next;
    while (current != list.nil) {
        std::cout << current->key << " ";
        current = current->next;
    }
    std::cout << std::endl;

    return 0;
}
