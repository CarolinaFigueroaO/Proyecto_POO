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
    Catalogo catalogo;
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
        if(opcionMenu=='D')
        {
            historialDia();
        }
        else if(opcionMenu=='S')
        {
            historialSemana();
        }
        else if(opcionMenu=='I')
        {
            infoUsuario();
        }
        else if(opcionMenu=='C')
        {
            catalogoAlimentos(catalogo);
        }
        else if(opcionMenu=='M')
        {
            generarNuevaComida();
        }
        }

        
        void generarNuevaComida(){
            //Generar 1 comida
            MenuRecomendado(usuarioRegistrado);
        }
        void infoUsuario(){
            //Mostrar info del usuario
            cout << usuarioRegistrado;
        }

        void catalogoAlimentos(Catalogo catalogo){
            //Mostrar catalogo de alimentos
            try
            {
                if(catalogo.getCatalago().empty())
                {
                    throw runtime_error("El catalogo esta vacio");
                }
                catalogo.mostrarCatalogo();
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << '\n';
            }
        }

        void historialSemana(){
            //Mostrar historial de la semana
            cout << "Historial de la semana" << endl;
        }
        void historialDia()
        {
            //Mostrar historial del dia
            cout << "Historial del dia" << endl;
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