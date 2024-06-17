//
// Created by gabriel on 4/25/24.
//

#include "Item.h"

#include <fstream>
#include <iostream>

Item::Item(int numero = 0, float peso = 0, int utilidade = 0, float preco = 0)
        : numero(numero),
          peso(peso),
          utilidade(utilidade),
          preco(preco) {
}

int Item::getNumero() const {
    return numero;
}

float Item::getPeso() const {
    return peso;
}

int Item::getUtilidade() const {
    return utilidade;
}

float Item::getPreco() const {
    return preco;
}

std::vector<Item> Item::lerCSVdeItens(std::ifstream file) {

    int numero {};
    float peso {};
    int utilidade {};
    float preco {};

    std::vector<Item> itens;
    char c;

    while(!file.eof()) {
        file >> numero >> c >> peso >> c >> utilidade >> c >> preco >> c;
        itens.emplace_back(numero, peso, utilidade, preco);
    }

    return itens;
}
