#include "selection.hpp"


ALS::Selectionsort::Selectionsort(){}

void ALS::Selectionsort::Selections(Objeto obj[],int size){
    for(int i=0;i<size-1;i++){
        int min = i;
        
        for(int j=(i+1);j<size;j++){
            if(obj[j].getChave()<obj[min].getChave()){
                min = j;
            }
        }


        int aux = obj[i].getChave();
        obj[i].SetObjeto(obj[min].getChave());
        obj[min].SetObjeto(aux);
    }

}