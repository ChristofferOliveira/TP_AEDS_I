#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void sit_game(char matriz[][6],int n)//Função para imprimir a estado atual da Matriz.
{
    int i,j;
    printf("\tSituacao do jogo\n");
    for(i=0;i<6;i++)
    {
        for(j=0;j<6;j++)
        {
            printf("%c ",matriz[i][j]);
        }
        printf("\n");
    }
}
void reset_game(char matriz[0][6],int n,char crt1,char crt2)//Função para tirar o historico do jogo na matriz.
{
    int i,j;
    for(i=0;i<6;i++)
    {
        for(j=0;j<6;j++)
        {
            if((matriz[i][j]==crt1) || (matriz[i][j]==crt2))
            {
                matriz[i][j]=' ';
            }
        }
    }
}
int main(){
    int opc,vezjogador=1,coo1,coo2,contdrod=0,vencedor=0,ctrljogadacpu=0;
    char player1[30],player2[30],crt1=' ',crt2=' ';
    char matriz[6][6]={' ','1',' ','2',' ','3','1',' ','|',' ','|',' ',' ','-','-','-','-','-','2',' ','|',' ','|',' ',' ','-','-','-','-','-','3',' ','|',' ','|',' '};
    do{//Menu para escolher o tipo de jogo.
        printf("\tTipo de Jogo\n1-Para jogador 1 vs computador\n2-Para jogador 1 vs jogador 2\n3-Encerrar\n");//menu
        scanf("%d",&opc);
        switch(opc)//Pegando opção digitada e fazendo a ação necessaria.
        {
        case 1:
            system("clear");
            printf("\tJOGADOR VS COMPUTADOR\nDigite o nome com que deseja jogar\n");
            getchar();
            scanf("%s",player1);
            do//Validando o caracter escolhido pelo jogador 1
            {
                printf("Digite o caracter que deseja utilizar(exceto 'espaco''|''-' e '#')\n");
                getchar();
                scanf("%c",&crt1);
                if((crt1==' ') || (crt1=='|') || (crt1=='-') || (crt1=='#'))//Mensagem de rro para o usuário.
                {
                    system("clear");
                    printf("Caracter invalido,tente novamente\n");
                }
            }while((crt1==' ') || (crt1=='|') || (crt1=='-') || (crt1=='#'));//condição para a validação do caracter
            system("clear");
            printf("\tJogo iniciado\n");
            while(contdrod<=9&&vencedor==0)//Condição para que o jogo para quando houver jogador ou todas as 9 jogadas serem feitas.
            {
                system("clear");
                sit_game(matriz,6);
                do//validando entrada do caracter no jogo
                {
                    do//validando coordenadas
                    {
                        printf("Sua vez %s\ndigite as coordenadas que deseja marcar(linha coluna) e que nao esteja marcada\n",player1);
                        scanf("%d",&coo1);
                        scanf("%d",&coo2);
                    }while((coo1>3) || (coo1<0) || (coo2>3) ||(coo2<0));//condiçao para não ter jogadas fora das coordenadas.
                    if(coo1==3)//Deixando o caracter digitado de acordo com a matriz[6][6].
                    {
                        coo1=5;
                    }
                    if(coo1==2)
                    {
                        coo1=3;
                    }
                    if(coo2==3)
                    {
                        coo2=5;
                    }
                    if(coo2==2)
                    {
                        coo2=3;
                    }
                }while(matriz[coo1][coo2]=='#'||matriz[coo1][coo2]==crt1);//Condição para não jogar onde há caracters.
                matriz[coo1][coo2]=crt1;//colocando  o caracer no jogo.
                contdrod++;
                if((matriz[1][1]==crt1&&matriz[1][1]==matriz[3][1]&&matriz[1][1]==matriz[5][1])
                    ||(matriz[1][1]==crt1&&matriz[1][1]==matriz[3][3]&&matriz[1][1]==matriz[5][5])
                    ||(matriz[1][1]==crt1&&matriz[1][1]==matriz[1][3]&&matriz[1][1]==matriz[1][5])
                    ||(matriz[1][3]==crt1&&matriz[1][3]==matriz[3][3]&&matriz[3][3]==matriz[5][3])
                    ||(matriz[1][5]==crt1&&matriz[1][5]==matriz[3][5]&&matriz[3][5]==matriz[5][5])
                    ||(matriz[1][5]==crt1&&matriz[1][5]==matriz[3][3]&&matriz[3][3]==matriz[5][1])
                    ||(matriz[3][1]==crt1&&matriz[3][1]==matriz[3][3]&&matriz[3][3]==matriz[3][5])
                    ||(matriz[5][1]==crt1&&matriz[5][1]==matriz[5][3]&&matriz[5][3]==matriz[5][5]))//verificando se o jogador 1 venceu.
                    {
                        system("clear");
                        printf("\t!!!!!JOGADOR %s VENCEUUU!!!!!\n",player1);
                        sit_game(matriz,6);
                        vencedor=1;
                        getch();
                    }
                if(contdrod<9)
                {
                    if(vencedor==0)
                    {
                        if(matriz[1][1]=='#'&&matriz[1][3]=='#'&&matriz[1][5]!=crt1)//Verificando se o computador tem chance de ganhar.
                        {
                            matriz[1][5]='#';
                            ctrljogadacpu++;
                        }
                        else if(matriz[1][1]=='#'&&matriz[1][5]=='#'&&matriz[1][3]!=crt1)//Verificando se o computador tem chance de ganhar.
                        {
                            matriz[1][3]='#';
                            ctrljogadacpu++;
                        }
                        else if(matriz[1][3]=='#'&&matriz[1][5]=='#'&&matriz[1][1]!=crt1)//Verificando se o computador tem chance de ganhar.
                        {
                            matriz[1][1]='#';
                            ctrljogadacpu++;
                        }
                        else if(matriz[1][1]=='#'&&matriz[3][1]=='#'&&matriz[5][1]!=crt1)//Verificando se o computador tem chance de ganhar.
                        {
                            matriz[5][1]='#';
                            ctrljogadacpu++;
                        }
                        else if(matriz[1][1]=='#'&&matriz[5][1]=='#'&&matriz[3][1]!=crt1)//Verificando se o computador tem chance de ganhar.
                        {
                            matriz[3][1]='#';
                            ctrljogadacpu++;
                        }
                        else if(matriz[3][1]=='#'&&matriz[5][1]=='#'&&matriz[1][1]!=crt1)//Verificando se o computador tem chance de ganhar.
                        {
                            matriz[1][1]='#';
                            ctrljogadacpu++;
                        }
                        if(matriz[1][1]=='#'&&matriz[3][3]=='#'&&matriz[5][5]!=crt1)//Verificando se o computador tem chance de ganhar.
                        {
                            matriz[5][5]='#';
                            ctrljogadacpu++;
                        }
                        else if(matriz[1][1]=='#'&&matriz[5][5]=='#'&&matriz[3][3]!=crt1)//Verificando se o computador tem chance de ganhar.
                        {
                            matriz[3][3]='#';
                            ctrljogadacpu++;
                        }
                        else if(matriz[3][3]=='#'&&matriz[5][5]=='#'&&matriz[1][1]!=crt1)//Verificando se o computador tem chance de ganhar.
                        {
                            matriz[1][1]='#';
                            ctrljogadacpu++;
                        }
                        if(matriz[1][3]=='#'&&matriz[3][3]=='#'&&matriz[5][3]!=crt1)//Verificando se o computador tem chance de ganhar.
                        {
                            matriz[5][3]='#';
                            ctrljogadacpu++;
                        }
                        else if(matriz[1][3]=='#'&&matriz[5][3]=='#'&&matriz[3][3]!=crt1)//Verificando se o computador tem chance de ganhar.
                        {
                            matriz[3][3]='#';
                            ctrljogadacpu++;
                        }
                        else if(matriz[3][3]=='#'&&matriz[5][3]=='#'&&matriz[1][3]!=crt1)//Verificando se o computador tem chance de ganhar.
                        {
                            matriz[1][3]='#';
                            ctrljogadacpu++;
                        }
                        else if(matriz[1][5]=='#'&&matriz[3][5]=='#'&&matriz[5][5]!=crt1)//Verificando se o computador tem chance de ganhar.
                        {
                            matriz[5][5]='#';
                            ctrljogadacpu++;
                        }
                        else if(matriz[1][5]=='#'&&matriz[5][5]=='#'&&matriz[3][5]!=crt1)//Verificando se o computador tem chance de ganhar.
                        {
                            matriz[3][5]='#';
                            ctrljogadacpu++;
                        }
                        else if(matriz[3][5]=='#'&&matriz[5][5]=='#'&&matriz[1][5]!=crt1)//Verificando se o computador tem chance de ganhar.
                        {
                            matriz[1][5]='#';
                            ctrljogadacpu++;
                        }
                        else if(matriz[1][5]=='#'&&matriz[3][3]=='#'&&matriz[5][1]!=crt1)//Verificando se o computador tem chance de ganhar.
                        {
                            matriz[5][1]='#';
                            ctrljogadacpu++;
                        }
                        else if(matriz[1][5]=='#'&&matriz[5][1]=='#'&&matriz[3][3]!=crt1)//Verificando se o computador tem chance de ganhar.
                        {
                            matriz[3][3]='#';
                            ctrljogadacpu++;
                        }
                        else if(matriz[3][3]=='#'&&matriz[5][1]=='#'&&matriz[1][5]!=crt1)//Verificando se o computador tem chance de ganhar.
                        {
                            matriz[1][5]='#';
                            ctrljogadacpu++;
                        }
                        else if(matriz[3][1]=='#'&&matriz[3][3]=='#'&&matriz[3][5]!=crt1)//Verificando se o computador tem chance de ganhar.
                        {
                            matriz[3][5]='#';
                            ctrljogadacpu++;
                        }
                        else if(matriz[3][1]=='#'&&matriz[3][5]=='#'&&matriz[3][3]!=crt1)//Verificando se o computador tem chance de ganhar.
                        {
                            matriz[3][3]='#';
                            ctrljogadacpu++;
                        }
                        else if(matriz[3][3]=='#'&&matriz[3][5]=='#'&&matriz[3][1]!=crt1)//Verificando se o computador tem chance de ganhar.
                        {
                            matriz[3][1]='#';
                            ctrljogadacpu++;
                        }
                        else if(matriz[5][1]=='#'&&matriz[5][3]=='#'&&matriz[5][5]!=crt1)//Verificando se o computador tem chance de ganhar.
                        {
                            matriz[5][5]='#';
                            ctrljogadacpu++;
                        }
                        else if(matriz[5][1]=='#'&&matriz[5][5]=='#'&&matriz[5][3]!=crt1)//Verificando se o computador tem chance de ganhar.
                        {
                            matriz[5][3]='#';
                            ctrljogadacpu++;
                        }
                        else if(matriz[5][3]=='#' && matriz[5][5]=='#' && matriz[5][1]!=crt1)//Verificando se o computador tem chance de ganhar.
                        {
                            matriz[5][1]='#';
                            ctrljogadacpu++;
                        }
                        if(ctrljogadacpu==0)//condição para que o computador não faça duas jogadas
                        {
                            while(ctrljogadacpu!=1)
                            {
                                if(matriz[1][1]==crt1 && matriz[1][3]==crt1 && matriz[1][5]!='#')//Verificando se o jogador tem chance de ganhar na proxima jogada e marcando no lugar que ele tem chance de ganhar.
                                {
                                    matriz[1][5]='#';
                                    ctrljogadacpu++;
                                    break;
                                }
                                if(matriz[1][1]==crt1 && matriz[1][5]==crt1 && matriz[1][3]!='#')//Verificando se o jogador tem chance de ganhar na proxima jogada e marcando no lugar que ele tem chance de ganhar.
                                {
                                    matriz[1][3]='#';
                                    ctrljogadacpu++;
                                    break;
                                }
                                if(matriz[1][3]==crt1 && matriz[1][5]==crt1 && matriz[1][1]!='#')//Verificando se o jogador tem chance de ganhar na proxima jogada e marcando no lugar que ele tem chance de ganhar.
                                {
                                    matriz[1][1]='#';
                                    ctrljogadacpu++;
                                    break;
                                }
                                if(matriz[1][1]==crt1 && matriz[3][1]==crt1 && matriz[5][1]!='#')//Verificando se o jogador tem chance de ganhar na proxima jogada e marcando no lugar que ele tem chance de ganhar.
                                {
                                    matriz[5][1]='#';
                                    ctrljogadacpu++;
                                    break;
                                }
                                if(matriz[1][1]==crt1 && matriz[5][1]==crt1 && matriz[3][1]!='#')//Verificando se o jogador tem chance de ganhar na proxima jogada e marcando no lugar que ele tem chance de ganhar.
                                {
                                    matriz[3][1]='#';
                                    ctrljogadacpu++;
                                    break;
                                }
                                if(matriz[3][1]==crt1 && matriz[5][1]==crt1 && matriz[1][1]!='#')//Verificando se o jogador tem chance de ganhar na proxima jogada e marcando no lugar que ele tem chance de ganhar.
                                {
                                    matriz[1][1]='#';
                                    ctrljogadacpu++;
                                    break;
                                }
                                if(matriz[1][1]==crt1 && matriz[3][3]==crt1 && matriz[5][5]!='#')//Verificando se o jogador tem chance de ganhar na proxima jogada e marcando no lugar que ele tem chance de ganhar.
                                {
                                    matriz[5][5]='#';
                                    ctrljogadacpu++;
                                    break;
                                }
                                if(matriz[1][1]==crt1 && matriz[5][5]==crt1 && matriz[3][3]!='#')//Verificando se o jogador tem chance de ganhar na proxima jogada e marcando no lugar que ele tem chance de ganhar.
                                {
                                    matriz[3][3]='#';
                                    ctrljogadacpu++;
                                    break;
                                }
                                if(matriz[3][3]==crt1 && matriz[5][5]==crt1 && matriz[1][1]!='#')//Verificando se o jogador tem chance de ganhar na proxima jogada e marcando no lugar que ele tem chance de ganhar.
                                {
                                    matriz[1][1]='#';
                                    ctrljogadacpu++;
                                    break;
                                }
                                if(matriz[1][3]==crt1 && matriz[3][3]==crt1 && matriz[5][3]!='#')//Verificando se o jogador tem chance de ganhar na proxima jogada e marcando no lugar que ele tem chance de ganhar.
                                {
                                    matriz[5][3]='#';
                                    ctrljogadacpu++;
                                    break;
                                }
                                if(matriz[1][3]==crt1 && matriz[5][3]==crt1 && matriz[3][3]!='#')//Verificando se o jogador tem chance de ganhar na proxima jogada e marcando no lugar que ele tem chance de ganhar.
                                {
                                    matriz[3][3]='#';
                                    ctrljogadacpu++;
                                    break;
                                }
                                if(matriz[3][3]==crt1 && matriz[5][3]==crt1 && matriz[1][3]!='#')//Verificando se o jogador tem chance de ganhar na proxima jogada e marcando no lugar que ele tem chance de ganhar.
                                {
                                    matriz[1][3]='#';
                                    ctrljogadacpu++;
                                    break;
                                }
                                if(matriz[1][5]==crt1 && matriz[3][5]==crt1 && matriz[5][5]!='#')//Verificando se o jogador tem chance de ganhar na proxima jogada e marcando no lugar que ele tem chance de ganhar.
                                {
                                    matriz[5][5]='#';
                                    ctrljogadacpu++;
                                    break;
                                }
                                if(matriz[1][5]==crt1 && matriz[5][5]==crt1 && matriz[3][5]!='#')//Verificando se o jogador tem chance de ganhar na proxima jogada e marcando no lugar que ele tem chance de ganhar.
                                {
                                    matriz[3][5]='#';
                                    ctrljogadacpu++;
                                    break;
                                }
                                if(matriz[3][5]==crt1 && matriz[5][5]==crt1 && matriz[1][5]!='#')//Verificando se o jogador tem chance de ganhar na proxima jogada e marcando no lugar que ele tem chance de ganhar.
                                {
                                    matriz[1][5]='#';
                                    ctrljogadacpu++;
                                    break;
                                }
                                if(matriz[1][5]==crt1 && matriz[3][3]==crt1 && matriz[5][1]!='#')//Verificando se o jogador tem chance de ganhar na proxima jogada e marcando no lugar que ele tem chance de ganhar.
                                {
                                    matriz[5][1]='#';
                                    ctrljogadacpu++;
                                    break;
                                }
                                if(matriz[1][5]==crt1 && matriz[5][1]==crt1 && matriz[3][3]!='#')//Verificando se o jogador tem chance de ganhar na proxima jogada e marcando no lugar que ele tem chance de ganhar.
                                {
                                    matriz[3][3]='#';
                                    ctrljogadacpu++;
                                    break;
                                }
                                if(matriz[3][3]==crt1 && matriz[5][1]==crt1 && matriz[1][5]!='#')//Verificando se o jogador tem chance de ganhar na proxima jogada e marcando no lugar que ele tem chance de ganhar.
                                {
                                    matriz[1][5]='#';
                                    ctrljogadacpu++;
                                    break;
                                }
                                if(matriz[3][1]==crt1 && matriz[3][3]==crt1 && matriz[3][5]!='#')//Verificando se o jogador tem chance de ganhar na proxima jogada e marcando no lugar que ele tem chance de ganhar.
                                {
                                    matriz[3][5]='#';
                                    ctrljogadacpu++;
                                    break;
                                }
                                if(matriz[3][1]==crt1 && matriz[3][5]==crt1 && matriz[3][3]!='#')//Verificando se o jogador tem chance de ganhar na proxima jogada e marcando no lugar que ele tem chance de ganhar.
                                {
                                    matriz[3][3]='#';
                                    ctrljogadacpu++;
                                    break;
                                }
                                if(matriz[3][3]==crt1 && matriz[3][5]==crt1 && matriz[3][1]!='#')//Verificando se o jogador tem chance de ganhar na proxima jogada e marcando no lugar que ele tem chance de ganhar.
                                {
                                    matriz[3][1]='#';
                                    ctrljogadacpu++;
                                    break;
                                }
                                if(matriz[5][1]==crt1 && matriz[5][3]==crt1 && matriz[5][5]!='#')//Verificando se o jogador tem chance de ganhar na proxima jogada e marcando no lugar que ele tem chance de ganhar.
                                {
                                    matriz[5][5]='#';
                                    ctrljogadacpu++;
                                    break;
                                }
                                if(matriz[5][1]==crt1 && matriz[5][5]==crt1 && matriz[5][3]!='#')//Verificando se o jogador tem chance de ganhar na proxima jogada e marcando no lugar que ele tem chance de ganhar.
                                {
                                    matriz[5][3]='#';
                                    ctrljogadacpu++;
                                    break;
                                }
                                if(matriz[5][3]==crt1 && matriz[5][5]==crt1 && matriz[5][1]!='#')//Verificando se o jogador tem chance de ganhar na proxima jogada e marcando no lugar que ele tem chance de ganhar.
                                {
                                    matriz[5][1]='#';
                                    ctrljogadacpu++;
                                    break;
                                }
                                break;
                            }
                        }
                        if(ctrljogadacpu==0)//condição para que o computador não faça duas jogadas.
                        {
                            if(matriz[3][3]!=crt1 && matriz[3][3]!='#')//Para bloquar algumas jogadas estratégicas.
                            {
                                matriz[3][3]='#';
                            }
                            else if((matriz[1][1]==crt1 && matriz[5][5]==crt1) || (matriz[1][5]==crt1 && matriz[5][1]==crt1) && matriz[3][1]!='#')//Para bloquar algumas jogadas estratégicas.
                            {
                                matriz[3][1]='#';
                            }
                            else if(matriz[5][3]==crt1 && matriz[3][1]==crt1 && matriz[5][1]!='#')//Para bloquar algumas jogadas estratégicas.
                            {
                                matriz[5][1]='#';
                            }
                            else if(matriz[1][3]==crt1 && matriz[3][1]==crt1 && matriz[1][1]!='#')//Para bloquar algumas jogadas estratégicas.
                            {
                                matriz[1][1]='#';
                            }
                            else if(matriz[1][3]==crt1 && matriz[3][5]==crt1 && matriz[1][5]!='#')//Para bloquar algumas jogadas estratégicas.
                            {
                                matriz[1][5]='#';
                            }
                            else if(matriz[3][5]==crt1 && matriz[5][3]==crt1 && matriz[5][5]!='#')//Para bloquar algumas jogadas estratégicas.
                            {
                                matriz[5][5]='#';
                            }
                            else if(matriz[1][5]!=crt1 && matriz[1][5]!='#')//Para bloquar algumas jogadas estratégicas.
                            {
                                matriz[1][5]='#';
                            }
                            else if(matriz[3][5]!=crt1 && matriz[3][5]!='#' && matriz[3][3]!='#')//Para bloquar algumas jogadas estratégicas.
                            {
                                matriz[3][5]='#';
                            }
                            else if(matriz[5][1]!=crt1 && matriz[5][1]!='#')//Para bloquar algumas jogadas estratégicas.
                            {
                                matriz[5][1]='#';
                            }
                            else if(matriz[5][5]!=crt1 && matriz[5][5]!='#')//Para bloquar algumas jogadas estratégicas.
                            {
                                matriz[5][5]='#';
                            }
                            else if(matriz[5][3]!=crt1 && matriz[5][3]!='#')//Para bloquar algumas jogadas estratégicas.
                            {
                                matriz[5][3]='#';
                            }
                            else if(matriz[1][1]!=crt1 && matriz[1][1]!='#')//Para bloquar algumas jogadas estratégicas.
                            {
                                matriz[1][1]='#';
                            }
                        }
                        if((matriz[1][1]=='#' && matriz[1][1]==matriz[3][1] && matriz[1][1]==matriz[5][1])
                        || (matriz[1][1]=='#' && matriz[1][1]==matriz[3][3] && matriz[1][1]==matriz[5][5])
                        || (matriz[1][1]=='#' && matriz[1][1]==matriz[1][3] && matriz[1][1]==matriz[1][5])
                        || (matriz[1][3]=='#' && matriz[1][3]==matriz[3][3] && matriz[3][3]==matriz[5][3])
                        || (matriz[1][5]=='#' && matriz[1][5]==matriz[3][5] && matriz[3][5]==matriz[5][5])
                        || (matriz[1][5]=='#' && matriz[1][5]==matriz[3][3] && matriz[3][3]==matriz[5][1])
                        || (matriz[3][1]=='#' && matriz[3][1]==matriz[3][3] && matriz[3][3]==matriz[3][5])
                        || (matriz[5][1]=='#' && matriz[5][1]==matriz[5][3] && matriz[5][3]==matriz[5][5]))//Condição que verifica se o computador venceu.
                        {
                            system("clear");
                            printf("\t!!!!!COMPUTADOR VENCEUUU!!!!!\n");
                            sit_game(matriz,6);
                            vencedor=1;
                            getch();
                        }
                        ctrljogadacpu=0;
                        contdrod++;
                    }
                }
                if(vencedor==0 && contdrod==9)//Exibindo "VELHA" caso tenha sido feita as 9 jogadas.
                {
                    system("clear");
                    sit_game(matriz,6);
                    printf("\t!!!!!DEU VELHA!!!!!\n");
                    contdrod++;
                    getch();
                }
            }
            //comandos para resetar o programa para iniciar uma nova partida.
            contdrod=0;
            vezjogador=1;
            reset_game(matriz,6,crt1,'#');
            vencedor=0;

            system("clear");
            break;
        case 2:
            crt1=' ';//Deixando o caracter como vazio para que o jogador 1 utilize-o para jogar em outro modo.
            system("clear");
            printf("\tJOGADOR 1 VS JOGADOR 2\nJogador 1 digite o nome com que deseja jogar\n");
            getchar();
            scanf("%s",player1);
            do//Validando entrada do caracter do jogador 1.
            {
                printf("Digite o caracter que deseja utilizar(exceto 'espaço''|' e '-')\n");
                getchar();
                scanf("%c",&crt1);
                if(crt1==' ' || crt1=='|' || crt1=='-')
                {
                    system("clear");
                    printf("Caracter invalido,tente novamente");
                }
            }while((crt1==' ') || (crt1=='|') || (crt1=='-'));//Condição para validar a entrada do caracter do jogador 1.
            do{//validando entrada do nome do jogador 2
                printf("jogador 2 digite o nome com que deseja jogar(Diferente do jogador %s)\n",player1);
                getchar();
                scanf("%s",player2);
            }while(strcmp(player1,player2)==0);//Condição para que o jogador 2 não fique com o mesmo nome do jogador 1.
            do{//validando entrada do caracter do jogador 2
                printf("Digite o caracter que deseja utilizar(exceto 'espaco','|','-' e caracter ja utilizado %c)\n",crt1);
                getchar();
                scanf("%c",&crt2);
                if((crt2==' ') || (crt2=='|') || (crt2=='-') || (crt2==crt1))
                {
                    system("clear");
                    printf("Caracter invalido,tente novamente\n");
                }
            }while((crt2==' ') || (crt2=='|') || (crt2=='-') || (crt2==crt1));//condição para que o jogador 2 não tenha o mesmo caracter do jogador 1 e nem os caracters usados para montar a matriz.
            system("clear");
            printf("\tJogo iniciado\n");
            while(contdrod<=9 && vencedor==0)//condição para que o jogo pare quando houver vencedor ou completar o número de jogadas.
            {
                system("clear");
                sit_game(matriz,6);
                if(vezjogador==1)//condição para alternar a vez dos jogadores.
                {
                    do//validando entrada do caracter no jogo
                    {
                        do//validando coordenadas
                        {
                            printf("Vez do %s jogar\ndigite as coordenadas que deseja marcar(linha coluna) e que nao esteja marcada\n",player1);
                            scanf("%d",&coo1);
                            scanf("%d",&coo2);
                        }while((coo1>3) || (coo1<0) || (coo2>3 ) || (coo2<0));
                        if(coo1==3)//Deixando o caracter digitado de acordo com a matriz[6][6].
                        {
                            coo1=5;
                        }
                        if(coo1==2)//Deixando o caracter digitado de acordo com a matriz[6][6].
                        {
                            coo1=3;
                        }
                        if(coo2==3)//Deixando o caracter digitado de acordo com a matriz[6][6].
                        {
                            coo2=5;
                        }
                        if(coo2==2)//Deixando o caracter digitado de acordo com a matriz[6][6].
                        {
                            coo2=3;
                        }
                    }while(matriz[coo1][coo2]==crt2 || matriz[coo1][coo2]==crt1);//condição para não fazer jogada no lugar que ja tenha sido preenchido.
                    contdrod++;
                    vezjogador=2;//comando para alternar entre a vez de cada jogador jogar.
                    matriz[coo1][coo2]=crt1;//colocando  o caracer no jogo
                    if((matriz[1][1]==crt1 && matriz[1][1]==matriz[3][1] && matriz[1][1]==matriz[5][1])
                    || (matriz[1][1]==crt1 && matriz[1][1]==matriz[3][3] && matriz[1][1]==matriz[5][5])
                    || (matriz[1][1]==crt1 && matriz[1][1]==matriz[1][3] && matriz[1][1]==matriz[1][5])
                    || (matriz[1][3]==crt1 && matriz[1][3]==matriz[3][3] && matriz[3][3]==matriz[5][3])
                    || (matriz[1][5]==crt1 && matriz[1][5]==matriz[3][5] && matriz[3][5]==matriz[5][5])
                    || (matriz[1][5]==crt1 && matriz[1][5]==matriz[3][3] && matriz[3][3]==matriz[5][1])
                    || (matriz[3][1]==crt1 && matriz[3][1]==matriz[3][3] && matriz[3][3]==matriz[3][5])
                    || (matriz[5][1]==crt1 && matriz[5][1]==matriz[5][3] && matriz[5][3]==matriz[5][5]))//verificando se o jogador 1 ganhou.
                    {
                        system("clear");
                        printf("\t!!!!!JOGADOR %s VENCEUUU!!!!!\n",player1);
                        sit_game(matriz,6);
                        vencedor=1;
                        getch();
                    }
                }
                else
                {
                    if((contdrod<9 && vencedor==0))//condição para que jogador 2 não faça jogadas caso há um vencedor ou tenha dado velha.
                    {
                        do//validando entrada do caracter no jogo
                        {
                            do//validadando as coordenadas do usuário 2.
                            {
                                printf("Vez do %s jogar\ndigite as coordenadas que deseja marcar(linha coluna) e que nao esteja marcada\n",player2);
                                scanf("%d",&coo1);
                                scanf("%d",&coo2);
                            }while((coo1>3) || (coo1<0) || (coo2>3) || (coo2<0));//condição para que as coordenadas digitadas seja válidas
                            if(coo1==3)//Deixando o caracter digitado de acordo com a matriz[6][6].
                            {
                                coo1=5;
                            }
                            if(coo1==2)//Deixando o caracter digitado de acordo com a matriz[6][6].
                            {
                                coo1=3;
                            }
                            if(coo2==3)//Deixando o caracter digitado de acordo com a matriz[6][6].
                            {
                                coo2=5;
                            }
                            if(coo2==2)//Deixando o caracter digitado de acordo com a matriz[6][6].
                            {
                                coo2=3;
                            }
                        }while(matriz[coo1][coo2]==crt1 || matriz[coo1][coo2]==crt2);//condição para que o jogador não marque onde já está marcado.
                        contdrod++;
                        vezjogador=1;//comando para alternar entre a vez de cada jogador jogar.
                        matriz[coo1][coo2]=crt2;//colocando  o caracer no jogo
                        if((matriz[1][1]==crt2 && matriz[1][1]==matriz[3][1] && matriz[1][1]==matriz[5][1])
                        || (matriz[1][1]==crt2 && matriz[1][1]==matriz[3][3] && matriz[1][1]==matriz[5][5])
                        || (matriz[1][1]==crt2 && matriz[1][1]==matriz[1][3] && matriz[1][1]==matriz[1][5])
                        || (matriz[1][3]==crt2 && matriz[1][3]==matriz[3][3] && matriz[3][3]==matriz[5][3])
                        || (matriz[1][5]==crt2 && matriz[1][5]==matriz[3][5] && matriz[3][5]==matriz[5][5])
                        || (matriz[1][5]==crt2 && matriz[1][5]==matriz[3][3] && matriz[3][3]==matriz[5][1])
                        || (matriz[3][1]==crt2 && matriz[3][1]==matriz[3][3] && matriz[3][3]==matriz[3][5])
                        || (matriz[5][1]==crt2 && matriz[5][1]==matriz[5][3] && matriz[5][3]==matriz[5][5]))//Verificando se o jogador 2 ganhou.
                        {
                            system("clear");
                            printf("\t!!!!!JOGADOR %s VENCEUUU!!!!!\n",player2);
                            vencedor=1;
                            sit_game(matriz,6);
                            getch();
                        }
                    }
                    if(vencedor==0 && contdrod==9)//Exibindo "VELHA" caso tenha sido feita as 9 jogadas.
                    {
                        printf("\t!!!!!DEU VELHA!!!!!\n");
                        contdrod++;
                        getch();
                    }
                }
            }
            //comandos para resetar o jogo.
            contdrod=0;
            vezjogador=1;
            reset_game(matriz,6,crt1,crt2);
            vencedor=0;
            system("clear");
            break;
        case 3://Encerrar programa
            system("clear");
            printf("Encerrado");
            break;
        default://Mensagem de erro caso seja digitada a opção inválida.
            system("clear");
            printf("Opcao invalida tente novamente.Pressione qualquer tecla\n");
            getch();
            break;
        }
    }while(opc!=3);//Encerrar programa pela opção 3.*/
    return 0;
}

