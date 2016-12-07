#include <string>
#include <iostream>
#include "windows.h"
#include "Turma.h"
#include "Aluno.h"

void gotoxyF (int x, int y)
{
    COORD point;
    point.X = x;
    point.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), point);
}

string mat;

Turma::Turma()
{
    materia=""; ano=0 ; semestre=0; diaSemana=0; nrTurma=0; codDisciplina=0;
}
Turma::~Turma()
{
}
void Turma::abrirTurma(int n)
{
    gotoxyF(7,11); cout << "informe o nome da Turma: ";
    cin.ignore();
    getline (cin,mat);
    setMateria(mat);
    gotoxyF(7,12); cout << "Ano: ";
    cin >> ano;
    gotoxyF(7,13);cout << "Semestre: ";
    cin >> semestre;
    gotoxyF(7,14);cout << "Dia da semana: ";
    cin >> diaSemana;
    gotoxyF(7,15);cout << "Numero da turma: "<< n+1<<endl<<endl;
    setNrTurma(n+1);
}
void Turma::alocarProfessor(string n)
{
    ///validar se rofessor já está inserido antes de alocar outro professor.
    professor = n;
}
void Turma::matricularAluno(string n)
{
    alunos[contTA] = n;
    contTA++;
}

void Turma::emitirDiario()
{
    cout<<"Turma: "<<getMateria()<<endl<<"Ano : "<<ano<<endl<<"Semestre : "<<semestre<<endl;
    cout<<"Dia da semana: "<<diaSemana<<endl<<"Nr Turma: "<<getNrTurma()<<endl<<endl;
}

string Turma::getMateria ()
{
    return materia;
}
void Turma::setMateria (string n)
{
    materia = n;
}

int Turma::getNrTurma ()
{
    return nrTurma;
}

void Turma::setNrTurma (int n)
{
    nrTurma=n;
}
void Turma::setCodDisciplina (int n)
{
    codDisciplina = n;
}
void Turma::printDiarioClasse ()
{
    int i;
    gotoxyF(80,6); cout << "Turma: "<<getNrTurma();
    gotoxyF(80,7); cout << "Materia: "<< materia;
    gotoxyF(80,8); cout << "Professor: "<< professor;
    if(contTA == 0)
    {
        gotoxyF(80,9); cout << "Nenhum aluno inserido na turma.";
    }
    else
    {
        cout << ":";
        for(i=0; i<contTA; i++){
            gotoxyF(80,i+10); cout << "Aluno " << i+1 <<": "<< alunos[i];
        }
    }
}
