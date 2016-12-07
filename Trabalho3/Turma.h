#ifndef TURMA_H
#define TURMA_H
#include "Aluno.h"

class Aluno;
class Professor;

class Turma
{
    int ano, semestre, diaSemana,nrTurma,codDisciplina,contTA=0;
    string horarios,materia,alunos[30],professor="Vazio";

public:
    Turma();
    virtual ~Turma();
    void abrirTurma(int);
    void alocarProfessor(string);
    void matricularAluno(string);
    void emitirDiario();
    string getMateria ();
    void setMateria (string);
    int getNrTurma ();
    void setNrTurma (int);
    void setCodDisciplina (int);
    void printDiarioClasse ();
};

#endif // TURMA_H

