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

void CadastraTurma(Disciplina * disciplinas[],Turma * turmas[]);
void CadastraDisciplina(Disciplina * disciplinas[],Curso * cursos[]);
void CadastraCurso(Professor * professores[],Curso * cursos[]);
void MatricularAluno(Turma * turmas[],Aluno * alunos[]);
void MatricularProfessor(Turma * turmas[],Professor * professores[]);
void IncluirAvaliacao(Avaliacao * avaliacao[],Aluno * alunos[],Turma * turmas[]);
void consultaAvaliacao(Avaliacao * Avaliacao[]);
void AlocarCoordenador(Professor * professores[],Curso * cursos[]);
void MudarSituacao(Aluno * alunos[]);
void PrintAluno(Aluno * alunos[]);

//avaliacao.cpp - construtor nao esta sendo usado, e tem muita coisa, transformar em funçao
//case 13 - mudar os gotoxy para o lado, adicionar turma
//em varias funçoes tem um cout para limpar o s/n, adaptar os outros gotoxy para serem um seguido do outro
//ao incluir duas avaliações em turmas diferentes. Verificar,

int main()
{
    bool compare;
    int resp,cont=0;
    int i;
    Aluno * alunos[50];
    Professor * professores[50];
    Disciplina * disciplinas[20];
    Turma * turmas[50];
    Curso * cursos[10];
    Avaliacao * avaliacao[10];
    do
    {
        Tela::inicio();
        Tela::moldura();
        do
        {
            Tela::gotoxy(25,6);
            cin>>resp;
        }
        while (!(resp>0 && resp<14));
        switch(resp)
        {
        case 1 :
            compare=false;
            Tela::limpaTela();
            alunos[Aluno::getCont()] = new Aluno;
            alunos [Aluno::getCont()]->cadastrar();
            for(i=0; i<Aluno::getCont(); i++)
            {
                if(alunos[i]->getMatriculaAluno() == alunos[Aluno::getCont()]->getMatriculaAluno())
                {
                    Tela::gotoxy(7,22);
                    cout << "Operacao cancelada, pois aluno ja existe.";
                    delete alunos[Aluno::getCont()];
                    compare = true;
                    break;
                }
            }
            if(!(compare))
            {
                Tela::gotoxy(7,22);
                cout << "Aluno inserido com sucesso, Pressione Enter.";
                Aluno::addCont();
            }
            getch();
            break;
        case 2 :
            compare=false;
            Tela::limpaTela();
            professores[Professor::getCont()] = new Professor;
            professores[Professor::getCont()]->cadastrar();
            for(i=0; i<Professor::getCont(); i++)
            {
                if(professores[i]->getNome() == professores[Professor::getCont()]->getNome())
                {
                    Tela::gotoxy(7,22);
                    cout << "Operacao cancelada, pois professor ja existe.";
                    delete professores[Professor::getCont()];
                    compare = true;
                    break;
                }
            }
            if(!(compare))
            {
                Tela::gotoxy(7,22);
                cout << "Professor inserido com sucesso, Pressione Enter.";
                Professor::addCont();
            }
            getch();
            break;
        case 3 :
            Tela::limpaTela();
            CadastraTurma(disciplinas,turmas);
            getch();
            break;
        case 4 :
            Tela::limpaTela();
            CadastraDisciplina(disciplinas,cursos);
            getch();
            break;
        case 5 :
            Tela::limpaTela();
            CadastraCurso(professores,cursos);
            getch();
            break;
        case 6 :
            MatricularAluno(turmas,alunos);
            break;
        case 7 :
            MatricularProfessor(turmas,professores);
            break;
        case 8 :
            IncluirAvaliacao(avaliacao,alunos,turmas);
            break;
        case 9 :
            Tela::limpaTela();
            Tela::gotoxy(6,6);
            cout<<"Escolha uma opcao: ";
            Tela::gotoxy(6,8);
            cout<<"1) Aluno Consulta Avaliacao: ";
            Tela::gotoxy(6,9);
            cout<<"2) Diario de Classe: ";
            Tela::gotoxy(6,10);
            cout<<"3) Relatorio aluno geral: ";
            do
            {
                Tela::gotoxy(25,6);
                cin>>resp;
            }
            while (resp<1 || resp>3);
            switch(resp)
            {
            case 1 :
                Tela::limpaTela();
                consultaAvaliacao(avaliacao);
                break;
            case 2 :
                Tela::limpaTela();
                Tela::molduraPrint();
                Tela::gotoxy(7,6);
                cout << "Informe o codigo da turma: ";
                cin >> resp;
                for (i=0; i<Turma::getCont(); i++)
                {
                    if (turmas[i]-> getNrTurma() == resp)
                    {
                        turmas[i]-> printDiarioClasse();
                        break;
                    }
                }
                getch();
                break;
            case 3 :
                Tela::molduraPrint();
                getch();
                break;
            }
            break;
        case 10:
            Tela::limpaTela();
            AlocarCoordenador(professores,cursos);
            getch();
            break;
        case 11:
            Tela::limpaTela();
            MudarSituacao(alunos);
            getch();
            break;
        case 12:
            Tela::limpaTela();
            char resp2;
            do
            {
                Tela::gotoxy(6,8);
                cout << "1) Aluno";
                Tela::gotoxy(6,9);
                cout << "2) Professor";
                cout << "Digite o que deseja alterar: ";
                cin >> resp;
            }
            while(!(resp>0 && resp<3));
            switch(resp)
            {
            case 1:
            {
                compare=false;
                string matricula;
                Tela::limpaTela();
                do
                {
                    resp2 = 'N';
                    Tela::gotoxy(7,7);
                    cout << "                                                 ";
                    Tela::gotoxy(7,8);
                    cout << "                                                 ";
                    Tela::gotoxy(7,6);
                    cout << "Digite a matricula do aluno: ";
                    cin >> matricula;
                    for(i=0; i<Aluno::getCont(); i++)
                    {
                        if(alunos[i]->getMatriculaAluno() == matricula)
                        {
                            Tela::gotoxy(7,6);
                            cout << "                                                    ";
                            Tela::gotoxy(7,6);
                            cout << "Digite os novos dados:";
                            alunos[i]->cadastrar();
                            Tela::gotoxy(7,12);
                            cout << "Aluno atualizado.";
                            compare = true;
                            break;
                        }
                    }
                    if(!(compare))
                    {
                        do
                        {
                            Tela::gotoxy(7,7);
                            cout << "Nao existe o aluno inserido, deseja inserir";
                            Tela::gotoxy(7,8);
                            cout << "outra matricula ? S/N : ";
                            cin >> resp2;
                            resp2 = toupper(resp2);
                        }
                        while(!(resp2 == 'S' || resp2 == 'N'));
                    }
                }
                while(!(resp2 == 'N'));
                Tela::gotoxy(7,14);
                cout << "Voltando ao menu inicial.";
                break;
            }
            case 2:
            {
                compare=false;
                string nome;
                Tela::limpaTela();
                do
                {
                    resp2 = 'N';
                    Tela::gotoxy(7,7);
                    cout << "                                                 ";
                    Tela::gotoxy(7,8);
                    cout << "                                                 ";
                    Tela::gotoxy(7,6);
                    cout << "Digite o nome do professor: ";
                    cin >> nome;
                    for(i=0; i<Professor::getCont(); i++)
                    {
                        if(professores[i]->getNome() == nome)
                        {
                            Tela::gotoxy(7,6);
                            cout << "                                                    ";
                            Tela::gotoxy(7,6);
                            cout << "Digite os novos dados:";
                            professores[i]->cadastrar();
                            Tela::gotoxy(7,12);
                            cout << "Professor atualizado.";
                            compare = true;
                            break;
                        }
                    }
                    if(!(compare))
                    {
                        do
                        {
                            Tela::gotoxy(7,7);
                            cout << "Nao existe o professor inserido, deseja inserir";
                            Tela::gotoxy(7,8);
                            cout << "outro nome ? S/N : ";
                            cin >> resp2;
                            resp2 = toupper(resp2);
                        }
                        while(!(resp2 == 'S' || resp2 == 'N'));
                    }
                }
                while(!(resp2 == 'N'));
                Tela::gotoxy(7,14);
                cout << "Voltando ao menu inicial.";
                break;
            }
            }
            getch();
            break;
        case 13:
            Tela::limpaTela();
            PrintAluno(alunos);
            getch();
            break;
        }
    }
    while (cont<100);
    return 0;
}

