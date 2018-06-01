#include "validar.h"
#include<ctype.h>
#include<string.h>

int validar(Usuario_t *u)
{
    u->nombre[0]=toupper(u->nombre[0]);
    u->apellido[0]=toupper(u->apellido[0]);

    if(strlen(u->username)<8)
        return 1;
    
    if(strlen(u->username)>10)
        return 2;

    if(strlen(u->password)<10)
        return 3;

    if(countletters(u->password)==0)
        return 4;

    if(countdigits(u->password)==0)
        return 5;

    return 0;
}

int countdigits(char *s){
    int n=0;

    while(*s!='\0'){
        if(isdigit(*s))
            n++;
        s++;
    }
    return n;   
}

int countletters(char *s){
    int n=0;

    while(*s!='\0'){
        if(isalpha(*s))
            n++;
        s++;
    }
    return n;   
}
