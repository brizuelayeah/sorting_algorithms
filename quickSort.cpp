/*****************************************************************************************
* Fichero:  quickSort.cpp
* Autores:  Óscar Brizuela y Pilar Fierro
* Práctica 1 de Algoritmia para Problemas Difíciles
*****************************************************************************************/
#include "includes.hpp"

/*
 *  Función que, dado un vector de enteros "array" y un entero "n", rellena dicho array de "n" componentes aleatorias
 */
void generateRandomIntArray(int array[], int n) {
    srand(time(NULL));              // Genera una semilla aleatoria
    for (int i = 0; i < n; i++) {   // Recorre el array
        array[i] = rand() % 101;    // Genera un número aleatorio entre 0 y 100
    }
} 

/*
 *  Función que, dado un vector de enteros "array", un entero "n" y un entero "element", 
 *  rellena el vector con el entero "element"
 */
void generateIntArrayWithSameElements(int array[], int n, int element) {
    for (int i = 0; i < n; i++) {   // Recorre el array
        array[i] = element;         // Completa todos los componentes con el entero "element"
    }
}

/*
 *  Función que, dado un vector de enteros "arr", un entero "start" y un entero "end", devuelve el elemento mediano 
 *  entre el primer, último y elemento del medio de dicho vector.
 */
int findMedian(int arr[], int start, int end) {
    int middle = start + (end - start) / 2;                 // Calcula el valor del índice del medio emntre "start" y "end"
    int elements[3] = {arr[start], arr[middle], arr[end]};  // Crea un array para almacenar los elementos más a la izquierda, el del medio y el más a la derecha

    if (elements[0] > elements[1]) {        // Si el elemento más a la izquierda es mayor que el del medio
        swap(elements[0], elements[1]);     // Se intercambian
    }
    if (elements[1] > elements[2]) {        // Si el elemento del medio es mayor que el de la derecha
        swap(elements[1], elements[2]);     // Se intercambian
    }
    if (elements[0] > elements[1]) {        // Si el elemento más a la izquierda es mayor que el del medio
        swap(elements[0], elements[1]);     // Se intercambian
    }

    return elements[1];                     // Devuelve el mediano
}

/* 
 *  Función que, dado un vector de enteros "arr" y los enteros "start", "end" y "pivot", reordena el vector 
 *  de manera que los elementos que sean menores que el pivote se sitúan a su izquierda y los
 *  mayores a su derecha, devolviendo el índice del elemento más pequeño en la parte derecha de dicho vector.
 */
int particion(int arr[], int start, int end, int pivot) {
    int i = start, j = end;         // Se declaran los índices "i" y "j"
    while (i <= j) {                // Mientras que "i" sea menor o igual que "j"
        while (arr[i] < pivot) {    // Mientras que el elemento de la izquierda sea menor que el pivote
            i++;                    // Se incrementa el índice "i"
        }

        while (arr[j] > pivot) {    // Mientras que el elemento de la derecha sea mayor que el pivote
            j--;                    // Se decrementa el índice "j"
        }

        if (i <= j) {               // Si i es menor o igual que "j"
            swap(arr[i], arr[j]);   // Se intercambian los elementos de "i" y "j"
            i++;                    // Se incrementa i
            j--;                    // Se decrementa "j"
        }
    }
    return i;                       // Se devuelve el índice "i"

}

/*
 *  Función que, dado un vector de enteros "arr", un entero "start" y un entero "end" reorganiza los elementos de 
 *  dicho vector comprendidos entre la posición "start" y "end" de manera que los elementos que sean menores que 
 *  el pivote se situan a su izquierda y los mayores a su derecha, devolviendo el índice del elemento más pequeño 
 *  en la parte derecha de dicho vector.
 */
int partition_random(int arr[], int start, int end)
{
    int pivot = arr[end];                   // Se obtiene el pivote como el último elemento del array
    int i = (start - 1);                    // Se declara el índice del elemento más pequeño
 
    for (int j = start; j <= end - 1; j++){ // Se recorre el array de izquierda a derecha
        if (arr[j] <= pivot) {              // Si el elemento actual es menor o igual que el pivote
            i++;                            // Se incrementa el índice del elemento más pequeño
            swap(arr[i], arr[j]);           // Se intercambian los elementos
        }
    }
    swap(arr[i + 1], arr[end]);             // Se intercambia el pivote con el elemento más pequeño
    return (i + 1);                         // Se devuelve el índice del elemento más pequeño
}
 
