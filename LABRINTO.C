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
#define _CRT_SECURE_NO_WARNINGS
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
void TransfCord (int x, int y, int * i, int *j);
void ObterCoordChave (int chave , int * x, int * y);

/*****  Código das funções exportadas pelo módulo  *****/


/***************************************************************************
*
*  Função: LAB  &Criar Labirinto
*****/

void LAB_CriarLab (int altura, int largura)
{

	GRF_CriarGrafo(&labirinto,NULL);
	LAB_altura=altura;
	LAB_largura=largura;

} /* Fim função: LAB  &Criar Labirinto */

/***************************************************************************
*
*  Função: LAB  &Criar Caminho
*****/

int LAB_CriarCaminho (int x, int y, char direcao)
{
	int chave1, chave2, i, j;

	TransfCord(x, y, &i, &j);	
	chave1=ObterChaveCord(i,j);
	chave2=ObterChaveDir(chave1,direcao);

	if (chave2/100<0 || chave2/100>=LAB_altura ||chave2%100<0 || chave2%100>=LAB_largura)
	{
		return -1;
	}

	GRF_CriaVertice(labirinto,NULL,chave1);
	GRF_CriaVertice(labirinto,NULL,chave2);
	GRF_CriaAresta(labirinto,chave1,chave2);

	return 0;

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
	GRF_CriaVertice(labirinto,NULL,LAB_entrada);

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
	GRF_CriaVertice(labirinto,NULL,LAB_saida);

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
		for ( i = 0 ; i < LAB_largura ; i++ )
		{
			chave_vertice = ObterChaveCord ( i , j ) ;

			//if ( GRF_ExisteVertice ( labirinto , chave_vertice ) == GRF_CondRetVerticeJaExiste )
			//{
				
				if( GRF_ExisteAresta ( labirinto , chave_vertice , ObterChaveDir ( chave_vertice , 'L' ) ) == GRF_CondRetArestaJaExiste )
				{
					fprintf ( arq_saida , "%d %c\n" , chave_vertice , 'L' ) ;
				}
				if( GRF_ExisteAresta ( labirinto , chave_vertice , ObterChaveDir ( chave_vertice , 'S' ) ) == GRF_CondRetArestaJaExiste )
				{
					fprintf ( arq_saida , "%d %c\n" , chave_vertice , 'S' ) ;
				}
		//	}
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
	int chave_vertice;
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
	
	while (fscanf (arq_entrada , "%d %c" , &chave_vertice , &direcao )==2)
	{
		LAB_CriarCaminho ( chave_vertice%100+1, LAB_altura-chave_vertice/100, direcao ) ;
	}/* while */
	fclose (arq_entrada);

	GRF_AlteraCorrente(labirinto,LAB_entrada); /*  precisa por corrente na entrada */


	return;

} /* Fim função: LAB  &Carregar Labirinto */

/***************************************************************************
*
*  Função: LAB  &Destruir Labirinto
*****/

void LAB_DestruirLab ( void )
{
	if (labirinto != NULL)
	{
		GRF_DestroiGrafo(labirinto);
	}
	LAB_entrada=-1;
	LAB_saida=-1;
} /* Fim função: LAB  &Destruir Labirinto */

/***************************************************************************
*
*  Função: LAB  &Solucionar Labirinto
*****/

void LAB_SolucionarLab ( int ** buffer_solucao )
{
	int chaveAtual , * aux , i , *temp , x , y ;

	if (labirinto == NULL)
	{
		exit(1);
	}

	if(GRF_ObterCorr (labirinto,&chaveAtual,NULL) != GRF_CondRetOK )
	{

	}

	aux = (int *) malloc (LAB_altura * LAB_largura * ( sizeof ( int ) ) ) ;	

	if(GRF_ObtemCaminho (labirinto , chaveAtual , LAB_saida , aux ) == GRF_CondRetVerticesDesconexos )
	{
		printf ("Não há caminho") ;
	}

	buffer_solucao = ( int ** )malloc ( LAB_largura * LAB_altura * sizeof ( int * ) ) ;
	temp = ( int * )malloc ( LAB_largura * LAB_altura * 2 * sizeof ( int ) ) ;
	for (i = 0; i < LAB_largura * LAB_altura; i++) 
	{
		buffer_solucao[i] = temp + (i * 2);
	}

	for( i=0 ; aux[i]!=-1 ; i++ )
	{
		ObterCoordChave ( chaveAtual , &x , &y ) ;
		buffer_solucao[i][0] = x ;
		buffer_solucao[i][1] = y ;
	}

	buffer_solucao[i][0] = -1 ;
	buffer_solucao[i][1] = -1 ;

	return;
} /* Fim função: LAB  &Solucionar Labirinto */

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
void TransfCord (int x, int y, int * i, int *j)
{
	*i=x-1;
	*j=LAB_altura-y;
}

/***********************************************************************
*
*  $FC Função: LAB
*
*  $ED Descrição da função
*     
*
***********************************************************************/
void ObterCoordChave (int chave , int * x, int * y)
{
	*x = chave%100 + 1 ;
	*y = LAB_altura - chave/100 ;
}