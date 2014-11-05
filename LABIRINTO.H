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
*     Implementa um labirinto utilizando um
*	  grafo não direcionado genérico. Só é possível existir
*	  um labirinto em operação por vez.
*
*************************************************************************/

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
		 LAB_CondRetLabirintoNaoExiste,
			   /* Labirinto não foi criado */
		 LAB_CondRetNaoExisteCaminho,
			   /* Nao existe caminho entre as celulas */
		 LAB_CondRetErroArquivo,
			   /* Erro ao abrir ou gerar o arquivo */
		 LAB_CondRetSaida,
			   /* Corrente se encontra na saída */
		 LAB_CondRetForaLab,
			   /* Caminho vai para fora da área do labirinto */
		 LAB_CondRetMemoria,
			   /* Nao ha memoria suficiente para alocar a estrutura */
		 LAB_CondRetCaminhoJaExiste
			  /* Ja existe caminho entre as celulas do Labirinto*/
   } LAB_tpCondRet ;


/***********************************************************************
*
*  $FC Função: LAB  &Criar Labirinto
*
*  $ED Descrição da função
*      Cria um labirinto estático utilizando um grafo não direcionado
*	   genérico.
*
*  $EP Parâmetros
*		altura - número de células de altura do labirinto
*		largura - número de células de largura do labirinto
*
*  $FV Valor retornado
*		LAB_CondRetOK - criou labirinto sem problemas
*		LAB_CondRetMemoria - faltou memória ao alocar espaço
*
*  $AE Assertivas de entrada
*
*  $AS Assertivas de saída
*
***********************************************************************/

   LAB_tpCondRet LAB_CriarLab (int altura, int largura);

   /***********************************************************************
*
*  $FC Função: LAB  &Criar Caminho
*
*  $ED Descrição da função
*      Cria caminho entre duas células do labirinto
*
*  $EP Parâmetros
*		x - coordenada x da célula apartir da qual o caminho será criado
*		y - coordenada y da célula apartir da qual o caminho será criado
*		direcao - direcao para a qual se quer criar o caminho
*
*  $FV Valor retornado
*		LAB_CondRetOK - criou caminho sem problemas
*		LAB_CondRetForaLab - caminho para a direcao desejada 
*							esta fora dos limites do labirinto
*
*  $AE Assertivas de entrada
*
*  $AS Assertivas de saída
*
***********************************************************************/

	LAB_tpCondRet LAB_CriarCaminho (int x, int y, char direcao);

/***********************************************************************
*
*  $FC Função: LAB  &Mostra Lab
*
*  $ED Descrição da função
*      Imprime labirinto na tela
*
*  $EP Parâmetros
*		
*  $FV Valor retornado
*		LAB_CondRetOK - mostrou labirinto sem problemas
*		LAB_CondRetLabirintoNaoExiste - não existe labirinto
*
*  $AE Assertivas de entrada
*
*  $AS Assertivas de saída
*
***********************************************************************/

	LAB_tpCondRet LAB_MostraLab ( void );

/***********************************************************************
*
*  $FC Função: LAB  &Criar Entrada
*
*  $ED Descrição da função
*      Cria entrada do labirinto.
*
*  $EP Parâmetros
*		x - coordenada x da célula de entrada
*		y - coordenada y da célula de entrada
*
*  $FV Valor retornado
*		LAB_CondRetOK - criou entrada sem problemas
*		LAB_CondRetLabirintoNaoExiste - não existe labirinto
*
*  $AE Assertivas de entrada
*
*  $AS Assertivas de saída
*
***********************************************************************/

	LAB_tpCondRet LAB_CriarEntrada (int x, int y );

/***********************************************************************
*
*  $FC Função: LAB  &Criar Saida
*
*  $ED Descrição da função
*      Cria saida do labirinto.
*
*  $EP Parâmetros
*		x - coordenada x da célula de saida
*		y - coordenada y da célula de saida
*
*  $FV Valor retornado
*		LAB_CondRetOK - criou saida sem problemas
*		LAB_CondRetLabirintoNaoExiste - não existe labirinto
*
*  $AE Assertivas de entrada
*
*  $AS Assertivas de saída
*
***********************************************************************/

	LAB_tpCondRet LAB_CriarSaida (int x, int y );

/***********************************************************************
*
*  $FC Função: LAB  &Andar
*
*  $ED Descrição da função
*      Anda para uma célula vizinha
*
*  $EP Parâmetros
*		direcao - direcao para a qual se quer andar
*
*  $FV Valor retornado
*		LAB_CondRetOK - andou sem problemas
*		LAB_CondRetLabirintoNaoExiste - não existe labirinto
*		LAB_CondRetNaoExisteCaminho - não existe caminho para a direção desejada
*		LAB_CondRetSaida - célula na direção desejada é a saida do labirinto
*
*  $AE Assertivas de entrada
*
*  $AS Assertivas de saída
*
***********************************************************************/

	LAB_tpCondRet LAB_Andar (char direcao );

/***********************************************************************
*
*  $FC Função: LAB  &Carrega
*
*  $ED Descrição da função
*      Carrega um labirinto a partir de um arquivo
*
*  $EP Parâmetros
*		nome_entrada - ponteiro para nome do arquivo a partir do qual 
*					   se deseja carregar o labirinto
*
*  $FV Valor retornado
*		LAB_CondRetOK - carregou labirinto sem problemas
*		LAB_CondRetErroArquivo - não foi possivel abrir o arquivo
*
*  $AE Assertivas de entrada
*
*  $AS Assertivas de saída
*
***********************************************************************/

	LAB_tpCondRet LAB_Carregar ( char * nome_entrada );

/***********************************************************************
*
*  $FC Função: LAB  &Solucionar Lab
*
*  $ED Descrição da função
*      Encontra caminho até a saida do labirinto
*
*  $EP Parâmetros
*		buffer_solucao - referencia para ponteiro do buffer 
*						no qual o caminho será armazenado
*
*  $FV Valor retornado
*		LAB_CondRetOK - solucionou labirinto sem problemas
*		LAB_CondRetLabirintoNaoExiste - não existe labirinto
*		LAB_CondRetNaoExisteCaminho - não existe caminho para a direção desejada
*		LAB_CondRetMemoria - faltou memória ao alocar espaço
*
*  $AE Assertivas de entrada
*
*  $AS Assertivas de saída
*
***********************************************************************/

	LAB_tpCondRet LAB_SolucionarLab ( int *** buffer_solucao );

/***********************************************************************
*
*  $FC Função: LAB  &Salvar
*
*  $ED Descrição da função
*      Salva um labirinto em um arquivo
*
*  $EP Parâmetros
*		nome_saida - ponteiro para nome do arquivo no qual
*					 se deseja salvar o labirinto
*
*  $FV Valor retornado
*		LAB_CondRetOK - salvou labirinto sem problemas
*		LAB_CondRetErroArquivo - não foi possivel abrir o arquivo
*
*  $AE Assertivas de entrada
*
*  $AS Assertivas de saída
*
***********************************************************************/

	LAB_tpCondRet LAB_Salvar ( char * nome_saida );

/***********************************************************************
*
*  $FC Função: LAB  &Destruir
*
*  $ED Descrição da função
*      Destrói o labirinto se este existir
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
	
	void LAB_DestruirLab ( void );



/********** Fim do módulo de definição: LAB Labirinto **********/
