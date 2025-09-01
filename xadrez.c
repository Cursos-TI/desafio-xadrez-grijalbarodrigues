#include <stdio.h>
#include <string.h>

void MovTorre (int numTorre, const char direcaoTorre[])
{
    if(numTorre > 0){
        printf("%s\n", direcaoTorre);
        MovTorre(numTorre - 1, direcaoTorre);
    }
}

void MovBispo(int passo, int totalPassos, char direcaoBispoX[], char direcaoBispoY[]) {
    if (passo < totalPassos) {
        for (int i = 0; i < 1; i++) { // loop externo (vertical)
            for (int j = 0; j < 1; j++) { // loop interno (horizontal)
                printf("%s e %s\n", direcaoBispoY, direcaoBispoX);
            }
        }
        MovBispo(passo + 1, totalPassos, direcaoBispoX, direcaoBispoY);
    }
}

void MovRainhaH (int numRainha, char direcaoRainhaX[]){
    
    if(numRainha >0){
        printf("%s\n", direcaoRainhaX);

        MovRainhaH (numRainha -1, direcaoRainhaX);
    }
}

void MovRainhaV (int numRainha, char direcaoRainhaY[]){
    
    if(numRainha >0){
        printf("%s\n", direcaoRainhaY);

        MovRainhaV (numRainha -1, direcaoRainhaY);
    }
}

void MovRainhaD (int numRainha, char direcaoRainhaX[], char direcaoRainhaY[]){
    if (numRainha >0){
        printf("%s e %s\n", direcaoRainhaY, direcaoRainhaX);
        MovRainhaD(numRainha -1, direcaoRainhaX, direcaoRainhaY);
        
    }
}

