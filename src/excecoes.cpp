#include "excecoes.h"
#include <exception>
#include <iostream>

const char* ErroDeJogoExcecao::what() const noexcept {
  return "Ops, ocorreu um erro!";
}

const char* ErroDeStringExcecao::what() const noexcept {
  return "Essa entrada é inválida!";
}
