#ifndef CURSO_H
#define CURSO_H

#include <string>
#include <iostream>
#include "windows.h"
#include "tela.h"

using namespace std;

class Curso
{
    int codigo;
    string descricao,coordenador;
    static int contC;
    public:
        Curso();
        virtual ~Curso();
        void cadastrar ();
        int getCodigo ();
        string getCoordenador();
        void setCoordenador(string);
        static int getCont();
        static void addCont();
};

#endif // CURSO_H
