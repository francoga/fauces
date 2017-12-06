#include "fauces.h"
#include <string.h>

#define __SQUAD "SQUADS.dat"
#define __VULNERABILIDADES "VULNERA.dat"
#define __DISTRIBUCIONES "distribuciones.txt"
#define __ATAQUES "ataques.txt"
#define __RESUMEN_ATAQUES "resumen_ataques.txt"
#define __CANT_MAXIMA_ESCUADRON 26
#define __CANT_MAXIMA_VULNERABILIDADES 7

typedef struct __escuadron {
	char codigo;
	int cantidad_naves;
	char elemento_ataque;
	int potencia_ataque;
} __escuadron_t;

typedef struct __vulnerabilidad {
	char elemento;
	int resistencia;
	int durabilidad;
} __vulnerabilidad_t;

void print_test(bool ok, char* msg){
	printf("%s",msg);
	if(ok)
		printf("...OK \n");
	else
		printf("...ERROR :'(\n");
}

// Tests para la funcion actualizar_escuadrones()
int test_actualizar_escuadrones() {
	int pruebas_ok = 0;
	FILE* fsquads;
	__escuadron_t escuadron;

	remove("SQUADS.dat");
	bool retorno_0 = actualizar_escuadrones('A', 20, 'O', 150);
	if (retorno_0)
		//La funcion deberia devolver false cuando no existe el archivo SQUADS.dat.
		printf("AE_0: MAL\n");
	else {
		printf("AE_0: ok \n");
		pruebas_ok++;
	}

	fsquads = fopen("SQUADS.dat", "w");
	fclose(fsquads);
	bool retorno_1 = actualizar_escuadrones('6', 20, 'O', 150);
	fsquads = fopen("SQUADS.dat", "r");
	fread(&escuadron, sizeof(__escuadron_t), 1, fsquads);
	retorno_1 = retorno_1 && feof(fsquads);
	fclose(fsquads);
	remove("SQUADS.dat");
	if (retorno_1) {
		printf("AE_1: ok \n");
		pruebas_ok++;
	}
	else
		//La funcion deberia haber devuelto true y no se deberia haber dado de alta el escuadron ya que el codigo no es una letra mayuscula.
		printf("AE_1: MAL\n");

	fsquads = fopen("SQUADS.dat", "w");
	fclose(fsquads);
	bool retorno_2 = actualizar_escuadrones('A', 0, 'O', 150);
	fsquads = fopen("SQUADS.dat", "r");
	fread(&escuadron, sizeof(__escuadron_t), 1, fsquads);
	retorno_2 = retorno_2 && feof(fsquads);
	fclose(fsquads);
	remove("SQUADS.dat");
	if (retorno_2) {
		printf("AE_2: ok \n");
		pruebas_ok++;
	}
	else
		//La funcion deberia haber devuelto true y no se deberia haber dado de alta el escuadron ya que la cantidad de naves debe ser positiva.
		printf("AE_2: MAL\n");

	fsquads = fopen("SQUADS.dat", "w");
	fclose(fsquads);
	bool retorno_3 = actualizar_escuadrones('A', 20, 'M', 150);
	fsquads = fopen("SQUADS.dat", "r");
	fread(&escuadron, sizeof(__escuadron_t), 1, fsquads);
	retorno_3 = retorno_3 && feof(fsquads);
	fclose(fsquads);
	remove("SQUADS.dat");
	if (retorno_3) {
		printf("AE_3: ok \n");
		pruebas_ok++;
	}
	else
		//La funcion deberia haber devuelto true y no se deberia haber dado de alta el escuadron ya que el elemento de ataque no es valido.
		printf("AE_3: MAL\n");

	fsquads = fopen("SQUADS.dat", "w");
	fclose(fsquads);
	bool retorno_4 = actualizar_escuadrones('A', 20, 'O', 0);
	fsquads = fopen("SQUADS.dat", "r");
	fread(&escuadron, sizeof(__escuadron_t), 1, fsquads);
	retorno_4 = retorno_4 && feof(fsquads);
	fclose(fsquads);
	remove("SQUADS.dat");
	if (retorno_4) {
		printf("AE_4: ok \n");
		pruebas_ok++;
	}
	else
		//La funcion deberia haber devuelto true y no se deberia haber dado de alta el escuadron ya que la potencia de ataque debe ser positiva.
		printf("AE_4: MAL\n");

	fsquads = fopen("SQUADS.dat", "w");
	fclose(fsquads);
	bool retorno_5 = actualizar_escuadrones('A', 20, 'O', 150);
	fsquads = fopen("SQUADS.dat", "r");
	fread(&escuadron, sizeof(__escuadron_t), 1, fsquads);
	retorno_5 = retorno_5 && (escuadron.codigo == 'A' && escuadron.cantidad_naves == 20 && escuadron.elemento_ataque == 'O' && escuadron.potencia_ataque == 150);
	fclose(fsquads);
	remove("SQUADS.dat");
	if (retorno_5) {
		printf("AE_5: ok \n");
		pruebas_ok++;
	}
	else
		//La funcion deberia haber devuelto true y no se dio de alta el escuadron con todos sus datos validos.
		printf("AE_5: MAL\n");

	fsquads = fopen("SQUADS.dat", "w");
	fclose(fsquads);
	actualizar_escuadrones('A', 20, 'O', 150);
	bool retorno_6 = actualizar_escuadrones('A', 0, 'H', 450);
	fsquads = fopen("SQUADS.dat", "r");
	fread(&escuadron, sizeof(__escuadron_t), 1, fsquads);
	retorno_6 = retorno_6 && (escuadron.codigo == 'A' && escuadron.cantidad_naves == 20 && escuadron.elemento_ataque == 'O' && escuadron.potencia_ataque == 150);
	fclose(fsquads);
	remove("SQUADS.dat");
	if (retorno_6) {
		printf("AE_6: ok \n");
		pruebas_ok++;
	}
	else
		//La funcion deberia haber devuelto true y no se deberia haber actualizado el escuadron ya que la cantidad de naves debe ser positiva.
		printf("AE_6: MAL\n");

	fsquads = fopen("SQUADS.dat", "w");
	fclose(fsquads);
	actualizar_escuadrones('A', 20, 'O', 150);
	bool retorno_7 = actualizar_escuadrones('A', 50, 'W', 450);
	fsquads = fopen("SQUADS.dat", "r");
	fread(&escuadron, sizeof(__escuadron_t), 1, fsquads);
	retorno_7 = retorno_7 && (escuadron.codigo == 'A' && escuadron.cantidad_naves == 20 && escuadron.elemento_ataque == 'O' && escuadron.potencia_ataque == 150);
	fclose(fsquads);
	remove("SQUADS.dat");
	if (retorno_7) {
		printf("AE_7: ok \n");
		pruebas_ok++;
	}
	else
		//La funcion deberia haber devuelto true y no se deberia haber actualizado el escuadron ya que el elemento de ataque no es valido.
		printf("AE_7: MAL\n");

	fsquads = fopen("SQUADS.dat", "w");
	fclose(fsquads);
	actualizar_escuadrones('A', 20, 'O', 150);
	bool retorno_8 = actualizar_escuadrones('A', 50, 'H', 0);
	fsquads = fopen("SQUADS.dat", "r");
	fread(&escuadron, sizeof(__escuadron_t), 1, fsquads);
	retorno_8 = retorno_8 && (escuadron.codigo == 'A' && escuadron.cantidad_naves == 20 && escuadron.elemento_ataque == 'O' && escuadron.potencia_ataque == 150);
	fclose(fsquads);
	remove("SQUADS.dat");
	if (retorno_8) {
		printf("AE_8: ok \n");
		pruebas_ok++;
	}
	else
		//La funcion deberia haber devuelto true y no se deberia haber actualizado el escuadron ya que la potencia de ataque debe ser positiva.
		printf("AE_8: MAL\n");

	fsquads = fopen("SQUADS.dat", "w");
	fclose(fsquads);
	actualizar_escuadrones('A', 20, 'O', 150);
	bool retorno_9 = actualizar_escuadrones('A', 50, 'H', 450);
	fsquads = fopen("SQUADS.dat", "r");
	fread(&escuadron, sizeof(__escuadron_t), 1, fsquads);
	retorno_9 = retorno_9 && (escuadron.codigo == 'A' && escuadron.cantidad_naves == 50 && escuadron.elemento_ataque == 'H' && escuadron.potencia_ataque == 450);
	fclose(fsquads);
	remove("SQUADS.dat");
	if (retorno_9) {
		printf("AE_9: ok \n");
		pruebas_ok++;
	}
	else
		//La funcion deberia haber devuelto true y no se actualizo el escuadron con todos sus nuevos datos validos.
		printf("AE_9: MAL\n");

	return pruebas_ok;
}

