/*cadastrar cliente (nome + idade ou id)
listar clientes
buscar cliente
(extra se der tempo: remover)*/
#include <stdio.h>
#define MAX 100

typedef struct{
    int id;
    char nome[50];
}Cliente;

Cliente cliente[MAX];
int total = 0;

void cadastrar(Cliente *cliente,int *total);
void listar ( Cliente *cliente,int *total);
int buscar ( Cliente *cliente,int *total,int id);
void ordenar ( Cliente *cliente,int *total);
void remover (Cliente *cliente,int *total);

int main(){
    Cliente clientes[MAX];
    int total = 0;
    int opcao;

    do{
        printf("--------- MENU ---------\n");
        printf("1 - CADASTRAR\n");
        printf("2 - LISTAR\n");
        printf("3 - BUSCAR\n");
        printf("4 - ORDENAR\n");
        printf("5 - REMOVER\n");
        printf("0 - SAIR\n");
        printf("escolha uma opcao: ");
        scanf("%d", &opcao);

        switch(opcao){
            case 1 :
            printf("--------- CADASTRAR CLIENTE ---------\n");
            cadastrar(clientes,&total);
            printf("clente cadastrado!\n");
            break;

            case 2 :
            printf("--------- LISTAR CLIENTES ---------\n");
            listar(clientes,&total);
            printf("fim da operacao!\n");
            break;

            case 3 : 
            printf("--------- BUSCAR CLIENTE ---------\n");
            int id;
                printf("digite o ID do cliente para busca: ");
                scanf("%d", &id);
            buscar(clientes,&total,id);
            printf("fim da operacao\n");
            break;

            case 4 :
            printf("--------- ORDENAR CLIENTES ---------\n");
            ordenar(clientes,&total);
            printf("fim da operacao\n");
            break;

            case 5 : 
            printf("--------- REMOVER CLIENTE ---------\n");
            remover(clientes,&total);
            printf("fim da operacao!\n");
            break;

            case 0 :

            printf("saindo...\n");
            break;

            default :
            printf("opcao invalida!\n");
    
        }
        
    }while(opcao !=0);


    return 0;
}
void cadastrar(Cliente *cliente,int *total){
    if (*total >= MAX){
        printf("total de clientes ja atingido!!");
        return;
    }
    printf("digite ID do cliente: ");
    scanf("%d", &cliente[*total].id);
    printf(" \n");
    printf("digite nome do cliente: ");
    scanf(" %[^\n]", &cliente[*total].nome);
    
    (*total)++;

}
void listar(Cliente *cliente,int *total){
    for(int i = 0; i < *total; i++){
        printf("ID : %d || Nome : %s\n", cliente[i].id, cliente[i].nome);
        printf("\n");
    }


}
int buscar ( Cliente *cliente,int *total,int id){
    for(int i = 0; i < *total; i++){
        if(id == cliente[i].id){
            printf("cliente encontrado: %s\n", cliente[i].nome);
            return i;
        }
        printf("cliente nao encontrado!!");
        return -1;
    }
}
void ordenar (Cliente *cliente,int *total){
    Cliente temp;
    for(int i = 0 ; i < *total - 1; i++){
        for(int j = 0; j < *total - 1 - i; j ++){
            if(cliente[j].id > cliente[j + 1].id){
                temp = cliente[j];
                cliente[j].id = cliente[j + 1].id;
                cliente[j + 1] = temp;
                }
        }
    }
}
void remover (Cliente *cliente,int *total){
    int id;
    printf("digite id do cliente a ser removido: ");
    scanf("%d", &id);
    int pos = buscar(cliente,total, id);
    if(pos == -1){
        printf("ID incorreto ou cliente nao encontrado!!\n");
        return;
    }
    for(int i = 0; i < *total - 1; i ++){
        cliente[i] = cliente[i + 1];
        }
        (*total)--;
        printf("Cliente removido com sucesso\n");
    }