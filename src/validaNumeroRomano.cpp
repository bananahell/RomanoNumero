/**
 * @file validaNumeroRomano.cpp
 * 
 * @brief Validador de números romanos.
 *
 * @author Pedro Nogueira - 14/0065032
 *
 */

#include <validaNumeroRomano.hpp>


int converteRomano(string numeroRomano) {

  /*
   * 1. A letter repeats its value that many times (XXX = 30, CC = 200, etc.). A letter can only be repeated three times.
   * 2. If one or more letters are placed after another letter of greater value, add that amount.
   * 3. If a letter is placed before another letter of greater value, subtract that amount.
   *   a. Only subtract powers of ten (I, X, or C, but not V or L)
   *   b. Only subtract one number from another.
   *   c. Do not subtract a number from one that is more than 10 times greater (that is, you can subtract 1 from 10 [IX] but not 1 from 20—there is no such number as IXX.)
   * 4. A bar placed on top of a letter or string of letters increases the numeral's value by 1,000 times.
   */
  if (!avaliaRomano(numeroRomano)) {
    return -1;
  }

  int numeroDecimal = 0;
  vector<int> letras;
  for (unsigned int i = 0; i < numeroRomano.size(); i++) {
    letras.push_back(converteUmaLetra(numeroRomano.at(i)));
  }
  letras.push_back(0);

  for (unsigned int i = 0; i < numeroRomano.size(); i++) {
    if (letras[i] == letras[i+1]) {
      i = adicionaMesmasLetras(&numeroDecimal, letras, i);
    } else if (letras[i] > letras[i+1]) {
      i = adicionaOutrasLetras(&numeroDecimal, letras, i);
    } else {
      i = subtraiLetras(&numeroDecimal, letras, i);
    }
  }
  
  return numeroDecimal;

}

bool avaliaRomano(string numeroRomano) {
  for (unsigned int i = 0; i < numeroRomano.size(); i++) {

    if (numeroRomano.size() != 0 && (numeroRomano.at(i) == 'N' || numeroRomano.at(i) == 'n')) {
      return false;
    }

    if (numeroRomano.at(i) != 'N' && numeroRomano.at(i) != 'n' && 
        numeroRomano.at(i) != 'I' && numeroRomano.at(i) != 'i' && 
        numeroRomano.at(i) != 'V' && numeroRomano.at(i) != 'v' && 
        numeroRomano.at(i) != 'X' && numeroRomano.at(i) != 'x' && 
        numeroRomano.at(i) != 'L' && numeroRomano.at(i) != 'l' && 
        numeroRomano.at(i) != 'C' && numeroRomano.at(i) != 'c' && 
        numeroRomano.at(i) != 'D' && numeroRomano.at(i) != 'd' && 
        numeroRomano.at(i) != 'M' && numeroRomano.at(i) != 'm') {
      return false;
    }

    if (i < numeroRomano.size() - 1) {

      if (converteUmaLetra(numeroRomano.at(i)) <= converteUmaLetra(numeroRomano.at(i+1)) && 
          (numeroRomano.at(i) == 'V' || numeroRomano.at(i) == 'v' ||
          numeroRomano.at(i) == 'L' || numeroRomano.at(i) == 'l' ||
          numeroRomano.at(i) == 'D' || numeroRomano.at(i) == 'd')) {
        return false;
      }

      if (converteUmaLetra(numeroRomano.at(i)) < converteUmaLetra(numeroRomano.at(i+1)) && 
          converteUmaLetra(numeroRomano.at(i)) * 10 != converteUmaLetra(numeroRomano.at(i+1)) && 
          converteUmaLetra(numeroRomano.at(i)) * 5 != converteUmaLetra(numeroRomano.at(i+1))) {
        return false;
      }

      if (i < numeroRomano.size() - 3) {
        if (numeroRomano.at(i) == numeroRomano.at(i+1)) {
          if (numeroRomano.at(i) == numeroRomano.at(i+2)) {
            if (numeroRomano.at(i) == numeroRomano.at(i+3)) {
              return false;
            }
          }
        }
      }

    }

  }
  return true;
}

int converteUmaLetra(char letraAtual) {
  switch (letraAtual) {
  case 'n':
  case 'N':
    return 0;
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
int adicionaMesmasLetras(int* numeroDecimal, vector<int> letras, int i) {
  int resultado = letras[i] + letras[i+1];
  if (letras[i] == letras[i+2]) {
    resultado += letras[i+2];
    *numeroDecimal += resultado;
    return i + 1;
  }
  *numeroDecimal += resultado;
  return i + 1;
}
int adicionaOutrasLetras(int* numeroDecimal, vector<int> letras, int i) {
  int resultado = letras[i] + letras[i+1];
  int j;
  for (j = 0; j > -1; j++) {
    if (letras[i+j+2] == 0) {
      *numeroDecimal += resultado;
      break;
    }
    if (letras[i+j+1] > letras[i+j+2]) {
      resultado += letras[i+j+2];
    } else {
      *numeroDecimal += resultado;
      break;
    }
  }
  return i + j + 1;
}
int subtraiLetras(int* numeroDecimal, vector<int> letras, int i) {
  *numeroDecimal += letras[i+1] - letras[i];
  return i + 1;
}