void CadastraTurma(Disciplina * disciplinas[],Turma * turmas[])
{
    int i;
    char opcao;
    int cod;
    bool compare=false;
    if (Disciplina::getCont()>0)
    {
        Tela::gotoxy(4,4);
        cout << "I n c l u i r - T u r m a.";
        do
        {
            opcao='N';
            Tela::gotoxy(7,9);
            cout << "                                                            ";
            Tela::gotoxy(7,10);
            cout << "                                                            ";
            Tela::gotoxy(7,8);
            cout << "Informe o codigo da Disciplina: ";
            cin >> cod;
            for (i=0; i<Disciplina::getCont(); i++)
            {
                if (disciplinas[i]->getCodigo()==cod)
                {
                    compare=true;
                    break;
                }
            }
            if (compare == false)
            {
                do
                {
                    Tela::gotoxy(7,9);
                    cout << "Sem Disciplinas para o codigo inserido. ";
                    Tela::gotoxy(7,10);
                    cout << "Deseja inserir outro codigo ? S/N : ";
                    cin >> opcao;
                    opcao = toupper(opcao);
                }
                while(!(opcao == 'S' || opcao == 'N'));
                if(opcao == 'N')
                {
                    Tela::gotoxy(7,22);
                    cout << "Operacao cancelada, Pressione Enter.";
                }
            }
            else
            {
                compare = false;
                opcao = 'N';
                Tela::gotoxy(7,9);
                cout << "                                                                             ";
                turmas[Turma::getCont()]= new Turma;
                turmas[Turma::getCont()]->abrirTurma(Turma::getCont());
                for(i=0; i<Turma::getCont(); i++)
                {
                    if(turmas[i]->getMateria() == turmas[Turma::getCont()]->getMateria())
                    {
                        Tela::gotoxy(7,22);
                        cout << "Operacao cancelada, pois turma ja existe.";
                        delete turmas[Turma::getCont()];
                        compare = true;
                        break;
                    }
                }
                if(!(compare))
                {
                    Tela::gotoxy(7,22);
                    cout << "Turma inserido com sucesso, Pressione Enter.";
                    turmas[Turma::getCont()]->setCodDisciplina(cod);
                    Turma::addCont();
                }
            }
        }
        while (!(opcao == 'N'));
    }
    else
    {
        Tela::gotoxy(7,7);
        cout << "Nao existem Disciplinas para inserir a turma.";
        Tela::gotoxy(7,8);
        cout << "Insira uma Disciplina primeiro.";
    }
}

