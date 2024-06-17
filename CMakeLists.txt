cmake_minimum_required(VERSION 3.28)
project(AlgoritmoGenetico)

set(CMAKE_CXX_STANDARD 17)

add_executable(AlgoritmoGenetico main.cpp
        Individuo/Item.cpp
        Individuo/Item.h
        MetodoPopulacional/IMetodoPopulacional.h
        AlgoritmoGenetico.cpp
        AlgoritmoGenetico.h
        Individuo/Individuo.h
        Cruzamento/ICruzamento.h
        Gene/IGene.h
        Individuo/TipoMochila.cpp
        Individuo/TipoMochila.h
        Gene/GeneMochila.cpp
        Gene/GeneMochila.h
        Selecao/ISelecao.h
        Aleatorio.cpp
        Aleatorio.h
        Individuo/Individuo.cpp
        Individuo/ITipoIndividuo.h
        MetodoPopulacional/PhiLambda.cpp
        MetodoPopulacional/PhiLambda.h
        Cruzamento/Uniforme.cpp
        Cruzamento/Uniforme.h
        Selecao/Torneio.cpp
        Selecao/Torneio.h
)
