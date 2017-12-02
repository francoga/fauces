#ifndef FAUCES_HELPERS_H
#define FAUCES_HELPERS_H

#endif //FAUCES_HELPERS_H

typedef struct Resultado {
    int ok;
    int fallaron;
} Resultado;

void agregarResultado(Resultado* r1, Resultado r2);
void crearDataEscuadron();
void crearDataVulnera();
void imprimirTest(Resultado res, const char func[]);
void assert(bool, Resultado*);