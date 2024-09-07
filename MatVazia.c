
#include<windows.h>
#include <time.h>
#include <stdio.h>
#include<locale.h>


char matVazia[15][15];
char mat_copiadora[15][15];
char login[30];
char login2[30];
char senha[30];
short int x = 40;
short int y = 5;
short int simbolo_trilha = 0;
short int Player01_heart = 0;
short int Player02_wood  = 0;
short int Player03_sword = 0;
short int Player04_smile = 0;

short int CasaRed = 0;
short int CasaGreen = 0;
short int CasaBlue = 0;
short int CasaYellow =0;


short int  RollDiceGme=0;



short int ligavolta =1;
short int desligaGame=0;
//--------------------------

short int ContadorDeEntrada =0;

short int TesteDeVezRed =0;


//------------------------------------------------------nULTIMA VERSÃO

typedef struct
{
    int vetPosicao[55];
    char nomePosicao[55];


} Rota_do_Jogo;

/*typedef struct
{
    int anterior;
} JogadaAnterior;*/
typedef struct
{
    short int GiroDado;
    short int AcumuladorDeGiro;
    short int saida;
    short int mascara;
    short int killPeao;
    short int chegada;
    short int volta;
    short int RotaGeral;
    short int MinhaVez;
} Times;

Times R1,G1,Y1,B1;
Rota_do_Jogo rotaGlobal,RotaTeste;
//-----------------------------------------------------------




void TabelaAscii()
{
    int i;
    for(i=0; i<300; i++)
    {
        printf("%i -simbolo..........> %c\n",i,i);
    }

}
void Regra_da_Final_Red()
{
    if(R1.AcumuladorDeGiro>57 && R1.AcumuladorDeGiro>62)
    {

        int aux = RollDiceGme;
        int stop =R1.AcumuladorDeGiro - aux;
        R1.AcumuladorDeGiro = stop;
        Rota_do_R1(R1.AcumuladorDeGiro);

    }

}
void Regra_da_Final_Green()
{
    if(G1.AcumuladorDeGiro>57 && G1.AcumuladorDeGiro>62)
    {

        int aux = RollDiceGme;
        int stop =G1.AcumuladorDeGiro - aux;
        G1.AcumuladorDeGiro = stop;
        Rota_do_G1(G1.AcumuladorDeGiro);

    }

}

void Regra_da_Final_Yellow()
{
    if(Y1.AcumuladorDeGiro>57 && Y1.AcumuladorDeGiro>62)
    {

        int aux = RollDiceGme;
        int stop =Y1.AcumuladorDeGiro - aux;
        Y1.AcumuladorDeGiro = stop;
        Rota_do_Y1(Y1.AcumuladorDeGiro);

    }

}
void Regra_da_Final_blue()
{
    if(B1.AcumuladorDeGiro>57 && B1.AcumuladorDeGiro>62)
    {

        int aux = RollDiceGme;
        int stop =B1.AcumuladorDeGiro - aux;
        B1.AcumuladorDeGiro = stop;
        Rota_do_B1(B1.AcumuladorDeGiro);

    }

}


void Vitoria()
{

inicio:

    if(R1.AcumuladorDeGiro ==62)
    {
        desligaGame=1;

        for(int i =5; i<10; i++)
        {

            for(int j =1; j<14; j++)
            {


                mat_copiadora[i][j]=' ';


            }
        }

        Show_Matriz_Copiadora();
        gotoxy(45,12);
        CorVermelha();
        printf("%s VENCEU!!\n",login);
        printf("\033[10B");


    }

    //----------------------------------------

    if(Y1.AcumuladorDeGiro == 61||Y1.AcumuladorDeGiro == 62)
    {

        desligaGame=1;

        for(int i =5; i<10; i++)
        {

            for(int j =1; j<14; j++)
            {


                mat_copiadora[i][j]=' ';


            }
        }

        Show_Matriz_Copiadora();
        ColorYellow();
        gotoxy(45,12);
        printf("%s VENCEU!!\n",login2);
        printf("\033[10B");


    }



}

void CorVermelha()
{

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    //  SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
    // SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE);
    //SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
    // printf("\033[1;31;40m");

}
void ColorGreen()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
    // printf("\033[1;32;40m");

}

void ColorBlue()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_BLUE);

}
void ColorAzulAgua()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);

}
void ColorYellow()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN);

}
void ColorWhite()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

void gotoxy(int x, int y)
{
    printf("\033[%d;%dH", y, x);
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void hideCursor()
{
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 100;
    info.bVisible = FALSE;
    SetConsoleCursorInfo(consoleHandle, &info);
}
Creditos_Finais()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

    int cont1=25,cont =21;
    setlocale(LC_ALL,"portuguese");
    hideCursor();




    while(cont1 !=3)
    {
        cont1 --;

        gotoxy(58,cont1);

        printf(
            "\n\n\n                                  No contexto atual, a tecnologia digital está transformando jogos de tabuleiro como o Ludo.\n\n\n"
            "                                  Este projeto digitaliza o Ludo em C para oferecer uma experiência moderna e acessível,\n\n\n"
            "                                  mantendo a essência do jogo tradicional. Serão implementadas interfaces intuitivas e seguras,\n\n\n"
            "                                  promovendo uma nova forma de jogar, adequada para todas as gerações.\n\n\n"

        );


        Sleep(300);
        system("cls");

    }

    //------------------------------------------------------------------------------------



    while(cont !=3)
    {

        cont--;



        gotoxy(58,cont);
        printf("    DESENVOLVEDORES\n\n\n");
        printf("                                        Tema .................................Professor Rodrigo Marcondes\n\n");
        printf("                                        Telas documentação....................Lucas Lima\n\n");
        printf("                                        Lógica funcional .....................Paulo Bueno\n\n\n\n\n\n");






        printf(
            "                                            ______      _____  ______          _____    ___   ___ ___  _  _   \n"
            "                                           |  ____/\\   / ____||  ____|   /\\   |  __ \\  |__ \\ / _ \\__ \\| || |  \n"
            "                                           | |__ /  \\  | |    | |__     /  \\  | |__) |    ) | | | | ) | || |_ \n"
            "                                           |  __/ /\\ \\ | |    |  __|   / /\\ \\ |  _  /    / /| | | |/ /|__   _|\n"
            "                                           | | / ____ \\| |____| |____ / ____ \\| | \\ \\   / /_| |_| / /_   | |  \n"
            "                                           |_|/_/    \\_\\______|______/_/    \\_\\_|  \\_\\ |____|\\___/____|  |_|  \n"
            "                                                                    \n"
            "                                                                    \n"
        );
        if(cont ==4)
        {
            getch();
        }
        Sleep(100);

        system("cls");


    }




}
void Ranking()
{

    printf("   \033[10B");
    printf("                                     \033[38;5;87m%c\033[38;5;87m\033[0m", 201);

    for(int i = 0; i < 55; i++) printf("\033[38;5;87m%c\033[0m", 205);

    printf("\033[38;5;87m%c\033[0m\n", 187);

    printf("                                        \033[38;5;87m%c\033[0m               \033[1;33m        RANKING                         \033[0m\033[38;5;87m%c\033[0m\n", 186, 186);

    printf("                                        \033[38;5;87m%c\033[38;5;87m\033[0m", 204);
    for(int i = 0; i < 55; i++) printf("\033[38;5;87m%c\033[0m", 205);
    printf("\033[38;5;87m%c\033[0m\n", 185);

    printf("                                        \033[38;5;87m%c\033[0m 1. LUCAS LIMA.                                        \033[38;5;87m%c\033[0m\n", 186, 186);
    printf("                                        \033[38;5;87m%c\033[0m 2. JOAO DO CAMINHAO                                   \033[38;5;87m%c\033[0m\n", 186, 186);
    printf("                                        \033[38;5;87m%c\033[0m 3. PAULO BUENO                                        \033[38;5;87m%c\033[0m\n", 186, 186);
    printf("                                        \033[38;5;87m%c\033[0m 4..........................                           \033[38;5;87m%c\033[0m\n", 186, 186);

    printf("                                        \033[38;5;87m%c\033[0m \033[38;5;220mTotal jogadores............03    \033[0m                     \033[38;5;87m%c\033[0m\n", 186, 186);

    printf("                                        \033[38;5;87m%c\033[38;5;87m\033[0m", 200);
    for(int i = 0; i < 55; i++) printf("\033[38;5;87m%c\033[0m", 205);
    printf("\033[38;5;87m%c\033[0m\n", 188);

    printf("\033[10B");


}
void Telalogin()
{


    ContadorDeEntrada++;


    //----------------------------------------------------


    printf("\033[10B");


    printf("                                        \033[38;5;87m%c\033[38;5;87m\033[0m", 201);
    for(int i = 0; i < 55; i++) printf("\033[38;5;87m%c\033[0m", 205);
    printf("\033[38;5;87m%c\033[0m\n", 187);

    printf("                                        \033[38;5;87m%c\033[0m                  \033[1;33mTELA DE LOGIN                        \033[0m\033[38;5;87m%c\033[0m\n", 186, 186);

    printf("                                        \033[38;5;87m%c\033[38;5;87m\033[0m", 204);
    for(int i = 0; i < 55; i++) printf("\033[36;5;87m%c\033[0m", 205);
    printf("\033[38;5;87m%c\033[0m\n", 185);

    printf("                                        \033[38;5;87m%c\033[0m                                                       \033[38;5;87m%c\033[0m\n", 186, 186);
    printf("                                        \033[38;5;87m%c\033[0m                 \033[1;33mDigite seu login:                     \033[0m\033[38;5;87m%c\033[0m\n", 186, 186);
    printf("                                        \033[38;5;87m%c\033[0m                                                       \033[38;5;87m%c\033[0m\n", 186, 186);
    printf("                                        \033[38;5;87m%c\033[0m                 \033[1;33mDigite sua senha:                     \033[0m\033[38;5;87m%c\033[0m\n", 186, 186);
    printf("                                        \033[38;5;87m%c\033[0m                                                       \033[38;5;87m%c\033[0m\n", 186, 186);

    printf("                                        \033[38;5;87m%c\033[38;5;87m\033[0m", 200);
    for(int i = 0; i < 55; i++) printf("\033[38;5;87m%c\033[0m", 205);
    printf("\033[38;5;87m%c\033[0m\n", 188);


    if( ContadorDeEntrada ==1)
    {
        gotoxy(76,14);
        scanf("%s",&login);

        gotoxy(76,16);
        scanf("%s",&senha);
        printf("\033[4B");

    }
    else  if( ContadorDeEntrada ==2)
    {
        gotoxy(76,14);
        scanf("%s",&login2);

        gotoxy(76,16);
        scanf("%s",&senha);
        printf("\033[4B");;

    }

}
void Regras()
{

    printf("\033[10B");

    printf("                                    \033[38;5;87m%c\033[0m", 201);
    for(int i = 0; i < 55; i++) printf("\033[38;5;87m%c\033[0m", 205);
    printf("\033[38;5;87m%c\033[0m\n", 187);

    printf("                                    \033[38;5;87m%c\033[0m       \033[1;33mREGRAS DO LUDO                                  \033[0m\033[38;5;87m%c\033[0m\n", 186, 186);

    printf("                                    \033[38;5;87m%c\033[0m", 204);
    for(int i = 0; i < 55; i++) printf("\033[38;5;87m%c\033[0m", 205);
    printf("\033[38;5;87m%c\033[0m\n", 185);

    printf("                                    \033[38;5;87m%c\033[0m 1. Cada jogador tem quatro pecas.                     \033[38;5;87m%c\033[0m\n", 186, 186);
    printf("                                    \033[38;5;87m%c\033[0m 2. O objetivo e levar todas as pecas                  \033[38;5;87m%c\033[0m\n", 186, 186);
    printf("                                    \033[38;5;87m%c\033[0m    do inicio ate o centro do tabuleiro                \033[38;5;87m%c\033[0m\n", 186, 186);
    printf("                                    \033[38;5;87m%c\033[0m 3. Pecas so podem sair da base ao tirar               \033[38;5;87m%c\033[0m\n", 186, 186);
    printf("                                    \033[38;5;87m%c\033[0m    um 6 no dado.                                      \033[38;5;87m%c\033[0m\n", 186, 186);
    printf("                                    \033[38;5;87m%c\033[0m 4. Jogar um 6 da direito a uma nova                   \033[38;5;87m%c\033[0m\n", 186, 186);
    printf("                                    \033[38;5;87m%c\033[0m    jogada.                                            \033[38;5;87m%c\033[0m\n", 186, 186);
    printf("                                    \033[38;5;87m%c\033[0m 5. Se uma peca cai na mesma casa que                  \033[38;5;87m%c\033[0m\n", 186, 186);
    printf("                                    \033[38;5;87m%c\033[0m    uma peca adversaria, peca oponente                 \033[38;5;87m%c\033[0m\n", 186, 186);
    printf("                                    \033[38;5;87m%c\033[0m    e mandada de volta a base.                         \033[38;5;87m%c\033[0m\n", 186, 186);
    printf("                                    \033[38;5;87m%c\033[0m 6. As pecas movem-se pelo tabuleiro                   \033[38;5;87m%c\033[0m\n", 186, 186);
    printf("                                    \033[38;5;87m%c\033[0m    conforme o numero tirado no dado.                  \033[38;5;87m%c\033[0m\n", 186, 186);
    printf("                                    \033[38;5;87m%c\033[0m 7. O primeiro jogador a levar todas as                \033[38;5;87m%c\033[0m\n", 186, 186);
    printf("                                    \033[38;5;87m%c\033[0m    suas pecas ao centro vence.                        \033[38;5;87m%c\033[0m\n", 186, 186);
    printf("                                    \033[38;5;87m%c\033[0m                                                       \033[38;5;87m%c\033[0m\n", 186, 186);
    printf("                                    \033[38;5;87m%c\033[0m   \033[38;5;220mDivirta-se e jogue limpo!      \033[0m                     \033[38;5;87m%c\033[0m\n", 186, 186);

    printf("                                    \033[38;5;87m%c\033[0m", 200);
    for(int i = 0; i < 55; i++) printf("\033[38;5;87m%c\033[0m", 205);
    printf("\033[38;5;87m%c\033[0m\n", 188);


}
void  Gravador(void)
{

    FILE *file;
    file=fopen("Gravacao.txt","w");
    fprintf(file,"LOGIN: %s\nSENHA: %s",login,senha);
    fclose(file);

    return 0;
}

int LigarVoltar(int x)
{
    if(x==1)
    {
        mat_copiadora[1][6]=169;
        mat_copiadora[12][8]=169;
    }

}

void Creditos()
{
    hideCursor();
    int time =100;
    int cont =0;
    while(cont!=1)
    {
        cont++;
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY | FOREGROUND_GREEN);

        gotoxy(50,3);
        printf("DESENVOLVEDORES ");
        Sleep(1000);
        system("cls");
        gotoxy(50,5);
        printf("I   2 5 6 J 5 5 P 6 8 P 7");
        Sleep(time);
        system("cls");
        gotoxy(50,3);
        printf("  S D A U U 9 8 O 0 6");
        Sleep(time);
        system("cls");
        gotoxy(50,5);
        printf(" I T  A M O I Y 6 8 4 3");
        Sleep(time);
        system("cls");
        gotoxy(50,3);
        printf(" A J L K I  L L K J H Q W E R T O I Ç K H O L");
        Sleep(time);
        system("cls");
        gotoxy(50,5);
        printf("I   A I D S Ç P X");
        Sleep(time);
        system("cls");
        gotoxy(50,7);
        printf("PAULO BUENO");
        Sleep(1000);
        system("cls");
        gotoxy(50,3);
        printf(" B  U L  G F I T   S");
        Sleep(time);
        system("cls");
        gotoxy(50,5);
        printf("I   A   D S J  K L J H G U H N B C X D D J L  U U P X");
        Sleep(time);
        system("cls");
        gotoxy(50,3);
        printf("  S D A U L K U Y X Y");
        Sleep(time);
        system("cls");
        gotoxy(50,5);
        printf(" I T  A M O I Y U J H G U S");
        Sleep(time);
        system("cls");
        gotoxy(50,3);
        printf(" A J L K I  L L K J H Q W E R T O I Ç K H O L");
        Sleep(time);
        system("cls");
        gotoxy(50,5);
        printf("I   A I D S Ç P X");
        Sleep(time);
        system("cls");
        gotoxy(50,5);
        printf("I   A  O  KI W Q");
        Sleep(time);
        system("cls");
        gotoxy(50,4);
        printf("LUCAS LIMA");
        Sleep(1000);
        system("cls");
        gotoxy(50,5);
        printf(" A A L H G Y T R W E D C V N G S Y U F G ");
        Sleep(time);
        system("cls");
        gotoxy(50,3);
        printf("I   A I D F G J J K D R P X");
        Sleep(time);
        system("cls");
        gotoxy(50,5);
        printf("I   A  F Q");
        Sleep(time);
        system("cls");
        gotoxy(50,5);
        printf(" A A L H G Y G S 2 6 F G ");
        Sleep(time);
        system("cls");
        gotoxy(50,6);
        printf("FACEAR 2024");
        Sleep(1000);
        system("cls");
    }
}
void Loading()
{

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY | FOREGROUND_GREEN);
    int x = 50;
    int y = 10;
    int B = 219;

    char vet[70] = {B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B};


    gotoxy(x, y);
    printf("%c", 218);
    for (int i = 0; i < 40; i++) printf("%c", 196);
    //--------------------------------------------------
    printf("%c", 191);

    gotoxy(x, y + 1);
    printf("%c", 179);
    gotoxy(x + 41, y + 1);
    printf("%c", 179);

    gotoxy(x, y + 2);
    printf("%c", 192);
    //--------------------------------------------------
    for (int i = 0; i < 40; i++) printf("%c", 196);
    printf("%c", 217);

    gotoxy(60,11);
    printf("L U D O  F I R E \n");

    gotoxy(64,13);
    printf("...LOADING... \n");

    gotoxy(x + 1, y + 1);
    for (int i = 0; i < 40; i++)
    {
        printf("%c", vet[i]);
        Sleep(100);
    }

    printf("\n\n\n\n\n\n");
    // getch();

}

