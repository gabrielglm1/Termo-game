#ifndef PDS2_EXCECOES_TERMO_H
#define PDS2_EXCECOES_TERMO_H

#include <exception>

class ErroDeJogoExcecao : public std::exception {
    public:
    virtual const char* what() const noexcept;
};

class ErroDeStringExcecao : public ErroDeJogoExcecao {
    public:
    virtual const char* what() const noexcept;
};

#endif //  PDS2_EXCECOES_H