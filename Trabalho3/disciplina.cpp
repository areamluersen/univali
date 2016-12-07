#include "disciplina.h"
#include "windows.h"
#include <iostream>
#include <string>

void gotoxyG (int x, int y)
{
    COORD point;
    point.X = x;
    point.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), point);
}

using namespace std;

Disciplina::Disciplina()
{
    codigo = 0; descricao =""; cargaHoraria = 0; ementa = ""; bibliografia = "";
}

Disciplina::~Disciplina()
{
}
void Disciplina::cadastrar()
{
    gotoxyG(7,10); cout << "Disciplina: ";
    cin.ignore();
    getline(cin,descricao);
    gotoxyG(7,11);cout << "Codigo da disciplina: ";
    cin >> codigo;
    gotoxyG(7,12);cout << "Carga Horaria: ";
    cin >> cargaHoraria;
    gotoxyG(7,13);cout << "Preencha a Ementa da Disciplina: ";
    cin.ignore();
    getline(cin,ementa);
    gotoxyG(7,15);cout << "Preencha a Bibliografia da Disciplina: ";
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
