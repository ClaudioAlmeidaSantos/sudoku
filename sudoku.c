#include <stdio.h>

void print_matriz(int matriz[9][9]){
    int i,j,a=1,b=1;
    for (i=0;i<9;i++){
        for(j=0;j<9;j++){
            printf("(%i)",matriz[i][j]);
            if (a==3){
                printf("|");
                a=1;
            } else{
                a++;
            }
        }
        printf("\n");
        if(b==3){
            printf("------------------------------\n");
            b=1;
        }else{
            b++;
        }
    }
    printf("\n");
}

int resultado(int matriz[9][9]){
    int resultado=1;
    int i,j,k;
    int teste;
    //checar linhas
    for (i=0;i<9;i++){
        for(j=0;j<9;j++){
           for (k=0;k<9;k++){
               if( matriz[i][j]=matriz[i][k] && j!=k){
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
               if( matriz[j][i]=matriz[j][k] && i!=k){
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
    int sudoku[9][9] = {     {0, 0, 5, 3, 0, 0, 0, 0, 0},
                             {8, 0, 0, 0, 0, 0, 0, 2, 0},
                             {0, 7, 0, 0, 1, 0, 5, 0, 0},
                             {4, 0, 0, 0, 0, 5, 3, 0, 0},
                             {0, 1, 0, 0, 7, 0, 0, 0, 6},
                             {0, 0, 3, 2, 0, 0, 0, 8, 0},
                             {0, 6, 0, 5, 0, 0, 0, 0, 9},
                             {0, 0, 4, 0, 0, 0, 0, 3, 0},
                             {0, 0, 0, 0, 0, 9, 7, 0, 0}};
    print_matriz(sudoku);

    //jogo
    int loop = 1;
    int comando,a,b,c;
    while (loop == 1)
    {
        printf("\n\n=============================================================");
        printf("\n Comandos:\n 1- Imprimir tabela\n 2- Alterar algum valor\n 3- Checar Resultado\n");
        scanf("%i",&comando);

        switch (comando)
        {
        case 1:
            print_matriz(sudoku);
            break;
        case 2:
            printf("\n Coordenada da celula vc quer mudar?");
            scanf("%i %i", &a, &b);
            printf("\n Valor:");
            scanf("%i", &c);
            sudoku[a][b]=c;
            break;
        case 3:
            if(resultado(sudoku)==1){
                printf("\nParabens! Vc terminou.\t:)");
            } else {
                printf("\nAinda nao acabou...\n");
            }
            break;
        default:
        printf("Comando Invalido!");
            break;
        }

    }
    
   
    return 0;
}
 