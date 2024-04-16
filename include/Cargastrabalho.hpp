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
    
    public:
        Cargadetrabalho(int tam);

        int TamanhodeItens(Objeto obj[]);        



};



#endif