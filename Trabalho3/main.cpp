#include <iostream>
#include <string>
#include <time.h>
#include "curso.h"
#include "disciplina.h"
#include "professor.h"
#include "avaliacao.h"
#include "Aluno.h"
#include "Turma.h"
#include "tela.h"
#include "windows.h"
#include <conio.h>


using namespace std;

void CadastraTurma(int &contD,int &contT,Disciplina * disciplinas[],Turma * turmas[]);
void CadastraDisciplina(int &contC,int &contD,Disciplina * disciplinas[],Curso * cursos[]);
void CadastraCurso(int &contC,int &contP,Professor * professores[],Curso * cursos[]);
void MatricularAluno(int &contT,int &contA,Turma * turmas[],Aluno * alunos[]);
void MatricularProfessor(int &contT,int &contP,Turma * turmas[],Professor * professores[]);
void IncluirAvaliacao(int &contA,int &contT,int &contAV,Avaliacao * avaliacao[],Aluno * alunos[],Turma * turmas[]);
void consultaAvaliacao (int &contAV, Avaliacao * Avaliacao[]);
void gotoxyB(int x,int y);

int main()
{
    int resp,cont=0,contT=0,contA=0,contP=0,contC=0,contD=0,contAV=0;
    Aluno * alunos[50];
    Professor * professores[50];
    Disciplina * disciplinas[20];
    Turma * turmas[50];
    Curso * cursos[10];
    Avaliacao * avaliacao[10];
    Tela*tela;

    do
    {
        tela->inicio();
        tela->moldura();
        do
        {
            gotoxyB(25,6);
            cin>>resp;
        }
        while (resp<1 || resp>9);
        switch(resp)
        {
        case 1 :
            tela->limpaTela();
            alunos[contA] = new Aluno;
            alunos [contA]->cadastrar();
            contA++;
            Sleep(1500);
            break;
        case 2 :
            tela->limpaTela();
            professores[contP] = new Professor;
            professores[contP]->cadastrar();
            contP++;
            Sleep(1500);
            break;
        case 3 :
            tela->limpaTela();
            CadastraTurma(contD,contT,disciplinas,turmas);
            Sleep(1500);
            break;

        case 4 :
            tela->limpaTela();
            CadastraDisciplina(contC,contD,disciplinas,cursos);
            Sleep(1500);
            break;
        case 5 :
            tela->limpaTela();
            CadastraCurso(contC,contP,professores,cursos);
            Sleep(1500);
            break;
        case 6 :
            MatricularAluno(contT,contA,turmas,alunos);
            break;
        case 7 :
            MatricularProfessor(contT,contP,turmas,professores);
            break;
        case 8 :
            IncluirAvaliacao(contA,contT,contAV,avaliacao,alunos,turmas);
            break;
        case 9 :
            tela->limpaTela();
            gotoxyB(6,6);
            cout<<"Escolha uma opcao: ";
            gotoxyB(6,8);
            cout<<"1) Aluno Consulta Avaliacao: ";
            gotoxyB(6,9);
            cout<<"2) Diario de Classe: ";
            gotoxyB(6,10);
            cout<<"3) Relatorio aluno geral: ";
            do
            {
                gotoxyB(25,6);
                cin>>resp;
            }
            while (resp<1 || resp>3);
            switch(resp)
            {
            case 1 :
                tela->limpaTela();
                consultaAvaliacao(contAV,avaliacao);
                break;
            case 2 :
                tela ->limpaTela();
                tela ->molduraPrint();
                gotoxyB(7,6); cout << "Informe o codigo da turma: ";
                cin >> resp;
                for (int i=0; i<contT; i++){
                    if (turmas[i]-> getNrTurma() == resp){
                        turmas[i]-> printDiarioClasse();
                    }
                }
                getch();
                break;
            case 3 :
                tela->molduraPrint();
                Sleep(1500);
                break;
            }
            break;
        }
    }
    while (cont<100);

    return 0;
}
void CadastraTurma(int &contD,int &contT,Disciplina * disciplinas[],Turma * turmas[])
{
    char opcao;
    int cod;
    bool compare=false;
    if (contD>0)
    {
        gotoxyB(4,4);
        cout << "I n c l u i r - T u r m a.";
        do
        {
            gotoxyB(7,8);
            cout << "Informe o codigo da Disciplina da Turma : ";
            cin >> cod;
            for (int i=0; i<contD; i++)
            {
                if (disciplinas[i]->getCodigo()==cod)
                    compare=true;
            }
            if (compare == false)
            {
                gotoxyB(7,9);
                cout << "Sem Disciplinas para o codigo inserido. ";
                gotoxyB(7,10);
                cout << "Deseja inserir outro codigo ? S/N : ";
                cin >> opcao;
                opcao = toupper(opcao);
            }
            else
            {
                gotoxyB(7,9);
                cout << "                                                                             ";
                turmas[contT]= new Turma;
                turmas[contT]->abrirTurma(contT);
                turmas[contT]->setCodDisciplina(cod);
                contT++;
            }
        }
        while (compare == false && opcao == 'S');
    }
    else
    {
        gotoxyB(7,7);
        cout << "Nao existem Disciplinas para inserir a turma.";
        gotoxyB(7,8);
        cout << "Insira uma Disciplina primeiro.";
    }
}

