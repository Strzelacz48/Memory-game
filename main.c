#include"naglowek.h"
int main()
{
    kafelek plansza[6][6];
    mieszanie(plansza);
    for(int i=0;i<6;i++)
    {
        for(int j=0;j<6;j++)
        {
            printf("%d ",plansza[i][j].val);
        }
        printf("\n");
    }
    return 0;
}
