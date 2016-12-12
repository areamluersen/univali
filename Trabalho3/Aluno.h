#ifndef ALUNO_H
#define ALUNO_H

#include <string>
#include "Pessoa.h"
#include "Turma.h"
#include <string>
#include <iostream>
#include <stdio.h>
#include "windows.h"
#include "tela.h"

using namespace std;

class Turma;

class Aluno : public Pessoa
{
    string matricula,situacao;
    int nt, turmas[6];
    static int contA;
public:
    Aluno();
    virtual ~Aluno();
    int getTurmaAluno(int);
    string getMatriculaAluno ();
    string getSituacaoAluno();
    void setTurmaAluno(int);
    void cadastrar ();
    void matricularCurso();
    void trancar();
    void formar();
    void evadir();
    void obterAvaliacoes();
    void emitirHistorico();
    static int getCont();
    static void addCont();
};

#endif // ALUNO_H