void MatrizLudo()
{



    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    //system("color B");
    int tamanho = 55;
    int simbolA =178;
    int simboloB =186;
    char matTela[10][tamanho];

    int x = 50;//30
    int y = 10;//5



    for(int i=0; i<10; i++)
    {
        for(int j=0; j<tamanho; j++)
        {
            matTela[i][j] = simbolA;

        }
        printf("\n");
    }


    for(int j=0; j<tamanho; j++)
    {

        matTela[0][j] = 205;
        matTela[9][j] = 205;
    }

    for(int i=0; i<10; i++)
    {

        matTela[0][0] = 201;
        matTela[0][54] = 187;
        matTela[9][0] = 200;
        matTela[9][54] = 188;

        if(i>0 && i<9)
        {
            matTela[i][0] = simboloB;
            matTela[i][54] = simboloB;
        }

        if(i>1 && i<8)
        {
            matTela[i][19] = ' ';
            matTela[i][23] = ' ';
            matTela[i][26] = ' ';
            matTela[i][28] = ' ';
            matTela[i][32] = ' ';
            matTela[i][34] = ' ';
        }

    }


    for(int j =20; j<34; j++)
    {
        matTela[7][j] = ' ';
        matTela[7][22] = simbolA;
        matTela[7][27] = simbolA;
        matTela[7][30] = simbolA;
        matTela[7][31] = simbolA;

        if(j>27 && j<34)
        {
            matTela[2][j] = ' ';
        }
        matTela[2][30] = simbolA;
        matTela[2][31] = simbolA;

    }
    for(int i=3; i<7; i++)
    {

        matTela[i][30] = ' ';

    }


    //show matela-----------------------------

    for(int i=0; i<10; i++)
    {

        for(int j=0; j<tamanho; j++)
        {
            int x_atual = x + j * 1;
            int y_atual = y + i;


            gotoxy(x_atual, y_atual);


            if(i==0 && j<55)
            {
                SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
            }

            else if(j==0 && i>0)
            {
                SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
            }

            else if(j==54 && i>0)
            {
                SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);

            }

            else if(i==9 && j<55)
            {
                SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);

            }

            else
            {
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            }



            /*matTela[7][20] ='F';
            matTela[7][25] ='I';
            matTela[7][28] ='R';
            matTela[7][33] ='E';*/


            printf("%c",matTela[i][j]);

        }
        printf("\n");
    }

}

void Menu()
{


inicio:
    MatrizLudo();


    int coleta =0;
    void Opcoes() {}
    gotoxy(69,22);
    printf("1.NOVO JOGO\n");
    gotoxy(69,23);
    printf("2.SOBRE\n");
    gotoxy(69,24);
    printf("3.RANKING\n");
    gotoxy(69,25);
    printf("4.INCLUIR JOGADOR\n");
    gotoxy(70,17);
    CorVermelha();
    printf("F");
    gotoxy(75,17);
    ColorYellow();
    printf("I");
    gotoxy(78,17);
    CorVermelha();
    printf("R");
    gotoxy(83,17);
    ColorYellow();
    printf("E");

    gotoxy(69,27);
    scanf("%i",&coleta);
    system("cls");

    switch(coleta)
    {
    case 1:
        Creditos();
        Loading();
        coleta =0;
        break;
    case 2:
        Regras();
        getch();
        system("cls");
        goto inicio;
        coleta =0;
        break;
    case 3:
        Ranking();
        getch();
        system("cls");
        goto inicio;
        coleta =0;
        break;
    case 4:
        Telalogin();
        Gravador();
        getch();
        system("cls");

        goto inicio;
        coleta =0;

        break;
    }


}


int Rota_do_R1(int QualPeao)
{
    CorVermelha();

    switch(QualPeao)
    {

    case 1:
        gotoxy(42,11);
        printf("R");
        rotaGlobal.vetPosicao[1]='R';
        break;
    case 2:
        gotoxy(44,11);
        printf("R");
        rotaGlobal.vetPosicao[2]='R';
        break;
    case 3:
        gotoxy(46,11);
        printf("R");
        rotaGlobal.vetPosicao[3]='R';
        break;
    case 4:
        gotoxy(48,11);
        printf("R");
        rotaGlobal.vetPosicao[4]='R';
        break;
    case 5:
        gotoxy(50,11);
        printf("R");
        rotaGlobal.vetPosicao[5]='R';
        break;
    case 6:
        gotoxy(52,11);
        printf("R");
        rotaGlobal.vetPosicao[6]='R';
        break;

    //---------------------------curva

    case 7:
        gotoxy(52,10);
        printf("R");
        rotaGlobal.vetPosicao[7]='R';
        break;
    case 8:
        gotoxy(52,9);
        printf("R");
        rotaGlobal.vetPosicao[8]='R';
        break;
    case 9:
        gotoxy(52,8);
        printf("R");
        rotaGlobal.vetPosicao[9]='R';
        break;
    case 10:
        gotoxy(52,7);
        printf("R");
        rotaGlobal.vetPosicao[10]='R';
        break;
    case 11:
        gotoxy(52,6);
        printf("R");
        rotaGlobal.vetPosicao[11]='R';
        break;
    case 12:
        gotoxy(52,5);
        printf("R");
        rotaGlobal.vetPosicao[12]='R';
        break;
    //---------------------------curva
    case 13:
        gotoxy(54,5);
        printf("R");
        rotaGlobal.vetPosicao[13]='R';
        break;
    case 14:
        gotoxy(56,5);
        printf("R");
        rotaGlobal.vetPosicao[14]='R';
        break;
    //-----------------------------
    case 15:
        gotoxy(56,6);
        printf("R");
        rotaGlobal.vetPosicao[15]='R';
        break;
    case 16:
        gotoxy(56,7);
        printf("R");
        rotaGlobal.vetPosicao[16]='R';
        break;
    case 17:
        gotoxy(56,8);
        printf("R");
        rotaGlobal.vetPosicao[17]='R';
        break;
    case 18:
        gotoxy(56,9);
        printf("R");
        rotaGlobal.vetPosicao[18]='R';
        break;
    case 19:
        gotoxy(56,10);
        printf("R");
        rotaGlobal.vetPosicao[19]='R';
        break;
    case 20:
        gotoxy(56,11);
        printf("R");
        rotaGlobal.vetPosicao[20]='R';
        break;
    //---------------------------curva
    case 21:
        gotoxy(58,11);
        printf("R");
        rotaGlobal.vetPosicao[21]='R';
        break;
    case 22:
        gotoxy(60,11);
        printf("R");
        rotaGlobal.vetPosicao[22]='R';
        break;
    case 23:
        gotoxy(62,11);
        printf("R");
        rotaGlobal.vetPosicao[23]='R';
        break;
    case 24:
        gotoxy(64,11);
        printf("R");
        rotaGlobal.vetPosicao[24]='R';
        break;
    case 25:
        gotoxy(66,11);
        printf("R");
        rotaGlobal.vetPosicao[25]='R';
        break;
    case 26:
        gotoxy(68,11);
        printf("R");
        rotaGlobal.vetPosicao[26]='R';
        break;
    //--------------------------------------
    case 27:
        gotoxy(68,12);
        printf("R");
        rotaGlobal.vetPosicao[27]='R';
        break;
    case 28:
        gotoxy(68,13);
        printf("R");
        rotaGlobal.vetPosicao[28]='R';
        break;
    //--------------------------------curva
    case 29:
        gotoxy(66,13);
        printf("R");
        rotaGlobal.vetPosicao[29]='R';
        break;
    case 30:
        gotoxy(64,13);
        printf("R");
        rotaGlobal.vetPosicao[30]='R';
        break;
    case 31:
        gotoxy(62,13);
        printf("R");
        rotaGlobal.vetPosicao[31]='R';
        break;
    case 32:
        gotoxy(60,13);
        printf("R");
        rotaGlobal.vetPosicao[32]='R';
        break;
    case 33:
        gotoxy(58,13);
        printf("R");
        rotaGlobal.vetPosicao[33]='R';
        break;
    //--------------------------------curva
    case 34:
        gotoxy(56,13);
        printf("R");
        rotaGlobal.vetPosicao[34]='R';
        break;
    case 35:
        gotoxy(56,14);
        printf("R");
        rotaGlobal.vetPosicao[35]='R';
        break;
    case 36:
        gotoxy(56,15);
        printf("R");
        rotaGlobal.vetPosicao[36]='R';
        break;
    case 37:
        gotoxy(56,16);
        printf("R");
        rotaGlobal.vetPosicao[37]='R';
        break;
    case 38:
        gotoxy(56,17);
        printf("R");
        rotaGlobal.vetPosicao[38]='R';
        break;
    case 39:
        gotoxy(56,18);
        printf("R");
        rotaGlobal.vetPosicao[39]='R';
        break;
    case 40:
        gotoxy(56,19);
        printf("R");
        rotaGlobal.vetPosicao[40]='R';
        break;
    //--------------------------------curva
    case 41:
        gotoxy(54,19);
        printf("R");
        rotaGlobal.vetPosicao[41]='R';
        break;
    case 42:
        gotoxy(52,19);
        printf("R");
        rotaGlobal.vetPosicao[42]='R';
        break;
    //--------------------------------up
    case 43:
        gotoxy(52,18);
        printf("R");
        rotaGlobal.vetPosicao[43]='R';
        break;
    case 44:
        gotoxy(52,17);
        printf("R");
        rotaGlobal.vetPosicao[44]='R';
        break;
    case 45:
        gotoxy(52,16);
        printf("R");
        rotaGlobal.vetPosicao[45]='R';
        break;
    case 46:
        gotoxy(52,15);
        printf("R");
        rotaGlobal.vetPosicao[46]='R';
        break;
    case 47:
        gotoxy(52,14);
        printf("R");
        rotaGlobal.vetPosicao[47]='R';
        break;
    case 48:
        gotoxy(52,13);
        printf("R");
        rotaGlobal.vetPosicao[48]='R';
        break;
    //--------------------------------R
    case 49:
        gotoxy(50,13);
        printf("R");
        rotaGlobal.vetPosicao[49]='R';
        break;
    case 50:
        gotoxy(48,13);
        printf("R");
        rotaGlobal.vetPosicao[50]='R';
        break;
    case 51:
        gotoxy(46,13);
        printf("R");
        rotaGlobal.vetPosicao[51]='R';
        break;
    case 52:
        gotoxy(44,13);
        printf("R");
        rotaGlobal.vetPosicao[52]='R';
        break;
    case 53:
        gotoxy(42,13);
        printf("R");
        rotaGlobal.vetPosicao[53]='R';
        break;
    case 54:
        gotoxy(40,13);
        printf("R");
        rotaGlobal.vetPosicao[54]='R';
        break;
    //--------------------------------up
    case 55:
        gotoxy(40,12);
        printf("R");
        rotaGlobal.vetPosicao[55]='R';
        break;
    //--------------------------------finish
    case 56:
        gotoxy(42,12);
        printf("R");
        break;
    case 57:
        gotoxy(44,12);
        printf("R");
        break;
    case 58:
        gotoxy(46,12);
        printf("R");
        break;
    case 59:
        gotoxy(48,12);
        printf("R");
        break;
    case 60:
        gotoxy(50,12);
        printf("R");
        break;
    case 61:
        gotoxy(52,12);
        printf("R");
        break;
    case 62:
        gotoxy(54,12);
        printf("R");
        break;


        // }
    }
}

