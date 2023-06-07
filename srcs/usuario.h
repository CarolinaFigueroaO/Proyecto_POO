// --- CLASE PERSONA ---
// Jorge Luis Nájera Espinosa - A01424106
// Andrea Carolina Figueroa Orihuela - A01424250
#include <iostream>
#include <string>
#include <vector>
#include "persona.h"

using namespace std;

#pragma once

//Herencia de clase persona
class Usuario : public Persona { 

    double calorias; //Calorias consumidas por el usuario

public:
    //CONSTRUCTORES
    //Constructor vacio
    Usuario () {}
    //Constructor con los tres atributos para inicializar
    Usuario(const string& nombre, const int& edad, const double& peso,const double& calorias)
        : Persona(nombre, edad, peso), calorias(calorias) {}
    //Constructor copia
    Usuario(const Usuario& otro)
        : Persona(otro.getNombre(), otro.getEdad(), otro.getPeso()), calorias(otro.calorias) {}
    //Destructor
    ~Usuario(){}

    //METODOS
    //Getters
    double getCalorias() const { return calorias; }
    //Setters
    void setCalorias(const double& calorias) { this -> calorias = calorias; }
};