#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

 typedef struct Nodo{
      int info;
      struct Nodo *prox;

 }Nodo;

  typedef struct Lista{
        Nodo *prim;
  }Lista;

  void InserirNaLista(Lista *lista,int valor){
       Nodo *novo = malloc(sizeof(Nodo));
        if(novo != NULL){
           novo -> info = valor;
           novo -> prox = lista -> prim;
           lista -> prim = novo;
        }
        else{
            printf("Memória Insuficiente");
        }
  }
        void ConsultarLista(Lista *lista){
            if(lista->prim == NULL){
                printf("Lista vazia\n");
                return;
            }
            Nodo *novo = lista -> prim;
            printf("\nLista: ");
            while(novo != NULL){
                printf("%d ",novo -> info);
                novo = novo -> prox;
            }
            printf("\n\n");

        }
        void AlterarLista(Lista *lista,int valor1,int valor2){
            Nodo *pAtu = lista->prim;
            while(pAtu != NULL && pAtu->info != valor1){
                pAtu = pAtu -> prox;
            }

            if(pAtu != NULL){
                    pAtu->info = valor2;
                    printf("Valor alterado\n");
             } else{
                printf("Valor não encontrado\n");
              }

            }

  void RemoverElementoLista(Lista *lista,int valor){
          Nodo *pAtu = lista->prim;
          Nodo *pAnt = NULL;

         while(pAtu != NULL && pAtu->info != valor){
            pAnt = pAtu;
            pAtu = pAtu -> prox;
         }
         if(pAtu != NULL){
            if(pAnt == NULL){
                lista->prim = pAtu->prox;
            }
            else{
                pAnt->prox = pAtu->prox;
            }
            free(pAtu);
            printf("Valor removido\n");
         }
         else{
            printf("Valor não encontrado\n");
         }
  }

int main(){
    setlocale(LC_ALL, "");

  Lista *lista = malloc(sizeof(Lista));
  lista->prim = NULL;

  int op,valor,valor1,valor2;

  do{
       printf("\nDigite 1 para Inserir:\n");
       printf("Digite 2 para Consultar:\n");
       printf("Digite 3 para Alterar:\n");
       printf("Digite 4 para Remover:\n");
       printf("Digite 0 para sair:\n");
       printf("Escolha uma opção:\n");
       scanf("%d",&op);

        switch(op){
       case 1:
           printf("Digite o valor:\n");
           scanf("%d",&valor);
           InserirNaLista(lista,valor);
           break;
         case 2:
             ConsultarLista(lista);
             break;
         case 3:
             printf("Digite o primeiro valor:\n");
             scanf("%d",&valor1);
             printf("Digite o segundo valor:\n");
             scanf("%d",&valor2);
             AlterarLista(lista,valor1,valor2);
             break;
         case 4:
             printf("Digite o valor:\n");
             scanf("%d",&valor);
             RemoverElementoLista(lista,valor);
             break;
         default:
             if(op != 0){
            printf("Opçao Inválida!");

        }
    }
  }while(op != 0);

    free(lista);
    return 0;
}