int Rota_do_Y1(int QualPeao)
{
    ColorYellow();



    switch(QualPeao)
    {
    case 1:
        gotoxy(66,13);
        printf("Y");
        rotaGlobal.vetPosicao[29]='Y';
        Y1.RotaGeral =29;
        break;
    case 2:
        gotoxy(64,13);
        printf("Y");
        rotaGlobal.vetPosicao[30]='Y';
        Y1.RotaGeral =30;
        break;
    case 3:
        gotoxy(62,13);
        printf("Y");
        rotaGlobal.vetPosicao[31]='Y';
        Y1.RotaGeral =31;
        break;
    case 4:
        gotoxy(60,13);
        printf("Y");
        rotaGlobal.vetPosicao[32]='Y';
        Y1.RotaGeral =32;
        break;
    case 5:
        gotoxy(58,13);
        printf("Y");
        rotaGlobal.vetPosicao[33]='Y';
        Y1.RotaGeral =33;
        break;
    //--------------------------------curva
    case 6:
        gotoxy(56,13);
        printf("Y");
        rotaGlobal.vetPosicao[34]='Y';
        Y1.RotaGeral =34;
        break;
    case 7:
        gotoxy(56,14);
        printf("Y");
        rotaGlobal.vetPosicao[35]='Y';
        Y1.RotaGeral =35;
        break;
    case 8:
        gotoxy(56,15);
        printf("Y");
        rotaGlobal.vetPosicao[36]='Y';
        Y1.RotaGeral =36;
        break;
    case 9:
        gotoxy(56,16);
        printf("Y");
        rotaGlobal.vetPosicao[37]='Y';
        Y1.RotaGeral =37;
        break;
    case 10:
        gotoxy(56,17);
        printf("Y");
        rotaGlobal.vetPosicao[38]='Y';
        Y1.RotaGeral =38;
        break;
    case 11:
        gotoxy(56,18);
        printf("Y");
        rotaGlobal.vetPosicao[39]='Y';
        Y1.RotaGeral =39;
        break;
    case 12:
        gotoxy(56,19);
        printf("Y");
        rotaGlobal.vetPosicao[40]='Y';
        Y1.RotaGeral =40;
        break;
    //--------------------------------curva
    case 13:
        gotoxy(54,19);
        printf("Y");
        rotaGlobal.vetPosicao[41]='Y';
        Y1.RotaGeral =41;
        break;
    case 14:
        gotoxy(52,19);
        printf("Y");
        rotaGlobal.vetPosicao[42]='Y';
        Y1.RotaGeral =42;
        break;
    //--------------------------------up
    case 15:
        gotoxy(52,18);
        printf("Y");
        rotaGlobal.vetPosicao[43]='Y';
        Y1.RotaGeral =43;
        break;
    case 16:
        gotoxy(52,17);
        printf("Y");
        rotaGlobal.vetPosicao[44]='Y';
        Y1.RotaGeral =44;
        break;
    case 17:
        gotoxy(52,16);
        printf("Y");
        rotaGlobal.vetPosicao[45]='Y';
        Y1.RotaGeral =45;
        break;
    case 18:
        gotoxy(52,15);
        printf("Y");
        rotaGlobal.vetPosicao[46]='Y';
        Y1.RotaGeral =46;
        break;
    case 19:
        gotoxy(52,14);
        printf("Y");
        rotaGlobal.vetPosicao[47]='Y';
        Y1.RotaGeral =47;
        break;
    case 20:
        gotoxy(52,13);
        printf("Y");
        rotaGlobal.vetPosicao[48]='Y';
        Y1.RotaGeral =48;
        break;
    //--------------------------------R
    case 21:
        gotoxy(50,13);
        printf("Y");
        rotaGlobal.vetPosicao[49]='Y';
        Y1.RotaGeral =49;
        break;
    case 22:
        gotoxy(48,13);
        printf("Y");
        rotaGlobal.vetPosicao[50]='Y';
        Y1.RotaGeral =50;
        break;
    case 23:
        gotoxy(46,13);
        printf("Y");
        rotaGlobal.vetPosicao[51]='Y';
        Y1.RotaGeral =51;
        break;
    case 24:
        gotoxy(44,13);
        printf("Y");
        rotaGlobal.vetPosicao[52]='Y';
        Y1.RotaGeral =52;
        break;
    case 25:
        gotoxy(42,13);
        printf("Y");
        rotaGlobal.vetPosicao[53]='Y';
        Y1.RotaGeral =53;
        break;
    case 26:
        gotoxy(40,13);
        printf("Y");
        rotaGlobal.vetPosicao[54]='Y';
        Y1.RotaGeral =54;
        break;
    //--------------------------------up
    case 27:
        gotoxy(40,12);
        printf("Y");
        rotaGlobal.vetPosicao[55]='Y';
        Y1.RotaGeral =55;
        break;

    case 28:
        gotoxy(40,11);
        printf("Y");
        rotaGlobal.vetPosicao[0]='Y';
        Y1.RotaGeral =0;
        break;

    //----------------------------
    case 29:
        gotoxy(42,11);
        printf("Y");
        rotaGlobal.vetPosicao[1]='Y';
        Y1.RotaGeral =1;
        break;
    case 30:
        gotoxy(44,11);
        printf("Y");
        rotaGlobal.vetPosicao[2]='Y';
        Y1.RotaGeral =2;
        break;
    case 31:
        gotoxy(46,11);
        printf("Y");
        rotaGlobal.vetPosicao[3]='Y';
        Y1.RotaGeral =3;
        break;
    case 32:
        gotoxy(48,11);
        printf("Y");
        rotaGlobal.vetPosicao[4]='Y';
        Y1.RotaGeral =4;
        break;
    case 33:
        gotoxy(50,11);
        printf("Y");
        rotaGlobal.vetPosicao[5]='Y';
        Y1.RotaGeral =5;
        break;
    case 34:
        gotoxy(52,11);
        printf("Y");
        rotaGlobal.vetPosicao[6]='Y';
        Y1.RotaGeral =6;
        break;

    //---------------------------curva

    case 35:
        gotoxy(52,10);
        printf("Y");
        rotaGlobal.vetPosicao[7]='Y';
        Y1.RotaGeral =7;
        break;
    case 36:
        gotoxy(52,9);
        printf("Y");
        rotaGlobal.vetPosicao[8]='Y';
        Y1.RotaGeral =8;
        break;
    case 37:
        gotoxy(52,8);
        printf("Y");
        rotaGlobal.vetPosicao[9]='Y';
        Y1.RotaGeral =9;
        break;
    case 38:
        gotoxy(52,7);
        printf("Y");
        rotaGlobal.vetPosicao[10]='Y';
        Y1.RotaGeral =10;
        break;
    case 39:
        gotoxy(52,6);
        printf("Y");
        rotaGlobal.vetPosicao[11]='Y';
        Y1.RotaGeral =11;
        break;
    case 40:
        gotoxy(52,5);
        printf("Y");
        rotaGlobal.vetPosicao[12]='Y';
        Y1.RotaGeral =12;
        break;
    //---------------------------curva
    case 41:
        gotoxy(54,5);
        printf("Y");
        rotaGlobal.vetPosicao[13]='Y';
        Y1.RotaGeral =13;
        break;
    case 42:
        gotoxy(56,5);
        printf("Y");
        rotaGlobal.vetPosicao[14]='Y';
        Y1.RotaGeral =14;
        break;
    //-----------------------------
    case 43:
        gotoxy(56,6);
        printf("Y");
        rotaGlobal.vetPosicao[15]='Y';
        Y1.RotaGeral =15;
        break;
    case 44:
        gotoxy(56,7);
        printf("Y");
        rotaGlobal.vetPosicao[16]='Y';
        Y1.RotaGeral =16;
        break;
    case 45:
        gotoxy(56,8);
        printf("Y");
        rotaGlobal.vetPosicao[17]='Y';
        Y1.RotaGeral =17;
        break;
    case 46:
        gotoxy(56,9);
        printf("Y");
        rotaGlobal.vetPosicao[18]='Y';
        Y1.RotaGeral =18;
        break;
    case 47:
        gotoxy(56,10);
        printf("Y");
        rotaGlobal.vetPosicao[19]='Y';
        Y1.RotaGeral =19;
        break;
    case 48:
        gotoxy(56,11);
        printf("Y");
        rotaGlobal.vetPosicao[20]='Y';
        Y1.RotaGeral =20;
        break;
    //---------------------------curva
    case 49:
        gotoxy(58,11);
        printf("Y");
        rotaGlobal.vetPosicao[21]='Y';
        Y1.RotaGeral =21;
        break;
    case 50:
        gotoxy(60,11);
        printf("Y");
        rotaGlobal.vetPosicao[22]='Y';
        Y1.RotaGeral =22;
        break;
    case 51:
        gotoxy(62,11);
        printf("Y");
        rotaGlobal.vetPosicao[23]='Y';
        Y1.RotaGeral =23;
        break;
    case 52:
        gotoxy(64,11);
        printf("Y");
        rotaGlobal.vetPosicao[24]='Y';
        Y1.RotaGeral =24;
        break;
    case 53:
        gotoxy(66,11);
        printf("Y");
        rotaGlobal.vetPosicao[25]='Y';
        Y1.RotaGeral =25;
        break;
    case 54:
        gotoxy(68,11);
        printf("Y");
        rotaGlobal.vetPosicao[26]='Y';
        Y1.RotaGeral =26;
        break;
    //--------------------------------------
    case 55:
        gotoxy(68,12);
        printf("Y");
        rotaGlobal.vetPosicao[27]='Y';
        Y1.RotaGeral =27;
        break;
    //------------------------------------------------------finish
    case 56:
        gotoxy(66,12);
        printf("Y");
        break;
    case 57:
        gotoxy(64,12);
        printf("Y");
        break;
    case 58:
        gotoxy(62,12);
        printf("Y");
        break;
    case 59:
        gotoxy(60,12);
        printf("Y");
        break;
        gotoxy(58,12);
        printf("Y");
    case 60:
        gotoxy(56,12);
        printf("Y");
        break;
    case 61:
        gotoxy(54,12);
        printf("Y");
        break;

    }



}

