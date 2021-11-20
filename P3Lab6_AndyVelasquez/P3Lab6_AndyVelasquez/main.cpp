#include <iostream>
#include "Tablero.h"
#include "CasillaBuscaMinas.h"
#include "BuscaMinas.h"
#include "string"
#include "stdlib.h"
#include "time.h"
#include "windows.h"


using namespace std;
int menu();
 
int main() {
	int opcion;
	
	while((opcion = menu()) != 3) {
		switch (opcion) {
			case 1: {
				int nivel = 0;
			    int vidas = 0;
			    int intentos = 0;
			    int fila =0;
			    int columna =0;
			    bool fin = false;
			    cout<<"   Dificulta                    "<<endl;
			    cout<<endl;
			    cout<<"   1. Facil      "<<endl;
			    cout<<"   2. Medio      "<<endl;
			    cout<<"   3. Dificil    "<<endl;
			    cout<<endl;
			    cout<<"   Ingresa el tu Nivel de dificultad: ";cin>>nivel;cout<<endl;
			
			    switch (nivel) {
			        case 1:{
			            nivel = 8;
			            vidas = 12;
			            fin = false;
			            intentos=0;
			            Tablero t(nivel);
			            t.imprimir (nivel, fin, fila, columna, intentos, vidas);
			       }
			            break;
			        case 2:
			        	{
			            nivel = 12;
			            vidas = 8;
			            fin = false;
			            intentos=0;
			            Tablero t(nivel);
			            t.imprimir (nivel, fin, fila, columna, intentos, vidas);
			            break;
			        }
			        case 3:{
			            nivel = 12;
			            vidas = 4;
			            fin = false;
			            intentos=0;
			            Tablero t(nivel);
			            t.imprimir (nivel, fin, fila, columna, intentos, vidas);
			          
			            break;
					}
			        default:
			            
			            cout<<"   escribe un nivel valido entre 1 y 3"<<endl;
			            
			            break;
			    }

	   	    }
		}
	}
    
	return 0;
}
int menu() {
		int opcion;
		cout << " MENU DE BUSCAMINAS " << endl;
		cout << "1. Jugar al Busca minas" << endl;
		cout << "2. Salir" << endl;
		cout << endl;
		cout << "Ingrese la opcion: ";
		cin >> opcion;
		cout << endl;
		while(opcion < 1 || opcion > 1) {
			cout << "Seleccione una opcion dentro del rango disponible" << endl;
			cout << "Ingrese la opcion: ";
			cin >> opcion;
			cout << endl;
		}
		return opcion;
	}// fin del menu
	// fin de la clase 