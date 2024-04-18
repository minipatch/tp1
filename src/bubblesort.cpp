#include "bubblesort.hpp"


ALB::Bubblesort::Bubblesort(){}


void ALB::Bubblesort::BubbleS(Objeto obj[],int size){
    for(int i = size-1;i>0;i--){

        for(int j=0;j<i;j++){

            if(obj[j+1].getChave()<obj[j].getChave()){

                int aux = obj[j].getChave();

                obj[j].SetObjeto(obj[j+1].getChave());

                obj[j+1].SetObjeto(aux);    
            }

        }

    }   

}

