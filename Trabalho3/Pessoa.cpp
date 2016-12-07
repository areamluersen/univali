#include "Pessoa.h"
#include <iostream>
#include <string>

using namespace std;

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
void Pessoa::setNome(string n)
{
    nome = n;
}
string Pessoa::getEndereco()
{
    return endereco;
}
void Pessoa::setEndereco(string cep)
{
    endereco = cep;
}

string Pessoa::getTelefone()
{
    return telefone;
}

void Pessoa::setTelefone(string tel)
{
    telefone = tel;
}
