#include <iostream>
#include <string>
#include "usuario.h"
#include "menuRecomendado.h"

using namespace std;

int main(){

    Usuario carolina("Carolina", 19, 44, 1.56);
    MenuRecomendado uno(carolina);
    MenuRecomendado dos(carolina);
    MenuRecomendado tres(carolina);
    MenuRecomendado cuatro(carolina);
    carolina.generarReporte();
    return 0;
}