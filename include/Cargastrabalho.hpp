#ifndef CARGA_TRABALHO_HPP
#define CARGA_TRABALHO_HPP

#include <iostream>
#include "objeto.hpp"
#include "algorithSimple.hpp"
#include "quicksort.hpp"
#include "mergesort.hpp"
#include "shellsort.hpp"
#include "counting.hpp"
#include "radixsort.hpp"
#include "bucket.hpp"


class Cargadetrabalho{
    private:
        int _tam;
        // Objeto _obj[];
    

        bool Isordenado = false;

        bool  IsinverOrde = false;
    public:
        Cargadetrabalho(int tam);

        void Movimentacoes(Objeto obj[]);      

        void Tamanhoembytes(Objeto obj[],int i);  

        void OlharTamnhodovetor(Objeto obj[]);
};



#endif