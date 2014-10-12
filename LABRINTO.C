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

	int x, y;

	GRF_CriarGrafo(&labirinto,NULL);
	LAB_altura=altura;
	LAB_largura=largura;

	for(y=0;y<altura;y++)
	{
		for(x=0;x<largura;x++)
		{
			GRF_CriaVertice(labirinto,NULL,ObterChaveCord(x,y));
		}
	}

} /* Fim função: LAB  &Criar Labirinto */

/***************************************************************************
*
*  Função: GRF  &Criar Caminho
*****/

void LAB_CriarCaminho (int x, int y, char direcao)
{
	int chave=ObterChaveCord(x,y);

	GRF_CriaAresta(labirinto,chave,ObterChaveDir(chave,direcao));

} /* Fim função: LAB  &Criar Labirinto */

/***************************************************************************
*
*  Função: GRF  &Criar Caminho
*****/
void LAB_MostraLab ( void )
{
	int x, y,chave;

	
	for (x=0 ; x<2*LAB_largura+1; x++ )
	{
		printf("_");
	}


	printf("\n");

	for (y=0; y<LAB_altura ; y++)
	{
		printf("|");

		for (x=0; x<LAB_largura ; x++ )
		{
			chave=ObterChaveCord(x,y);
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

int ObterChaveCord (int x, int y)
{
	return y*100+x;
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