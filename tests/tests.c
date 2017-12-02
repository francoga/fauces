#include <stdio.h>
#include "../src/fauces.h"
#include "helpers.h"

Resultado test_actualizar_escuadrones() {
    Resultado res = {};
    assert(actualizar_escuadrones('B', 11, 'S', 21), &res);
    imprimirTest(res, __func__);
    return res;
}

//Resultado dummyTest() {
//    Resultado res = {};
//    imprimirTest(res, __func__);
//    return res;
//}


int main() {
    crearDataEscuadron();
    crearDataVulnera();

    Resultado resultado = {};
    agregarResultado(&resultado, test_actualizar_escuadrones());

    printf("\nPasaron %i de %i pruebas", resultado.ok, resultado.ok + resultado.fallaron);

    return 0;
}
