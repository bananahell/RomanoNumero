/**
 * @file validaNumeroRomano.hpp
 * 
 * @brief Validador de números romanos.
 *
 * @author Pedro Nogueira - 14/0065032
 *
 */

#ifndef ROMANONUMERO_VALIDANUMEROROMANO_H
#define ROMANONUMERO_VALIDANUMEROROMANO_H

#include <string>
#include <vector>

#endif

using namespace std;


/**
 * @brief Conversor de número romano para decimal
 * 
 * Converte o número romano passado para um número decimal já no membro numeroDecimal da própria classe.
 *
 * @param numeroRomano - String contendo um número romano
 *
 */
int converteRomano(string numeroRomano);
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
bool avaliaRomano(string numeroRomano);

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
int converteUmaLetra(char letraAtual);
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
int adicionaMesmasLetras(int* numeroDecimal, vector<int> letras, int i);
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
int adicionaOutrasLetras(int* numeroDecimal, vector<int> letras, int i);
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
int subtraiLetras(int* numeroDecimal, vector<int> letras, int i);
