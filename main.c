#include <stdio.h>
#include "LABIRINTO.H"

int main (){

	printf("comecou\n\n");

	LAB_CriarLab(3,3);
	LAB_MostraLab();
	
	LAB_CriarCaminho(1,1,'l');
	LAB_CriarCaminho(2,1,'l');
	LAB_CriarCaminho(3,1,'n');
	LAB_CriarCaminho(3,2,'o');
	LAB_CriarCaminho(2,2,'o');
	LAB_CriarCaminho(1,3,'s');
	LAB_CriarCaminho(1,3,'l');
	LAB_CriarCaminho(2,3,'l');

	LAB_MostraLab();


	printf("\n\nterminou\n\n");
	return 0;
}