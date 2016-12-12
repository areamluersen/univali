#include "Tela.h"

void Tela::gotoxy (int x, int y)
{
    COORD point;
    point.X = x;
    point.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), point);
}

void Tela::inicio()
{
    system("CLS"); // DESENHO DA TELA-MOLDURA
    gotoxy(6,6);
    cout<<"Escolha uma opcao: ";
    gotoxy(6,8);
    cout<<"1) Incluir Aluno";
    gotoxy(6,9);
    cout<<"2) Incluir Professor";
    gotoxy(6,10);
    cout<<"3) Incluir Turma";
    gotoxy(6,11);
    cout<<"4) Incluir Disciplina";
    gotoxy(6,12);
    cout<<"5) Incluir Curso";
    gotoxy(6,13);
    cout<<"6) Matricular Aluno";
    gotoxy(6,14);
    cout<<"7) Alocar Professor";
    gotoxy(6,15);
    cout<<"8) Incluir Avaliacao";
    gotoxy(6,16);
    cout<<"9) Impressoes - Historico - Situacao";
    gotoxy(6,17);
    cout<<"10) Alocar Coordenador";
    gotoxy(6,18);
    cout<<"11) Mudar situacao de aluno";
    gotoxy(6,19);
    cout<<"12) Alterar dados";
    gotoxy(6,20);
    cout<<"13) Print aluno";
}

void Tela::moldura()
{
    int coluna;
    //Cabecalho
    gotoxy(3,2);
    cout<<char(186);
    coluna =3;

    do
    {
        gotoxy (coluna, 1);
        cout<<char(205);
        coluna++;
    }
    while (coluna != 75);
//linha superior
    gotoxy (30,2);
    cout<<"B E M - V I N D O!";
    coluna = 3;
    gotoxy(coluna,3);
    cout<<char(200);
    gotoxy(3,1);
    cout<<char(201);
    gotoxy(3,3);
    cout<<char(200);
    gotoxy(75,1);
    cout<<char(187);
    coluna=4;
    do
    {
        gotoxy (coluna,3);
        cout<<char(205)<<char(188);
        coluna++;
    }
    while (coluna != 75);

    coluna = 75;
    gotoxy(coluna,2);
    cout<<char(186);

//TERMINA CABEÇALHO
    coluna=4;

    do
    {
        gotoxy (coluna,5);
        cout<<char(205)<<char(187);
        coluna++;
    }
    while (coluna != 75);
    //barra de baixo
    coluna=4;
    gotoxy(3,23);cout<<char(200);
    do
    {
        gotoxy (coluna,23);
        cout<<char(205)<<char(188);
        coluna++;
    }
    while (coluna !=75 );
    //barra lateral direita
    coluna=6;
    do
    {
        gotoxy (75,coluna);
        cout<<char(186);
        coluna++;
    }
    while (coluna != 23);
    //barra lateral esquerda
    coluna=6;
    do
    {
        gotoxy (3,coluna);
        cout<<char(186);
        coluna++;
    }
    while (coluna != 23);
    gotoxy(3,5);cout<<char(201);

}

void Tela::limpaTela()
{
    for (int i=6; i<22; i++)
    {
        for (int j=6; j<60; j++)
        {
            gotoxy(j,i);
            cout<<" ";
        }
    }
}
void Tela::molduraPrint()
{
    gotoxy (91,2); cout << "- P R I N T -";
    int i=5,j;
        {
        for (int j=78; j<117; j++){
            gotoxy(j,i); cout << char(205);
        }
    }
        {
            j=78;
        for (int i=5; i<28; i++){
            gotoxy(j,i); cout << "|";
            gotoxy(j+39,i); cout << "|";
        }
    }
}
