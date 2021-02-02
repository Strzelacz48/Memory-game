#include"naglowek.h"
extern kafelek plansza[6][6];
extern GtkWidget *planszagtk,*komorka,*notatki;
extern int x,y,a,tab[18],liczbar;
extern bool stangry;
char* intToString(int n)
{
    char str[100000];
    sprintf(str, "%d", n);
    return strdup(str);
}
char* stringmake(char *A,int B, char *C,int D)
{
    char str[100000];
    if(D!=-1)
    {
        printf(str, "%s%d%s%d",D,C,B,A);
        return strdup(str);
    }
    else
    {
        sprintf(str, "%s%d%s",A,B,C);
        return strdup(str);
    }
}
void test()
{
    //g_timeout_add();
}
//funkcja do pisania komunikatow
void wyjscie(int tryb,int liczba1,int liczba2)
{
    if(tryb==0)
    {
        gtk_button_set_label(GTK_BUTTON(notatki),"");
    }
    else if(tryb==1)//liczba1 i liczba2 sątakie same
    {
        gchar *tryb1="Są takie same";
        gtk_button_set_label(GTK_BUTTON(notatki),tryb1);
    }
    else if(tryb==2)//liczba1 i liczba2 są inne
    {
        gchar *tryb2="Nie są takie same";
        gtk_button_set_label(GTK_BUTTON(notatki),tryb2);
    }
    else if(tryb==3)//gra się skończyła
    {
        gchar *tryb3="Gra skończona wygrałeś w ",*tryb3p=" ruchach";
        gtk_button_set_label(GTK_BUTTON(notatki),stringmake(tryb3,liczba1,tryb3p,-1));
    }
    else if(tryb==4)//gra została zresetowana
    {
        gchar *tryb4="Gra się rozpoczęła wybierz parę guzików";
        gtk_button_set_label(GTK_BUTTON(notatki),tryb4);
    }
    else if(tryb==5)
    {
        gchar *tryb5="Wybierz zakryty guzik";
        gtk_button_set_label(GTK_BUTTON(notatki),tryb5);
    }
}
//główna funkcja do guzików
void wybierz(GtkWidget *button)
{
    if(stangry==true)
    {
        wyjscie(3,liczbar,-1);
        //g_print("\nGra skończona wygrałeś w %d ruchów\n",liczbar);
        return;
    }
    if(a==2)
    {
        a=0;
        for(int i=0;i<6;i++)
        {
            for(int j=0;j<6;j++)
            {
                if(plansza[i][j].czyo==0)
                {
                    komorka=gtk_grid_get_child_at (GTK_GRID(planszagtk),j,i);
                    gtk_button_set_label(GTK_BUTTON(komorka),"");
                }
            }
        }
    }

    GValue top = G_VALUE_INIT;
    GValue left = G_VALUE_INIT;
    g_value_init(&top, G_TYPE_INT);
    g_value_init(&left, G_TYPE_INT);
    gtk_container_child_get_property(GTK_CONTAINER(planszagtk), button, "top-attach", &top);
    gtk_container_child_get_property(GTK_CONTAINER(planszagtk), button, "left-attach", &left);
    x = g_value_get_int(&top);
    y = g_value_get_int(&left);
    //g_print("%d %d\n",x,y);
    if(plansza[x][y].czyo==1)
    {
        wyjscie(5,0,0);
        //g_print("Wybierz zakryty guzik\n");
        return;
    }
    bool pom=false;
    for(int i=0; i<6; i++)
    {
        for(int j=0; j<6; j++)
        {
            if(plansza[i][j].wyb==true)
            {
                if(plansza[x][y].val==plansza[i][j].val)
                {//jeśli wybrano 2 takie same guziki
                    plansza[i][j].wyb=false;
                    plansza[x][y].czyo=1;
                    pom=true;//debugingg
                    wyjscie(1,plansza[x][y].val,plansza[x][y].val);
                    //g_print("Są takie same\n");
                    tab[plansza[x][y].val]=0;
                    //zmiana etykiet guzikow
                    gtk_button_set_label(GTK_BUTTON(komorka),intToString(plansza[i][j].val));
                    komorka=gtk_grid_get_child_at (GTK_GRID(planszagtk),y,x);
                    gtk_button_set_label(GTK_BUTTON(komorka),intToString(plansza[x][y].val));
                    a++;
                    liczbar++;
                    break;
                }
                else
                {
                    plansza[i][j].wyb=false;
                    plansza[i][j].czyo=0;
                    pom=true;//debugging
                    wyjscie(2,plansza[x][y].val,plansza[i][j].val);
                    //g_print("Nie są takie same\n");
                    a++;
                    komorka=gtk_grid_get_child_at (GTK_GRID(planszagtk),y,x);
                    gtk_button_set_label(GTK_BUTTON(komorka),intToString(plansza[x][y].val));/*
                    gtk_button_set_label(GTK_BUTTON(komorka),"");
                    komorka=gtk_grid_get_child_at (GTK_GRID(planszagtk),j,i);
                    gtk_button_set_label(GTK_BUTTON(komorka),"");*/
                    liczbar++;
                    break;
                }
            }
        }
    }
//pierwszy wybrany guzik
    if(pom==false)
    {
        plansza[x][y].czyo=1;
        plansza[x][y].wyb=true;
        komorka=gtk_grid_get_child_at (GTK_GRID(planszagtk),y,x);
        gtk_button_set_label(GTK_BUTTON(komorka),intToString(plansza[x][y].val));
        wyjscie(0,0,0);
        a++;
        //tab[plansza[x][y].val];
    }
    else
    {
        int pom2=18;
        for(int i=0;i<18;i++)
        {
            //debugging
            //g_print("%d ",tab[i]);
            if(tab[i]==0)
                {pom2--;}
        }
        if(pom2==0)
            {
                wyjscie(3,liczbar,liczbar);
                //g_print("\nGra skończona wygrałeś w %d ruchów\n",liczbar);
                stangry=true;
            }
    }
}

