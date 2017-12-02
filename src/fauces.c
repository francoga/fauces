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


bool actualizar_escuadrones(char codigo_escuadron, int cantidad_naves, char elemento_ataque, int potencia_ataque) {
    if (!verificar_escuadron(codigo_escuadron, elemento_ataque)
        || cantidad_naves < CANTIDAD_MIN
        || potencia_ataque < CANTIDAD_MIN) {
        return false;
    }


    return true;
}

bool actualizar_vulnerabilidades(char* archivo_actualizacion){
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