#include <iostream>
#include <string>
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
    public:
        App(){}
        App(const Usuario& usuario){ }
        ~App(){}

        void start(){
            cout << "===== BIENVENIDO =====" << endl;
            while(opcionMenu!= 'E')
            {
                cout << "Ingrese su nombre: " << endl;
                cin >> nombre;
                cout << "Ingrese su edad: " << endl;
                cin >> edad;
                cout << "Ingrese su peso: " << endl;
                cin >> peso;
                cout << "Ingrese su estatura: " << endl;
                cin >> estatura;
                usuarioRegistrado = new Usuario(nombre, edad, peso, estatura);
                cout << "Ingrese una opcion:" << endl;
                cout << "D: reporte del dia \nS: reporte semanal \nI: info de usuario \nC: catalogo de alimentos \nM: generar nueva comida recomendada" << endl;
                cin >> opcionMenu;
            }

        }
        void generarNuevaComida(){
            //Generar 1 comida
            MenuRecomendado(usuarioRegistrado);
        }
        void historialDia(){

        }
};
int main(){
    /*
        App aplicacion;
    aplicacion.start();
    */

   Usuario carolina("Caro", 19,55,1.57);
   cout << carolina;
   //MenuRecomendado menu(carolina);
   //cout << menu << endl;
    return 0;
}