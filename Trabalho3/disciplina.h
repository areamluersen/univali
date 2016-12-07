#ifndef DISCIPLINA_H
#define DISCIPLINA_H
#include <string>

using namespace std;
class Curso;

class Disciplina
{
    int codigo,cargaHoraria,cursoDisciplina;
    string descricao,ementa,bibliografia;
    public:
        Disciplina();
        virtual ~Disciplina();
        void cadastrar();
        int getCodigo();
        void setCursoDisciplina(int);
};

#endif // DISCIPLINA_H
