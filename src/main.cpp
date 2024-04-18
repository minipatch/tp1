#include "Cargastrabalho.hpp"
#include <chrono>
#include <thread>

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





    std::string algoritmo;

    std::getline(std::cin,algoritmo);


    //ordena o vetor com buuble
    if(algoritmo == "ALB")
    {
        ALB::Bubblesort a;   
        auto inicio = std::chrono::steady_clock::now();
    
        a.BubbleS(vetor,size);

        auto fin = std::chrono::steady_clock::now();

        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(fin - inicio).count();

        std::cout<<duration<<std::endl<<std::endl;
    }

    else if(algoritmo == "ALBS")
    {
        ALBS::Bucketsort b;

        auto inicio = std::chrono::steady_clock::now();
        b.Buckets(vetor,size);
        auto fin = std::chrono::steady_clock::now();

        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(fin - inicio).count();
        std::cout<<duration<<std::endl<<std::endl;

    }

    else if(algoritmo == "ALCS")
    {
        ALCS::Countingsort c;

        auto inicio = std::chrono::steady_clock::now();
        c.Coutings(vetor,size);
        auto fin = std::chrono::steady_clock::now();

        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(fin - inicio).count();
        std::cout<<duration<<std::endl<<std::endl;

    }

    else if(algoritmo == "ALI")
    {
        ALI::Insertsort i;

        auto inicio = std::chrono::steady_clock::now();
        i.InsertS(vetor,size);
        auto fin = std::chrono::steady_clock::now();

        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(fin - inicio).count(); 
        std::cout<<duration<<std::endl<<std::endl;

    }

    else if(algoritmo == "ALQ")
    {
        ALQ::QuickSort q;

        auto inicio = std::chrono::steady_clock::now();
        q.QuickS(vetor,size);
        std::this_thread::sleep_for (std::chrono::seconds(1));
        auto fin = std::chrono::steady_clock::now();

        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(fin - inicio).count();
        std::cout<<duration<<std::endl<<std::endl;
    }

    else if(algoritmo == "ALM")
    {
        ALM::Mergesort m;

        auto inicio = std::chrono::steady_clock::now();
        m.MergeS(vetor,0,size-1);
        auto fin = std::chrono::steady_clock::now();

        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(fin - inicio).count();
        std::cout<<duration<<std::endl<<std::endl;
        
    }


    else if(algoritmo == "ALRX")
    {
        ALRX::Radixsort r;

        auto inicio = std::chrono::steady_clock::now();
        r.radixs(vetor,size);
        auto fin = std::chrono::steady_clock::now();

        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(fin - inicio).count();
        std::cout<<duration<<std::endl<<std::endl;

    }

    else if(algoritmo == "ALS")
    {
        ALS::Selectionsort s;

        auto inicio = std::chrono::steady_clock::now();
        s.Selections(vetor,size);
        auto fin = std::chrono::steady_clock::now();

        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(fin - inicio).count();
        std::cout<<duration<<std::endl<<std::endl;

    }

    else if(algoritmo == "ALSH")
    {
        ALSH::Shellsort s;

        auto inicio = std::chrono::steady_clock::now();

        s.Shells(vetor,size);
        auto fin = std::chrono::steady_clock::now();

        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(fin - inicio).count();
        std::cout<<duration<<std::endl<<std::endl;
    }


    for(int i=0;i<size;i++){
        std::cout<<vetor[i].getChave()<<std::endl;
    }

    
}