#ifndef QUICKSORT_HPP
#define QUICKSORT_HPP

#include <iostream>
#include "objeto.hpp"

namespace ALQ{

    class QuickSort{
        private:

            int _chave; 
        
        public:

            QuickSort();

            void particionar(int esq,int dir,int *i,int *j,Objeto obj[]);

            void ordena(int esq,int dir,Objeto obj[]);

            void QuickS(Objeto obj[],int n);

    };

}


#endif