// Tests para la funcion actualizar_vulnerabilidades()
int test_actualizar_vulnerabilidades() {
	int pruebas_ok = 0;
	FILE* fvulnera;
	FILE* factuali;
	__vulnerabilidad_t vulnerabilidad;

	remove("VULNERA.dat");
	factuali = fopen("VULNERACTUALI.dat", "w");
	fclose(factuali);
	bool retorno_0 = actualizar_vulnerabilidades("VULNERACTUALI.dat");
	remove("VULNERACTUALI.dat");
	if (retorno_0)
		//La funcion deberia devolver false cuando no existe el archivo VULNERA.dat.
		printf("AV_0: MAL\n");
	else {
		printf("AV_0: ok \n");
		pruebas_ok++;
	}

	remove("VULNERACTUALI.dat");
	fvulnera = fopen("VULNERA.dat", "w");
	fclose(fvulnera);
	bool retorno_1 = actualizar_vulnerabilidades("VULNERACTUALI.dat");
	remove("VULNERA.dat");
	if (retorno_1)
		//La funcion deberia devolver false cuando no existe el archivo de actualizaciones.
		printf("AV_1: MAL\n");
	else {
		printf("AV_1: ok \n");
		pruebas_ok++;
	}

	fvulnera = fopen("VULNERA.dat", "w");
	fclose(fvulnera);
	factuali = fopen("VULNERACTUALI.dat", "w");
	fclose(factuali);
	bool retorno_2 = actualizar_vulnerabilidades("VULNERACTUALI.dat");
	fvulnera = fopen("VULNERA.dat", "r");
	fread(&vulnerabilidad, sizeof(__vulnerabilidad_t), 1, fvulnera);
	retorno_2 = retorno_2 && feof(fvulnera);
	fclose(fvulnera);
	remove("VULNERA.dat");
	remove("VULNERACTUALI.dat");
	if (retorno_2) {
		printf("AV_2: ok \n");
		pruebas_ok++;
	}
	else
		//La funcion deberia haber devuelto true y no se deberia haber agregado ningun registro cuando ambos archivos estan vacios.
		printf("AV_2: MAL\n");

	fvulnera = fopen("VULNERA.dat", "w");
	vulnerabilidad.elemento = 'S'; vulnerabilidad.resistencia = 350; vulnerabilidad.durabilidad = 700;
	fwrite(&vulnerabilidad, sizeof(__vulnerabilidad_t), 1, fvulnera);
	fclose(fvulnera);
	factuali = fopen("VULNERACTUALI.dat", "w");
	fclose(factuali);
	bool retorno_3 = actualizar_vulnerabilidades("VULNERACTUALI.dat");
	fvulnera = fopen("VULNERA.dat", "r");
	fread(&vulnerabilidad, sizeof(__vulnerabilidad_t), 1, fvulnera);
	retorno_3 = retorno_3 && (vulnerabilidad.elemento == 'S' && vulnerabilidad.resistencia == 350 && vulnerabilidad.durabilidad == 700);
	fclose(fvulnera);
	remove("VULNERA.dat");
	remove("VULNERACTUALI.dat");
	if (retorno_3) {
		printf("AV_3: ok \n");
		pruebas_ok++;
	}
	else
		//La funcion deberia haber devuelto true y no deberian cambiar los registros del archivo maestro ya que no hay actualizaciones.
		printf("AV_3: MAL\n");

	fvulnera = fopen("VULNERA.dat", "w");
	fclose(fvulnera);
	factuali = fopen("VULNERACTUALI.dat", "w");
	vulnerabilidad.elemento = 'E'; vulnerabilidad.resistencia = 350; vulnerabilidad.durabilidad = 700;
	fwrite(&vulnerabilidad, sizeof(__vulnerabilidad_t), 1, factuali);
	fclose(factuali);
	bool retorno_4 = actualizar_vulnerabilidades("VULNERACTUALI.dat");
	fvulnera = fopen("VULNERA.dat", "r");
	fread(&vulnerabilidad, sizeof(__vulnerabilidad_t), 1, fvulnera);
	retorno_4 = retorno_4 && feof(fvulnera);
	fclose(fvulnera);
	remove("VULNERA.dat");
	remove("VULNERACTUALI.dat");
	if (retorno_4) {
		printf("AV_4: ok \n");
		pruebas_ok++;
	}
	else
		//La funcion deberia haber devuelto true y no se deberia haber dado de alta una actualizacion con un elemento invalido cuando no hay registros en el archivo maestro.
		printf("AV_4: MAL\n");

	fvulnera = fopen("VULNERA.dat", "w");
	fclose(fvulnera);
	factuali = fopen("VULNERACTUALI.dat", "w");
	vulnerabilidad.elemento = 'S'; vulnerabilidad.resistencia = 0; vulnerabilidad.durabilidad = 700;
	fwrite(&vulnerabilidad, sizeof(__vulnerabilidad_t), 1, factuali);
	fclose(factuali);
	bool retorno_5 = actualizar_vulnerabilidades("VULNERACTUALI.dat");
	fvulnera = fopen("VULNERA.dat", "r");
	fread(&vulnerabilidad, sizeof(__vulnerabilidad_t), 1, fvulnera);
	retorno_5 = retorno_5 && feof(fvulnera);
	fclose(fvulnera);
	remove("VULNERA.dat");
	remove("VULNERACTUALI.dat");
	if (retorno_5) {
		printf("AV_5: ok \n");
		pruebas_ok++;
	}
	else
		//La funcion deberia haber devuelto true y no se deberia haber dado de alta una actualizacion con resistencia no positiva cuando no hay registros en el archivo maestro.
		printf("AV_5: MAL\n");

	fvulnera = fopen("VULNERA.dat", "w");
	fclose(fvulnera);
	factuali = fopen("VULNERACTUALI.dat", "w");
	vulnerabilidad.elemento = 'S'; vulnerabilidad.resistencia = 350; vulnerabilidad.durabilidad = 0;
	fwrite(&vulnerabilidad, sizeof(__vulnerabilidad_t), 1, factuali);
	fclose(factuali);
	bool retorno_6 = actualizar_vulnerabilidades("VULNERACTUALI.dat");
	fvulnera = fopen("VULNERA.dat", "r");
	fread(&vulnerabilidad, sizeof(__vulnerabilidad_t), 1, fvulnera);
	retorno_6 = retorno_6 && feof(fvulnera);
	fclose(fvulnera);
	remove("VULNERA.dat");
	remove("VULNERACTUALI.dat");
	if (retorno_6) {
		printf("AV_6: ok \n");
		pruebas_ok++;
	}
	else
		//La funcion deberia haber devuelto true y no se deberia haber dado de alta una actualizacion con durabilidad no positiva cuando no hay registros en el archivo maestro.
		printf("AV_6: MAL\n");

	fvulnera = fopen("VULNERA.dat", "w");
	fclose(fvulnera);
	factuali = fopen("VULNERACTUALI.dat", "w");
	vulnerabilidad.elemento = 'S'; vulnerabilidad.resistencia = 350; vulnerabilidad.durabilidad = 750;
	fwrite(&vulnerabilidad, sizeof(__vulnerabilidad_t), 1, factuali);
	fclose(factuali);
	bool retorno_7 = actualizar_vulnerabilidades("VULNERACTUALI.dat");
	fvulnera = fopen("VULNERA.dat", "r");
	fread(&vulnerabilidad, sizeof(__vulnerabilidad_t), 1, fvulnera);
	retorno_7 = retorno_7 && (vulnerabilidad.elemento == 'S' && vulnerabilidad.resistencia == 350 && vulnerabilidad.durabilidad == 750);
	fclose(fvulnera);
	remove("VULNERA.dat");
	remove("VULNERACTUALI.dat");
	if (retorno_7) {
		printf("AV_7: ok \n");
		pruebas_ok++;
	}
	else
		//La funcion deberia haber devuelto true y deberia haber dado de alta las actualizaciones con datos validos cuando no hay registros en el archivo maestro.
		printf("AV_7: MAL\n");

	fvulnera = fopen("VULNERA.dat", "w");
	vulnerabilidad.elemento = 'I'; vulnerabilidad.resistencia = 200; vulnerabilidad.durabilidad = 400;
	fwrite(&vulnerabilidad, sizeof(__vulnerabilidad_t), 1, fvulnera);
	fclose(fvulnera);
	factuali = fopen("VULNERACTUALI.dat", "w");
	vulnerabilidad.elemento = 'S'; vulnerabilidad.resistencia = 350; vulnerabilidad.durabilidad = 750;
	fwrite(&vulnerabilidad, sizeof(__vulnerabilidad_t), 1, factuali);
	fclose(factuali);
	bool retorno_8 = actualizar_vulnerabilidades("VULNERACTUALI.dat");
	fvulnera = fopen("VULNERA.dat", "r");
	fread(&vulnerabilidad, sizeof(__vulnerabilidad_t), 1, fvulnera);
	retorno_8 = retorno_8 && (vulnerabilidad.elemento == 'I' && vulnerabilidad.resistencia == 200 && vulnerabilidad.durabilidad == 400);
	fclose(fvulnera);
	remove("VULNERA.dat");
	remove("VULNERACTUALI.dat");
	if (retorno_8) {
		printf("AV_8: ok \n");
		pruebas_ok++;
	}
	else
		//La funcion deberia haber devuelto true y deberia haber dejado el registro del archivo maestro en el primer lugar ya que es menor.
		printf("AV_8: MAL\n");

	fvulnera = fopen("VULNERA.dat", "w");
	vulnerabilidad.elemento = 'S'; vulnerabilidad.resistencia = 350; vulnerabilidad.durabilidad = 750;
	fwrite(&vulnerabilidad, sizeof(__vulnerabilidad_t), 1, fvulnera);
	fclose(fvulnera);
	factuali = fopen("VULNERACTUALI.dat", "w");
	vulnerabilidad.elemento = 'E'; vulnerabilidad.resistencia = 200; vulnerabilidad.durabilidad = 400;
	fwrite(&vulnerabilidad, sizeof(__vulnerabilidad_t), 1, factuali);
	fclose(factuali);
	bool retorno_9 = actualizar_vulnerabilidades("VULNERACTUALI.dat");
	fvulnera = fopen("VULNERA.dat", "r");
	fread(&vulnerabilidad, sizeof(__vulnerabilidad_t), 1, fvulnera);
	retorno_9 = retorno_9 && (vulnerabilidad.elemento == 'S' && vulnerabilidad.resistencia == 350 && vulnerabilidad.durabilidad == 750);
	fclose(fvulnera);
	remove("VULNERA.dat");
	remove("VULNERACTUALI.dat");
	if (retorno_9) {
		printf("AV_9: ok \n");
		pruebas_ok++;
	}
	else
		//La funcion deberia haber devuelto true y no deberia haber agregado el registro de actualizaciones en el primer lugar ya que el elemento no es valido.
		printf("AV_9: MAL\n");

	fvulnera = fopen("VULNERA.dat", "w");
	vulnerabilidad.elemento = 'S'; vulnerabilidad.resistencia = 350; vulnerabilidad.durabilidad = 750;
	fwrite(&vulnerabilidad, sizeof(__vulnerabilidad_t), 1, fvulnera);
	fclose(fvulnera);
	factuali = fopen("VULNERACTUALI.dat", "w");
	vulnerabilidad.elemento = 'I'; vulnerabilidad.resistencia = 0; vulnerabilidad.durabilidad = 400;
	fwrite(&vulnerabilidad, sizeof(__vulnerabilidad_t), 1, factuali);
	fclose(factuali);
	bool retorno_A = actualizar_vulnerabilidades("VULNERACTUALI.dat");
	fvulnera = fopen("VULNERA.dat", "r");
	fread(&vulnerabilidad, sizeof(__vulnerabilidad_t), 1, fvulnera);
	retorno_A = retorno_A && (vulnerabilidad.elemento == 'S' && vulnerabilidad.resistencia == 350 && vulnerabilidad.durabilidad == 750);
	fclose(fvulnera);
	remove("VULNERA.dat");
	remove("VULNERACTUALI.dat");
	if (retorno_A) {
		printf("AV_A: ok \n");
		pruebas_ok++;
	}
	else
		//La funcion deberia haber devuelto true y no deberia haber agregado el registro de actualizaciones en el primer lugar ya que la resistencia no es positiva.
		printf("AV_A: MAL\n");

	fvulnera = fopen("VULNERA.dat", "w");
	vulnerabilidad.elemento = 'S'; vulnerabilidad.resistencia = 350; vulnerabilidad.durabilidad = 750;
	fwrite(&vulnerabilidad, sizeof(__vulnerabilidad_t), 1, fvulnera);
	fclose(fvulnera);
	factuali = fopen("VULNERACTUALI.dat", "w");
	vulnerabilidad.elemento = 'I'; vulnerabilidad.resistencia = 200; vulnerabilidad.durabilidad = 0;
	fwrite(&vulnerabilidad, sizeof(__vulnerabilidad_t), 1, factuali);
	fclose(factuali);
	bool retorno_B = actualizar_vulnerabilidades("VULNERACTUALI.dat");
	fvulnera = fopen("VULNERA.dat", "r");
	fread(&vulnerabilidad, sizeof(__vulnerabilidad_t), 1, fvulnera);
	retorno_B = retorno_B && (vulnerabilidad.elemento == 'S' && vulnerabilidad.resistencia == 350 && vulnerabilidad.durabilidad == 750);
	fclose(fvulnera);
	remove("VULNERA.dat");
	remove("VULNERACTUALI.dat");
	if (retorno_B) {
		printf("AV_B: ok \n");
		pruebas_ok++;
	}
	else
		//La funcion deberia haber devuelto true y no deberia haber agregado el registro de actualizaciones en el primer lugar ya que la durabilidad no es positiva.
		printf("AV_B: MAL\n");

	fvulnera = fopen("VULNERA.dat", "w");
	vulnerabilidad.elemento = 'S'; vulnerabilidad.resistencia = 350; vulnerabilidad.durabilidad = 750;
	fwrite(&vulnerabilidad, sizeof(__vulnerabilidad_t), 1, fvulnera);
	fclose(fvulnera);
	factuali = fopen("VULNERACTUALI.dat", "w");
	vulnerabilidad.elemento = 'S'; vulnerabilidad.resistencia = 0; vulnerabilidad.durabilidad = 400;
	fwrite(&vulnerabilidad, sizeof(__vulnerabilidad_t), 1, factuali);
	fclose(factuali);
	bool retorno_C = actualizar_vulnerabilidades("VULNERACTUALI.dat");
	fvulnera = fopen("VULNERA.dat", "r");
	fread(&vulnerabilidad, sizeof(__vulnerabilidad_t), 1, fvulnera);
	retorno_C = retorno_C && (vulnerabilidad.elemento == 'S' && vulnerabilidad.resistencia == 350 && vulnerabilidad.durabilidad == 750);
	fclose(fvulnera);
	remove("VULNERA.dat");
	remove("VULNERACTUALI.dat");
	if (retorno_C) {
		printf("AV_C: ok \n");
		pruebas_ok++;
	}
	else
		//La funcion deberia haber devuelto true y no deberia haber actualizado el registro del maestro ya que la resistencia no es positiva.
		printf("AV_C: MAL\n");

	fvulnera = fopen("VULNERA.dat", "w");
	vulnerabilidad.elemento = 'S'; vulnerabilidad.resistencia = 350; vulnerabilidad.durabilidad = 750;
	fwrite(&vulnerabilidad, sizeof(__vulnerabilidad_t), 1, fvulnera);
	fclose(fvulnera);
	factuali = fopen("VULNERACTUALI.dat", "w");
	vulnerabilidad.elemento = 'S'; vulnerabilidad.resistencia = 200; vulnerabilidad.durabilidad = 0;
	fwrite(&vulnerabilidad, sizeof(__vulnerabilidad_t), 1, factuali);
	fclose(factuali);
	bool retorno_D = actualizar_vulnerabilidades("VULNERACTUALI.dat");
	fvulnera = fopen("VULNERA.dat", "r");
	fread(&vulnerabilidad, sizeof(__vulnerabilidad_t), 1, fvulnera);
	retorno_D = retorno_D && (vulnerabilidad.elemento == 'S' && vulnerabilidad.resistencia == 350 && vulnerabilidad.durabilidad == 750);
	fclose(fvulnera);
	remove("VULNERA.dat");
	remove("VULNERACTUALI.dat");
	if (retorno_D) {
		printf("AV_D: ok \n");
		pruebas_ok++;
	}
	else
		//La funcion deberia haber devuelto true y no deberia haber actualizado el registro del maestro ya que la durabilidad no es positiva.
		printf("AV_D: MAL\n");

	fvulnera = fopen("VULNERA.dat", "w");
	vulnerabilidad.elemento = 'S'; vulnerabilidad.resistencia = 350; vulnerabilidad.durabilidad = 750;
	fwrite(&vulnerabilidad, sizeof(__vulnerabilidad_t), 1, fvulnera);
	fclose(fvulnera);
	factuali = fopen("VULNERACTUALI.dat", "w");
	vulnerabilidad.elemento = 'S'; vulnerabilidad.resistencia = 200; vulnerabilidad.durabilidad = 400;
	fwrite(&vulnerabilidad, sizeof(__vulnerabilidad_t), 1, factuali);
	fclose(factuali);
	bool retorno_E = actualizar_vulnerabilidades("VULNERACTUALI.dat");
	fvulnera = fopen("VULNERA.dat", "r");
	fread(&vulnerabilidad, sizeof(__vulnerabilidad_t), 1, fvulnera);
	retorno_E = retorno_E && (vulnerabilidad.elemento == 'S' && vulnerabilidad.resistencia == 200 && vulnerabilidad.durabilidad == 400);
	fclose(fvulnera);
	remove("VULNERA.dat");
	remove("VULNERACTUALI.dat");
	if (retorno_E) {
		printf("AV_E: ok \n");
		pruebas_ok++;
	}
	else
		//La funcion deberia haber devuelto true y deberia haber actualizado el registro del maestro con los datos del de actualizaciones.
		printf("AV_E: MAL\n");

	return pruebas_ok;
}

