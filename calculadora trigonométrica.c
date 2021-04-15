// Jos� Antonio Costa Neto & Gabriela La�s Pereira

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <locale.h>
#include<math.h>
#define grausPorRadiano 57.2958
#define PI 3.14159265
char a,enter;
short posX = 84, posY = 22;

void moveXY(int x, int y, char t[10])
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD position = {x,y};
    SetConsoleCursorPosition(hStdout, position);
    printf("%s", t);
}

void programa1()
{
    moveXY(1,1, "Digite um valor:");
    moveXY(1,2,"Seno:");
    moveXY(1,3,"Cosseno:");
    moveXY(1,4,"Tangente:");
    moveXY(1,5,"Secante:");
    moveXY(1,6,"Cossecante:");
    moveXY(1,7,"Cotangente:");
    moveXY(1,22,"*Utilize v�rgula para indicar casas decimais, ex: 1/2=0,5");
    moveXY(1,23,"*O valor em radianos n�o deve ser indicado em fun��o de pi.");
    moveXY(1,24,"*O sinal negativo demonstra o quadrante.");
}

void programaArcoSeno()
{
    moveXY(1,1, "Digite o valor do seno:");
    moveXY(1,2,"Arco em graus:");
    moveXY(1,3,"Arco em radianos:");
    moveXY(1,28,"*Utilize v�rgula para indicar casas decimais, ex: 1/2=0,5");
}
void programaArcoCosseno()
{
    moveXY(1,1, "Digite o valor do cosseno:");
    moveXY(1,2,"Arco em graus:");
    moveXY(1,3,"Arco em radianos:");
    moveXY(1,28,"*Utilize v�rgula para indicar casas decimais, ex: 1/2=0,5");
}
void programaArcoTangente()
{
    moveXY(1,1, "Digite o valor da tangente:");
    moveXY(1,2,"Arco em graus:");
    moveXY(1,3,"Arco em radianos:");
    moveXY(1,28,"*Utilize v�rgula para indicar casas decimais, ex: 1/2=0,5");
}



void tabelaConsultaNotaveis()
{
	moveXY(1,1, "�ngulos not�veis/Seu valor em radianos");
    moveXY(1,2,"30�/0,5236");
    moveXY(1,3,"45�/0,7854");
    moveXY(1,4,"60�/1,047197551198");
    moveXY(1,5,"90�/1,570796326797");
    moveXY(1,6,"120�/2,094395102396");
    moveXY(1,7,"135�/2,356194490196");
    moveXY(1,8,"150�/2,617993877995");
    moveXY(1,9,"180�/3,141592653594");
    moveXY(1,10,"210�/3,665191429193");
    moveXY(1,11,"225�/3,926990816993");
    moveXY(1,12,"240�/4,188790204792");
    moveXY(1,13,"270�/4,712388980391");
    moveXY(1,14,"300�/5,235987755991");
    moveXY(1,15,"315�/5,49778714379");
    moveXY(1,16,"330�/5,75958653159");
    moveXY(1,17,"360�/6,283185307189");
}
void menu()
{
	moveXY(86,22,"Fazer c�lculo em graus");
    moveXY(86,23,"Fazer c�lculo em radianos");
    moveXY(86,24,"Fazer c�lculo do arco seno");
    moveXY(86,25,"Fazer c�lculo do arco cosseno");
    moveXY(86,26,"Fazer c�lculo do arco tangente");
    moveXY(86,27,"Consultar �ngulos not�veis");
    moveXY(86,28,"Sair");
}

