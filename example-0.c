#include <gtk/gtk.h>

static void
print_hello (GtkWidget *widget,
             gpointer   data)
{
  g_print ("Hello World\n");
}

static void
activate (GtkApplication *app,
          gpointer        user_data)
{
  GtkWidget *window;
  GtkWidget *button1;
 // GtkWidget *button_box;
  GtkWidget *grid;

  window = gtk_application_window_new (app);
  gtk_window_set_title (GTK_WINDOW (window), "മലയാളം ");
  gtk_window_set_default_size (GTK_WINDOW (window), 700, 200);
  grid= gtk_grid_new();
  gtk_container_add (GTK_CONTAINER (window),grid);

  button1 = gtk_button_new_with_label ("Hello");
  g_signal_connect (button1, "clicked", G_CALLBACK (print_hello), NULL);
  gtk_grid_attach (GTK_GRID (grid), button1, 0, 0, 1, 1);
  button1= gtk_button_new_with_label ("Hellooo");
  g_signal_connect_swapped (button1, "clicked", G_CALLBACK (gtk_widget_destroy), window);
  gtk_grid_attach (GTK_GRID (grid), button1, 1, 0, 1, 1);
 
 // gtk_container_add (GTK_CONTAINER (button_box), button1);
//  gtk_container_add (GTK_CONTAINER (button_box), button2);
  
  gtk_widget_show_all (window);
}

int
main (int    argc,
      char **argv)
{
  GtkApplication *app;
  int status;

  app = gtk_application_new ("org.gtk.example", G_APPLICATION_FLAGS_NONE);
  g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);
  status = g_application_run (G_APPLICATION (app), argc, argv);
  g_object_unref (app);

  return status;
}

