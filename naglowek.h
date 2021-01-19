#ifndef NAGLOWEK_H_INCLUDED
#define NAGLOWEK_H_INCLUDED
#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#include<gtk/gtk.h>
#include<stdbool.h>
typedef struct elem
{
    int val;
    int x;
    int y;
}kafelek;
bool check(kafelek a,kafelek b);
//int los();
void mieszanie(kafelek plansza[6][6]);
#endif // NAGLOWEK_H_INCLUDED