void CadastraDisciplina(int &contC,int &contD,Disciplina * disciplinas[],Curso * cursos[])
{
    char opcao;
    int cod;
    bool compare=false;
    if (contC>0)
    {
        gotoxyB(4,4);
        cout << "I n c l u i r - D i s c i p l i n a.";
        do
        {
            gotoxyB(7,7);
            cout << "Informe o codigo do Curso da Disciplina : ";
            cin >> cod;
            for (int i=0; i<contC; i++)
            {
                if (cursos[i]->getCodigo()==cod)
                    compare=true;
            }
            if (compare == false)
            {
                gotoxyB(7,8);
                cout << "Nao foram encontrados Cursos com o codigo inserido";
                gotoxyB(7,9);
                cout << "Dseja inserir outro codigo ? S/N: ";
                cin >> opcao;
                opcao = toupper(opcao);
            }
            else
            {
                disciplinas[contD]=new Disciplina;
                disciplinas[contD] -> cadastrar();
                disciplinas[contD] -> setCursoDisciplina(cod);
                contD++;
                gotoxyB(7,22);
                cout << "Disciplina inserida com sucesso, voltando para tela inicial.";
            }
        }
        while (compare == false && opcao == 'S');
    }
    else
    {
        gotoxyB(7,7);
        cout << "Nao existem cursos para inserir a Disciplina.";
        gotoxyB(7,8);
        cout << "Insira um curso primeiro.";
    }
}

