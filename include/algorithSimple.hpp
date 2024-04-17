#ifndef ALGORITMO_HPP
#define ALGORIMTO_HPP

#include <iostream>
#include "objeto.hpp"

namespace ALS{

    class AlgoritmSimple{
        private:


        public:
            AlgoritmSimple();

            void Bubblesort(Objeto obj[],int size);

            void Insertsort(Objeto obj[],int size);        

            void Selectionsort(Objeto obj[],int size);

    };
    
}

#endif