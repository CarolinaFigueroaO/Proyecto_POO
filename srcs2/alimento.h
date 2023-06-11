// --- CLASE ALIMENTO ---
// Jorge Luis Nájera Espinosa - A01424106
// Andrea Carolina Figueroa Orihuela - A01424250

#include <iostream>
#include <string>

using namespace std;

#pragma once


class Alimento {
    
    string nombre;   // Nombre del alimento
    double calorias;         // Cantidad de calorías en el alimento
    double gramos;
public:
    //CONSTRUCTORES
    //Constructor vacio
    Alimento() {} 
    // Constructor que inicializa todos los atributos
    Alimento(const string& nombre, double calorias, double gramos)  
            : nombre(nombre),  calorias(calorias), gramos(gramos) {}
    //Constructor copia
    //Alimento(Alimento &otro) 
            //: nombre(otro.nombre), calorias(otro.calorias) {}
    //Destructor
    ~Alimento(){}

    //Setters de atributos
    void setNombre(const string &nombre) { this -> nombre = nombre; }
    void setCalorias(const int &calorias) { this -> calorias = calorias; }
    // Getters de atributos
    const string& getNombre() const { return nombre; }
    double getCalorias() const { return calorias; }
    
    void imprimeAlimento();
};

void Alimento::imprimeAlimento(){
    cout << "\t" << nombre  << ", gramos: " << gramos << ", calorias: " << calorias << endl;
}