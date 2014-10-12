/***************************************************************************
*
*  $MCD Módulo de definição: LAB Labirinto
*
*  Arquivo gerado:              LABIRINTO.h
*  Letras identificadoras:      LAB
*
*  Projeto: INF 1301 Automatização dos testes de módulos C
*  Gestor:  DI/PUC-Rio
*  Autores: cs  -  Clara Szwarcman
*			gs  -  Guilherme Simas
*			lb  -  Lucas Borges
*
*  $HA Histórico de evolução:
*     Versão  Autor    Data     Observações
*     1      csgslb 11/out/2014 início desenvolvimento
*
*  $ED Descrição do módulo
*     
*
*
*
*************************************************************************/


/***** Declarações exportadas pelo módulo *****/

/***********************************************************************
*
*  $TC Tipo de dados: LAB Condições de retorno
*
*
*  $ED Descrição do tipo
*     Condições de retorno das funções do labirinto
*
***********************************************************************/

   typedef enum {

         LAB_CondRetOK ,
               /* Concluiu corretamente */

   } LAB_tpCondRet ;


/***********************************************************************
*
*  $FC Função: GRF  &Criar Labirinto
*
*  $ED Descrição da função
*    
*  $EP Parâmetros
*
*  $FV Valor retornado
*
*  $AE Assertivas de entrada
*
*  $AS Assertivas de saída
*
***********************************************************************/
void LAB_CriarLab (int altura, int largura);
void LAB_CriarCaminho (int x, int y, char direcao);
void LAB_MostraLab ( void );
void LAB_CriarEntrada (int x, int y );
void LAB_CriarSaida (int x, int y );
int LAB_Andar (char direcao );



/********** Fim do módulo de definição: GRF Grafo não orientado **********/
