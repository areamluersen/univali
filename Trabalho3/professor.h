#ifndef PROFESSOR_HPP_INCLUDE
#define PROFESSOR_HPP_INCLUDED

#include"pessoa.h"
#include <iostream>
#include "windows.h"
#include "tela.h"

class Professor : public Pessoa
{
private:
    string titulacaoMaxima;
    int nt,turmas[6];
    static int contP;
public:
    Professor ();
    virtual ~Professor ();
    void cadastrar();
    void setTurmaProfessor (int);
    static int getCont();
    static void addCont();
};

#endif // PROFESSOR_HPP_INCLUDEDR_H
