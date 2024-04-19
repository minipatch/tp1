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

    Algoritm::Sorts s;    

    s.Bubbblesort(aux,_tam);


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

//função verifica se o vetor esta organizado de forma crescente ou decrecente ou bagunçado
void Cargadetrabalho::OlharTamnhodovetor(Objeto obj[]){
    int count1 = 1;
    int count2 = 1;

    for(int i=0;i<_tam-1;i++){
        
        if(obj[i].getChave()>=obj[i+1].getChave()){
            count1 += 1;
        }

        if(obj[i+1].getChave()>=obj[i].getChave()){
            count2 += 1;
        }
    }

    if(count1 == _tam){
        _InversamenteO = true;
    }

    if(count2 == _tam){
        _Isordenado = true;
    }

    else if(count1 != _tam && count2 != _tam){
        _baguncado = true;
    }

}


bool Cargadetrabalho::getIsordenado(){
    return _Isordenado;
}


bool Cargadetrabalho::getInversa(){
    return _InversamenteO;
}

bool Cargadetrabalho::getBaguncado(){
    return _baguncado;
}

