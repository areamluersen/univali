#ifndef AVALIACAO_H
#define AVALIACAO_H
#include <string>

using namespace std;

class Avaliacao
{
    float nota1,nota2,notaProvaFinal;
    string aluno,aprovacao;
    int frequencia,turma;
public:
    Avaliacao(string,int);
    virtual ~Avaliacao();
    float getNota1 ();
    float getNota2 ();
    float getProvaFinal ();
    string getAprovacao ();
    void setAprovacao (string);
    void setNota1 (float);
    void setNota2 (float);
    void setNotaProvaFinal (float);
    void setFrequencia (int);
    void setNomeAluno(string);
    string getNomeAluno ();
    void setCodigoTurma(int);
    void consultaAvaliacao ();

};

#endif // AVALIACAO_H
