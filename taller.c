#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "validar.h"
#include "validar.c"

int main(void) {
  Usuario_t usu;
  printf("Introduce un nombre: ");
  scanf("%s",usu.nombre);
  printf("Introduce un apellido: ");
  scanf("%s",usu.apellido);
  printf("Introduce un username: ");
  scanf("%s",usu.username);
  printf("Introduce un password: ");
  scanf("%s",usu.password);
  usu.userid = rand() % 100;
  
  switch(validar(usu)) {
      case 0 :
         printf("No hubo error\n" );
         break;
      case 1 :
         printf("Username muy corto\n" );
         break;
      case 2 :
         printf("Username muy largo\n" );
         break;
      case 3 :
         printf("Password muy corta\n" );
         break;
      case 4 :
         printf("Password no tiene letras\n" );
         break;
      default :
         printf("Password no tiene digitos\n" );
   }
  printf(" %s %s",usu.nombre,usu.apellido);
  return 0;
}
