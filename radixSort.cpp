/*****************************************************************************************
* Fichero:  radixSort.cpp
* Autores:  Óscar Brizuela y Pilar Fierro
* Práctica 1 de Algoritmia para Problemas Difíciles
*****************************************************************************************/
#include "includes.hpp"

/*
 *  Función que dado un entero n, devuelve un número con n dígitos
 */
int generateRandomNumber(int n) {
    int min = 1;                            // Valor mínimo que puede tomar el número
    for (int i = 1; i < n; i++) {           // Se calcula el valor mínimo que puede tomar el número
        min *= 10;
    }
    int max = min * 10 - 1;                 // Valor máximo que puede tomar el número
    return min + rand() % (max - min + 1);  // Se devuelve el número aleatorio
}

/*
 *  Función que, dado un vector de enteros "arr" y un entero "n", 
 *  devuelve el valor del elemento más grande de dicho vector.
 */
int getMax(int arr[], int n) {
    int mx = arr[0];                // Inicializa la variable "mx" con el primer elemento
    for (int i = 1; i < n; i++){    // Recorre el array desde el segundo elemento hasta el último
        if (arr[i] > mx){           // Si el elemento actual es mayor que el máximo
            mx = arr[i];            // Se actualiza el máximo
        }
    }
    return mx;                      // Devuelve el máximo
}

/* 
 * Función que, dado un vector de enteros "arr", un entero "n" y un entero "exp", ordena el array por conteo según el exponente
 */
void countSort(int arr[], int n, int exp) {
    int output[n];                      // Array de salida
    int i, count[10] = { 0 };           // Índice "i" y array de conteo "count[]"

    for (i = 0; i < n; i++){            // Almacena el número de ocurrencias en "count[]"
        count[(arr[i] / exp) % 10]++;
    }
    
    for (i = 1; i < 10; i++){           // Cambia "count[i]" para que contenga la posición real de este dígito en "output[]"
        count[i] += count[i - 1];
    }
    
    for (i = n - 1; i >= 0; i--) {      // Construye el array de salida
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for (i = 0; i < n; i++){            // Copia el array de salida a "arr[]", conteniendo así los números ordenados según el dígito actual
        arr[i] = output[i];
    }

}

/*
 * Función que, dado un vector de enteros "arr" y un entero "n",
 * ordena dicho vector utilizando el algoritmo radixSort
*/
void radixsort(int arr[], int n) {
    int m = getMax(arr, n);             // Encuentra el número máximo para conocer el número de dígitos

    // En vez de pasar el número de dígito, se pasa exp. exp es 10^i donde "i" es el número de dígito actual
    for (int exp = 1; m / exp > 0; exp *= 10){ // Para cada dígito, ordena el array usando Counting Sort
        countSort(arr, n, exp);
    }
}
