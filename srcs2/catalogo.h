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
    proteinas.emplace_back("Res", 100, 250);
    proteinas.emplace_back("Salmon", 100, 206);
    proteinas.emplace_back("Huevos", 100, 155);
    proteinas.emplace_back("Pollo", 100, 165);
    proteinas.emplace_back("Atun", 100, 130);
    proteinas.emplace_back("Camarones", 100, 99);
    catalogo.emplace_back("Proteinas", proteinas);


    vector<Alimento> carbohidratos;
    carbohidratos.emplace_back("Avena", 50, 190);
    carbohidratos.emplace_back("Pan", 100, 150);
    carbohidratos.emplace_back("Pasta", 70, 100);
    carbohidratos.emplace_back("Arroz", 70, 90);
    carbohidratos.emplace_back("Maiz", 50, 43);
    carbohidratos.emplace_back("Patatas", 50, 38);
    catalogo.emplace_back("Carbohidratos", carbohidratos);


    vector<Alimento> frutas; 
    frutas.emplace_back("Platano", 50, 48);
    frutas.emplace_back("Pera", 50, 28);
    frutas.emplace_back("Manzana", 50, 26);
    frutas.emplace_back("Pinia", 50, 25);
    frutas.emplace_back("Naranja", 50, 22);
    frutas.emplace_back("Fresas", 50, 16);
    catalogo.emplace_back("Frutas", frutas);


    vector<Alimento> verduras; //50
    verduras.emplace_back("Zanahoria", 50, 20);
    verduras.emplace_back("Brocoli", 50, 17);
    verduras.emplace_back("Pimiento", 50, 13);
    verduras.emplace_back("Espinaca", 50, 12);
    verduras.emplace_back("Tomate", 50, 9);
    verduras.emplace_back("Calabacin", 50, 8);
    catalogo.emplace_back("Verduras", verduras);


    vector<Alimento> lacteos; 
    lacteos.emplace_back("Helado", 150, 310);
    lacteos.emplace_back("Mantequilla", 20, 140);
    lacteos.emplace_back("Queso", 30, 120);
    lacteos.emplace_back("Crema", 30, 100);
    lacteos.emplace_back("Leche", 100, 61);
    lacteos.emplace_back("Yogur", 100, 59);
    catalogo.emplace_back("Lacteos", lacteos);
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