// --- CLASE MENU RECOMENDADO ---
// Jorge Luis Nájera Espinosa - A01424106
// Andrea Carolina Figueroa Orihuela - A01424250

#include <iostream>
#include <string>
#include <ctime>
#include "usuario.h"
#include "catalogo.h"

using namespace std;

#pragma once


class MenuRecomendado {
    Catalogo catalogo; //Creamos un objeto catalogo para poder recomendar comidas
    vector <Alimento> menu; //Vector de los alimentos recomendados
    string horaFecha; //Atributo para hora y fecha del menu
    double caloriasTotales = 0.0; //Calorias totales iniciales antes de recomendar alimentos

    public:
        MenuRecomendado() {}
        MenuRecomendado(Usuario&); //Construimos un menu recomendado recibiendo un usuario

    int variedadMenu(const int& num1, const int& num2) //Metodo para darle variedad a los menus recomendados
    {
        static bool isSeeded = false; // Variable  para verificar si la semilla ya ha sido generada
        if (!isSeeded) {
            srand(time(0)); // Generar la semilla solo una vez
            isSeeded = true; // Actualizar la variable de semilla generada
        }
        int randomNum = rand() % 2;
        if (randomNum == 0) {
            return num1;
        } else {
            return num2;
        }
    }

    string getFecha(){  return horaFecha; } //Getter de fecha y hora


    //Sobrecarga del operador << para la impresion de los atributos del menu recomendado
    friend std::ostream& operator<<(std::ostream& os, const MenuRecomendado& menu) 
    {
        os << "Fecha: " << menu.horaFecha << endl;
        for (auto alimento : menu.menu) 
        {
                os << alimento;
        }
        return os;
    }

};


//Estructura del constructor menu recomendado a partir de un usuario
MenuRecomendado::MenuRecomendado(Usuario& usuario)
{
            time_t now = std::time(0);
            tm* localTime = std::localtime(&now); // Guardamos la hora de creacion del menu
            char buffer[80];
            strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", localTime);
            horaFecha = buffer;
            cout << "Fecha: " << horaFecha << endl;
            catalogo.cargarCatalogo();
            if (usuario.imc < 18.5) //Ofrecemos opciones distintas a partir del imc del usuario
            {
                cout << "Tu indice de masa es bajo, te recomendamos un consumo de altas calorias" << endl;
                cout << "\tAlimento - Gramos - Calorias" << endl;
                for (int i = 0; i < 5; i++)
                {
                    Grupo altasCalorias = catalogo.getCatalago()[i];  // Accede a cada grupo del catalogo
                    Alimento alimentoAltasCal = altasCalorias.getAlimentos()[variedadMenu(0,1)];  // Obtener el alimento del calorias altas del grupo
                    caloriasTotales += alimentoAltasCal.getCalorias(); //Sumar calorias del alimento al total del menu recomendado
                    menu.push_back(alimentoAltasCal);
                    cout << alimentoAltasCal;  //Imprime el alimento recomentado
                }
                cout << "Calorias totales de comida sugerida: " << caloriasTotales << endl;
            }
            else if (usuario.imc> 18.5 && usuario.imc < 25)
            {
                cout << "Tu indice de masa es saludable, te recomendamos un consumo de medias calorias" << endl;
                cout << "\tAlimento - Gramos - Calorias" << endl;
                for (int i = 0; i < 5; i++)
                {
                    Grupo mediasCalorias = catalogo.getCatalago()[i];  // Accede a cada grupo del catalogo
                    Alimento alimentoMediasCal = mediasCalorias.getAlimentos()[variedadMenu(2,3)];  // Obtener el alimento del calorias medias del grupo
                    caloriasTotales += alimentoMediasCal.getCalorias(); //Sumar calorias del alimento al total del menu recomendado
                    menu.push_back(alimentoMediasCal);
                    cout << alimentoMediasCal;  //Imprime el alimento recomentado
                }
                cout << "Calorias totales de comida sugerida: " << caloriasTotales << endl;
            }
            else if (usuario.imc > 25)
            {
                cout << "Tu indice de masa es alto, te recomendamos un consumo de bajas calorias" << endl;
                cout << "\tAlimento - Gramos - Calorias" << endl;
                for (int i = 0; i < 5; i++)
                {
                    Grupo bajasCalorias = catalogo.getCatalago()[i]; // Accede a cada grupo del catalogo
                    Alimento alimentoBajasCal = bajasCalorias.getAlimentos()[variedadMenu(4,5)];  // Obtener el alimento del calorias bajas del grupo
                    caloriasTotales += alimentoBajasCal.getCalorias(); //Sumar calorias del alimento al total del menu recomendado
                    menu.push_back(alimentoBajasCal);
                    cout << alimentoBajasCal;  //Imprime el alimento recomentado
                }
                cout << "Calorias totales de comida sugerida: " << caloriasTotales << endl;
            }
            usuario.actualizarCalorias(caloriasTotales); //Registramos las calorias de los menus en el usuario
}