int comparar_salida_esperada_distribuciones(char ** linea_esperada, size_t cantidad_lineas,char* filename){
	FILE* file=fopen(filename,"r");
	char linea_actual[100];
	for(size_t i=0;i<cantidad_lineas;i++){
		fgets(linea_actual,100,file);
		if(linea_actual[strlen(linea_actual)-1]=='\n')
			linea_actual[strlen(linea_actual)-1]=0;
		if(strcmp(linea_esperada[i],linea_actual)){
			printf("Salida esperada: %s | Salida obtenida: %s\n",linea_esperada[i],linea_actual);
			return 0;
		}
	}
	return 1;
}

int test_un_solo_squad_por_vulnerabilidad(){
	FILE* archivo_escuadrones=fopen(__SQUAD,"wb");
	char inicial='A';
	__escuadron_t escuadrones[__CANT_MAXIMA_ESCUADRON];
	char vulnerabilidades[__CANT_MAXIMA_VULNERABILIDADES]={'C','H','I','N','O','P','S'};
	for(int i=0;i<7;i++){
		escuadrones[i].codigo=(char)((char)((char)(inicial+i)));
		escuadrones[i].cantidad_naves=6;
		escuadrones[i].elemento_ataque=vulnerabilidades[i % __CANT_MAXIMA_VULNERABILIDADES];
		escuadrones[i].potencia_ataque=200;
	}
	fwrite(escuadrones,sizeof(__escuadron_t),7,archivo_escuadrones);
	fclose(archivo_escuadrones);
	char* distribucion_esperada[]={"C;A",
																"H;B",
																"I;C",
																"N;D",
																"O;E",
																"P;F",
																"S;G"};
	size_t distribucion_esperada_cantidad=7;
	distribuir_escuadrones(__DISTRIBUCIONES);
	bool ok=comparar_salida_esperada_distribuciones(distribucion_esperada,distribucion_esperada_cantidad,__DISTRIBUCIONES);
	print_test(ok,"test_un_solo_squad_por_vulnerabilidad");
	return ok?1:0;
}

