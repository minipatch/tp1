#include "sort.hpp"


Algoritm::Sorts::Sorts(){}

//algoritmos sinples
void Algoritm::Sorts::Bubbblesort(Objeto obj[],int size)
{
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


void Algoritm::Sorts::Insertsort(Objeto obj[],int size)
{
   
    for(int i=1;i<size;i++){
        
        int aux = obj[i].getChave();
        int j = i-1;

        while(aux < obj[j].getChave() && j >=0)
        {
            obj[j+1].SetObjeto(obj[j].getChave());
            --j;
        } 
    
        obj[j+1].SetObjeto(aux);

    }

}


void Algoritm::Sorts::Selectsort(Objeto obj[],int size)
{
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

//quicksort

void Algoritm::Sorts::particionar(int esq,int dir,int *i,int *j,Objeto obj[])
{
    Objeto  pivo,aux;
    *i = esq;
    *j = dir;

    pivo = obj[(*i+*j)/2];

    do{

        while(pivo.getChave() > obj[*i].getChave()){
            (*i)++;
        }
        while(pivo.getChave() < obj[*j].getChave()){
            (*j)--;
        }

        if(*i <= *j){
                //troca dos objetos
                aux = obj[*i];

                obj[*i] = obj[*j];

                obj[*j] = aux; 

                (*i)++;
                (*j)--;
        }

    }while(*i<= *j);
}

void Algoritm::Sorts::ordena(int esq,int dir,Objeto obj[])
{
    int i;
    int j;
    
    particionar(esq,dir,&i,&j,obj);
    
    if(esq<j){
        ordena(esq,j,obj);
    }


    if(i<dir){
        ordena(i,dir,obj);
    }
}

void Algoritm::Sorts::QuickSort(Objeto obj[],int n)
{
    ordena(0,n-1,obj);
}


// merge sort

void Algoritm::Sorts::Merge(Objeto obj[],int esq, int mid,int dir)
{
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


void Algoritm::Sorts::MergeSort(Objeto obj[],int esq,int dir)
{
    if(esq<dir){
        int m = esq +(dir-esq)/2;


        MergeSort(obj,esq,m);
        MergeSort(obj,m+1,dir);

        Merge(obj,esq,m,dir);
    }
}


//counting sort

void Algoritm::Sorts::Coutingsort(Objeto obj[],int size)
{
    Objeto output[MAX_TAM];
    Objeto count[MAX_TAM];
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

//bucket sort

Objeto Algoritm::Sorts::Maxtam(Objeto obj[],int size)
{
    Objeto Max = obj[0];

    for(int i=1;i<size;i++){
        if(obj[i].getChave()>Max.getChave()){
            Max.SetObjeto(obj[i].getChave());
        }
    }
    return Max;
}

void Algoritm::Sorts::Bucketsort(Objeto obj[],int size)
{
    Objeto balde[MAX_TAM+1];

    const int Max = Maxtam(obj,size).getChave();

    for(int i=0;i<=Max;i++){
        balde[i].SetObjeto(0);
    }

    for(int i=0;i<size;i++){
        balde[obj[i].getChave()].incrementar1();
    }


    for(int i=0,j=0;i <= Max;i++){
        while(balde[i].getChave()>0){
            obj[j++].SetObjeto(i);
            balde[i].decrementar1();
        }
    }
}

//shellsort

void Algoritm::Sorts::Shellsort(Objeto obj[],int size)
{
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


//radix sort
Objeto Algoritm::Sorts::getmaxS(Objeto obj[],int size)
{
    Objeto max = obj[0];

    for(int i=1;i<size;i++){
        if(obj[i].getChave()>max.getChave()){
            max = obj[i];
        }

    }
    return max;
}

void Algoritm::Sorts::coutingsortR(Objeto obj[],int size,int place)
{
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

void Algoritm::Sorts::radixs(Objeto obj[],int size)
{
    Objeto max = getmaxS(obj,size);

    for(int place =1; max.getChave()/ place >0;place*=10){
        coutingsortR(obj,size,place);
    }
}