/*****************************************************************************************
* Fichero:  main_reals.cpp
* Autores:  Óscar Brizuela y Pilar Fierro
* Práctica 1 de Algoritmia para Problemas Difíciles
*****************************************************************************************/
#include "quickSort.cpp"
#include "radixSort.cpp"
#include "bubbleSort.cpp"
#include "includes.hpp"

// Almacenamiento de IDs (DNIs ó NIEs) en vectores estáticos
string real_entries_string_array_100[100] = {};
string real_entries_string_array_1000[1000] = {};
string real_entries_string_array_10000[10000] = {};
int real_entries_integer_array_100[100] = {};
int real_entries_integer_array_1000[1000] = {};
int real_entries_integer_array_10000[10000] = {};

/*
 * Función que lee el fichero de entrada "dnis_a_txt.txt", en el cual cada línea corresponde a un
 * DNI ó NIE, y completa 3 vectores de enteros (de 100 componentes, de 1000 y de 10000)
 * con los primeros 100, 1000 ó 10000 DNIs ó NIEs del fichero.
 */
void extract_dnis() {
    ifstream dnis_a_txt;
    dnis_a_txt.open("dnis_a_txt.txt");
    string dni;
    if (dnis_a_txt.is_open()) {
        int j = 0;
        while(dnis_a_txt) {
            getline(dnis_a_txt, dni);
            if(j < 100) {
                real_entries_string_array_100[j] = dni;
            }
            if(j < 1000) {
                real_entries_string_array_1000[j] = dni;
            }
            if(j < 10000) {
                real_entries_string_array_10000[j] = dni;
            }
            j++;
        }
    }

    for(int k = 0; k < 100; k++) {
        real_entries_integer_array_100[k] = atoi(real_entries_string_array_100[k].c_str());
    }

    for(int k = 0; k < 1000; k++) {
        real_entries_integer_array_1000[k] = atoi(real_entries_string_array_1000[k].c_str());
    }
    for(int k = 0; k < 10000; k++) {
        real_entries_integer_array_10000[k] = atoi(real_entries_string_array_10000[k].c_str());
    }
}

/*  
 *  Función que, dado un entero "n", un vector de enteros "arr_original" y otro "arr_copy", 
 *  copia los elementos de "arr_original" en "arr_copy".
 */
void copyArray(int n, int arr_original[], int arr_copy[]){
    for(int i = 0; i < n; i++) {
        arr_copy[i] = arr_original[i];
    }
}

/*
 *  Función que dado un entero "caso", otro entero "subcaso" y un vector de ficheros de salida "ficherosSalida",
 *  ordena los vectores de enteros de 100, 1000 y 10000 componentes aplicando el algoritmo correspondiente de quickSort
 *  y escribe en los ficheros de salida los tiempos de ejecución de cada algoritmo.
 */
