#include "shellsort.hpp"


ALSH::Shellsort::Shellsort(){}



void ALSH::Shellsort::Shells(Objeto obj[],int size){
    for(int inter = size/2;inter>0;inter/=2){
        
        for(int i=inter;i<size;i++){
            
            Objeto temp = obj[i];
            int j;
            
            for(j=i ; j>=inter && obj[j-inter].getChave()>temp.getChave();j-=inter){
                obj[j] = obj[j-inter];
            }
            
            obj[j] = temp;
        }    
    }
}