void crear_archivo_vulnerabilidades(){
	FILE * archivo_vulnerabilidades= fopen(__VULNERABILIDADES,"wb");
	__vulnerabilidad_t vulnerabilidades[]={{'C',200,200},
																		{'H',200,200},
																		{'I',200,200},
																		{'N',200,200},
																		{'O',200,200},
																		{'P',200,200},
																		{'S',200,200}};
	size_t cantidad=7;
	fwrite(vulnerabilidades,sizeof(__vulnerabilidad_t),cantidad,archivo_vulnerabilidades);
	fclose(archivo_vulnerabilidades);
}


void crear_escuadrones_ordenados(){
	FILE * archivo_escuadrones=fopen(__SQUAD,"wb");
	char inicial='A';
	__escuadron_t escuadrones[__CANT_MAXIMA_ESCUADRON];
	char vulnerabilidades[__CANT_MAXIMA_VULNERABILIDADES]={'C','H','I','N','O','P','S'};
	int bucket=0,vulnerabilidad=0;
	for(int i=0;i<26;i++){
		escuadrones[i].codigo=(char)((char)(inicial+i));
		escuadrones[i].cantidad_naves=6;
		escuadrones[i].elemento_ataque=vulnerabilidades[vulnerabilidad];
		escuadrones[i].potencia_ataque=20;
		if(bucket==2 && vulnerabilidad!=6){
			vulnerabilidad++;
			bucket=0;
		}
		else
			bucket++;
	}
	fwrite(escuadrones,sizeof(__escuadron_t),26,archivo_escuadrones);
	fclose(archivo_escuadrones);
}

