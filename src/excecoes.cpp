#include "excecoes.h"
#include <exception>
#include <iostream>

const char* ErroDeJogoExcecao::what() const noexcept {
  return "Ops, ocorreu um erro!";
}

const char* OpcaoInvalidaExcecao::what() const noexcept {
  return "Essa opção não é permitida!";
}

const char* EntradaInvalidaExcecao::what() const noexcept {
  return "Essa entrada é inválida! Uma palavra deve ter 5 letras.";
}

const char* ErroConstrutorInvalido::what() const noexcept {
  return "Essa inicialização não é permitida!";
}
