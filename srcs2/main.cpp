#include <iostream>
#include <string>
#include "usuario.h"
#include "menuRecomendado.h"

using namespace std;


class App
{
    vector<Usuario> usuarios;
    char opcionMenu;
    string nombreUsuario;
    public:
        App(){}
        App(const Usuario& usuario){ usuarios.push_back(usuario); }
        ~App(){}

        void start(){
            cout << "===== BIENVENIDO =====" << endl;
            while(opcionMenu!= 'E')
            {
                cout << "Ingrese su nombre de usuario: " << endl;
                cin >> nombreUsuario;
                for(auto usuario: usuarios){
                    if(usuario.getNombre() != nombreUsuario)
                    {
                        cout << "Debe registrar sus datos primero" << endl;
                    }
                }
                cout << "Bienvenido de vuelta" << endl;
                cout << "Ingrese una opcion:" << endl;
                cout << "D: reporte del dia \nS: reporte semanal \nI: info de usuario \nC: catalogo de alimentos \nM: generar nuevo menu recomendado" << endl;
                cin >> opcionMenu;
 
            }
        }
};
int main(){
    
    cout << "===== BIENVENIDO =====" << endl;
    Usuario caro("a", 15, 68, 1.70);
    MenuRecomendado menu(caro);
    return 0;
}