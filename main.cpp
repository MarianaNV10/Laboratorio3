#include <metodo1.h>
#include <metodo2.h>

int main()
{

    unsigned short opc;
    bool banP=true;
    while(banP){

        cout << "1. Primer metodo" << endl;
        cout << "2. Segundo metodo" << endl;
        cout << "3. Cajero" << endl;
        cout << "4. Salir" << endl;
        cout << "Digite una opcion: ";
        cin >> opc;
        system("CLS");

        switch (opc) {
            case 1: //Primer metodo -> char
                menuPM();
                break;

            case 2: //Segundo metodo ->string
                menuSM();
                break;

            case 3: //Cajero


                break;

            case 4:
                banP=false;
                system("CLS");

                break;

            default:
                cout << "La opcion ingresada no ha sido encontrada" << endl;
                system("CLS");
                break;
        }
    }


    return 0;
}
