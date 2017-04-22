/**
 * @file RomanoNumero.hpp
 * 
 * @brief Arquivo com a declaração de RomanoNumero, classe responsável por converter número romanos em decimais e vice-versa
 *
 * @author Pedro Nogueira - 14/0065032
 *
 */

#ifndef ROMANONUMERO_ROMANONUMERO_H
#define ROMANONUMERO_ROMANONUMERO_H

#include <validaNumeroRomano.hpp>

#include <string>

#endif

using namespace std;


/**
 * @brief Classe que contém um número e o converte para número decimal ou romano
 *
 * Aqui tem a implementação de um grafo em si. Ele usa um sistema de matriz
 * para armazenar suas arestas.
 *
 * @author Pedro Nogueira - 14/0065032
 *
 */
class RomanoNumero {

  public:
    /**
     * @brief Construtor padrão
     * 
     * Instancia objeto RomanoNumero com os valores 0 (N).
     *
     */
    RomanoNumero();
    /**
     * @brief Construtor romano
     * 
     * Instancia objeto RomanoNumero com número romano passado.
     *
     * @param numeroRomano - String contendo um número romano
     *
     */
    explicit RomanoNumero(string numeroRomano);
    /**
     * @brief Construtor decimal
     * 
     * Instancia objeto RomanoNumero com número decimal passado.
     *
     * @param numeroDecimal - Inteiro contendo um número decimal
     *
     */
    explicit RomanoNumero(int numeroDecimal);

    /**
     * @brief Get do número romano
     * 
     * Acesso à informação da variável privada numeroRomano.
     *
     * @return numeroRomano - Número romano do objeto
     *
     */
    string getNumeroRomano();
    /**
     * @brief Get do número decimal
     * 
     * Acesso à informação da variável privada numeroDecimal.
     *
     * @return numeroDecimal - Número decimal do objeto
     *
     */
    int getNumeroDecimal();

    /**
     * @brief Set do número romano
     * 
     * Disponibiliza a troca do valor da variável privada numeroRomano.
     *
     * @param numeroRomano - Número romano do objeto
     *
     */
    void setNumeroRomano(string numeroRomano);
    /**
     * @brief Set do número decimal
     * 
     * Disponibiliza a troca do valor da variável privada numeroDecimal.
     *
     * @param numeroDecimal - Número decimal do objeto
     *
     */
    void setNumeroDecimal(int numeroDecimal);

  private:
    string numeroRomano;  /**< Número romano associado ao objeto. */
    int numeroDecimal;  /**< Número decimal associado ao objeto. */

    /**
     * @brief Conversor de número decimal para romano
     * 
     * Converte o número decimal passado para um número romano já no membro numeroRomano da própria classe.
     *
     * @param numeroDecimal - Inteiro contendo um número decimal
     *
     */
    void converteDecimal(int numeroDecimal);
    /**
     * @brief Construtor do número romano
     * 
     * A partir de um decimal, esse método constrói o número romano equivalente.
     *
     * @param numero - Número decimal a ser convetido
     *
     */
    void constroiRomano(int numero);
    /**
     * @brief Inseridor de letras no número romano resultante
     * 
     * Insere no membro numeroRomano da própria classe as letras correspondentes à sua devida construção.
     *
     * @param numero - Número decimal a ser convetido
     * @param grandeza - Indicador do tamanho do número em questão, sendo ele divisível por 1000, 100, 10 ou somente 1
     *
     */
    void insereLetrasRomanas(int numero, int grandeza);


    /**
     * @brief Conversor de letras de algarismos romanos para números
     * 
     * Converte uma única letra de algarismos romanos em um inteiro.
     *
     * @param letraAtual - Caracter correspondente à letra a ser convertida
     *
     * @return int - Número correspondente ao algarismo romano passado como parâmetro
     *
     */
    friend int converteUmaLetra(char letraAtual);
    /**
     * @brief Adicionador de letras iguais de algarismos romanos ao número romano resultante
     * 
     * Adiciona no membro resultante numeroRomano letras correspondentes ao número romano.
     * Esse método em específico pega letras seguidas e idênticas do algarismo romano que se adicionam.
     *
     * @param numeroDecimal - Número decimal processado até o momento. Essa função incrementa o que for passado de número romano diretamente na variável.
     * @param letras - Vetor de valores inteiros correspondentes aos valores individuais de cada uma das letras do número romano
     * @param i - Índice que indica onde no vetor passado começa a construção aditiva do número romano
     *
     * @return i - Índice final da construção aditiva do número romano desejada com esse método
     *
     */
    friend int adicionaMesmasLetras(int* numeroDecimal, vector<int> letras, int i);
    /**
     * @brief Adicionador de letras diferentes aditivas de algarismos romanos ao número romano resultante
     * 
     * Adiciona no membro resultante numeroRomano letras correspondentes ao número romano.
     * Esse método em específico pega letras seguidas e diferentes do algarismo romano que se adicionam.
     *
     * @param numeroDecimal - Número decimal processado até o momento. Essa função incrementa o que for passado de número romano diretamente na variável.
     * @param letras - Vetor de valores inteiros correspondentes aos valores individuais de cada uma das letras do número romano
     * @param i - Índice que indica onde no vetor passado começa a construção aditiva do número romano
     *
     * @return i - Índice final da construção aditiva do número romano desejada com esse método
     *
     */
    friend int adicionaOutrasLetras(int* numeroDecimal, vector<int> letras, int i);
    /**
     * @brief Adicionador de letras diferentes subtrativas de algarismos romanos ao número romano resultante
     * 
     * Adiciona no membro resultante numeroRomano letras correspondentes ao número romano.
     * Esse método em específico pega letras seguidas e diferentes do algarismo romano que se subtraem.
     *
     * @param numeroDecimal - Número decimal processado até o momento. Essa função incrementa o que for passado de número romano diretamente na variável.
     * @param letras - Vetor de valores inteiros correspondentes aos valores individuais de cada uma das letras do número romano
     * @param i - Índice que indica onde no vetor passado começa a construção aditiva do número romano
     *
     * @return i - Índice final da construção subtrativa do número romano desejada com esse método
     *
     */
    friend int subtraiLetras(int* numeroDecimal, vector<int> letras, int i);

    /**
     * @brief Conversor de número romano para decimal
     * 
     * Converte o número romano passado para um número decimal já no membro numeroDecimal da própria classe.
     *
     * @param numeroRomano - String contendo um número romano
     *
     */
    friend int converteRomano(string numeroRomano);
    /**
     * @brief Avaliador de números romanos
     * 
     * Checa se o número romano passado para o programa é um número válido.
     *
     * @param numeroRomano - String contendo um número romano
     *
     * @return bool - True para se o número romano passado é válido
     *
     */
    friend bool avaliaRomano(string numeroRomano);

};
