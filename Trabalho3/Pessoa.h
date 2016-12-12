#ifndef PESSOA_H
#define PESSOA_H

#include <string>
#include <iostream>
#include <string>

using namespace std;

class Pessoa
{
    protected:
        string nome,endereco,telefone;
    public:
        Pessoa();
        virtual ~Pessoa();
        string getNome();
        string getEndereco();
        string getTelefone();
        virtual void cadastrar ()=0;
};

#endif // PESSOA_H
