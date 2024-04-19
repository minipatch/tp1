#include "Cargastrabalho.hpp"
#include <chrono>
#include <fstream>
#include <thread>
#include <string>
#include "sort.hpp"
// #include "matplotlibcpp.h"



void InsertS(Objeto obj[],int size){
    for(int i=1;i<size;i++){
        
        int aux = obj[i].getChave();
        int j = i-1;

        while(aux < obj[j].getChave() && j >=0)
        {
            obj[j+1].SetObjeto(obj[j].getChave());
            --j;
        } 
    
        obj[j+1].SetObjeto(aux);

    }
}
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

    for(int i=0;i<size;i++){
        std::cout<<vetor[i].getChave()<<std::endl;
    }



    std::cout<<std::endl;





    //carga de trabalho
    Cargadetrabalho Carga(size);

    //quantos elementos para ordernar
    std::cout<<Carga.qtsiordenar(vetor)<<std::endl;;

    //tamanho de algum item do vetor
    std::cout<<Carga.Tamanhoembytes(vetor,1)<<std::endl;

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

    Algoritm::Sorts s;
        

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
     
        auto inicio1 = std::chrono::steady_clock::now();
        s.Bubbblesort(aux1,size);
        auto fin1 = std::chrono::steady_clock::now();

        auto duration1 = std::chrono::duration_cast<std::chrono::milliseconds>(fin1 - inicio1).count();

        std::cout<<duration1<<std::endl;

        // ordenação do algorimto bucket
        auto inicio2 = std::chrono::steady_clock::now();
        s.Bucketsort(aux2,size);
        auto fin2 = std::chrono::steady_clock::now();



        auto duration2 = std::chrono::duration_cast<std::chrono::milliseconds>(fin2 - inicio2).count();

        std::cout<<duration2<<std::endl;


        // ordernação do algorimto counting sort


        auto inicio3 = std::chrono::steady_clock::now();
        s.Coutingsort(aux3,size);
        auto fin3 = std::chrono::steady_clock::now();

        auto duration3 = std::chrono::duration_cast<std::chrono::milliseconds>(fin3 - inicio3).count();

        std::cout<<duration3<<std::endl;

        //ordenação do algoritmo insert sort

        auto inicio4 = std::chrono::steady_clock::now();
        s.Insertsort(aux4,size);
        auto fin4 = std::chrono::steady_clock::now();

        auto duration4 = std::chrono::duration_cast<std::chrono::milliseconds>(fin4 - inicio4).count();
   
        std::cout<<duration4<<std::endl;


        //ordenação do algoritmo quicksort
        auto inicio5 = std::chrono::steady_clock::now();
        s.QuickSort(aux5,size);
        auto fin5 = std::chrono::steady_clock::now();

        auto duration5 = std::chrono::duration_cast<std::chrono::microseconds>(fin5 - inicio5).count();

        std::cout<<duration5<<std::endl;


        // //ordenação do algoritmo do merge sort
        auto inicio6 = std::chrono::steady_clock::now();
        s.MergeSort(aux6,0,size-1);
        auto fin6 = std::chrono::steady_clock::now();
        
        auto duration6 = std::chrono::duration_cast<std::chrono::microseconds>(fin6 - inicio6).count();

        std::cout<<duration6<<std::endl;
    

        // ordenação do algoritmo do radix
        auto inicio7 = std::chrono::steady_clock::now();
        s.radixs(aux7,size);
        auto fin7 = std::chrono::steady_clock::now();

        auto duration7 = std::chrono::duration_cast<std::chrono::microseconds>(fin7 - inicio7).count();

        std::cout<<duration7<<std::endl;


        //ordenação do algoritmo do select
        auto inicio8 = std::chrono::steady_clock::now();
        s.Selectsort(aux8,size);
        auto fin8 = std::chrono::steady_clock::now();

        auto duration8 = std::chrono::duration_cast<std::chrono::microseconds>(fin8 - inicio8).count();
   
        std::cout<<duration8<<std::endl;


        //ordenação do algorimto do shellsort
        auto inicio9 = std::chrono::steady_clock::now();
        s.Shellsort(aux9,size);
        auto fin9  = std::chrono::steady_clock::now();

        auto duration9 = std::chrono::duration_cast<std::chrono::microseconds>(fin9 - inicio9).count();
    
        std::cout<<duration9<<std::endl;

    
        // for(int i=0;i<size;i++){
        //     std::cout<<aux3[i].getChave()<<std::endl;
        // }
}