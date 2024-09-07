// Lucas Noia Pereira - DRE: 124367988

#include <stdio.h>
#include <string.h>

#define NOME_MAX 100
#define PRODUTO_MAX 100

typedef struct {
    int codigo;
    char nome[NOME_MAX];
    float preco;
    int quantidade;
} Produto;
Produto produtos[PRODUTO_MAX];
int num_produtos = 0;

int inserirProdutos();
int listarProdutos();
int buscarProdutoPorNome();
int excluirProdutoPorNome();
int menu();

int main(){
    menu();
    return 0;
}

int menu(){
    int opcao;
    do{
        printf("\n----Menu de Opcoes----\n");
        printf("1. Inserir Produtos\n");
        printf("2. Listar produtos\n");
        printf("3. Buscar produto pelo nome\n");
        printf("4. Excluir produto por nome\n");
        printf("5. Sair\n");
        scanf("%d", &opcao);
        
        switch (opcao)
        {
        case 1:
            inserirProdutos();
            break;
        case 2:
            listarProdutos();
            break;
        case 3:
            buscarProdutoPorNome();
            break;
        case 4: 
            excluirProdutoPorNome();
            break;
        case 5:
            printf("Saindo...\n");
            break;
        
        default:
            printf("Opcao invalida...\n");
        }
    } while (opcao   != 5);
    
    return 0;

}
int inserirProdutos(){
    if (num_produtos == PRODUTO_MAX){
        printf("Numero maximo de produtos atingidos!!!!\n");
        return 0;

    }
    Produto p;
    printf("Digite o codigo do produto: "); scanf("%d", &p.codigo);
    printf("Digite o nome do produto: "); scanf("%99s", p.nome); // usar isso para pegar um tamanho maximo no arry nome 
    printf("Digite o preco do produto: "); scanf("%f", &p.preco);
    printf("Digite a quantidade produtos: "); scanf("%d", &p.quantidade);

    for (int i = 0; i < num_produtos; i++){
        if(produtos[i].codigo == p.codigo){
            printf("Erro: ja existe um produto com esse codigo!!!\n");
            return 0;
        }
    }
    produtos[num_produtos] = p;
    num_produtos++;
    printf("Produto inserido com sucesso!\n");  
    return 0; 
}
int listarProdutos(){
    if (num_produtos == 0){
        printf("Nenhum produto encontrado...\n");
        return 0;
    }
    printf("----Lista de produtos----\n");
    for (int i = 0; i < num_produtos; i++){
        printf("Codigo: %d\nNome: %s\nPreco: R$ %.2f\nQuantidade: %d\n--------------------\n", produtos[i].codigo, produtos[i].nome, produtos[i].preco, produtos[i].quantidade);
    }
    return 0;
}
int buscarProdutoPorNome(){
    char nome[NOME_MAX];
    printf("Digite aqui o nome que deseja buscar: "); scanf("%99s", nome);
    for (int i = 0; i < num_produtos; i++){
        if (strcmp(nome, produtos[i].nome)==0){
            printf("\nProduto encontrado: \nCodigo: %d\nNome: %s\nPreco: R$ %.2f\nQuantidade: %d\n", produtos[i].codigo, produtos[i].nome, produtos[i].preco, produtos[i].quantidade);
            return 0;
        }
    
    }

    return 0;
}
int excluirProdutoPorNome(){
    char nome[NOME_MAX]; printf("Digite aqui o nome que deseja excluir: "); scanf("%99s", nome);
    for(int i = 0; i < num_produtos; i++){
        if (strcmp(nome, produtos[i].nome)==0){
            for (int j = i; j < num_produtos -1 ; j ++){
                produtos[j] = produtos[j+1];
            }
        }
        num_produtos--;
        printf("\nProduto excluido com sucesso!\n");
        return 0;
        
    }
    
    return 0;
}