void CadastraDisciplina(Disciplina * disciplinas[],Curso * cursos[])
{
    int i;
    char opcao;
    int cod;
    bool compare=false;
    if (Curso::getCont()>0)
    {
        Tela::gotoxy(4,4);
        cout << "I n c l u i r - D i s c i p l i n a.";
        do
        {
            opcao = 'N';
            Tela::gotoxy(7,8);
            cout << "                                                            ";
            Tela::gotoxy(7,9);
            cout << "                                                            ";
            Tela::gotoxy(7,7);
            cout << "Informe o codigo do Curso: ";
            cin >> cod;
            for (i=0; i<Curso::getCont(); i++)
            {
                if (cursos[i]->getCodigo()==cod)
                {
                    compare=true;
                    break;
                }
            }
            if (compare == false)
            {
                do
                {
                    Tela::gotoxy(7,8);
                    cout << "Nao foram encontrados Cursos com o codigo inserido";
                    Tela::gotoxy(7,9);
                    cout << "Deseja inserir outro codigo ? S/N: ";
                    cin >> opcao;
                    opcao = toupper(opcao);
                }
                while(!(opcao == 'S' || opcao == 'N'));
                if(opcao == 'N')
                {
                    Tela::gotoxy(7,22);
                    cout << "Operacao cancelada, Pressione Enter.";
                }
            }
            else
            {
                compare=false;
                opcao = 'N';
                disciplinas[Disciplina::getCont()]=new Disciplina;
                disciplinas[Disciplina::getCont()] -> cadastrar();
                for(i=0; i<Disciplina::getCont(); i++)
                {
                    if(disciplinas[i]->getCodigo() == disciplinas[Disciplina::getCont()]->getCodigo())
                    {
                        Tela::gotoxy(7,22);
                        cout << "Operacao cancelada, pois disciplina ja existe.";
                        delete disciplinas[Disciplina::getCont()];
                        compare = true;
                        break;
                    }
                }
                if(!(compare))
                {
                    Tela::gotoxy(7,22);
                    cout << "Disciplina inserido com sucesso, Pressione Enter.";
                    disciplinas[Disciplina::getCont()] -> setCursoDisciplina(cod);
                    Disciplina::addCont();
                }
            }
        }
        while (!(opcao == 'N'));

    }
    else
    {
        Tela::gotoxy(7,7);
        cout << "Nao existem cursos para inserir a Disciplina.";
        Tela::gotoxy(7,8);
        cout << "Insira um curso primeiro.";
    }
}

