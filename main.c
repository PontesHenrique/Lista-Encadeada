#include "lista.c"

int main(void)
{
	int id = 1;
	int continuar;
	
	setlocale(LC_ALL, "Portuguese");
	
	No *cabecaLista = NULL;
	
	char opcao_char = 'a';
	int opcao = opcao_char;
    while(opcao){
        printf("	*** Lista Encadeada ***\n\n");
        printf("1) Inserir no início da Lista\n");
        printf("2) Inserir no final da Lista\n");
        printf("3) Inserir ordenado da Lista\n");
        printf("4) Remover elemento da Lista\n");
        printf("5) Buscar elemento na Lista\n");
        printf("6) Tamanho da Lista\n");
        printf("7) Imprimir Lista\n");
        printf("8) Limpar Lista\n");
        printf("0) Encerrar\n\n");

        do{
        	fflush(stdin);
            printf("Opção:");
            scanf("%d", &opcao_char);
            fflush(stdin);
            if(opcao == 48){
            	if(!cabecaLista){
            		return EXIT_SUCCESS;
				}
            	free(cabecaLista);
				printf("Memória liberada com sucesso");
            	return EXIT_SUCCESS;
			}
        }while((opcao < 49 || opcao > 56));
  
        fflush(stdin);
        system("CLS");//limpa a tela

        switch(opcao){
            case 49:
                inserirInicio(&cabecaLista, id);
                id++;
                imprimeLista(cabecaLista, "Lista: ");
            break;
            
            case 50:
            	printf("Digite numero: ");
            	scanf("%d", &id);
                inserirFinal(&cabecaLista, id);
                imprimeLista(cabecaLista, "Lista: ");
            break;
            
            case 51:
                printf("Digite numero: ");
            	scanf("%d", &id);
                inserirOrdenado(&cabecaLista, id);
                imprimeLista(cabecaLista, "Lista: ");
            break;
            
            case 52:
            	
            	continuar = validarResp("Confirma Remover elemento?", 1);//Retorna 1 se a resposta for verdadeira e realiza novo cadastro
    			system("CLS");
    			if(continuar){
    				printf("Digite numero: ");
	            	scanf("%d", &id);
	                if(!removeElemento(&cabecaLista, id)){
	                	printf("O elemnto %d não pertence a lista\n");
					}
	                imprimeLista(cabecaLista, "Lista: ");
				}
                
            break;
            
            case 53:
                printf("Digite o elemento para busca: ");
                scanf("%d", &id);
                if(buscaElemento(cabecaLista, id)){
                	printf("%d pertence a lista\n");
				}else{
					printf("%d não pertence a lista\n");
				}
            break;
            
            case 54:
            	imprimeLista(cabecaLista, "Lista: ");
                printf("A lista possui %d elementos\n", tamanhoLista(cabecaLista));
            break;
            
            case 55:
                imprimeLista(cabecaLista, "Lista: ");
            break;
            
            case 56:
                limparLista(&cabecaLista);
            	imprimeLista(cabecaLista, "Lista: ");
            break;

        }
    }//fim do while
    
	//free(cabecaLista);
	//printf("Memória liberada com sucesso");
    //return EXIT_SUCCESS;

}

























