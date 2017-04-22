/**
 * @file RomanoConversorTeste.cpp
 *
 * @brief Testador da classe de números romanos, vindos do arquivo RomanoNumero.hpp.
 * Usa a biblioteca de teste da Google gtest.
 *
 * @author Pedro Nogueira - 14/0065032
 *
 */

#include <RomanoNumero.hpp>

#include <gtest/gtest.h>


/**
 * @brief Teste Instanciando NenhumParametro, testando se a classe está sendo instanciada corretamente sem parâmetro.
 *
 */
TEST(Instanciando, NenhumParametro) {
  RomanoNumero* numTeste = new RomanoNumero();
  EXPECT_EQ(-1, numTeste->getNumeroDecimal());
  EXPECT_EQ("", numTeste->getNumeroRomano());
  delete numTeste;
}
/**
 * @brief Teste Instanciando NumeroDecimal, testando se a classe está sendo instanciada com número decimal e já convertendo para romano.
 *
 */
TEST(Instanciando, 42) {
  RomanoNumero* numTeste = new RomanoNumero(42);
  EXPECT_EQ(42, numTeste->getNumeroDecimal());
  EXPECT_EQ("XLII", numTeste->getNumeroRomano());
  delete numTeste;
}
/**
 * @brief Teste Instanciando NumeroRomano, testando se a classe está sendo instanciada com número romano e já convertendo para decimal.
 *
 */
TEST(Instanciando, XCVII) {
  RomanoNumero* numTeste = new RomanoNumero("XCVII");
  EXPECT_EQ("XCVII", numTeste->getNumeroRomano());
  EXPECT_EQ(97, numTeste->getNumeroDecimal());
  delete numTeste;
}

/**
 * @brief Teste Setando Decimal, testando se a classe está setando números decimais no objeto corretamente.
 *
 */
TEST(Setando, de42para97) {
  RomanoNumero* numTeste = new RomanoNumero(42);
  EXPECT_EQ("XLII", numTeste->getNumeroRomano());
  numTeste->setNumeroDecimal(97);
  EXPECT_EQ(97, numTeste->getNumeroDecimal());
  EXPECT_EQ("XCVII", numTeste->getNumeroRomano());
  delete numTeste;
}
/**
 * @brief Teste Setando Romano, testando se a classe está setando números romanos no objeto corretamente.
 *
 */
TEST(Setando, deXCVIIparaXLII) {
  RomanoNumero* numTeste = new RomanoNumero("xcvii");
  EXPECT_EQ(97, numTeste->getNumeroDecimal());
  numTeste->setNumeroRomano("XLII");
  EXPECT_EQ("XLII", numTeste->getNumeroRomano());
  EXPECT_EQ(42, numTeste->getNumeroDecimal());
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
