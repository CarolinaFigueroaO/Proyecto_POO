// --- CLASE PERSONA ---
// Jorge Luis Nájera Espinosa - A01424106
// Andrea Carolina Figueroa Orihuela - A01424250
#include <iostream>
#include <string>
#include <vector>

using namespace std;

#pragma once

class Persona {
    
public:

    string nombre; //Nombre de persona
    int edad; //Edad de persona
    double peso; //Peso de persona
    double estatura;

    //CONSTRUCTORES
    //Constructor vacio
    Persona () {}
    //Constructor con los tres atributos para inicializar
    Persona(const string& nombre, const int& edad, const double& peso, const double& estatura) : nombre(nombre), edad(edad), peso(peso), estatura(estatura) {}
    //Constructor copia
    Persona(const Persona& otro) : nombre(otro.nombre), edad(otro.edad), peso(otro.peso), estatura(otro.estatura) {}
    //Destructor
    ~Persona(){}

    //METODOS
    //Getters
    string getNombre() const { return nombre; }
    int getEdad() const { return edad; }
    double getPeso() const { return peso; }
    double getEstatura() const { return estatura; }
    //Setters
    void setNombre(const string& nombre) { this -> nombre = nombre; }
    void setEdad(const int& edad) { this -> edad = edad; }
    void setPeso(const double& peso) { this -> peso = peso; }
    void setEsatura(const double& estatura) { this -> estatura = estatura; }
};
