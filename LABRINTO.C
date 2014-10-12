/***************************************************************************
*  $MCI Módulo de implementação: LAB Labirinto
*
*  Arquivo gerado:              LABIRINTO.c
*  Letras identificadoras:      lab
*
*  Projeto: INF 1301 Automatização dos testes de módulos C
*  Gestor:  DI/PUC-Rio
*  Autores: cs  -  Clara Szwarcman
*			gs  -  Guilherme Simas
*			lb  -  Lucas Borges
*
*  $HA Histórico de evolução:
*     Versão  Autor    Data     Observações
*	  1		 csgslb 11/out/2014 início desenvolvimento
*
*
***************************************************************************/
#include <stdio.h>
#include <stdlib.h>

#include "LABIRINTO.H"
#include "GRAFO.H"

static int LAB_entrada;
static int LAB_saida;
static int LAB_largura;
static int LAB_altura;
static GRF_tppGrafo labirinto;


/***** Protótipos das funções encapuladas no módulo *****/

int ObterChaveCord (int i, int j);
int ObterChaveDir (int chave, char direcao);


/*****  Código das funções exportadas pelo módulo  *****/


/***************************************************************************
*
*  Função: LAB  &Criar Labirinto
*****/

void LAB_CriarLab (int altura, int largura)
{

	int i, j;

	GRF_CriarGrafo(&labirinto,NULL);
	LAB_altura=altura;
	LAB_largura=largura;

	for(j=0;j<altura;j++)
	{
		for(i=0;i<largura;i++)
		{
			GRF_CriaVertice(labirinto,NULL,ObterChaveCord(i,j));
		}
	}

} /* Fim função: LAB  &Criar Labirinto */

/***************************************************************************
*
*  Função: LAB  &Criar Caminho
*****/

void LAB_CriarCaminho (int x, int y, char direcao)
{
	int chave, i, j;

	TransfCord(x, y, &i, &j);	
	chave=ObterChaveCord(i,j);

	GRF_CriaAresta(labirinto,chave,ObterChaveDir(chave,direcao));

} /* Fim função: LAB  &Criar Caminho */

/***************************************************************************
*
*  Função: LAB  &Mostrar Labirinto
*****/

void LAB_MostraLab ( void )
{
	int i, j,chave, posicao;

	GRF_ObterCorr(labirinto,&posicao,NULL);
	
	printf("  ");
	for (i=0 ; i<2*LAB_largura+1; i++ )
	{
		printf("_");
	}


	printf("\n");

	for (j=0; j<LAB_altura ; j++)
	{
		printf("%d", LAB_altura-j);
		if (LAB_altura-j<10)
			printf(" ");
		printf("|");

		for (i=0; i<LAB_largura ; i++ )
		{
			chave=ObterChaveCord(i,j);
			if( GRF_ExisteAresta(labirinto,chave,ObterChaveDir(chave,'s')) == GRF_CondRetArestaJaExiste)
			{
				if(chave != LAB_entrada && chave != LAB_saida && chave != posicao )
				{
					printf(" ");
				}
				else 
				{
					printf("+");
				}
			}
			else
			{
				if(chave != LAB_entrada && chave != LAB_saida && chave != posicao )
				{
					printf("_");
				}
				else 
				{
					printf("%c",0xf1);
				}

			} /* if */

			if( GRF_ExisteAresta(labirinto,chave,ObterChaveDir(chave,'l')) == GRF_CondRetArestaJaExiste)
			{
				printf(" ");
			}
			else
			{
				printf("|");
			} /* if */
		}
		printf("\n");
	}

	printf("   ");
	for (i=1 ; i<=LAB_largura; i++ )
	{
		printf("%d",i%10);
		if (i%10==9)
			printf("%d",(i+1)/10);
		else
			printf(" ");
	}
	printf("\n");

} /* Fim função: LAB  &Mostrar Labirinto */

/***************************************************************************
*
*  Função: LAB  &Criar Entrada
*****/

void LAB_CriarEntrada (int x, int y )
{
	int i, j;

	TransfCord(x,y,&i,&j);
	LAB_entrada=ObterChaveCord(i,j);
	GRF_AlteraCorrente(labirinto,LAB_entrada);

} /* Fim função: LAB  &Criar Entrada */

/***************************************************************************
*
*  Função: LAB  &Criar Saida
*****/

