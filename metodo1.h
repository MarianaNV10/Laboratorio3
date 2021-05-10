#ifndef METODO1_H
#define METODO1_H

#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

void lecturaPM(char *NomA, char *Bin, int Tm);

void codificacionPM(char *Bin, char *Codif, int Tm, int Sem);

void decodificacionPM(char *Codif, char *DesC, int Tm, int Sem);

void escribirPM(char *NomAr, char *Dats, int T);

void escribirDPM(char *NomAr, char *Dats, int T);

int tam(char *NomA);

void binarioPM(char c, char *b);

void decimal(char *deco, char *cad, int T);

void menuPM();

#endif // METODO1_H
