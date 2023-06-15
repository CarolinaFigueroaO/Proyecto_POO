// --- CLASE GRUPO ---
// Jorge Luis Nájera Espinosa - A01424106
// Andrea Carolina Figueroa Orihuela - A01424250

#include <iostream>
#include <string>
#include <vector>
#include "alimento.h"

using namespace std;

#pragma once


class Grupo {

    string nombre;               // Nombre del grupo
    vector<Alimento> alimentos;  // Alimentos que forman este alimento

public:
        // CONSTRUCTORES
        //Constructor vacio
        Grupo () {}
        //Constructor que inicializa con dato nombre
        Grupo (const string &nombre)
                : nombre(nombre){}
        //Constructor que inicializa todos los datos
        Grupo (const string &nombre, const vector<Alimento> &alimentos)
                : nombre(nombre), alimentos(alimentos) {}
        //Constructor copia
        Grupo (const Grupo &otro) 
                : nombre(otro.nombre), alimentos(otro.alimentos) {}
        //Destructor
        ~Grupo(){}

        //Setters
        void setNombre(const string &nombre) { this -> nombre = nombre; }
        void agregarAlimento(const Alimento& alimento) { alimentos.push_back(alimento); }    //Getters
        const string& getNombre() const { return nombre; }
        const vector<Alimento> getAlimentos() const { return alimentos; }


        friend std::ostream& operator<<(std::ostream& os, const Grupo& grupo) 
        {
                os << "Grupo: " << grupo.getNombre() << endl;
                for (auto alimento : grupo.getAlimentos()) 
                {
                        os << alimento;
                }
                return os;
        }
};


