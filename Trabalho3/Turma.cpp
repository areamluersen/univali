#include "Turma.h"

int Turma::contT=0;

string mat;

Turma::Turma()
{
    materia=""; ano=0 ; semestre=0; diaSemana=0; nrTurma=0; codDisciplina=0; contTA=0; professor="Vazio";
}

Turma::~Turma()
{
}

void Turma::abrirTurma(int n)
{
    Tela::gotoxy(7,11); cout << "informe o nome da Turma: ";
    cin.ignore();
    getline (cin,materia);
    do
    {
        Tela::gotoxy(7,12); cout << "Ano: ";
        cin >> ano;
    }
    while(ano < 2016);
    do
    {
        Tela::gotoxy(7,13);cout << "Semestre: ";
        cin >> semestre;
    }while(!(semestre == 1 || semestre == 2));
    do
    {
        Tela::gotoxy(7,14);cout << "Dia da semana: 1)Segunda...7)Domingo: ";
        cin >> diaSemana;
    }
    while(!(diaSemana > 0 && diaSemana < 8));
    Tela::gotoxy(7,15);cout << "Numero da turma: "<< n+1<<endl<<endl;
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
    Tela::gotoxy(80,6); cout << "Turma: "<<getNrTurma();
    Tela::gotoxy(80,7); cout << "Materia: "<< materia;
    Tela::gotoxy(80,8); cout << "Professor: "<< professor;
    if(contTA == 0)
    {
        Tela::gotoxy(80,9); cout << "Nenhum aluno inserido na turma.";
    }
    else
    {
        cout << ":";
        for(i=0; i<contTA; i++){
            Tela::gotoxy(80,i+10); cout << "Aluno " << i+1 <<": "<< alunos[i];
        }
    }
}

int Turma::getCont()
{
    return contT;
}

void Turma::addCont()
{
    contT++;
}
