#include "Cargastrabalho.hpp"


Cargadetrabalho::Cargadetrabalho(int tam){
    //um valor receber o outro
    this->_tam = tam;

}


//não esta me dando as movimentações certas 
void Cargadetrabalho::Movimentacoes(Objeto obj[]){
    //como vou medir tenho que medir a quantidade de movimentação que há em cada algoritmo? ou so falar quantos itens tem que ser movimentos?
    int count = 0;


    //acho que essa medida não esta certo
    for(int i=1;i<_tam;i++){
        //quantas movimentações eu faço comparando se o valor anterior é maior do que o valor atual
        if(obj[i].getChave()<obj[i-1].getChave()){
            count++;
        }
        //sem movientações 
        if(obj[i].getChave()>=obj[i-1].getChave()){
            count+=0;
        }
    }


    
    // comentario de quantas movimentações
    if(count == 0){
        std::cout<<count<<std::endl;
    }
    else{
        std::cout<<count<<std::endl;
    }

}

//tem que verificar se ta esta certo
void Cargadetrabalho::Tamanhoembytes(Objeto obj[],int i){
    int pos = i;

    if(i>0){
        pos = pos - 1;
        size_t bytes = sizeof(obj[pos]);
        std::cout<<"tamanho do vetor na posicao "<<pos+1<<" em bytes e: "<<bytes<<std::endl;
    }
   
    else if(i == 0){
        size_t bytes = sizeof(obj[pos]);
        std::cout<<"tamanho do vetor em bytes e: "<<bytes<<std::endl;
    } 
    
}




void Cargadetrabalho::OlharTamnhodovetor(Objeto obj[]){
    int count = 1;
    
    for(int i=1;i<_tam;i++){
        if(obj[i].getChave()<obj[i-1].getChave()){
            count+=0;
        }
        
        else if(obj[i].getChave()>=obj[i-1].getChave()){
        
            count++;
        }
    }
    
    if(count == _tam){
        
        std::cout<<"o vetor é proporcional"<<std::endl;
        
        Isordenado = true;
    }

    if(count == 1){
        
        std::cout<<"o vetor é inversamente proporcional"<<std::endl;
        
        IsinverOrde = true;
    }


    if(count > 1 && count <_tam){
        std::cout<<"vetor esta totalmente bagunçado"<<std::endl;

        Isordenado = false;
        IsinverOrde = false;

    }
    std::cout<<count<<std::endl;
}





