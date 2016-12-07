#include"professor.h"
#include <iostream>
#include "windows.h"

int posi=0;

void gotoxyD (int x, int y)
{
    COORD point;
    point.X = x;
    point.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), point);
}
Professor::Professor ()
{
    nome = "";
    endereco = "";
    telefone = "";
    titulacaoMaxima = "";
}
Professor::~Professor ()
{

}
void Professor::cadastrar()
{
    gotoxyD(4,4);
    cout << "I n c l u i r  -  P r o f e s s o r";
    gotoxyD(7,7); cout << "Professor(a) : ";
    cin.ignore();
    getline(cin,nome);
    gotoxyD(7,8); cout << "Endereco : ";
    cin.ignore();
    getline(cin,endereco);
    gotoxyD(7,9); cout << "Telefone : ";
    cin >> telefone;
    do
    {
        gotoxyD(7,10); cout << "Titulacao: (Graduacao/Especializacao/Mestrado/Doutorado))";
        gotoxyD(7,11); cin >> titulacaoMaxima;
        locale loc;
        for(string::size_type i=0; i<titulacaoMaxima.length(); ++i)
            titulacaoMaxima[i] = tolower(titulacaoMaxima[i],loc);
    }
    while(!(titulacaoMaxima == "graduacao" || titulacaoMaxima == "especializacao" || titulacaoMaxima == "mestrado" || titulacaoMaxima == "doutorado"));
    gotoxyD(7,22); cout << "Professor inserido com sucesso, voltando para tela inicial.";
}
string Professor::getNome()
{
    return nome;
}

void Professor::setTurmaProfessor (int n)
{
    if (posi<5){
    turmas[posi]=n;
    posi++;
    nt++;
    }
    else {cout << "Maximo de cursos atingidos";}
}
