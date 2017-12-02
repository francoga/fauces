#include <stdio.h>
#include "../src/fauces.h"
#include "helpers.h"

Resultado test_actualizar_escuadrones() {
    Resultado res = {};

    actualizar_escuadrones('A', 1, 'a', 1);

    imprimirTest(res, __func__);
    return res;
}

Resultado dummyTest() {
    Resultado res = {};
    imprimirTest(res, __func__);
    return res;
}


int main() {
    crearDataEscuadron();
    crearDataVulnera();

    Resultado resultado = {};
    agregarResultado(&resultado, dummyTest());

    printf("\nPasaron %i de %i pruebas", resultado.ok, resultado.ok + resultado.fallaron);

    return 0;
}
