#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "grupoAlimento.h"



using namespace std;

#pragma once

class Catalogo{
    vector<Grupo> catalogo;
public:
    Catalogo(){}
    ~Catalogo(){}

    void cargarCatalogo();
    vector<Grupo> getCatalago();
    void mostrarCatalogo();
};

void Catalogo::cargarCatalogo()
{
    ifstream archivo(".../lista_alimentos.txt");

    try
    {
        archivo.open("lista_alimentos.txt");
        if(!archivo.is_open())
        {
            throw runtime_error("Error al abrir el archivo");
        }
        string nombre;
        int cantidad;
        int calorias;
        string grupo;
        vector<Alimento> alimentos;

        int contador = 0;
        while (archivo >> nombre >> cantidad >> calorias)
        {
            alimentos.emplace_back(nombre, cantidad, calorias);
            contador++;
            if (contador == 6)
            {
                archivo >> grupo;
                getline(archivo, nombre);
                catalogo.emplace_back(grupo, alimentos);
                alimentos.clear();
                contador = 0;
            }
            string lineaVacia;
            getline(archivo, lineaVacia);
        }
    }
    catch(runtime_error& e)
    {
        cout << e.what() << endl;
    }
}

vector<Grupo> Catalogo::getCatalago(){
    return catalogo;
}

void Catalogo::mostrarCatalogo()
{
    for (auto grupo: catalogo)
    {
        cout << grupo;
    }

}