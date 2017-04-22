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
  this->numeroRomano = "";
  this->numeroDecimal = -1;
}
RomanoNumero::RomanoNumero(string numeroRomano) {
  numeroDecimal = converteRomano(numeroRomano);
  if (numeroDecimal != -1) {
    setNumeroRomano(numeroRomano);
  } else {
    this->numeroRomano = "";
  }
}
RomanoNumero::RomanoNumero(int numeroDecimal) {
  if (numeroDecimal < 4000) {
    setNumeroDecimal(numeroDecimal);
    converteDecimal(numeroDecimal);
  } else {
    this->numeroDecimal = -1;
    this->numeroRomano = "";
  }
}


void RomanoNumero::converteDecimal(int numeroDecimal) {

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


string RomanoNumero::getNumeroRomano() {
  return numeroRomano;
}
int RomanoNumero::getNumeroDecimal() {
  return numeroDecimal;
}

void RomanoNumero::setNumeroRomano(string numeroRomano) {
  numeroDecimal = converteRomano(numeroRomano);
  this->numeroRomano = "";
  if (numeroDecimal != -1) {
    this->numeroRomano = numeroRomano;
  }
}
void RomanoNumero::setNumeroDecimal(int numeroDecimal) {
  if (numeroDecimal < 4000) {
    this->numeroDecimal = numeroDecimal;
    converteDecimal(numeroDecimal);
  } else {
    this->numeroDecimal = -1;
    this->numeroRomano = "";
  }
}
