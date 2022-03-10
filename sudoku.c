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

int validacao(int a, int b, int matriz[9][9]){
    int resposta;
    a= a-1;
    b=b-1;
    if(matriz[a][b]==0){
        resposta = 1; // ok
        return resposta;
    } else{
        resposta=0;
        return resposta;
    }

}

int checar(int matriz[9][9]){
    int resultado=1;
    int i,j,k;
    //checar linhas
    for (i=0;i<9;i++){
        for(j=0;j<9;j++){
           for (k=0;k<9;k++){
               if( matriz[i][j]==matriz[i][k] && j!=k){
                   resultado = 0;
                   return resultado;
               }
           }  
        }
    }

    //checar coluna
    for (i=0;i<9;i++){
        for(j=0;j<9;j++){
           for (k=0;k<9;k++){
               if( matriz[j][i]==matriz[j][k] && i!=k){
                   resultado = 0;
                   return resultado;
               }
           }
            
        }
    }
    //checar quadrado
    return resultado;
}

int main (){
    //matriz
    int base[9][9] = {       {3, 2, 6, 3, 8, 0, 0, 4, 7},
                             {5, 0, 0, 2, 0, 0, 0, 0, 6},
                             {0, 0, 0, 0, 0, 7, 0, 0, 2},
                             {0, 0, 2, 5, 0, 8, 0, 9, 4},
                             {0, 0, 0, 0, 0, 0, 0, 0, 0},
                             {6, 8, 0, 9, 0, 2, 1, 0, 0},
                             {1, 0, 0, 4, 0, 0, 0, 0, 0},
                             {2, 0, 0, 0, 0, 1, 0, 0, 9},
                             {8, 6, 0, 0, 0, 9, 7, 5, 1}};


    // recebendo de uma matriz base                       
    int sudoku[9][9];
    
    //igualando as matrizes
    int i,j;
    for (i=0;i<9;i++){
        for(j=0;j<9;j++){
            sudoku[i][j] = base[i][j];
           }
        }

    //jogo
    int loop = 1;
    int comando,a,b,c;

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
            if( validacao(a,b,base)==1){
                printf("\nValor: ");
                scanf("%i",&c);
                sudoku[a-1][b-1] = c;
                break;
            } else{
                printf("\nValor Invalido, essa coordenada não pode ser alterada");
                break;
            }
            
        
        case 3:
           //Rodar Função de checar tabela
           if (checar(sudoku)==1){
               printf("\n<=========>\nParabéns! Voce Terminou.");
           } else if(checar(sudoku)==2){
               printf("\n <=========>\nTem algo errado.");
           }
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
