#ifndef SORT_HPP
#define SORT_HPP


#include <iostream>
#include "objeto.hpp"

static const int MAX_TAM =  10000;

namespace Algoritm{
    class Sorts{
        private:

            // static constexpr int max_tam =  10000;

        public:

            Sorts();

        //algoritmos simples
            void Bubbblesort(Objeto obj[],int size);

            void Insertsort(Objeto obj[],int size);

            void Selectsort(Objeto obj[],int size);


        // quick sort
        
            void particionar(int esq,int dir,int *i,int *j,Objeto obj[]);

            void ordena(int esq,int dir,Objeto obj[]);

            void QuickSort(Objeto obj[],int n);

        // merge sort

            void Merge(Objeto obj[],int esq, int mid,int dir);

            // int tamanho(Objeto obj[]);

            void MergeSort(Objeto obj[],int esq,int dir);

        //counting sort

            void Coutingsort(Objeto obj[],int size);
        
        // ta com problema
        //bucket sort
            void Bucketsort(Objeto obj[],int tam);

            Objeto Maxtam(Objeto obj[],int tam);

        //shellsrot
            void Shellsort(Objeto obj[],int size);

        //radixsort
            Objeto getmaxS(Objeto obj[],int size);

            void coutingsortR(Objeto obj[],int size,int place);

            void radixs(Objeto obj[],int size);




    };


}




#endif