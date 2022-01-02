#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void TPilha_Atual (int *pilha, int topo) { //Imprime todos os elementos da pilha
	int i;
	printf ("Pilha atual: ");
	for (i=1; i<=topo; i++) {
		printf ("%d ", pilha[i]);
	}
	printf ("\n");
}

int TPilha_EhVazia (int topo) { //Verifica se a pilha está vazia
	if (topo==0) {
		printf ("A pilha está vazia\n");
		return 1;
	}
	else {
		return 0;
	}
}

int TPilha_EhCheia (int max, int topo) { //Verifica se a pilha está cheia
	if (topo==max) { 
		printf ("A pilha está cheia\n");
		return 1;
	}
	else {
		return 0;
	}
}

void TPilha_Empilha (int *pilha, int insere, int topo) { //Insere um elemento, e depois imprime a pilha
	pilha[topo+1]=insere;
	TPilha_Atual(pilha, topo+1);
}

//---------------------------------

int main () {
	int *pilha;
	int n, opcao, insere, topo=0;
	
	printf ("Digite o tamanho da pilha: ");
	scanf ("%d", &n);
	printf ("\n");
	pilha=(int *) malloc (n * sizeof(int)); //Inicia a pilha com o tamanho desejado
	while (opcao!=4) {
		printf ("Escolha uma operação (1-push / 2-pop / 3-top / 4-fim): ");
		scanf ("%d", &opcao);
		switch (opcao) {
			case 1: //Caso "Push" (insere um item)
				if (TPilha_EhCheia(n, topo)==0) { //Verifica se um elemento pode ser adicionado
					printf ("Digite o número desejado: ");
					scanf ("%d", &insere);
					printf ("\n");
					TPilha_Empilha(pilha, insere, topo);
					topo++;
				}
				break;
			case 2: //Caso "Pop" (retira o último item)
				if (TPilha_EhVazia(topo)==0) { //Verifica se um elemento pode ser retirado
					topo--; //Diminui o índice do topo, ignorando o valor posterior
					TPilha_Atual(pilha, topo);
				}
				break;
			case 3: //Caso "Top" (verifica o valor do último item)
				if (TPilha_EhVazia(topo)==0) {
					printf ("Topo da pilha: %d\n", pilha[topo]);
				}
				break;
		}
	}
	
	return 0;
}
