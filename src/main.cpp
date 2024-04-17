#include "Cargastrabalho.hpp"



int main(){
    

    Objeto vetor[3];

    Objeto pessoa(1);

    Objeto pessoa1(3);

    Objeto pessoa2(3); 
    

    vetor[0] = pessoa;

    vetor[1] = pessoa1;

    vetor[2] = pessoa2;


    
    int size = sizeof(vetor) / sizeof(vetor[0]);

    for(int i=0;i<size;i++){
        std::cout<<vetor[i].getChave()<<std::endl;
    }

    Cargadetrabalho tb(size);    



    std::cout<<std::endl;

    // std::cout<<numorderna<<std::endl;

    // for(int i=0;i<size;i++){
    //     std::cout<<vetor[i].getChave()<<std::endl;
    // }

    std::cout<<tb.qtsiordenar(vetor)<<std::endl;    
}