#include"professor.h"

int posi=0;

int Professor::contP=0;

Professor::Professor ()
{
    nome = "";
    endereco = "";
    telefone = "";
    titulacaoMaxima = "";
    nt=0;
}
Professor::~Professor ()
{

}
void Professor::cadastrar()
{
    int cont=0;
    Tela::gotoxy(4,4);
    cout << "I n c l u i r  -  P r o f e s s o r";
    Tela::gotoxy(7,7); cout << "Professor(a) : ";
    cin.ignore();
    getline(cin,nome);
    Tela::gotoxy(7,8); cout << "Endereco : ";
    cin.ignore();
    getline(cin,endereco);
    do
    {
        Tela::gotoxy(7,9); cout << "Telefone : ";
        cin >> telefone;
        for(string::size_type i=0; i<telefone.length(); ++i) cont++;
    }
    while(cont < 8);
    do
    {
        Tela::gotoxy(7,10); cout << "Titulacao: (Graduacao/Especializacao/Mestrado/Doutorado)";
        Tela::gotoxy(7,11); cin >> titulacaoMaxima;
        locale loc;
        for(string::size_type i=0; i<titulacaoMaxima.length(); ++i)
            titulacaoMaxima[i] = tolower(titulacaoMaxima[i],loc);
    }
    while(!(titulacaoMaxima == "graduacao" || titulacaoMaxima == "especializacao" || titulacaoMaxima == "mestrado" || titulacaoMaxima == "doutorado"));
}

void Professor::setTurmaProfessor (int n)
{
    if (posi<5)
    {
        turmas[posi]=n;
        posi++;
        nt++;
    }
    else {cout << "Maximo de cursos atingidos";}
}

int Professor::getCont()
{
    return contP;
}

void Professor::addCont()
{
    contP++;
}
