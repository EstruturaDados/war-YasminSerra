#include <stdio.h> 
#include <string.h>

#define MAX_PAISES 5
#define TAM_NOME 30
#define TAM_COR 10

struct Territorio {
    char nome[TAM_NOME];
    char cor [TAM_COR];
    int tropas;
};

void limparBufferEntrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    struct Territorio territorios [MAX_PAISES];
    int totalpaises = 0;
    int opcao;

    do {

        printf("===================================\n");
        printf("CADASTRAMENtO DE TERRITÓRIO\n");
        printf("===================================\n");
        printf("1 - Cadastrar novo Território\n");
        printf("2 - Listar todos os Territórios\n");
        printf("0 - Sair\n");
        printf("------------------------------------\n");   
        printf("Escolha uma opcao: ");

        scanf("%d", &opcao);
        limparBufferEntrada();

        switch (opcao) {
            case 1: 
                printf("---cadastro de Novo Território -----\n\n");
               
                if (totalpaises < MAX_PAISES) {
                    printf("Digite o nome do país: ");
                    fgets(territorios[totalpaises].nome, TAM_NOME, stdin);
                   
                    printf("Digite a cor: ");
                    fgets(territorios[totalpaises].cor, TAM_COR, stdin);


                  territorios[totalpaises].nome[strcspn(territorios[totalpaises].nome, "\n")] = '\0';
                  territorios[totalpaises].cor[strcspn(territorios[totalpaises].cor, "\n")] = '\0';
                  

                  printf("Digite o número de tropas: ");
                  scanf("%d", &territorios[totalpaises].tropas);
                  limparBufferEntrada();

                  totalpaises++;

                  printf("\nTerritório cadastrado com sucesso!\n");

                } else {
                    
                    printf(" Limite de Territórios atingidos! Nao é possivel cadastrar mais territórios. \n: ");
                }
                break;
            case 2: 
                if (totalpaises == 0)  {
                    printf("Nenhum Territórico cadastrado ainda.\n");
                } else { 
                    for (int i = 0; i < totalpaises; i++ ) {
                        printf("---------------------------\n");
                        printf("Território %d \n", i + 1);
                        printf("Nome: %s\n", territorios[i].nome );
                        printf("cor: %s\n", territorios[i].cor );
                        printf("tropas: %d\n", territorios[i].tropas );
                    }
                    printf("---------------------------\n");
                }

                printf("\nPressione Enter para continuar...");
                getchar();
                break;
            case 0: 
                printf("\nSaindo do sistema...\n");
                break;

            default:
                printf("\nOpcao invalida! Tente novamente.\n");
                printf("\nPressione Enter para continuar...");
                getchar();
                break;
        }
    } while (opcao != 0);

    return 0;
}