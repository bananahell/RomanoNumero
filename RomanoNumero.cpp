#include <RomanoNumero.hpp>
/**
 * @file RomanoNumero.cpp
 *
 * @brief Classe que contém um número e o converte para número decimal ou romano.
 *
 * Aqui tem a implementação de um grafo em si. Ele usa um sistema de matriz
 * para armazenar suas arestas.
 *
 * @author Pedro Nogueira - 14/0065032
 *
 */
public class RomanoNumero {
	
	public:
		RomanoNumero();
		RomanoNumero(String numeroRomano) {
			this.numeroRomano = numeroRomano;
		}
		RomanoNumero(long numeroDecimal) {
			this.numeroDecimal = numeroDecimal;
		}

	private:
		String numeroRomano;
		long numeroDecimal;
	
}