//funkcja do wybierania ustawienia planszy
void mieszanie()
{
    wyjscie(4,0,0);
    a=0;
    liczbar=0;
    stangry=false;
    //tablica pamiętająca czy nie ma za dużo tych samych liczb na planszy
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
                //return ;
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
            //czyszczenie guzikow
            komorka=gtk_grid_get_child_at (GTK_GRID(planszagtk),i,j);
            gtk_button_set_label(GTK_BUTTON(komorka),"");
            //printf("%d ",r);
        }
        //printf("\n");
    }//wskazowki jak wyglada plansza przydatne przy sprawdzaniu
    /*for(int i=0; i<6; i++)
    {
        for(int j=0; j<6; j++)
        {
            g_print(" %d",plansza[i][j].val);
        }
        g_print("\n");
    }*/
}
//stara funkcja do gry w konsoli
int grawkonsoli()
{
    kafelek plansza[6][6];
    mieszanie((kafelek*)plansza);
    int tab1[18]= {0};
    for(int i=0; i<6; i++)
    {
        for(int j=0; j<6; j++)
        {
            //sprawdzanie czy są pary/*
            if(tab1[plansza[i][j].val]==2)
            {
                printf("error");
                return 0;
            }
            else
            {
                tab1[plansza[i][j].val]++;
            }//koniec sprawdzania*/
            printf("%d ",plansza[i][j].val);
        }
        printf("\n");
    }//pom ilosć aktualnie wybranych kafelków
    for(int i=0; i<18; i++) //resetowanie tabeli z ilością par
    {
        tab1[i]=0;
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
            if(tab1[i]==0)
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
                tab1[plansza[x][y].val]=1;
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
//funkcje zapasowe/pozostalosci po tworzeniu głownych funkcji
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
/*bool have_same_value(kafelek a,kafelek b)
{
    return a.val==b.val;
}*/
