#include <gtk/gtk.h>
#include <stdio.h>
#include <wchar.h>
#include <locale.h>

static void
print_hello (GtkWidget *widget,
             gpointer   data)
{
    setlocale(LC_CTYPE, "");
    wchar_t star = 0x0D05;
    wprintf(L"%lc\n", star);
}

int
main (int   argc,
      char *argv[])
{
  GtkBuilder *builder;
  GObject *window;
  GObject *button;
  GError *error = NULL;

  gtk_init (&argc, &argv);

  /* Construct a GtkBuilder instance and load our UI description */
  builder = gtk_builder_new ();
  if (gtk_builder_add_from_file (builder, "builder.ui", &error) == 0)
    {
      g_printerr ("Error loading file: %s\n", error->message);
      g_clear_error (&error);
      return 1;
    }

  /* Connect signal handlers to the constructed widgets. */
  window = gtk_builder_get_object (builder, "window");
  g_signal_connect (window, "destroy", G_CALLBACK (gtk_main_quit), NULL);
  gtk_window_set_default_size (GTK_WINDOW (window), 700, 200);

  button = gtk_builder_get_object (builder, "button1");
  g_signal_connect (button, "clicked", G_CALLBACK (print_hello), NULL);

  button = gtk_builder_get_object (builder, "button2");
  g_signal_connect (button, "clicked", G_CALLBACK (print_hello), NULL);
  
  button = gtk_builder_get_object (builder, "button3");
  g_signal_connect (button, "clicked", G_CALLBACK (print_hello), NULL);

  button = gtk_builder_get_object (builder, "button4");
  g_signal_connect (button, "clicked", G_CALLBACK (print_hello), NULL);
 
  button = gtk_builder_get_object (builder, "button5");
  g_signal_connect (button, "clicked", G_CALLBACK (print_hello), NULL);
 
 button = gtk_builder_get_object (builder, "button6");
  g_signal_connect (button, "clicked", G_CALLBACK (print_hello), NULL);
 
 button = gtk_builder_get_object (builder, "button7");
  g_signal_connect (button, "clicked", G_CALLBACK (print_hello), NULL);

 button = gtk_builder_get_object (builder, "button8");
  g_signal_connect (button, "clicked", G_CALLBACK (print_hello), NULL);

  button = gtk_builder_get_object (builder, "quit");
  g_signal_connect (button, "clicked", G_CALLBACK (gtk_main_quit), NULL);

  gtk_main ();

  return 0;
}