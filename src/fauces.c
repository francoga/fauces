#include "fauces.h"
#include <stdbool.h>

bool verificar_elemento(char elemento) {
    return elemento == HIDROGENO || elemento == YODO || elemento == CARBONO || elemento == NITROGENO ||
           elemento == OXIGENO || elemento == AZUFRE || elemento == FOSFORO;
}

bool verificar_mayuscula(char codigo_escuadron) {
    return (codigo_escuadron >= A && codigo_escuadron <= Z);
}

bool verificar_escuadron(char codigo_escuadron, char elemento_ataque) {
    return verificar_mayuscula(codigo_escuadron) && verificar_elemento(elemento_ataque);
}

bool verificar_vulnerabilidad(tvulnera vulnera) {
    return verificar_elemento(vulnera.codigo_elemento) && vulnera.resistencia > CANTIDAD_MIN &&
           vulnera.durabilidad > CANTIDAD_MIN;
}

/**
 * Retorna la posicion en el archivo del escuadron o -1 si no esta.
 */
int indexOf(char codigo_escuadron, FILE *file) {
    tsquad squad;
    bool found = false;
    int curr_index = 0;
    size_t structSize = sizeof(tsquad);

    //leer hasta encontrar o fin del archivo
    while (!found && fread(&squad, structSize, 1, file)) {
        if (squad.codigo_escuadron == codigo_escuadron) {
            found = true;
        } else {
            curr_index++;
        }
    }
    return found ? curr_index * (int) structSize : -1;
}

bool actualizar_escuadrones(char codigo_escuadron, int cantidad_naves, char elemento_ataque, int potencia_ataque) {
    if (!verificar_escuadron(codigo_escuadron, elemento_ataque)
        || cantidad_naves < CANTIDAD_MIN
        || potencia_ataque < CANTIDAD_MIN) {
        printf("Datos invalido para escuadron\n");
        return false;
    }
    FILE *file = fopen(SQUADS, "rwb");
    int i = indexOf(codigo_escuadron, file);
    printf("Indice del escuadron en el archivo: %i\n", i);
    if (i == -1) {
        //mover puntero al final del archivo
        fseek(file, 0, SEEK_SET);
        printf("Agregando el escuadron: %c\n", codigo_escuadron);
    } else {
        //mover puntero desde el comienzo del archivo
        fseek(file, i, SEEK_SET);
        printf("Actualizando el escuadron: %c\n", codigo_escuadron);
    }

    //Escribir escuadron
    tsquad esc = {codigo_escuadron, cantidad_naves, elemento_ataque, potencia_ataque};
    fwrite(&esc, sizeof(esc), 1, file);

    return true;
}

void archivos_union(FILE *fvulnera, FILE *factualizacion) {
    tvulnera vulnera1, vulnera2, aux[7];
    int posAux = 0;

    fread(&vulnera1, sizeof(tvulnera), 1, fvulnera);
    while (fread(&vulnera2, sizeof(tvulnera), 1, factualizacion)) {
        if (verificar_vulnerabilidad(vulnera2)) {
            if (vulnera1.codigo_elemento == vulnera2.codigo_elemento) {
                aux[posAux++] = vulnera2;
                fread(&vulnera1, sizeof(tvulnera), 1, fvulnera);
            } else if (vulnera1.codigo_elemento > vulnera2.codigo_elemento) {
                aux[posAux++] = vulnera2;
            } else {
                aux[posAux++] = vulnera1;
                fread(&vulnera1, sizeof(tvulnera), 1, fvulnera);
            }
        }
    }
    fseek(fvulnera, 0, SEEK_SET);
    fwrite(aux, sizeof(tvulnera), sizeof(aux), fvulnera);
}

bool actualizar_vulnerabilidades(char *archivo_actualizacion) {
    FILE *fvulnera = fopen(VULNERA, "rb");
    FILE *factualizacion = fopen(archivo_actualizacion, "rb");
    if (!fvulnera || !factualizacion) {
        return false;
    }
    archivos_union(fvulnera, factualizacion);
    return true;
}

void insertion_sort(char arr[]) {
//TODO
}

/**
 * Busca todos los codigos correspondientes a un elemento en los squads
 */
void buscar_squads_elemento(FILE* fsquads, char elem, char* codigos) {
    tsquad squad;
    int i = 0;
    while(fread(&squad, sizeof(tsquad), 1, fsquads)) {
        if (squad.elemento_ataque == elem) {
            codigos[i++] = squad.codigo_escuadron;
        }
    }
    insertion_sort(codigos);
}

bool distribuir_escuadrones(char *archivo_distribuciones) {
    tvulnera vulnera;
    FILE *fdist = fopen(archivo_distribuciones, "w");
    FILE *fsquads = fopen(SQUADS, "rb");
    FILE *fvulnera = fopen(VULNERA, "rb");

    if (!fdist || !fsquads || !fvulnera) {
        return false;
    }

    while (fread(&vulnera, sizeof(tvulnera), 1, fvulnera)) {
        fprintf(fdist, "%c;", vulnera.codigo_elemento);
        char codigos[26];
        buscar_squads_elemento(fsquads, vulnera.codigo_elemento, codigos);
        for (int i=0;i< sizeof(codigos); i++) {
            if (i > 0) {
                fprintf(fdist, "-");
            }
            fprintf(fdist, "%c", codigos[i]);
        }
        fprintf(fdist, "\n");
    }

    return true;
}

bool realizar_ataques(char *archivo_ataques, char *archivo_resumen, bool *fauces_destruida) {
    return 0;
}