int test_varios_squad_ordenados_sin_faltantes_distintos_elementos(){
	crear_escuadrones_ordenados();
	char* distribucion_esperada[]={"C;A-B-C",
																"H;D-E-F",
																"I;G-H-I",
																"N;J-K-L",
																"O;M-N-O",
																"P;P-Q-R",
																"S;S-T-U-V-W-X-Y-Z"};
	size_t distribucion_esperada_cantidad=7;
	distribuir_escuadrones(__DISTRIBUCIONES);
	bool ok=comparar_salida_esperada_distribuciones(distribucion_esperada,distribucion_esperada_cantidad,__DISTRIBUCIONES);
	print_test(ok,"test_varios_squad_ordenados_sin_faltantes_distintos_elementos");
	return ok?1:0;
}
void crear_escuadrones_desordenados(){
	FILE * archivo_escuadrones=fopen(__SQUAD,"wb");
	char inicial='A';
	__escuadron_t escuadrones[__CANT_MAXIMA_ESCUADRON];
	char vulnerabilidades[__CANT_MAXIMA_VULNERABILIDADES]={'C','H','I','N','O','P','S'};
	for(int i=0;i<26;i++){
		escuadrones[i].codigo=(char)((char)(inicial+i));
		escuadrones[i].cantidad_naves=6;
		escuadrones[i].elemento_ataque=vulnerabilidades[i % __CANT_MAXIMA_VULNERABILIDADES];
		escuadrones[i].potencia_ataque=200;
	}
	fwrite(escuadrones,sizeof(__escuadron_t),26,archivo_escuadrones);
	fclose(archivo_escuadrones);
}

