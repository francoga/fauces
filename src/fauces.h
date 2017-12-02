#ifndef FAUCES_H
#define FAUCES_H
#include <stdbool.h>
#include <stdio.h>

static const char HIDROGENO= 'H';
static const char YODO= 'I';
static const char CARBONO= 'C';
static const char NITROGENO= 'N';
static const char OXIGENO= 'O';
static const char AZUFRE= 'S';
static const char FOSFORO= 'P';
static const int CANTIDAD_MIN= 0;
static const int A= 65;
static const int Z= 90;
//static const char* NOMBRE_ARCHIVO= "SQUAD.dat";
//static const char* NOMBRE_ARCHIVO1= "VULNERA.dat";


typedef struct maestro_escuadrones{
	char codigo_escuadron;
	int cantidad_naves_escuadron;
	char elemento_ataque;
	int potencia_ataque;
}tescuadrones;

typedef struct maestro_vulnerabilidades{
	char codigo_elemento;
	int resistencia;
	int durabilidad;
}tvulnera;

bool actualizar_escuadrones(char codigo_escuadron, int cantidad_naves, char elemento_ataque, int potencia_ataque);

bool actualizar_vulnerabilidades(char* archivo_actualizacion);

bool distribuir_escuadrones(char* archivo_distribuciones);

bool realizar_ataques(char* archivo_ataques, char* archivo_resumen, bool* fauces_destruida);

#endif
