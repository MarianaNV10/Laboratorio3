#include <metodo1.h>

void escribirPM(char *NomAr, char *Dats,int T){ //Esta función es para escribir binarios en el archivo .dat

    ofstream Archivo;

    Archivo.open(NomAr, ios::binary);
    cout << "\nEscribiendo la informacion en el archivo......." << endl;
    Archivo.write(Dats,T*8); //El write sirve cuando se trabaja con binarios puesto que le puede entregar hasta donde quiero que copia siendo esto la longitud de la cadena
    Archivo.close();
}

void decodificacionPM(char *Codif, char *DesC, int Tm, int Sem){

    cout << "\nDecodificando la informacion....." << endl;

    int j=0, cero=0, uno=0, aux=0, cnt;

    for (int h=1; h<=(Tm*8)/Sem;h++){  // Hace la primera parte de la codificacio que es invertir los numeros del primer grupo de tamaño=sem
        for(;j<Sem*h && Codif[j]!=-1; j++){
            if(j<Sem){
                if(Codif[j]=='0'){
                    DesC[j]='1';
                }
                else if (Codif[j]=='1'){
                    DesC[j]='0';
                }
            }
            else{

                DesC[j]=Codif[j];
            }
        }
    }

    j=0;

    for(int k=1; k<(Tm*8)/Sem; k++){ // La condición son los paquetes de cantidad Sem que hay

        for(; j<Sem*k; j++){  //Cantidad de ceros y unos que hay en el paquete anterior al que se le aplicara la codificacion
            if(DesC[j]=='0'){
                cero++;
            }
            else if(DesC[j]=='1'){
                uno++;
            }
        }
        aux=j;
        if(cero==uno){ //Primera regla
            for(; aux<Sem*(k+1); aux++){
                if(DesC[aux]=='0'){
                    DesC[aux]='1';
                }
                else if (Codif[aux]=='1'){
                    DesC[aux]='0';
                }
            }
        }
        else if(cero>uno){ //Segunda regla
            cnt=1;
            for(; aux<Sem*(k+1); aux++){
                if(cnt%2==0){
                    if(DesC[aux]=='0'){
                        DesC[aux]='1';
                    }
                    else if (Codif[aux]=='1'){
                        DesC[aux]='0';
                    }
                }
                cnt++;
            }
        }
        else{ //Terca regla
            cnt=1;
            for(; aux<Sem*(k+1); aux++){
                if(cnt%3==0){
                    if(DesC[aux]=='0'){
                        DesC[aux]='1';
                    }
                    else if (Codif[aux]=='1'){
                        DesC[aux]='0';
                    }
                }
                cnt++;
            }
        }
        cero=0;
        uno=0;

    }
}



void codificacionPM(char *Bin, char *Codif, int Tm, int Sem){

    cout << "\nCodificando la informacion......" << endl;

    int j=0, cero=0, uno=0, aux=0, cnt;

    for (int h=1; h<=(Tm*8)/Sem;h++){  // Hace la primera parte de la codificacio que es invertir los numeros del primer grupo de tamaño=sem
        for(;j<Sem*h && Bin[j]!=-1; j++){

            if(j<Sem){
                if(Bin[j]=='0'){
                    Codif[j]='1';
                }
                else if (Bin[j]=='1'){
                    Codif[j]='0';
                }
            }
            else{

                Codif[j]=Bin[j];
            }
        }
    }


    j=0;

    for(int k=1; k<(Tm*8)/Sem; k++){ // La condición son los paquetes de cantidad Sem que hay

        for(; j<Sem*k; j++){  //Cantidad de ceros y unos que hay en el paquete anterior al que se le aplicara la codificacion
            if(Bin[j]=='0'){
                cero++;
            }
            else if(Bin[j]=='1'){
                uno++;
            }
        }
        aux=j;
        if(cero==uno){ //Primera regla
            for(; aux<Sem*(k+1); aux++){
                if(Codif[aux]=='0'){
                    Codif[aux]='1';
                }
                else if (Codif[aux]=='1'){
                    Codif[aux]='0';
                }
            }
        }
        else if(cero>uno){ //Segunda regla
            cnt=1;
            for(; aux<Sem*(k+1); aux++){
                if(cnt%2==0){
                    if(Codif[aux]=='0'){
                        Codif[aux]='1';
                    }
                    else if (Codif[aux]=='1'){
                        Codif[aux]='0';
                    }
                }
                cnt++;
            }
        }
        else{ //Terca regla
            cnt=1;
            for(; aux<Sem*(k+1); aux++){
                if(cnt%3==0){
                    if(Codif[aux]=='0'){
                        Codif[aux]='1';
                    }
                    else if (Codif[aux]=='1'){
                        Codif[aux]='0';
                    }
                }
                cnt++;
            }
        }
        cero=0;
        uno=0;

    }
}

