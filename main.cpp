

#include "AlgoritmoGenetico.h"


int main() {

    AlgoritmoGenetico algoritmo_genetico = AlgoritmoGenetico(TORNEIO, UNIFORME, PHILAMBDA, MOCHILA);

    algoritmo_genetico.executar();

    return 0;
}
