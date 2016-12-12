#include "Pessoa.h"

int qtde=0;

Pessoa::Pessoa()
{
    nome = "";
    qtde++;
}
Pessoa::~Pessoa()
{
    //dtor
}
string Pessoa::getNome()
{
    return nome;
}
string Pessoa::getEndereco()
{
    return endereco;
}

string Pessoa::getTelefone()
{
    return telefone;
}
