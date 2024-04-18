#ifndef COUNTING_HPP
#define COUNTING_HPP

#include <iostream>
#include "objeto.hpp"


namespace ALCS{


    class Countingsort{
        private:

        const int MAX_TAM = 100000;
        public:

            Countingsort();

            void Coutings(Objeto obj[],int size);
    };
}






#endif