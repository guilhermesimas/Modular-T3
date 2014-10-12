#include <stdio.h>
#include "LABIRINTO.H"

int main (){

	printf("comecou\n\n");

	LAB_CriarLab(3,3);
	LAB_MostraLab();
	
	LAB_CriarCaminho(0,2,'l');
	LAB_CriarCaminho(1,2,'l');
	LAB_CriarCaminho(2,2,'n');
	LAB_CriarCaminho(2,1,'o');
	LAB_CriarCaminho(1,1,'o');
	LAB_CriarCaminho(0,1,'n');
	LAB_CriarCaminho(0,0,'l');
	LAB_CriarCaminho(1,0,'l');

	LAB_MostraLab();


	printf("\n\nterminou\n\n");
	return 0;
}