#include "counting.hpp"

ALCS::Countingsort::Countingsort(){}



void ALCS::Countingsort::Coutings(Objeto obj[],int size){
    Objeto output[10];
    Objeto count[10];
    int max = obj[0].getChave();


    for(int i=1;i<size;i++){
        if(obj[i].getChave()>max){
            max = obj[i].getChave();
        }
    }

    for(int i=0;i<=max;i++){
        count[i] = 0;
    }

    for(int i=0;i<size;i++){
        // int aux = 0;
        // aux += 1;
        count[obj[i].getChave()].incrementar1();
    }

    for(int i=1;i<=max;i++){
        count[i].incrementarn(count[i-1].getChave());
    }

    for(int i=size-1 ; i>=0; i--){
        output[count[obj[i].getChave()].getChave()-1] = obj[i];
        count[obj[i].getChave()].decrementar1();
    }

    for(int i=0;i<size;i++){
        obj[i].SetObjeto(output[i].getChave());
    }
}
    