void CadastraCurso(Professor * professores[],Curso * cursos[])
{
    int i;
    char opcao;
    string coord;
    bool compare=false;
    cursos[Curso::getCont()]= new Curso;
    cursos[Curso::getCont()]->cadastrar();
    for(i=0; i<Curso::getCont(); i++)
    {
        if(cursos[i]->getCodigo() == cursos[Curso::getCont()]->getCodigo())
        {
            Tela::gotoxy(7,22);
            cout << "Operacao cancelada, pois curso ja existe.";
            delete cursos[Curso::getCont()];
            compare = true;
            break;
        }
    }
    if(!(compare))
    {
        do
        {
            opcao = 'N';
            Tela::gotoxy(7,10);
            cout << "                                                            ";
            Tela::gotoxy(7,11);
            cout << "                                                            ";
            Tela::gotoxy(50,9);
            cout << "                         ";
            Tela::gotoxy(7,9);
            cout << "Informe o nome do professor Coordenador do curso : ";
            cin.ignore();
            getline(cin,coord);
            for (i=0; i<Professor::getCont(); i++)
            {
                if (professores[i]->getNome()==coord)
                {
                    compare=true;
                    break;
                }
            }
            if (compare == false)
            {
                do
                {
                    cursos[Curso::getCont()]->setCoordenador("Sem Coordenador");
                    Tela::gotoxy(7,10);
                    cout << "Nao existe o nome inserido, deseja inserir";
                    Tela::gotoxy(7,11);
                    cout << "outro nome ? S/N : ";
                    cin >> opcao;
                    opcao = toupper(opcao);
                }
                while(!(opcao == 'S' || opcao == 'N'));
                if(opcao == 'N')
                {
                    Tela::gotoxy(7,22);
                    cout << "Operacao cancelada, Pressione Enter.";
                }
            }
            else
            {
                Tela::gotoxy(45,10);
                cout << "                             ";
                Tela::gotoxy(7,10);
                cout << "Resultado encontrado, registrando coordenador.";
                cursos[Curso::getCont()]->setCoordenador(coord);
                Sleep(1000);
            }
        }
        while (compare == false && opcao == 'S');
        Curso::addCont();
        Tela::gotoxy(7,22);
        cout << "Curso inserido com sucesso, Pressione Enter.";
    }
}

