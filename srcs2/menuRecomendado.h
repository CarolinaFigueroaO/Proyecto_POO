// --- CLASE ALIMENTO ---
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
    Catalogo catalogo;
    vector <Alimento> menu;
    string paraUsuario;
    double caloriasTotales = 0.0;
    public:
        MenuRecomendado() {}
        MenuRecomendado(Usuario&);

    int variedadMenu(int num1, int num2)
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


};

MenuRecomendado::MenuRecomendado(Usuario& usuario)
{
            paraUsuario = usuario.nombre;
            cout << "Menu recomendado para " << paraUsuario << ", cargando..." << endl;
            catalogo.cargarCatalogo();
            if (usuario.imc < 18.5)
            {
                cout << "Tu indice de masa es bajo, te recomendamos un consumo de altas calorias" << endl;
                cout << "\tAlimento\tGramos\tCalorias" << endl;
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
                cout << "\tAlimento\tGramos\tCalorias" << endl;
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
                cout << "\tAlimento\tGramos\tCalorias" << endl;
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
            usuario.actualizarCalorias(caloriasTotales);
}