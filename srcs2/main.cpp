// --- CLASE APP y MAIN DE EJECUCION ---
// Jorge Luis Nájera Espinosa - A01424106
// Andrea Carolina Figueroa Orihuela - A01424250

#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include "usuario.h"
#include "menuRecomendado.h"

using namespace std;

//Clase App que estructura el proceso de la aplicacion
class App
{
    char opcionMenu; //Opcion de menu que eligira el usuario
    Usuario* usuarioRegistrado; //Usuario que se registrara
    string nombre; //Atributos para almacenar en usuario
    int edad;
    double peso;
    double estatura;
    vector<MenuRecomendado> historial; //Vector para el historial del usuario
    Catalogo catalogo; //Catalogo ofrecido
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
    App aplicacion; //Creacion de aplicacion
    aplicacion.start(); //Ejecucion de aplicacion
    return 0;
}




void App::start(){
    //Bienvenida y registro de usuario
    cout << "------------ BIENVENIDO ------------" << endl;
    cout << "Podras generar 4 comidas recomendadas de acuerdo a tu IMC." << endl;
    cout << "Ingrese datos reales o realistas para el correcto funcionamiento de la app, \nsino se le pedira ingresar los datos nuevamente" << endl;
    cout << "Ingrese su nombre: " << endl;
    cin >> nombre;
    do
    {
        cout << "Ingrese su edad (10 - 100): " << endl;
        cin >> edad;
        if (cin.fail()) { //Verificamos que ingrese el tipo de dato correcto
            cout << "Error: Ingrese un numero valido." << endl;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    } while (edad < 10 || edad > 100); //Verificamos datos realistas

    do
    {
        cout << "Ingrese su peso (kg): " << endl;
        cin >> peso;
        if (cin.fail()) { //Verificamos que ingrese el tipo de dato correcto
            cout << "Error: Ingrese un numero valido." << endl;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    } while (peso < 30 || peso > 200 || cin.fail()); //Verificamos datos realistas
    
    do
    {
        cout << "Ingrese su estatura (m): " << endl;
        cin >> estatura;
        if (cin.fail()) { //Verificamos que ingrese el tipo de dato correcto
            cout << "Error: Ingrese un numero valido." << endl;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    } while (estatura < 1 || estatura > 2.40); //Verificamos datos realistas

    usuarioRegistrado = new Usuario(nombre, edad, peso, estatura); //Registramos al usuario
    //Bucle del menu de opciones para mostrar distintos reportes
    do {
        cout << "Ingrese una opcion:" << endl;
        cout << "M: generar una comida recomendada \nD: generar comidas recomendadas del dia (4 comidas) \nH: Historial de comidas generadas hoy \nI: info de usuario \nC: catalogo de alimentos  \nQ: salir" << endl;
        cin >> opcionMenu;
        //Llamamos los metodos para cada opcion de menu
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
            cout << "Opcion invalida!. Por favor, ingrese una opcion valida." << endl; //En caso de que no se tener la opcion ingresada
        }
    } while (true);
}


void App::generarComida(){ 
    if(historial.size()>= 4) { //Comprobamos que el usuario no haya rebasado el limite de comidas generadas
        cout << "Limite de comidas generadas alcanzado!" << endl;
    } else{
        MenuRecomendado menu(*usuarioRegistrado); //Generamos una recomendacion para el usuario registrado
        historial.push_back(menu); //Guardamos la recomendacion en el historial
    }

}
void App::historialDia(){
    cout << "-------- Menus generados hoy --------" << endl;
    if (historial.size() == 0){ cout << "No se han generado menus aun" << endl; }
    //Mostrar historial del dia
    for (auto menus: historial) //Recorremos los objetos del historial
    {
        cout << menus; //Mostramos los menus con la sobrecarga de <<
    }
    cout << "------------------------------------" << endl;
}

void App::catalogoAlimentos(){
    //Mostrar y verificar que no hayas problemas en el catalogo
    catalogo.cargarCatalogo(); //Cargamos los alimentos al catalogo (desde el archivo)
    try //Se intenta realizar lo siguiente para detectar errores
    {
        if(catalogo.getCatalago().empty()) //Si el catalogo esta vacio arrojara una excepcion
        {
            throw runtime_error("El catalogo esta vacio");
        }
        catalogo.mostrarCatalogo(); //Si no hay excepcion, muestra el catalogo
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n'; //Muestra la excepcion detectada
    }
}

void App::comidasDia()
{
    if(historial.size()>= 4) { //Verifica que el usuario no haya rebasado el limite de comidas generadas
        cout << "Limite de comidas generadas alcanzado!" << endl;
    } else{
        int lim = 4 - historial.size(); //Calculo cuantas comidas le faltan para alcanzar el limite
        for (size_t i = 0; i < lim; i++) //Genera las comidas faltantes del dia
        {
            MenuRecomendado menu(*usuarioRegistrado); //Recomedaciones apartir del usuario registrado
            historial.push_back(menu); //Guarda las recomendaciones en el historial
        }
        if(historial.size()>= 4) { //Vuelve a verificar sino a alcanzado el limite de comidas generadas
        cout << "Limite de comidas generadas alcanzado!" << endl;
        }
    }
}
