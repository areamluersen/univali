#include "curso.h"

class Professor;

int Curso::contC=0;

Curso::Curso()
{
    codigo=0;
    descricao="";
    coordenador="Sem Coordenador";
}

Curso::~Curso()
{
}
void Curso::cadastrar ()
{
    Tela::gotoxy(4,4); cout << "I n c l u i r  -  C u r s o. ";
    Tela::gotoxy(7,7); cout << "Informe o nome do curso : ";
    cin.ignore();
    getline(cin,descricao);
    Tela::gotoxy(7,8); cout << "Informe codigo do curso : ";
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

int Curso::getCont()
{
    return contC;
}

void Curso::addCont()
{
    contC++;
}