int Rota_do_G1(int QualPeao)
{

    ColorGreen();
    switch(QualPeao)
    {



    //-----------------------------
    case 1:
        gotoxy(56,6);
        printf("G");
        rotaGlobal.vetPosicao[15]='G';
        G1.RotaGeral =15;
        break;
    case 2:
        gotoxy(56,7);
        printf("G");
        rotaGlobal.vetPosicao[16]='G';
        G1.RotaGeral =16;
        break;
    case 3:
        gotoxy(56,8);
        printf("G");
        rotaGlobal.vetPosicao[17]='G';
        G1.RotaGeral =17;
        break;
    case 4:
        gotoxy(56,9);
        printf("G");
        rotaGlobal.vetPosicao[18]='G';
        G1.RotaGeral =18;
        break;
    case 5:
        gotoxy(56,10);
        printf("G");
        rotaGlobal.vetPosicao[19]='G';
        G1.RotaGeral =19;
        break;
    //-------------------------------
    case 6:
        gotoxy(56,11);
        printf("G");
        rotaGlobal.vetPosicao[20]='G';
        G1.RotaGeral =20;
        break;
    //---------------------------curva
    case 7:
        gotoxy(58,11);
        printf("G");
        rotaGlobal.vetPosicao[21]='G';
        G1.RotaGeral =21;
        break;
    case 8:
        gotoxy(60,11);
        printf("G");
        rotaGlobal.vetPosicao[22]='G';
        G1.RotaGeral =22;
        break;
    case 9:
        gotoxy(62,11);
        printf("G");
        rotaGlobal.vetPosicao[23]='G';
        G1.RotaGeral =23;
        break;
    case 10:
        gotoxy(64,11);
        printf("G");
        rotaGlobal.vetPosicao[24]='G';
        G1.RotaGeral =24;
        break;
    case 11:
        gotoxy(66,11);
        printf("G");
        rotaGlobal.vetPosicao[25]='G';
        G1.RotaGeral =25;
        break;
    case 12:
        gotoxy(68,11);
        printf("G");
        rotaGlobal.vetPosicao[26]='G';
        G1.RotaGeral =26;
        break;
    //--------------------------------------
    case 13:
        gotoxy(68,12);
        printf("G");
        rotaGlobal.vetPosicao[27]='G';
        G1.RotaGeral =27;
        break;
    case 14:
        gotoxy(68,13);
        printf("G");
        rotaGlobal.vetPosicao[28]='G';
        G1.RotaGeral =28;
        break;
    //--------------------------------curva
    case 15:
        gotoxy(66,13);
        printf("G");
        rotaGlobal.vetPosicao[29]='G';
        G1.RotaGeral =29;
        break;
    case 16:
        gotoxy(64,13);
        printf("G");
        rotaGlobal.vetPosicao[30]='G';
        G1.RotaGeral =30;
        break;
    case 17:
        gotoxy(62,13);
        printf("G");
        rotaGlobal.vetPosicao[31]='G';
        G1.RotaGeral =31;
        break;
    case 18:
        gotoxy(60,13);
        printf("G");
        rotaGlobal.vetPosicao[32]='G';
        G1.RotaGeral =32;
        break;
    case 19:
        gotoxy(58,13);
        printf("G");
        rotaGlobal.vetPosicao[33]='G';
        G1.RotaGeral =33;
        break;
    //--------------------------------curva
    case 20:
        gotoxy(56,13);
        printf("G");
        rotaGlobal.vetPosicao[34]='G';
        G1.RotaGeral =34;
        break;
    case 21:
        gotoxy(56,14);
        printf("G");
        rotaGlobal.vetPosicao[35]='G';
        G1.RotaGeral =35;
        break;
    case 22:
        gotoxy(56,15);
        printf("G");
        rotaGlobal.vetPosicao[36]='G';
        G1.RotaGeral =36;
        break;
    case 23:
        gotoxy(56,16);
        printf("G");
        rotaGlobal.vetPosicao[37]='G';
        G1.RotaGeral =37;
        break;
    case 24:
        gotoxy(56,17);
        printf("G");
        rotaGlobal.vetPosicao[38]='G';
        G1.RotaGeral =38;
        break;
    case 25:
        gotoxy(56,18);
        printf("G");
        rotaGlobal.vetPosicao[39]='G';
        G1.RotaGeral =39;
        break;
    case 26:
        gotoxy(56,19);
        printf("G");
        rotaGlobal.vetPosicao[40]='G';
        G1.RotaGeral =40;
        break;
    //--------------------------------curva
    case 27:
        gotoxy(54,19);
        printf("G");
        rotaGlobal.vetPosicao[41]='G';
        G1.RotaGeral =41;
        break;
    case 28:
        gotoxy(52,19);
        printf("G");
        rotaGlobal.vetPosicao[42]='G';
        G1.RotaGeral =42;
        break;
    //--------------------------------up
    case 29:
        gotoxy(52,18);
        printf("G");
        rotaGlobal.vetPosicao[43]='G';
        G1.RotaGeral =43;
        break;
    case 30:
        gotoxy(52,17);
        printf("G");
        rotaGlobal.vetPosicao[44]='G';
        G1.RotaGeral =44;
        break;
    case 31:
        gotoxy(52,16);
        printf("G");
        rotaGlobal.vetPosicao[45]='G';
        G1.RotaGeral =45;
        break;
    case 32:
        gotoxy(52,15);
        printf("G");
        rotaGlobal.vetPosicao[46]='G';
        G1.RotaGeral =46;
        break;
    case 33:
        gotoxy(52,14);
        printf("G");
        rotaGlobal.vetPosicao[47]='G';
        G1.RotaGeral =47;
        break;
    case 35:
        gotoxy(52,13);
        printf("G");
        rotaGlobal.vetPosicao[48]='G';
        G1.RotaGeral =48;
        break;
    //--------------------------------R
    case 34:
        gotoxy(50,13);
        printf("G");
        rotaGlobal.vetPosicao[49]='G';
        G1.RotaGeral =49;
        break;
    case 36:
        gotoxy(48,13);
        printf("G");
        rotaGlobal.vetPosicao[50]='G';
        G1.RotaGeral =50;
        break;
    case 37:
        gotoxy(46,13);
        printf("G");
        rotaGlobal.vetPosicao[51]='G';
        G1.RotaGeral =51;
        break;
    case 38:
        gotoxy(44,13);
        printf("G");
        rotaGlobal.vetPosicao[52]='G';
        G1.RotaGeral =52;
        break;
    case 39:
        gotoxy(42,13);
        printf("G");
        rotaGlobal.vetPosicao[53]='G';
        G1.RotaGeral =53;
        break;
    case 40:
        gotoxy(40,13);
        printf("G");
        rotaGlobal.vetPosicao[54]='G';
        G1.RotaGeral =54;
        break;
    //--------------------------------up
    case 41:
        gotoxy(40,12);
        printf("G");
        rotaGlobal.vetPosicao[55]='G';
        G1.RotaGeral =55;
        break;


    //--------------------------------------- proxima posição vai zerar
    case 42:
        gotoxy(40,11);
        printf("G");
        break;
        rotaGlobal.vetPosicao[0]='G';
        G1.RotaGeral =0;
    case 43:
        gotoxy(42,11);
        printf("G");
        rotaGlobal.vetPosicao[1]='G';
        G1.RotaGeral =1;
        break;
    case 44:
        gotoxy(44,11);
        printf("G");
        rotaGlobal.vetPosicao[2]='G';
        G1.RotaGeral =2;
        break;
    case 45:
        gotoxy(46,11);
        printf("G");
        rotaGlobal.vetPosicao[3]='G';
        G1.RotaGeral =3;
        break;
    case 46:
        gotoxy(48,11);
        printf("G");
        rotaGlobal.vetPosicao[4]='G';
        G1.RotaGeral =4;
        break;
    case 47:
        gotoxy(50,11);
        printf("G");
        rotaGlobal.vetPosicao[5]='G';
        G1.RotaGeral =5;
        break;
    case 48:
        gotoxy(52,11);
        printf("G");
        rotaGlobal.vetPosicao[6]='G';
        G1.RotaGeral =6;
        break;

    //---------------------------curva

    case 49:
        gotoxy(52,10);
        printf("G");
        rotaGlobal.vetPosicao[7]='G';
        G1.RotaGeral =7;
        break;
    case 50:
        gotoxy(52,9);
        printf("G");
        rotaGlobal.vetPosicao[8]='G';
        G1.RotaGeral =8;
        break;
    case 51:
        gotoxy(52,8);
        printf("G");
        rotaGlobal.vetPosicao[9]='G';
        G1.RotaGeral =9;
        break;
    case 52:
        gotoxy(52,7);
        printf("G");
        rotaGlobal.vetPosicao[10]='G';
        G1.RotaGeral =10;
        break;
    case 53:
        gotoxy(52,6);
        printf("G");
        rotaGlobal.vetPosicao[11]='G';
        G1.RotaGeral =11;
        break;
    case 54:
        gotoxy(52,5);
        printf("G");
        rotaGlobal.vetPosicao[12]='G';
        G1.RotaGeral =12;
        break;

    case 55:
        gotoxy(54,5);
        printf("G");
        rotaGlobal.vetPosicao[13]='G';
        G1.RotaGeral =13;
        break;
    //-------------------------------------------------finish


    case 56:
        gotoxy(54,6);
        printf("G");
        break;
    case 57:
        gotoxy(54,7);
        printf("G");
        break;
    case 58:
        gotoxy(54,8);
        printf("G");
        break;
    case 59:
        gotoxy(54,9);
        printf("G");
        break;
    case 60:
        gotoxy(54,10);
        printf("G");
        break;
    case 61:
        gotoxy(54,11);
        printf("G");
        break;
    case 62:
        //----------------
        gotoxy(54,12);
        printf("G");
        break;


    }
}
int Rota_do_B1(int QualPeao)
{
    ColorBlue();


    switch(QualPeao)
    {
    case 1:
        gotoxy(52,18);
        printf("B");
        rotaGlobal.vetPosicao[43]='B';
        B1.RotaGeral =43;
        break;
    case 2:
        gotoxy(52,17);
        printf("B");
        rotaGlobal.vetPosicao[44]='B';
        B1.RotaGeral =44;
        break;
    case 3:
        gotoxy(52,16);
        printf("B");
        rotaGlobal.vetPosicao[45]='B';
        B1.RotaGeral =45;
        break;
    case 4:
        gotoxy(52,15);
        printf("B");
        rotaGlobal.vetPosicao[46]='B';
        B1.RotaGeral =46;
        break;
    case 5:
        gotoxy(52,14);
        printf("B");
        rotaGlobal.vetPosicao[47]='B';
        B1.RotaGeral =47;
        break;
    case 6:
        gotoxy(52,13);
        printf("B");
        rotaGlobal.vetPosicao[48]='B';
        B1.RotaGeral =48;
        break;
    //--------------------------------R
    case 7:
        gotoxy(50,13);
        printf("B");
        rotaGlobal.vetPosicao[49]='B';
        B1.RotaGeral =49;
        break;
    case 8:
        gotoxy(48,13);
        printf("B");
        rotaGlobal.vetPosicao[50]='B';
        B1.RotaGeral =50;
        break;
    case 9:
        gotoxy(46,13);
        printf("B");
        rotaGlobal.vetPosicao[51]='B';
        B1.RotaGeral =51;
        break;
    case 10:
        gotoxy(44,13);
        printf("B");
        rotaGlobal.vetPosicao[52]='B';
        B1.RotaGeral =52;
        break;
    case 11:
        gotoxy(42,13);
        printf("B");
        rotaGlobal.vetPosicao[53]='B';
        B1.RotaGeral =53;
        break;
    case 12:
        gotoxy(40,13);
        printf("B");
        rotaGlobal.vetPosicao[54]='B';
        B1.RotaGeral =54;
        break;
    case 13:
        gotoxy(40,12);
        printf("B");
        rotaGlobal.vetPosicao[55]='B';
        B1.RotaGeral =55;
        break;
    case 14:
        gotoxy(40,11);
        printf("B");
        rotaGlobal.vetPosicao[0]='B';
        B1.RotaGeral =0;
        break;
    //--------------------------------
    case 15:
        gotoxy(42,11);
        printf("B");
        rotaGlobal.vetPosicao[1]='B';
        B1.RotaGeral =1;
        break;
    case 16:
        gotoxy(44,11);
        printf("B");
        rotaGlobal.vetPosicao[2]='B';
        B1.RotaGeral =2;
        break;
    case 17:
        gotoxy(46,11);
        printf("B");
        rotaGlobal.vetPosicao[3]='B';
        B1.RotaGeral =2;
        break;
    case 18:
        gotoxy(48,11);
        printf("B");
        rotaGlobal.vetPosicao[4]='B';
        B1.RotaGeral =2;
        break;
    case 19:
        gotoxy(50,11);
        printf("B");
        rotaGlobal.vetPosicao[5]='B';
        B1.RotaGeral =5;
        break;
    case 20:
        gotoxy(52,11);
        printf("B");
        rotaGlobal.vetPosicao[6]='B';
        B1.RotaGeral =6;
        break;

    //---------------------------curva

    case 21:
        gotoxy(52,10);
        printf("B");
        rotaGlobal.vetPosicao[7]='B';
        B1.RotaGeral =7;
        break;
    case 22:
        gotoxy(52,9);
        printf("B");
        rotaGlobal.vetPosicao[8]='B';
        B1.RotaGeral =8;
        break;
    case 23:
        gotoxy(52,8);
        printf("B");
        rotaGlobal.vetPosicao[9]='B';
        B1.RotaGeral =9;
        break;
    case 24:
        gotoxy(52,7);
        printf("B");
        rotaGlobal.vetPosicao[10]='B';
        B1.RotaGeral =10;
        break;
    case 25:
        gotoxy(52,6);
        printf("B");
        rotaGlobal.vetPosicao[11]='B';
        B1.RotaGeral =11;
        break;
    case 26:
        gotoxy(52,5);
        printf("B");
        rotaGlobal.vetPosicao[12]='B';
        B1.RotaGeral =12;
        break;
    //---------------------------curva
    case 27:
        gotoxy(54,5);
        printf("B");
        rotaGlobal.vetPosicao[13]='B';
        B1.RotaGeral =13;
        break;
    case 28:
        gotoxy(56,5);
        printf("B");
        rotaGlobal.vetPosicao[14]='B';
        B1.RotaGeral =14;
        break;
    //-----------------------------
    case 29:
        gotoxy(56,6);
        printf("B");
        rotaGlobal.vetPosicao[15]='B';
        B1.RotaGeral =15;
        break;
    case 30:
        gotoxy(56,7);
        printf("B");
        rotaGlobal.vetPosicao[16]='B';
        B1.RotaGeral =16;
        break;
    case 31:
        gotoxy(56,8);
        printf("B");
        rotaGlobal.vetPosicao[17]='B';
        B1.RotaGeral =17;
        break;
    case 32:
        gotoxy(56,9);
        printf("B");
        rotaGlobal.vetPosicao[18]='B';
        B1.RotaGeral =18;
        break;
    case 33:
        gotoxy(56,10);
        printf("B");
        rotaGlobal.vetPosicao[19]='B';
        B1.RotaGeral =19;
        break;
    case 34:
        gotoxy(56,11);
        printf("B");
        rotaGlobal.vetPosicao[20]='B';
        B1.RotaGeral =20;
        break;
    //---------------------------curva
    case 35:
        gotoxy(58,11);
        printf("B");
        rotaGlobal.vetPosicao[21]='B';
        B1.RotaGeral =21;
        break;
    case 36:
        gotoxy(60,11);
        printf("B");
        rotaGlobal.vetPosicao[22]='B';
        B1.RotaGeral =22;
        break;
    case 37:
        gotoxy(62,11);
        printf("B");
        rotaGlobal.vetPosicao[23]='B';
        B1.RotaGeral =23;
        break;
    case 38:
        gotoxy(64,11);
        printf("B");
        rotaGlobal.vetPosicao[24]='B';
        B1.RotaGeral =24;
        break;
    case 39:
        gotoxy(66,11);
        printf("B");
        rotaGlobal.vetPosicao[25]='B';
        B1.RotaGeral =25;
        break;
    case 40:
        gotoxy(68,11);
        printf("B");
        rotaGlobal.vetPosicao[26]='B';
        B1.RotaGeral =26;
        break;
    //--------------------------------------
    case 41:
        gotoxy(68,12);
        printf("B");
        rotaGlobal.vetPosicao[27]='B';
        B1.RotaGeral =27;
        break;
    case 42:
        gotoxy(68,13);
        printf("B");
        rotaGlobal.vetPosicao[28]='B';
        B1.RotaGeral =28;
        break;
    //--------------------------------curva
    case 43:
        gotoxy(66,13);
        printf("B");
        rotaGlobal.vetPosicao[29]='B';
        B1.RotaGeral =29;
        break;
    case 44:
        gotoxy(64,13);
        printf("B");
        rotaGlobal.vetPosicao[30]='B';
        B1.RotaGeral =30;
        break;
    case 45:
        gotoxy(62,13);
        printf("B");
        rotaGlobal.vetPosicao[31]='B';
        B1.RotaGeral =31;
        break;
    case 46:
        gotoxy(60,13);
        printf("B");
        rotaGlobal.vetPosicao[32]='B';
        B1.RotaGeral =32;
        break;
    case 47:
        gotoxy(58,13);
        printf("B");
        rotaGlobal.vetPosicao[33]='B';
        B1.RotaGeral =33;
        break;
    //--------------------------------curva
    case 48:
        gotoxy(56,13);
        printf("B");
        rotaGlobal.vetPosicao[34]='B';
        B1.RotaGeral =34;
        break;
    case 49:
        gotoxy(56,14);
        printf("B");
        rotaGlobal.vetPosicao[35]='B';
        B1.RotaGeral =35;
        break;
    case 50:
        gotoxy(56,15);
        printf("B");
        rotaGlobal.vetPosicao[36]='B';
        B1.RotaGeral =36;
        break;
    case 51:
        gotoxy(56,16);
        printf("B");
        rotaGlobal.vetPosicao[37]='B';
        B1.RotaGeral =37;
        break;
    case 52:
        gotoxy(56,17);
        printf("B");
        rotaGlobal.vetPosicao[38]='B';
        B1.RotaGeral =38;
        break;
    case 53:
        gotoxy(56,18);
        printf("B");
        rotaGlobal.vetPosicao[39]='B';
        B1.RotaGeral =39;
        break;
    case 54:
        gotoxy(56,19);
        printf("B");
        rotaGlobal.vetPosicao[40]='B';
        B1.RotaGeral =40;
        break;
    //--------------------------------curva
    case 55:
        gotoxy(54,19);
        printf("B");
        rotaGlobal.vetPosicao[41]='B';
        B1.RotaGeral =41;
        break;
    //------------------------------------------finish
    case 56:
        gotoxy(54,18);
        printf("B");
        break;
    case 57:
        gotoxy(54,17);
        printf("B");
        break;
    case 58:
        gotoxy(54,16);
        printf("B");
        break;
    case 59:
        gotoxy(54,15);
        printf("B");
        break;
    case 60:
        gotoxy(54,14);
        printf("B");
        break;
    case 61:
        gotoxy(54,13);
        printf("B");
        break;
    case 62:
        gotoxy(54,12);
        printf("B");
        break;






    }

    // }
}

int DadoDesenhoVermelho(int x)
{

    ColorWhite();
    int DiceSimbolo =169;
    for(int i=6; i<10; i++) //LIMPA CASA DO VERMELHO
    {
        gotoxy(42,i);
        printf("       ");

    }

    switch(x)
    {

    case 1:
        gotoxy(42,7);
        printf("  %c",DiceSimbolo);
        break;
    case 2:
        gotoxy(42,6);
        printf("%c",DiceSimbolo);
        gotoxy(46,8);
        printf("%c",DiceSimbolo);
        break;
    case 3:
        gotoxy(42,6);
        printf("%c",DiceSimbolo);
        gotoxy(44,7);
        printf("%c",DiceSimbolo);
        gotoxy(46,8);
        printf("%c",DiceSimbolo);
        break;
    case 4:
        gotoxy(42,6);
        printf("%c   %c",DiceSimbolo,DiceSimbolo);
        gotoxy(42,8);
        printf("%c   %c",DiceSimbolo,DiceSimbolo);
        break;
    case 5:
        gotoxy(42,6);
        printf("%c   %c",DiceSimbolo,DiceSimbolo);
        gotoxy(44,7);
        printf("%c",DiceSimbolo);
        gotoxy(42,8);
        printf("%c   %c",DiceSimbolo,DiceSimbolo);

        break;
    case 6:

        gotoxy(42,6);
        printf("%c   %c",DiceSimbolo,DiceSimbolo);
        gotoxy(42,7);
        printf("%c   %c",DiceSimbolo);
        gotoxy(42,8);
        printf("%c   %c",DiceSimbolo,DiceSimbolo);
        break;

    }
}
int DadoDesenhoVerde(int x)
{

    ColorWhite();
    for(int i=6; i<10; i++)
    {
        gotoxy(60,i);
        printf("       ");

    }
    switch(x)
    {
    case 1:
        gotoxy(62,7);
        printf("%c",169);
        break;

    case 2:
        gotoxy(60,6);
        printf("%c",169);
        gotoxy(64,8);
        printf("%c",169);
        break;

    case 3:
        gotoxy(60,6);
        printf("%c",169);
        gotoxy(62,7);
        printf("%c",169);
        gotoxy(64,8);
        printf("%c",169);

        break;

    case 4:
        gotoxy(60,6);
        printf("%c   %c",169,169);
        gotoxy(60,8);
        printf("%c   %c",169,169);
        break;

    case 5:
        gotoxy(60,6); //05
        printf("%c   %c",169,169);
        gotoxy(62,7);
        printf("%c",169);
        gotoxy(60,8);
        printf("%c   %c",169,169);
        break;

    case 6:
        gotoxy(60,6);
        printf("%c   %c",169,169);
        gotoxy(60,7);
        printf("%c   %c",169,169);
        gotoxy(60,8);
        printf("%c   %c",169,169);
        break;
    }
}
int  DadoDesenhoAmarelo(int x)
{

    ColorWhite();
    for(int i=15; i<19; i++)
    {
        gotoxy(60,i);
        printf("       ");

    }

    switch(x)
    {

    case 1:
        gotoxy(62,16);
        printf("%c",169);
        break;
    case 2:
        gotoxy(60,15);
        printf("%c",169);
        gotoxy(64,17);
        printf("%c",169);
        break;
    case 3:
        gotoxy(60,15);
        printf("%c",169);
        gotoxy(62,16);
        printf("%c",169);
        gotoxy(64,17);
        printf("%c",169);
        break;
    case 4:
        gotoxy(60,15);
        printf("%c   %c",169,169);
        gotoxy(60,17);
        printf("%c   %c",169,169);
        break;

    case 5:
        gotoxy(60,15);
        printf("%c   %c",169,169);
        gotoxy(62,16);
        printf("%c",169);
        gotoxy(60,17);
        printf("%c   %c",169,169);
        break;
    case 6:
        gotoxy(60,15);
        printf("%c   %c",169,169);
        gotoxy(60,16);
        printf("%c   %c",169,169);
        gotoxy(60,17);
        printf("%c   %c",169,169);
        break;
    }

}

int DadoDesenhoAzul(int x)
{
    ColorWhite();

    for(int i=15; i<19; i++)
    {
        gotoxy(42,i);
        printf("       ");

    }
    switch(x)
    {
    case 1:
        gotoxy(44,16);
        printf("%c",169);
        break;

    case 2:
        gotoxy(42,15);
        printf("%c",169);
        gotoxy(46,17);
        printf("%c",169);
        break;
    case 3:
        gotoxy(42,15);
        printf("%c",169);
        gotoxy(44,16);
        printf("%c",169);
        gotoxy(46,17);
        printf("%c",169);
        break;
    case 4:
        gotoxy(42,15); //4
        printf("%c   %c",169,169);
        gotoxy(42,17);
        printf("%c   %c",169,169);
        break;
    case 5:
        gotoxy(42,15);
        printf("%c   %c",169,169);
        gotoxy(44,16);
        printf("%c",169);
        gotoxy(42,17);
        printf("%c   %c",169,169);
        break;
    case 6:
        gotoxy(42,15);
        printf("%c   %c",169,169);
        gotoxy(42,16);
        printf("%c   %c",169,169);
        gotoxy(42,17);
        printf("%c   %c",169,169);
        break;
    }

}
void Reset_Mat_Copiadora()
{

    for(int i=0; i<15; i++)
    {
        for(int j=0; j<15; j++)
        {

            mat_copiadora[i][j] = matVazia[i][j];
        }

    }

}

