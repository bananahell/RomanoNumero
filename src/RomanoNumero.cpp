/**
 * @file RomanoNumero.cpp
 * 
 * @brief Arquivo com a classe RomanoNumero, classe responsável por converter número romanos em decimais e vice-versa.
 *
 * @author Pedro Nogueira - 14/0065032
 *
 */

#include <RomanoNumero.hpp>


RomanoNumero::RomanoNumero() {
  setNumeroDecimal(0);
}
RomanoNumero::RomanoNumero(string numeroRomano) {
  setNumeroRomano(numeroRomano);
}
RomanoNumero::RomanoNumero(long numeroDecimal) {
  setNumeroDecimal(numeroDecimal);
}

string RomanoNumero::getNumeroRomano() {
  return numeroRomano;
}
long RomanoNumero::getNumeroDecimal() {
  return numeroDecimal;
}

void RomanoNumero::setNumeroRomano(string numeroRomano) {
  this->numeroRomano = numeroRomano;
}
void RomanoNumero::setNumeroDecimal(long numeroDecimal) {
  this->numeroDecimal = numeroDecimal;
}
