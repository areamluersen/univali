#include "curso.h"
#include <iostream>
#include "windows.h"

class Professor;

void gotoxyE (int x, int y)
{
    COORD point;
    point.X = x;
    point.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), point);
}

Curso::Curso()
{
    codigo=0;
    descricao="";
    coordenador="";
}

Curso::~Curso()
{
}
void Curso::cadastrar ()
{
    gotoxyE(4,4); cout << "I n c l u i r  -  C u r s o. ";
    gotoxyE(7,7); cout << "Informe o nome do curso : ";
    cin.ignore();
    getline(cin,descricao);
    gotoxyE(7,8); cout << "Informe codigo do curso : ";
    cin >> codigo;
}
int Curso::getCodigo ()
{
    return codigo;
}
string Curso::getCoordenador()
{
    return coordenador;
}
void Curso::setCoordenador(string n)
{
    coordenador = n;
}
