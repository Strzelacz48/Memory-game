#include"naglowek.h"
typedef struct elem
{
    int val;
    int x;
    int y;
} kafelek;
bool check(kafelek a,kafelek b)
{
if(a.val==b.val)
    return true;
else
    return false;
}
