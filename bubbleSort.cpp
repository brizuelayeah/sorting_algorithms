/*****************************************************************************************
* Fichero:  bubbleSort.cpp
* Autores:  Óscar Brizuela y Pilar Fierro
* Práctica 1 de Algoritmia para Problemas Difíciles
*****************************************************************************************/
#include "includes.hpp"

/*
 *  Función que, dado un array de enteros "arr" y un entero "n", ordena de menor a mayor los elementos 
 *  de dicho array aplicando el algoritmo de ordenación bubbleSort
 */
void bubbleSort(int arr[], int n) {
    int i, j;                                   // Se declaran los índices "i" y "j"
    bool swapped;                               // Se declara la variable "swapped" de tipo booleano
    for (i = 0; i < n - 1; i++) {               // Se recorre el array desde el primer elemento hasta el penúltimo
        swapped = false;                        // Se inicializa la variable "swapped" a false
        for (j = 0; j < n - i - 1; j++) {       // Se recorre el array desde el primer elemento hasta el penúltimo
            if (arr[j] > arr[j + 1]) {          // Si el elemento actual es mayor que el siguiente
                swap(arr[j], arr[j + 1]);       // Se intercambian los elementos
                swapped = true;                 // Se actualiza la variable "swapped" a true
            }
        }
 
        if (swapped == false){                  // Si no se ha realizado ningún intercambio
            break;                              // Se sale del bucle
        }
    }
}

