#ifndef METODO2_H
#define METODO2_H

#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <stdlib.h>

using namespace std;


string lecturaSM (string NomA, string Bin, int T); //Lectura del archivo y encontrar su representacion en binario

string binarioSM(char c);

int longitud(string NomA);

string codificarSM(string Bin, int T, int Sem, string Codi);

string descodificarSM(string Codi, int T, int sem, string Bin);

string decimalSM(string Desc, string Cadena, int T);

void escribirSM(string NomAC,string Datos);

void escribirDSM(string NomAD, string Datos);

void menuSM();

#endif // METODO2_H
