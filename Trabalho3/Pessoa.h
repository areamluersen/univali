#ifndef PESSOA_H
#define PESSOA_H
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
        void setNome(string);//
        string getEndereco();
        void setEndereco(string);
        string getTelefone();
        void setTelefone(string);
        virtual void cadastrar ()=0;
};

#endif // PESSOA_H
