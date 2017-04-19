#include <RomanoNumero.hpp>

using namespace std;

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
class RomanoNumero {
	
	public:
		RomanoNumero();
		RomanoNumero(string numeroRomano) {
			setNumeroRomano(numeroRomano);
		}
		RomanoNumero(long numeroDecimal) {
			setNumeroDecimal(numeroDecimal);
		}
	
		string getNumeroRomano() {
			return numeroRomano;
		}
		long getNumeroDecimal() {
			return numeroDecimal;
		}
	
		void setNumeroRomano(string numeroRomano) {
			this->numeroRomano = numeroRomano;
		}
		void setNumeroDecimal(long numeroDecimal) {
			this->numeroDecimal = numeroDecimal;
		}

	private:
		string numeroRomano;
		long numeroDecimal;
	
};
