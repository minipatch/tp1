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
    

        bool _Isordenado = false;

        bool _InversamenteO = false;

        bool _baguncado = false;
    public:
        Cargadetrabalho(int tam);

        int qtsiordenar(Objeto obj[]);      

        size_t Tamanhoembytes(Objeto obj[],int i);  

        void OlharTamnhodovetor(Objeto obj[]);

        bool getIsordenado();

        bool getBaguncado();

        bool getInversa();
};



#endif