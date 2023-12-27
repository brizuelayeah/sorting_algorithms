/*****************************************************************************************
* Fichero:  main.cpp
* Autores:  Óscar Brizuela y Pilar Fierro
* Práctica 1 de Algoritmia para Problemas Difíciles
*****************************************************************************************/
#include "utils.cpp"
#include "includes.hpp"

/*
 * Función que dados dos enteros y un array de enteros, devuelve dicho array con 
 * los elementos ordenados de menor a mayor aplicando el algoritmo escogido
 */
void opcionAlgoritmo(int opcion, int arr[], int n, ofstream ficherosSalida[]){
    switch(opcion){
        case 1: 
            quickSortOpcion(arr, 0, n-1, 1, 1, ficherosSalida);
            //quickSortOpcion(arr, 0, n-1, 1, 2, ficherosSalida);          // --> DA ERRORES
            quickSortOpcion(arr, 0, n-1, 1, 3, ficherosSalida);
            quickSortOpcion(arr, 0, n-1, 2, 1, ficherosSalida);
            quickSortOpcion(arr, 0, n-1, 2, 2, ficherosSalida);
            quickSortOpcion(arr, 0, n-1, 2, 3, ficherosSalida);
            quickSortOpcion(arr, 0, n-1, 3, 1, ficherosSalida);
            break;
        case 2:
            radixSortOpcion(arr, n, 1, ficherosSalida);
            radixSortOpcion(arr, n, 2, ficherosSalida);
            break;
        case 3:
            bubbleSortOption(arr, n, ficherosSalida); // Iterativo
            break;
        default:    
            cout << "opcion no valida" << endl;
            break;
    }
}

/*
 *  Función que escribe en los ficheros con los resultados de las pruebas para cada algoritmo en cada posible caso
 */
void writeInFile(int opcion, int arr[], int n, ofstream ficherosSalida[], ifstream ficherosEntrada[]) {
    int log_num_elementos;
    log_num_elementos = (opcion != 2) ? 3 : 2; // Si la opción es 2, la variable es 2, si no, es 3

    for(int i = 0; i < log_num_elementos; i++) {    // Se realizan las iteraciones necesarias  
        for(int j = 0; j < 20; j++) {               // Iteraciones de los experimentos
            opcionAlgoritmo(opcion, arr, pow(10, i + 3), ficherosSalida);
        }
    }

}

/*
 *  Función que dados dos vectores, uno de ficheros de entrada "ficherosEntrada" y otro de ficheros de salida "ficherosSalida",
 *  lee la los tiempos de ejecución de los ficheros de entrada y escribe en el fichero de salida las medias correspondientes
 */
void ejecutar(ifstream ficherosEntrada[], ofstream ficherosSalida[]){
    for(int k = 0; k < 10; k++) {
        if(k != 1) {                       // Caso 2 peor quicksort
            string line;
            vector<double> execution_times;
            while (getline(ficherosEntrada[k], line)) {
                // Procesa cada línea del fichero
                string substring = line.substr(16, 5);
                execution_times.push_back(stod(substring));
            }
            

            double first20Average = 0.0;
            for (int i = 0; i < 20; i++) {
                first20Average += execution_times[i];
            }
            first20Average /= 20.0;
            // Calcula la media de los 20 siguientes tiempos de ejecución
            double next20Average = 0.0;
            for (int i = 20; i < 40; i++) {
                next20Average += execution_times[i];
            }
            next20Average /= 20.0;
            double secondNext20Average = 0.0;

            if(k != 7 && k != 8) {
                for (int i = 40; i < 60; i++) {
                    secondNext20Average += execution_times[i];
                }
                secondNext20Average /= 20.0;
            }
            
            ficherosSalida[k] << "Primera media: " << first20Average << endl;
            ficherosSalida[k] << "Segunda media: " << next20Average << endl;

            if(k != 7 && k != 8) {
                ficherosSalida[k] << "Tercera media: " << secondNext20Average << endl;
            }
        }
    }
}



/*
 *  Función que muestra el resultado de ordenación de un vector de enteros de cada algoritmo.
 */
void todosAlgoritmos(){
    
    cout << "----------------------------------------------------" << endl;
    cout << "          RESULTADOS ALGORITMOS ORDENACION          " << endl;
    cout << "----------------------------------------------------" << endl;
   
    int n = 100;
    int arr[n];

    generateRandomIntArray(arr, n);
    cout << "Vector de enteros aleatorios a ordenar: ";
    printArray(arr, n);

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

        quickSort(arr, 0, n-1, i);
        printArray(arr, n);
        cout << endl;
    }

    cout << endl;
    cout << " => RADIXSORT" << endl;
    cout << "----------------";
    cout << endl;
    cout << "       ";
    radixsort(arr, n);
    printArray(arr, n);
    cout << endl;
       

    cout << endl;
    cout << " => BUBBLESORT" << endl;
    cout << "-----------------" << endl;
    
    bubbleSort(arr, n);
    cout << "       ";
    printArray(arr, n);
    cout << endl;
    
    
}

/*
 *  Función principal
 */
int main(){

    mensajeInicio(); // Se muestra el mensaje inicial por pantalla
    ifstream ficherosEntrada[10];   // Se declara el vector de ficheros de entrada
    ofstream ficherosSalida[10];    // Se declara el vector de ficheros de salida
    ficherosEntradaSalida(ficherosEntrada, ficherosSalida);
    
    // Se declaran los arrays de strings y enteros que se van a utilizar para almacenar los datos de los ficheros de entrada
    string real_entries_string_array[54369] = {};
    int real_entries_integer_array[54369] = {};

    // Se declaran las variables necesarias
    int n = 1000;    // Tamaño del vector
    int n_inter = 20;   // Número de iteraciones
    int random_entries_array[n] = {}; // Vector de enteros que se va a utilizar para almacenar los números aleatorios
    int dni_entries_array[n] = {};    // Vector de enteros que se va a utilizar para almacenar los DNIs

    // Escribe en los fihceros con los resultados de las pruebas para cada algoritmo en cada posible caso
    writeInFile(1, random_entries_array, n, ficherosSalida, ficherosEntrada);
    writeInFile(2, random_entries_array, n, ficherosSalida, ficherosEntrada);
    writeInFile(3, random_entries_array, n, ficherosSalida, ficherosEntrada);
    
    ejecutar(ficherosEntrada, ficherosSalida);
    
    // Se cierran los ficheros de entrada y salida
    for(int i = 0; i < 10; i++) {
        ficherosEntrada[i].close();
        ficherosSalida[i].close();
    }

    // Se ejecuta lso algoritmos de ordenación para cada caso
    todosAlgoritmos();
    return 0;
}