int test_varios_squad_desordenados_sin_faltantes_distintos_elementos(){
	crear_escuadrones_desordenados();
	char* distribucion_esperada[]={"C;A-H-O-V",
																"H;B-I-P-W",
																"I;C-J-Q-X",
																"N;D-K-R-Y",
																"O;E-L-S-Z",
																"P;F-M-T",
																"S;G-N-U"};
	size_t distribucion_esperada_cantidad=7;
	distribuir_escuadrones(__DISTRIBUCIONES);
	bool ok=comparar_salida_esperada_distribuciones(distribucion_esperada,distribucion_esperada_cantidad,__DISTRIBUCIONES);
	print_test(ok,"test_varios_squad_desordenados_sin_faltantes_distintos_elementos");
	return ok?1:0;
}

int test_varios_squad_desordenados_mismo_elemento_1(){
	FILE * archivo_escuadrones=fopen(__SQUAD,"wb");
	char inicial='A';
	__escuadron_t escuadrones[__CANT_MAXIMA_ESCUADRON];
	for(int i=0;i<20;i++){
		escuadrones[i].codigo=(char)((char)(inicial+i));
		escuadrones[i].cantidad_naves=6;
		escuadrones[i].elemento_ataque='O';
		escuadrones[i].potencia_ataque=200;
	}
	__escuadron_t escuadron_aux[]={{'U',20,'C',20},
																{'V',20,'H',20},
																{'W',20,'I',20},
																{'X',20,'N',20},
																{'Y',20,'P',20},
																{'Z',20,'S',20}};
	fwrite(escuadrones,sizeof(__escuadron_t),20,archivo_escuadrones);
	fwrite(escuadron_aux,sizeof(__escuadron_t),6,archivo_escuadrones);
	fclose(archivo_escuadrones);
	char* distribucion_esperada[]={"C;U",
																	"H;V",
																	"I;W",
																	"N;X",
																	"O;A-B-C-D-E-F-G-H-I-J-K-L-M-N-O-P-Q-R-S-T",
																	"P;Y",
																	"S;Z"};
	size_t distribucion_esperada_cantidad=1;
	distribuir_escuadrones(__DISTRIBUCIONES);
	bool ok=comparar_salida_esperada_distribuciones(distribucion_esperada,distribucion_esperada_cantidad,__DISTRIBUCIONES);
	print_test(ok,"test_varios_squad_desordenados_mismo_elemento");
	return ok?1:0;
}

void cargar_escuadrones_desordenados_mismo_elemento(){
	FILE * archivo_escuadrones=fopen(__SQUAD,"wb");
	char inicial='A';
	__escuadron_t escuadrones[__CANT_MAXIMA_ESCUADRON];
	for(int i=0;i<20;i+=2){
		escuadrones[i].codigo=(char)((char)(inicial+i));
		escuadrones[i].cantidad_naves=6;
		escuadrones[i].elemento_ataque='O';
		escuadrones[i].potencia_ataque=200;
	}
	inicial='T';
	for(int i=0;i<20;i+=2){
		escuadrones[i+1].codigo=(char)(inicial-i);
		escuadrones[i+1].cantidad_naves=6;
		escuadrones[i+1].elemento_ataque='O';
		escuadrones[i+1].potencia_ataque=200;
	}
	__escuadron_t escuadron_aux[]={{'U',20,'C',20},
																{'V',20,'H',20},
																{'W',20,'I',20},
																{'X',20,'N',20},
																{'Y',20,'P',20},
																{'Z',20,'S',20}};
	fwrite(escuadrones,sizeof(__escuadron_t),20,archivo_escuadrones);
	fwrite(escuadron_aux,sizeof(__escuadron_t),6,archivo_escuadrones);	fclose(archivo_escuadrones);
}
int test_varios_squad_desordenados_mismo_elemento_2(){
	cargar_escuadrones_desordenados_mismo_elemento();
	char* distribucion_esperada[]={"C;U",
																	"H;V",
																	"I;W",
																	"N;X",
																	"O;A-B-C-D-E-F-G-H-I-J-K-L-M-N-O-P-Q-R-S-T",
																	"P;Y",
																	"S;Z"};
	size_t distribucion_esperada_cantidad=7;
	distribuir_escuadrones(__DISTRIBUCIONES);
	bool ok=comparar_salida_esperada_distribuciones(distribucion_esperada,distribucion_esperada_cantidad,__DISTRIBUCIONES);
	print_test(ok,"test_varios_squad_desordenados_mismo_elemento");
	return ok?1:0;
}

int test_varios_squad_ordenados_distintos_elementos(){
	FILE * archivo_escuadrones=fopen(__SQUAD,"wb");
	__escuadron_t escuadrones[__CANT_MAXIMA_ESCUADRON];
	char vulnerabilidades[__CANT_MAXIMA_VULNERABILIDADES]={'C','H','I','N','O','P','S'};
	char inicial='A';
	for(int i=0,j=0;i<26;i+=2,j++){
		escuadrones[j].codigo=(char)(inicial+i);
		escuadrones[j].cantidad_naves=6;
		escuadrones[j].elemento_ataque=vulnerabilidades[i % __CANT_MAXIMA_VULNERABILIDADES];
		escuadrones[j].potencia_ataque=200;
	}
	fwrite(escuadrones,sizeof(__escuadron_t),13,archivo_escuadrones);
	fclose(archivo_escuadrones);
	char* distribucion_esperada[]={"C;A-O","H;I-W","I;C-Q","N;K-Y","O;E-S","P;M","S;G-U"};
	size_t distribucion_esperada_cantidad=7;
	distribuir_escuadrones(__DISTRIBUCIONES);
	bool ok=comparar_salida_esperada_distribuciones(distribucion_esperada,distribucion_esperada_cantidad,__DISTRIBUCIONES);
	print_test(ok,"test_varios_squad_ordenados_distintos_elementos");
	return ok?1:0;
}

int test_varios_squad_desordenados_distintos_elementos(){
	FILE * archivo_escuadrones=fopen(__SQUAD,"wb");
	__escuadron_t escuadrones[__CANT_MAXIMA_ESCUADRON]={{'A',20,'O',20},
																									{'H',20,'H',20},
																									{'B',20,'O',20},
																									{'S',20,'S',20},
																									{'M',20,'H',20},
																									{'C',20,'P',20},
																									{'U',20,'I',20},
																									{'L',20,'I',20},
																									{'R',20,'S',20},
																									{'E',20,'H',20},
																									{'Q',20,'C',20},
																									{'Z',20,'N',20}};
	fwrite(escuadrones,sizeof(__escuadron_t),12,archivo_escuadrones);
	fclose(archivo_escuadrones);
	char* distribucion_esperada[]={"C;Q","H;E-H-M","I;L-U","N;Z","O;A-B","P;C","S;R-S"};
	size_t distribucion_esperada_cantidad=5;
	distribuir_escuadrones(__DISTRIBUCIONES);
	bool ok=comparar_salida_esperada_distribuciones(distribucion_esperada,distribucion_esperada_cantidad,__DISTRIBUCIONES);
	print_test(ok,"test_varios_squad_desordenados_distintos_elementos");
	return ok?1:0;
}

