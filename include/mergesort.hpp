#ifndef MERGESORT_HPP
#define MERGESORT_HPP

#include "objeto.hpp"
#include <iostream>

namespace ALM{
    class Mergesort{
        private:


        public:

            Mergesort();

            void Merge(Objeto obj[],int esq, int mid,int dir);


            void MergeS(Objeto obj[],int esq,int dir);
    
            int tamanho(Objeto obj[]);
    };



};



#endif