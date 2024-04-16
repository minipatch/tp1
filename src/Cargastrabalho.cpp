#include "Cargastrabalho.hpp"


Cargadetrabalho::Cargadetrabalho(int tam){
    //um valor receber o outro
    this->_tam = tam;

}


int Cargadetrabalho::TamanhodeItens(Objeto obj[]){
    ALS::AlgoritmSimple n;
    int count=0;

    std::cout<<"quantidade de movimentaçõpes do algorimto bubble"<<std::endl;
    count = n.Bubblesort(obj,_tam);
 

    return count;
}