int main (){

    int opcao;
    int x, y;
    int i = 1;

    printf("***VAMOS INICIAR O JOGO DE XADREZ***\n");
    printf("Escolha uma das peças abaixo para o primeiro movimento:\n");
    printf("1. para Torre\n");
    printf("2. para Bispo\n");
    printf("3. para Rainha\n");
    printf("4. para Cavalo\n");
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

        MovTorre(casasTorre, direcaoTorre);
                
        break;

        /*for( i =1; i <= casasTorre; i++){
        printf("%d casa para %s\n", i, direcaoTorre);
        }
        printf("A torre se moveu %d casas para %s.\n", i -1, direcaoTorre);
        break;*/
    
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

        MovBispo (0, casasBispo, direcaoBispoX, direcaoBispoY);

        /*while (i <= casasBispo)
        {
            printf("%d casa para %s e para %s\n", i, direcaoBispoY, direcaoBispoX);
            i++;
        } printf("O BISPO se moveu %d casas para %s e para %s\n", i-1, direcaoBispoY, direcaoBispoX);
        */
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

                MovRainhaH(casasRainha, direcaoRainhaX);

                /*do{
                    printf("%d casa para %s\n", i, direcaoRainhaX);
                    i++;
                }
                while (i <= casasRainha);{
                    printf("A Rainha se moveu %d casas para %s\n", i-1, direcaoRainhaX);
                }*/
                    break;

            case 2://rainha na vertical
                printf("Você quer movimentar a Rainha para CIMA ou para BAIXO?\n");

                while (getchar() != '\n');//limpar o buffer
                fgets(direcaoRainhaY, sizeof(direcaoRainhaY), stdin);
                direcaoRainhaY[strcspn (direcaoRainhaY, "\n")]='\0';

                printf("Quantas casas você quer movimentar a Rainha?\n");
                scanf("%d", &casasRainha);

                MovRainhaV(casasRainha, direcaoRainhaY);

                /*do{
                    printf("%d casa para %s\n", i, direcaoRainhaY);
                    i++;
                }
                while (i <= casasRainha);{
                    printf("A Rainha se moveu %d casas para %s\n", i-1, direcaoRainhaY);
                }*/
                    break;

            case 3://rainha na diagonal
                char direcaoRainhaX[11], direcaoRainhaY[11];
                int casasRainha;
                
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

                MovRainhaD (casasRainha, direcaoRainhaX, direcaoRainhaY);

                /*while (i <= casasRainha)
                {
                    printf("%d casa para %s e para %s\n", i, direcaoRainhaY, direcaoRainhaX);
                    i++;
                } printf("A RAINHA se moveu %d casas para %s e para %s\n", i-1, direcaoRainhaY, direcaoRainhaX);*/
            } break;   
    case 4: //cavalo

        int cavaloX, cavaloY, cavaloCompleto;
        int opcaoCavalo;

        printf("O cavalo se movimenta em L.\n");
        printf("Para isso você precisa escolher 2 movimentos\n");
        printf("Qual será o primeiro movimento do cavalo?\n");
        printf("1. HORIZONTAL DIREITA\n");
        printf("2. HORIZONTAL ESQUERDA\n");
        printf("3. VERTICAL PARA CIMA\n");
        printf("4. VERTICAL PARA BAIXO\n");
        scanf("%d", &opcaoCavalo);

        switch (opcaoCavalo)
        {
        case 1://primeiro movimento cavalo - HORIZONTAL DIREITA
            
            int opcaoCavaloHD;

            printf("Você escolheu o 1º movimento do cavalo para HORIZONTAL DIREITA\n");
            printf("Na horizontal direita você quer mover para CIMA ou para BAIXO?\n");
            printf("1. HORIZONTAL DIREITA PARA CIMA\n");
            printf("2. HORIZONTAL DIREITA PARA BAIXO\n");
            scanf("%d", &opcaoCavaloHD);
            
                switch (opcaoCavaloHD)
                {
                case 1://HORIZONTAL DIREITA PARA CIMA
                    
                    int i;
                    
                    for(i = 1; i==1; i++){
                        for(int j =1; j<=2; j++){
                            printf("Direita\n");
                        }
                        
                    }printf("Cima\n");
                    printf("\n");
                    
                    break;
                case 2://HORIZONTAL DIREIA PARA BAIXO
                                        
                    for(i = 1; i==1; i++){
                        for(int j =1; j<=2; j++){
                            printf("Direita\n");
                        }
                        
                    }printf("Baixo\n");
                    printf("\n");
                                        
                    break;
                }break;    
            
        case 2://segundo movimento cavalo - horizontal ESQUERDA
            
            int opcaoCavaloHE;
            printf("Você escolheu o 1º movimento do cavalo para HORIZONTAL ESQUERDA\n");
            printf("Na horizontal esquerda você quer mover para CIMA ou para BAIXO?\n");
            printf("1. HORIZONTAL ESQUERDA PARA CIMA\n");
            printf("2. HORIZONTAL ESQUERDA PARA BAIXO\n");
            scanf("%d", &opcaoCavaloHE);
            
                switch (opcaoCavaloHE)
                {
                case 1://HORIZONTAL ESQUERDA PARA CIMA
                    
                    int i;
                    
                    for(i = 1; i==1; i++){
                        for(int j =1; j<=2; j++){
                            printf("Esqueda\n");
                        }
                        
                    }printf("Cima\n");
                    printf("\n");
                    
                    break;
                case 2://HORIZONTAL ESQUERDA PARA BAIXO
                                        
                    for(i = 1; i==1; i++){
                        for(int j =1; j<=2; j++){
                            printf("Esquerda\n");
                        }
                        
                    }printf("Baixo\n");
                    printf("\n");
                                        
                    break;
                }break;
        case 3://primeiro movimento cavalo - VERTICAL CIMA DIREITA
            
            int opcaoCavaloVcima;

            printf("Você escolheu o 1º movimento do cavalo na VERTICAL PARA CIMA\n");
            printf("Na vertical para cima você quer mover para DIREITA ou para ESQUERDA?\n");
            printf("1. VERTICAL PARA CIMA E DIREITA\n");
            printf("2. VERTICAL PARA CIMA E ESQUERDA\n");
            scanf("%d", &opcaoCavaloVcima);
            
                switch (opcaoCavaloVcima)
                {
                case 1://VERTICAL DIREITA PARA CIMA
                    
                    int i;
                    
                    for(i = 1; i==1; i++){
                        for(int j =1; j<=2; j++){
                            printf("Cima\n");
                        }
                        
                    }printf("Direita\n");
                    printf("\n");
                    
                    break;
                case 2://VERTICAL DIREIA PARA BAIXO
                                        
                    for(i = 1; i==1; i++){
                        for(int j =1; j<=2; j++){
                            printf("Cima\n");
                        }
                        
                    }printf("Esquerda\n");
                    printf("\n");
                                        
                    break;
                }break;    
        case 4://primeiro movimento cavalo - VERTICAL para baixo
            
            int opcaoCavaloVbaixo;

            printf("Você escolheu o 1º movimento do cavalo para VERTICAL PARA BAIXO\n");
            printf("Na vertical para baixo você quer mover para DIREITA ou para ESQUERDA?\n");
            printf("1. VERTICAL PARA BAIXO E DIREITA\n");
            printf("2. VERTICAL PARA BAIXO E ESQUERDA\n");
            scanf("%d", &opcaoCavaloVbaixo);
            
                switch (opcaoCavaloVbaixo)
                {
                case 1://VERTICAL DIREITA PARA BAIXO
                    
                    int i;
                    
                    for(i = 1; i==1; i++){
                        for(int j =1; j<=2; j++){
                            printf("Baixo\n");
                        }
                        
                    }printf("Direita\n");
                    printf("\n");
                    
                    break;
                case 2://VERTICAL ESQUERDA PARA BAIXO
                                        
                    for(i = 1; i==1; i++){
                        for(int j =1; j<=2; j++){
                            printf("Baixo\n");
                        }
                        
                    }printf("Esquerda\n");
                    printf("\n");
                                        
                    break;
                }break;
        
        }
    return 0;
}}