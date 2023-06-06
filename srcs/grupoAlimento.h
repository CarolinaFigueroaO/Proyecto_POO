// --- CLASE GRUPO ---
// Jorge Luis Nájera Espinosa - A01424106
// Andrea Carolina Figueroa Orihuela - A01424250

#include <iostream>
#include <string>
#include <string>
#include <vector>
#include "alimento.h"

using namespace std;

#pragma once


class Grupo {
private:
    string nombre;               // Nombre del grupo
    vector<const Alimento*> alimentos;  // Alimentos que forman este alimento

public:
    // CONSTRUCTORES
    //Constructor vacio
    Grupo () {}
    //Constructor que inicializa con dato nombre
    Grupo (const string &nombre)
            : nombre(nombre){}
    //Constructor que inicializa todos los datos
    Grupo (const string &nombre, const vector<const Alimento*> &alimentos)
            : nombre(nombre), alimentos(alimentos) {}
    //Constructor copia
    Grupo (const Grupo &otro) 
            : nombre(otro.nombre), alimentos(otro.alimentos) {}
    //Destructor
    ~Grupo(){}
    
    //Setters
    void setNombre(const string &nombre) { this -> nombre = nombre; }
    void agregarAlimento(const Alimento* &alimento) { alimentos.push_back(alimento); }
    //Getters
    const string& getNombre() const { return nombre; }
    const vector<const Alimento*>& getAlimentos() const { return alimentos; }
};
