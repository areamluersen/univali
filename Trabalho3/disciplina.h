#ifndef DISCIPLINA_H
#define DISCIPLINA_H

#include <string>
#include "windows.h"
#include <iostream>
#include <string>
#include "tela.h"

using namespace std;
class Curso;

class Disciplina
{
    int codigo,cargaHoraria,cursoDisciplina;
    string descricao,ementa,bibliografia;
    static int contD;
    public:
        Disciplina();
        virtual ~Disciplina();
        void cadastrar();
        int getCodigo();
        void setCursoDisciplina(int);
        static int getCont();
        static void addCont();
};

#endif // DISCIPLINA_H
