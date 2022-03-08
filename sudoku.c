#include <stdio.h>

void print_matriz(int matriz[9][9]){
    int i,j,a=1,b=1;
    for (i = 1; i < 10; i++){
        if (i == 4 || i == 7)
            printf("\t");
        printf("\t%i", i);
    }

    printf("\n  -----------------------------------------------------------------------------------------------\n");

    for (i=0;i<9;i++){
        printf("%i |", i+1);
        for(j=0;j<9;j++){
            printf("\t%i",matriz[i][j]);
            if (a==3){
                printf("\t|");
                a=1;
            } else{
                a++;
            }
        }
        printf("\n");
        if(b==3){
            printf("  -----------------------------------------------------------------------------------------------\n");
            b=1;
        }else{
            b++;
        }
    }
    printf("\n");
}

void criarVer(int sudoku[9][9], int ver[9][9]){
    int a, b, c;

    for(a = 0; a < 9; a++){
        for(b = 0; b < 9; b++){
            if (sudoku[a][b] == 0){
                ver[a][b] = 0;
            }
            else{
                ver[a][b] = 1;
            }
        }
    }
}



int main (){
    //matriz
    int sudoku[9][9] = {     {3, 2, 6, 3, 8, 0, 0, 4, 7},
                             {5, 0, 0, 2, 0, 0, 0, 0, 6},
                             {0, 0, 0, 0, 0, 7, 0, 0, 2},
                             {0, 0, 2, 5, 0, 8, 0, 9, 4},
                             {0, 0, 0, 0, 0, 0, 0, 0, 0},
                             {6, 8, 0, 9, 0, 2, 1, 0, 0},
                             {1, 0, 0, 4, 0, 0, 0, 0, 0},
                             {2, 0, 0, 0, 0, 1, 0, 0, 9},
                             {8, 6, 0, 0, 0, 9, 7, 5, 1}};

    //jogo
    int loop = 1;
    int comando,a,b,c;
    int ver[9][9];

    criarVer(sudoku, ver);

    print_matriz(sudoku);

    while (loop == 1){
        printf("\n<== Comandos ==>");
        printf("\n 1- Imprimir Tabela\n 2- Alterar Valor da Tabela\n 3- Checar Tabela\n 4- Desistir\n");
        scanf("%i", &comando);
        switch (comando)
        {
        case 1:
            print_matriz(sudoku);
            break;
        case 2:
            printf("\nCoordenada: ");
            scanf("%i %i", &a, &b);
            if(ver[a-1][b-1] != 0){
                printf("\nNao eh possivel alterar valores da tabela original!\n");
                break;
            }
            else{
                printf("\nValor: ");
                scanf("%i",&c);
                sudoku[a-1][b-1] = c;
                break;
            }
        case 3:
           //Rodar Função de checar tabela
           /*
           if (checar(sudoku)==0){
               printf("\n<=========>\nParabéns! Voce Terminou.");
           } else if(checar(sudoku)==1){
               printf("\n <=========>\nTem algo errado.");
           }
           */
            break;
        case 4:
            printf("\n\t ff" );
            return 0;
            break;

        default:
            printf("Valor Invalido");
            break;
        }

    }


    return 0;
}
