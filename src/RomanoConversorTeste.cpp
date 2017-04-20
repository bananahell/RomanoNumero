/**
 * @file RomanoConversorTeste.cpp
 *
 * @brief Testador da classe de números romanos, vindos do arquivo RomanoNumero.hpp.
 * Usa a biblioteca de teste da Google gtest.
 *
 * @author Pedro Nogueira - 14/0065032
 *
 */

#include <gtest/gtest.h>

#include <RomanoNumero.hpp>


/**
 * @brief Teste InstanciandoRomanoNumero, testando se a classe está sendo instanciada sem parâmetro.
 *
 */
TEST(Instanciando, NenhumParametro) {
  RomanoNumero* numTeste = new RomanoNumero();
  EXPECT_EQ(1, numTeste->getNumeroDecimal());
  delete numTeste;
}
/**
 * @brief Teste InstanciandoRomanoNumero, testando se a classe está sendo instanciada com número decimal.
 *
 */
TEST(Instanciando, NumeroDecimal) {
  RomanoNumero* numTeste = new RomanoNumero(42);
  EXPECT_EQ(42, numTeste->getNumeroDecimal());
  delete numTeste;
}
/**
 * @brief Teste InstanciandoRomanoNumero, testando se a classe está sendo instanciada com número romano.
 *
 */
TEST(Instanciando, NumeroRomano) {
  RomanoNumero* numTeste = new RomanoNumero("XCVII");
  EXPECT_EQ("XCVII", numTeste->getNumeroRomano());
  EXPECT_EQ(97, numTeste->getNumeroDecimal());
  delete numTeste;
}

/**
 * @brief Teste InstanciandoRomanoNumero, testando se a classe está sendo instanciada com número romano.
 *
 */
TEST(Setando, Decimal) {
  RomanoNumero* numTeste = new RomanoNumero(42);
  numTeste->setNumeroDecimal(97);
  EXPECT_EQ(97, numTeste->getNumeroDecimal());
  delete numTeste;
}
/**
 * @brief Teste InstanciandoRomanoNumero, testando se a classe está sendo instanciada com número romano.
 *
 */
TEST(Setando, Romano) {
  RomanoNumero* numTeste = new RomanoNumero("XCVII");
  numTeste->setNumeroRomano("XLII");
  EXPECT_EQ("XLII", numTeste->getNumeroRomano());
  delete numTeste;
}


/**
 * @brief Main do programa.
 *
 * @return Testes executados pelo gtest.
 *
 */
int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
