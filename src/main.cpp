#include "Cargastrabalho.hpp"
#include <chrono>
#include <fstream>
#include <thread>
#include <string>
#include "sort.hpp"
#include <sstream>
#include <limits>
#include <vector>
#include <cstring>



void ObterObjeto(Objeto vet[], int size)
{
    for (int i = 0; i < size; i++)
    {
        Objeto obj;
        vet[i] = obj;
    }
}

void AjustaVetor(Objeto vet[], int size, Objeto aux1[])
{
    for (int i = 0; i < size; i++)
    {
        aux1[i] = vet[i];
    }
}

void printvetor(Objeto vet[],int size){
    for(int i=0;i<size;i++){
        std::cout<<vet[i].getChave()<<std::endl;
    }
}


// Função para converter uma substring em um número inteiro

void obterObjetoOrd(Objeto vet[],int size)
{
    for(int i=0;i<size;i++)
    {
        Objeto obj(i);
        vet[i].SetObjeto(obj.getChave());
    }
}


void ObterObjetoInv(Objeto vet[],int size)
{
    int count = 0;
    for(int i=size-1;i>=0;i--)
    {
        
        Objeto obj(i);
        vet[count].SetObjeto(obj.getChave());
        count++;
    }
}

void printsituation(std::string type){
    
    const char* nomeArquivo = type.c_str();

    // Abrir o arquivo para leitura
    FILE* arquivoaux = fopen(nomeArquivo, "r");
    if (arquivoaux == NULL) {
        std::cerr << "Erro ao abrir o arquivo." << std::endl;
        return;
    }

    char linha[256]; 
    int menorTempos[MAX_TAM]; 
    char melhorAlgoritmo[MAX_TAM][256];

    for (int i = 0; i < MAX_TAM; ++i) {
        menorTempos[i] = 999999;
        strcpy(melhorAlgoritmo[i], "NONE"); 
    }

    fgets(linha, sizeof(linha), arquivoaux);

    while (fgets(linha, sizeof(linha), arquivoaux) != NULL) {
        char* token = strtok(linha, ",");
        int tam = atoi(token);

        token = strtok(NULL, ",");
        char algoritmo[256];
        strcpy(algoritmo, token);

        if (strcmp(algoritmo, "cargatrabalho1") == 0 ||
            strcmp(algoritmo, "cargadetrabalho2") == 0 ||
            strcmp(algoritmo, "cargadetrabalho3") == 0) {
            continue; 
        }

        
        token = strtok(NULL, ",");
        int tempo = atoi(token);

        
        if (tempo < menorTempos[tam]) {
            menorTempos[tam] = tempo;
            strcpy(melhorAlgoritmo[tam], algoritmo); 
        }
    }

    for (int tam = 0; tam < MAX_TAM; ++tam) {
        if (menorTempos[tam] != 999999) {
            std::cout << "Para tamanho " << tam << ", o melhor algoritmo foi: " << melhorAlgoritmo[tam] << std::endl;
        }
    }

    fclose(arquivoaux);


}



