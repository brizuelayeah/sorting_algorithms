/*****************************************************************************************
* Fichero:  utils.cpp
* Autores:  Óscar Brizuela y Pilar Fierro
* Práctica 1 de Algoritmia para Problemas Difíciles
*****************************************************************************************/
#include "includes.hpp"
#include "quickSort.cpp"
#include "radixSort.cpp"
#include "bubbleSort.cpp"

/*
 *  Función que muestra el mensaje inicial del programa
 */
void mensajeInicio(){
    cout << "----------------------------------------------------" << endl;
    cout << "|             Algoritmos de ordenacion             |" << endl;
    cout << "----------------------------------------------------" << endl;
    cout << "-> Se esta ejecutando el programa, espere porfavor, le va a costar unos segundos..." << endl;
    cout << "" << endl;
}


/*
 *  Función que dado un vector de ficheros de entrada y ficheros de salida 
 *  genera vectores con los nombres dichos ficheros
 */
void ficherosEntradaSalida(ifstream ficherosEntrada[], ofstream ficherosSalida[]){
    ficherosSalida[0].open("execution_time_quickSort_worst1.txt");
    ficherosEntrada[0].open("execution_time_quickSort_worst1.txt"); 
    
    ficherosSalida[1].open("execution_time_quickSort_worst2.txt");
    ficherosEntrada[1].open("execution_time_quickSort_worst2.txt");
    
    ficherosSalida[2].open("execution_time_quickSort_worst3.txt");
    ficherosEntrada[2].open("execution_time_quickSort_worst3.txt");
    
    ficherosSalida[3].open("execution_time_quickSort_newVersion1.txt");
    ficherosEntrada[3].open("execution_time_quickSort_newVersion1.txt");
    
    ficherosSalida[4].open("execution_time_quickSort_newVersion2.txt");
    ficherosEntrada[4].open("execution_time_quickSort_newVersion2.txt");
    
    ficherosSalida[5].open("execution_time_quickSort_newVersion3.txt");
    ficherosEntrada[5].open("execution_time_quickSort_newVersion3.txt");
    
    ficherosSalida[6].open("execution_time_quickSort_average.txt");
    ficherosEntrada[6].open("execution_time_quickSort_average.txt");
    
    ficherosSalida[7].open("execution_time_radixSort_worst.txt");
    ficherosEntrada[7].open("execution_time_radixSort_worst.txt");
    
    ficherosSalida[8].open("execution_time_radixSort_average.txt");
    ficherosEntrada[8].open("execution_time_radixSort_average.txt");
    
    ficherosSalida[9].open("execution_time_bubbleSort.txt");
    ficherosEntrada[9].open("execution_time_bubbleSort.txt");

}



/* 
 *  Función que dado un vector de enteros y un entero n, que genera un vector de n elementos
 */
void createRandomArrayWithOneLongElement(int arr[], int n) {

    int longElement = generateRandomNumber(9);  // Se genera un número aleatorio de 9 dígitos   
    int longElementIndex = rand() % n;          // Se genera un número aleatorio entre 0 y n-1, será la posición del elemento de 9 dígitos

    for (int i = 0; i < n; i++) {               // Se recorre el vector
        if (i == longElementIndex) {            // Si la posición coincide con la posición del elemento de 9 dígitos
            arr[i] = longElement;               // Se coloca el elemento de 9 dígitos
        } else {
            arr[i] = generateRandomNumber(2);   // Si no, se genera un número aleatorio de 2 dígitos y se coloca en esa posición
        }
    }
}

/*
 *  Función que imprime por pantalla el array
 */
void printArray(int arr[], int n){
    cout << "[";
    for (int i = 0; i < n; i++) {
        cout << arr[i];
        if(i==n-1){
            cout << "]";
        } else {
            cout << ", ";
        }
    }
    //cout << endl; 
}

/*
 *  Función que dado un array de enteros y su tamaño, lo rellena con números aleatorios
 */
void fillArrayWithRandomNumbers(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        int type = rand() % 3;                  // Se genera un número aleatorio entre 0, 1 y 2

        if (type == 0) {
            arr[i] = generateRandomNumber(2);   // Genera un número de 2 dígitos
        } else if (type == 1) {
            arr[i] = generateRandomNumber(3);   // Genera un número de 3 dígitos
        } else {
            arr[i] = generateRandomNumber(4);   // Genera un número de 4 dígitos
        }
    }
}

/*
 *  Función que dado un array de enteros, un entero start y otro end, reordena los elementos de dicho array
 *  de menor a mayor aplicando el algoritmo QuickSort y midiendo el tiempo de ejecución
 */
