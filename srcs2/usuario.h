// --- CLASE PERSONA ---
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
    //Constructor con los tres atributos para inicializar
    Usuario(const string& nombre, const int& edad, const double& peso, const double& estatura) : Persona(nombre, edad, peso, estatura), calConsumidas(0.0) {}
   //Constructor copia
    Usuario(const Usuario& otro) : Persona(otro.getNombre(), otro.getEdad(), otro.getPeso(), otro.getEstatura()), calConsumidas(otro.calConsumidas) {}
    //Destructor
    ~Usuario(){}

    //METODOS
    //Getters
    double getCalorias() { return calConsumidas; }
    //Setters
    void actualizarCalorias(const double& _calConsumidas) { calConsumidas += _calConsumidas; }
    int calcularIMC()
    {
        imc = peso/pow(estatura, 2);
        return imc;
    }

    void generarReporte(){
        cout << "--- Reporte del Usuario ---" << endl;
        cout << "Nombre: " << getNombre() << endl;
        cout << "Edad: " << getEdad() << endl;
        cout << "Estatura: " << getEstatura() << " m" << endl;
        cout << "IMC: " << calcularIMC() << endl;
        cout << "Calorias consumidas hoy: " << calConsumidas << endl;
    }

};