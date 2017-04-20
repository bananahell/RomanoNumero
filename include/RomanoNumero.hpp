#include <string>
#include <vector>

using namespace std;


/**
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
    RomanoNumero(string numeroRomano);
    RomanoNumero(long numeroDecimal);

    string getNumeroRomano();
    long getNumeroDecimal();

    void setNumeroRomano(string numeroRomano);
    void setNumeroDecimal(long numeroDecimal);

  private:
    string numeroRomano;
    long numeroDecimal;
    const int I = 1;
    const int V = 5;
    const int X = 10;
    const int L = 50;
    const int C = 100;
    const int D = 500;
    const int M = 1000;

    void converte(long numeroDecimal);
    void converte(string numeroRomano);
    int converteUmaLetra(char letraAtual);

};
