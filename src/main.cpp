#include "Cargastrabalho.hpp"
#include <chrono>

int main(){
    

    Objeto vetor[3];

    Objeto pessoa(2);

    Objeto pessoa1(3);

    Objeto pessoa2(1); 
    

    vetor[0] = pessoa;

    vetor[1] = pessoa1;

    vetor[2] = pessoa2;


    
    int size = sizeof(vetor) / sizeof(vetor[0]);
    
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
    if(algoritmo == "ALB"){
        ALB::Bubblesort a;   
        auto inicio = std::chrono::steady_clock::now();
    
        a.BubbleS(vetor,size);

        auto fin = std::chrono::steady_clock::now();

        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(fin - inicio).count();

        std::cout<<duration<<std::endl<<std::endl;
    }

    else if(algoritmo == "ALBS"){
        ALBS::Bucketsort b;

        auto inicio = std::chrono::steady_clock::now();
        b.Buckets(vetor,size);
        auto fin = std::chrono::steady_clock::now();

        auto duration = std::chrono::duration_cast<std::chrono::seconds>(fin - inicio).count();
    }

    else if(algoritmo == "ALCS"){
        ALCS::Countingsort c;

        auto inicio = std::chrono::steady_clock::now();
        c.Coutings(vetor,size);
        auto fin = std::chrono::steady_clock::now();

        auto duration = std::chrono::duration_cast<std::chrono::seconds>(fin - inicio).count();
    }

    else if(algoritmo == "ALI"){
        ALI::Insertsort i;

        auto inicio = std::chrono::steady_clock::now();
        i.InsertS(vetor,size);
        auto fin = std::chrono::steady_clock::now();

        auto duration = std::chrono::duration_cast<std::chrono::seconds>(fin - inicio).count(); 
    }




    for(int i=0;i<size;i++){
        std::cout<<vetor[i].getChave()<<std::endl;
    }

}