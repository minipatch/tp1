#include "objeto.hpp"

Objeto::Objeto(){}

Objeto::Objeto(int chave){
    this->_chave = chave;
}


int Objeto::getChave(){
    return _chave;
}

void Objeto::SetObjeto(int chave){
    _chave = chave;
}

void Objeto::decrementar1(){
    _chave--;
}

void Objeto::incrementar1(){
    _chave++;
}

void Objeto::incrementarn(int n){
    _chave += n;
}