void quickSortOpcionReals(int caso, int subcaso, ofstream ficherosSalida[]){
    double execution_time;
    if(caso == 1) {
        if(subcaso == 1) { // Caso peor 1: se toma quicksort utilizando como pivote el elemento que está más a la izquierda
                           // con un vector ya ordenado con números aleatorios como entrada
            for(int j = 0; j < 20; j++) {    // En el array de 1000
                int copy_real_entries_integer_array_1000[1000];
                copyArray(1000, real_entries_integer_array_1000, copy_real_entries_integer_array_1000);
                quickSort(copy_real_entries_integer_array_1000, 0, 1000, 1);         // -> Se ordena por primera vez
                auto start_time = std::chrono::high_resolution_clock::now();
                quickSort(copy_real_entries_integer_array_1000, 0, 1000, 1);         // Una vez ordenado se vuelve a aplicar el algoritmo para medir el tiempo de ejecución del caso peor-
                auto end_time = std::chrono::high_resolution_clock::now();
                execution_time = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count() / 1000.0;
                ficherosSalida[0] << "Execution Time: " << std::fixed << std::setprecision(5) << execution_time << " milliseconds" << endl;
            }
            for(int j = 0; j < 20; j++) {   // En el array de 10000
                int copy_real_entries_integer_array_10000[10000];
                copyArray(10000, real_entries_integer_array_10000, copy_real_entries_integer_array_10000);
                quickSort(copy_real_entries_integer_array_10000, 0, 10000, 1);
                auto start_time = std::chrono::high_resolution_clock::now();
                quickSort(copy_real_entries_integer_array_10000, 0, 10000, 1);
                auto end_time = std::chrono::high_resolution_clock::now();
                execution_time = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count() / 1000.0;
                ficherosSalida[0] << "Execution Time: " << std::fixed << std::setprecision(5) << execution_time << " milliseconds" << endl;
            }   
        }
        else if(subcaso == 2) {     // NO FUNCIONA
                            // Caso peor 2: se toma quicksort utilizando como pivote el elemento que está más a la derecha
                            // con un vector ya ordenado de forma decreciente con números aleatorios como entrada
            for(int j = 0; j < 20; j++) {
                int copy_real_entries_integer_array_1000[1000];
                copyArray(1000, real_entries_integer_array_1000, copy_real_entries_integer_array_1000);
                quickSortReverse(copy_real_entries_integer_array_1000, 0, 1000);
                auto start_time = std::chrono::high_resolution_clock::now();
                quickSort(copy_real_entries_integer_array_1000, 0, 1000, 2); 
                auto end_time = std::chrono::high_resolution_clock::now();
                execution_time = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count() / 1000.0;
                ficherosSalida[1] << "Execution Time: " << std::fixed << std::setprecision(5) << execution_time << " milliseconds" << endl;
            }
            for(int j = 0; j < 20; j++) {
                int copy_real_entries_integer_array_10000[10000];
                copyArray(10000, real_entries_integer_array_10000, copy_real_entries_integer_array_10000);
                quickSortReverse(copy_real_entries_integer_array_10000, 0, 10000);
                auto start_time = std::chrono::high_resolution_clock::now();
                quickSort(copy_real_entries_integer_array_10000, 0, 10000, 2); 
                auto end_time = std::chrono::high_resolution_clock::now();
                execution_time = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count() / 1000.0;
                ficherosSalida[1] << "Execution Time: " << std::fixed << std::setprecision(5) << execution_time << " milliseconds" << endl;
            }
        }
        else {
            cout << "Caso peor no valido" << endl;
        }
    }

    else if(caso == 2) {
        if(subcaso == 1) { // Caso optimizado 1: se toma quicksort utilizando como pivote el elemento de en medio
                            // con un vector de números aleatorios como entrada
            for(int j = 0; j < 20; j++) {
                int copy_real_entries_integer_array_1000[1000];
                copyArray(1000, real_entries_integer_array_1000, copy_real_entries_integer_array_1000);
                auto start_time = std::chrono::high_resolution_clock::now();
                quickSort(copy_real_entries_integer_array_1000, 0, 1000, 3);
                auto end_time = std::chrono::high_resolution_clock::now();
                execution_time = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count() / 1000.0;
                ficherosSalida[2] << "Execution Time: " << std::fixed << std::setprecision(5) << execution_time << " milliseconds" << endl;
            }
            for(int j = 0; j < 20; j++) {
                int copy_real_entries_integer_array_10000[10000];
                copyArray(10000, real_entries_integer_array_10000, copy_real_entries_integer_array_10000);
                auto start_time = std::chrono::high_resolution_clock::now();
                quickSort(copy_real_entries_integer_array_10000, 0, 10000, 3);
                auto end_time = std::chrono::high_resolution_clock::now();
                execution_time = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count() / 1000.0;
                ficherosSalida[2] << "Execution Time: " << std::fixed << std::setprecision(5) << execution_time << " milliseconds" << endl;
            }
        }
        else if(subcaso == 2) { // Caso optimizado 2: se toma quicksort utilizando como pivote el elemento mediano
                                // entre el de la izquierda, el de la derecha y el de en medio // con un vector de números aleatorios como entrada
            for(int j = 0; j < 20; j++) {
                int copy_real_entries_integer_array_1000[1000];
                copyArray(1000, real_entries_integer_array_1000, copy_real_entries_integer_array_1000);
                auto start_time = std::chrono::high_resolution_clock::now();
                quickSort(copy_real_entries_integer_array_1000, 0, 1000, 4);
                auto end_time = std::chrono::high_resolution_clock::now();
                execution_time = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count() / 1000.0;
                ficherosSalida[3] << "Execution Time: " << std::fixed << std::setprecision(5) << execution_time << " milliseconds" << endl;
            }
            for(int j = 0; j < 20; j++) {
                int copy_real_entries_integer_array_10000[10000];
                copyArray(10000, real_entries_integer_array_10000, copy_real_entries_integer_array_10000);
                auto start_time = std::chrono::high_resolution_clock::now();
                quickSort(copy_real_entries_integer_array_10000, 0, 10000, 4);
                auto end_time = std::chrono::high_resolution_clock::now();
                execution_time = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count() / 1000.0;
                ficherosSalida[3] << "Execution Time: " << std::fixed << std::setprecision(5) << execution_time << " milliseconds" << endl;
            }
        }
        else if(subcaso == 3) { // Caso optimizado 3: se toma quicksort utilizando como pivote un elemento aleatorio
                                // con un vector de números aleatorios como entrada
            for(int j = 0; j < 20; j++) {
                int copy_real_entries_integer_array_1000[1000];
                copyArray(1000, real_entries_integer_array_1000, copy_real_entries_integer_array_1000);
                auto start_time = std::chrono::high_resolution_clock::now();
                quickSort(copy_real_entries_integer_array_1000, 0, 1000, 5);
                auto end_time = std::chrono::high_resolution_clock::now();
                execution_time = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count() / 1000.0;
                ficherosSalida[4] << "Execution Time: " << std::fixed << std::setprecision(5) << execution_time << " milliseconds" << endl;
            }
            for(int j = 0; j < 20; j++) {
                int copy_real_entries_integer_array_10000[10000];
                copyArray(10000, real_entries_integer_array_10000, copy_real_entries_integer_array_10000);
                auto start_time = std::chrono::high_resolution_clock::now();
                quickSort(copy_real_entries_integer_array_10000, 0, 10000, 5);
                auto end_time = std::chrono::high_resolution_clock::now();
                execution_time = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count() / 1000.0;
                ficherosSalida[4] << "Execution Time: " << std::fixed << std::setprecision(5) << execution_time << " milliseconds" << endl;
            }
        }
    }

    else if(caso == 3) { // Caso normal: se toma quicksort utilizando como pivote el elemento que está más a la izquierda con un vector de números aleatorios como entrada
        for(int j = 0; j < 20; j++) {
                int copy_real_entries_integer_array_1000[1000];
                copyArray(1000, real_entries_integer_array_1000, copy_real_entries_integer_array_1000);
                auto start_time = std::chrono::high_resolution_clock::now();
                quickSort(copy_real_entries_integer_array_1000, 0, 1000, 1);
                auto end_time = std::chrono::high_resolution_clock::now();
                execution_time = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count() / 1000.0;
                ficherosSalida[5] << "Execution Time: " << std::fixed << std::setprecision(5) << execution_time << " milliseconds" << endl;
            }
        for(int j = 0; j < 20; j++) {
            int copy_real_entries_integer_array_10000[10000];
            copyArray(10000, real_entries_integer_array_10000, copy_real_entries_integer_array_10000);
            auto start_time = std::chrono::high_resolution_clock::now();
            quickSort(copy_real_entries_integer_array_10000, 0, 10000, 1);
            auto end_time = std::chrono::high_resolution_clock::now();
            execution_time = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count() / 1000.0;
            ficherosSalida[5] << "Execution Time: " << std::fixed << std::setprecision(5) << execution_time << " milliseconds" << endl;
        }
    }
    else {
        cout << "Caso no valido" << endl;
    }
}