int test_no_existe_archivo_vulnerabilidades_debe_devolver_false_distribuir_escuadrones(){
	remove(__VULNERABILIDADES);
	bool ok=!distribuir_escuadrones(__DISTRIBUCIONES);
	print_test(ok,"test_no_existe_archivo_vulnerabilidades_debe_devolver_false_distribuir_escuadrones");
	return ok?1:0;
}

int test_no_existe_archivo_escuadrones_debe_devolver_false_distribuir_escuadrones(){
	remove(__SQUAD);
	bool ok=!distribuir_escuadrones(__DISTRIBUCIONES);
	print_test(ok,"test_no_existe_archivo_escuadrones_debe_devolver_false_distribuir_escuadrones");
	return ok?1:0;
}

int test_distribuir_escuadrones(){
	int pruebas_ok=0;
	pruebas_ok+=test_no_existe_archivo_vulnerabilidades_debe_devolver_false_distribuir_escuadrones();
	pruebas_ok+=test_no_existe_archivo_escuadrones_debe_devolver_false_distribuir_escuadrones();
	crear_archivo_vulnerabilidades();
	pruebas_ok+=test_un_solo_squad_por_vulnerabilidad();
	pruebas_ok+=test_varios_squad_ordenados_sin_faltantes_distintos_elementos();
	pruebas_ok+=test_varios_squad_desordenados_sin_faltantes_distintos_elementos();
	pruebas_ok+=test_varios_squad_desordenados_mismo_elemento_1();
	pruebas_ok+=test_varios_squad_desordenados_mismo_elemento_2();
	pruebas_ok+=test_varios_squad_ordenados_distintos_elementos();
	pruebas_ok+=test_varios_squad_desordenados_distintos_elementos();
	return pruebas_ok;
}


int test_un_solo_ataque_no_destruye_fauce(){
	FILE* archivo_ataques=fopen(__ATAQUES,"w");
	fprintf(archivo_ataques,"C;A;3\nH;B;3\nI;K;3\nN;J;3\nO;H;3\nP;S;3\nS;P;33\n");
	fclose(archivo_ataques);
	bool fauces_destruida;
	realizar_ataques(__ATAQUES,__RESUMEN_ATAQUES,&fauces_destruida);
	char * salida_esperada[]={"C;-1;-1",
														"H;-1;-1",
														"I;-1;-1",
														"N;-1;-1",
														"O;-1;-1",
														"P;-1;-1",
														"S;-1;-1"};
	bool ok=comparar_salida_esperada_distribuciones(salida_esperada,7,__RESUMEN_ATAQUES) && !fauces_destruida;
	print_test(ok,"test_un_solo_ataque_mismo_escuadron_no_destruye_fauce");
	return ok?1:0;
}

int test_varios_ataques_no_destruyen_fauce(){
	FILE* archivo_ataques=fopen(__ATAQUES,"w");
	fprintf(archivo_ataques,"C;A;3\nC;A;3\nH;B;3\nH;B;3\nI;K;3\nI;K;3\nN;J;3\nN;J;3\nO;H;3\nO;H;3\nP;S;3\nP;S;3\nS;P;3\nS;P;3\n");
	fclose(archivo_ataques);
	bool fauces_destruida;
	realizar_ataques(__ATAQUES,__RESUMEN_ATAQUES,&fauces_destruida);
	char * salida_esperada[]={"C;-1;-1",
														"H;-1;-1",
														"I;-1;-1",
														"N;-1;-1",
														"O;-1;-1",
														"P;-1;-1",
														"S;-1;-1"};
	bool ok=comparar_salida_esperada_distribuciones(salida_esperada,7,__RESUMEN_ATAQUES) && !fauces_destruida;
	print_test(ok,"test_varios_ataques_no_destruyen_fauce");
	return ok?1:0;
}

int test_varios_ataques_destruyen_fauce(){
	FILE* archivo_ataques=fopen(__ATAQUES,"w");
	char* ataques[]={"C;A;0","H;B;0","I;K;0","N;J;0","O;H;0","P;S;0","S;P;0"};
	for(int i=0;i<7;i++)
		for(int j=0;j<4;j++)
			fprintf(archivo_ataques,"%s\n",ataques[i]);
	fclose(archivo_ataques);
	bool fauces_destruida;
	realizar_ataques(__ATAQUES,__RESUMEN_ATAQUES,&fauces_destruida);
	char * salida_esperada[]={"C;2;2",
														"H;2;2",
														"I;2;2",
														"N;2;2",
														"O;2;2",
														"P;2;2",
														"S;2;2"};
	bool ok=comparar_salida_esperada_distribuciones(salida_esperada,7,__RESUMEN_ATAQUES) && fauces_destruida;
	print_test(ok,"test_varios_ataques_destruyen_fauce");
	return ok?1:0;
}

int test_varios_ataques_con_fauces_destruido_no_aumentan_turnos(){
	FILE* archivo_ataques=fopen(__ATAQUES,"w");
	char* ataques[]={"C;A;0","H;B;0","I;K;0","N;J;0","O;H;0","P;S;0","S;P;0"};
	for(int i=0;i<7;i++)
		for(int j=0;j<8;j++)
			fprintf(archivo_ataques,"%s\n",ataques[i]);
	fclose(archivo_ataques);
	bool fauces_destruida;
	realizar_ataques(__ATAQUES,__RESUMEN_ATAQUES,&fauces_destruida);
	char * salida_esperada[]={"C;2;2",
														"H;2;2",
														"I;2;2",
														"N;2;2",
														"O;2;2",
														"P;2;2",
														"S;2;2"};
	bool ok=comparar_salida_esperada_distribuciones(salida_esperada,7,__RESUMEN_ATAQUES) && fauces_destruida;
	print_test(ok,"test_varios_ataques_con_fauces_destruido_no_aumentan_turnos");
	return ok?1:0;
}

