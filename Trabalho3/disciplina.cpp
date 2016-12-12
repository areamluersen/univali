#include "disciplina.h"

int Disciplina::contD=0;

Disciplina::Disciplina()
{
    codigo = 0; descricao =""; cargaHoraria = 0; ementa = ""; bibliografia = "";
}

Disciplina::~Disciplina()
{
}
void Disciplina::cadastrar()
{
    Tela::gotoxy(7,10); cout << "Disciplina: ";
    cin.ignore();
    getline(cin,descricao);
    Tela::gotoxy(7,11);cout << "Codigo da disciplina: ";
    cin >> codigo;
    Tela::gotoxy(7,12);cout << "Carga Horaria: ";
    cin >> cargaHoraria;
    Tela::gotoxy(7,13);cout << "Preencha a Ementa da Disciplina: ";
    cin.ignore();
    getline(cin,ementa);
    Tela::gotoxy(7,15);cout << "Preencha a Bibliografia da Disciplina: ";
    cin.ignore();
    getline(cin,ementa);
}
int Disciplina::getCodigo()
{
    return codigo;
}
void Disciplina::setCursoDisciplina(int n)
{
    cursoDisciplina = n;
}

int Disciplina::getCont()
{
    return contD;
}

void Disciplina::addCont()
{
    contD++;
}
