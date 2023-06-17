// --- CLASE USUARIO ---
// Jorge Luis Nájera Espinosa - A01424106
// Andrea Carolina Figueroa Orihuela - A01424250
#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include "persona.h"

using namespace std;

#pragma once

//Herencia de clase persona
class Usuario : public Persona { 

    double calConsumidas; //Calorias consumidas por el usuario
public:
    double imc;

    //CONSTRUCTORES
    //Constructor vacio
    Usuario () : calConsumidas(0.0) {}
    //Constructor con los tres atributos para inicializar y determinar el imc
    Usuario(const string& nombre, const int& edad, const double& peso, const double& estatura) : Persona(nombre, edad, peso, estatura), calConsumidas(0.0) 
    {        
        imc = peso/pow(estatura, 2);
    }
   //Constructor copia
    Usuario(const Usuario& otro) : Persona(otro.getNombre(), otro.getEdad(), otro.getPeso(), otro.getEstatura()), calConsumidas(otro.calConsumidas) {}
    //Destructor
    ~Usuario(){}

    //METODOS
    //Getters
    double getCalorias() { return calConsumidas; }
    //Setters
    void actualizarCalorias(const double& _calConsumidas) { calConsumidas += _calConsumidas; }

    //Sobrecarga del operador << para la impresion de los atributos del usuario
    friend std::ostream& operator<<(std::ostream& os, const Usuario& usuario) {
        os << "--- INFO DEL USUARIO ---" << endl;
        os << "Nombre: " << usuario.getNombre() << endl;
        os << "Edad: " << usuario.getEdad() << endl;
        os << "Estatura: " << usuario.getEstatura() << " m" << endl;
        os << "IMC: " << usuario.imc << endl;
        os << "Calorias consumidas hoy: " << usuario.calConsumidas << endl;
        return os;
    }
};