void lecturaPM(char *NomA, char *Bin, int Tm){
    char carat;
    char bina[8];

    int control=0;

    ifstream Clasico;

    Clasico.open(NomA,ios::binary); //Preguntar si se deja el ios::in o es redundancia

    if (Clasico.is_open()){
        cout << "\nLeyendo el archivo....." << endl;
        while(!Clasico.eof()){
            carat=Clasico.get();
            binarioPM(carat,bina);
            for(int k=0; k<8 && control<Tm*8; k++, control++){
                Bin[control]=bina[k];
            }

        }
    }
    else{
        cout << "ERROR AL ABRIR EL ARCHIVO. Verifique que exista uno con el nombre ingresado" << endl;
        exit(1); //Sirve para detener el programa
    }

    Clasico.close();
}


void binarioPM(char c, char *b){
    int dec, aux=0;
    dec=c;
    for (int j=7; j>=0; j--){
        aux=dec%2;
        dec/=2;
        b[j]=aux+48;
    }
}


int tam(char *NomA){ //Tamaño del archivo

    int T=0;

    ifstream Archivo;
    Archivo.open(NomA, ios::in | ios::ate); //Para leer todos los caracteres que hayan. Puede que el ios::in sea redundante

    if (Archivo.is_open()){
        T=Archivo.tellg();
    }
    else{
        cout << "No se pudo abrir el fichero" << endl;
        exit(1);

    }

    Archivo.close();
    return T;

}

void decimal(char *deco, char *cad, int T) //Convertir la cadena de binarios a caracteres
{
    int j=0, cnt=1, pot=7, dec=0;
    for(int i=0; i<T; i++){ //Para la cadena convertida en decimal -> Caracter
        for(;j<cnt*8; j++){ // Para el arreglo decodificado de binario
            dec+=(deco[j]-48)*pow(2,pot);
            pot--;
        }
        cad[i]=char(dec);
        dec=0;
        cnt++;
        pot=7;
    }

}


void escribirDPM(char *NomAr, char *Dats, int T) //Escribir las caracteres descodificados en el archivo .txt
{
    ofstream Archivo;

    Archivo.open(NomAr, ios::binary);
    cout << "\nEscribiendo la informacion en el archivo......." << endl;
    Archivo.write(Dats,T);
    Archivo.close();
}


void menuPM()
{

    unsigned short op;
    bool banPM=true;
    int Tam=0, sem=0;
    char nomAC[]="natural.txt", nomAB[]="codificado.dat"; //Nombres de los archivos a usar

    Tam=tam(nomAC); //Longitud del archivo

    char *Binario = new char [Tam*8]; //Guardar la informacion en binario
    char *Cod = new char [Tam*8]; // Guardar la informacion en binario pero codificada
    char *Cadena = new char [Tam];

    while(banPM){
        cout << "\nMenu Primer Metodo" << endl;
        cout << "1. Codificar" << endl;
        cout << "2. Descodificar" << endl;
        cout << "3. Salir" << endl;
        cout << "Digite una opcion: ";
        cin >> op;

        switch (op) {

            case 1:
                cout << "Introduzca la semilla para la codificacion: ";
                cin >> sem;

                lecturaPM(nomAC,Binario, Tam); //Lee el archivo y lo convierte a binario
                codificacionPM(Binario,Cod,Tam,sem); // Codifica el archivo según las reglas dadas
                escribirPM(nomAB,Cod,Tam); //Escribe los datos codificados en el archivo .dat

                system("PAUSE");
                system("CLS");
                break;

            case 2:

                decodificacionPM(Cod,Binario, Tam, sem); //Aplica la decodificacion
                decimal(Binario, Cadena, Tam); //Convierte el arreglo decodificado en decimal -> caracter
                escribirDPM(nomAC,Cadena, Tam);
                system("PAUSE");
                system("CLS");

                break;

            case 3:
                banPM=false;
                //Liberar espacio en la memoria dinamica utilizado.
                delete [] Binario;
                delete [] Cod;
                delete [] Cadena;

                system("CLS");
                break;

            default:
                cout << "La opcion ingresada no ha sido encontrada." << endl;
                system("CLS");
                break;
        }
    }


}





















