#include <metodo2.h>

string lecturaSM(string NomA, string Bin, int T)
{
    string bina;
    char carac;
    int control=0;

    ifstream Archivo;

    Archivo.open(NomA, ios::binary);

    cout << "\nLeyendo el archivo...." << endl;

    if(Archivo.is_open()){
        while(!Archivo.eof()){
            carac=Archivo.get();
            bina=binarioSM(carac);
            for(int s=7; s>=0 && control<T*8;s--, control++){
                Bin+=bina[s]; //Concatenacion
            }

        }

    }
    else{
        cout << "ERROR AL ABRIR EL ARCHIVO." << endl;
        exit(1);
    }

    Archivo.close();

    return Bin;
}

string binarioSM(char c)
{
    string binary;
    int dec, aux=0;
    dec=c;
    for (int j=7; j>=0; j--){
        aux=dec%2;
        dec/=2;
        binary+=aux+48;
    }
    return binary;
}

int longitud(string NomA)
{
    int t;
    ifstream clas;

    clas.open(NomA, ios::binary | ios::ate);
    t=clas.tellg();
    clas.close();

    return t;

}

string codificarSM(string Bin, int T, int Sem, string Codi)
{
    string str;
    int c=0;

    cout << "\nCodificando la informacion..."<< endl;

    for(int i=1; i<=(T*8)/Sem; i++){
        for (; c<Sem*i && Bin[c]!='\0'; c++){
            str+=Bin[c]; //Revisar la parte de push_back y ver por cual cambiarla
        }

        Codi+=str[Sem-1];
        str.pop_back();
        Codi+=str;
        str.clear();
    }

    return  Codi;
}


void escribirSM(string NomAC, string Datos) //Verificar que escriba bien en el .dat
{
    ofstream Archivo;

    Archivo.open(NomAC, ios::binary);
    cout << "\nEscribiendo la informacion en el archivo......." << endl;
    Archivo << Datos;
    Archivo.close();

}

string descodificarSM(string Codi, int T, int sem, string Bin)
{
    string str;
    char aux;
    int c=0;

    cout << "\nDecodificando la información..." << endl;

    for (int j=1; j<=(T*8)/sem; j++){
        for(; c <sem*j; c++){
            str+=Codi[c];
        }

        for(int s=0; s<sem; s++){
            aux=str[s];
            if(str[s+1]!='\0'){
                str[s]=str[s+1];
                str[s+1]=aux;
            }
        }
        Bin+=str;
        str.clear();

    }
    return Bin;
}


string decimalSM(string Desc, string Cadena, int T)
{
    int b=0, pot=7, dec=0;
    for (int d=1; d<=T; d++){
        for(;b<d*8;b++){
            dec+=(Desc[b]-48)*pow(2,pot);
            pot--;
        }
        Cadena+=char(dec);
        dec=0;
        pot=7;
    }
    return Cadena;
}


void escribirDSM(string NomAD, string Datos)
{
    ofstream Arch;

    Arch.open(NomAD,ios::binary); //Verificar el modo de apertura
    cout << "\nEscribiendo la informacion en el archivo......." << endl;
    Arch<<Datos;
    Arch.close();

}

void menuSM()
{
    unsigned short op;
    int sem, Tam;
    string clasic, codif;
    string Binario, Cod, Cad;
    bool banSM=true;

    cout << "Ingrese el nombre del archivo para extraer la informacion: ";
    cin.get();
    getline(cin,clasic);
    fflush(stdin); //Limpiar el buffer
    cout << "Ingrese el nombre del archivo para guardar la codificacion: ";
    getline(cin,codif);

    Tam=longitud(clasic);

    while(banSM){

        cout<< "\nMenu Segundo Metodo" << endl;
        cout << "1. Codificar" << endl;
        cout << "2. Descodificar" << endl;
        cout << "3. Salir" << endl;
        cout << "Digite una opcion: ";
        cin >> op;

        switch (op) {

        case 1: //Codificacion segundo metodo

            cout << "Digite la semilla: ";
            cin >> sem;
            Binario=lecturaSM(clasic,Binario,Tam);
            Cod=codificarSM(Binario,Tam,sem,Cod);
            escribirSM(codif,Cod);
            Binario.clear();

            system("PAUSE");
            system("CLS");

            break;

        case 2: //Decodificacion segundo metodo

            Binario=descodificarSM(Cod,Tam,sem,Binario);
            Cad=decimalSM(Binario,Cad,Tam);
            escribirDSM(clasic,Cad);

            system("PAUSE");
            system("CLS");
            break;

        case 3:

            banSM=false;
            Binario.clear();
            Cod.clear();
            Cad.clear();
            clasic.clear();
            codif.clear();

            system("CLS");
            break;
        }
   }
}
