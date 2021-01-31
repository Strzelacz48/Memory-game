#include"naglowek.h"
kafelek plansza[6][6];
GtkWidget *planszagtk;
//GtkWidget *komorka;
int x,y,tab[18];
int main(int argc,char *argv[])
{
    srand(time(NULL));
    mieszanie();
    //int a;
    // gtk grid sie przyda
    gtk_init (&argc, &argv);
    GtkWidget *window=gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window),"Gra w Memory");
    gtk_window_set_position(GTK_WINDOW(window),GTK_WIN_POS_CENTER);
    gtk_container_set_border_width(GTK_CONTAINER(window), 30);
    g_signal_connect(G_OBJECT(window),"destroy",G_CALLBACK(gtk_main_quit),NULL);

    //1 box
    GtkWidget *box1 = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    gtk_container_add(GTK_CONTAINER(window), box1);

    // guzik mieszania
    GtkWidget *button=gtk_button_new_with_label("Mieszaj");
    g_signal_connect(G_OBJECT(button),"clicked",G_CALLBACK(mieszanie),NULL);
    gtk_container_add(GTK_CONTAINER(box1), button);

    // plansza do gry
    planszagtk = gtk_grid_new();
    gtk_grid_set_row_spacing(GTK_GRID(planszagtk), 5);
    gtk_grid_set_row_homogeneous(GTK_GRID(planszagtk), TRUE);
    gtk_grid_set_column_spacing(GTK_GRID(planszagtk), 5);
    gtk_grid_set_column_homogeneous(GTK_GRID(planszagtk), TRUE);
    gtk_container_add(GTK_CONTAINER(box1),planszagtk);
    for(int i=0;i<6;i++)
    {
        for(int j=0;j<6;j++)
        {
            button=gtk_button_new();
            g_signal_connect(G_OBJECT(button),"clicked",G_CALLBACK(wybierz),NULL);
            gtk_grid_attach(GTK_GRID(planszagtk),button,j,i,1,1);
        }
    }
    gtk_widget_show_all(window);
    gtk_main ();
    return 0;
}