void Show_Matriz_Copiadora()
{
    //----------------------- AJUSTANDO OS FUROS DA MATRIZ

    //--------- base vermelha

    printf("\033[1;31;40m");
    gotoxy(41,5);
    printf("%c %c %c %c %c ",219,219,219,219,219);

    gotoxy(41,10);
    printf("%c %c %c %c %c ",219,219,219,219,219);



    ColorWhite();
    gotoxy(43,6);
    printf("  %c  ",219);
    gotoxy(41,7);
    printf("  %c %c %c ",219,219);
    gotoxy(41,8);
    printf("  %c %c %c ",219,219);
    gotoxy(43,9);
    printf("  %c  ",219);

    //-------------------------------- base verde
    printf("\033[1;32;40m");
    gotoxy(59,5);
    printf("%c %c %c %c %c ",219,219,219,219,219);

    gotoxy(59,10);
    printf("%c %c %c %c %c ",219,219,219,219,219);



    ColorWhite();
    gotoxy(61,6);
    printf("  %c  ",219);
    gotoxy(59,7);
    printf("  %c %c %c ",219,219);
    gotoxy(59,8);
    printf("  %c %c %c ",219,219);
    gotoxy(61,9);
    printf("  %c  ",219);



    //-------------------------------- base amarelo


    printf("\033[2;33;40m");


    gotoxy(59,14);
    printf("%c %c %c %c %c ",219,219,219,219,219);

    gotoxy(59,19);
    printf("%c %c %c %c %c ",219,219,219,219,219);



    ColorWhite();
    gotoxy(61,15);
    printf("  %c  ",219);
    gotoxy(59,16);
    printf("  %c %c %c ",219,219);
    gotoxy(59,17);
    printf("  %c %c %c ",219,219);
    gotoxy(61,18);
    printf("  %c  ",219);


    //-------------------------------- base azul
    // printf("\033[1;34;40m");
    printf("\033[2;34;40m");
    gotoxy(41,14);
    printf("%c %c %c %c %c ",219,219,219,219,219);

    gotoxy(41,19);
    printf("%c %c %c %c %c ",219,219,219,219,219);



    ColorWhite();
    gotoxy(43,15);
    printf("  %c  ",219);
    gotoxy(41,16);
    printf("  %c %c %c ",219,219);
    gotoxy(41,17);
    printf("  %c %c %c ",219,219);
    gotoxy(43,18);
    printf("  %c  ",219);







    //**************************************
    LigarVoltar(ligavolta);
    //*************************************
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    for(int i=0; i<15; i++)
    {
        for(int j=0; j<15; j++)
        {


            if(mat_copiadora[i][j]==3)
            {
                // SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                CorVermelha();

            }
            else if(mat_copiadora[i][j]== 5)
            {
                SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
            }
            else if(mat_copiadora[i][j] == 6)
            {

                SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_BLUE);

            }
            else if(mat_copiadora[i][j] == 1)
            {
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN);
            }

            else if(mat_copiadora[i][j] == CasaRed )
            {
                //SetConsoleTextAttribute(hConsole,FOREGROUND_RED);
                CorVermelha();
            }
            else if(mat_copiadora[i][j]== CasaGreen)
            {
                SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
            }
            else if(mat_copiadora[i][j]== CasaBlue)
            {

                SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_BLUE);

            }
            else if(mat_copiadora[i][j]== CasaYellow)
            {
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN);

            }



            //********************************************************************* paint whit internal house
            else if((i>=1 && i<=4)&&(j>=1 && j<=4))
            {

                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

                if(mat_copiadora[i][j]==82)
                {
                    // SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                    CorVermelha();
                }
            }

            //********************************************************************* paint whit internal house
            else if((i>=1 && i<=4)&&(j>=10 && j<=13))
            {

                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                if(mat_copiadora[i][j]==71)
                {
                    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
                }
            }
            //********************************************************************* paint whit internal house
            else if((i>=10 && i<=13)&&(j>=1 && j<=4))
            {

                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                if(mat_copiadora[i][j]==66)
                {
                    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_BLUE);
                }
            }
            //********************************************************************* paint whit internal house
            else if((i>=10 && i<=13)&&(j>=10 && j<=13))
            {

                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                if(mat_copiadora[i][j]==89)
                {
                    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN);

                }
            }


            //*********************************************************************
            else if(i==6 && j==1)
            {

                // SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                CorVermelha();
                if(mat_copiadora[6][1]=='R')
                {
                    //SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                    CorVermelha();
                }
                else  if(mat_copiadora[6][1]=='Y')
                {
                    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN);
                }
            }
            else if(i==7 &&j>=1 &&j<=6)
            {
                // SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                CorVermelha();
            }
            //*********************************************************************
            else if(i==1 && j==8)
            {
                SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
                if(mat_copiadora[1][8]=='R')
                {
                    //  SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                    CorVermelha();
                }
                else  if(mat_copiadora[1][8]=='Y')
                {
                    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN);
                }
            }
            else if(i>=1 && j==7 &&i<=6)
            {
                SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
            }
            //*********************************************************************
            else if(i==8 && j==13)
            {
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN);
                if(mat_copiadora[8][13]=='R')
                {
                    // SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                    CorVermelha();
                }
                else  if(mat_copiadora[8][13]=='Y')
                {
                    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN);
                }
            }
            else if(i==7 && j>=8 && j<=13)
            {
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN);
            }
            //*********************************************************************
            else if(i==13 && j==6)
            {

                SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_BLUE);
                if(mat_copiadora[13][6]=='R')
                {
                    SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                }
                else  if(mat_copiadora[13][6]=='Y')
                {
                    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN);
                }

            }
            else if(j==7 && i<=13 && i>=8)
            {
                //  SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
                SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_BLUE);

            }

            //*********************************************************************

            else if(i<=5 && j <=5)
            {
                // SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                CorVermelha();

            }
            //*********************************************************************
            else if(i<=5 && j>=9)
            {
                SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
            }

            //*********************************************************************
            else if(i>=9 && j<=5)
            {
                SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_BLUE);
            }
            //*********************************************************************
            else if(i>=9&& j>=9)
            {
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN);
            }

            //*********************************************************************


            //************************************************************************movientation caracter color
            else if(mat_copiadora[i][j]==82)
            {
                //SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                CorVermelha();
            }
            else if(mat_copiadora[i][j]==71)
            {
                SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
            }
            else if(mat_copiadora[i][j]==66)
            {
                SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_BLUE);
            }
            else if(mat_copiadora[i][j]==89)
            {
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN);

            }



            else
            {
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            }


            int x_atual = x + j * 2;
            int y_atual = y + i;


            gotoxy(x_atual, y_atual);

            printf("%c",mat_copiadora[i][j]);
        }
        printf("\n");
    }





}
void Matriz_Vazia()
{


    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);


    simbolo_trilha = 254;
    Player01_heart = 82;
    Player02_wood  = 71;
    Player03_sword = 66;
    Player04_smile = 89;
    CasaRed = 219;//219
    CasaGreen = 219;//219
    CasaBlue = 219;//219
    CasaYellow =219;//219


    for(int i=0; i<15; i++)
    {
        for(int j=0; j<15; j++)
        {
            matVazia[i][j]=' ';
            matVazia[7][7] = 'X';
        }

    }


    // MATRIZ LADO VERMELHO

    char vazio =' ';

    for(int i=0; i<6; i++)
    {
        for(int j=0; j<6; j++)
        {
            matVazia[i][j] = CasaRed;


        }

    }
    matVazia[1][1] =' ';
    matVazia[1][4] = ' ';
    matVazia[4][1] = ' ';
    matVazia[4][4] =' ';


    //TRILHA VERMELHA

    matVazia[6][1] = simbolo_trilha;
    matVazia[7][1] = simbolo_trilha;
    matVazia[7][2] = simbolo_trilha;
    matVazia[7][3] = simbolo_trilha;
    matVazia[7][4] = simbolo_trilha;
    matVazia[7][5] = simbolo_trilha;
    matVazia[7][6] = simbolo_trilha;

    //MATRIZ LADO VERDE

    for(int i=0; i<6; i++)
    {
        for(int j=9; j<15; j++)
        {
            matVazia[i][j] = CasaGreen;
        }
        printf("\n");
    }
    matVazia[1][10] = ' ';
    matVazia[1][13] = ' ';
    matVazia[4][10] = ' ';
    matVazia[4][13] = ' ';

    //TRILHA VERDE

    matVazia[1][8] = simbolo_trilha;
    matVazia[1][7] = simbolo_trilha;
    matVazia[2][7] = simbolo_trilha;
    matVazia[3][7] = simbolo_trilha;
    matVazia[4][7] = simbolo_trilha;
    matVazia[5][7] = simbolo_trilha;
    matVazia[6][7] = simbolo_trilha;

    //MATRIZ LADO AMARELO

    for(int i=9; i<15; i++)
    {
        for(int j=9; j<15; j++)
        {
            matVazia[i][j] = CasaYellow;
        }

    }
    matVazia[10][10] = ' ';
    matVazia[10][13] = ' ';
    matVazia[13][10] = ' ';
    matVazia[13][13] = ' ';

    //TRILHA AMARELO
    matVazia[8][13] = simbolo_trilha;
    matVazia[7][13] = simbolo_trilha;
    matVazia[7][12] = simbolo_trilha;
    matVazia[7][11] = simbolo_trilha;
    matVazia[7][10] = simbolo_trilha;
    matVazia[7] [9] = simbolo_trilha;
    matVazia[7] [8] = simbolo_trilha;

    //MATRIZ LADO AZUL
    for(int i=9; i<15; i++)
    {
        for(int j=0; j<6; j++)
        {
            matVazia[i][j] = CasaBlue;
        }

    }
    matVazia[10][1] = ' ';
    matVazia[10][4] = ' ';
    matVazia[13][1] = ' ';
    matVazia[13][4] = ' ';

    //TRILHA AZUL
    matVazia[13][6] = simbolo_trilha;
    matVazia[13][7] = simbolo_trilha;
    matVazia[12][7] = simbolo_trilha;
    matVazia[11][7] = simbolo_trilha;
    matVazia[10][7] = simbolo_trilha;
    matVazia[9] [7] = simbolo_trilha;
    matVazia[8] [7] = simbolo_trilha;


}

//-----------------------------------------------------------------------------

void DadoGeral()
{
    Beep(500,50);
    srand(time(NULL));

    RollDiceGme =(rand()%6)+1;


}
int MascaraRed(int x)
{

    CorVermelha();


    gotoxy(42,6); //r1
    printf("R");
    gotoxy(48,6); //r2
    printf("R");
    gotoxy(42,9); //r3
    printf("R");
    gotoxy(48,9); //r4
    printf("R");


    switch(x)
    {
    case 1:
        gotoxy(42,6); //r1
        printf(" ");
        break;
    case 2:
        gotoxy(42,6); //r1
        printf(" ");
        gotoxy(48,6); //r2
        printf(" ");
        break;
    case 3:
        gotoxy(42,6); //r1
        printf(" ");
        gotoxy(48,6); //r2
        printf(" ");
        gotoxy(42,9); //r3
        printf(" ");
        break;
    case 4:
        gotoxy(42,6); //r1
        printf(" ");
        gotoxy(48,6); //r2
        printf(" ");
        gotoxy(42,9); //r3
        printf(" ");
        gotoxy(48,9); //r4
        printf(" ");
        break;
    }

}
int MascaraGreen(int x)
{
    ColorGreen();

    gotoxy(60,6); //G1
    printf("G");
    gotoxy(66,6); //G2
    printf("G");
    gotoxy(60,9); //G3
    printf("G");
    gotoxy(66,9); //G4
    printf("G");

    switch(x)
    {
    case 1:
        gotoxy(60,6); //G1
        printf(" ");
        break;
    case 2:
        gotoxy(60,6); //G1
        printf(" ");
        gotoxy(66,6); //G2
        printf(" ");
        break;
    case 3:
        gotoxy(60,6); //G1
        printf(" ");
        gotoxy(66,6); //G2
        printf(" ");
        gotoxy(60,9); //G3
        printf(" ");
        break;

    case 4:
        gotoxy(60,6); //G1
        printf(" ");
        gotoxy(66,6); //G2
        printf(" ");
        gotoxy(60,9); //G3
        printf(" ");
        gotoxy(66,9); //G4
        printf(" ");
        break;
    }
}
int MascaraYellow(int x)
{
    ColorYellow();
    gotoxy(60,15); //y1
    printf("Y");
    gotoxy(66,15); //y2
    printf("Y");
    gotoxy(60,18); //y3
    printf("Y");
    gotoxy(66,18); //y4
    printf("Y");

    switch(x)
    {
    case 1:
        gotoxy(60,15); //y1
        printf(" ");
        break;
    case 2:
        gotoxy(60,15); //y1
        printf(" ");
        gotoxy(66,15); //y2
        printf(" ");
        break;
    case 3:
        gotoxy(60,15); //y1
        printf(" ");
        gotoxy(66,15); //y2
        printf(" ");
        gotoxy(60,18); //y3
        printf(" ");
        break;
    case 4:
        gotoxy(60,15); //y1
        printf(" ");
        gotoxy(66,15); //y2
        printf(" ");
        gotoxy(60,18); //y3
        printf(" ");
        gotoxy(66,18); //y4
        printf(" ");
        break;
    }
}
int MascaraBlue(int x)
{

    ColorBlue();

    gotoxy(42,15); //y1
    printf("B");
    gotoxy(48,15); //y2
    printf("B");
    gotoxy(48,18); //y3
    printf("B");
    gotoxy(42,18); //y4
    printf("B");
    switch(x)
    {
    case 1:
        gotoxy(42,15); //y1
        printf(" ");
        break;
    case 2:
        gotoxy(42,15); //y1
        printf(" ");
        gotoxy(48,15); //y2
        printf(" ");
        break;
    case 3:
        gotoxy(42,15); //y1
        printf(" ");
        gotoxy(48,15); //y2
        printf(" ");
        gotoxy(48,18); //y3
        printf(" ");
        break;
    case 4:
        gotoxy(42,15); //y1
        printf(" ");
        gotoxy(48,15); //y2
        printf(" ");
        gotoxy(48,18); //y3
        printf(" ");
        gotoxy(42,18); //y4
        printf(" ");
        break;
    }
}

