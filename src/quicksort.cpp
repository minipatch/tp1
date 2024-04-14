#include "quicksort.hpp"


ALQ::QuickSort::QuickSort(){}


void ALQ::QuickSort::particionar(int esq,int dir,int *i,int *j,Objeto obj[]){
    Objeto  pivo,aux;
    *i = esq;
    *j = dir;

    pivo = obj[(*i+*j)/2];

    do{

        while(pivo.getChave() > obj[*i].getChave()){
            (*i)++;
        }
        while(pivo.getChave() < obj[*j].getChave()){
            (*j)--;
        }

        if(*i <= *j){
                //troca dos objetos
                aux = obj[*i];

                obj[*i] = obj[*j];

                obj[*j] = aux; 

                (*i)++;
                (*j)--;
        }

    }while(*i<= *j);


}


void ALQ::QuickSort::ordena(int esq,int dir,Objeto obj[]){
    int i;
    int j;
    
    particionar(esq,dir,&i,&j,obj);
    
    if(esq<j){
        ordena(esq,j,obj);
    }


    if(i<dir){
        ordena(i,dir,obj);
    }
}


void ALQ::QuickSort::QuickS(Objeto obj[],int n){
    ordena(0,n-1,obj);
}