void CadastraCurso(int &contC,int &contP,Professor * professores[],Curso * cursos[])
{
    char opcao;
    string coord;
    bool compare=false;
    cursos[contC]= new Curso;
    cursos[contC]->cadastrar();
    do
    {
        gotoxyB(50,9);
        cout << "                         ";
        gotoxyB(7,9);
        cout << "Informe o nome do professor Coordenador do curso : ";
        cin.ignore();
        getline(cin,coord);
        for (int i=0; i<contP; i++)
        {
            if (professores[i]->getNome()==coord)
                compare=true;
        }
        if (compare == false)
        {
            cursos[contC]->setCoordenador("Sem Coordenador");
            gotoxyB(7,10);
            cout << "Nao existe o nome inserido, deseja inserir outro nome ? S/N : ";
            cin >> opcao;
            opcao = toupper(opcao);
        }
        else
        {
            gotoxyB(45,10);
            cout << "                             ";
            gotoxyB(7,10);
            cout << "Resultado encontrado, registrando coordenador."<<endl;
            cursos[contC]->setCoordenador(coord);
            Sleep(500);
        }
    }
    while (compare == false && opcao == 'S');
    contC++;
    gotoxyB(7,22);
    cout << "Curso inserido com sucesso, voltando para tela inicial.";
}
void gotoxyB(int x,int y)
{
    COORD point;
    point.X = x;
    point.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), point);
}
void MatricularAluno(int &contT,int &contA,Turma * turmas[],Aluno * alunos[])
{
    string nome;
    bool compare=false, comp=false;
    char opcao,opcao2;
    int cod;
    Tela*tela;
    tela->limpaTela();
    gotoxyB(4,4);
    cout << "M a t r i c u l a r  - A l u n o";
    gotoxyB(6,6);
    cout << "Verificando se existem Alunos e Turmas cadastrados";
    Sleep(1000);
    if (contT>0 && contA>0)
    {
        do
        {
            opcao ='n';
            gotoxyB(6,8);
            cout << "Informe o Nome do Aluno: ";
            cin.ignore();
            getline(cin,nome);
            for (int i=0; i<contA; i++)
            {
                if (alunos[i]->getNome()==nome)
                {
                    compare=true;
                    gotoxyB(6,9);
                    cout << "Aluno encontrado.";
                    do
                    {
                        comp == false;
                        gotoxyB(6,10);
                        cout << "Informe o numero da Turma: ";
                        cin >> cod;
                        for (int j=0; j<contT; j++)
                        {
                            if (turmas[j]->getNrTurma()==cod)
                            {
                                comp=true;
                                alunos[i]->setTurmaAluno(cod);
                                alunos[i]->matricularCurso();
                                turmas[j]->matricularAluno(alunos[i]->getNome());
                                gotoxyB(6,11);
                                cout << "Matriculando Aluno na Turma :";
                                Sleep(1000);
                                cout << "  O K ";
                            }
                        }
                        if (comp == false)
                        {
                            gotoxyB(6,9);
                            cout << "Sem Turmas para o numero inserido, deseja inserir outro numero? S/N : ";
                            cin >> opcao2;
                            opcao2 = toupper(opcao2);
                        }
                    }
                    while (opcao2 == 'S');
                }
            }
            if (compare == false)
            {
                gotoxyB(4,9);
                cout << "Nao foram encontrados Alunos com o nome inserido, deseja inserir outro nome ? S/N : ";
                cin >> opcao;
                opcao = toupper(opcao);
            }
        }
        while (opcao == 'S');
    }
    else
    {
        gotoxyB(20,21);
        cout << "Nao existem alunos ou turmas cadastrados.";
    }
    gotoxyB(20,22);
    cout << "Voltando para a tela inicial.";
    Sleep(2000);
}

