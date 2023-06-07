// --- CLASE PERSONA ---
// Jorge Luis Nájera Espinosa - A01424106
// Andrea Carolina Figueroa Orihuela - A01424250
#include <iostream>
#include <string>
#include <vector>

using namespace std;

#pragma once

class Persona {

    string nombre; //Nombre de persona
    int edad; //Edad de persona
    double peso; //Peso de persona

public:
    //CONSTRUCTORES
    //Constructor vacio
    Persona () {}
    //Constructor con los tres atributos para inicializar
    Persona(const string& nombre, const int& edad, const int& peso)
        : nombre(nombre), edad(edad), peso(peso) {}
    //Constructor copia
    Persona(const Persona& otro) 
        : nombre(otro.nombre), edad(otro.edad), peso(otro.peso) {}
    //Destructor
    ~Persona(){}

    //METODOS
    //Getters
    string getNombre() const { return nombre; }
    int getEdad() const { return edad; }
    double getPeso() const { return peso; }
    //Setters
    void setNombre(const string& nombre) { this -> nombre = nombre; }
    void setEdad(const int& edad) { this -> edad = edad; }
    void setPeso(const double& peso) { this -> peso = peso; }
};
