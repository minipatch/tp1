#include "algorithSimple.hpp"

//construtor do algoritmo
ALS::AlgoritmSimple::AlgoritmSimple(){}


// algoritmo para realizar algumas trocas 
// void ALS::AlgoritmSimple::Trade(Objeto obj1,Objeto obj2){
//     int aux = obj1.getChave();
//     obj1.SetObjeto(obj2.getChave());
//     obj2.SetObjeto(aux);

// }

//algoritmo bolhad
void ALS::AlgoritmSimple::Bubblesort(Objeto obj[],int size){
    for(int i = size-1;i>0;i--){

        for(int j=0;j<i;j++){

            if(obj[j+1].getChave()<obj[j].getChave()){

                int aux = obj[j].getChave();

                obj[j].SetObjeto(obj[j+1].getChave());

                obj[j+1].SetObjeto(aux);                
                // ALS::AlgoritmSimple::Trade(obj[j].getChave(),obj[j+1].getChave());
            }

        }

    }   

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