void MatricularAluno(Turma * turmas[],Aluno * alunos[])
{
    int i;
    string nome;
    bool compare=false, comp=false;
    char opcao,opcao2;
    int cod;
    Tela::limpaTela();
    Tela::gotoxy(4,4);
    cout << "M a t r i c u l a r  - A l u n o" ;
    Tela::gotoxy(6,6);
    cout << "Verificando se existem Alunos e Turmas cadastrados";
    Sleep(1000);
    if (Turma::getCont()>0 && Aluno::getCont()>0)
    {
        do
        {
            opcao ='N';
            Tela::gotoxy(4,9);
            cout << "                                                            ";
            Tela::gotoxy(4,10);
            cout << "                                                            ";
            Tela::gotoxy(6,8);
            cout << "Informe o Nome do Aluno: ";
            cin.ignore();
            getline(cin,nome);
            for (i=0; i<Aluno::getCont(); i++)
            {
                if (alunos[i]->getNome()==nome)
                {
                    compare=true;
                    Tela::gotoxy(6,9);
                    cout << "Aluno encontrado.";
                    do
                    {
                        opcao ='N';
                        Tela::gotoxy(6,9);
                        cout << "                                                            ";
                        Tela::gotoxy(6,10);
                        cout << "                                                            ";
                        Tela::gotoxy(6,10);
                        cout << "Informe o numero da Turma: ";
                        cin >> cod;
                        for (int j=0; j<Turma::getCont(); j++)
                        {
                            if (turmas[j]->getNrTurma()==cod)
                            {
                                comp=true;
                                alunos[i]->setTurmaAluno(cod);
                                alunos[i]->matricularCurso();
                                turmas[j]->matricularAluno(alunos[i]->getNome());
                                Tela::gotoxy(6,11);
                                cout << "Matriculando Aluno na Turma :";
                                getch();
                                cout << "  O K ";
                                break;
                            }
                        }
                        if (comp == false)
                        {
                            do
                            {
                                Tela::gotoxy(6,9);
                                cout << "Sem Turmas para o numero inserido, deseja inserir";
                                Tela::gotoxy(6,10);
                                cout << "outro numero? S/N : ";
                                cin >> opcao2;
                                opcao2 = toupper(opcao2);
                            }
                            while(!(opcao2 == 'S' || opcao2 == 'N'));
                            if(opcao == 'N')
                            {
                                Tela::gotoxy(7,22);
                                cout << "Operacao cancelada, Pressione Enter.";
                            }
                        }
                    }
                    while (opcao2 == 'S');
                }
            }
            if (compare == false)
            {
                do
                {
                    Tela::gotoxy(4,9);
                    cout << "Nao foram encontrados Alunos com o nome inserido, deseja inserir";
                    Tela::gotoxy(4,10);
                    cout << "outro nome ? S/N : ";
                    cin >> opcao;
                    opcao = toupper(opcao);
                }
                while(!(opcao == 'S' || opcao == 'N'));
            }
        }
        while (opcao == 'S');
    }
    else
    {
        Tela::gotoxy(20,21);
        cout << "Nao existem alunos ou turmas cadastrados.";
    }
    Tela::gotoxy(20,22);
    cout << "Voltando para a tela inicial.";
    getch();
}

void MatricularProfessor(Turma * turmas[],Professor * professores[])
{
    int i;
    string nome;
    bool compare=false,comp=false;
    char opcao='N',opcao2='N';
    int cod;
    Tela::limpaTela();
    Tela::gotoxy(4,4);
    cout << "M a t r i c u l a r  -  P r o f e s s o r";
    Tela::gotoxy(6,6);
    cout << "Verificando se existem Professores e Turmas cadastrados";
    Sleep(1000);
    if (Turma::getCont()>0 && Professor::getCont()>0)
    {
        do
        {
            opcao ='N';
            Tela::gotoxy(4,9);
            cout << "                                                            ";
            Tela::gotoxy(4,10);
            cout << "                                                            ";
            Tela::gotoxy(6,8);
            cout << "Informe o Nome do Professor: ";
            cin.ignore();
            getline(cin,nome);
            for (i=0; i<Professor::getCont(); i++)
            {
                if (professores[i]->getNome()==nome)
                {
                    compare=true;
                    cin.ignore();
                    Tela::gotoxy(6,9);
                    cout << "Professor encontrado.";
                    do
                    {
                        Tela::gotoxy(6,9);
                        cout << "                                                            ";
                        Tela::gotoxy(6,10);
                        cout << "                                                            ";
                        Tela::gotoxy(6,10);
                        cout << "Informe o numero da Turma: ";
                        cin >> cod;
                        for (int j=0; j<Turma::getCont(); j++)
                        {
                            if (turmas[j]->getNrTurma()==cod)
                            {
                                comp=true;
                                professores[i]->setTurmaProfessor(cod);
                                turmas[j]->alocarProfessor(professores[i]->getNome());
                                Tela::gotoxy(6,11);
                                cout << "Matriculando Professor na Turma :";
                                getch();
                                cout << "  O K ";
                                break;
                            }
                        }
                        if (comp == false)
                        {
                            do
                            {
                                Tela::gotoxy(6,9);
                                cout << "Sem Turmas para o numero inserido, deseja inserir";
                                Tela::gotoxy(6,10);
                                cout << "outro numero? S/N : ";
                                cin >> opcao2;
                                opcao2 = toupper(opcao2);
                            }
                            while(!(opcao2 == 'S' || opcao2 == 'N'));
                            if(opcao == 'N')
                            {
                                Tela::gotoxy(7,22);
                                cout << "Operacao cancelada, Pressione Enter.";
                            }
                        }
                    }
                    while (opcao2 == 'S');
                }
            }
            if (compare == false)
            {
                do
                {
                    Tela::gotoxy(4,9);
                    cout << "Nao foram encontrados Professores com o nome inserido, deseja inserir";
                    Tela::gotoxy(4,10);
                    cout << "outro nome ? S/N : ";
                    cin >> opcao;
                    opcao = toupper(opcao);
                }
                while(!(opcao == 'S' || opcao == 'N'));
            }
        }
        while (opcao == 'S');
    }
    else
    {
        Tela::gotoxy(20,21);
        cout << "Nao existem Professores ou turmas cadastrados.";
    }
    Tela::gotoxy(20,22);
    cout << "Voltando para a tela inicial.";
    getch();
}

