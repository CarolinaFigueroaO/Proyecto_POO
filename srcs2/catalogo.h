#include <iostream>
#include <string>
#include <vector>
#include "grupoAlimento.h"


using namespace std;

#pragma once

//Herencia de clase persona
class Catalogo{
    vector<Grupo> catalogo;
public:
    Catalogo(){}
    ~Catalogo(){}

    void crearGrupos();
    vector<Grupo> getCatalago();
    void mostrarCatalogo();
};

void Catalogo::crearGrupos()
{
    vector<Alimento> proteinas;
    proteinas.emplace_back("Pollo", 100, 165);
    proteinas.emplace_back("Salmon", 100, 165);
    proteinas.emplace_back("Huevos", 100, 165);
    proteinas.emplace_back("Leche", 100, 165);
    proteinas.emplace_back("Res", 100, 165);
    catalogo.emplace_back("Proteinas", proteinas);

    vector<Alimento> frutas;
    frutas.emplace_back("Manzanas", 50,20);
    frutas.emplace_back("Platano", 50,20);
    frutas.emplace_back("Naranja", 50,20);
    frutas.emplace_back("Uvas", 50, 35);
    frutas.emplace_back("Fresas", 50, 15);
    catalogo.emplace_back("Frutas", frutas);

    vector<Alimento> verduras;
    verduras.emplace_back("Pepinos", 50, 7);
    verduras.emplace_back("Espinacas", 50, 12);
    verduras.emplace_back("Brocoli", 50, 17);
    verduras.emplace_back("Tomate", 50, 18);
    verduras.emplace_back("Zanahoria", 50, 20);
    catalogo.emplace_back("Verduras", verduras);

}

vector<Grupo> Catalogo::getCatalago(){
    return catalogo;
}

void Catalogo::mostrarCatalogo()
{
    for (auto grupo: catalogo)
    {
        grupo.imprimeGrupo();
    }

}