/*
 *  Función que dado un vector de ficheros de salida "ficherosSalida",
 *  ordena los vectores de enteros de 100, 1000 y 10000 componentes aplicando el algoritmo radixSort
 *  y escribe en los ficheros de salida los tiempos de ejecución de cada algoritmo.
 */
void radixSortOpcionReals(ofstream ficherosSalida[]){
    double execution_time;
    for(int j = 0; j < 20; j++) {
        auto start_time = std::chrono::high_resolution_clock::now();
        radixsort(real_entries_integer_array_1000, 1000);
        auto end_time = std::chrono::high_resolution_clock::now();
        execution_time = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count() / 1000.0;
        ficherosSalida[6] << "Execution Time: " << std::fixed << std::setprecision(5) << execution_time << " milliseconds" << endl;
    }
    for(int j = 0; j < 20; j++) {
        auto start_time = std::chrono::high_resolution_clock::now();
        radixsort(real_entries_integer_array_10000, 10000);
        auto end_time = std::chrono::high_resolution_clock::now();
        execution_time = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count() / 1000.0;
        ficherosSalida[6] << "Execution Time: " << std::fixed << std::setprecision(5) << execution_time << " milliseconds" << endl;
    }
}
 
/*
 *  Función que, dado un vector de ficheros de salida "ficherosSalida",
 *  ordena los vectores de enteros de 100, 1000 y 10000 componentes aplicando el algoritmo bubbleSort
 *  y escribe en los ficheros de salida los tiempos de ejecución de cada algoritmo.
 */
