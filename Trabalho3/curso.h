#ifndef CURSO_H
#define CURSO_H
#include <string>

using namespace std;

class Curso
{
    int codigo;
    string descricao,coordenador;
    public:
        Curso();
        virtual ~Curso();
        void cadastrar ();
        int getCodigo ();
        string getCoordenador();
        void setCoordenador(string);
};

#endif // CURSO_H
