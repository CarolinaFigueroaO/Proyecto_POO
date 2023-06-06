// --- CLASE ALIMENTO ---
// Jorge Luis Nájera Espinosa - A01424106
// Andrea Carolina Figueroa Orihuela - A01424250

#include <iostream>
#include <string>

using namespace std;

#pragma once


class Alimento {
private:
    string nombre;   // Nombre del alimento
    int calorias;         // Cantidad de calorías en el alimento

public:
    //CONSTRUCTORES
    //Constructor vacio
    Alimento() {} 
    //Constructor default
    Alimento() = default;
    // Constructor que inicializa todos los atributos
    Alimento(const string& nombre, int calorias)  
            : nombre(nombre),  calorias(calorias) {}
    //Constructor copia
    Alimento(Alimento &&otro) 
            : nombre(otro.nombre), calorias(otro.calorias) {}
    //Destructor
    ~Alimento(){}

    //Setters de atributos
    void setNombre(const string &nombre) { this -> nombre = nombre; }
    void setNombre(const int &calorias) { this -> calorias = calorias; }
    // Getters de atributos
    const string& getNombre() const { return nombre; }
    int getCalorias() const { return calorias; }

};

