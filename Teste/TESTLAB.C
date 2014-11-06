/***************************************************************************
*  $MCI Modulo de implementacao: TLAB Teste labirinto
*
*  Arquivo gerado:              TESTLAB.c
*  Letras identificadoras:      TLAB
*
*  Projeto: INF 1301 Automatizacao dos testes de modulos C
*  Gestor:  DI/PUC-Rio
*  Autores: cs  -  Clara Szwarcman
*			gs  -  Guilherme Simas
*			lb  -  Lucas Borges
*
*  $HA Historico de evolucao:
*     Versao  Autor    Data     Observacoes
*	  1      csgslb 28/out/2014 inicio desenvolvimento
*
*  $ED Descricao do modulo
*     Este modulo contem as funcoes especificas para o teste do
*     modulo labirinto implementado com grafo. Ele trata de apenas 
*	  um labirinto de cada vez.
*
*  $EIU Interface com o usuario pessoa
*     Comandos de teste especificos para testar o modulo lista:
*
*     =comando <Parametro>
*
***************************************************************************/

#include    <string.h>
#include    <stdio.h>
#include    <malloc.h>

#include    "TST_ESPC.H"

#include    "Generico.h"
#include    "LerParm.h"

#include	"LABIRINTO.H"

static const char COMANDO_CMD				[ ] = "=comando"  ;
static const char CRIAR_LABIRINTO_CMD       [ ] = "=criar"    ;
static const char CRIAR_CAMINHO_CMD			[ ] = "=criar_cam";
static const char MOSTRA_LAB_CMD			[ ] = "=mostra";
static const char CRIAR_ENTRADA_CMD			[ ] = "=criar_ent";
static const char CRIAR_SAIDA_CMD			[ ] = "=criar_saida";
static const char ANDAR_CMD					[ ] = "=andar";
static const char CARREGAR_CMD				[ ] = "=carregar";
static const char SOLUCIONAR_CMD			[ ] = "=solucionar";
static const char SALVAR_CMD				[ ] = "=salvar";
static const char DESTRUIR_CMD				[ ] = "=destruir";
/*****  C�digo das fun��es exportadas pelo m�dulo  *****/


/***********************************************************************
*
*  $FC Fun��o: TGRF &Efetuar opera��es de teste espec�ficas para grafo
*
*  $ED Descri��o da fun��o
*     Efetua os diversos comandos de teste espec�ficos para o m�dulo
*     grafo sendo testado.
*
*  $EP Par�metros
*     $P ComandoTeste - String contendo o comando
*
*  $FV Valor retornado
*     Ver TST_tpCondRet definido em TST_ESPC.H
*
***********************************************************************/