int main()
{

    //criando objetos e tirando o o tamanho desses objetos
    Objeto vetorB[4];
    Objeto vetorO[4];
    Objeto vetorI[4];
    
    int size1 = sizeof(vetorB) / sizeof(vetorB[0]);
    int size2 = sizeof(vetorO) / sizeof(vetorO[0]);
    int size3 = sizeof(vetorO) / sizeof(vetorO[0]);


    ObterObjeto(vetorB, size1);
    obterObjetoOrd(vetorO,size2);
    ObterObjetoInv(vetorI,size3);


    
    int numero;
    do{
        std::cout<<"escolha um valor entre 0 "<<size1-1<<" para saber seu tamanho em bytes"<<std::endl;
        std::cin>>numero;
        if(numero<0 || numero >= size1){
            std::cout<<"entrada invalida"<<std::endl;
        }
    }while(numero<0 || numero >= size1);





    std::cout << "vetor de entrada: " << std::endl;

    std::this_thread::sleep_for(std::chrono::seconds(5));

    //imprimindo o vetor bagunçado
    printvetor(vetorB,size1);

    std::cout << std::endl;

    //imprimindo o vetor ordenado
    printvetor(vetorO,size2);


    std::cout << std::endl;

    //imprimindo o vetor inversamente ordenado 

    printvetor(vetorI,size3);

    std::cout << std::endl;





    std::this_thread::sleep_for(std::chrono::seconds(5));


    // carga de trabalho do vetorB
    Cargadetrabalho Carga(size1);
    Cargadetrabalho Carga2(size2);
    Cargadetrabalho Carga3(size3);


    std::cout << "carga de trabalho do vetor baguncado: " << std::endl;

    // quantos elementos para ordernar

    int qtsB = Carga.qtsiordenar(vetorB);

    auto inicioB1 = std::chrono::steady_clock::now();
    Carga.qtsiordenar(vetorB);
    auto finB1 = std::chrono::steady_clock::now();

    std::cout<<"quantidade de elementos para se organizar e de: "<<qtsB<<std::endl;

    auto durationB1 = std::chrono::duration_cast<std::chrono::microseconds>(finB1 - inicioB1).count();

    std::cout<<"duracao de carga de trabalho da quantidade de elementos para se organizar e de: "<<durationB1<<std::endl;

    std::cout<<std::endl;

    // tamanho de algum item do vetor
    size_t tamanhoB = Carga.Tamanhoembytes(vetorB, numero);

    auto inicioB2 = std::chrono::steady_clock::now();
    Carga.Tamanhoembytes(vetorB, 1);
    auto fimB2 = std::chrono::steady_clock::now();

    std::cout<<"tamanho do vetor em bytes é de "<<tamanhoB<<std::endl;

    auto durationB2 = std::chrono::duration_cast<std::chrono::microseconds>(fimB2-inicioB2).count();

    std::cout<<"duracao de carga de trabalho relacionado a tamanho do elemento em bytes e de: "<<durationB2<<std::endl;


    std::cout<<std::endl;

    // Olhar se vetor esta bagunçado ordernado ou não ordernado
    auto inicioB3 = std::chrono::steady_clock::now();
    Carga.OlharTamnhodovetor(vetorB);
    auto finB3 = std::chrono::steady_clock::now();

    auto durationB3 = std::chrono::duration_cast<std::chrono::microseconds>(finB3-inicioB3).count();


    if (Carga.getInversa() == true)
    {
        std::cout << "vetor esta inversamente ordernado" << std::endl;
    }

    if (Carga.getIsordenado() == true)
    {
        std::cout << "vetor esta ordernado " << std::endl;
    }

    if (Carga.getBaguncado() == true)
    {
        std::cout << "vetor esta baguncado" << std::endl;
    }
    std::cout<<std::endl<<"duracao do tempo para saber se o vetor e organizado ou inversamente organizado ou baguncado e de: "<<durationB3<<std::endl;


    std::cout << std::endl;





    std::this_thread::sleep_for(std::chrono::seconds(5));




    // carga de trabalho do vetor ordenado
    std::cout<<"carga do vetor ordenado"<<std::endl;

    int qtsO = Carga2.qtsiordenar(vetorO);

    auto inicioO1 = std::chrono::steady_clock::now();
    Carga2.qtsiordenar(vetorO);
    auto finO1 = std::chrono::steady_clock::now();

    std::cout<<"quantidade de elementos para se organizar e de: "<<qtsO<<std::endl;

    auto durationO1 = std::chrono::duration_cast<std::chrono::microseconds>(finO1 - inicioO1).count();

    std::cout<<"duracao de carga de trabalho da quantidade de elementos para se organizar e de: "<<durationO1<<std::endl;

    std::cout<<std::endl;

    // tamanho de algum item do vetor
    size_t tamanhoO = Carga2.Tamanhoembytes(vetorO, numero);

    auto inicioO2 = std::chrono::steady_clock::now();
    Carga2.Tamanhoembytes(vetorO, 1);
    auto finO2 = std::chrono::steady_clock::now();

    std::cout<<"tamanho do vetor em bytes é de "<<tamanhoO<<std::endl;

    auto durationO2 = std::chrono::duration_cast<std::chrono::microseconds>(finO2-inicioO2).count();

    std::cout<<"duracao de carga de trabalho relacionado a tamanho do elemento em bytes e de: "<<durationO2<<std::endl;


    std::cout<<std::endl;

    // Olhar se vetor esta bagunçado ordernado ou não ordernado
    auto inicioO3 = std::chrono::steady_clock::now();
    Carga2.OlharTamnhodovetor(vetorO);
    auto finO3 = std::chrono::steady_clock::now();

    auto durationO3 = std::chrono::duration_cast<std::chrono::microseconds>(finO3-inicioO3).count();


    if (Carga2.getInversa() == true)
    {
        std::cout << "vetor esta inversamente ordernado" << std::endl;
    }

    if (Carga2.getIsordenado() == true)
    {
        std::cout << "vetor esta ordernado " << std::endl;
    }

    if (Carga2.getBaguncado() == true)
    {
        std::cout << "vetor esta baguncado" << std::endl;
    }
    std::cout<<std::endl<<"duracao do tempo para saber se o vetor e organizado ou inversamente organizado ou baguncado e de: "<<durationO3<<std::endl;




    std::this_thread::sleep_for(std::chrono::seconds(5));


    std::cout<<"carga de trabalho do vetor inversamente ordenado:"<<std::endl;
    //carga de trabalho para vetor inversamente ordenado
    std::cout << std::endl;

    int qtsI = Carga.qtsiordenar(vetorI);

    auto inicioI1 = std::chrono::steady_clock::now();
    Carga3.qtsiordenar(vetorI);
    auto finI1 = std::chrono::steady_clock::now();

    std::cout<<"quantidade de elementos para se organizar e de: "<<qtsI<<std::endl;

    auto durationI1 = std::chrono::duration_cast<std::chrono::microseconds>(finI1 - inicioI1).count();

    std::cout<<"duracao de carga de trabalho da quantidade de elementos para se organizar e de: "<<durationI1<<std::endl;

    std::cout<<std::endl;

    // tamanho de algum item do vetor
    size_t tamanhoI = Carga3.Tamanhoembytes(vetorI, numero);

    auto inicioI2 = std::chrono::steady_clock::now();
    Carga3.Tamanhoembytes(vetorI, 1);
    auto fimI2 = std::chrono::steady_clock::now();

    std::cout<<"tamanho do vetor em bytes é de "<<tamanhoI<<std::endl;

    auto durationI2 = std::chrono::duration_cast<std::chrono::microseconds>(fimI2-inicioI2).count();

    std::cout<<"duracao de carga de trabalho relacionado a tamanho do elemento em bytes e de: "<<durationI2<<std::endl;


    std::cout<<std::endl;

    // Olhar se vetor esta bagunçado ordernado ou não ordernado
    auto inicioI3 = std::chrono::steady_clock::now();
    Carga3.OlharTamnhodovetor(vetorI);
    auto finI3 = std::chrono::steady_clock::now();

    auto durationI3 = std::chrono::duration_cast<std::chrono::microseconds>(finI3 - inicioI3).count();


    if (Carga3.getInversa() == true)
    {
        std::cout << "vetor esta inversamente ordernado" << std::endl;
    }

    if (Carga3.getIsordenado() == true)
    {
        std::cout << "vetor esta ordernado " << std::endl;
    }

    if (Carga3.getBaguncado() == true)
    {
        std::cout << "vetor esta baguncado" << std::endl;
    }
    std::cout<<std::endl<<"duracao do tempo para saber se o vetor e organizado ou inversamente organizado ou baguncado e de: "<<durationI3<<std::endl;


    std::cout << std::endl;
    


    std::this_thread::sleep_for(std::chrono::seconds(5));



    //ordenar e contar tempo dos algoritmos 

    Algoritm::Sorts ordena;

    Objeto aux1[size1];
    Objeto aux2[size1];
    Objeto aux3[size1];
    Objeto aux4[size1];
    Objeto aux5[size1];
    Objeto aux6[size1];
    Objeto aux7[size1];
    Objeto aux8[size1];
    Objeto aux9[size1];

    AjustaVetor(vetorB, size1, aux1);
    AjustaVetor(vetorB, size1, aux2);
    AjustaVetor(vetorB, size1, aux3);
    AjustaVetor(vetorB, size1, aux4);
    AjustaVetor(vetorB, size1, aux5);
    AjustaVetor(vetorB, size1, aux6);
    AjustaVetor(vetorB, size1, aux7);
    AjustaVetor(vetorB, size1, aux8);
    AjustaVetor(vetorB, size1, aux9);

    std::cout << "tempo dos algoritmos Baguncados: " << std::endl;

    auto inicioBB1 = std::chrono::steady_clock::now();
    ordena.Bubbblesort(aux1, size1);
    auto finBB1 = std::chrono::steady_clock::now();

    auto durationBB1 = std::chrono::duration_cast<std::chrono::microseconds>(finBB1 - inicioBB1).count();

    std::cout << "tempo do algoritmo bolha em microsegundos e de " << durationBB1 << std::endl;

    // ordenação do algorimto bucket
    auto inicioBB2 = std::chrono::steady_clock::now();
    ordena.Bucketsort(aux2, size1);
    auto finBB2 = std::chrono::steady_clock::now();

    auto durationBB2 = std::chrono::duration_cast<std::chrono::microseconds>(finBB2 - inicioBB2).count();

    std::cout << "tempo do algoritmo bucket em microsegundos e de " << durationBB2 << std::endl;

    // ordernação do algorimto counting sort

    auto inicioBB3 = std::chrono::steady_clock::now();
    ordena.Coutingsort(aux3, size1);
    auto finBB3 = std::chrono::steady_clock::now();

    auto durationBB3 = std::chrono::duration_cast<std::chrono::microseconds>(finBB3 - inicioBB3).count();

    std::cout << "tempo do algoritmo counting em microsegundos e de " << durationBB3 << std::endl;

    // ordenação do algoritmo insert sort

    auto inicioBB4 = std::chrono::steady_clock::now();
    ordena.Insertsort(aux4, size1);
    auto finBB4 = std::chrono::steady_clock::now();

    auto durationBB4 = std::chrono::duration_cast<std::chrono::microseconds>(finBB4 - inicioBB4).count();

    std::cout << "tempo do algoritmo insert em microsegundos e de " << durationBB4 << std::endl;

    // ordenação do algoritmo quicksort
    auto inicioBB5 = std::chrono::steady_clock::now();
    ordena.QuickSort(aux5, size1);
    auto finBB5 = std::chrono::steady_clock::now();

    auto durationBB5 = std::chrono::duration_cast<std::chrono::microseconds>(finBB5 - inicioBB5).count();

    std::cout << "tempo do algoritmo quicksort em microsegundos e de " << durationBB5 << std::endl;

    // //ordenação do algoritmo do merge sort
    auto inicioBB6 = std::chrono::steady_clock::now();
    ordena.MergeSort(aux6, 0, size1 - 1);
    auto finBB6 = std::chrono::steady_clock::now();

    auto durationBB6 = std::chrono::duration_cast<std::chrono::microseconds>(finBB6 - inicioBB6).count();

    std::cout << "tempo do algoritmo mergesort em microsegundos e de " << durationBB6 << std::endl;

    // ordenação do algoritmo do radix
    auto inicioBB7 = std::chrono::steady_clock::now();
    ordena.radixs(aux7, size1);
    auto finBB7 = std::chrono::steady_clock::now();

    auto durationBB7 = std::chrono::duration_cast<std::chrono::microseconds>(finBB7 - inicioBB7).count();

    std::cout << "tempo do algorimto radixsort em microsegundos e de " << durationBB7 << std::endl;

    // ordenação do algoritmo do select
    auto inicioBB8 = std::chrono::steady_clock::now();
    ordena.Selectsort(aux8, size1);
    auto finBB8 = std::chrono::steady_clock::now();

    auto durationBB8 = std::chrono::duration_cast<std::chrono::microseconds>(finBB8 - inicioBB8).count();

    std::cout << "tempo do algoritmo selecsort em microsegundos e de " << durationBB8 << std::endl;

    // ordenação do algorimto do shellsort
    auto inicioBB9 = std::chrono::steady_clock::now();
    ordena.Shellsort(aux9, size1);
    auto finBB9 = std::chrono::steady_clock::now();

    auto durationBB9 = std::chrono::duration_cast<std::chrono::microseconds>(finBB9 - inicioBB9).count();

    std::cout << "tempo do algoritmo shellsort em microsegundos e de " << durationBB9 << std::endl;

    std::cout<<std::endl;

    if(size1<=50){
        printvetor(aux1,size1);
        std::cout<<std::endl;

        printvetor(aux2,size1);
        std::cout<<std::endl;

        printvetor(aux3,size1);
        std::cout<<std::endl;

        printvetor(aux4,size1);
        std::cout<<std::endl;

        printvetor(aux5,size1);
        std::cout<<std::endl;

        printvetor(aux6,size1);
        std::cout<<std::endl;

        printvetor(aux7,size1);
        std::cout<<std::endl;


        printvetor(aux8,size1);
        std::cout<<std::endl;

        printvetor(aux9,size1);
        std::cout<<std::endl;

    }


    std::this_thread::sleep_for(std::chrono::seconds(10));




    AjustaVetor(vetorO, size2, aux1);
    AjustaVetor(vetorO, size2, aux2);
    AjustaVetor(vetorO, size2, aux3);
    AjustaVetor(vetorO, size2, aux4);
    AjustaVetor(vetorO, size2, aux5);
    AjustaVetor(vetorO, size2, aux6);
    AjustaVetor(vetorO, size2, aux7);
    AjustaVetor(vetorO, size2, aux8);
    AjustaVetor(vetorO, size2, aux9);

    std::cout << "tempo dos algoritmos no caso onde eles estão ordenados: " << std::endl;

    auto inicioOO1 = std::chrono::steady_clock::now();
    ordena.Bubbblesort(aux1, size2);
    auto finOO1 = std::chrono::steady_clock::now();

    auto durationOO1 = std::chrono::duration_cast<std::chrono::microseconds>(finOO1 - inicioOO1).count();

    std::cout << "tempo do algoritmo bolha em microsegundos e de " << durationOO1 << std::endl;

    // ordenação do algorimto bucket
    auto inicioOO2 = std::chrono::steady_clock::now();
    ordena.Bucketsort(aux2, size2);
    auto finOO2 = std::chrono::steady_clock::now();

    auto durationOO2 = std::chrono::duration_cast<std::chrono::microseconds>(finOO2 - inicioOO2).count();

    std::cout << "tempo do algoritmo bucket em microsegundos e de " << durationOO2 << std::endl;

    // ordernação do algorimto counting sort

    auto inicioOO3 = std::chrono::steady_clock::now();
    ordena.Coutingsort(aux3, size2);
    auto finOO3 = std::chrono::steady_clock::now();

    auto durationOO3 = std::chrono::duration_cast<std::chrono::microseconds>(finOO3 - inicioOO3).count();

    std::cout << "tempo do algoritmo counting em microsegundos e de " << durationOO3 << std::endl;

    // ordenação do algoritmo insert sort

    auto inicioOO4 = std::chrono::steady_clock::now();
    ordena.Insertsort(aux4, size2);
    auto finOO4 = std::chrono::steady_clock::now();

    auto durationOO4 = std::chrono::duration_cast<std::chrono::microseconds>(finOO4 - inicioOO4).count();

    std::cout << "tempo do algoritmo insert em microsegundos e de " << durationOO4 << std::endl;

    // ordenação do algoritmo quicksort
    auto inicioOO5 = std::chrono::steady_clock::now();
    ordena.QuickSort(aux5, size2);
    auto finOO5 = std::chrono::steady_clock::now();

    auto durationOO5 = std::chrono::duration_cast<std::chrono::microseconds>(finOO5 - inicioOO5).count();

    std::cout << "tempo do algoritmo quicksort em microsegundos e de " << durationOO5 << std::endl;

    // //ordenação do algoritmo do merge sort
    auto inicioOO6 = std::chrono::steady_clock::now();
    ordena.MergeSort(aux6, 0, size2 - 1);
    auto finOO6 = std::chrono::steady_clock::now();

    auto durationOO6 = std::chrono::duration_cast<std::chrono::microseconds>(finOO6 - inicioOO6).count();

    std::cout << "tempo do algoritmo mergesort em microsegundos e de " << durationOO6 << std::endl;

    // ordenação do algoritmo do radix
    auto inicioOO7 = std::chrono::steady_clock::now();
    ordena.radixs(aux7, size2);
    auto finOO7 = std::chrono::steady_clock::now();

    auto durationOO7 = std::chrono::duration_cast<std::chrono::microseconds>(finOO7 - inicioOO7).count();

    std::cout << "tempo do algorimto radixsort em microsegundos e de " << durationOO7 << std::endl;

    // ordenação do algoritmo do select
    auto inicioOO8 = std::chrono::steady_clock::now();
    ordena.Selectsort(aux8, size2);
    auto finOO8 = std::chrono::steady_clock::now();

    auto durationOO8 = std::chrono::duration_cast<std::chrono::microseconds>(finOO8 - inicioOO8).count();

    std::cout << "tempo do algoritmo selecsort em microsegundos e de " << durationOO8 << std::endl;

    // ordenação do algorimto do shellsort
    auto inicioOO9 = std::chrono::steady_clock::now();
    ordena.Shellsort(aux9, size2);
    auto finOO9 = std::chrono::steady_clock::now();

    auto durationOO9 = std::chrono::duration_cast<std::chrono::microseconds>(finOO9 - inicioOO9).count();

    std::cout << "tempo do algoritmo shellsort em microsegundos e de " << durationOO9 << std::endl;

    std::cout<<std::endl;

    if(size1<=50){
        printvetor(aux1,size1);
        std::cout<<std::endl;

        printvetor(aux2,size1);
        std::cout<<std::endl;

        printvetor(aux3,size1);
        std::cout<<std::endl;

        printvetor(aux4,size1);
        std::cout<<std::endl;

        printvetor(aux5,size1);
        std::cout<<std::endl;

        printvetor(aux6,size1);
        std::cout<<std::endl;

        printvetor(aux7,size1);
        std::cout<<std::endl;


        printvetor(aux8,size1);
        std::cout<<std::endl;

        printvetor(aux9,size1);
        std::cout<<std::endl;

    }


    std::this_thread::sleep_for(std::chrono::seconds(10));


    AjustaVetor(vetorI, size3, aux1);
    AjustaVetor(vetorI, size3, aux2);
    AjustaVetor(vetorI, size3, aux3);
    AjustaVetor(vetorI, size3, aux4);
    AjustaVetor(vetorI, size3, aux5);
    AjustaVetor(vetorI, size3, aux6);
    AjustaVetor(vetorI, size3, aux7);
    AjustaVetor(vetorI, size3, aux8);
    AjustaVetor(vetorI, size3, aux9);

    std::cout << "tempo dos algoritmos inversamente ordenados: " << std::endl;

    auto inicioII1 = std::chrono::steady_clock::now();
    ordena.Bubbblesort(aux1, size3);
    auto finII1 = std::chrono::steady_clock::now();

    auto durationII1 = std::chrono::duration_cast<std::chrono::microseconds>(finII1 - inicioII1).count();

    std::cout << "tempo do algoritmo bolha em microsegundos e de " << durationII1 << std::endl;

    // ordenação do algorimto bucket
    auto inicioII2 = std::chrono::steady_clock::now();
    ordena.Bucketsort(aux2, size3);
    auto finII2 = std::chrono::steady_clock::now();

    auto durationII2 = std::chrono::duration_cast<std::chrono::microseconds>(finII2 - inicioII2).count();

    std::cout << "tempo do algoritmo bucket em microsegundos e de " << durationII2 << std::endl;

    // ordernação do algorimto counting sort

    auto inicioII3 = std::chrono::steady_clock::now();
    ordena.Coutingsort(aux3, size3);
    auto finII3 = std::chrono::steady_clock::now();

    auto durationII3 = std::chrono::duration_cast<std::chrono::microseconds>(finII3 - inicioII3).count();

    std::cout << "tempo do algoritmo counting em microsegundos e de " << durationII3 << std::endl;

    // ordenação do algoritmo insert sort

    auto inicioII4 = std::chrono::steady_clock::now();
    ordena.Insertsort(aux4, size3);
    auto finII4 = std::chrono::steady_clock::now();

    auto durationII4 = std::chrono::duration_cast<std::chrono::microseconds>(finII4 - inicioII4).count();

    std::cout << "tempo do algoritmo insert em microsegundos e de " << durationII4 << std::endl;

    // ordenação do algoritmo quicksort
    auto inicioII5 = std::chrono::steady_clock::now();
    ordena.QuickSort(aux5, size3);
    auto finII5 = std::chrono::steady_clock::now();

    auto durationII5 = std::chrono::duration_cast<std::chrono::microseconds>(finII5 - inicioII5).count();

    std::cout << "tempo do algoritmo quicksort em microsegundos e de " << durationII5 << std::endl;

    // //ordenação do algoritmo do merge sort
    auto inicioII6 = std::chrono::steady_clock::now();
    ordena.MergeSort(aux6, 0, size3 - 1);
    auto finII6 = std::chrono::steady_clock::now();

    auto durationII6 = std::chrono::duration_cast<std::chrono::microseconds>(finII6 - inicioII6).count();

    std::cout << "tempo do algoritmo mergesort em microsegundos e de " << durationII6 << std::endl;

    // ordenação do algoritmo do radix
    auto inicioII7 = std::chrono::steady_clock::now();
    ordena.radixs(aux7, size3);
    auto finII7 = std::chrono::steady_clock::now();

    auto durationII7 = std::chrono::duration_cast<std::chrono::microseconds>(finII7 - inicioII7).count();

    std::cout << "tempo do algorimto radixsort em microsegundos e de " << durationII7 << std::endl;

    // ordenação do algoritmo do select
    auto inicioII8 = std::chrono::steady_clock::now();
    ordena.Selectsort(aux8, size3);
    auto finII8 = std::chrono::steady_clock::now();

    auto durationII8 = std::chrono::duration_cast<std::chrono::microseconds>(finII8 - inicioII8).count();

    std::cout << "tempo do algoritmo selecsort em microsegundos e de " << durationII8 << std::endl;

    // ordenação do algorimto do shellsort
    auto inicioII9 = std::chrono::steady_clock::now();
    ordena.Shellsort(aux9, size3);
    auto finII9 = std::chrono::steady_clock::now();

    auto durationII9 = std::chrono::duration_cast<std::chrono::microseconds>(finII9 - inicioII9).count();

    std::cout << "tempo do algoritmo shellsort em microsegundos e de " << durationII9 << std::endl;

    std::cout<<std::endl;

    if(size1<=50){
        printvetor(aux1,size1);
        std::cout<<std::endl;

        printvetor(aux2,size1);
        std::cout<<std::endl;

        printvetor(aux3,size1);
        std::cout<<std::endl;

        printvetor(aux4,size1);
        std::cout<<std::endl;

        printvetor(aux5,size1);
        std::cout<<std::endl;

        printvetor(aux6,size1);
        std::cout<<std::endl;

        printvetor(aux7,size1);
        std::cout<<std::endl;


        printvetor(aux8,size1);
        std::cout<<std::endl;

        printvetor(aux9,size1);
        std::cout<<std::endl;

    }


    std::this_thread::sleep_for(std::chrono::seconds(10));


    std::ofstream arquivo1("extras/baguncado.csv",std::ofstream::app);


    if(!arquivo1.is_open()){
        std::cerr<<"Erro ao abrir o arquivo! "<<std::endl;
        return 1;
    }

    std::cout<<"salvando os dados do vetor baguncado "<<std::endl;

    arquivo1<<size1<<",cargadetrabalho1,"<<durationB1<<std::endl;
    arquivo1<<size1<<",cargadetrabalho2,"<<durationB2<<std::endl;
    arquivo1<<size1<<",cargadetrabalho3,"<<durationB3<<std::endl;
    arquivo1<<size1<<",bubblesort,"<<durationBB1<<std::endl;
    arquivo1<<size1<<",bucketsort,"<<durationBB2<<std::endl;
    arquivo1<<size1<<",countingsort,"<<durationBB3<<std::endl;
    arquivo1<<size1<<",insertosort,"<<durationBB4<<std::endl;
    arquivo1<<size1<<",quicksort,"<<durationBB5<<std::endl;
    arquivo1<<size1<<",mergesort,"<<durationBB6<<std::endl;
    arquivo1<<size1<<",radixsort,"<<durationBB7<<std::endl;
    arquivo1<<size1<<",selectionsort,"<<durationBB8<<std::endl;
    arquivo1<<size1<<",shellsort,"<<durationBB9<<std::endl;

    arquivo1.close();


    std::this_thread::sleep_for(std::chrono::seconds(5));

    std::cout<<"salvando os dados do vetor ordenado "<<std::endl;

    std::ofstream arquivo2("extras/ordenado.csv",std::ofstream::app);

    if(!arquivo2.is_open()){
        std::cerr<<"Errro ao abrir ao arquivo! "<<std::endl;
        return 1; 
    }


    //salvando os tempo das cargas de trabalho em um arquivo


    // salvando arquivos ordenados

    arquivo2<<size2<<",cargatrabalho1,"<<durationO1<<std::endl;
    arquivo2<<size2<<",cargadetrabalho2,"<<durationO2<<std::endl;
    arquivo2<<size2<<",cargadetrabalho3,"<<durationO3<<std::endl;
    arquivo2<<size2<<",bubblesort,"<<durationOO1<<std::endl;
    arquivo2<<size2<<",bucketsort,"<<durationOO2<<std::endl;
    arquivo2<<size2<<",countingsort,"<<durationOO3<<std::endl;
    arquivo2<<size2<<",insertosort,"<<durationOO4<<std::endl;
    arquivo2<<size2<<",quicksort,"<<durationOO5<<std::endl;
    arquivo2<<size2<<",mergesort,"<<durationOO6<<std::endl;
    arquivo2<<size2<<",radixsort,"<<durationOO7<<std::endl;
    arquivo2<<size2<<",selectionsort,"<<durationOO8<<std::endl;
    arquivo2<<size2<<",shellsort,"<<durationOO9<<std::endl;

 
    arquivo2.close();


    std::cout<<"salvando os dados dos vetores inversamente ordenados"<<std::endl; 


    std::ofstream arquivo3("extras/inversamente.csv",std::ofstream::app);

    if(!arquivo3.is_open()){
        std::cerr<<"Errro ao abrir ao arquivo! "<<std::endl;
        return 1; 
    }


    //salvando os tempo das cargas de trabalho em um arquivo


    // salvando arquivos ordenados

    arquivo3<<size3<<",cargatrabalho1,"<<durationI1<<std::endl;
    arquivo3<<size3<<",cargadetrabalho2,"<<durationI2<<std::endl;
    arquivo3<<size3<<",cargadetrabalho3,"<<durationI3<<std::endl;
    arquivo3<<size3<<",bubblesort,"<<durationII1<<std::endl;
    arquivo3<<size3<<",bucketsort,"<<durationII2<<std::endl;
    arquivo3<<size3<<",countingsort,"<<durationII3<<std::endl;
    arquivo3<<size3<<",insertosort,"<<durationII4<<std::endl;
    arquivo3<<size3<<",quicksort,"<<durationII5<<std::endl;
    arquivo3<<size3<<",mergesort,"<<durationII6<<std::endl;
    arquivo3<<size3<<",radixsort,"<<durationII7<<std::endl;
    arquivo3<<size3<<",selectionsort,"<<durationII8<<std::endl;
    arquivo3<<size3<<",shellsort,"<<durationII9<<std::endl;

    std::cout<<std::endl;


 
    arquivo3.close();

    std::cout<<"caso baguncado: "<<std::endl;

    printsituation("extras/baguncado.csv");

    std::cout<<"caso ordenado: "<<std::endl;


    printsituation("extras/ordenado.csv");


    std::cout<<"caso inversamente ordenado: "<<std::endl;

    printsituation("extras/inversamente.csv");




    return 0;
}


