#ifndef ALUNO_H
#define ALUNO_H
#include <string>
#include "Pessoa.h"
#include "Turma.h"


using namespace std;

class Turma;

class Aluno : public Pessoa
{
    string matricula,situacao;
    int nt=0 , turmas[6];
public:
    Aluno();
    virtual ~Aluno();
    int  getTurmaAluno(int);
    string getMatriculaAluno ();
    void setTurmaAluno(int);
    void cadastrar ();
    void matricularCurso();
    void trancar();
    void formar();
    void evadir();
    void obterAvaliacoes();
    void emitirHistorico();
};

#endif // ALUNO_H
