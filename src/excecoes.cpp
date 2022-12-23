#include "excecoes.h"
#include <exception>
#include <iostream>

const char* ErroDeJogoExcecao::what() const noexcept {
  return "Ops, ocorreu um erro!";
}

const char* ErroDeStringExcecao::what() const noexcept {
  return "Essa entrada é inválida!";
}

const char* ErroConstrutorInvalido::what() const noexcept {
  return "Essa inicialização não é permitida!";
}

const char* ErroParametroInvalido::what() const noexcept {
  return "Palavra não encontrada no dicionário!";
}
