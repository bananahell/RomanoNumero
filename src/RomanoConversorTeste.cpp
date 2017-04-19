#include <gtest/gtest.h>

#include <RomanoNumero.hpp>

/**
 * @file RomanoConversorTeste.cpp
 *
 * @brief Testador da classe de números romanos, vindos do arquivo RomanoNumero.hpp.
 * Usa a biblioteca de teste da Google gtest.
 *
 * @author Pedro Nogueira - 14/0065032
 *
 */

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
