#include "Aluno.h"
#include <string>
#include <iostream>
#include <stdio.h>
#include "windows.h"

using namespace std;

string n,cep,tel;
int pos=0;

void gotoxyC (int x, int y)
{
    COORD point;
    point.X = x;
    point.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), point);
}

Aluno::Aluno()
{
    situacao =" ";
    matricula = "";
    turmas;
}
Aluno::~Aluno()
{
}
void Aluno::cadastrar()
{
    gotoxyC(4,4);
    cout << "I n c l u i r  -  A l u n o";
    gotoxyC(7,7);cout << "Informe o nome do aluno : ";
    cin.ignore();
    getline(cin,n);
    gotoxyC(7,8);cout << "Informe a Matricula do Aluno : ";
    cin.ignore();
    getline(cin,matricula);
    setNome(n);
    gotoxyC(7,9); cout << "Endereco : ";
    cin.ignore();
    getline(cin,cep);
    setEndereco(cep);
    gotoxyC(7,10);cout << "Telefone : ";
    cin.ignore();
    getline(cin,tel);
    setTelefone(tel);
    fflush(stdin);
    gotoxyC(7,22); cout << "Aluno inserido com sucesso, voltando para tela inicial.";
}
void Aluno::setTurmaAluno (int n)
{
    if (pos<5){
    turmas[pos]=n;
    pos++;
    nt++;
    }
    else {cout << "Maximo de cursos atingidos";}
}
int  Aluno::getTurmaAluno(int n){
    return turmas[n];
}
string Aluno::getMatriculaAluno ()
{
    return matricula;
}
void Aluno::matricularCurso()
{
    situacao = "Matriculado";
}
void Aluno::trancar()
{
    situacao = "Trancado";
}

void Aluno::formar()
{
    situacao = "Formado";
}
void Aluno::evadir()
{
    situacao = "evadido";
}

void Aluno::obterAvaliacoes()
{

}
void Aluno::emitirHistorico()
{

}