void MatricularProfessor(int &contT,int &contP,Turma * turmas[],Professor * professores[])
{
    string nome;
    bool compare=false,comp=false;
    char opcao='n',opcao2='n';
    int cod;
    Tela*tela;
    tela->limpaTela();
    gotoxyB(4,4);
    cout << "M a t r i c u l a r  -  P r o f e s s o r";
    gotoxyB(6,6);
    cout << "Verificando se existem Professores e Turmas cadastrados";
    Sleep(1000);
    if (contT>0 && contP>0)
    {
        do
        {
            opcao ='n';
            gotoxyB(6,8);
            cout << "Informe o Nome do Professor: ";
            cin.ignore();
            getline(cin,nome);
            for (int i=0; i<contP; i++)
            {
                if (professores[i]->getNome()==nome)
                {
                    compare=true;
                    cin.ignore();
                    gotoxyB(6,9);
                    cout << "Professor encontrado.";
                    do
                    {
                        comp == false;
                        gotoxyB(6,10);
                        cout << "Informe o numero da Turma: ";
                        cin >> cod;
                        for (int j=0; j<contT; j++)
                        {
                            if (turmas[j]->getNrTurma()==cod)
                            {
                                comp=true;
                                professores[i]->setTurmaProfessor(cod);
                                turmas[j]->alocarProfessor(professores[i]->getNome());
                                gotoxyB(6,11);
                                cout << "Matriculando Professor na Turma :";
                                Sleep(1000);
                                cout << "  O K ";
                            }
                        }
                        if (comp == false)
                        {
                            gotoxyB(6,9);
                            cout << "Sem Turmas para o numero inserido, deseja inserir outro numero? S/N : ";
                            cin >> opcao2;
                            opcao2 = toupper(opcao2);
                        }
                    }
                    while (opcao2 == 'S');
                }
            }
            if (compare == false)
            {
                gotoxyB(4,9);
                cout << "Nao foram encontrados Professores com o nome inserido, deseja inserir outro nome ? S/N : ";
                cin >> opcao;
                opcao = toupper(opcao);
            }
        }
        while (opcao == 'S');
    }
    else
    {
        gotoxyB(20,21);
        cout << "Nao existem Professores ou turmas cadastrados.";
    }
    gotoxyB(20,22);
    cout << "Voltando para a tela inicial.";
    Sleep(2000);
}
void IncluirAvaliacao(int &contA,int &contT,int &contAV,Avaliacao * avaliacao[],Aluno * alunos[],Turma * turmas[])
{
    string nome;
    bool compare=false, comp=false;
    char opcao='n',opcao2='n';
    int cod;
    Tela*tela;
    tela->limpaTela();
    gotoxyB(4,4);
    cout << "I n c l u i r  -  A v a l i a c a o";
    gotoxyB(6,6);
    cout << "Verificando se existem Alunos e Turmas cadastrados";
    Sleep(1000);
    if (contA > 0 && contT > 0)
    {
        do
        {
            opcao ='n';
            gotoxyB(6,8);
            cout << "Informe o Nome do Aluno: ";
            cin.ignore();
            getline(cin,nome);
            for (int i=0; i<contA; i++)
            {
                if (alunos[i]->getNome()==nome)
                {
                    compare=true;
                    gotoxyB(6,9);
                    cout << "Aluno encontrado.";
                    do
                    {
                        opcao2 == 'n';
                        gotoxyB(6,10);
                        cout << "Informe o numero da Turma: ";
                        cin >> cod;
                        for (int j=0; j<contT; j++)
                        {
                            if (alunos[i]->getTurmaAluno(j)==cod)
                            {
                                comp=true;
                                avaliacao[contAV] = new Avaliacao(nome,cod);
                                contAV++;
                                gotoxyB(6,16);
                                cout << "Salvando Avaliacao :";
                                Sleep(1000);
                                cout << "  O K ";
                            }
                        }
                        if (comp == false)
                        {
                            gotoxyB(6,11);
                            cout << "Aluno nao e dessa turma, deseja inserir outro numero? S/N : ";
                            cin >> opcao2;
                            opcao2 = toupper(opcao2);
                        }
                    }
                    while (opcao2 == 'S');
                }
            }
            if (compare == false)
            {
                gotoxyB(4,9);
                cout << "Nao foram encontrados Alunos com o nome inserido, deseja inserir outro nome ? S/N : ";
                cin >> opcao;
                opcao = toupper(opcao);
            }
        }
        while (opcao == 'S');
    }
    else
    {
        gotoxyB(20,21);
        cout << "Nao existem Alunos ou turmas cadastrados.";
        Sleep(1500);
    }
}
void consultaAvaliacao (int &contAV, Avaliacao * avaliacao[])
{
    string nome;
    bool compare;
    char opcao;
    gotoxyB(6,6);
    cout << "Verificando se existem Registros de avaliacoes.";
    Sleep(1000);
    if (contAV>0)
    {
        do
        {
            compare = false;
            opcao ='n';
            for (int i=0; i<contAV; i++)
            {
                gotoxyB(6,8);
                cout << "Informe o Nome do Aluno: ";
                cin.ignore();
                getline(cin,nome);
                if (avaliacao[i]->getNomeAluno() == nome)
                {
                    compare = true;
                    avaliacao[i]->consultaAvaliacao();
                }
                if (compare==false)
                {
                    gotoxyB(4,9);
                    cout << "Nao foram encontrados Alunos com o nome inserido, deseja inserir outro nome ? S/N : ";
                    cin >> opcao;
                    opcao = toupper(opcao);
                }
            }
        }
        while (opcao == 'S' && compare==false);
    }
    else
    {
        gotoxyB(15,21);
        cout << "Nao existem Avaliacos lancadas, insira uma primeiro.";
        gotoxyB(15,22);
        cout << "Enter Para voltar a tela inicial.";
    }
    getch();
}