void TrilhaFogo()
{
    gotoxy(58,11);
    ColorYellow();
    printf(" %c",207);


    gotoxy(50,13);
    ColorYellow();
    printf(" %c",207);
}
void Demostrativo()
{
    gotoxy(40,21);
    ColorBlue();
    printf("Robo02");

    gotoxy(60,3);
    ColorGreen();
    printf("Robo01");

    gotoxy(40,3);
    CorVermelha();
    printf("%s",login);

    gotoxy(60,21);
    ColorYellow();
    printf("%s",login2);


    gotoxy(47,25);
    ColorYellow();
    printf("...LUDO");
    gotoxy(54,25);
    CorVermelha();
    printf("FIRE...");



    gotoxy(76,25);
    ColorWhite();
    printf("VOLTA [%c]",254);
}
void AguardaVitoria()
{
    int x =82;
    gotoxy(x,3);
    ColorAzulAgua();
    printf(" FINAL\n");

    // printf("\033[6;38;45m");
    gotoxy(x,5);
    printf("%c%c%c%c%c%c%c\n", 201, 205, 205, 205, 205, 205, 187);
    gotoxy(x,6);
    printf("%c  R  %c\n", 186, 186);
    gotoxy(x,7);
    printf("%c  %i  %c\n", 186,R1.chegada,186);
    gotoxy(x,8);
    printf("%c%c%c%c%c%c%c\n", 200, 205, 205, 205, 205, 205, 188);

    gotoxy(x,9);
    printf("%c%c%c%c%c%c%c\n", 201, 205, 205, 205, 205, 205, 187);
    gotoxy(x,10);
    printf("%c  G  %c\n", 186, 186);
    gotoxy(x,11);
    printf("%c  %i  %c\n", 186,G1.chegada,186);
    gotoxy(x,12);
    printf("%c%c%c%c%c%c%c\n", 200, 205, 205, 205, 205, 205, 188);

    gotoxy(90,5);
    printf("%c%c%c%c%c%c%c\n", 201, 205, 205, 205, 205, 205, 187);
    gotoxy(90,6);
    printf("%c  Y  %c\n", 186, 186);
    gotoxy(90,7);
    printf("%c  %i  %c\n", 186,Y1.chegada,186);
    gotoxy(90,8);
    printf("%c%c%c%c%c%c%c\n", 200, 205, 205, 205, 205, 205, 188);

    gotoxy(90,9);
    printf("%c%c%c%c%c%c%c\n", 201, 205, 205, 205, 205, 205, 187);
    gotoxy(90,10);
    printf("%c  B  %c\n", 186, 186);
    gotoxy(90,11);
    printf("%c  %i  %c\n", 186,B1.chegada,186);
    gotoxy(90,12);
    printf("%c%c%c%c%c%c%c\n", 200, 205, 205, 205, 205, 205, 188);
}
void VoltarBase()
{
    if(R1.AcumuladorDeGiro ==11 || R1.AcumuladorDeGiro==38)
    {
        Beep(700,1000);
        R1.AcumuladorDeGiro=0;
        gotoxy(76,25);
        CorVermelha();
        printf("VOLTA [%c]",254);
        R1.mascara=0;
        if(R1.killPeao >0)
        {
            R1.mascara +=R1.killPeao;
        }

        R1.saida =0;




    }
    else  if(G1.AcumuladorDeGiro ==24 || G1.AcumuladorDeGiro==53)
    {
        Beep(700,1000);
        G1.AcumuladorDeGiro=0;
        gotoxy(76,25);
        ColorGreen();
        printf("VOLTA [%c]",254);
        G1.mascara =0;
        if(G1.killPeao >0)
        {
            G1.mascara +=G1.killPeao;
        }

        G1.saida =0;




    }
    else if(Y1.AcumuladorDeGiro ==10 || Y1.AcumuladorDeGiro==39)
    {
        Beep(700,1000);
        Y1.AcumuladorDeGiro=0;
        gotoxy(76,25);
        ColorYellow();
        printf("VOLTA [%c]",254);
        Y1.mascara=0;
        if(Y1.killPeao >0)
        {
            Y1.mascara +=Y1.killPeao;
        }

        Y1.saida =0;




    }
    else  if(B1.AcumuladorDeGiro ==25 || B1.AcumuladorDeGiro==52)
    {
        Beep(700,1000);
        B1.AcumuladorDeGiro=0;
        gotoxy(76,25);
        ColorBlue();
        printf("VOLTA [%c]",254);
        B1.mascara=0;
        if(B1.killPeao >0)
        {
            B1.mascara +=B1.killPeao;
        }

        B1.saida =0;




    }
}
void CasaFire()
{

    if(R1.AcumuladorDeGiro ==22 || R1.AcumuladorDeGiro ==49)
    {
        // R1.mascara+=1;
        R1.killPeao+=1;
        Fogo();
        Demostrativo();
    }
    else if(G1.AcumuladorDeGiro ==7 || G1.AcumuladorDeGiro ==35)
    {
        //G1.mascara+=1;
        G1.killPeao+=1;
        Fogo();
        Demostrativo();
    }
    else if(Y1.AcumuladorDeGiro ==21 || Y1.AcumuladorDeGiro ==50)
    {
        //Y1.mascara+=1;
        Y1.killPeao+=1;
        Fogo();
        Demostrativo();
    }
    else if(B1.AcumuladorDeGiro ==7 || B1.AcumuladorDeGiro ==36)
    {
        // B1.mascara+=1;
        B1.killPeao+=1;
        Fogo();
        Demostrativo();
    }

}
void BlocoDaVezR()
{
    CorVermelha();

    gotoxy(30,24);
    printf("%c%c%c%c%c\n", 201, 205,  205, 205, 187);
    gotoxy(30,25);
    printf("%c R %c\n",186,186);
    gotoxy(30,26);
    printf("%c%c%c%c%c\n", 200,  205, 205, 205, 188);
}
void BlocoDaVezG()
{
    ColorGreen();

    gotoxy(30,24);
    printf("%c%c%c%c%c\n", 201, 205,  205, 205, 187);
    gotoxy(30,25);
    printf("%c G %c\n", 186,186);
    gotoxy(30,26);
    printf("%c%c%c%c%c\n", 200,  205, 205, 205, 188);
}
void BlocoDaVezY()
{
    ColorYellow();

    gotoxy(30,24);
    printf("%c%c%c%c%c\n", 201, 205,  205, 205, 187);
    gotoxy(30,25);
    printf("%c Y %c\n", 186,186);
    gotoxy(30,26);
    printf("%c%c%c%c%c\n", 200,  205, 205, 205, 188);
}
void BlocoDaVezB()
{
    ColorBlue();

    gotoxy(30,24);
    printf("%c%c%c%c%c\n", 201, 205,  205, 205, 187);
    gotoxy(30,25);
    printf("%c B %c\n", 186,186);
    gotoxy(30,26);
    printf("%c%c%c%c%c\n", 200,  205, 205, 205, 188);
}
int  BarLifeGreen(int x)
{

    switch(x)
    {
    case 0:
        gotoxy(74,8);
        ColorAzulAgua();
        printf("100\%%");
        gotoxy(72,10);
        printf("%c %c %c %c ",219,219,219,219);
        ColorGreen();
        gotoxy(71,9); //jogador verde  67--23
        printf("%c%c%c%c%c%c%c%c%c%C\n", 201, 205, 205, 205,205,205,205, 205, 205, 187);
        gotoxy(71,10);
        printf("%c\n", 186);
        gotoxy(80,10);
        printf("%c\n", 186);
        gotoxy(71,11);
        printf("%c%c%c%c%c%c%c%c%c%C\n", 200, 205, 205, 205,205,205,205, 205, 205, 188);
        break;
    case 1:
        gotoxy(74,8);
        ColorAzulAgua();
        printf("75\%%");
        gotoxy(72,10);
        printf("%c %c %c  ",219,219,219);
        ColorGreen();
        gotoxy(71,9); //jogador verde
        printf("%c%c%c%c%c%c%c%c%c%C\n", 201, 205, 205, 205,205,205,205, 205, 205, 187);
        gotoxy(71,10);
        printf("%c\n", 186);
        gotoxy(80,10);
        printf("%c\n", 186);
        gotoxy(71,11);
        printf("%c%c%c%c%c%c%c%c%c%C\n", 200, 205, 205, 205,205,205,205, 205, 205, 188);
        break;
    case 2:
        gotoxy(74,8);
        ColorAzulAgua();
        printf("50\%%");
        gotoxy(72,10);
        printf("%c %c  ",219,219);
        ColorGreen();
        gotoxy(71,9); //jogador verde
        printf("%c%c%c%c%c%c%c%c%c%C\n", 201, 205, 205, 205,205,205,205, 205, 205, 187);
        gotoxy(71,10);
        printf("%c\n", 186);
        gotoxy(80,10);
        printf("%c\n", 186);
        gotoxy(71,11);
        printf("%c%c%c%c%c%c%c%c%c%C\n", 200, 205, 205, 205,205,205,205, 205, 205, 188);
        break;
    case 3:
        gotoxy(74,8);
        ColorAzulAgua();
        printf("25\%%");
        gotoxy(72,10);
        CorVermelha();
        printf("%c ",219);
        ColorGreen();
        gotoxy(71,9); //jogador verde
        printf("%c%c%c%c%c%c%c%c%c%C\n", 201, 205, 205, 205,205,205,205, 205, 205, 187);
        gotoxy(71,10);
        printf("%c\n", 186);
        gotoxy(80,10);
        printf("%c\n", 186);
        gotoxy(71,11);
        printf("%c%c%c%c%c%c%c%c%c%C\n", 200, 205, 205, 205,205,205,205, 205, 205, 188);
        break;
    case 4:
        gotoxy(74,8);
        ColorAzulAgua();
        printf("0\%%");
        gotoxy(72,10);
        printf(" ");
        ColorGreen();
        gotoxy(71,9); //jogador verde
        printf("%c%c%c%c%c%c%c%c%c%C\n", 201, 205, 205, 205,205,205,205, 205, 205, 187);
        gotoxy(71,10);
        printf("%cDERROTA\n", 186);
        gotoxy(80,10);
        printf("%c\n", 186);
        gotoxy(71,11);
        printf("%c%c%c%c%c%c%c%c%c%C\n", 200, 205, 205, 205,205,205,205, 205, 205, 188);
        break;

    }

    //--------------------------------------------------------------------------------------------------------------
}
int  BarLifeYellow(int x)
{


    switch(x)
    {
    case 0:

        gotoxy(74,16); //yellow
        ColorAzulAgua();
        printf("100\%%");
        gotoxy(72,18);
        printf("%c %c %c %c ",219,219,219,219);

        ColorYellow();
        gotoxy(71,17);
        printf("%c%c%c%c%c%c%c%c%c%C\n", 201, 205, 205, 205,205,205,205, 205, 205, 187);
        gotoxy(71,18);
        printf("%c\n", 186);
        gotoxy(80,18);
        printf("%c\n", 186);
        gotoxy(71,19);
        printf("%c%c%c%c%c%c%c%c%c%C\n", 200, 205, 205, 205,205,205,205, 205, 205, 188);
        break;
    case 1:

        gotoxy(74,16); //yellow
        ColorAzulAgua();
        printf("75\%%");
        gotoxy(72,18);
        printf("%c %c %c ",219,219,219);

        ColorYellow();
        gotoxy(71,17);
        printf("%c%c%c%c%c%c%c%c%c%C\n", 201, 205, 205, 205,205,205,205, 205, 205, 187);
        gotoxy(71,18);
        printf("%c\n", 186);
        gotoxy(80,18);
        printf("%c\n", 186);
        gotoxy(71,19);
        printf("%c%c%c%c%c%c%c%c%c%C\n", 200, 205, 205, 205,205,205,205, 205, 205, 188);
        break;
    case 2:

        gotoxy(74,16); //yellow
        ColorAzulAgua();
        printf("50\%%");
        gotoxy(72,18);
        printf("%c %c  ",219,219);

        ColorYellow();
        gotoxy(71,17);
        printf("%c%c%c%c%c%c%c%c%c%C\n", 201, 205, 205, 205,205,205,205, 205, 205, 187);
        gotoxy(71,18);
        printf("%c\n", 186);
        gotoxy(80,18);
        printf("%c\n", 186);
        gotoxy(71,19);
        printf("%c%c%c%c%c%c%c%c%c%C\n", 200, 205, 205, 205,205,205,205, 205, 205, 188);
        break;
    case 3:

        gotoxy(74,16); //yellow
        ColorAzulAgua();
        printf("25\%%");
        gotoxy(72,18);
        CorVermelha();
        printf("%c ",219);

        ColorYellow();
        gotoxy(71,17);
        printf("%c%c%c%c%c%c%c%c%c%C\n", 201, 205, 205, 205,205,205,205, 205, 205, 187);
        gotoxy(71,18);
        printf("%c\n", 186);
        gotoxy(80,18);
        printf("%c\n", 186);
        gotoxy(71,19);
        printf("%c%c%c%c%c%c%c%c%c%C\n", 200, 205, 205, 205,205,205,205, 205, 205, 188);
        break;
    case 4:

        gotoxy(74,16); //yellow
        ColorAzulAgua();
        printf("0\%%");
        gotoxy(72,18);
        printf(" ");

        ColorYellow();
        gotoxy(71,17);
        printf("%c%c%c%c%c%c%c%c%c%C\n", 201, 205, 205, 205,205,205,205, 205, 205, 187);
        gotoxy(71,18);
        printf("%cDERROTA\n", 186);
        gotoxy(80,18);
        printf("%c\n", 186);
        gotoxy(71,19);
        printf("%c%c%c%c%c%c%c%c%c%C\n", 200, 205, 205, 205,205,205,205, 205, 205, 188);
        break;
    }

}
int  BarLifeBlue(int x)
{
    switch(x)
    {
    case 0:
        gotoxy(74,12); //blue
        ColorAzulAgua();
        printf("100\%%");
        gotoxy(72,14);
        printf("%c %c %c %c ",219,219,219,219);

        ColorBlue();
        gotoxy(71,13);
        printf("%c%c%c%c%c%c%c%c%c%C\n", 201, 205, 205, 205,205,205,205, 205, 205, 187);
        gotoxy(71,14);
        printf("%c\n", 186);
        gotoxy(80,14);
        printf("%c\n", 186);
        gotoxy(71,15);
        printf("%c%c%c%c%c%c%c%c%c%C\n", 200, 205, 205, 205,205,205,205, 205, 205, 188);

        break;
    case 1:
        gotoxy(74,12); //blue
        ColorAzulAgua();
        printf("75\%%");
        gotoxy(72,14);
        printf("%c %c %c  ",219,219,219);

        ColorBlue();
        gotoxy(71,13);
        printf("%c%c%c%c%c%c%c%c%c%C\n", 201, 205, 205, 205,205,205,205, 205, 205, 187);
        gotoxy(71,14);
        printf("%c\n", 186);
        gotoxy(80,14);
        printf("%c\n", 186);
        gotoxy(71,15);
        printf("%c%c%c%c%c%c%c%c%c%C\n", 200, 205, 205, 205,205,205,205, 205, 205, 188);

        break;
    case 2:
        gotoxy(74,12); //blue
        ColorAzulAgua();
        printf("50\%%");
        gotoxy(72,14);
        printf("%c %c  ",219,219,219,219);

        ColorBlue();
        gotoxy(71,13);
        printf("%c%c%c%c%c%c%c%c%c%C\n", 201, 205, 205, 205,205,205,205, 205, 205, 187);
        gotoxy(71,14);
        printf("%c\n", 186);
        gotoxy(80,14);
        printf("%c\n", 186);
        gotoxy(71,15);
        printf("%c%c%c%c%c%c%c%c%c%C\n", 200, 205, 205, 205,205,205,205, 205, 205, 188);

        break;
    case 3:
        gotoxy(74,12); //blue
        ColorAzulAgua();
        printf("25\%%");
        gotoxy(72,14);
        CorVermelha();
        printf("%c ",219);

        ColorBlue();
        gotoxy(71,13);
        printf("%c%c%c%c%c%c%c%c%c%C\n", 201, 205, 205, 205,205,205,205, 205, 205, 187);
        gotoxy(71,14);
        printf("%c\n", 186);
        gotoxy(80,14);
        printf("%c\n", 186);
        gotoxy(71,15);
        printf("%c%c%c%c%c%c%c%c%c%C\n", 200, 205, 205, 205,205,205,205, 205, 205, 188);

        break;
    case 4:
        gotoxy(74,12); //blue
        ColorAzulAgua();
        printf("0\%%");
        gotoxy(72,14);
        printf(" ");

        ColorBlue();
        gotoxy(71,13);
        printf("%c%c%c%c%c%c%c%c%c%C\n", 201, 205, 205, 205,205,205,205, 205, 205, 187);
        gotoxy(71,14);
        printf("%cDERROTA\n", 186);
        gotoxy(80,14);
        printf("%c\n", 186);
        gotoxy(71,15);
        printf("%c%c%c%c%c%c%c%c%c%C\n", 200, 205, 205, 205,205,205,205, 205, 205, 188);

        break;
    }
}
int  BarLifeRed(int x)
{



    switch(x)
    {
    case 0:
        gotoxy(74,4);
        ColorAzulAgua();
        printf("100\%%");
        gotoxy(72,6);
        printf("%c %c %c %c ",219,219,219,219);

        CorVermelha();
        gotoxy(71,5); //jogador vermelho
        printf("%c%c%c%c%c%c%c%c%c%C\n", 201, 205, 205, 205,205,205,205, 205, 205, 187);
        gotoxy(71,6);
        printf("%c\n",186);
        gotoxy(80,6);
        printf("%c\n",186);
        gotoxy(71,7);
        printf("%c%c%c%c%c%c%c%c%c%C\n", 200, 205, 205, 205,205,205,205, 205, 205, 188);
        break;
    case 1:
        gotoxy(74,4);
        ColorAzulAgua();
        printf("75\%%");
        gotoxy(72,6);
        printf("%c %c %c  ",219,219,219);

        CorVermelha();
        gotoxy(71,5); //jogador vermelho
        printf("%c%c%c%c%c%c%c%c%c%C\n", 201, 205, 205, 205,205,205,205, 205, 205, 187);
        gotoxy(71,6);
        printf("%c\n",186);
        gotoxy(80,6);
        printf("%c\n",186);
        gotoxy(71,7);
        printf("%c%c%c%c%c%c%c%c%c%C\n", 200, 205, 205, 205,205,205,205, 205, 205, 188);
        break;
    case 2:
        gotoxy(74,4);
        ColorAzulAgua();
        printf("50\%%");
        gotoxy(72,6);
        printf("%c %c    ",219,219);

        CorVermelha();
        gotoxy(71,5); //jogador vermelho
        printf("%c%c%c%c%c%c%c%c%c%C\n", 201, 205, 205, 205,205,205,205, 205, 205, 187);
        gotoxy(71,6);
        printf("%c\n",186);
        gotoxy(80,6);
        printf("%c\n",186);
        gotoxy(71,7);
        printf("%c%c%c%c%c%c%c%c%c%C\n", 200, 205, 205, 205,205,205,205, 205, 205, 188);
        break;
    case 3:
        gotoxy(74,4);
        ColorAzulAgua();

        printf("25\%%");
        gotoxy(72,6);
        CorVermelha();
        printf("%c      ",219);

        CorVermelha();
        gotoxy(71,5); //jogador vermelho
        printf("%c%c%c%c%c%c%c%c%c%C\n", 201, 205, 205, 205,205,205,205, 205, 205, 187);
        gotoxy(71,6);
        printf("%c\n",186);
        gotoxy(80,6);
        printf("%c\n",186);
        gotoxy(71,7);
        printf("%c%c%c%c%c%c%c%c%c%C\n", 200, 205, 205, 205,205,205,205, 205, 205, 188);
        break;
    case 4:
        gotoxy(72,4);
        ColorAzulAgua();
        printf("0\%%");
        gotoxy(72,6);
        printf("        ");

        CorVermelha();
        gotoxy(71,5); //jogador vermelho
        printf("%c%c%c%c%c%c%c%c%c%C\n", 201, 205, 205, 205,205,205,205, 205, 205, 187);
        gotoxy(71,6);
        printf("%cDERROTA\n",186);
        gotoxy(80,6);
        printf("%c\n",186);
        gotoxy(71,7);
        printf("%c%c%c%c%c%c%c%c%c%C\n", 200, 205, 205, 205,205,205,205, 205, 205, 188);
        break;




    }



}
void QuadroDesing()
{

    // ColorAzulAgua();
    printf("\033[1;36;40m");
    int x =70;

    gotoxy(100,3);
    printf("%c",187);
    gotoxy(x,3);
    printf("%c",201);

    gotoxy(x,4);
    printf("%c                             %c",186,186);
    gotoxy(x,5);
    printf("%c                             %c",186,186);
    gotoxy(x,6);
    printf("%c                             %c",186,186);
    gotoxy(x,7);
    printf("%c                             %c",186,186);
    gotoxy(x,8);
    printf("%c                             %c",186,186);
    gotoxy(x,9);
    printf("%c                             %c",186,186);
    gotoxy(x,10);
    printf("%c                             %c",186,186);
    gotoxy(x,11);
    printf("%c                             %c",186,186);
    gotoxy(x,12);
    printf("%c                             %c",186,186);
    gotoxy(x,13);
    printf("%c                             %c",186,186);
    gotoxy(x,14);
    printf("%c                             %c",186,186);
    gotoxy(x,15);
    printf("%c                             %c",186,186);
    gotoxy(x,16);
    printf("%c                             %c",186,186);
    gotoxy(x,17);
    printf("%c                             %c",186,186);
    gotoxy(x,18);
    printf("%c                             %c",186,186);
    gotoxy(x,19);
    printf("%c                             %c",186,186);



    gotoxy(100,20);
    printf("%c",188);
    gotoxy(70,20);
    printf("%c",200);

    gotoxy(71,3);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205);

    gotoxy(71,20);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205);

    GraficoDeRota();


}
GraficoDeRota()
{

    gotoxy(86,14);
    printf("Runners");


    //...............................................................................red....
    if(R1.AcumuladorDeGiro<10)
    {
        CorVermelha();
        gotoxy(84,16);
        printf("-%c---------",184);
    }
    else if(R1.AcumuladorDeGiro>10 && R1.AcumuladorDeGiro<25)
    {
        CorVermelha();
        gotoxy(84,16);
        printf("---%c-------",184);
    }
    else if(R1.AcumuladorDeGiro>25 && R1.AcumuladorDeGiro<45)
    {
        CorVermelha();
        gotoxy(84,16);
        printf("-------%c---",184);
    }
    else if(R1.AcumuladorDeGiro>45 && R1.AcumuladorDeGiro<55)
    {
        CorVermelha();
        gotoxy(84,16);
        printf("----------%c",184);
    }
    else if(R1.AcumuladorDeGiro>57 && R1.AcumuladorDeGiro<1000)
    {
        CorVermelha();
        gotoxy(84,16);
        printf("----------%c",184);

    }

    //............................................................................green.......

    if(G1.AcumuladorDeGiro<10)
    {
        ColorGreen();
        gotoxy(84,17);
        printf("-%c---------",184);
    }
    else if(G1.AcumuladorDeGiro>10 && G1.AcumuladorDeGiro<25)
    {
        ColorGreen();
        gotoxy(84,17);
        printf("---%c-------",184);
    }
    else if(G1.AcumuladorDeGiro>25 && G1.AcumuladorDeGiro<45)
    {
        ColorGreen();
        gotoxy(84,17);
        printf("-------%c---",184);
    }
    else if(G1.AcumuladorDeGiro>45 && G1.AcumuladorDeGiro<55)
    {
        ColorGreen();
        gotoxy(84,17);
        printf("----------%c",184);
    }
    else if(G1.AcumuladorDeGiro>57 && G1.AcumuladorDeGiro<1000)
    {
        ColorGreen();
        gotoxy(84,17);
        printf("----------%c",184);

    }

    //............................................................................yellow.......
    if(Y1.AcumuladorDeGiro<10)
    {
        ColorYellow();
        gotoxy(84,18);
        printf("-%c---------",184);
    }
    else if(Y1.AcumuladorDeGiro>10 && Y1.AcumuladorDeGiro<25)
    {
        ColorYellow();
        gotoxy(84,18);
        printf("---%c-------",184);
    }
    else if(Y1.AcumuladorDeGiro>25 && Y1.AcumuladorDeGiro<45)
    {
        ColorYellow();
        gotoxy(84,18);
        printf("-------%c---",184);
    }
    else if(Y1.AcumuladorDeGiro>45 && Y1.AcumuladorDeGiro<55)
    {
        ColorYellow();
        gotoxy(84,18);
        printf("----------%c",184);
    }
    else if(Y1.AcumuladorDeGiro>57 && Y1.AcumuladorDeGiro<1000)
    {
        ColorYellow();
        gotoxy(84,18);
        printf("----------%c",184);

    }
    //.....................................................................BLUE..................
    if(B1.AcumuladorDeGiro<10)
    {
        ColorBlue();
        gotoxy(84,19);
        printf("-%c---------",184);
    }
    else if(B1.AcumuladorDeGiro>10 && B1.AcumuladorDeGiro<25)
    {
        ColorBlue();
        gotoxy(84,19);
        printf("---%c-------",184);
    }
    else if(B1.AcumuladorDeGiro>25 && B1.AcumuladorDeGiro<45)
    {
        ColorBlue();
        gotoxy(84,19);
        printf("-------%c---",184);
    }
    else if(B1.AcumuladorDeGiro>45 && B1.AcumuladorDeGiro<55)
    {
        ColorBlue();
        gotoxy(84,19);
        printf("----------%c",184);
    }
    else if(B1.AcumuladorDeGiro>57 && B1.AcumuladorDeGiro<1000)
    {
        ColorBlue();
        gotoxy(84,19);
        printf("----------%c",184);

    }









}
void VerificadorDeChegada()
{
    if(R1.AcumuladorDeGiro ==62)
    {
        R1.chegada = 1;
    }
    if(G1.AcumuladorDeGiro ==62)
    {
        G1.chegada = 1;
    }
    if(Y1.AcumuladorDeGiro ==62)
    {
        Y1.chegada = 1;
    }
    if(B1.AcumuladorDeGiro ==62)
    {
        B1.chegada = 1;
    }
}



