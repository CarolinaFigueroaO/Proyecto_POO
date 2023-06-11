#include <iostream>
#include <string>
#include "usuario.h"
#include "menuRecomendado.h"

using namespace std;

int main(){

    Usuario carolina("Carolina", 19, 45, 1.56);
    MenuRecomendado recomendacion(carolina);

    return 0;
}