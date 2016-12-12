#include "Aluno.h"

int pos=0;
int Aluno::contA=0;

Aluno::Aluno()
{
    situacao ="Matriculado";
    matricula ="";
    nt=0;
}
Aluno::~Aluno()
{
}
void Aluno::cadastrar()
{
    int cont=0;
    Tela::gotoxy(4,4);
    cout << "I n c l u i r  -  A l u n o";
    Tela::gotoxy(7,7);cout << "Informe o nome do aluno : ";
    cin.ignore();
    getline(cin,nome);
    Tela::gotoxy(7,8);cout << "Informe a Matricula do Aluno : ";
    cin >> matricula;
    Tela::gotoxy(7,9); cout << "Endereco : ";
    cin.ignore();
    getline(cin,endereco);
    do
    {
        Tela::gotoxy(7,10);cout << "Telefone : ";
        cin >> telefone;
        for(string::size_type i=0; i<telefone.length(); ++i) cont++;
    }
    while(cont < 8);
}
void Aluno::setTurmaAluno (int n)
{
    if (pos<5)
    {
        turmas[pos]=n;
        pos++;
        nt++;
    }
    else {cout << "Maximo de cursos atingidos";}
}

int  Aluno::getTurmaAluno(int n){
    return turmas[n];
}

string Aluno::getMatriculaAluno()
{
    return matricula;
}

string Aluno::getSituacaoAluno()
{
    return situacao;
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
    situacao = "Evadido";
}

void Aluno::obterAvaliacoes()
{

}
void Aluno::emitirHistorico()
{

}

int Aluno::getCont()
{
    return contA;
}

void Aluno::addCont()
{
    contA++;
}