void bubbleSortOptionReals(ofstream ficherosSalida[]){
    double execution_time;
    for(int j = 0; j < 20; j++) {
        auto start_time = std::chrono::high_resolution_clock::now();
        bubbleSort(real_entries_integer_array_1000, 1000);
        auto end_time = std::chrono::high_resolution_clock::now();
        execution_time = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count() / 1000.0;
        ficherosSalida[7] << "Execution Time: " << std::fixed << std::setprecision(5) << execution_time << " milliseconds" << endl;
    }
    for(int j = 0; j < 20; j++) {
        auto start_time = std::chrono::high_resolution_clock::now();
        bubbleSort(real_entries_integer_array_10000, 10000);
        auto end_time = std::chrono::high_resolution_clock::now();
        execution_time = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count() / 1000.0;
        ficherosSalida[7] << "Execution Time: " << std::fixed << std::setprecision(5) << execution_time << " milliseconds" << endl;
    }
}

/*
 *  Función que, dados un entero "opcion" y un vector de ficheros de salida "ficherosSalida",
 *  ordena los arrays de 100, 1000 y 10000 componentes con los elementos ordenados de menor a mayor 
 *  aplicando el algoritmo escogido
 */
void opcionAlgoritmoReals(int opcion, ofstream ficherosSalida[]){
    if(opcion == 1) {
        quickSortOpcionReals(1, 1, ficherosSalida);
        //quickSortOpcionReals(1, 2, ficherosSalida);          // --> DA ERRORES
        quickSortOpcionReals(2, 1, ficherosSalida);
        quickSortOpcionReals(2, 2, ficherosSalida);
        quickSortOpcionReals(2, 3, ficherosSalida);
        quickSortOpcionReals(3, 1, ficherosSalida);
    }
    else if(opcion == 2) {
        radixSortOpcionReals(ficherosSalida);
    }
    else if(opcion == 3) {
        bubbleSortOptionReals(ficherosSalida);
    }
    else {
        cout << "opcion no valida" << endl;
    }
}

/*
 *  Función que imprime por pantalla el array de reales "arr" de tamaño "n".
 */
void printArrayReales(int arr[], int n){
    cout << "[";
    for (int i = 0; i < n; i++) {
        cout << arr[i];
        if(i == n - 1){
            cout << "]";
        } else {
            cout << ", ";
        }
    }
}

/* 
 *  Función que dados dos vectores, uno de ficheros de entrada "ficherosEntrada" y otro de ficheros de salida "ficherosSalida",
 *  abre los ficheros de entrada y salida correspondientes a cada algoritmo.
 */
void ficherosEntradaSalidaReales(ifstream ficherosEntrada[], ofstream ficherosSalida[]){ 
    ficherosSalida[0].open("execution_time_quickSort_worst1_real.txt");
    ficherosEntrada[0].open("execution_time_quickSort_worst1_real.txt");
    
    ficherosSalida[1].open("execution_time_quickSort_worst2_real.txt");
    ficherosEntrada[1].open("execution_time_quickSort_worst2_real.txt");
    
    ficherosSalida[2].open("execution_time_quickSort_newVersion1_real.txt");
    ficherosEntrada[2].open("execution_time_quickSort_newVersion1_real.txt");
    
    ficherosSalida[3].open("execution_time_quickSort_newVersion2_real.txt");
    ficherosEntrada[3].open("execution_time_quickSort_newVersion2_real.txt");
    
    ficherosSalida[4].open("execution_time_quickSort_newVersion3_real.txt");
    ficherosEntrada[4].open("execution_time_quickSort_newVersion3_real.txt");
    
    ficherosSalida[5].open("execution_time_quickSort_average_real.txt");
    ficherosEntrada[5].open("execution_time_quickSort_average_real.txt");
    
    ficherosSalida[6].open("execution_time_radixSort_average_real.txt");
    ficherosEntrada[6].open("execution_time_radixSort_average_real.txt");
    
    ficherosSalida[7].open("execution_time_bubbleSort_average_real.txt");
    ficherosEntrada[7].open("execution_time_bubbleSort_average_real.txt");
}


