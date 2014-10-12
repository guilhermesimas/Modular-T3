#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "LABIRINTO.H"

void Titulo ( void );
void InicializaLAB (void );
void MenuPrincipal ( void ) ;
void JogarLab ( void );
char ConvDir (int cod);
void TelaPrbs ( void );
int ReobterEntrada ( void );
void CriarLab ( void );
void ObtemPosicaoValida(int altura,int largura,int *x,int *y);


int main (){
	int entrada;

	MenuPrincipal();

	printf("Entre sua escolha: ");
	scanf("%d",&entrada);

	while (entrada!=3) 
	{
		if(entrada==1)
		{
			system("cls");
			CriarLab();
			/******************   ver cirar lab pra interface de usuario que falta  *******************/
		}
		
		else if (entrada == 2)
		{
			system("cls");
			LAB_Carregar("teste.lab");
			JogarLab();
			/************** Falta interface com usuario pedindo nome do arquivo  **************************/
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
	
	LAB_DestruirLab();

	return 0;
}

void Titulo ( void )
{
		printf("\n\n");
	printf("\t\t _           _     _      _       _        \n"
		   "\t\t| |         | |   (_)    (_)     | |       \n"
		   "\t\t| |     __ _| |__  _ _ __ _ _ __ | |_ ___  \n"
		   "\t\t| |    / _` | '_ \\| | '__| | '_ \\| __/ _ \\ \n"
		   "\t\t| |___| (_| | |_) | | |  | | | | | || (_) |\n"
		   "\t\t\\_____/\\__,_|_.__/|_|_|  |_|_| |_|\\__\\___/ \n"
		   "                                           \n"
		   "                                           \n");

}
void MenuPrincipal ( void ) {

	Titulo();
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
	while (entrada<1 || entrada >5)
	{
		entrada=ReobterEntrada();
	}

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
		
		system("cls");
		LAB_MostraLab();

		printf("\n\n1 - Mover-se para Sul\n"
				"2 - Mover-se para Norte\n"
				"3 - Mover-se para Oeste\n"
				"4 - Mover-se para Leste\n"
				"5 - Voltar ao menu principal\n\n"
				"Escolha uma das opcoes: ");
		scanf("%d",&entrada);
		while (entrada<1 || entrada >5)
			{
				entrada=ReobterEntrada();
			}
	}
}

char ConvDir (int cod)
{
	if (cod == 1)
	{
		return 's';
	}
	else if (cod == 2)
	{
		return 'n';
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
	printf("\n\n\t _____        _____            ____  ______ _   _  _____ _ _ \n"
			"\t|  __ \\ /\\   |  __ \\     /\\   |  _ \\|  ____| \\ | |/ ____| | |\n"
			"\t| |__) /  \\  | |__) |   /  \\  | |_) | |__  |  \\| | (___ | | |\n"
			"\t|  ___/ /\\ \\ |  _  /   / /\\ \\ |  _ <|  __| | . ` |\\___ \\| | |\n"
			"\t| |  / ____ \\| | \\ \\  / ____ \\| |_) | |____| |\\  |____) |_|_|\n"
			"\t|_| /_/    \\_\\_|  \\_\\/_/    \\_\\____/|______|_| \\_|_____/(_|_)\n\n\n");
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
	int altura, largura, x,y;
	LAB_DestruirLab();
	printf("Criando Labirinto...\n\n");
	Titulo();
	printf("Quantas celulas de altura deve ter o labirinto? (Maximo de 38)\n");
	scanf("%d",&altura);
	while(altura<=0 || altura >38)
	{
		printf("Altura invalida, forneca uma entre 1 e 38: ");
		scanf("%d",&altura);

	}

	printf("Quantas celulas de largura deve ter o labirinto? (Maximo de 38)\n");
	scanf("%d",&largura);
	while(largura<=0 || largura >38)
	{
		printf("Largura invalida, forneca uma entre 1 e 38: ");
		scanf("%d",&largura);

	}

	LAB_CriarLab(altura,largura);

	system("cls");
	printf("Criando Labirinto...\n\n");
	LAB_MostraLab();

	printf("\n\nQual a posicao da entrada? (x,y)\n");
	ObtemPosicaoValida(altura,largura,&x,&y);
	LAB_CriarEntrada(x,y);

	printf("Qual a posicao da saida? (x,y)\n");
	ObtemPosicaoValida(altura,largura,&x,&y);
	LAB_CriarSaida(x,y);

	system("cls");
	printf("Criando Labirinto...\n\n");
	LAB_MostraLab();

	printf("Comandos:\n"
			"caminho x,y <direcao>\n"
			"salvar <nomedoarquivo>\n"
			"resolver\n");

	/**********************   FALTA COISA AQUI      **********************************////////////////////////////////////////////////////////////

	system("pause");
}
void ObtemPosicaoValida(int altura,int largura,int *x,int *y)
{
	*x=-1;
	*y=-1;
	scanf("%d,%d",x,y);
	while (*x<1 || *x>largura )
	{
		printf("Posicao x invalida, forneca uma coordenada entre 1 e %d: ", largura);
		scanf("%d",x);
	}
	while ( *y<1 || *y>altura)
	{
		printf("Posicao y invalida, forneca uma coordenada entre 1 e %d: ", altura);
		scanf("%d",y);
	}
}