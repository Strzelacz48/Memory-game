#include"naglowek.h"

bool check(kafelek a,kafelek b)
{
    if(a.val==b.val)
        return true;
    else
        return false;
}
void los() // funkcja do losowania liczb z przedzialu <0,18>
{
    int a;
    scanf("%d",&a);
    srand(time(NULL));
    for(int i=0; i<a; i++)
    {
        int r = rand()%18;      // Returns a pseudo-random integer between 0 and RAND_MAX.
        printf("%d" " ",r);
    }
//return r;
}
/*void mieszanie()
{
    int tab[18];
    for(int i=0;i<6;i++)
    {

    }
}*/