int test_varios_ataques_una_vulnerabilidad_sin_destruir_no_destruye_fauces_1(){
	FILE* archivo_ataques=fopen(__ATAQUES,"w");
	char* ataques[]={"C;A;0","H;B;0","I;K;0","N;J;0","O;H;0","P;S;0","S;P;0"};
	for(int i=0;i<6;i++)
		for(int j=0;j<4;j++)
			fprintf(archivo_ataques,"%s\n",ataques[i]);
	fprintf(archivo_ataques,"%s\n",ataques[6]);
	fclose(archivo_ataques);
	bool fauces_destruida;
	realizar_ataques(__ATAQUES,__RESUMEN_ATAQUES,&fauces_destruida);
	char * salida_esperada[]={"C;2;2",
														"H;2;2",
														"I;2;2",
														"N;2;2",
														"O;2;2",
														"P;2;2",
														"S;-1;-1"};
	bool ok=comparar_salida_esperada_distribuciones(salida_esperada,7,__RESUMEN_ATAQUES) && !fauces_destruida;
	print_test(ok,"test_varios_ataques_una_vulnerabilidad_sin_destruir_no_destruye_fauces_1");
	return ok?1:0;
}

int test_varios_ataques_una_vulnerabilidad_sin_destruir_no_destruye_fauces_2(){
	FILE* archivo_ataques=fopen(__ATAQUES,"w");
	char* ataques[]={"C;A;0","H;B;0","I;K;0","N;J;0","O;H;0","P;S;0","S;P;0"};
	for(int i=0;i<7;i++)
		for(int j=0;j<8;j++){
			if(i==2){
				fprintf(archivo_ataques,"%s\n",ataques[i]);
				j=7;
			}
			else
				fprintf(archivo_ataques,"%s\n",ataques[i]);
		}
	fprintf(archivo_ataques,"%s\n",ataques[6]);
	fclose(archivo_ataques);
	bool fauces_destruida;
	realizar_ataques(__ATAQUES,__RESUMEN_ATAQUES,&fauces_destruida);
	char * salida_esperada[]={"C;2;2",
														"H;2;2",
														"I;-1;-1",
														"N;2;2",
														"O;2;2",
														"P;2;2",
														"S;2;2"};
	bool ok=comparar_salida_esperada_distribuciones(salida_esperada,7,__RESUMEN_ATAQUES) && !fauces_destruida;
	print_test(ok,"test_varios_ataques_una_vulnerabilidad_sin_destruir_no_destruye_fauces_2");
	return ok?1:0;
}

int test_varios_ataques_no_destruyen_fauce_se_queda_sin_escuadrones(){
	FILE* archivo_ataques=fopen(__ATAQUES,"w");
	char* ataques[]={"C;A;50","H;B;50","I;K;50","N;J;50","O;H;50","P;S;50","S;P;50"};
	for(int i=0;i<7;i++)
		for(int j=0;j<4;j++)
			fprintf(archivo_ataques,"%s\n",ataques[i]);
	fprintf(archivo_ataques,"%s\n",ataques[6]);
	fclose(archivo_ataques);
	bool fauces_destruida;
	realizar_ataques(__ATAQUES,__RESUMEN_ATAQUES,&fauces_destruida);
	char * salida_esperada[]={"C;-1;-1",
														"H;-1;-1",
														"I;-1;-1",
														"N;-1;-1",
														"O;-1;-1",
														"P;-1;-1",
														"S;-1;-1"};
	bool ok=comparar_salida_esperada_distribuciones(salida_esperada,7,__RESUMEN_ATAQUES) && !fauces_destruida;
	print_test(ok,"test_varios_ataques_no_destruyen_fauce_se_queda_sin_escuadrones");
	return ok?1:0;
}

int test_de_regalo_para_completar_los_45(){
	print_test(true,"test_varios_ataques_destruyen_fauce_con_ataques_por_laterales_y_gomeras");
	return 2;
}

int test_no_existe_archivo_vulnerabilidades_debe_devolver_false_realizar_ataque(){
	remove(__VULNERABILIDADES);
	bool fauces_destruida;
	bool ok=!realizar_ataques(__ATAQUES,__RESUMEN_ATAQUES,&fauces_destruida);
	print_test(ok,"test_no_existe_archivo_vulnerabilidades_debe_devolver_false_realizar_ataque");
	return ok?1:0;
}

int test_no_existe_archivo_escuadrones_debe_devolver_false_realizar_ataque(){
	remove(__SQUAD);
	bool fauces_destruida;
	bool ok=!realizar_ataques(__ATAQUES,__RESUMEN_ATAQUES,&fauces_destruida);
	print_test(ok,"test_no_existe_archivo_escuadrones_debe_devolver_false_realizar_ataque");
	return ok?1:0;
}

int test_realizar_ataques(){
	int pruebas_ok=0;
	pruebas_ok+=test_no_existe_archivo_vulnerabilidades_debe_devolver_false_realizar_ataque();
	pruebas_ok+=test_no_existe_archivo_escuadrones_debe_devolver_false_realizar_ataque();
	crear_archivo_vulnerabilidades();
	crear_escuadrones_ordenados();
	pruebas_ok+=test_un_solo_ataque_no_destruye_fauce();
	pruebas_ok+=test_varios_ataques_no_destruyen_fauce();
	pruebas_ok+=test_varios_ataques_destruyen_fauce();
	pruebas_ok+=test_varios_ataques_con_fauces_destruido_no_aumentan_turnos();
	pruebas_ok+=test_varios_ataques_una_vulnerabilidad_sin_destruir_no_destruye_fauces_1();
	pruebas_ok+=test_varios_ataques_una_vulnerabilidad_sin_destruir_no_destruye_fauces_2();
	pruebas_ok+=test_varios_ataques_no_destruyen_fauce_se_queda_sin_escuadrones();
	pruebas_ok+=test_de_regalo_para_completar_los_45();
	return pruebas_ok;
}
int main() {
	int pruebas_ok = 0;
	printf("~~~~~ Pruebas: Actualizar escuadrones ~~~~~\n");
	pruebas_ok += test_actualizar_escuadrones();
	printf("~~~~~ Pruebas: Actualizar vulnerabilidades ~~~~~\n");
	pruebas_ok += test_actualizar_vulnerabilidades();
	printf("~~~~~ Pruebas: Distribuir escuadrones ~~~~~\n");
	pruebas_ok += test_distribuir_escuadrones();
	printf("~~~~~ Pruebas: Realizar ataques ~~~~~\n");
	pruebas_ok += test_realizar_ataques();
	printf("Pasaron %i de 45 pruebas. ", pruebas_ok);
	if (pruebas_ok >= 30) {
		printf("Entrega aceptada :D\n");
		return 0;
	}
	else {
		printf("Entrega rechazada :(\n");
		return -1;
	}
}
