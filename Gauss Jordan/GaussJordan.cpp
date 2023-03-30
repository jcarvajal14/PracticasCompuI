#include <iostream>
#include <array>

// Añadir std para fácil llamado de funciones
using namespace std;


template <typename matriz>
void LlenarMatriz(matriz & miMatriz);

template <typename matriz>
void ImprimirMatriz(matriz & miMatriz);

template <typename matriz>
void ImprimirSolucion(matriz & miMatriz);

template <typename matriz>
void GaussJordan(matriz & miMatriz);

int main(){


    const int variables = 3;

    const int columnas = variables + 1;

    array <array<float, columnas>, variables> miMatriz = { 0 };


    LlenarMatriz(miMatriz);

    ImprimirMatriz(miMatriz);

    GaussJordan(miMatriz);

    ImprimirSolucion(miMatriz);

    return 0;
}

template <typename matriz>

void LlenarMatriz(matriz & miMatriz)

{
    int variables = miMatriz.size();

    for (int i = 0; i < variables; i++) {

        for (int j = 0; j <= variables; j++) {

            cout << "Valor elemento [" << i << "][" << j << "]: ";

            cin >> miMatriz[i][j];
        }
    }
}


template <typename matriz>

void ImprimirMatriz(matriz & miMatriz)

{
    int variables = miMatriz.size();

    for (int i = 0; i < variables; i++) {

        cout << "[ ";

        for (int j = 0; j < variables + 1; j++)

            cout << miMatriz[i][j] << '\t';

        cout << "]\n";
    }
}

template <typename matriz>

void ImprimirSolucion(matriz & miMatriz)

{
    cout << "La solución de la matriz es: " << endl;

    for (int i = 0; i < miMatriz.size(); i++) {

        cout << "x" << i + 1 << " = " << miMatriz[i][miMatriz.size()] << endl;
    }
  
}

template <typename matriz>

void GaussJordan(matriz & miMatriz){


    for (int i = 0; i < miMatriz.size(); i++) {

        // Buscamos el pivote
        
        int pivote = i;

        for (int j = i + 1; j < miMatriz.size(); j++) {

            if (abs(miMatriz[j][i]) > abs(miMatriz[pivote][i])) {

                pivote = j;
            }
        }

        // Intercambio de filas

        if (pivote != i) {

            swap(miMatriz[i], miMatriz[pivote]);
        }

        // Hacer ceros debajo del pivote

        for (int j = i + 1; j < miMatriz.size(); j++) {

            double valor = miMatriz[j][i] / miMatriz[i][i];

            for (int k = i + 1; k < miMatriz.size() + 1 ; k++) {

                miMatriz[j][k] -= valor * miMatriz[i][k];
            }

            miMatriz[j][i] = 0;
        }


    }

    // Hacer ceros encima del pivote

    for (int i = miMatriz.size() - 1; i >= 0; i--) {

        for (int j = i - 1; j >= 0; j--) {

            double valor = miMatriz[j][i] / miMatriz[i][i];

            for (int k = i + 1; k < miMatriz.size() + 1; k++) {

                miMatriz[j][k] -= valor * miMatriz[i][k];
            }

            miMatriz[j][i] = 0;
        }
    }

    // Normalizar las filas

    for (int i = 0; i < miMatriz.size(); i++) {

        double valor = miMatriz[i][i];

        for (int j = i; j < miMatriz.size() + 1; j++) {

            miMatriz[i][j] /= valor;
        }
    }

}
