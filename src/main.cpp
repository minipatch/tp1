#include "algorithSimple.hpp"
#include "objeto.hpp"
#include "quicksort.hpp"
#include "mergesort.hpp"
#include "shellsort.hpp"
#include "counting.hpp"
#include "radixsort.hpp"
#include "bucket.hpp"

int tamanho(Objeto vet[]){
    int tam = sizeof(vet) / sizeof(vet[0]);
    return tam;
}


int main(){
    

    Objeto vetor[6];

    Objeto pessoa(5);

    Objeto pessoa0(9);

    Objeto pessoa20(2);

    Objeto pessoa1(3);

    Objeto pessoa2(1); 
    
    Objeto pessoa19(4);

    vetor[0] = pessoa;

    vetor[1] = pessoa1;

    vetor[2] = pessoa2;

    vetor[3] = pessoa0;

    vetor[4] = pessoa20;

    vetor[5] = pessoa19;

    
    int size = sizeof(vetor) / sizeof(vetor[0]);

    for(int i=0;i<6;i++){
        std::cout<<vetor[i].getChave()<<std::endl;
    }

    ALBS::Bucketsort b;


    b.Buckets(vetor,size);

    // ALRX::Radixsort r;

    // r.radixs(vetor,size);




    std::cout<<std::endl;

    for(int i=0;i<6;i++){
        std::cout<<vetor[i].getChave()<<std::endl;
    }

    
}