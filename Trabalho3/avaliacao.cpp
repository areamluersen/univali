#include "avaliacao.h"
#include "windows.h"
#include <iostream>

float nota,media;

void gotoxyH (int x, int y)
{
    COORD point;
    point.X = x;
    point.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), point);
}

Avaliacao::Avaliacao(string a, int t)
{
    setNomeAluno(a);
    setCodigoTurma(t);
    do
    {
        gotoxyH(7,11);
        cout << "Frequencia do aluno: ";
        cin >> frequencia;

    }
    while (frequencia < 0 || frequencia > 100);
    do
    {
        gotoxyH(7,12);
        cout << "Nota 1: ";
        cin >> nota;
    }
    while (nota < 0 || nota > 10);
    setNota1(nota);
    do
    {
        gotoxyH(7,13);
        cout << "Nota 2: ";
        cin >> nota;
    }
    while (nota < 0 || nota > 10);
    setNota2(nota);
    media = (getNota1()+getNota2())/2;
    if (media >= 3 && media <7)
    {
        do
        {
            gotoxyH(7,14);
            cout << "Prova Final: ";
            cin >> nota;
        }
        while (nota < 0 || nota > 10);
        setNotaProvaFinal(nota);
        media = (media+nota)/2;
    }
    if (media >= 5 && frequencia >= 75)
    {
        setAprovacao("Aprovado");
        gotoxyH(7,15);
        cout << "Aluno Aprovado.";
    }
    else
    {
        setAprovacao("Reprovado");
        gotoxyH(7,15);
        cout << "Aluno Reprovado.";
    }
}
Avaliacao::~Avaliacao()
{
}
float Avaliacao::getNota1 ()
{
    return nota1;
}
float Avaliacao::getNota2 ()
{
    return nota2;
}
float Avaliacao::getProvaFinal ()
{
    return notaProvaFinal;
}
void Avaliacao::setNota1 (float n)
{
    nota1 = n;
}
void Avaliacao::setNota2 (float n)
{
    nota2 = n;
}
void Avaliacao::setNotaProvaFinal (float n)
{
    notaProvaFinal = n;
}
void Avaliacao::setFrequencia (int n)
{
    frequencia = n;
}
void Avaliacao::setNomeAluno(string n)
{
    aluno = n;
}
void Avaliacao::setCodigoTurma(int n)
{
    turma = n;
}
string Avaliacao::getAprovacao ()
{
    return aprovacao;
}
void Avaliacao::setAprovacao (string  n)
{
    aprovacao = n;
}
string Avaliacao::getNomeAluno ()
{
    return aluno;
}
void Avaliacao::consultaAvaliacao ()
{
    gotoxyH(6,10);
    cout << "Aluno : "<< aluno;
    gotoxyH(6,11);
    cout << "Nota 1: "<< getNota1();
    gotoxyH(6,12);
    cout << "Nota 2: "<< getNota2();
    gotoxyH(6,13);
    cout << "Nota Prova final-se tiver: "<< getProvaFinal();
    gotoxyH(6,14);
    cout << "media: "<<media;
    gotoxyH(6,15);
    cout << "Resultado: "<<aprovacao;
}