TST_tpCondRet TST_EfetuarComando( char * ComandoTeste )
{

	int numLidos   = -1 , 
		CondRetEsp = -1 ,
		CondRetObt = -1 ,
		numElem    = -1 ;
	/* Inicializa para qualquer coisa */


	/* Testar Destruir Labirinto */
	if( strcmp( ComandoTeste , DESTRUIR_CMD ) == 0 )
	{

		LAB_DestruirLab() ;

		return TST_CondRetOK;

	} /* fim ativa: Testar CriarLista */

	/* Testar Criar Labirinto */
	else if ( strcmp( ComandoTeste , CRIAR_LABIRINTO_CMD ) == 0 )
	{
		int altura, largura;
		
		numLidos = LER_LerParametros( "iii" ,
			&altura,&largura,&CondRetEsp ) ;

		if ( numLidos != 3 )
		{
			return TST_CondRetParm ;
		} /* if */

		CondRetObt = LAB_CriarLab ( altura , largura ) ;

		return TST_CompararInt( CondRetEsp , CondRetObt ,
			"Retorno errado ao criar labirinto." );

	} /* fim ativa: Testar Criar Labirinto */

	/* Testar Criar Caminho */
	else if ( strcmp( ComandoTeste , CRIAR_CAMINHO_CMD ) == 0 )
	{
		int x, y;
		char direcao;

		numLidos = LER_LerParametros( "iici" ,&x, &y, &direcao,
			&CondRetEsp ) ;

		if ( numLidos != 4 )
		{
			return TST_CondRetParm ;
		} /* if */

		CondRetObt = LAB_CriarCaminho (x, y, direcao);

		return TST_CompararInt( CondRetEsp , CondRetObt ,
			"Retorno errado ao Criar caminho." );

	} /* fim ativa: Testar Criar Caminho */

	/* Testar Mostra Labirinto */
	else if ( strcmp( ComandoTeste , MOSTRA_LAB_CMD ) == 0 )
	{
	
		numLidos = LER_LerParametros( "i" 
									,&CondRetEsp ) ;

		if ( numLidos != 1 )
		{
			return TST_CondRetParm ;
		} /* if */

		CondRetObt = LAB_MostraLab() ;

		return TST_CompararInt( CondRetEsp , CondRetObt ,
			"Retorno errado ao criar labirinto." );

	} /* fim ativa: Testar Mostra Labirinto */

	/* Testar Criar Entrada */
	else if ( strcmp( ComandoTeste , CRIAR_ENTRADA_CMD ) == 0 )
	{
		int x, y;

		numLidos = LER_LerParametros( "iii" ,&x, &y,
			&CondRetEsp ) ;

		if ( numLidos != 3 )
		{
			return TST_CondRetParm ;
		} /* if */

		CondRetObt = LAB_CriarEntrada (x, y);

		return TST_CompararInt( CondRetEsp , CondRetObt ,
			"Retorno errado ao Criar Entrada." );

	} /* fim ativa: Testar Criar Entrada */

	/* Testar Criar saida */
	else if ( strcmp( ComandoTeste , CRIAR_SAIDA_CMD ) == 0 )
	{
		int x, y;

		numLidos = LER_LerParametros( "iii" ,&x, &y,
			&CondRetEsp ) ;

		if ( numLidos != 3 )
		{
			return TST_CondRetParm ;
		} /* if */

		CondRetObt = LAB_CriarSaida (x, y);

		return TST_CompararInt( CondRetEsp , CondRetObt ,
			"Retorno errado ao Criar Saida." );

	} /* fim ativa: Testar Criar Saida */

	/* Testar Andar */
	if ( strcmp( ComandoTeste , ANDAR_CMD ) == 0 )
	{
		char direcao;
		numLidos = LER_LerParametros( "ci" ,
			&direcao,&CondRetEsp ) ;

		if ( numLidos != 2 )
		{
			return TST_CondRetParm ;
		} /* if */

		CondRetObt=LAB_Andar( direcao ) ;

		return TST_CompararInt( CondRetEsp , CondRetObt ,
			"Retorno errado ao andar." );

	} /* fim ativa: Testar andar */

	/* Testar Carregar labirinto */
	else if ( strcmp( ComandoTeste , CARREGAR_CMD ) == 0 )
	{
		char entrada [30];
		numLidos = LER_LerParametros( "si" ,
			&entrada,&CondRetEsp ) ;

		if ( numLidos != 2 )
		{
			return TST_CondRetParm ;
		} /* if */

		CondRetObt=LAB_Carregar( entrada ) ;

		return TST_CompararInt( CondRetEsp , CondRetObt ,
			"Retorno errado ao carregar labirinto." );

	} /* fim ativa: Testar Carregar labirinto */

	/* Testar Solucionar Labirinto */
	if ( strcmp( ComandoTeste , SOLUCIONAR_CMD ) == 0 )
	{
		
		numLidos = LER_LerParametros( "i" ,
			&CondRetEsp ) ;

		if ( numLidos != 1 )
		{
			return TST_CondRetParm ;
		} /* if */

		CondRetObt=LAB_SolucionarLab(NULL) ;

		return TST_CompararInt( CondRetEsp , CondRetObt ,
			"Retorno errado ao solucionar o labirinto." );

	} /* fim ativa: Testar solucionar labirinto */

	/* Testar Salvar Labirinto */
	else if ( strcmp( ComandoTeste , SALVAR_CMD ) == 0 )
	{
		char saida [30];

		numLidos = LER_LerParametros( "si" ,
			&saida,&CondRetEsp ) ;

		if ( numLidos != 2 )
		{
			return TST_CondRetParm ;
		} /* if */

		CondRetObt=LAB_Salvar( saida ) ;

		return TST_CompararInt( CondRetEsp , CondRetObt ,
			"Retorno errado ao salvar o labirinto." );

	} /* fim ativa: Testar salvar o labirinto */

	return TST_CondRetNaoConhec;

} /* Fim fun��o: TGRF &Testar Grafo */

/********** Fim do m�dulo de implementa��o: TGRF Teste grafo gen�rico **********/
