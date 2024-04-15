#ifndef BUCKET_HPP
#define BUCKET_HPP

#include <iostream>
#include "objeto.hpp"


namespace ALBS{
    class Bucketsort{
        private:

        public:
            Bucketsort();

            void Buckets(Objeto obj[],int tam);

            Objeto Maxtam(Objeto obj[],int tam);
        
    };

}




#endif