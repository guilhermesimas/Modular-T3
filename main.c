#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "LABIRINTO.H"

void InicializaLAB (void );
void MenuPrincipal ( void ) ;
void JogarLab ( void );
char ConvDir (int cod);
void TelaPrbs ( void );
int ReobterEntrada ( void );
void CriarLab ( void );

int main (){
	int entrada;

	MenuPrincipal();

	printf("Entre sua escolha: ");
	scanf("%d",&entrada);

	while (entrada!=3) 
	{
		if(entrada==1)
		{
			CriarLab();
		}
		
		else if (entrada == 2)
		{
			/* carregando um labirinto */
		}

		#ifdef _DEBUG
		else if (entrada == 4)
		{
			system("cls");
			InicializaLAB();
			JogarLab();
		}
		#endif

		else
		{
			entrada=ReobterEntrada();
		}
		system("cls");
		MenuPrincipal();

		printf("Entre sua escolha: ");
		scanf("%d",&entrada);
	}


	return 0;
}

void MenuPrincipal ( void ) {

	printf("\n\n");
	printf("\t\t _           _     _      _       _        \n"
		   "\t\t| |         | |   (_)    (_)     | |       \n"
		   "\t\t| |     __ _| |__  _ _ __ _ _ __ | |_ ___  \n"
		   "\t\t| |    / _` | '_ \\| | '__| | '_ \\| __/ _ \\ \n"
		   "\t\t| |___| (_| | |_) | | |  | | | | | || (_) |\n"
		   "\t\t\\_____/\\__,_|_.__/|_|_|  |_|_| |_|\\__\\___/ \n"
		   "                                           \n"
		   "                                           \n");
	printf("\t\t\tMENU PRINCIPAL\n"
			"\t\t\t1 - Criar um labirinto\n"
			"\t\t\t2 - Carregar um labirinto\n"
			"\t\t\t3 - Sair\n");

	#ifdef _DEBUG
	printf("\t\t\t4 - Jogar labirinto pre-definido\n");
	#endif

	printf("\n\n");
}
void InicializaLAB (void ){

	LAB_CriarLab(3,3);

	LAB_CriarCaminho(1,1,'l');
	LAB_CriarCaminho(2,1,'l');
	LAB_CriarCaminho(3,1,'n');
	LAB_CriarCaminho(3,2,'o');
	LAB_CriarCaminho(2,2,'o');
	LAB_CriarCaminho(1,3,'s');
	LAB_CriarCaminho(1,3,'l');
	LAB_CriarCaminho(2,3,'l');

	LAB_CriarEntrada(1,1);
	LAB_CriarSaida(3,3);
}
void JogarLab ( void )
{
	int entrada;
	LAB_MostraLab();

	printf("\n\n1 - Mover-se para Sul\n"
			"2 - Mover-se para Norte\n"
			"3 - Mover-se para Oeste\n"
			"4 - Mover-se para Leste\n"
			"5 - Voltar ao menu principal\n\n"
			"Escolha uma das opcoes: ");
	scanf("%d",&entrada);

	while ( 1 )
	{
		if (entrada >=1 && entrada <= 4)
		{
			if (LAB_Andar(ConvDir(entrada)))
			{
				TelaPrbs();
				return;
			}
		}

		else if (entrada ==5)
		{
			int resp;
			system("cls");
			printf("Tem certeza que quer voltar ao menu principal?\n"
					"O progresso de seu jogo sera perdido.\n"
					"1 - SIM\n"
					"2 - NAO\n");
			scanf("%d", &resp);
			while (resp !=1 && resp!=2)
			{
				resp=ReobterEntrada();
			}
			if (resp == 1 )
			{
				return; 
			}

		}
		else
		{
			while (entrada<1 || entrada >5)
			{
				entrada=ReobterEntrada();
			}
		}
		system("cls");
		LAB_MostraLab();

		printf("\n\n1 - Mover-se para Sul\n"
				"2 - Mover-se para Norte\n"
				"3 - Mover-se para Oeste\n"
				"4 - Mover-se para Leste\n"
				"5 - Voltar ao menu principal\n\n"
				"Escolha uma das opcoes: ");
		scanf("%d",&entrada);
	}
}

char ConvDir (int cod)
{
	if (cod == 1)
	{
		return 'n';
	}
	else if (cod == 2)
	{
		return 's';
	}
	else if (cod == 3)
	{
		return 'o';
	}
	else
	{
		return 'l';
	}

}
void TelaPrbs ( void )
{
	system("cls");
	printf("\n\n\n\n\t\t\t\t\tPARABENS!!!\n\n\n\n\n\n");
	system("pause");
}
int ReobterEntrada ( void )
{
	int entrada;
	printf("Opcao invalida, por favor escolha uma das listadas acima: ");
	scanf("%d", &entrada);
	return entrada;
}

void CriarLab ( void )
{
	int input1, input2;

	printf("Quantas celulas de altura deve ter o labirinto? (Maximo de 40)\n");
	scanf("%d",&input1);
	while(0)
	{
	}

	printf("Quantas celulas de largura deve ter o labirinto? (Maximo de 40)\n");
	scanf("%d",&input2);
	while(0)
	{
	}

	LAB_CriarLab(input1,input2);

	system("cls");
	LAB_MostraLab();

	system("pause");
}