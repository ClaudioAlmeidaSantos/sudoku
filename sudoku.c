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

int main (){
    //matriz
    int sudokuFacil[9][9] = {{0, 0, 0, 0, 0, 0, 0, 0, 0},
                             {0, 0, 0, 0, 0, 0, 0, 0, 0},
                             {0, 0, 0, 0, 0, 0, 0, 0, 0},
                             {0, 0, 0, 0, 0, 0, 0, 0, 0},
                             {0, 0, 0, 0, 0, 0, 0, 0, 0},
                             {0, 0, 0, 0, 0, 0, 0, 0, 0},
                             {0, 0, 0, 0, 0, 0, 0, 0, 0},
                             {0, 0, 0, 0, 0, 0, 0, 0, 0},
                             {0, 0, 0, 0, 0, 0, 0, 0, 0}};
    
    int sudokuMedio[9][9] = {{0, 0, 0, 0, 0, 0, 0, 0, 0},
                             {0, 0, 0, 0, 0, 0, 0, 0, 0},
                             {0, 0, 0, 0, 0, 0, 0, 0, 0},
                             {0, 0, 0, 0, 0, 0, 0, 0, 0},
                             {0, 0, 0, 0, 0, 0, 0, 0, 0},
                             {0, 0, 0, 0, 0, 0, 0, 0, 0},
                             {0, 0, 0, 0, 0, 0, 0, 0, 0},
                             {0, 0, 0, 0, 0, 0, 0, 0, 0},
                             {0, 0, 0, 0, 0, 0, 0, 0, 0}};
    
    int sudokuDificil[9][9] = {{0, 0, 0, 0, 0, 0, 0, 0, 0},
                             {0, 0, 0, 0, 0, 0, 0, 0, 0},
                             {0, 0, 0, 0, 0, 0, 0, 0, 0},
                             {0, 0, 0, 0, 0, 0, 0, 0, 0},
                             {0, 0, 0, 0, 0, 0, 0, 0, 0},
                             {0, 0, 0, 0, 0, 0, 0, 0, 0},
                             {0, 0, 0, 0, 0, 0, 0, 0, 0},
                             {0, 0, 0, 0, 0, 0, 0, 0, 0},
                             {0, 0, 0, 0, 0, 0, 0, 0, 0}};


    int sudoku[9][9];
    int dificuldade;
    printf("Nivel do jogo: 1- Facil, 2-Media, 3- Dificil");
    scanf("%i,&dificuldade")
    switch (dificuldade)
    {
    case 1:
        sudoku=sudokuFacil;
        break;
    case 2:
        sudoku=sudokuMedio;
        break;
    case 3:
        sudoku=sudokuDificil;
        break;
    
    default:
        printf(" Valor Invalido");
        break;
    }


    

    //jogo
    int loop = 1;
    int comando,a,b,c;
    while (loop == 1){
        print_matriz(sudoku);
        printf("coordenada para ser alterada: "); scanf("%i % i",&a,&b);
        printf("Valor: "); scanf("%i",&c);
        
        
        
    }
    
   
    return 0;
}
