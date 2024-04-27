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


int contarDigitos(const char* str) {
    int count = 0;
    while (*str) {
        if (isdigit(*str)) {
            count++;
        }
        str++;
    }
    return count;
}

// Função para converter uma substring em um número inteiro
int stringParaInt(const char* str, int length) {
    int result = 0;
    for (int i = 0; i < length; ++i) {
        result = result * 10 + (str[i] - '0');
    }
    return result;
}



int main()
{


    Objeto vetor[10];
    int size = sizeof(vetor) / sizeof(vetor[0]);
    ObterObjeto(vetor, size);

    // //vetores auxiliares do experimento

    // Objeto vet[10];
    // Objeto vet1[20];
    // Objeto vet2[30];
    // Objeto vet5[500];


    // int size1 = sizeof(vet) / sizeof(vet[0]);
    // int size2 = sizeof(vet1) / sizeof(vet1[0]);
    // int size3 = sizeof(vet2) / sizeof(vet2[0]);
    // int size4 = sizeof(vet5) / sizeof(vet5[0]);

    // ObterObjeto(vet,size1);
    // ObterObjeto(vet1,size2);
    // ObterObjeto(vet2,size3);
    // ObterObjeto(vet5,size4);    
    


    std::cout << "vetor de entrada: " << std::endl;

    std::this_thread::sleep_for(std::chrono::seconds(2));

    for (int i = 0; i < size; i++)
    {
        std::cout << vetor[i].getChave() << std::endl;
    }

    std::cout << std::endl;

    // carga de trabalho
    Cargadetrabalho Carga(size);

    std::cout << "carga de trabalho: " << std::endl;

    // quantos elementos para ordernar

    int qts = Carga.qtsiordenar(vetor);

    auto inicioc = std::chrono::steady_clock::now();
    Carga.qtsiordenar(vetor);
    auto finc = std::chrono::steady_clock::now();

    std::cout<<"quantidade de elementos para se organizar e de: "<<qts<<std::endl;

    auto durationc = std::chrono::duration_cast<std::chrono::microseconds>(finc - inicioc).count();

    std::cout<<"duracao de carga de trabalho da quantidade de elementos para se organizar e de: "<<durationc<<std::endl;

    std::cout<<std::endl;

    // tamanho de algum item do vetor
    size_t tamanho = Carga.Tamanhoembytes(vetor, 1);

    auto inicioC1 = std::chrono::steady_clock::now();
    Carga.Tamanhoembytes(vetor, 1);
    auto fimC1 = std::chrono::steady_clock::now();

    std::cout<<"tamanho do vetor em bytes é de "<<tamanho<<std::endl;

    auto durationc1 = std::chrono::duration_cast<std::chrono::microseconds>(fimC1-inicioC1).count();

    std::cout<<"duracao de carga de trabalho relacionado a tamanho do elemento em bytes e de: "<<durationc1<<std::endl;


    std::cout<<std::endl;

    // Olhar se vetor esta bagunçado ordernado ou não ordernado
    auto inicioC2 = std::chrono::steady_clock::now();
    Carga.OlharTamnhodovetor(vetor);
    auto finC2 = std::chrono::steady_clock::now();

    auto durationc2 = std::chrono::duration_cast<std::chrono::microseconds>(finC2-inicioC2).count();


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
    std::cout<<std::endl<<"duracao do tempo para saber se o vetor e organizado ou inversamente organizado ou baguncado e de: "<<durationc2<<std::endl;


    std::cout << std::endl;

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

    AjustaVetor(vetor, size, aux1);
    AjustaVetor(vetor, size, aux2);
    AjustaVetor(vetor, size, aux3);
    AjustaVetor(vetor, size, aux4);
    AjustaVetor(vetor, size, aux5);
    AjustaVetor(vetor, size, aux6);
    AjustaVetor(vetor, size, aux7);
    AjustaVetor(vetor, size, aux8);
    AjustaVetor(vetor, size, aux9);

    std::cout << "tempo dos algoritmos: " << std::endl;

    auto inicio1 = std::chrono::steady_clock::now();
    ordena.Bubbblesort(aux1, size);
    auto fin1 = std::chrono::steady_clock::now();

    auto duration1 = std::chrono::duration_cast<std::chrono::microseconds>(fin1 - inicio1).count();

    std::cout << "tempo do algoritmo bolha em microsegundos e de " << duration1 << std::endl;

    // ordenação do algorimto bucket
    auto inicio2 = std::chrono::steady_clock::now();
    ordena.Bucketsort(aux2, size);
    auto fin2 = std::chrono::steady_clock::now();

    auto duration2 = std::chrono::duration_cast<std::chrono::microseconds>(fin2 - inicio2).count();

    std::cout << "tempo do algoritmo bucket em microsegundos e de " << duration2 << std::endl;

    // ordernação do algorimto counting sort

    auto inicio3 = std::chrono::steady_clock::now();
    ordena.Coutingsort(aux3, size);
    auto fin3 = std::chrono::steady_clock::now();

    auto duration3 = std::chrono::duration_cast<std::chrono::microseconds>(fin3 - inicio3).count();

    std::cout << "tempo do algoritmo counting em microsegundos e de " << duration3 << std::endl;

    // ordenação do algoritmo insert sort

    auto inicio4 = std::chrono::steady_clock::now();
    ordena.Insertsort(aux4, size);
    auto fin4 = std::chrono::steady_clock::now();

    auto duration4 = std::chrono::duration_cast<std::chrono::microseconds>(fin4 - inicio4).count();

    std::cout << "tempo do algoritmo insert em microsegundos e de " << duration4 << std::endl;

    // ordenação do algoritmo quicksort
    auto inicio5 = std::chrono::steady_clock::now();
    ordena.QuickSort(aux5, size);
    auto fin5 = std::chrono::steady_clock::now();

    auto duration5 = std::chrono::duration_cast<std::chrono::microseconds>(fin5 - inicio5).count();

    std::cout << "tempo do algoritmo quicksort em microsegundos e de " << duration5 << std::endl;

    // //ordenação do algoritmo do merge sort
    auto inicio6 = std::chrono::steady_clock::now();
    ordena.MergeSort(aux6, 0, size - 1);
    auto fin6 = std::chrono::steady_clock::now();

    auto duration6 = std::chrono::duration_cast<std::chrono::microseconds>(fin6 - inicio6).count();

    std::cout << "tempo do algoritmo mergesort em microsegundos e de " << duration6 << std::endl;

    // ordenação do algoritmo do radix
    auto inicio7 = std::chrono::steady_clock::now();
    ordena.radixs(aux7, size);
    auto fin7 = std::chrono::steady_clock::now();

    auto duration7 = std::chrono::duration_cast<std::chrono::microseconds>(fin7 - inicio7).count();

    std::cout << "tempo do algorimto radixsort em microsegundos e de " << duration7 << std::endl;

    // ordenação do algoritmo do select
    auto inicio8 = std::chrono::steady_clock::now();
    ordena.Selectsort(aux8, size);
    auto fin8 = std::chrono::steady_clock::now();

    auto duration8 = std::chrono::duration_cast<std::chrono::microseconds>(fin8 - inicio8).count();

    std::cout << "tempo do algoritmo selecsort em microsegundos e de " << duration8 << std::endl;

    // ordenação do algorimto do shellsort
    auto inicio9 = std::chrono::steady_clock::now();
    ordena.Shellsort(aux9, size);
    auto fin9 = std::chrono::steady_clock::now();

    auto duration9 = std::chrono::duration_cast<std::chrono::microseconds>(fin9 - inicio9).count();

    std::cout << "tempo do algoritmo shellsort em microsegundos e de " << duration9 << std::endl;

    std::cout<<std::endl;

    if(size<=50){
        printvetor(aux1,size);
        std::cout<<std::endl;

        printvetor(aux2,size);
        std::cout<<std::endl;

        printvetor(aux3,size);
        std::cout<<std::endl;

        printvetor(aux4,size);
        std::cout<<std::endl;

        printvetor(aux5,size);
        std::cout<<std::endl;

        printvetor(aux6,size);
        std::cout<<std::endl;

        printvetor(aux7,size);
        std::cout<<std::endl;


        printvetor(aux8,size);
        std::cout<<std::endl;

        printvetor(aux9,size);
        std::cout<<std::endl;

    }



    std::ofstream arquivo("tempo_algo2.csv",std::ofstream::app);

    if(!arquivo.is_open()){
        std::cerr<<"Errro ao abrir ao arquivo! "<<std::endl;
        return 1; 
    }


    //salvando os tempo das cargas de trabalho em um arquivo


    arquivo<<size<<",cargatrabalho1,"<<durationc<<std::endl;
    arquivo<<size<<",cargadetrabalho2,"<<durationc1<<std::endl;
    arquivo<<size<<",cargadetrabalho3,"<<durationc2<<std::endl;
    arquivo<<size<<",bubblesort,"<<duration1<<std::endl;
    arquivo<<size<<",bucketsort,"<<duration2<<std::endl;
    arquivo<<size<<",countingsort,"<<duration3<<std::endl;
    arquivo<<size<<",insertosort,"<<duration4<<std::endl;
    arquivo<<size<<",quicksort,"<<duration5<<std::endl;
    arquivo<<size<<",mergesort,"<<duration6<<std::endl;
    arquivo<<size<<",radixsort,"<<duration7<<std::endl;
    arquivo<<size<<",selectionsort,"<<duration8<<std::endl;
    arquivo<<size<<",shellsort,"<<duration9<<std::endl;

 
    arquivo.close();
        // Nome do arquivo a ser lido
    const char* nomeArquivo = "tempo_algo.csv";

    // Abrir o arquivo para leitura
    FILE* arquivo1 = fopen(nomeArquivo, "r");
    if (arquivo1 == NULL) {
        std::cerr << "Erro ao abrir o arquivo." << std::endl;
        return 1;
    }

    char linha[256]; 
    int menorTempos[MAX_TAM]; 
    char melhorAlgoritmo[MAX_TAM][256];

    for (int i = 0; i < MAX_TAM; ++i) {
        menorTempos[i] = 999999;
        strcpy(melhorAlgoritmo[i], "NONE"); 
    }

    fgets(linha, sizeof(linha), arquivo1);

    while (fgets(linha, sizeof(linha), arquivo1) != NULL) {
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

    fclose(arquivo1);

    return 0;
}


