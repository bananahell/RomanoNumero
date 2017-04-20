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
  /* converte(numeroRomano); */
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
void converte(string numeroRomano) {
	
  try {
    
    long resultado;
    vector<int> letras;
    for(int i = 0; i < numeroRomano.size(); i++) {
      letras.push_back(converteUmaLetra(numeroRomano.at(i)));
    }
    letras.push_back(0);
    
    for(int i = 0; i < numeroRomano.size(); i++) {
      if(letras[i] == letras[i+1]) {
        /* resultado += adicionaMesmasLetras(letras, i); */
      } else if(letras[i] > letras[i+1]) {
        /* resultado += adicionaOutrasLetras(letras, i); */
      } else {
        /* resultado += subtraiLetras(letras, i); */
      }
    }
    
    /* setNumeroDecimal(resultado); */
    
  } catch (Exception e) {
    
  }
	
}
void converte(long numeroDecimal) {
	
}

int converteUmaLetra(char letraAtual) {
  switch(letraAtual) {
    case 'i':
    case 'I':
      return I;
    case 'v':
    case 'V':
      return V;
    case 'x':
    case 'X':
      return X;
    case 'l':
    case 'L':
      return L;
    case 'c':
    case 'C':
      return C;
    case 'd':
    case 'D':
      return D;
    case 'm':
    case 'M':
      return M;
  }
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