/*
 *  Función que, dado un vector de enteros "arr", un entero "start" y un entero "end", realiza la partición de dicho 
 *  vector utilizando como pivote un elemento aleatorio del vector entre las posiciones "start" y "end", devolviendo
 *  el índice del pivote.
 */
int partition_r(int arr[], int start, int end)
{
    srand(time(NULL));                              // Genera una semilla aleatoria                      
    int random = start + rand() % (end - start);    // Genera un número aleatorio entre start y end
    swap(arr[random], arr[end]);                    // Intercambia el elemento en posición aleatoria con el último elemento del array
 
    return partition_random(arr, start, end);       // Devuelve el índice del pivote
}

/*
 *  Función que, dado un vector de enteros "arr", un entero "start" y un entero "end", realiza la partición del vector tomando 
 *  como pivote el elemento en la posición "start". Por tanto, el vector queda dividido en un subvector formado por los elementos
 *  que están a la izquierda del pivote y otro subvector formado por todos los elementos que estén a la derecha del pivote,
 *  devolviendo el índice del pivote tras realizar la partición.
*/
int partitionLeftMost(int arr[], int start, int end) {
 
    int pivot = arr[start];             // Primer elemento como pivote
    int k = end;                        // Se guarda en una variable el último elemento del array
    for (int i = end; i > start; i--) { // Se recorre el array de derecha a izquierda
        if (arr[i] > pivot){            // Si el elemento es mayor que el pivote
            swap(arr[i], arr[k--]);     // Se intercambia el elemento con el último elemento del array
        }
    }
    swap(arr[start], arr[k]);           // Se intercambia el pivote con el último elemento del array
    return k;                           // Se devuelve el índice del pivote
}

/*
 *  Función que, dado un vector de enteros "arr", un entero "start" y un entero "end", realiza la partición del vector tomando como 
 *  pivote el elemento en la posición "end". Por tanto, el vector queda dividido en un subvector formado por 
 *  los elementos que están a la izquierda del pivote y otro subvector formado por todos los elementos que estén a la derecha del pivote,
 *  devolviendo el índice del pivote después de realizar la partición.
*/
int partitionRightMost(int arr[], int start, int end) {
    int pivot = arr[end];               // Se obtiene el pivote como el último elemento del array
    int i = (start - 1);                // Se obtiene el índice del elemento más pequeño

    for (int j = start; j <= end - 1; j++) { // Se recorre el array de izquierda a derecha
        if (arr[j] <= pivot) {          // Si el elemento es menor o igual que el pivote
            i++;                        // Se incrementa el índice del elemento más pequeño
            swap(arr[i], arr[j]);       // Se intercambia el elemento más pequeño con el elemento actual
        }
    }
    swap(arr[i + 1], arr[end]);         // Se intercambia el pivote con el elemento más pequeño
    return (i + 1);                     // Se devuelve el índice del elemento más pequeño
}

/*
 *  Función que, dado un vector de enteros "arr", un entero "start" y un entero "end", realiza la partición del vector tomando como 
 *  pivote el elemento en la posición del medio entre "start" y "end". Por tanto, el vector queda dividido en un subvector formado por 
 *  los elementos que están a la izquierda del pivote y otro subvector formado por todos los elementos que estén a la derecha del pivote,
 *  devolviendo el índice del pivote después de realizar la partición.
*/
int partitionMiddlePivot(int arr[], int start, int end) {
    int middle = start + (end - start) / 2;     // Se obtiene el índice del elemento que está en el medio
    int pivot = arr[middle];                    // Se obtiene el pivote como el elemento del medio
    return particion(arr, start, end, pivot);   // Se devuelve el índice del pivote

}

/*
 *  Función que, dado un vector de enteros "arr", un entero "start" y un entero "end", realiza la partición del vector tomando como 
 *  pivote el elemento mediano entre el elemento más a la izquierda, el más a la derecha y el que se sitúa en el medio. Por tanto, 
 *  el vector queda dividido en un subvector formado por los elementos que están a la izquierda del pivote y otro subvector formado 
 *  por todos los elementos que estén a la derecha del pivote, devolviendo el índice de donde se encuentra el pivote tras la partición
*/
int partitionMedianPivot(int arr[], int start, int end) {

    int leftmost = arr[start];              // Se obtiene el elemento más a la izquierda
    int rightmost = arr[end];               // Se obtiene el elemento más a la derecha
    int middle = start + (end - start) / 2; // Se obtiene el elemento que está en el medio
    int middleElement = arr[middle];        // Se obtiene el elemento que está en el medio
    int pivot, i = start, j = end;          // Se declara el pivote, el índice i y el índice j
    
    pivot = findMedian(arr, start, end);    // Se obtiene el pivote como el elemento mediano entre el elemento más a la izquierda, el más a la derecha y el que se sitúa en el medio
    return particion(arr, start, end, pivot);   // Se devuelve el índice del pivote
}

