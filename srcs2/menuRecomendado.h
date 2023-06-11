// --- CLASE ALIMENTO ---
// Jorge Luis Nájera Espinosa - A01424106
// Andrea Carolina Figueroa Orihuela - A01424250

#include <iostream>
#include <string>
#include "usuario.h"
#include "catalogo.h"

using namespace std;

#pragma once


class MenuRecomendado {
    Catalogo catalogo;
    vector <Alimento> recomendaciones;
    double caloriasTotales;
    public:
        MenuRecomendado() {}
        MenuRecomendado(Usuario usuario)
        {
            catalogo.crearGrupos();
            cout << "IMC: " << usuario.calcularIMC() << endl;
            // imc < 18.5 = Peso bajo
            // 18.5 < imc < 25 = Peso saludable
            // imc > 25 = Sobrepeso
            if (usuario.calcularIMC() < 18.5)
            {
                cout << "Tu indice de masa es bajo, te recomendamos un consumo de altas calorias" << endl;
                for (int i = 0; i < 2; i++)
                {
                    Grupo altasCalorias = catalogo.getCatalago()[i];  // Accede a cada grupo del catalogo
                    Alimento alimentoAltasCal = altasCalorias.getAlimentos()[3];  // Obtener el alimento del calorias altas del grupo
                    caloriasTotales =+ alimentoAltasCal.getCalorias(); //Sumar calorias del alimento al total del menu recomendado
                    alimentoAltasCal.imprimeAlimento();  //Imprime el alimento recomentado
                }
                cout << "Calorias totales: " << caloriasTotales << endl;
            }
            else if (usuario.calcularIMC()> 18.5 && usuario.imc < 25)
            {
                cout << "Tu indice de masa es saludable, te recomendamos un consumo de medias calorias" << endl;
                for (int i = 0; i < 2; i++)
                {
                    Grupo mediasCalorias = catalogo.getCatalago()[i];  // Accede a cada grupo del catalogo
                    Alimento alimentoMediasCal = mediasCalorias.getAlimentos()[2];  // Obtener el alimento del calorias medias del grupo
                    caloriasTotales += alimentoMediasCal.getCalorias(); //Sumar calorias del alimento al total del menu recomendado
                    alimentoMediasCal.imprimeAlimento();  //Imprime el alimento recomentado
                }
            }
            else if (usuario.calcularIMC() > 25)
            {
                cout << "Tu indice de masa es alto, te recomendamos un consumo de bajas calorias" << endl;
                for (int i = 0; i < 2; i++)
                {
                    Grupo mediasCalorias = catalogo.getCatalago()[i]; // Accede a cada grupo del catalogo
                    Alimento alimentoMediasCal = mediasCalorias.getAlimentos()[1];  // Obtener el alimento del calorias bajas del grupo
                    caloriasTotales += alimentoMediasCal.getCalorias(); //Sumar calorias del alimento al total del menu recomendado
                    alimentoMediasCal.imprimeAlimento();  //Imprime el alimento recomentado
                }
            }
        } 

};