#include "Cargastrabalho.hpp"


Cargadetrabalho::Cargadetrabalho(int tam){
    //um valor receber o outro
    this->_tam = tam;

}


//quantos itens a ordernar esta certo
int Cargadetrabalho::qtsiordenar(Objeto obj[]){
    int count=0;    

    Objeto aux[_tam];

    for(int i=0;i<_tam;i++){
        aux[i] = obj[i];
    }   

    ALS::AlgoritmSimple buuble;    


    buuble.Bubblesort(aux,_tam);

    for(int i=0;i<_tam;i++){
        if(aux[i].getChave() != obj[i].getChave()){
            count += 1;
        }
    }

    return count;
}


//tamanho em bytes esta certo
size_t Cargadetrabalho::Tamanhoembytes(Objeto obj[],int i){
    
    size_t bytes;
    
    if(i>0){
    
        bytes = sizeof(obj[i-1]);
    }
   
    else if(i == 0){
    
        bytes = sizeof(obj[i]);
    } 

    return bytes;
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





