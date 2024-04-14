#include "radixsort.hpp"

ALRX::Radixsort::Radixsort(){

}

Objeto ALRX::Radixsort::getmax(Objeto obj[],int size){
    Objeto max = obj[0];

    for(int i=1;i<size;i++){
        if(obj[i].getChave()>max.getChave()){
            max = obj[i];
        }

    }
    return max;
}

void ALRX::Radixsort::coutingsort(Objeto obj[],int size,int place){
    const int max = 10;

    Objeto output[size];
    Objeto count[max];

    for(int i=0;i<max;i++){
        count[i].SetObjeto(0);
    }


    for(int i=0;i<size;i++){
        count[(obj[i].getChave()/place) %10].incrementar1();
    }

    for(int i=1;i<max;i++){
        count[i].incrementarn(count[i-1].getChave());
    }

    for(int i= size-1;i>=0;i--){
        output[count[(obj[i].getChave()/place) %10].getChave() -1] = obj[i];
        count[(obj[i].getChave()/place)%10].decrementar1();
    }

    for(int i=0;i<size;i++){
        obj[i] = output[i];
    }
}


void ALRX::Radixsort::radixs(Objeto obj[],int size){
    Objeto max = getmax(obj,size);

    for(int place =1; max.getChave()/ place >0;place*=10){
        coutingsort(obj,size,place);
    }
}