void LAB_CriarSaida (int x, int y )
{
	int i, j;

	TransfCord(x,y,&i,&j);
	LAB_saida=ObterChaveCord(i,j);

} /* Fim função: LAB  &Criar Saida */

/***************************************************************************
*
*  Função: LAB  &Andar
*****/

int LAB_Andar (char direcao )
{
	int chave_prox, chave,ret;

	GRF_ObterCorr(labirinto,&chave,NULL);
	chave_prox=ObterChaveDir(chave, direcao);

	ret=GRF_IrVizinho(labirinto, chave_prox);


	if (ret==GRF_CondRetOK && chave_prox==LAB_saida)
	{
		return 1;
	}

	return 0;

} /* Fim função: LAB  &Andar */

/***************************************************************************
*
*  Função: LAB  &Salvar Labirinto
*****/

void LAB_Salvar ( char * nome_saida )
{
	int i , j ;
	int chave_vertice ;
	FILE * arq_saida ;

	arq_saida = fopen ( nome_saida , "w" ) ;

	if ( arq_saida == NULL )
	{
		printf(" Erro ao criar arquivo. ") ;
		return ;
	}

	fprintf ( arq_saida , "%d %d %d %d\n" , LAB_largura , LAB_altura , LAB_entrada , LAB_saida ) ;

	for ( j = 0 ; j < LAB_altura ; j++ )
	{
		for ( i = 0 ; j < LAB_largura ; j++ )
		{
			chave_vertice = ObterChaveCord ( i , j ) ;

			if ( GRF_ExisteVertice ( labirinto , chave_vertice ) == GRF_CondRetVerticeJaExiste )
			{
				
				if( GRF_ExisteAresta ( labirinto , chave_vertice , ObterChaveDir ( chave_vertice , 'L' ) ) == GRF_CondRetArestaJaExiste )
				{
					fprintf ( arq_saida , "%d %c" , chave_vertice , 'L' ) ;
				}
				if( GRF_ExisteAresta ( labirinto , chave_vertice , ObterChaveDir ( chave_vertice , 'S' ) ) == GRF_CondRetArestaJaExiste )
				{
					fprintf ( arq_saida , "%d %c" , chave_vertice , 'S' ) ;
				}
			}
		}
	}/* for */

	fclose ( arq_saida ) ;

	return;

} /* Fim função: LAB  &Salvar Labirinto */

/***************************************************************************
*
*  Função: LAB  &Carregar Labirinto
*****/

void LAB_Carregar ( char * nome_entrada )
{
	int chave_vertice ;
	char direcao ;
	FILE * arq_entrada ;

	arq_entrada = fopen ( nome_entrada , "r" ) ;

	if ( arq_entrada == NULL )
	{
		printf( "Erro ao abrir o arquivo" );
		return ;
	}/* if */

	fscanf (arq_entrada,"%d %d %d %d", &LAB_largura , &LAB_altura , &LAB_entrada , &LAB_saida );

	LAB_CriarLab ( LAB_altura , LAB_largura );
	
	while (fscanf (arq_entrada , "%d %c" , &chave_vertice , &direcao ))
	{
		GRF_CriaAresta ( labirinto , chave_vertice , ObterChaveDir ( chave_vertice , direcao )  ) ;
	}/* while */

	fclose (arq_entrada);

	return;

} /* Fim função: LAB  &Carregar Labirinto */

/*****  Código das funções encapsuladas no módulo  *****/

/***********************************************************************
*
*  $FC Função: LAB
*
*  $ED Descrição da função
*     
*
***********************************************************************/

int ObterChaveCord (int i, int j)
{
	return j*100+i;
}  /* Fim função: LAB  &Criar Labirinto */

/***********************************************************************
*
*  $FC Função: LAB
*
*  $ED Descrição da função
*     
*
***********************************************************************/

int ObterChaveDir (int chave, char direcao)
{
	
	if (direcao=='s' || direcao=='S')
	{
		return chave+100;
	} 
	
	else if (direcao=='l' || direcao=='L')
	{
		return chave+1;
	}
	
	else if (direcao=='n' || direcao=='N')
	{
		return chave-100;
	}

	else if (direcao=='o' || direcao=='O')
	{
		return chave-1;
	}

	return -1;

}

/***********************************************************************
*
*  $FC Função: LAB
*
*  $ED Descrição da função
*     
*
***********************************************************************/
int TransfCord (int x, int y, int * i, int *j)
{
	*i=x-1;
	*j=LAB_altura-y;
}