/*
 *  Función que muestra el resultado de ordenación de un vector de enteros de cada algoritmo.
 */
void todosAlgoritmos(){
    
    cout << "----------------------------------------------------" << endl;
    cout << "          RESULTADOS ALGORITMOS ORDENACION          " << endl;
    cout << "----------------------------------------------------" << endl;
   
    int n = 100;

    cout << "Vector de enteros aleatorios a ordenar: ";
    printArrayReales(real_entries_integer_array_100, n);

    cout << endl;
    cout << " => QUICKSORT" << endl;
    cout << "-----------------" << endl;

    string mensaje[] = {
        "partition left most",
        "partition right most",
        "middle pivot",
        "median pivot",
        "random pivot"
    };
    
    for(int i = 1; i < 6; i++){
        cout << "   --> " << mensaje[i-1] << ": ";

        quickSort(real_entries_integer_array_100, 0, 100, i);
        printArrayReales(real_entries_integer_array_100, 100);
        cout << endl;
    }

    cout << endl;
    cout << " => RADIXSORT" << endl;
    cout << "----------------";
    cout << endl;
    cout << "       ";

    radixsort(real_entries_integer_array_100, 100);
    printArrayReales(real_entries_integer_array_100, 100);
    cout << endl;
       

    cout << endl;
    cout << " => BUBBLESORT" << endl;
    cout << "-----------------" << endl;
    cout << "   --> implementacion" << endl;
    
    bubbleSort(real_entries_integer_array_100, 100);
    cout << "       ";
    printArrayReales(real_entries_integer_array_100, 100);
    cout << endl;
    
}

/*
 * Función que, dados un vector de ficheros de entrada "ficherosEntrada" y un vector de ficheros de 
 * salida "ficherosSalida", lee los tiempos del fichero correspondiente de "ficherosEntrada" y escribe 
 * en ese mismo fichero las medias de los experimentos con 1000 y 10000 elementos.
 */
void ejecutarReales(ifstream ficherosEntrada[], ofstream ficherosSalida[]){
    for(int k = 0; k < 8; k++) {
        if(k != 1) {                // Worst case 2 quicksort
            string line;
            vector<double> execution_times;
            while (getline(ficherosEntrada[k], line)) {
                string substring = line.substr(16, 5);
                execution_times.push_back(stod(substring));
            }
            
            double first20Average = 0.0;
            for (int i = 0; i < 20; i++) {
                first20Average += execution_times[i];
            }
            first20Average /= 20.0;

            double next20Average = 0.0;
            for (int i = 20; i < 40; i++) {
                next20Average += execution_times[i];
            }
            next20Average /= 20.0;
            double secondNext20Average = 0.0;
            
            ficherosSalida[k] << "Primera media: " << first20Average << endl;
            ficherosSalida[k] << "Segunda media: " << next20Average << endl;

        }
    }
}

/*
 *  Función principal
 */
int main(){
    // Se muestran por pantalla la información para que el usuario escoja que algoritmo quiere aplicar
    // Handle real entries
    cout << "----------------------------------------------------" << endl;
    cout << "|             Algoritmos de ordenacion             |" << endl;
    cout << "----------------------------------------------------" << endl;
    cout << "-> Se esta ejecutando el programa, espere porfavor, le va a costar unos segundos..." << endl;
    cout << "" << endl;
    
    ifstream ficherosEntradaReales[8];
    ofstream ficherosSalidaReales[8];

    ficherosEntradaSalidaReales(ficherosEntradaReales, ficherosSalidaReales);

    extract_dnis();

    opcionAlgoritmoReals(1, ficherosSalidaReales);
    opcionAlgoritmoReals(2, ficherosSalidaReales);
    opcionAlgoritmoReals(3, ficherosSalidaReales);

    ejecutarReales(ficherosEntradaReales, ficherosSalidaReales);
    
    todosAlgoritmos();
    return 0;
}