void quickSortOpcion(int arr[], int start, int end, int caso, int subcaso, ofstream ficherosSalida[]){
    int n = end + 1;
    double execution_time;
    if (start < end){
        if(caso == 1) {
            if(subcaso == 1) {  // Caso peor 1: se toma quicksort utilizando como pivote el elemento que está más a la izquierda
                                // con un vector ya ordenado con números aleatorios como entrada
                generateRandomIntArray(arr, n);
                quickSort(arr, start, end, 1);      
                auto start_time = std::chrono::high_resolution_clock::now();
                quickSort(arr, start, end, 1);
                auto end_time = std::chrono::high_resolution_clock::now();
                execution_time = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count() / 1000.0;
                ficherosSalida[0] << "Execution Time: " << std::fixed << std::setprecision(5) << execution_time << " milliseconds" << endl;
            }
            else if(subcaso == 2) { // Caso peor 2: se toma quicksort utilizando como pivote el elemento que está más a la derecha
                                    // con un vector ya ordenado de forma decreciente con números aleatorios como entrada
                generateRandomIntArray(arr, n);
                quickSortReverse(arr, start, end);
                auto start_time = std::chrono::high_resolution_clock::now();
                quickSort(arr, start, end, 2); 
                auto end_time = std::chrono::high_resolution_clock::now();
                execution_time = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count() / 1000.0;
                ficherosSalida[1] << "Execution Time: " << std::fixed << std::setprecision(5) << execution_time << " milliseconds" << endl;
                
            }
            else if(subcaso == 3) { // Caso peor 3: se toma quicksort utilizando como pivote el elemento que está más a la izquierda
                                    // con un vector cuyos elementos son todos iguales
                generateIntArrayWithSameElements(arr, n, 8);
                auto start_time = std::chrono::high_resolution_clock::now();
                quickSort(arr, start, end, 3);      
                auto end_time = std::chrono::high_resolution_clock::now();
                execution_time = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count() / 1000.0;
                ficherosSalida[2] << "Execution Time: " << std::fixed << std::setprecision(5) << execution_time << " milliseconds" << endl;
                
            }
            else {
                cout << "Caso peor no valido" << endl;
            }
        }
        else if(caso == 2) {
            generateRandomIntArray(arr, n);
            if(subcaso == 1) {
                auto start_time = std::chrono::high_resolution_clock::now();
                quickSort(arr, start, end, 3);
                auto end_time = std::chrono::high_resolution_clock::now();
                execution_time = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count() / 1000.0;
                ficherosSalida[3] << "Execution Time: " << std::fixed << std::setprecision(5) << execution_time << " milliseconds" << endl;
            }
            else if(subcaso == 2) {
                auto start_time = std::chrono::high_resolution_clock::now();
                quickSort(arr, start, end, 4);
                auto end_time = std::chrono::high_resolution_clock::now();
                execution_time = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count() / 1000.0;
                ficherosSalida[4] << "Execution Time: " << std::fixed << std::setprecision(5) << execution_time << " milliseconds" << endl;
            }
            else if(subcaso == 3) {
                auto start_time = std::chrono::high_resolution_clock::now();
                quickSort(arr, start, end, 5);
                auto end_time = std::chrono::high_resolution_clock::now();
                execution_time = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count() / 1000.0;
                ficherosSalida[5] << "Execution Time: " << std::fixed << std::setprecision(5) << execution_time << " milliseconds" << endl;
            }
        }

        else if(caso == 3) {
            // Caso normal: se toma quicksort utilizando como pivote el elemento que está más a la izquierda con un vector de números aleatorios como entrada
            generateRandomIntArray(arr, n);
            auto start_time = std::chrono::high_resolution_clock::now();
            quickSort(arr, start, end, 1);
            auto end_time = std::chrono::high_resolution_clock::now();
            execution_time = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count() / 1000.0;
            ficherosSalida[6] << "Execution Time: " << std::fixed << std::setprecision(5) << execution_time << " milliseconds" << endl;
        }
        else {
            cout << "Caso no valido" << endl;
        }
    }
}

/*
 *  Función que dado un array de enteros y un entero n, reordena los elementos de dicho array de menor a mayor
 *  aplicando el algoritmo RadixSort y midiendo el tiempo de ejecución
 */
void radixSortOpcion(int arr[], int n, int caso, ofstream ficherosSalida[]){
    double execution_time;
    if(caso == 1) {
        // Caso peor
        // se crea un array con elementos con el mismo número de dígitos excepto uno, que se coloca en una posición aleatoria
        createRandomArrayWithOneLongElement(arr, n);
        auto start_time = std::chrono::high_resolution_clock::now();
        radixsort(arr, n);
        auto end_time = std::chrono::high_resolution_clock::now();
        execution_time = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count() / 1000.0;
        ficherosSalida[7] << "Execution Time: " << std::fixed << std::setprecision(5) << execution_time << " milliseconds" << endl;

    }
    else if(caso == 2) {
        // Caso normal: 
        // Función apra crear un array con todos los números de 2, 3 o 4 cifras cada uno
        fillArrayWithRandomNumbers(arr, n);
        auto start_time = std::chrono::high_resolution_clock::now();
        radixsort(arr, n);
        auto end_time = std::chrono::high_resolution_clock::now();
        execution_time = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count() / 1000.0;
        ficherosSalida[8] << "Execution Time: " << std::fixed << std::setprecision(5) << execution_time << " milliseconds" << endl;
    }
    else {
        cout << "Caso no valido" << endl;
    }
}

/* 
 *  Función que dado un array de enteros y un entero n, reordena los elementos de dicho array de menor a mayor
 *  aplicando el algoritmo BubbleSort y midiendo el tiempo de ejecución
 */
void bubbleSortOption(int arr[], int n , ofstream ficherosSalida[]){
    double execution_time;
    auto start_time = std::chrono::high_resolution_clock::now();

    bubbleSort(arr, n);
    auto end_time = std::chrono::high_resolution_clock::now();
    execution_time = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count() / 1000.0;
    ficherosSalida[9] << "Execution Time: " << std::fixed << std::setprecision(5) << execution_time << " milliseconds" << endl;

   
}