void IncluirAvaliacao(Avaliacao * avaliacao[],Aluno * alunos[],Turma * turmas[])
{
    int i;
    string nome;
    bool compare=false, comp=false;
    char opcao='N',opcao2='N';
    int cod;
    Tela::limpaTela();
    Tela::gotoxy(4,4);
    cout << "I n c l u i r  -  A v a l i a c a o";
    Tela::gotoxy(6,6);
    cout << "Verificando se existem Alunos e Turmas cadastrados";
    Sleep(1000);
    if (Aluno::getCont() > 0 && Turma::getCont() > 0)
    {
        do
        {
            opcao ='N';
            Tela::gotoxy(4,9);
            cout << "                                                            ";
            Tela::gotoxy(4,10);
            cout << "                                                            ";
            Tela::gotoxy(6,8);
            cout << "Informe o Nome do Aluno: ";
            cin.ignore();
            getline(cin,nome);
            for (i=0; i<Aluno::getCont(); i++)
            {
                if (alunos[i]->getNome()==nome)
                {
                    compare=true;
                    Tela::gotoxy(6,9);
                    cout << "Aluno encontrado.";
                    do
                    {
                        opcao2='N';
                        Tela::gotoxy(6,11);
                        cout << "                                                            ";
                        Tela::gotoxy(6,12);
                        cout << "                                                            ";
                        Tela::gotoxy(6,10);
                        cout << "Informe o numero da Turma: ";
                        cin >> cod;
                        for (int j=0; j<Turma::getCont(); j++)
                        {
                            if (alunos[i]->getTurmaAluno(j)==cod)
                            {
                                comp=true;
                                avaliacao[Avaliacao::getCont()] = new Avaliacao(nome,cod);
                                Avaliacao::addCont();
                                Tela::gotoxy(6,16);
                                cout << "Salvando Avaliacao :";
                                getch();
                                cout << "  O K ";
                                break;
                            }
                        }
                        if (comp == false)
                        {
                            do
                            {
                                Tela::gotoxy(6,11);
                                cout << "Aluno nao e dessa turma, deseja inserir";
                                Tela::gotoxy(6,12);
                                cout << "outro numero? S/N : ";
                                cin >> opcao2;
                                opcao2 = toupper(opcao2);
                            }
                            while(!(opcao2 == 'S' || opcao2 == 'N'));
                            if(opcao2 == 'N')
                            {
                                Tela::gotoxy(7,22);
                                cout << "Operacao cancelada, Pressione Enter.";
                            }
                        }
                    }
                    while (opcao2 == 'S');
                }
            }
            if (compare == false)
            {
                do
                {
                    Tela::gotoxy(4,9);
                    cout << "Nao foram encontrados Alunos com o nome inserido, deseja inserir";
                    Tela::gotoxy(4,10);
                    cout << "outro nome ? S/N : ";
                    cin >> opcao;
                    opcao = toupper(opcao);
                }
                while(!(opcao == 'S' || opcao == 'N'));
                if(opcao == 'N')
                {
                    Tela::gotoxy(7,22);
                    cout << "Operacao cancelada, Pressione Enter.";
                }
            }
        }
        while (opcao == 'S');
    }
    else
    {
        Tela::gotoxy(20,21);
        cout << "Nao existem Alunos ou turmas cadastrados.";
        getch();
    }
}

