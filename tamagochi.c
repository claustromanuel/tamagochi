#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_NAME_LEN 20

typedef struct {
    char nombre[MAX_NAME_LEN];
    char* color;
    char* personalidad;
    int hambre;
    int energia;
    int felicidad;
} Tamagotchi;

char* colores[] = {"Rojo", "Azul", "Verde", "Amarillo", "Naranja", "Morado"};
char* personalidades[] = {"Amigable", "Perezoso", "Activo", "Tímido"};

void inicializarTamagotchi(Tamagotchi *tama) {
    printf("Introduce un nombre para tu Tamagotchi: ");
    scanf("%s", tama->nombre);

    tama->color = colores[rand() % 6];
    tama->personalidad = personalidades[rand() % 4];
    tama->hambre = 50;
    tama->energia = 50;
    tama->felicidad = 50;
}

void alimentar(Tamagotchi *tama) {
    tama->hambre -= 10;
    if(tama->hambre < 0) tama->hambre = 0;
}

void jugar(Tamagotchi *tama) {
    if(strcmp(tama->personalidad, "Activo") == 0) {
        tama->felicidad += 15;
    } else {
        tama->felicidad += 10;
    }
    tama->energia -= 10;
    if(tama->energia < 0) tama->energia = 0;
}

void dormir(Tamagotchi *tama) {
    if(strcmp(tama->personalidad, "Perezoso") == 0) {
        tama->energia = 100;
        tama->felicidad += 5;
    } else {
        tama->energia = 80;
    }
}

void mostrarEstado(Tamagotchi tama) {
    printf("Nombre: %s\n", tama.nombre);
    printf("Color: %s\n", tama.color);
    printf("Personalidad: %s\n", tama.personalidad);
    printf("Hambre: %d\n", tama.hambre);
    printf("Energía: %d\n", tama.energia);
    printf("Felicidad: %d\n", tama.felicidad);
}

int main() {
    Tamagotchi tama;
    char eleccion;

    srand(time(NULL));

    inicializarTamagotchi(&tama);

    while(1) {
        printf("\nEstado actual de tu Tamagotchi:\n");
        mostrarEstado(tama);

        printf("\n¿Qué quieres hacer?\n");
        printf("a) Alimentar\n");
        printf("b) Jugar\n");
        printf("c) Dormir\n");
        printf("d) Salir\n");
        scanf(" %c", &eleccion);

        switch(eleccion) {
            case 'a':
                alimentar(&tama);
                break;
            case 'b':
                jugar(&tama);
                break;
            case 'c':
                dormir(&tama);
                break;
            case 'd':
                exit(0);
                break;
            default:
                printf("Elección no válida.\n");
        }

        tama.hambre += rand() % 10;
        if(tama.hambre > 100) tama.hambre = 100;
        tama.felicidad -= rand() % 10;
        if(tama.felicidad < 0) tama.felicidad = 0;

        if(tama.hambre == 100 || tama.energia == 0 || tama.felicidad == 0) {
            printf("¡Oh no! Tu Tamagotchi ha muerto...\n");
            break;
        }
    }

    return 0;
}
