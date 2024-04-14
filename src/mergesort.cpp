#include "mergesort.hpp"


ALM::Mergesort::Mergesort(){}


void ALM::Mergesort::Merge(Objeto obj[],int esq,int mid,int dir){
    int n1 = mid - esq + 1;
    int n2 = dir - mid;

    Objeto aux[n1];
    Objeto aux2[n2];

    for(int i=0;i<n1;i++){
        aux[i] = obj[esq+i];
    }

    for(int j=0;j<n2;j++){
        aux2[j] = obj[mid+1+j];
    }

    int i;
    int j;
    int k;

    i = 0;
    j =0;
    k = esq;

    while(i<n1 && j<n2){
        
        if(aux[i].getChave() <= aux2[j].getChave()){
            obj[k] = aux[i];
            i++;
        }
        
        else{
            obj[k] = aux2[j];
            j++;
        }
        
        k++;
    }
    
    while(i<n1){
        obj[k] = aux[i];
        i++;
        k++;
    }

    while(j<n2){
        obj[k] = aux2[j];
        j++;
        k++;
    }


}




void ALM::Mergesort::MergeS(Objeto obj[],int esq,int dir ){
    if(esq<dir){
        int m = esq +(dir-esq)/2;


        MergeS(obj,esq,m);
        MergeS(obj,m+1,dir);

        Merge(obj,esq,m,dir);
    }
}