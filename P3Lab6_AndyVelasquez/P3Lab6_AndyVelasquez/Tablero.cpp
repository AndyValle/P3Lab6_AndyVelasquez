#include "Tablero.h"
#include "string"
#include "stdlib.h"
#include "time.h"
#include "windows.h"

using namespace std;

void Tablero::reservarMemoria(int diff)
{
    if (diff >= 0 && diff <= 3)
    {
        //primero seleccionamos la dificultad
        liberar();
        switch (diff)
        {
        case 0:
            columnas = filas = EASY;
            n_bombas = EASY_B;
            break;
        case 1:
            columnas = filas = NORMAL;
            n_bombas = NORMAL_B;
            break;
        case 2:
            columnas = HARD;
            filas = NORMAL;
            n_bombas = HARD_B;
            break;
        }
        descubiertas = 0;
        //Una vez cargamos los datos del nivel de dificultad elegido, reservamos la memoria, tanto para la de char como la de booleano
        oculto = new char* [filas];
        for (int i = 0; i < filas; i++)
            oculto[i] = new char[columnas];

        visible = new bool* [filas];
        for (int i = 0; i < filas; i++)
            visible[i] = new bool[columnas];

        //Ahora la inicializamos a un valor por defecto, '0' y 0.
        for (int i = 0; i < filas; i++)
            for (int j = 0; j < columnas; j++)
                oculto[i][j] = '0';
        for (int i = 0; i < filas; i++)
            for (int j = 0; j < columnas; j++)
                visible[i][j] = false;
    }
    else
    {
        oculto = nullptr;
        visible = nullptr;
        filas = columnas = descubiertas = n_bombas = 0;
    }
}

void Tablero::liberar()
{
    if (oculto != nullptr)
    {
        for (int i = 0; i < filas; i++)
            delete[] oculto[i];
        delete[] oculto;
    }

    if (visible != nullptr)
    {
        for (int i = 0; i < filas; i++)
            delete[] visible[i];
        delete[] visible;
    }

    oculto = nullptr; 
    visible = nullptr;
}

Tablero::Tablero(int diff)
{
    oculto = nullptr;
    visible = nullptr;
    reservarMemoria(diff);
}

Tablero::~Tablero()
{
    liberar();
    filas = columnas = descubiertas = n_bombas = 0;
}

void Tablero::rellenaBombas(int fila_inicial, int columna_inicial)
{
   
}

void Tablero::calcularBombas(int f, int c)
{
   
}


void Tablero::mostrarTableroOculto() const {
	

}

void Tablero::mostrarTableroVisible() const {
	
}
 void Tablero::imprimir(int nivel, bool fin, int fila, int columna, int intentos, int vidas){
 
 	int m[nivel][nivel];
    string mT[nivel][nivel];
    srand(time(NULL));
			
			    ///* matriz que controla la logica *///
     for (int i = 0;i < nivel; i++) {
		 for (int j = 0; j < nivel; j++) {
			      m[i][j]=rand()%(2-0) + (i * 100) + (j * 10);
		 }
	 }
			    
	 for (int i = 0;i < nivel; i++) {
		  for (int j = 0; j < nivel; j++) {
			 mT[i][j]="#";
			            

			 }
	}

	  ///* impresion de la matriz visible *///
	cout<<"           Buscaminas      "<<endl;
			    
	 for (int i = 0;i < nivel; i++) {
		 cout<<endl;
		 for (int j = 0; j < nivel; j++) {
			 cout<<"   "<<mT[i][j];
		}
		cout<<endl;
	}
		 cout<<endl;
		 ///* logica del juego *///
		 while (fin == false) {
				FIL:
		   		cout<<"   digite la fila entre 0 y "<<nivel-1<<": ";cin>>fila;cout<<endl;
			   if (fila == 20) {
			            
			    }
			    if (fila < 0 || fila > nivel-1) {
			      cout<<"   escribe un numero entre 0 y "<<nivel-1<<": "<<endl;
			        goto FIL;
			     }
					COL:
			        cout<<"   digite la columna entre 0 y "<<nivel-1<<": ";cin>>columna;cout<<endl;
			    if (columna < 0 || columna > nivel-1) {
			        cout<<"   escribe un numero entre 0 y "<<nivel-1<<": "<<endl;
			         goto COL;
			    }
			    intentos++;
				if (m[fila][columna]%2== 0) {
			         mT[fila][columna] = " ";
			    }
			    if (m[fila][columna]%2== 1) {
			    	mT[fila][columna] = "*";
			        vidas--;
			        if (vidas==0) {
			               fin=true;
			        }
			    }
			        system("cls");
			    if (fin==false) {
			            
			        for (int i = 0;i < nivel; i++) {
			            cout<<endl;
			            for (int j = 0; j < nivel; j++) {
			                cout<<"  "<<mT[i][j];
			            }
			            cout<<endl;
			        }
			        cout<<endl;
			    }
		if (fin == true) {
			cout<<"          Buscaminas"<<vidas<<endl;
			cout<<endl;
			cout<<"                     Has perdido"<<endl;
			cout<<endl;
			Sleep(2000);
			system("cls");
			cout<<"Juega de nuevo "<<endl;
			Sleep(1000);
			system("cls");
			            
		 }
	 }	
}


void Tablero::mostrarBombas() const
{
    for (int i = 0; i < filas; i++) {
        if (i == 0) {
            std::cout << "\t";
            for (int k = 0; k < filas; k++)
                std::cout << "[" << k << "]";
            std::cout << "\n\n";
        }
        for (int j = 0; j < columnas; j++) {
            if (j == 0)
                std::cout << "[" << i << "]\t";
            if (oculto[i][j] == 'X')
                std::cout << "[" << oculto[i][j] << "]";
            else
                std::cout << "[ ]";

            if (j == columnas - 1)
                std::cout << "\t[" << i << "]";
        }
        if (i == filas - 1) {
            std::cout << "\n\n";
            std::cout << "\t";
            for (int k = 0; k < filas; k++)
                std::cout << "[" << k << "]";
        }
        std::cout << std::endl;
    }
}
	// fin de la clase 

bool Tablero::desvelarCasilla(int f, int c)
{
    if (oculto[f][c] != 'X'){
        hacerVisible(f,c);
        if (oculto[f][c] == '0')
            revelarCeros(f,c);
    }
    return oculto[f][c] != 'X';
}

void Tablero::colocarBandera(int f, int c)
{
    BuscaMinas aux(f,c);
    banderas.add(aux);
}

void Tablero::quitarBandera(int f, int c){
    BuscaMinas aux(f,c);
    if (banderas.estaEnLista(aux) != -1)
        banderas.eliminar(aux);
}

void Tablero::revelarCeros(int f, int c)
{
    static CasillaBuscaMinas visitados;
    BuscaMinas aux;
    for (int i=f-1; i <= f+1 && i >= 0 && i < filas; i++){
        for (int j=c-1; j <= c+1 && j>= 0 && j < columnas; j++){
            hacerVisible(i,j);
            aux.setX(i);
            aux.setY(j);
            if (oculto[i][j] == '0' && visitados.estaEnLista(aux) == -1) {
                visitados.add(aux);
                revelarCeros(i, j);
            }
            
        }
    }
    
}

bool Tablero::haGanado()
{
    if (descubiertas == filas * columnas - n_bombas)
        return true;
    else
        return false;
}
void Tablero::hacerVisible(int f, int c){
    if (!visible[f][c]){
        visible[f][c] = true;
        descubiertas++;
    }
}