void SatarGame()
{
    //------------------------------------------- resetando structs ---------------------









    //---------------------------------------------------------------------




    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    // short int soma =0;
    hideCursor();
    gotoxy(40,3);
    CorVermelha();
    printf("%s", login);
    gotoxy(58,21);
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN);
    printf("%s",login2);
    //---------------------------------------------------------------------------------------------------------demostrativo

    Demostrativo();



    //---------------------------------------------------------------------------------------------------------demostrativo




    R1.saida =0;
    R1.AcumuladorDeGiro =0;
    R1.GiroDado =0;
    R1.mascara=0;
    R1.killPeao =0;
    R1.volta=0;
    R1.chegada =0;

    G1.AcumuladorDeGiro =0;
    G1.GiroDado =0;
    G1.mascara =0;
    G1.saida =0;
    G1.killPeao =0;
    G1.volta=0;
    G1.chegada =0;


    Y1.AcumuladorDeGiro =0;
    Y1.GiroDado =0;
    Y1.mascara =0;
    Y1.saida =0;
    Y1.killPeao =0;
    Y1.volta=0;
    Y1.chegada =0;


    B1.AcumuladorDeGiro =0;
    B1.GiroDado =0;
    B1.mascara =0;
    B1.saida =0;
    B1.killPeao =0;
    B1.volta=0;
    B1.chegada =0;

    //------------------------------------------------------------testes


