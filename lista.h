#ifndef _LISTA_H_
#define _LISTA_H_

typedef struct no No;

No *criarNo(int id);
int listaVazia(No *inicioLista);
int tamanhoLista(No *inicioLista);
int inserirInicio(No **inicioLista, int id);
int inserirFinal(No **inicioLista, int id);
int inserirOrdenado(No **inicioLista, int id);
int buscaElemento(No *inicioLista, int id);
void imprimeLista(No *inicioLista, char *mensagem);
void limparLista(No **inicioLista);
int removeElemento(No **inicioLista, int id);
int validarResp(char mensagem[], int padrao);

#endif

