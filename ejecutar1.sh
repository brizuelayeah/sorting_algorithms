#!/bin/bash
# Script que compila y ejecuta la práctica 1
# Autores: Óscar Brizuela y Pilar Fierro
# Práctica 1 - Algoritmia para Problemas Difíciles

echo "Compilando y ejecutando la práctica 1, casos con numeros generados aleatoriamente..."
g++ -std=c++11 -o practica1Aleatorio main.cpp
./practica1Aleatorio

echo "Compilando y ejecutando la práctica 1, casos con numeros reales..."
g++ -std=c++11 -o practica1Reales main_reals.cpp
./practica1Reales