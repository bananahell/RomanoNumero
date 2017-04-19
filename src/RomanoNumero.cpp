/**
 * @file RomanoNumero.cpp
 * 
 * @brief Arquivo com a classe RomanoNumero, classe responsável por converter número romanos em decimais e vice-versa.
 *
 * @author Pedro Nogueira - 14/0065032
 *
 */

#include <RomanoNumero.hpp>


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
