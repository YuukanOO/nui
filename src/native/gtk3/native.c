#include <gtk/gtk.h>

void nui_native_init(int argc, char* argv[])
{
	gtk_init(&argc, &argv);
}

void nui_native_main_loop()
{
	gtk_main();
}

void nui_native_alert(const char* msg)
{
	// Create the gtk message non modal dialog
	GtkWidget* dialog = gtk_message_dialog_new(	NULL,
												GTK_DIALOG_DESTROY_WITH_PARENT,
												GTK_MESSAGE_INFO,
												GTK_BUTTONS_CLOSE,
												msg);
	// Connect the response event to the destroy widget slot
	g_signal_connect_swapped(	dialog, "response",
								G_CALLBACK(gtk_widget_destroy),
								dialog);
	// And show this widget
	gtk_widget_show(dialog);
}