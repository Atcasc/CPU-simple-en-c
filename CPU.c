#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int program(FILE *readingFile, int memoria[]);

int main(){
    FILE *readingFile;
    int memoria[20]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19};;
    char cadena[256];
    printf("Introduce la ruta del archivo:");
    scanf(" %[^\n]", cadena);

    readingFile=fopen(cadena,"r");
    if(readingFile==NULL){
        printf("fallo en la apertura del fichero");
        return 1;
    }
    return  program(readingFile,memoria);
}

int program(FILE *readingFile, int memoria[]){
    char linea[32];
    int datos=-1;
    int registro;
    fscanf(readingFile,"%s %d",linea,&datos);
    while(!feof(readingFile)){
        if(strcmp(linea,"LOAD")==0){
            if(datos==-1)printf("Falta un parametro en el LOAD");
            else{
            registro=memoria[datos];
            printf("load hecho\n");
            }
        }else if (strcmp(linea,"STORE")==0){
            if(datos==-1)printf("Falta un parametro en el STORE");
            else{
            memoria[datos]=registro;
            printf("store hecho\n");
            }
        }else if(strcmp(linea,"ADD")==0){
            if(datos==-1)printf("Falta un parametro en el ADD");
            else{
            registro+=memoria[datos];
            printf("add hecho\n");
            }
        }else if(strcmp(linea,"SUB")==0){
            if(datos==-1)printf("Falta un parametro en el SUB");
            else{
            registro-=memoria[datos];
            printf("sub hecho\n");
            }
        }else if(strcmp(linea,"JMP")==0){
            if(datos==-1)printf("Falta un parametro en el JMP");
            else{
                salto(datos,readingFile);
            }
        }
        else{
            printf("Instruccion no reconocida\n");
        }
        datos=-1;
        fscanf(readingFile,"%s %d",linea,&datos);
    }
    return registro;
}


int salto(int posicion,FILE *readingFile){
    return fseek(readingFile,posicion,SEEK_SET);
}

// hacer una funcion para salto y asi la reutilizo en los tres saltos