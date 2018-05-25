#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "validar.h"

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