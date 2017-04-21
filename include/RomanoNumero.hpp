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
    RomanoNumero(int numeroDecimal);

    string getNumeroRomano();
    int getNumeroDecimal();

    void setNumeroRomano(string numeroRomano);
    void setNumeroDecimal(int numeroDecimal);
  
    bool avaliaRomano(string numeroRomano);

  private:
    string numeroRomano;
    int numeroDecimal;

    void converte(int numeroDecimal);
    void converte(string numeroRomano);
    int converteUmaLetra(char letraAtual);
    int adicionaMesmasLetras(vector<int> letras, int i);
    int adicionaOutrasLetras(vector<int> letras, int i);
    int subtraiLetras(vector<int> letras, int i);
    void constroiRomano(int numero);
    void insereLetrasRomanas(int numero, int grandeza);

};
