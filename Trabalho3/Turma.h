#ifndef TURMA_H
#define TURMA_H

#include "Aluno.h"
#include <string>
#include <iostream>
#include "windows.h"
#include "tela.h"

class Aluno;
class Professor;

class Turma
{
    int ano, semestre, diaSemana,nrTurma,codDisciplina,contTA;
    static int contT;
    string horarios,materia,alunos[30],professor;
public:
    Turma();
    virtual ~Turma();
    void abrirTurma(int);
    void alocarProfessor(string);
    void matricularAluno(string);
    void emitirDiario();
    string getMateria ();
    int getNrTurma ();
    void setCodDisciplina (int);
    void printDiarioClasse ();
    static int getCont();
    static void addCont();
    void setNrTurma(int);
};

#endif // TURMA_H

