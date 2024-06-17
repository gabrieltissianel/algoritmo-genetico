//
// Created by gabriel on 5/13/24.
//

#ifndef ALGORITMOGENETICO_H
#define ALGORITMOGENETICO_H
#include <memory>

#include "Cruzamento/ICruzamento.h"
#include "Individuo/Individuo.h"
#include "MetodoPopulacional/IMetodoPopulacional.h"
#include "Selecao/ISelecao.h"


enum METODOPOPULACIONAL {
    PHILAMBDA
};

enum SELECAO {
    TORNEIO
};

enum TIPOINDIVIDUO {
    MOCHILA
};

enum CRUZAMENTO {
    UNIFORME
};

using namespace std;

using Populacao = vector<shared_ptr<Individuo>>;

class AlgoritmoGenetico {
private:
    unique_ptr<IMetodoPopulacional> metodo_populacional;
    unique_ptr<ISelecao> selecao;
    unique_ptr<ICruzamento> cruzamento;
    unique_ptr<Populacao> pais;
    unique_ptr<Populacao> filhos;

public:
    AlgoritmoGenetico(SELECAO selecao, CRUZAMENTO cruzamento, METODOPOPULACIONAL metodo_populacional, TIPOINDIVIDUO tipo_individuo);

    void executar();
};



#endif //ALGORITMOGENETICO_H
