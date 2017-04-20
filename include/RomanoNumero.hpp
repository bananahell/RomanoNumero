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

    void converte(long numeroDecimal);
    void converte(string numeroRomano);
    int converteUmaLetra(char letraAtual);
    int adicionaMesmasLetras(vector<int> letras, int i);
    int adicionaOutrasLetras(vector<int> letras, int i);
    int subtraiLetras(vector<int> letras, int i);

};
