#include <iostream>
#include <string>
#include <vector>
#include "usuario.h"
#include "menuRecomendado.h"

using namespace std;


class App
{
    char opcionMenu;
    Usuario* usuarioRegistrado;
    string nombre;
    int edad;
    double peso;
    double estatura;
    vector<MenuRecomendado> historial;
    Catalogo catalogo;
    public:
        App(){}
        App(const Usuario& usuario){ }
        ~App(){}

        void start();
        void comidasDia();
        void generarComida();
        void catalogoAlimentos();
        void historialDia();
};

int main(){
    App aplicacion;
    aplicacion.start();
    return 0;
}




void App::start(){
    cout << "------------ BIENVENIDO ------------" << endl;
    cout << "Ingrese su nombre: " << endl;
    cin >> nombre;
    cout << "Ingrese su edad: " << endl;
    cin >> edad;
    cout << "Ingrese su peso: " << endl;
    cin >> peso;
    cout << "Ingrese su estatura: " << endl;
    cin >> estatura;
    usuarioRegistrado = new Usuario(nombre, edad, peso, estatura);

    do {
        cout << "Ingrese una opcion:" << endl;
        cout << "M: generar una comida recomendada \nD: generar comidas recomendadas del dia (4 comidas) \nH: Reporte del historial de hoy \nI: info de usuario \nC: catalogo de alimentos  \nQ: salir" << endl;
        cin >> opcionMenu;
        if(opcionMenu == 'M') {
            generarComida();
        }
        else if (opcionMenu == 'D') {
            comidasDia();
        } else if (opcionMenu == 'H') {
            historialDia();
        } else if (opcionMenu == 'I') {
            cout << *usuarioRegistrado;
        } else if (opcionMenu == 'C') {
            catalogoAlimentos();
        } else if (opcionMenu == 'Q') {
            break;  // Salir del bucle si se ingresa 'Q'
        }
        else {
            cout << "Opcion invalida!. Por favor, ingrese una opcion valida." << endl;
        }
    } while (true);
}


void App::generarComida(){
    if(historial.size()>= 4) {
        cout << "Limite de comidas generadas alcanzado!" << endl;
    } else{
        MenuRecomendado menu(*usuarioRegistrado);
        historial.push_back(menu);
    }

}
void App::historialDia(){
    cout << "-------- Menus generados hoy --------" << endl;
    //Mostrar historial del dia
    for (auto menus: historial)
    {
        cout << menus;
    }
    cout << "------------------------------------" << endl;
}

void App::catalogoAlimentos(){
    //Mostrar y verificar que no hayas problemas en el catalogo
    Catalogo catalogoDisponible;
    catalogoDisponible.cargarCatalogo();
    try
    {
        if(catalogoDisponible.getCatalago().empty())
        {
            throw runtime_error("El catalogo esta vacio");
        }
        catalogoDisponible.mostrarCatalogo();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

void App::comidasDia()
{
    if(historial.size()>= 4) {
        cout << "Limite de comidas generadas alcanzado!" << endl;
    } else{
        int lim = 4 - historial.size();
        for (size_t i = 0; i < lim; i++)
        {
            MenuRecomendado menu(*usuarioRegistrado);
            historial.push_back(menu);
        }
        if(historial.size()>= 4) {
        cout << "Limite de comidas generadas alcanzado!" << endl;
        }
    }
}
