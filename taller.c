#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAXSTR 50

typedef struct Usuario{
 char nombre[MAXSTR];
 char apellido[MAXSTR];
 char username[MAXSTR];
 char password[MAXSTR];
 int userid;
}Usuario_t;
int validar(Usuario_t us);
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
int validar(Usuario_t us){
  if(islower(us.nombre[0])){
    toupper(us.nombre[0]);
  }
  if(islower(us.apellido[0])){
    toupper(us.apellido[0]);
  }
  if(strlen(us.username)<8){
    return 1;

  }
  else if(strlen(us.username)>10){
    return 2;
  }
  else if(strlen(us.password)<10){
    return 3;
  }
  else if(noString(us.password)){
    return 4;
  }
  else if(noInteger(us.password)){
    return 5;
  }
  else{
    return 0;
  }

}
int noString(char palabra[MAXSTR]){
  int iterator;
  for(iterator=0;iterator<strlen(palabra[MAXSTR]);iterator++){
    if(isalpha(palabra[iterator])){
      return 0;
    }
  }
  return 1;
}
int noInteger(char palabra[MAXSTR]){
  int ite;
  for(ite=0;ite<strlen(palabra[MAXSTR]);ite++){
    if(isdigit(palabra[ite])){
      return 0;
    }
  }
  return 1;
}