#include"naglowek.h"
//kafelek utworz(int a,int b,int c)
//{

//}
bool check(kafelek a,kafelek b)
{
    if(a.val==b.val)
        return true;
    else
        return false;
}
void wybrany(kafelek *a)
{
    a->czyo=1;
}
/*int los() // funkcja do losowania liczb z przedzialu <0,18>
{
    //int a;
    //scanf("%d",&a);
    srand(time(NULL));
    //for(int i=0; i<a; i++)
    //{
    int r = rand()%18;      // Returns a pseudo-random integer between 0 and RAND_MAX.
    //printf("%d" " ",r);
    //}
    return r;
}*/
void mieszanie(kafelek plansza[6][6])
{
    int tab[18];//tablica pamiętająca czy nie ma za dużo tych samych liczb na planszy
    srand(time(NULL));
    for(int i=0; i<18; i++)
    {
        tab[i]=0;
    }
    for(int i=0; i<6; i++)// pętle resetujące planszę
    {
        for(int j=0; j<6; j++)
        {
            int r = rand()%18;
            if(tab[r]!=2)
            {
                tab[r]++;
                plansza[i][j].val=r;
                plansza[i][j].czyo=0;
            }
            else//jeśli liczba była już 2 razy na planszy
            {
                //int k=r;
                while(tab[r]==2)//szukanie innej co nie była 2 razy
                {
                    if(r==17)
                    {
                        r=0;
                    }
                    else
                    {
                        r++;
                    }
                }
                tab[r]++;
                plansza[i][j].val=r;
                plansza[i][j].czyo=0;
            }
            //printf("%d ",r);
        }
        //printf("\n");
    }
}
