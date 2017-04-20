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
  setNumeroRomano("I");
  setNumeroDecimal(1);
}
RomanoNumero::RomanoNumero(string numeroRomano) {
  setNumeroRomano(numeroRomano);
  converte(numeroRomano);
}
RomanoNumero::RomanoNumero(long numeroDecimal) {
  setNumeroDecimal(numeroDecimal);
  /* converte(numeroDecimal); */
}


/*
 * 1. A letter repeats its value that many times (XXX = 30, CC = 200, etc.). A letter can only be repeated three times.
 * 2. If one or more letters are placed after another letter of greater value, add that amount.
 * 3. If a letter is placed before another letter of greater value, subtract that amount.
 *   a. Only subtract powers of ten (I, X, or C, but not V or L)
 *   b. Only subtract one number from another.
 *   c. Do not subtract a number from one that is more than 10 times greater (that is, you can subtract 1 from 10 [IX] but not 1 from 20—there is no such number as IXX.)
 * 4. A bar placed on top of a letter or string of letters increases the numeral's value by 1,000 times.
 */
void RomanoNumero::converte(string numeroRomano) {
	
    
    numeroDecimal = 0;
    vector<int> letras;
    for (unsigned int i = 0; i < numeroRomano.size(); i++) {
      letras.push_back(converteUmaLetra(numeroRomano.at(i)));
    }
    letras.push_back(0);
    
    for (unsigned int i = 0; i < numeroRomano.size(); i++) {
      if (letras[i] == letras[i+1]) {
        i = adicionaMesmasLetras(letras, i);
      } else if (letras[i] > letras[i+1]) {
        i = adicionaOutrasLetras(letras, i);
      } else {
        i = subtraiLetras(letras, i);
      }
    }
	
}
void RomanoNumero::converte(long numeroDecimal) {
  
}

int RomanoNumero::converteUmaLetra(char letraAtual) {
  switch (letraAtual) {
    case 'i':
    case 'I':
      return 1;
    case 'v':
    case 'V':
      return 5;
    case 'x':
    case 'X':
      return 10;
    case 'l':
    case 'L':
      return 50;
    case 'c':
    case 'C':
      return 100;
    case 'd':
    case 'D':
      return 500;
    case 'm':
    case 'M':
      return 1000;
  }
  return -1;
}

int RomanoNumero::adicionaMesmasLetras(vector<int> letras, int i) {
  int resultado = letras[i] + letras[i+1];
  if (letras[i] == letras[i+2]) {
    resultado += letras[i+2];
    numeroDecimal += resultado;
    return i + 1;
  }
  numeroDecimal += resultado;
  return i + 1;
}
int RomanoNumero::adicionaOutrasLetras(vector<int> letras, int i) {
  int resultado = letras[i] + letras[i+1];
  int j;
  for (j = 0; j > -1; j++) {
    if (letras[i+j+2] == 0) {
      numeroDecimal += resultado;
      break;
    }
    if (letras[i+j+1] > letras[i+j+2]) {
      resultado += letras[i+j+2];
    } else {
      numeroDecimal += resultado;
      break;
    }
  }
  return i + j + 1;
}
int RomanoNumero::subtraiLetras(vector<int> letras, int i) {
  numeroDecimal += letras[i+1] - letras[i];
  return i + 1;
}


string RomanoNumero::getNumeroRomano() {
  return numeroRomano;
}
long RomanoNumero::getNumeroDecimal() {
  return numeroDecimal;
}

void RomanoNumero::setNumeroRomano(string numeroRomano) {
  this->numeroRomano = numeroRomano;
  converte(numeroRomano);
}
void RomanoNumero::setNumeroDecimal(long numeroDecimal) {
  this->numeroDecimal = numeroDecimal;
}
