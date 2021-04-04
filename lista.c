#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <locale.h>
#include <ctype.h>

#include "lista.h"

#define NOME_TAM 30
#define END_TAM 50

#ifndef _LISTA_C_
#define _LISTA_C_

struct no
{
	int id;
	struct no *proximoNo;
};

No *criarNo(int id){
	
	No *no = (No*)malloc(sizeof(No));
	if(no){
		no->id = id;
		no->proximoNo = NULL;
	}
	return no;
}

listaVazia(No *inicioLista){
	return (inicioLista == NULL);
}

int tamanhoLista(No *inicioLista){
	
	int tamanho = 0;
	while(inicioLista){
		tamanho ++;
		inicioLista = inicioLista->proximoNo;
	}
	return tamanho;
}

int inserirInicio(No **inicioLista, int id){
	
	No *aux = criarNo(id);
	if(aux){
		aux->proximoNo = *inicioLista;
		*inicioLista = aux;
		return 1;
	}
	return 0;
}

int inserirFinal(No **inicioLista, int id){
	
	if(listaVazia(*inicioLista)){
		return inserirInicio(inicioLista, id);
	}else{
		No *aux = criarNo(id);
		if(aux){
			No *flag = *inicioLista;
			while(flag->proximoNo){
				flag = flag->proximoNo;
			}
			flag->proximoNo = aux;
			return 1;
		}
	}
	return 0;
}

int inserirOrdenado(No **inicioLista, int id){
	
	if(listaVazia(*inicioLista)){
		return inserirInicio(inicioLista, id);
	}
	
	No *novo = criarNo(id);
	if (novo){
		No *anterior = NULL;
		No *aux = *inicioLista;
		while(aux && aux->id < id){
			anterior = aux;
			aux = aux->proximoNo;
		}
		if(anterior == NULL){
			novo->proximoNo = *inicioLista;
			*inicioLista = novo;
			return 1;
		}
		novo->proximoNo = anterior->proximoNo;
		anterior->proximoNo = novo;
		return 1;
	}
	return 0;
}

int buscaElemento(No *inicioLista, int id)
{
	if(listaVazia(inicioLista)){
		return 0;
	}
	while(inicioLista){
		if(inicioLista->id == id){
			return 1;
		}
		inicioLista = inicioLista->proximoNo;
	}
	return 0;
}

void imprimeLista(No *inicioLista, char *mensagem){
	
	printf("%s", mensagem);
	while(inicioLista){
		printf("%d -> ", inicioLista->id);
		inicioLista = inicioLista->proximoNo;
	}
	printf(" NULL\n");
}

void limparLista(No **inicioLista){
	No *prox = NULL;
	No *aux = *inicioLista;
	while(aux){
		prox = aux->proximoNo;
		free(aux);
		aux = prox;
	}
	*inicioLista = NULL;
}

int removeElemento(No **inicioLista, int id){
	
	No *anterior = NULL;
	No *aux = *inicioLista;
	int flag = 0;
	while(aux){
		if(aux->id == id){
			flag = 1;
			break;
		}
		anterior = aux;
		aux = aux->proximoNo;
	}//fim do while
	
	if(flag){
		if(anterior == NULL){
			*inicioLista = aux->proximoNo;
			free(aux);
			return 1;
		}
		
		anterior->proximoNo = aux->proximoNo;
		free(aux);
		return 1;
	}
	return 0;
}

//============================  Valida uma determinada ação, onde será recebida a mensagem que será exibida para o usuario  ===========================
//============================             e apartir da opção escolhida, retorna 1 caso Sim, e 0 caso Não                  ============================

int validarResp(char mensagem[], int padrao) {
   int op;
   char cPadrao = (padrao ? 's' : 'n');

   do {
      printf("\n%s [S ou N] %c", mensagem, cPadrao);
      op = getch();
      printf("\n" );
   } while (op != 's' && op != 'S' && op != 'n' && op != 'N' && op != 13);

    if(op == 13)
        return padrao;

   return ((op == 's' || op == 'S') ? 1 : 0);
}

#endif