void consultaAvaliacao (Avaliacao * avaliacao[])
{
    int i;
    string nome;
    bool compare;
    char opcao;
    Tela::gotoxy(6,6);
    cout << "Verificando se existem Registros de avaliacoes.";
    getch();
    if (Avaliacao::getCont()>0)
    {
        do
        {
            Tela::gotoxy(4,9);
            cout << "                                                            ";
            Tela::gotoxy(4,10);
            cout << "                                                            ";
            compare = false;
            opcao ='N';
            for (i=0; i<Avaliacao::getCont(); i++)
            {
                Tela::gotoxy(6,8);
                cout << "Informe o Nome do Aluno: ";
                cin.ignore();
                getline(cin,nome);
                if (avaliacao[i]->getNomeAluno() == nome)
                {
                    compare = true;
                    avaliacao[i]->consultaAvaliacao();
                    break;
                }
                if (compare==false)
                {
                    do
                    {
                        Tela::gotoxy(4,9);
                        cout << "Nao foram encontrados Alunos com o nome inserido, deseja inserir";
                        Tela::gotoxy(4,10);
                        cout << "outro nome ? S/N : ";
                        cin >> opcao;
                        opcao = toupper(opcao);
                    }
                    while(!(opcao == 'S' || opcao == 'N'));
                    if(opcao == 'N')
                    {
                        Tela::gotoxy(7,22);
                        cout << "Operacao cancelada, Pressione Enter.";
                    }
                }
            }
        }
        while (opcao == 'S' && compare==false);
    }
    else
    {
        Tela::gotoxy(15,21);
        cout << "Nao existem Avaliacos lancadas, insira uma primeiro.";
        Tela::gotoxy(15,22);
        cout << "Enter Para voltar a tela inicial.";
    }
    getch();
}

void AlocarCoordenador(Professor * professores[],Curso * cursos[])
{
    if(Curso::getCont() > 0 && Professor::getCont() > 0)
    {
        int i;
        char opcao;
        string coord;
        int cur;
        bool compare=false;
        cursos[Curso::getCont()]= new Curso;
        do
        {
            opcao='N';
            Tela::gotoxy(7,9);
            cout << "                                                            ";
            Tela::gotoxy(7,9);
            cout << "                                                            ";
            Tela::gotoxy(50,7);
            cout << "                         ";
            Tela::gotoxy(7,7);
            cout << "Informe o codigo do curso : ";
            cin >> cur;
            for (i=0; i<Curso::getCont(); i++)
            {
                if (cursos[i]->getCodigo()==cur)
                {
                    compare=true;
                    break;
                }
            }
            if (compare == false)
            {
                do
                {
                    Tela::gotoxy(7,9);
                    cout << "Nao existe o curso inserido, deseja inserir";
                    Tela::gotoxy(7,9);
                    cout << "outro codigo ? S/N : ";
                    cin >> opcao;
                    opcao = toupper(opcao);
                }
                while(!(opcao == 'S' || opcao == 'N'));
                if(opcao == 'N')
                {
                    Tela::gotoxy(7,22);
                    cout << "Operacao cancelada, Pressione Enter.";
                }
            }
            else
            {
                Tela::gotoxy(7,12);
                cout << "                                                            ";
                Tela::gotoxy(7,13);
                cout << "                                                            ";
                compare=false;
                opcao = 'N';
                Tela::gotoxy(45,10);
                cout << "                             ";
                Tela::gotoxy(7,10);
                cout << "Resultado encontrado, digite o nome do professor que deseja";
                Tela::gotoxy(7,11);
                cout << "tornar coordenador: ";
                cin.ignore();
                getline(cin,coord);
                for (i=0; i<Professor::getCont(); i++)
                {
                    if (professores[i]->getNome()==coord)
                    {
                        compare=true;
                        break;
                    }
                }
                if (compare == false)
                {
                    //cursos[Curso::getCont()]->setCoordenador("Sem Coordenador"); - ta no construtor
                    do
                    {
                        Tela::gotoxy(7,12);
                        cout << "Nao existe o nome inserido, deseja inserir";
                        Tela::gotoxy(7,13);
                        cout << "outro nome ? S/N : ";
                        cin >> opcao;
                        opcao = toupper(opcao);
                    }
                    while(!(opcao == 'S' || opcao == 'N'));
                }
                else
                {
                    Tela::gotoxy(45,10);
                    cout << "                             ";
                    Tela::gotoxy(7,13);
                    cout << "Resultado encontrado, registrando coordenador.";
                    cursos[Curso::getCont()]->setCoordenador(coord);
                    Sleep(1000);
                }
            }
        }
        while (!(opcao == 'N'));
        Curso::addCont();
        Tela::gotoxy(7,22);
        cout << "Coordenador alocado com sucesso, Pressione Enter.";
    }
    else
    {
        Tela::gotoxy(50,7);
        cout << "                         ";
        Tela::gotoxy(7,7);
        cout << "Nao existe nenhum curso/professor.";
    }
}

