#include"naglowek.h"
int main()
{
    kafelek plansza[6][6];
    mieszanie(plansza);
    int tab[18]= {0};
    for(int i=0; i<6; i++)
    {
        for(int j=0; j<6; j++)
        {
            //sprawdzanie czy są pary/*
            if(tab[plansza[i][j].val]==2)
            {
                printf("error");
                return 0;
            }
            else
            {
                tab[plansza[i][j].val]++;
            }//koniec sprawdzania*/
            printf("%d ",plansza[i][j].val);
        }
        printf("\n");
    }//pom ilosć aktualnie wybranych kafelków
    for(int i=0; i<18; i++) //resetowanie tabeli z ilością par
    {
        tab[i]=0;
    }
    int x,y,x1,y1,pom=0;
    while(true)
    {
        //drukowanie planszy *- zakryte, pole numer - odkryte pole ze znakiem
        for(int i=0; i<6; i++)
        {
            for(int j=0; j<6; j++)
            {
                if(plansza[i][j].czyo==0)
                {
                    printf("* ");
                }
                else
                {
                    printf("%d ",plansza[i][j].val);
                }
            }
            printf("\n");
        }
        printf("\n");
        //sprawdzanie czy nie roziwązalismy planszy
        int koniec=18;
        for(int i=0; i<18; i++)
        {
            if(tab[i]==0)
            {
                koniec--;
            }
        }// konczenie gry
        if(koniec==18)
        {
            printf("Gratulacje wygrałeś w x ruchach");
            return 0;
            /*mieszanie();
            for(int i=0; i<6; i++)
            {
                for(int j=0; j<6; j++)
                {
                    if(plansza[i][j].czyo==0)
                    {
                        printf("* ");
                    }
                    else
                    {
                        printf("%d ",plansza[i][j].val);
                    }
                }
                printf("\n");
            }
            printf("\n");*/
        }

        if(pom==1)//jeśli to 2 z dwóch wybranych kafelków
        {
            x1=x;
            y1=y;
            scanf("%d %d",&x,&y);//skanowanie 2 kafelka
            if(plansza[x][y].czyo==0)
            {
                plansza[x][y].czyo=1;
            }
            else// skanowanie 2 kafelka dopóki będzie prawidłowy
            {
                while(plansza[x][y].czyo==1)
                {
                    printf("wybierz zakryty kafelek\n");
                    scanf("%d %d",&x,&y);
                }
                plansza[x][y].czyo=1;
            }
            if(plansza[x][y].val!=plansza[x1][y1].val)//sprawdzanie czy są takie same
            {
                plansza[x1][y1].czyo=1;
                for(int i=0; i<6; i++)
                {
                    for(int j=0; j<6; j++)
                    {
                        if(plansza[i][j].czyo==0)
                        {
                            printf("* ");
                        }
                        else
                        {
                            printf("%d ",plansza[i][j].val);
                        }
                    }
                    printf("\n");
                }
                printf("\n");
                plansza[x][y].czyo=0;
                plansza[x1][y1].czyo=0;
            }
            else
            {
                tab[plansza[x][y].val]=1;
            }
            pom=0;
        }
        else//jeśli to pierwszy z dwóch wybranych kafelków
        {
            scanf("%d %d",&x,&y);
            if(plansza[x][y].czyo==0)
            {
                plansza[x][y].czyo=1;
            }
            else
            {
                while(plansza[x][y].czyo==1)
                {
                    printf("wybierz zakryty kafelek\n");
                    scanf("%d %d",&x,&y);
                }
                plansza[x][y].czyo=1;
            }
            pom++;
        }
        //zamknięcie gry
        if(x==-1 && y==-1)
        {
            return 0;
        }
    }
}
