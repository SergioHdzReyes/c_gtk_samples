//
// Created by sergio on 07/11/21.
//

#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>

GtkWidget *window;
GtkWidget *fixed1;
GtkWidget *button1;
GtkWidget *label1;
GtkBuilder *builder;

int main (int argc, char *argv[])
{
    gtk_init(&argc, &argv);

    builder = gtk_builder_new_from_file("sample.glade");

    window = GTK_WIDGET(gtk_builder_get_object(builder, "window1"));

    g_signal_connect(window, "gtk_main_quit", NULL, NULL);

    gtk_builder_connect_signals(builder, NULL);

    fixed1 = GTK_WIDGET(gtk_builder_get_object(builder, "fixed1"));
    button1 = GTK_WIDGET(gtk_builder_get_object(builder, "button1"));
    label1 = GTK_WIDGET(gtk_builder_get_object(builder, "label1"));

    gtk_widget_show(window);
    gtk_main();

    return EXIT_SUCCESS;
}

void on_button1_clicked(GtkButton *b) {
    gtk_label_set_text(GTK_LABEL(label1), (const gchar*) "Hello World");
}