void MudarSituacao(Aluno * alunos[])
{
    int i;
    string matricula;
    char resp;
    bool compare = false;
    do
    {
        Tela::gotoxy(7,12);
        cout << "                                                            ";
        Tela::gotoxy(7,13);
        cout << "                                                            ";
        resp = 'N';
        Tela::gotoxy(7,6);
        cout << "Informe a matricula do aluno : ";
        cin >> matricula;
        for(i=0; i<=Aluno::getCont(); i++)
        {
            if(alunos[i]->getMatriculaAluno() == matricula)
            {
                int sit;
                do
                {
                    Tela::gotoxy(7,8);
                    cout << "1)Matriculado";
                    Tela::gotoxy(7,9);
                    cout << "2)Trancado";
                    Tela::gotoxy(7,10);
                    cout << "3)Formado";
                    Tela::gotoxy(7,11);
                    cout << "4)Evadido";
                    Tela::gotoxy(7,7);
                    cout << "Digite a situacao do aluno:";
                    cin >> sit;
                }
                while(!(sit>0 && sit <5));
                switch(sit)
                {
                case 1:
                    alunos[i]->matricularCurso();
                    break;
                case 2:
                    alunos[i]->trancar();
                    break;
                case 3:
                    alunos[i]->formar();
                    break;
                case 4:
                    alunos[i]->evadir();
                    break;
                }
                Tela::gotoxy(7,13);
                cout << "Situacao alterada";
                compare = true;
                break;
            }
        }
        if(!(compare))
        {
            do
            {
                Tela::gotoxy(7,12);
                cout << "Nao existe o aluno procurado, deseja inserir";
                Tela::gotoxy(7,13);
                cout << "outra matricula ? S/N : ";
                cin >> resp;
                resp = toupper(resp);
            }
            while(!(resp == 'S' || resp == 'N'));
            if(resp == 'N')
            {
                Tela::gotoxy(7,22);
                cout << "Operacao cancelada, Pressione Enter.";
            }
        }
    }
    while(!(resp == 'N'));
    Tela::gotoxy(7,14);
    cout << "Voltando para a tela inicial.";
}

void PrintAluno(Aluno * alunos[])
{
    int i;
    char opcao;
    bool compare=false;
    string matricula;
    Tela::limpaTela();
    Tela::gotoxy(4,4);
    cout << "M o s t r a r  - A l u n o" ;
    Tela::gotoxy(6,6);
    cout << "Verificando se existem Alunos cadastrados";
    Sleep(1000);
    if (Aluno::getCont()>0)
    {
        do
        {
            opcao = 'N';
            Tela::gotoxy(6,9);
            cout << "                                                          ";
            Tela::gotoxy(6,10);
            cout << "                                                          ";
            Tela::gotoxy(6,8);
            cout << "Informe a matricula do Aluno: ";
            cin >> matricula;
            for (i=0; i<Aluno::getCont(); i++)
            {
                if (alunos[i]->getMatriculaAluno()==matricula)
                {
                    compare=true;
                    Tela::gotoxy(6,9);
                    cout << "Aluno encontrado.";
                    Tela::gotoxy(6,10);
                    cout << "Nome: " << alunos[i]->getNome();
                    Tela::gotoxy(6,11);
                    cout << "Matricula: " << alunos[i]->getMatriculaAluno();
                    Tela::gotoxy(6,12);
                    cout << "Situacao: " << alunos[i]->getSituacaoAluno();
                    Tela::gotoxy(6,13);
                    cout << "Endereco: " << alunos[i]->getEndereco();
                    Tela::gotoxy(6,14);
                    cout << "Telefone: " << alunos[i]->getTelefone();
                    break;
                }
            }
            if (compare == false)
            {
                do
                {
                    Tela::gotoxy(6,9);
                    cout << "Nao foram encontrados alunos com essa matricula,";
                    Tela::gotoxy(6,10);
                    cout << "deseja inserir outra? S/N : ";
                    cin >> opcao;
                    opcao = toupper(opcao);
                }
                while(!(opcao == 'S' || opcao == 'N'));
            }
        }
        while (opcao == 'S');
    }
    else
    {
        Tela::gotoxy(20,21);
        cout << "Nao existem alunos ou turmas cadastrados.";
    }
    Tela::gotoxy(20,22);
    cout << "Voltando para a tela inicial.";
}