//------------------------------------------------------------

    while(desligaGame !=1)

    {

        printf("\033[5;37;40m");
        gotoxy(1,1);
        printf(" .           .         .      .          .   .       .  *");
        gotoxy(2,3);
        printf("       .          .                                .          .");
        gotoxy(72,1);
        printf(".             *           .");
        gotoxy(72,2);
        printf("         .      .                .");



//tttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttt



        for(int i =0; i<56; i++)
        {
            rotaGlobal.vetPosicao[i]=' ';
        }
        //red
       /* rotaGlobal.vetPosicao[1]='G';
        rotaGlobal.vetPosicao[2]='Y';
        rotaGlobal.vetPosicao[3]='B';
        rotaGlobal.vetPosicao[4]='G';
        rotaGlobal.vetPosicao[5]='Y';

         rotaGlobal.vetPosicao[56]='G';
        rotaGlobal.vetPosicao[57]='Y';
        rotaGlobal.vetPosicao[58]='B';
        rotaGlobal.vetPosicao[59]='G';
        rotaGlobal.vetPosicao[60]='Y';
         rotaGlobal.vetPosicao[61]='Y';*/
        //green
        /*  rotaGlobal.vetPosicao[16]='R';
           rotaGlobal.vetPosicao[17]='Y';
           rotaGlobal.vetPosicao[18]='B';
           rotaGlobal.vetPosicao[19]='R';
           rotaGlobal.vetPosicao[20]='Y';*/

        //yellow
        /*  rotaGlobal.vetPosicao[30]='G';
          rotaGlobal.vetPosicao[31]='G';
          rotaGlobal.vetPosicao[32]='B';
          rotaGlobal.vetPosicao[33]='R';
          rotaGlobal.vetPosicao[34]='B';*/

        //BLUE
        /*rotaGlobal.vetPosicao[44]='G';
        rotaGlobal.vetPosicao[45]='R';
        rotaGlobal.vetPosicao[46]='Y';
        rotaGlobal.vetPosicao[47]='R';
        rotaGlobal.vetPosicao[48]='Y';
        rotaGlobal.vetPosicao[50]='Y';*/


//tttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttt

        VerificadorDeChegada();
        GraficoDeRota();
        QuadroDesing();
        Demostrativo();
        TrilhaFogo();
        CasaFire();
        VoltarBase();
        AguardaVitoria();

        BarLifeRed(R1.killPeao);
        BarLifeGreen(G1.killPeao);
        BarLifeYellow(Y1.killPeao);
        BarLifeBlue(B1.killPeao);



        //----------------------------------

        Show_Matriz_Copiadora();

        MascaraBlue(B1.mascara);
        MascaraGreen(G1.mascara);
        MascaraRed(R1.mascara);
        MascaraYellow(Y1.mascara);



        Rota_do_R1(R1.AcumuladorDeGiro);
        Rota_do_G1(G1.AcumuladorDeGiro);
        Rota_do_Y1(Y1.AcumuladorDeGiro);
        Rota_do_B1(B1.AcumuladorDeGiro);

        //----------------------------------------
       /* for(int i =0; i<56; i++)
        {
            printf("[%i]%c\n",i,rotaGlobal.vetPosicao[i]);
        }
        getch();
        system("cls");*/

        //******************************************************VEZ DO VERMELHO
        BlocoDaVezR();
        R1.MinhaVez =1;
        G1.MinhaVez =0;
        Y1.MinhaVez =0;
        B1.MinhaVez =0;
        //---------------------------------------------
        if(R1.saida ==0)
        {

            getch();
            DadoGeral();
            DadoDesenhoVermelho(RollDiceGme);
            getch();
            R1.GiroDado =RollDiceGme;
            if(R1.GiroDado ==6)
            {
                R1.saida =1;
                R1.mascara = R1.killPeao+1;
                R1.AcumuladorDeGiro =1;
                Rota_do_R1(R1.AcumuladorDeGiro);
            }

        }
        else if(R1.saida ==1)
        {
            Vitoria();

              if(R1.killPeao ==4){
                R1.AcumuladorDeGiro =0;
                goto JumpRed;
              }

            //tttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttt

            R1.GiroDado = RollDiceGme;

            for(int i =0; i<56; i++)
            {
                if(R1.AcumuladorDeGiro>55)
                {
                 i=56;
                 break;

                }
                else{
                //--------------------------
                    if(rotaGlobal.vetPosicao[R1.AcumuladorDeGiro+RollDiceGme]=='G')
                    {
                        G1.saida =0;
                        G1.AcumuladorDeGiro =0;

                        //printf("VERMELHO capturou verde\n");
                        gotoxy(76,25);
                        CorVermelha();
                        printf("PEGOU");
                        gotoxy(82,25);
                        ColorGreen();
                        printf("[%c]",254);
                    }
                    else  if(rotaGlobal.vetPosicao[R1.AcumuladorDeGiro+RollDiceGme]=='Y')
                    {
                        Y1.saida =0;
                        Y1.AcumuladorDeGiro =0;

                        //printf("VERMELHO capturou amarelo\n");
                        gotoxy(76,25);
                        CorVermelha();
                        printf("PEGOU");
                        gotoxy(82,25);
                        ColorYellow();
                        printf("[%c]",254);

                    }
                    else if(rotaGlobal.vetPosicao[R1.AcumuladorDeGiro+RollDiceGme]=='B')
                    {
                        B1.saida =0;
                        B1.AcumuladorDeGiro =0;

                        //printf("VERMELHO capturou azul\n");
                        gotoxy(76,25);
                        CorVermelha();
                        printf("PEGOU");
                        gotoxy(82,25);
                        ColorBlue();
                        printf("[%c]",254);
                    }
                }

            }

            //ttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttt


            //------------------------------------------saida

            getch();


            Reset_Mat_Copiadora();
            Show_Matriz_Copiadora();
            MascaraBlue(B1.mascara);
            MascaraGreen(G1.mascara);
            MascaraRed(R1.mascara);
            MascaraYellow(Y1.mascara);

            Rota_do_G1(G1.AcumuladorDeGiro);
            Rota_do_Y1(Y1.AcumuladorDeGiro);
            Rota_do_B1(B1.AcumuladorDeGiro);


            DadoDesenhoVermelho(RollDiceGme);
            R1.GiroDado =RollDiceGme;
            R1.AcumuladorDeGiro += RollDiceGme;
            Rota_do_R1(R1.AcumuladorDeGiro);
            // R1.mascara =1;
            R1.mascara = R1.killPeao +1;
            getch();




            Regra_da_Final_Red();

        }


        //printf("\n\n\n\n\n\n\n\n\n\n\n valor de vermelho %i\n",R1.AcumuladorDeGiro);


        //printf("\n\n\n\n\n\n\n\n\n\n\n kill  %i\n",R1.killPeao);


        //******************************************************VEZ DO VERDE
  JumpRed:
        BlocoDaVezG();
        R1.MinhaVez =0;
        G1.MinhaVez =1;
        Y1.MinhaVez =0;
        B1.MinhaVez =0;
        //--------------------------------------
        if(G1.saida ==0)
        {
              if(G1.killPeao ==4|| G1.chegada==1){
                R1.AcumuladorDeGiro =0;
                goto JumpGreen;}

            getch();
            DadoGeral();
            DadoDesenhoVerde(RollDiceGme);
            getch();
            G1.GiroDado =RollDiceGme;
            if(G1.GiroDado ==6)
            {
                G1.saida =1;
                //G1.mascara = 1;
                G1.mascara = G1.killPeao+1;
                G1.AcumuladorDeGiro =1;
                Rota_do_G1(G1.AcumuladorDeGiro);
            }

        }
        else if(G1.saida ==1)
        {
           if(G1.killPeao ==4){
                R1.AcumuladorDeGiro =0;
                goto JumpGreen;
              }
//tttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttt


            //----------------------------------------------------------------------------
            G1.GiroDado = RollDiceGme;

            for(int i =0; i<56; i++)
            {
                if(G1.AcumuladorDeGiro>55)
                {
                 i=56;
                 break;

                }
                else{
                //--------------------------

                if(rotaGlobal.vetPosicao[G1.RotaGeral+RollDiceGme]=='R')
                {
                    R1.saida =0;
                    R1.AcumuladorDeGiro =0;

                    // printf("VERDE capturou o vermelho\n");
                    gotoxy(76,25);
                    ColorGreen();
                    printf("PEGOU");
                    gotoxy(82,25);
                    CorVermelha();
                    printf("[%c]",254);
                }
                else  if(rotaGlobal.vetPosicao[G1.RotaGeral+RollDiceGme]=='Y')
                {
                    Y1.saida =0;
                    Y1.AcumuladorDeGiro =0;

                    //  printf("VERDE capturou o amarelo\n");
                    gotoxy(76,25);
                    ColorGreen();
                    printf("PEGOU");
                    gotoxy(82,25);
                    ColorYellow();
                    printf("[%c]",254);
                }
                else if(rotaGlobal.vetPosicao[G1.RotaGeral+RollDiceGme]=='B')
                {
                    B1.saida =0;
                    B1.AcumuladorDeGiro =0;

                    // printf("VERDE capturou o azul\n");
                    gotoxy(76,25);
                    ColorGreen();
                    printf("PEGOU");
                    gotoxy(82,25);
                    ColorBlue();
                    printf("[%c]",254);
                }


            }
            }

//tttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttt


            //----------------------------------------------------------saida



            //DadoGeral();

            Reset_Mat_Copiadora();
            Show_Matriz_Copiadora();
            MascaraBlue(B1.mascara);
            MascaraGreen(G1.mascara);
            MascaraRed(R1.mascara);
            MascaraYellow(Y1.mascara);
            Rota_do_R1(R1.AcumuladorDeGiro);
            Rota_do_Y1(Y1.AcumuladorDeGiro);
            Rota_do_B1(B1.AcumuladorDeGiro);


            DadoDesenhoVerde(RollDiceGme);
            G1.GiroDado =RollDiceGme;
            G1.AcumuladorDeGiro += RollDiceGme;
            Rota_do_G1(G1.AcumuladorDeGiro);
            // G1.mascara =1;
            G1.mascara = G1.killPeao +1;
            getch();

            Regra_da_Final_Green();

        }

        //printf("\n\n\n\n\n\n\n\n\n\n\n valor de verde %i\n",G1.RotaGeral);

        //******************************************************VEZ DO AMARELO
            JumpGreen:

        BlocoDaVezY();
        R1.MinhaVez =0;
        G1.MinhaVez =0;
        Y1.MinhaVez =1;
        B1.MinhaVez =0;
        //---------------------------------------
        if(Y1.saida ==0)
        {
             if(Y1.killPeao ==4){
                Y1.AcumuladorDeGiro =0;
                goto JumpYellow;
              }
            getch();
            DadoGeral();
            DadoDesenhoAmarelo(RollDiceGme);
            getch();
            Y1.GiroDado =RollDiceGme;
            if(Y1.GiroDado ==6)
            {
                Y1.saida =1;
                Y1.mascara = Y1.killPeao+1;
                Y1.AcumuladorDeGiro =1;
                Rota_do_Y1(Y1.AcumuladorDeGiro);
            }

        }

        else if(Y1.saida ==1)
        {

            Vitoria();
              if(Y1.killPeao ==4){
                Y1.AcumuladorDeGiro =0;
                goto JumpYellow;
              }
//tttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttt
            Y1.GiroDado = RollDiceGme;

            for(int i =0; i<56; i++)
            {
               if(Y1.AcumuladorDeGiro>55)
                {
                 i=56;
                 break;

                }
                else{
                //--------------------------
                if(rotaGlobal.vetPosicao[Y1.RotaGeral+RollDiceGme]=='R')
                {
                    R1.saida =0;
                    R1.AcumuladorDeGiro =0;

                    // printf("AMARELO capturou o vermelho\n");
                    gotoxy(76,25);
                    ColorYellow();
                    printf("PEGOU");
                    gotoxy(82,25);
                    CorVermelha();
                    printf("[%c]",254);
                }
                else  if(rotaGlobal.vetPosicao[Y1.RotaGeral+RollDiceGme]=='G')
                {
                    G1.saida =0;
                    G1.AcumuladorDeGiro =0;

                    // printf("AMARELO capturou o verde\n");
                    gotoxy(76,25);
                    ColorYellow();
                    printf("PEGOU");
                    gotoxy(82,25);
                    ColorGreen();
                    printf("[%c]",254);
                }
                else if(rotaGlobal.vetPosicao[Y1.RotaGeral+RollDiceGme]=='B')
                {
                    B1.saida =0;
                    B1.AcumuladorDeGiro =0;

                    //printf("AMARELO capturou o azul\n");
                    gotoxy(76,25);
                    ColorYellow();
                    printf("PEGOU");
                    gotoxy(82,25);
                    ColorBlue();
                    printf("[%c]",254);
                }


            }
            }

//tttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttt
            //--------------------------------------SAIDA
            getch();
            DadoGeral();

            Reset_Mat_Copiadora();
            Show_Matriz_Copiadora();
            MascaraBlue(B1.mascara);
            MascaraGreen(G1.mascara);
            MascaraRed(R1.mascara);
            MascaraYellow(Y1.mascara);
            Rota_do_R1(R1.AcumuladorDeGiro);
            Rota_do_G1(G1.AcumuladorDeGiro);
            Rota_do_B1(B1.AcumuladorDeGiro);


            DadoDesenhoAmarelo(RollDiceGme);
            Y1.GiroDado =RollDiceGme;
            Y1.AcumuladorDeGiro += RollDiceGme;
            Rota_do_Y1(Y1.AcumuladorDeGiro);
            //Y1.mascara =1;
            Y1.mascara = Y1.killPeao +1;
            getch();

            Regra_da_Final_Yellow();
        }

        //printf("\n\n\n\n\n\n\n\n\n\n\n valor de amarelo %i\n",Y1.AcumuladorDeGiro);

        //******************************************************VEZ DO AZUL
        JumpYellow:

        BlocoDaVezB();
        R1.MinhaVez =0;
        G1.MinhaVez =0;
        Y1.MinhaVez =0;
        B1.MinhaVez =1;
        //---------------------------
        if(B1.saida ==0)
        {
            if(B1.killPeao ==4 || B1.chegada ==1){
                B1.AcumuladorDeGiro =0;
                goto JumpBlue;
              }

            getch();
            DadoGeral();
            DadoDesenhoAzul(RollDiceGme);
            getch();
            B1.GiroDado =RollDiceGme;
            if(B1.GiroDado ==6)
            {

                B1.saida =1;
                // B1.mascara =1;
                B1.mascara = B1.killPeao+1;
                B1.AcumuladorDeGiro =1;
                Rota_do_B1(B1.AcumuladorDeGiro);
            }

        }
        else if(B1.saida ==1)

        {     if(B1.killPeao ==4){
                B1.AcumuladorDeGiro =0;
                goto JumpBlue;
              }

            //tttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttt
            B1.GiroDado;

            B1.GiroDado = RollDiceGme;

            for(int i =0; i<56; i++)
            {
                 if(B1.AcumuladorDeGiro>55)
                {
                 i=56;
                 break;

                }
                else{
                //--------------------------
                if(rotaGlobal.vetPosicao[B1.RotaGeral+RollDiceGme]=='R')
                {
                    R1.saida =0;
                    R1.AcumuladorDeGiro =0;

                    //printf("AZUL capturou o vermelho\n");
                    gotoxy(76,25);
                    ColorBlue();
                    printf("PEGOU");
                    gotoxy(82,25);
                    CorVermelha();
                    printf("[%c]",254);
                }
                else  if(rotaGlobal.vetPosicao[B1.RotaGeral+RollDiceGme]=='G')
                {
                    G1.saida =0;
                    G1.AcumuladorDeGiro =0;

                    //printf("AZUL capturou verde\n");
                    gotoxy(76,25);
                    ColorBlue();
                    printf("PEGOU");
                    gotoxy(82,25);
                    ColorGreen();
                    printf("[%c]",254);
                }
                else if(rotaGlobal.vetPosicao[B1.RotaGeral+RollDiceGme]=='Y')
                {
                    Y1.saida =0;
                    Y1.AcumuladorDeGiro =0;

                    // printf("AZUL capturou o amarelo\n");
                    gotoxy(76,25);
                    ColorBlue();
                    printf("PEGOU");
                    gotoxy(82,25);
                    ColorYellow();
                    printf("[%c]",254);
                }


            }
            }

//tttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttt
            //----------------------------------------SAIDA
            getch();
            DadoGeral();


            Reset_Mat_Copiadora();
            Show_Matriz_Copiadora();
            MascaraBlue(B1.mascara);
            MascaraGreen(G1.mascara);
            MascaraRed(R1.mascara);
            MascaraYellow(Y1.mascara);
            Rota_do_R1(R1.AcumuladorDeGiro);
            Rota_do_G1(G1.AcumuladorDeGiro);
            Rota_do_Y1(Y1.AcumuladorDeGiro);


            DadoDesenhoAzul(RollDiceGme);
            B1.GiroDado =RollDiceGme;
            B1.AcumuladorDeGiro += RollDiceGme;
            Rota_do_B1(B1.AcumuladorDeGiro);

 JumpBlue:

            //B1.mascara =1;
            B1.mascara = B1.killPeao +1;
            getch();

            Regra_da_Final_blue();



        }

        //printf("\n\n\n\n\n\n\n\n\n\n\n valor de azul %i\n",B1.AcumuladorDeGiro);
        //*****************************************************

        //---------------------------------------------------------------------------------testes





        /* if(R1.AcumuladorDeGiro >6)
         {
             R1.AcumuladorDeGiro =1;
             B1.AcumuladorDeGiro =17;
             G1.AcumuladorDeGiro =44;
             Y1.AcumuladorDeGiro = 30;
         }*/



    }




    //----------------------------------------------------------------------------------------------------------



















}

void Fogo()
{

    hideCursor();
    for(int i =0; i<3; i++)
    {

        gotoxy(54,16);
        ColorYellow();
        printf("  %c      %c %c",166,254,167);
        gotoxy(54,17);
        printf("  %c   %c  %c",254,254,254);
        gotoxy(54,18);
        ColorYellow();
        printf("%c %c  %c %c %c",254,254,254,254,254);
        gotoxy(54,19);
        CorVermelha();
        printf("%c %c %c %c  %c",254,254,254,254,254);
        gotoxy(54,20);
        printf("FIRE");
        Sleep(100);
        system("cls");

        gotoxy(54,16);
        ColorYellow();
        printf("  %c   %c %c",254,254,166);
        gotoxy(54,17);
        printf("%c %c",254,254);
        gotoxy(54,18);
        CorVermelha();
        printf("%c%c %c",167,254,254);
        gotoxy(54,19);
        printf("%c  %c %c %c  %c",254,254,254,254,254);
        gotoxy(54,20);
        printf("FIRE");
        Sleep(100);
        system("cls");

        gotoxy(54,14);
        ColorYellow();
        printf("    %c",167);
        gotoxy(54,15);
        printf("  %c ",254);
        gotoxy(60,16);
        CorVermelha();
        printf("  %c   %c",254,167);
        gotoxy(54,17);
        printf("  %c   %c",254,254);
        gotoxy(64,18);
        printf("%c  %c %c  %c",254,254,254,167);
        gotoxy(54,19);
        ColorYellow();
        printf("%c %c %c %c %c",254,254,254,254,254);
        gotoxy(54,20);
        printf("FIRE");
        Sleep(100);
        system("cls");

        ColorYellow();
        gotoxy(54,15);
        printf(" %c",166);
        gotoxy(54,16);
        printf("    %c",166);
        gotoxy(54,15);
        printf("  %c ",254);
        gotoxy(54,16);
        printf(" %c %c",254,167);
        gotoxy(54,17);
        CorVermelha();
        printf("  %c%c",254,254);
        gotoxy(54,18);
        printf("%c  %c %c %c",254,254,254,167);
        gotoxy(54,19);
        CorVermelha();
        printf("%c %c%c %c",254,254,254,254);
        gotoxy(54,20);
        printf("FIRE");
        Sleep(100);
        system("cls");

        gotoxy(54,16);
        printf("  %c %c %c",166,254,167);
        gotoxy(54,17);
        printf("  %c%c  %c",254,167,254);
        gotoxy(54,18);
        ColorYellow();
        printf("%  c %c %c %c %c",166,254,254,254,254);
        gotoxy(54,19);
        CorVermelha();
        printf("%c %c %c %c%c",254,254,254,254,254);
        gotoxy(54,20);
        printf("FIRE");
        Sleep(100);
        system("cls");
    }

}
void FogoAbertura()
{

    hideCursor();
    for(int i =0; i<4; i++)
    {
        gotoxy(54,16);
        ColorYellow();


        printf("  %c      %c %c",166,254,167);
        gotoxy(54,17);
        printf("  %c   %c  %c",254,254,254);
        gotoxy(54,18);
        ColorYellow();
        printf("%c %c  %c %c %c",254,254,254,254,254);
        gotoxy(54,19);
        CorVermelha();
        printf("%c %c %c %c  %c",254,254,254,254,254);
        gotoxy(54,20);
        printf("LUDO FIRE");

        Sleep(100);
        system("cls");

        gotoxy(54,16);
        ColorYellow();
        printf("  %c   %c %c",254,254,166);
        gotoxy(54,17);
        printf("%c %c",254,254);
        gotoxy(54,18);
        CorVermelha();
        printf("%c%c %c",167,254,254);
        gotoxy(54,19);
        printf("%c  %c %c %c  %c",254,254,254,254,254);
        gotoxy(54,20);
        printf("LUDO FIRE");
        Sleep(100);
        system("cls");

        gotoxy(54,14);
        ColorYellow();
        printf("    %c",167);
        gotoxy(54,15);
        printf("  %c ",254);
        gotoxy(60,16);
        CorVermelha();
        printf("  %c   %c",254,167);
        gotoxy(54,17);
        printf("  %c   %c",254,254);
        gotoxy(64,18);
        printf("%c  %c %c  %c",254,254,254,167);
        gotoxy(54,19);
        ColorYellow();
        printf("%c %c %c %c %c",254,254,254,254,254);
        gotoxy(54,20);
        printf("LUDO FIRE");
        Sleep(100);
        system("cls");

        ColorYellow();
        gotoxy(54,15);
        printf(" %c",166);
        gotoxy(54,16);
        printf("    %c",166);
        gotoxy(54,15);
        printf("  %c ",254);
        gotoxy(54,16);
        printf(" %c %c",254,167);
        gotoxy(54,17);
        CorVermelha();
        printf("  %c%c",254,254);
        gotoxy(54,18);
        printf("%c  %c %c %c",254,254,254,167);
        gotoxy(54,19);
        CorVermelha();
        printf("%c %c%c %c",254,254,254,254);
        gotoxy(54,20);
        printf("LUDO FIRE");
        Sleep(100);
        system("cls");

        gotoxy(54,16);
        printf("  %c %c %c",166,254,167);
        gotoxy(54,17);
        printf("  %c%c  %c",254,167,254);
        gotoxy(54,18);
        ColorYellow();
        printf("%  c %c %c %c %c",166,254,254,254,254);
        gotoxy(54,19);
        CorVermelha();
        printf("%c %c %c %c%c",254,254,254,254,254);
        gotoxy(54,20);
        printf("LUDO FIRE");
        Sleep(100);
        system("cls");
    }

}

int main()
{






    printf("\033[10B");

    //-------------------------------------------------------------------- testes
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int coleta=0,cont=0;



    Menu();
    FogoAbertura();


    printf("\033[10B");
    system("cls");


    Matriz_Vazia();
    Reset_Mat_Copiadora();
    Show_Matriz_Copiadora();


    gotoxy(41,11);
    printf("\033[1;33;40m");
    printf("                           ");
    gotoxy(41,12);
    printf("\033[5;31;40m");
    printf("      N E W  G A M E       ");
    gotoxy(41,13);
    printf("                           ");



    printf("\033[5;37;40m");
    gotoxy(70,2);
    printf(".            .                           .");
    gotoxy(71,4);
    printf("    .          .          .        .");
    gotoxy(71,5);
    printf(" .                *             .           .");
    gotoxy(1,1);
    printf(" .           .         .      .          .   .         .  *");
    gotoxy(2,3);
    printf("       .          .                                              .");
    gotoxy(63,11);
    printf(".");
    gotoxy(65,9);
    printf(".");


    hideCursor();
    printf("\033[20B");
    getch();
    system("cls");





    SatarGame();
    system("cls");
    Creditos_Finais();












    system("pause");
}




