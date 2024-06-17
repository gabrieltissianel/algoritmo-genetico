//
// Created by gabriel on 4/25/24.
//

#ifndef ITEM_H
#define ITEM_H
#include <string>
#include <vector>


class Item {
private:
    const int numero;
    const float peso;
    const int utilidade;
    const float preco;

public:
    Item(int numero, float peso, int utilidade, float preco);

    [[nodiscard]] int getNumero() const;
    [[nodiscard]] float getPeso() const;
    [[nodiscard]] int getUtilidade() const;
    [[nodiscard]] float getPreco() const;

    static std::vector<Item> lerCSVdeItens(std::ifstream file);
};



#endif //ITEM_H
