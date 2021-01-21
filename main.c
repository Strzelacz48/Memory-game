#include"naglowek.h"
int main()
{
    kafelek plansza[6][6];
    mieszanie(plansza);
    int tab[18]={0};
    for(int i=0;i<6;i++)
    {
        for(int j=0;j<6;j++)
        {//sprawdzanie czy są pary/*
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
    int x,y,x1,y1,pom=0;
    while(true)
    {
        for(int i=0;i<6;i++)
        {
            for(int j=0;j<6;j++)
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
        if(pom==1)
        {
            x1=x;
            y1=y;
            scanf("%d %d",&x,&y);
            if(plansza[x][y].czyo==0)
            {
               plansza[x][y].czyo=1;
            }
            else
            {
                while(plansza[x][y].czyo==1)
                {scanf("%d %d",&x,&y);}
            }
            if(plansza[x][y].val!=plansza[x1][y1].val)
            {
                plansza[x1][y1].czyo=1;
                for(int i=0;i<6;i++)
                {
                    for(int j=0;j<6;j++)
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
            pom=0;
        }
        else
        {
            scanf("%d %d",&x,&y);
            if(plansza[x][y].czyo==0)
            {
               plansza[x][y].czyo=1;
            }
            else
            {
                while(plansza[x][y].czyo==1)
                {scanf("%d %d",&x,&y);}
            }
            pom++;
        }


        if(x==-1 && y==-1)
        {
           return 0;
        }

    }

}
