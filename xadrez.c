#include <stdio.h>
#include <string.h>

int main (){

    int opcao;
    int x, y;
    int i = 1;

    printf("***VAMOS INICIAR O JOGO DE XADREZ***\n");
    printf("Escolha uma das peças abaixo para o primeiro movimento:\n");
    printf("1. para Torre\n");
    printf("2. para Bispo\n");
    printf("3. para Rainha\n");
    scanf("%d", &opcao);
    
    switch (opcao)
    {
    case 1://movimento da torre com for
        char direcaoTorre[11];
        int casasTorre;
        
        
        printf("Você escolheu a TORRE\n");
        printf("Para qual direção você quer movimentar a TORRE?\n");

        while (getchar() != '\n');//limpar o buffer
        fgets(direcaoTorre, sizeof(direcaoTorre), stdin);
        direcaoTorre[strcspn (direcaoTorre, "\n")]='\0';

        printf("Quantas casas você quer movimentar a TORRE?\n");
        scanf("%d", &casasTorre);


        for( i =1; i <= casasTorre; i++){
        printf("%d casa para %s\n", i, direcaoTorre);
        }
        printf("A torre se moveu %d casas para %s.\n", i -1, direcaoTorre);
        break;

    case 2://movimento do BISPO COM while
        char direcaoBispoX[11], direcaoBispoY[11];
        int casasBispo;
                
        
        printf("Você escolheu o BISPO\n");
        printf("Atenção! O Bispo se move na diagonal\n");

        printf("PRIMEIRO MOVIMENTO DO BISPO\n");
        printf("Você quer movimentar o Bispo para CIMA ou para BAIXO?\n");

        while (getchar() != '\n');//limpar o buffer
        fgets(direcaoBispoY, sizeof(direcaoBispoY), stdin);
        direcaoBispoY[strcspn (direcaoBispoY, "\n")]='\0';

        printf("SEGUNDO MOVIMENTO DO BISPO\n");
        printf("Você quer movimentar o Bispo para DIREITA ou para ESQUERDA?\n");

        //while (getchar() != '\n');//limpar o buffer
        fgets(direcaoBispoX, sizeof(direcaoBispoX), stdin);
        direcaoBispoX[strcspn (direcaoBispoX, "\n")]='\0';

        printf("Quantas casas você quer movimentar o BISPO?\n");
        scanf("%d", &casasBispo);

        while (i <= casasBispo)
        {
            printf("%d casa para %s e para %s\n", i, direcaoBispoY, direcaoBispoX);
            i++;
        } printf("O BISPO se moveu %d casas para %s e para %s\n", i-1, direcaoBispoY, direcaoBispoX);
        
        break;

    case 3://movimento da rainha com do-while
        char direcaoRainhaX[11], direcaoRainhaY[11];
        int casasRainha, direcaoRainha;    
        
        printf("Você escolheu o RAINHA\n");
        printf("A Rainha se move em todos os sentidos: horizontal, vertical e diagonal\n");
        printf("Qual sentido você quer movimentar a Rainha?\n");
        printf("1. Horizontal\n");
        printf("2. Vertical\n");
        printf("3. Diagonal\n");
        scanf("%d", &direcaoRainha);

            switch (direcaoRainha)
            {
            case 1://rainha na horizonta
                
                printf("Você quer movimentar a Rainha para DIREITA ou ESQUERDA?\n");

                while (getchar() != '\n');//limpar o buffer
                fgets(direcaoRainhaX, sizeof(direcaoRainhaX), stdin);
                direcaoRainhaX[strcspn (direcaoRainhaX, "\n")]='\0';

                printf("Quantas casas você quer movimentar a Rainha?\n");
                scanf("%d", &casasRainha);

                do{
                    printf("%d casa para %s\n", i, direcaoRainhaX);
                    i++;
                }
                while (i <= casasRainha);{
                    printf("A Rainha se moveu %d casas para %s\n", i-1, direcaoRainhaX);
                }break;

            case 2://rainha na vertical
                printf("Você quer movimentar a Rainha para CIMA ou para BAIXO?\n");

                while (getchar() != '\n');//limpar o buffer
                fgets(direcaoRainhaY, sizeof(direcaoRainhaY), stdin);
                direcaoRainhaY[strcspn (direcaoRainhaY, "\n")]='\0';

                printf("Quantas casas você quer movimentar a Rainha?\n");
                scanf("%d", &casasRainha);

                do{
                    printf("%d casa para %s\n", i, direcaoRainhaY);
                    i++;
                }
                while (i <= casasRainha);{
                    printf("A Rainha se moveu %d casas para %s\n", i-1, direcaoRainhaY);
                }break;

            case 3://rainha na diagonal
                char direcaoBispoX[11], direcaoBispoY[11];
                int casasBispo;
                
                printf("PRIMEIRO MOVIMENTO DA RAINHA\n");
                printf("Você quer movimentar a RAINHA para CIMA ou para BAIXO?\n");

                while (getchar() != '\n');//limpar o buffer
                fgets(direcaoRainhaY, sizeof(direcaoRainhaY), stdin);
                direcaoRainhaY[strcspn (direcaoRainhaY, "\n")]='\0';

                printf("SEGUNDO MOVIMENTO DA RAINHA\n");
                printf("Você quer movimentar a RAINHA para DIREITA ou para ESQUERDA?\n");

                //while (getchar() != '\n');//limpar o buffer
                fgets(direcaoRainhaX, sizeof(direcaoRainhaX), stdin);
                direcaoRainhaX[strcspn (direcaoRainhaX, "\n")]='\0';

                printf("Quantas casas você quer movimentar a RAINHA?\n");
                scanf("%d", &casasRainha);

                while (i <= casasRainha)
                {
                    printf("%d casa para %s e para %s\n", i, direcaoRainhaY, direcaoRainhaX);
                    i++;
                } printf("A RAINHA se moveu %d casas para %s e para %s\n", i-1, direcaoRainhaY, direcaoRainhaX);
                
                break;
                    
            }
    }

    return 0;
}