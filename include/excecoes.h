#ifndef PDS2_EXCECOES_TERMO_H
#define PDS2_EXCECOES_TERMO_H

#include <exception>
/**
 * @brief Lança uma exceção para um erro genérico inesperado. 
*/
class ErroDeJogoExcecao : public std::exception {
    public:
    virtual const char* what() const noexcept;
};
/**
 * @brief Lança exceção quando a entrada tem um tamanho inválido.
*/
class EntradaInvalidaExcecao : public ErroDeJogoExcecao {
    public:
    virtual const char* what() const noexcept;
};
/**
 * @brief Lança exceção se o construtor não for válido.
*/
class ErroConstrutorInvalido : public ErroDeJogoExcecao {
 public:
    virtual const char* what() const noexcept;
};
/**
 * @brief Lança exceção se a opção for diferente de Y/N.
*/
class OpcaoInvalidaExcecao : public ErroDeJogoExcecao {
 public:
    virtual const char* what() const noexcept;
};

#endif //  PDS2_EXCECOES_H