#ifndef NAGLOWEK_H_INCLUDED
#define NAGLOWEK_H_INCLUDED
#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#include <string.h>
#include <gtk/gtk.h>
#include<stdbool.h>
typedef struct elem
{
    int val;
    int czyo;
    int y;
}kafelek;
typedef struct przycisk
{
    int val;
    int czyo;
    int posY,posX,lenY,lenX;
}guzik;
bool have_same_value(kafelek a,kafelek b);
int grawkonsoli();
void wybierz(GtkWidget *a);
//int los();
void mieszanie();
#endif // NAGLOWEK_H_INCLUDED
