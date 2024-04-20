#include "Cargastrabalho.hpp"
#include <chrono>
#include <fstream>
#include <thread>
#include <string>
#include "sort.hpp"
// #include "matplotlibcpp.h"




// namespace plt = matplotlibcpp

void ObterObjeto(Objeto vet[],int size){
    for(int i=0;i<size;i++){
        Objeto obj;
        vet[i] = obj;
    }
}




int main(){

    Objeto vetor[9999];

    int size = sizeof(vetor) / sizeof(vetor[0]);
    
    ObterObjeto(vetor,size);

    std::cout<<"vetor de entrada: "<<std::endl;

    std::this_thread::sleep_for(std::chrono::seconds(2));

    for(int i=0;i<size;i++){
        std::cout<<vetor[i].getChave()<<std::endl;
    }


    std::cout<<std::endl;





    //carga de trabalho
    Cargadetrabalho Carga(size);

    //quantos elementos para ordernar

    std::cout<<"carga de trabalho: "<<std::endl;

    std::cout<<"esse vetor contem "<<Carga.qtsiordenar(vetor)<<" elementos para se ordernar"<<std::endl;;

    //tamanho de algum item do vetor
    std::cout<<"peso em bytes desse vetor e de "<<Carga.Tamanhoembytes(vetor,1)<<std::endl;

    //Olhar se vetor esta bagunçado ordernado ou não ordernado
    Carga.OlharTamnhodovetor(vetor);

    if(Carga.getInversa() == true){
        std::cout<<"vetor esta inversamente ordernado"<<std::endl;
    }

    if(Carga.getIsordenado() == true){
        std::cout<<"vetor esta ordernado "<<std::endl;
    }

    if(Carga.getBaguncado() == true){
        std::cout<<"vetor esta baguncado"<<std::endl;
    }



    std::cout<<std::endl;

    Algoritm::Sorts ordena;


        Objeto aux1[size];
        Objeto aux2[size];
        Objeto aux3[size];
        Objeto aux4[size];
        Objeto aux5[size];
        Objeto aux6[size];
        Objeto aux7[size];
        Objeto aux8[size];
        Objeto aux9[size];



        for(int i=0;i<size;i++){
            aux1[i] = vetor[i];
            aux2[i] = vetor[i];
            aux3[i] = vetor[i];
            aux4[i] = vetor[i];
            aux5[i] = vetor[i];
            aux6[i] = vetor[i];
            aux7[i] = vetor[i];
            aux8[i] = vetor[i];
            aux9[i] = vetor[i];
        }

        std::cout<<"tempo dos algoritmos: "<<std::endl;
     
        auto inicio1 = std::chrono::steady_clock::now();
        ordena.Bubbblesort(aux1,size);
        auto fin1 = std::chrono::steady_clock::now();

        auto duration1 = std::chrono::duration_cast<std::chrono::milliseconds>(fin1 - inicio1).count();

        std::cout<<"tempo do algoritmo bolha em milissegundos e de "<<duration1<<std::endl;

        // ordenação do algorimto bucket
        auto inicio2 = std::chrono::steady_clock::now();
        ordena.Bucketsort(aux2,size);
        auto fin2 = std::chrono::steady_clock::now();



        auto duration2 = std::chrono::duration_cast<std::chrono::milliseconds>(fin2 - inicio2).count();

        std::cout<<"tempo do algoritmo bucket em milissegundos e de "<<duration2<<std::endl;


        // ordernação do algorimto counting sort


        auto inicio3 = std::chrono::steady_clock::now();
        ordena.Coutingsort(aux3,size);
        auto fin3 = std::chrono::steady_clock::now();

        auto duration3 = std::chrono::duration_cast<std::chrono::milliseconds>(fin3 - inicio3).count();

        std::cout<<"tempo do algoritmo counting em milisegundos e de "<<duration3<<std::endl;

        //ordenação do algoritmo insert sort

        auto inicio4 = std::chrono::steady_clock::now();
        ordena.Insertsort(aux4,size);
        auto fin4 = std::chrono::steady_clock::now();

        auto duration4 = std::chrono::duration_cast<std::chrono::milliseconds>(fin4 - inicio4).count();
   
        std::cout<<"tempo do algoritmo insert em milissegundos e de "<<duration4<<std::endl;


        //ordenação do algoritmo quicksort
        auto inicio5 = std::chrono::steady_clock::now();
        ordena.QuickSort(aux5,size);
        auto fin5 = std::chrono::steady_clock::now();

        auto duration5 = std::chrono::duration_cast<std::chrono::microseconds>(fin5 - inicio5).count();

        std::cout<<"tempo do algoritmo quicksort em milisegundos e de "<<duration5<<std::endl;


        // //ordenação do algoritmo do merge sort
        auto inicio6 = std::chrono::steady_clock::now();
        ordena.MergeSort(aux6,0,size-1);
        auto fin6 = std::chrono::steady_clock::now();
        
        auto duration6 = std::chrono::duration_cast<std::chrono::microseconds>(fin6 - inicio6).count();

        std::cout<<"tempo do algoritmo mergesort em milissegundos e de "<<duration6<<std::endl;
    

        // ordenação do algoritmo do radix
        auto inicio7 = std::chrono::steady_clock::now();
        ordena.radixs(aux7,size);
        auto fin7 = std::chrono::steady_clock::now();

        auto duration7 = std::chrono::duration_cast<std::chrono::microseconds>(fin7 - inicio7).count();

        std::cout<<"tempo do algorimto radixsort em milissegundos e de "<<duration7<<std::endl;


        //ordenação do algoritmo do select
        auto inicio8 = std::chrono::steady_clock::now();
        ordena.Selectsort(aux8,size);
        auto fin8 = std::chrono::steady_clock::now();

        auto duration8 = std::chrono::duration_cast<std::chrono::microseconds>(fin8 - inicio8).count();
   
        std::cout<<"tempo do algoritmo selecsort em milissegundos e de "<<duration8<<std::endl;


        //ordenação do algorimto do shellsort
        auto inicio9 = std::chrono::steady_clock::now();
        ordena.Shellsort(aux9,size);
        auto fin9  = std::chrono::steady_clock::now();

        auto duration9 = std::chrono::duration_cast<std::chrono::microseconds>(fin9 - inicio9).count();
    
        std::cout<<"tempo do algoritmo shellsrot em milissegundos e de "<<duration9<<std::endl;




        std::this_thread::sleep_for(std::chrono::seconds(3));

        for(int i=0;i<size;i++){
            std::cout<<aux9[i].getChave()<<std::endl;
        }

         
}