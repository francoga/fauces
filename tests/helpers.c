#include "stdio.h"
#include "../src/fauces.h"
#include "helpers.h"

void agregarResultado(Resultado* r1, Resultado r2) {
    r1->ok += r2.ok;
    r1->fallaron += r2.fallaron;
}

void crearDataEscuadron() {
    FILE *file;
    file = fopen(SQUADS, "wb");
    tescuadrones escuadrones[] = {
            {'A', 20, 'S', 20},
            {'B', 10, 'O', 30},
            {'X', 30, 'H', 5},
            {'J', 5,  'S', 40}
    };
    fwrite(escuadrones, sizeof(escuadrones), 1, file);
    fclose(file);
    printf("SQUADS.dat creado.\n");
}

void crearDataVulnera() {
    FILE *file;
    file = fopen(VULNERA, "wb");

    tvulnera vulneras[] = {
            {'H', 400,   200},
            {'O', 500,   500},
            {'S', 10000, 10}
    };
    fwrite(vulneras, sizeof(vulneras), 1, file);
    fclose(file);
    printf("VULNERA.dat creado.\n");
}

void imprimirTest(Resultado res, const char func[]) {
    printf("Pasaron %i de %i en '%s'\n", res.ok, res.ok + res.fallaron, func);
}