int main()
{
	double valor;
    int p;
	setlocale(LC_ALL, "Portuguese");
    system("color 3F");
    moveXY(54, 12, "Bem vindo!");
	moveXY(20, 14, "Esse programa calcula as raz�es trigonom�tricas seno, cosseno, tangente, secante,");
	moveXY(20, 15, "cossecante e cotangente de qualquer valor inserido em graus ou radianos, al�m de ");
	moveXY(20, 16, "arcos seno, arcos cosseno e arcos tangente.");
    moveXY(75,30, "");
	system("pause");
	system("cls");
    moveXY(84, 22, "->");
    do
    {


        menu();
        moveXY(posX, posY, "->");
        a = toupper(getch());

        switch(a)
        {
            case 'H':
                if (posY > 22)
                {
                    moveXY(84,posY, "  ");
                    posY-=1;
                    moveXY(84,posY, "->");
                }
            break;

            case 'P':
                if (posY < 28)
                {
                    moveXY(84,posY, "  ");
                    posY+=1;
                    moveXY(84,posY, "->");
                }
            break;

            case 0:
	        	a=getch();
	        	if(a==59) //tecla F1
	        	{
					infos();
					moveXY(38,10,"");
					system("pause");
				}
				break;

            case 13:  //pressionou enter
                if (posY == 22) //c�lculo em graus
                {
                	system("cls");
                	menu();
                	programa1();
                    moveXY(18,1, "");
                    scanf("%lf",&valor);
                    if (valor>360)
                    {
                        p=valor/360;
                        valor=valor-(360*abs(p));
                    }
                    moveXY(7,2, ""); //seno
                    printf("%.3lf",sin(valor*M_PI/180));
                    moveXY(10,3, ""); //cosseno
                    printf("%.3lf",cos(valor*M_PI/180));
                    moveXY(11,4, ""); //tangente
                    if (valor!=90 && valor!=270)
                        printf("%.3lf",tan(valor*M_PI/180));
                    else
                        printf("inexistente");
                    moveXY(10,5, ""); //secante
                    if (valor==90 || valor==270)
                    {
                        printf("inexistente");
                    }
                    else
                    {
                        if (cos(valor*M_PI/180)!=0)
                        printf("%.3lf",1/cos(valor*M_PI/180));
                        else
                        printf("inexistente");
                    }
                    moveXY(13,6, ""); //cossecante
                    if (valor==180 || valor==360 || valor==0)
                    {
                            printf("inexistente");
                    }
                    else
                    if (sin(valor*M_PI/180)!=0)
                        printf("%.3lf",1/sin(valor*M_PI/180));
                    else
                        printf("inexistente");
                    moveXY(13,7, ""); //cotangente
                    if (valor==180 || valor==360 || valor==0)
                    {
                            printf("inexistente");
                    }
                    else
                    if (valor!=90 && valor!=270 && (tan(valor*M_PI/180))!=0)
                        printf("%.3lf",1/tan(valor*M_PI/180));
                    else
                        printf("inexistente");
                }

                if (posY == 23) //c�lculo em radianos
                {
                	system("cls");
                	menu();
                	programa1();
                    moveXY(18,1, "");
                    scanf("%lf",&valor);
                    if (valor==6,283185307189){
						valor=0;
					}
					else if (valor>6,283185307189)
                    {
                        p=valor/6,283185307189;
                        valor=valor-(6,283185307189*abs(p));
                    }

                    moveXY(7,2, ""); //seno
                    printf("%.3lf",sin(valor));
                    moveXY(10,3, ""); //cosseno

                    printf("%.3lf",cos(valor));
                    moveXY(11,4, ""); //tangente
                    if (valor!=1,570796326797 && valor!=4,712388980391)
                        printf("%.3lf",tan(valor));
                    else
                        printf("inexistente");
                    moveXY(10,5, ""); //secante
                    if (valor!=1,570796326797 && valor!=4,712388980391)
                    {
                    	if (cos(valor)!=0)
                        printf("%.3lf",1/cos(valor));
                        else
                        printf("inexistente");

                    }
                    else
                    {
                        printf("inexistente");
                    }
                    moveXY(13,6, ""); //cossecante
                    if (valor!=3,141592653594 && valor!=0)
                    {
                    	if ((sin(valor))!=0)
                        	printf("%.3lf",1/sin(valor));
	                    else
	                        printf("inexistente");

                    }
                    else{
                            printf("inexistente");
                	}
					moveXY(13,7, ""); //cotangente
                    if (valor!=3,141592653594 && valor!=0)
                    {
                    	if (valor!=90 && valor!=270 && (tan(valor))!=0)
                        printf("%.3lf",1/tan(valor));
	                    else
	                        printf("inexistente");

                    }
                    else{
                            printf("inexistente");
                    }
                }

                if (posY == 24) //c�lculo dos arco seno
                {
                    system("cls");
                	menu();
                	programaArcoSeno();
                    moveXY(25,1, "");
                    scanf("%lf",&valor);
                    if(valor>1 || valor<-1)
                    {
                    	moveXY(16,2,"Inexistente");
                    	moveXY(19,3,"Inexistente");
					}
					else{
						moveXY(16,2,"");
						printf("%.2lf",(asin(valor)*grausPorRadiano));
                    	moveXY(19,3,"");
                    	printf("%lf",asin(valor));
					}
                }

                if (posY == 25) //c�lculo do arco cosseno
                {
                    system("cls");
                	menu();
                	programaArcoCosseno();
                    moveXY(28,1, "");
                    scanf("%lf",&valor);
                    if(valor>1 || valor<-1)
                    {
                    	moveXY(16,2,"Inexistente");
                    	moveXY(19,3,"Inexistente");
					}
					else{
						moveXY(16,2,"");
						printf("%.2lf",(acos(valor)*grausPorRadiano));
                    	moveXY(19,3,"");
                    	printf("%lf",acos(valor));
					}
                }
				if (posY == 26) //c�lculo do arco tangente
                {
                    system("cls");
                	menu();
                	programaArcoTangente();
                    moveXY(29,1, "");
                    scanf("%lf",&valor);
					moveXY(16,2,"");
					printf("%.2lf",(atan(valor)*grausPorRadiano));
                	moveXY(19,3,"");
                	printf("%lf",atan      (valor));
                }
                if (posY == 27)
                {
                	system("cls");
                	menu();
                	tabelaConsultaNotaveis();
				}

                if (posY == 28)
                {
                    system("cls");
                    exit(0);
                 }
            break;
        }

    }while(1);

    system("pause");
    return 0;
}

