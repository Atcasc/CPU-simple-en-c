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
    int datos;
    int registro;
    while(fscanf(readingFile,"%s %d",linea,&datos)!=EOF){
        if(strcmp(linea,"LOAD")==0){
            registro=memoria[datos];
            printf("load hecho");
        }else if (strcmp(linea,"STORE")==0){
            memoria[datos]=registro;
            printf("store hecho");
        }else if(strcmp(linea,"ADD")==0){
            registro+=memoria[datos];
            printf("add hecho");
        }else if(strcmp(linea,"SUB")==0){
            registro-=memoria[datos];
            printf("sub hecho");
        }
    }
    return registro;
}
