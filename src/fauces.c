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

/**
 * Retorna la posicion en el archivo del escuadron o -1 si no esta.
 */
int indexOf(char codigo_escuadron, FILE *file) {
    tescuadrones squad;
    bool found = false;
    int curr_index = 0;
    size_t structSize = sizeof(tescuadrones);

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
    tescuadrones esc = {codigo_escuadron, cantidad_naves, elemento_ataque, potencia_ataque};
    fwrite(&esc, sizeof(esc), 1, file);

    return true;
}

bool actualizar_vulnerabilidades(char *archivo_actualizacion) {
//	if(!verificar_elemento(codigo_elemento) || resistencia < CANTIDAD_MIN || durabilidad < CANTIDAD_MIN){
//
//	}


    return 0;
}

bool distribuir_escuadrones(char *archivo_distribuciones) {
    return 0;
}

bool realizar_ataques(char *archivo_ataques, char *archivo_resumen, bool *fauces_destruida) {
    return 0;
}