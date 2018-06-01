#include<stdio.h>
#include<stdlib.h>
#include "validar.h"

void mostrarDetalles(Usuario_t *u);

int main(){
    Usuario_t u;

    printf("Nombre: ");
    scanf("%[^\n]s",u.nombre);
    printf("Apellido: ");
    scanf(" %[^\n]s",u.apellido);
    printf("Username: ");
    scanf(" %[^\n]s",u.username);
    printf("Password: ");
    scanf(" %[^\n]s",u.password);

    u.userid=rand();

    /* Enviar codigo que cambia el texto a rojo, escribir y al final regresarlo a normal */
    printf("\e[31m");
    switch(validar(&u)){
        case 1:
            fprintf(stderr,"Username %s tiene menos de 8 caracteres\e[0m\n");
            break;
        case 2:
            fprintf(stderr,"Username %s tiene más de 10 caracteres\e[0m\n");
            break;
        case 3:
            fprintf(stderr,"Password %s tiene menos de 10 caracteres\e[0m\n");
            break;
        case 4:
            fprintf(stderr,"Password %s no tiene letras\e[0m\n");
            break;
        case 5:
            fprintf(stderr,"Password %s no tiene números\e[0m\n");
            break;
        default:
            printf("\e[0m\e[1mUsuario validado!\e[0m\n");
            mostrarDetalles(&u);
            break;
    }
}

void mostrarDetalles(Usuario_t *u){
    printf("Nombre:   %s\n",u->nombre);
    printf("Apellido: %s\n",u->apellido);
    printf("Username: %s\n",u->username);
    printf("Password: %s\n",u->password);
    printf("User ID:  %d\n",u->userid);
}
