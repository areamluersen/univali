#ifndef PROFESSOR_HPP_INCLUDE
#define PROFESSOR_HPP_INCLUDED

#include"pessoa.h"

class Professor : public Pessoa
{
private:
    string titulacaoMaxima;
    int nt=0,turmas[6];
public:
    Professor ();
    virtual ~Professor ();
    void cadastrar();
    string getNome();
    void setTurmaProfessor (int);
};

#endif // PROFESSOR_HPP_INCLUDEDR_H
