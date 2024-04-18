#include "insertsort.hpp"


ALI::Insertsort::Insertsort(){}


void ALI::Insertsort::InsertS(Objeto obj[],int size){
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