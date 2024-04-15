#include "bucket.hpp"


ALBS::Bucketsort::Bucketsort(){}

Objeto ALBS::Bucketsort::Maxtam(Objeto obj[],int tam){
    Objeto Max = obj[0];

    for(int i=1;i<tam;i++){
        if(obj[i].getChave()>Max.getChave()){
            Max.SetObjeto(obj[i].getChave());
        }
    }
    return Max;
}


void ALBS::Bucketsort::Buckets(Objeto obj[],int tam){
    Objeto balde[tam+1];

    const int Max = Maxtam(obj,tam).getChave();

    for(int i=0;i<=Max;i++){
        balde[i].SetObjeto(0);
    }

    for(int i=0;i<tam;i++){
        balde[obj[i].getChave()].incrementar1();
    }


    for(int i=0,j=0;i <= Max;i++){
        while(balde[i].getChave()>0){
            obj[j++].SetObjeto(i);
            balde[i].decrementar1();
        }
    }
}