/*
 *  Función que dado un  vector de enteros "arr", un entero "start" y un entero "end", realiza la partición en el vector 
 *  de manera que los elementos que sean mayores que el pivote se sitúan a su izquierda y los menores a su derecha, devolviendo
 *  el índice del pivote después de la partición
*/
int partitionForReversed(int arr[], int start, int end) {
    int pivot = arr[end];                       // Se obtiene como pivote el último elemento del array
    int i = (start - 1);                        // Se obtiene el índice del elemento más pequeño

    for (int j = start; j <= end - 1; j++) {
        if (arr[j] >= pivot) {                  // Si el elemento es mayor o igual que el pivote
            i++;                                // Se incrementa el índice del elemento más pequeño
            swap(arr[i], arr[j]);               // Se intercambia el elemento más pequeño con el elemento actual
        }
    }
    swap(arr[i + 1], arr[end]);                 // Se intercambia el pivote con el elemento más pequeño
    return (i + 1);                             // Se devuelve el índice del elemento más pequeño
}

/*
 *  Función que dado un vector de enteros "arr", un entero "start", un entero "end" y un entero "opcion", 
 *  implementa el algoritmo de QuickSort para ordenar los elementos del vector comprendidos entre "start" y "end"
 *  empleando el algoritmo de partición correspondiente a la opción indicada en el parámetro "opcion"
 */
void quickSort(int arr[], int start, int end, int opcion) {
    if (start < end){
        int pivotIndex;
        if(opcion == 1){                                 // Opción 1 -> Pivote: elemento en la posición más a la izquierda
            pivotIndex = partitionLeftMost(arr, start, end);
            quickSort(arr, start, pivotIndex - 1, opcion);
            quickSort(arr, pivotIndex + 1, end, opcion);

        }else if(opcion == 2){                           // Opción 2 -> Pivote: elemento en la posición más a la derecha
            pivotIndex = partitionRightMost(arr, start, end);
            quickSort(arr, start, pivotIndex - 1, opcion);
            quickSort(arr, pivotIndex + 1, end, opcion);

        }else if(opcion == 3){                           // Opción 3 -> Pivote: elemento en la posición del medio
            pivotIndex = partitionMiddlePivot(arr, start, end);
            quickSort(arr, start, pivotIndex - 1, opcion);
            quickSort(arr, pivotIndex, end, opcion);

        }else if(opcion == 4){                          // Opción 4 -> Pivote: elemento en la posición del elemento mediano
            pivotIndex = partitionMedianPivot(arr, start, end);
            quickSort(arr, start, pivotIndex - 1, opcion);
            quickSort(arr, pivotIndex, end, opcion);

        }else if(opcion == 5){                          // Opción 5 -> Pivote: elemento en una posición aleatoria
            pivotIndex = partition_r(arr, start, end);
            quickSort(arr, start, pivotIndex - 1, opcion);
            quickSort(arr, pivotIndex + 1, end, opcion);
        }else{
            cout << "Opcion no valida" << endl;
        }
    }
}

/*
 *  Función que, dado un vector de enteros "arr", un entero "start" y un entero "end", implementa el algotitmo de QuickSort
 *  inverso, es decir, ordena los elementos del vector comprendidos entre "start" y "end" en orden descendente (de mayor a menor)
*/
void quickSortReverse(int arr[], int start, int end) {
    if (start < end) {
        int pivotIndex = partitionForReversed(arr, start, end); // Se obtiene el índice del pivote
        quickSortReverse(arr, start, pivotIndex - 1);   // Se ordena la parte izquierda del pivote entre la posición start y pivotIndex - 1
        quickSortReverse(arr, pivotIndex + 1, end);     // Se ordena la parte derecha del pivote entre la posición pivotIndex + 1 y end
    }
}
