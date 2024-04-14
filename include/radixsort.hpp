#ifndef RADIX_HPP
#define RADIX_HPP

#include "objeto.hpp"
#include <iostream>

namespace ALRX{
    
    class Radixsort{
        private:


        public:
            Radixsort();

            Objeto getmax(Objeto obj[],int size);

            void coutingsort(Objeto obj[],int size,int place);

            void radixs(Objeto obj[],int size);

    };


}


#endif