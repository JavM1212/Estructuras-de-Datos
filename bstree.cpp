// main.cpp

#include "bstree.h"

int main() {
    bstree<int> tree;

    // Insertar elementos
    tree.Insert(new bstnode<int>(50));
    tree.Insert(new bstnode<int>(30));
    tree.Insert(new bstnode<int>(70));
    tree.Insert(new bstnode<int>(20));
    tree.Insert(new bstnode<int>(40));
    tree.Insert(new bstnode<int>(60));
    tree.Insert(new bstnode<int>(80));

    // Recorrido en orden (debe imprimir: 20 30 40 50 60 70 80)
    std::cout << "Recorrido en orden:" << std::endl;
    tree.InorderWalk(tree.root);

    // Búsqueda recursiva
    std::cout << "Búsqueda recursiva de 40: " << (tree.Search(tree.root, 40) != nullptr ? "Encontrado" : "No encontrado") << std::endl;
    std::cout << "Búsqueda recursiva de 25: " << (tree.Search(tree.root, 25) != nullptr ? "Encontrado" : "No encontrado") << std::endl;

    // Búsqueda iterativa
    std::cout << "Búsqueda iterativa de 60: " << (tree.IterativeSearch(tree.root, 60) != nullptr ? "Encontrado" : "No encontrado") << std::endl;
    std::cout << "Búsqueda iterativa de 75: " << (tree.IterativeSearch(tree.root, 75) != nullptr ? "Encontrado" : "No encontrado") << std::endl;

    // Mínimo y máximo
    std::cout << "Mínimo: " << tree.Minimum(tree.root)->key << std::endl;
    std::cout << "Máximo: " << tree.Maximum(tree.root)->key << std::endl;

    // Sucesor
    bstnode<int>* node = tree.Search(tree.root, 50);
    if (node) {
        bstnode<int>* succ = tree.Successor(node);
        if (succ) {
            std::cout << "Sucesor de 50: " << succ->key << std::endl;
        } else {
            std::cout << "50 no tiene sucesor" << std::endl;
        }
    }

    // Borrar nodos
    std::cout << "Borrando 20, 30, 50" << std::endl;
    tree.Delete(tree.Search(tree.root, 20));
    tree.Delete(tree.Search(tree.root, 30));
    tree.Delete(tree.Search(tree.root, 50));

    // Recorrido en orden después de borrado (debe imprimir: 40 60 70 80)
    std::cout << "Recorrido en orden después de borrado:" << std::endl;
    tree.InorderWalk(tree.root);

    return 0;
}
