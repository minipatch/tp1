#ifndef RADIX_HPP
#define RADIX_HPP

#include "objeto.hpp"
#include <iostream>

namespace ALRX{
    
    class Radixsort{
        private:


        public:
            Radixsort();

            void QuicksortB(Objeto obj[],int esq,int dir,int w);

            void sort(Objeto obj[],int esq,int dir);

    };


}


#endif