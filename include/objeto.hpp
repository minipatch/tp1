#ifndef OBJETO_HPP
#define OBJETO_HPP

#include <iostream>

class Objeto{
    private:
        int _chave;

    public:
        Objeto();
        Objeto(int chave);

        void SetObjeto(int chave);

        int getChave();


        //para countingsort
        void incrementar1();

        void decrementar1();

        void incrementarn(int n);
};









#endif