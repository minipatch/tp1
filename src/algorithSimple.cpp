#include "algorithSimple.hpp"

//construtor do algoritmo
ALS::AlgoritmSimple::AlgoritmSimple(){
    
}


//algoritmo bolhad
int ALS::AlgoritmSimple::Bubblesort(Objeto obj[],int size){
   int count =0;
    for(int i = size-1;i>0;i--){

        for(int j=0;j<i;j++){

            if(obj[j+1].getChave()<obj[j].getChave()){

                int aux = obj[j].getChave();

                obj[j].SetObjeto(obj[j+1].getChave());

                obj[j+1].SetObjeto(aux);    
                count++;
            }

        }

    }   
    return count;
}


//algoritmo de inserção
void ALS::AlgoritmSimple::Insertsort(Objeto obj[],int size){
    for(int i=0;i<size;i++){
        int j = size - 1;
        while(j>0 && obj[j].getChave() < obj[j-1].getChave()){



            int aux = obj[j].getChave();    
            obj[j].SetObjeto(obj[j-1].getChave());
            obj[j-1].SetObjeto(aux);

            j-=1;
        }
    }   
}


//algoritmo de seleção
void ALS::AlgoritmSimple::Selectionsort(Objeto obj[],int size){
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

