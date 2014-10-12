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
*  Função: GRF  &Criar Labirinto
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
*  Função: GRF  &Criar Caminho
*****/

void LAB_CriarCaminho (int x, int y, char direcao)
{
	int chave, i, j;

	TransfCord(x, y, &i, &j);	
	chave=ObterChaveCord(i,j);

	GRF_CriaAresta(labirinto,chave,ObterChaveDir(chave,direcao));

} /* Fim função: LAB  &Criar Labirinto */

/***************************************************************************
*
*  Função: GRF  &Criar Caminho
*****/
void LAB_MostraLab ( void )
{
	int i, j,chave;

	
	for (i=0 ; i<2*LAB_largura+1; i++ )
	{
		printf("_");
	}


	printf("\n");

	for (j=0; j<LAB_altura ; j++)
	{
		printf("|");

		for (i=0; i<LAB_largura ; i++ )
		{
			chave=ObterChaveCord(i,j);
			if( GRF_ExisteAresta(labirinto,chave,ObterChaveDir(chave,'s')) == GRF_CondRetArestaJaExiste)
			{
				printf(" ");
			}
			else
			{
				printf("_");
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


} /* Fim função: LAB  &Criar Labirinto */


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
