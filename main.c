#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include "llist.h"

// Definir constantes
const int n = 1000000;
const int range = 2 * n;

void insert_random_keys_and_search() {
    llist<int> list;
    
    // Insertar 1,000,000 de nodos con llaves aleatorias en la lista
    for (int i = 0; i < n; ++i) {
        int key = std::rand() % range;
        llnode<int>* node = new llnode<int>(key);
        list.Insert(node);
    }

    // Realizar búsquedas durante un segundo y contar cuántas se pueden hacer
    int search_count = 0;
    auto start_time = std::chrono::steady_clock::now();
    auto end_time = start_time + std::chrono::seconds(1);

    while (std::chrono::steady_clock::now() < end_time) {
        int key_to_search = std::rand() % range;
        list.Search(key_to_search);
        ++search_count;
    }

    std::cout << "Número de búsquedas realizadas en un segundo (aleatorio): " << search_count << std::endl;
}

void insert_sequential_keys_and_search() {
    llist<int> list;
    
    // Insertar llaves 0, 1, ..., n-1 en la lista
    for (int i = 0; i < n; ++i) {
        llnode<int>* node = new llnode<int>(i);
        list.Insert(node);
    }

    // Realizar búsquedas durante un segundo y contar cuántas se pueden hacer
    int search_count = 0;
    auto start_time = std::chrono::steady_clock::now();
    auto end_time = start_time + std::chrono::seconds(1);

    while (std::chrono::steady_clock::now() < end_time) {
        int key_to_search = std::rand() % range;
        list.Search(key_to_search);
        ++search_count;
    }

    std::cout << "Número de búsquedas realizadas en un segundo (secuencial): " << search_count << std::endl;
}

int main() {
    // Inicializar el generador de números aleatorios
    std::srand(std::time(nullptr));
    
    // Ejecutar inserción y búsqueda con números aleatorios
    insert_random_keys_and_search();
    
    // Ejecutar inserción y búsqueda con números secuenciales
    insert_sequential_keys_and_search();
    return 0;
}
