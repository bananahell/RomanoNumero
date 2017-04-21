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
  setNumeroRomano("N");
  setNumeroDecimal(0);
}
RomanoNumero::RomanoNumero(string numeroRomano) {
  if (avaliaRomano(numeroRomano)) {
    setNumeroRomano(numeroRomano);
    converte(numeroRomano);
  } else {
    setNumeroRomano("N");
    converte(numeroRomano);
  }
}
RomanoNumero::RomanoNumero(int numeroDecimal) {
  setNumeroDecimal(numeroDecimal);
  converte(numeroDecimal);
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
void RomanoNumero::converte(int numeroDecimal) {
  
  numeroRomano = "";
  if (numeroDecimal == 0) {
    numeroRomano = "N";
  } else {
    /* SEM A REGRA 4, SÓ VOU ATÉ 3999 */
    constroiRomano(numeroDecimal - numeroDecimal%1000);
    numeroDecimal -= (numeroDecimal/1000) * 1000;
    constroiRomano(numeroDecimal - numeroDecimal%100);
    numeroDecimal -= (numeroDecimal/100) * 100;
    constroiRomano(numeroDecimal - numeroDecimal%10);
    numeroDecimal -= (numeroDecimal/10) * 10;
    constroiRomano(numeroDecimal);
  }
  
}

int RomanoNumero::converteUmaLetra(char letraAtual) {
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

void RomanoNumero::constroiRomano(int numero) {
  if (numero/1000 > 0) {
      insereLetrasRomanas(numero/1000, 1000);
  } else if (numero/100 > 0) {
      insereLetrasRomanas(numero/100, 100);
  } else if (numero/10 > 0) {
      insereLetrasRomanas(numero/10, 10);
  } else {
      insereLetrasRomanas(numero, 1);
  }
}
void RomanoNumero::insereLetrasRomanas(int numero, int grandeza) {
  switch (grandeza) {
    case 1000:
      switch (numero) {
        case 1:
          numeroRomano.append("M");
          break;
        case 2:
          numeroRomano.append("MM");
          break;
        case 3:
          numeroRomano.append("MMM");
          break;
        /* 
         * SEM A REGRA 4, SÓ VOU ATÉ 3999
         * case 5:
         * case 6:
         * case 7:
         * case 8:
         */
      }
      break;
    case 100:
      switch (numero) {
        case 1:
          numeroRomano.append("C");
          break;
        case 2:
          numeroRomano.append("CC");
          break;
        case 3:
          numeroRomano.append("CCC");
          break;
        case 4:
          numeroRomano.append("CD");
          break;
        case 5:
          numeroRomano.append("D");
          break;
        case 6:
          numeroRomano.append("DC");
          break;
        case 7:
          numeroRomano.append("DCC");
          break;
        case 8:
          numeroRomano.append("DCCC");
          break;
        case 9:
          numeroRomano.append("CM");
          break;
      }
      break;
    case 10:
      switch (numero) {
        case 1:
          numeroRomano.append("X");
          break;
        case 2:
          numeroRomano.append("XX");
          break;
        case 3:
          numeroRomano.append("XXX");
          break;
        case 4:
          numeroRomano.append("XL");
          break;
        case 5:
          numeroRomano.append("L");
          break;
        case 6:
          numeroRomano.append("LX");
          break;
        case 7:
          numeroRomano.append("LXX");
          break;
        case 8:
          numeroRomano.append("LXXX");
          break;
        case 9:
          numeroRomano.append("XC");
          break;
      }
      break;
    case 1:
      switch (numero) {
        case 1:
          numeroRomano.append("I");
          break;
        case 2:
          numeroRomano.append("II");
          break;
        case 3:
          numeroRomano.append("III");
          break;
        case 4:
          numeroRomano.append("IV");
          break;
        case 5:
          numeroRomano.append("V");
          break;
        case 6:
          numeroRomano.append("VI");
          break;
        case 7:
          numeroRomano.append("VII");
          break;
        case 8:
          numeroRomano.append("VIII");
          break;
        case 9:
          numeroRomano.append("IX");
          break;
      }
      break;
  }
}

bool RomanoNumero::avaliaRomano(string numeroRomano) {
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


string RomanoNumero::getNumeroRomano() {
  return numeroRomano;
}
int RomanoNumero::getNumeroDecimal() {
  return numeroDecimal;
}

void RomanoNumero::setNumeroRomano(string numeroRomano) {
  if (avaliaRomano(numeroRomano)) {
    this->numeroRomano = numeroRomano;
    converte(numeroRomano);
  }
}
void RomanoNumero::setNumeroDecimal(int numeroDecimal) {
  this->numeroDecimal = numeroDecimal;
  converte(numeroDecimal);
}
