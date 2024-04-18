#ifndef SELECTION_HPP
#define SELECTION_HPP

#include <iostream>
#include <chrono>
#include "objeto.hpp"


namespace ALS{
    class Selectionsort{
        private:


        public:
            Selectionsort();


            // o algoritmo orderna e tira o tempo de execução do algoritmo
            void Selections(Objeto obj[],int size);
    };
}



#endif