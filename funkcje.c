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
    int tab[18];
    srand(time(NULL));
    for(int i=0; i<18; i++)
    {
        tab[i]=0;
    }
    for(int i=0; i<6; i++)
    {
        for(int j=0; j<6; j++)
        {
            int r = rand()%18;
            if(tab[r]!=2)
            {
                tab[r]++;
                plansza[i][j].val=r;
            }
            else
            {
                int k=r;
                while(tab[k]==2)
                {
                    if(k==18)
                    {
                        k=0;
                    }
                    else
                    {
                        k++;
                    }
                }
                tab[k]++;
                plansza[i][j].val=k;
            }
            //printf("%d ",r);
        }
        //printf("\n");
    }
}
