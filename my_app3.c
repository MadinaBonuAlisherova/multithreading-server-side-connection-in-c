#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>
#include <gtk/gtk.h>
#include <gtk/gtkx.h>
#include <math.h>
#include <ctype.h>
#include <netdb.h>
#include <json-c/json.h>
#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>


#define PORT 7777 
#define SA struct sockaddr 


// Main menu global variables
GtkBuilder *builder;

/**********************************/
GtkWidget *client_service;
//images
GtkWidget *main_image;
GtkWidget *image1;
GtkWidget *image2;
GtkWidget *image3; 
GtkWidget *image4; 
GtkWidget *image5;
GtkWidget *hotel_image;

GtkWidget *hot_but1;
GtkWidget *hot_but2;
GtkWidget *hot_but3;
GtkWidget *hot_but4;
GtkWidget *hot_but5;
GtkWidget *hot_but6;
GtkTextBuffer *hotel_buf;

/***************************************/


GtkWidget *main_page;

GtkWidget *form;
GtkWidget *full_name;
GtkWidget *addr_live;
GtkWidget *phone_number;
GtkWidget *email;
GtkWidget *regions;
GtkWidget *sour;
GtkWidget *date;
GtkWidget *gr_fml_al;
GtkWidget *finish;

int clientSocket, ret; 	
struct sockaddr_in serverAddr;
char buffer[2048];
char *query;
char *q;
char *region;
char *hot_btn1, *hot_btn2, *hot_btn3, *hot_btn4, *hot_btn5, *hot_btn6;

void on_destroy();
int main(int argc, char *argv[]) {


gtk_init(&argc, &argv); // init Gtk

builder = gtk_builder_new_from_file("app.glade");

main_page = GTK_WIDGET(gtk_builder_get_object(builder, "main_page"));
	client_service = GTK_WIDGET(gtk_builder_get_object(builder, "client_service"));
	
	main_image = GTK_WIDGET(gtk_builder_get_object(builder, "main_image"));
    	image1 = GTK_WIDGET(gtk_builder_get_object(builder, "image1"));
	image2 = GTK_WIDGET(gtk_builder_get_object(builder, "image2"));
	image3 = GTK_WIDGET(gtk_builder_get_object(builder, "image3")); 
 	image4 = GTK_WIDGET(gtk_builder_get_object(builder, "image4")); 
	image5 = GTK_WIDGET(gtk_builder_get_object(builder, "image5"));;

	hot_but1 = GTK_WIDGET(gtk_builder_get_object(builder, "hot_but1"));
	hot_but2 = GTK_WIDGET(gtk_builder_get_object(builder, "hot_but2")); 
	hot_but3 = GTK_WIDGET(gtk_builder_get_object(builder, "hot_but3"));
	hot_but4 = GTK_WIDGET(gtk_builder_get_object(builder, "hot_but4"));
	hot_but5 = GTK_WIDGET(gtk_builder_get_object(builder, "hot_but5"));
	hot_but6 = GTK_WIDGET(gtk_builder_get_object(builder, "hot_but6"));
	hotel_image = GTK_WIDGET(gtk_builder_get_object(builder, "hotel_image"));
	hotel_buf = GTK_TEXT_BUFFER(gtk_builder_get_object(builder, "hotel_buf"));
	form = GTK_WIDGET(gtk_builder_get_object(builder, "form"));
	full_name = GTK_WIDGET(gtk_builder_get_object(builder, "full_name"));
	addr_live = GTK_WIDGET(gtk_builder_get_object(builder, "addr_live"));
	phone_number = GTK_WIDGET(gtk_builder_get_object(builder, "phone_number"));
	email = GTK_WIDGET(gtk_builder_get_object(builder, "email"));
	regions = GTK_WIDGET(gtk_builder_get_object(builder, "regions"));
	date = GTK_WIDGET(gtk_builder_get_object(builder, "date"));
	gr_fml_al = GTK_WIDGET(gtk_builder_get_object(builder, "gr_fml_al"));
	sour = GTK_WIDGET(gtk_builder_get_object(builder, "pack"));
	finish = GTK_WIDGET(gtk_builder_get_object(builder, "finishh"));


//changin background color
GdkColor color; // default background color
color.red = 0xffff;
color.green = 0xffff;
color.blue = 0xffff;
gtk_widget_modify_bg(GTK_WIDGET(main_page), GTK_STATE_NORMAL, &color);

gtk_widget_modify_bg(GTK_WIDGET(client_service), GTK_STATE_NORMAL, &color);
// ALL CHANGES HERE ....

// CHANGES ENDED ....


bzero(buffer, sizeof(buffer));


clientSocket = socket(AF_INET, SOCK_STREAM, 0);
if(clientSocket < 0){
printf("[-]Error in connection.\n");
exit(1);
}
printf("[+]Client Socket is created.\n");


memset(&serverAddr, '\0', sizeof(serverAddr));
serverAddr.sin_family = AF_INET;
serverAddr.sin_port = htons(PORT);

serverAddr.sin_addr.s_addr = inet_addr("192.168.43.59");
// 192.168.43.28
//192.168.43.59
ret = connect(clientSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr));
printf("I am here\n");
if(ret < 0){
printf("[-]Error in connection.\n");
exit(1);
}




	g_signal_connect(main_page, "destroy", G_CALLBACK(on_destroy), NULL);
	
	gtk_builder_connect_signals(builder, NULL);
	
	gtk_widget_show_all(main_page);
	
	gtk_main();

printf("[+]Connected to Server.\n");

return EXIT_SUCCESS;
}

void on_and_but_clicked(GtkButton *b){
	//memset(region, 0, sizeof(region));
	region = "Andijan";
	char mn[100], fl1[100], fl2[100], fl3[100], fl4[100], fl5[100];
	sprintf(mn, "%s%s%s","./Media/regions/",region, "/1000x700/1.jpeg");
	gtk_image_set_from_file(GTK_IMAGE(main_image), mn);
	memset(mn, 0, sizeof(mn));
	sprintf(fl1, "%s%s%s","./Media/regions/",region, "/240x190/1.jpeg");
	gtk_image_set_from_file(GTK_IMAGE(image1), fl1);
	memset(fl1, 0, sizeof(fl1));
	sprintf(fl2, "%s%s%s","./Media/regions/",region, "/240x190/2.jpeg");
	gtk_image_set_from_file(GTK_IMAGE(image2), fl2);
	memset(fl2, 0, sizeof(fl2));
	sprintf(fl3, "%s%s%s","./Media/regions/",region, "/240x190/3.jpeg");
	gtk_image_set_from_file(GTK_IMAGE(image3), fl3);
	memset(fl3, 0, sizeof(fl3));
	sprintf(fl4, "%s%s%s","./Media/regions/",region, "/240x190/4.jpeg");
	gtk_image_set_from_file(GTK_IMAGE(image4), fl4);
	memset(fl4, 0, sizeof(fl4));
	sprintf(fl5, "%s%s%s","./Media/regions/",region, "/240x190/5.jpeg");
	gtk_image_set_from_file(GTK_IMAGE(image5), fl5);
	memset(fl5, 0, sizeof(fl5));
	hot_btn1 = "Bog'ishamol";
	hot_btn2 = "Karvon Saroy";
	hot_btn3 = "Xamkor Biznes Senter";
	hot_btn4 = "Elita Hotel";
	hot_btn5 = "Vella Elegant";
	hot_btn6 = "Oriental Hotel";
	gtk_button_set_label(GTK_BUTTON(hot_but1), hot_btn1);
	gtk_button_set_label(GTK_BUTTON(hot_but2), hot_btn2);
	gtk_button_set_label(GTK_BUTTON(hot_but3), hot_btn3);
	gtk_button_set_label(GTK_BUTTON(hot_but4), hot_btn4);
	gtk_button_set_label(GTK_BUTTON(hot_but5), hot_btn5);
	gtk_button_set_label(GTK_BUTTON(hot_but6), hot_btn6);
	gtk_widget_hide(main_page);
	gtk_widget_show_all(client_service);
	
}

void on_bukh_but_clicked(GtkButton *b){
	region = "Bukhara";
	char mn[100], fl1[100], fl2[100], fl3[100], fl4[100], fl5[100];
	sprintf(mn, "%s%s%s","./Media/regions/",region, "/1000x700/1.jpeg");
	gtk_image_set_from_file(GTK_IMAGE(main_image), mn);
	memset(mn, 0, sizeof(mn));
	sprintf(fl1, "%s%s%s","./Media/regions/",region, "/240x190/1.jpeg");
	gtk_image_set_from_file(GTK_IMAGE(image1), fl1);
	memset(fl1, 0, sizeof(fl1));
	sprintf(fl2, "%s%s%s","./Media/regions/",region, "/240x190/2.jpeg");
	gtk_image_set_from_file(GTK_IMAGE(image2), fl2);
	memset(fl2, 0, sizeof(fl2));
	sprintf(fl3, "%s%s%s","./Media/regions/",region, "/240x190/3.jpeg");
	gtk_image_set_from_file(GTK_IMAGE(image3), fl3);
	memset(fl3, 0, sizeof(fl3));
	sprintf(fl4, "%s%s%s","./Media/regions/",region, "/240x190/4.jpeg");
	gtk_image_set_from_file(GTK_IMAGE(image4), fl4);
	memset(fl4, 0, sizeof(fl4));
	sprintf(fl5, "%s%s%s","./Media/regions/",region, "/240x190/5.jpeg");
	gtk_image_set_from_file(GTK_IMAGE(image5), fl5);
	memset(fl5, 0, sizeof(fl5));
	
	hot_btn1 = "Kukaldosh Bouteque Hotel";
	hot_btn2 = "Rangrez Hotel";
	hot_btn3 = "Lyabi House Hotel";
	hot_btn4 = "Zargaron Plaza Hotel";
	hot_btn5 = "Hotel Zarafshon Sahid Hotel";
	hot_btn6 = "Amelia Bouteque Hotel Hotel";
	gtk_button_set_label(GTK_BUTTON(hot_but1), hot_btn1);
	gtk_button_set_label(GTK_BUTTON(hot_but2), hot_btn2);
	gtk_button_set_label(GTK_BUTTON(hot_but3), hot_btn3);
	gtk_button_set_label(GTK_BUTTON(hot_but4), hot_btn4);
	gtk_button_set_label(GTK_BUTTON(hot_but5), hot_btn5);
	gtk_button_set_label(GTK_BUTTON(hot_but6), hot_btn6);
	
	gtk_widget_hide(main_page);
	gtk_widget_show_all(client_service);
}

void on_fer_but_clicked(GtkButton *b){
	region = "Fergana";
	char mn[100], fl1[100], fl2[100], fl3[100], fl4[100], fl5[100];
	sprintf(mn, "%s%s%s","./Media/regions/",region, "/1000x700/1.jpeg");
	gtk_image_set_from_file(GTK_IMAGE(main_image), mn);
	memset(mn, 0, sizeof(mn));
	sprintf(fl1, "%s%s%s","./Media/regions/",region, "/240x190/1.jpeg");
	gtk_image_set_from_file(GTK_IMAGE(image1), fl1);
	memset(fl1, 0, sizeof(fl1));
	sprintf(fl2, "%s%s%s","./Media/regions/",region, "/240x190/2.jpeg");
	gtk_image_set_from_file(GTK_IMAGE(image2), fl2);
	memset(fl2, 0, sizeof(fl2));
	sprintf(fl3, "%s%s%s","./Media/regions/",region, "/240x190/3.jpeg");
	gtk_image_set_from_file(GTK_IMAGE(image3), fl3);
	memset(fl3, 0, sizeof(fl3));
	sprintf(fl4, "%s%s%s","./Media/regions/",region, "/240x190/4.jpeg");
	gtk_image_set_from_file(GTK_IMAGE(image4), fl4);
	memset(fl4, 0, sizeof(fl4));
	sprintf(fl5, "%s%s%s","./Media/regions/",region, "/240x190/5.jpeg");
	gtk_image_set_from_file(GTK_IMAGE(image5), fl5);
	memset(fl5, 0, sizeof(fl5));
	hot_btn1 = "Voyage Hotel";
	hot_btn2 = "Asia Fergana Hotel";
	hot_btn3 = "Asia Hotel";
	hot_btn4 = "Grand Fergana Hotel";
	hot_btn5 = "Atlas Hotel";
	hot_btn6 = "Terra Nova Hotel";
	gtk_button_set_label(GTK_BUTTON(hot_but1), hot_btn1);
	gtk_button_set_label(GTK_BUTTON(hot_but2), hot_btn2);
	gtk_button_set_label(GTK_BUTTON(hot_but3), hot_btn3);
	gtk_button_set_label(GTK_BUTTON(hot_but4), hot_btn4);
	gtk_button_set_label(GTK_BUTTON(hot_but5), hot_btn5);
	gtk_button_set_label(GTK_BUTTON(hot_but6), hot_btn6);
	gtk_widget_hide(main_page);
	gtk_widget_show_all(client_service);
}

void on_jiz_but_clicked(GtkButton *b){
	region = "Jizzakh";
	char mn[100], fl1[100], fl2[100], fl3[100], fl4[100], fl5[100];
	sprintf(mn, "%s%s%s","./Media/regions/",region, "/1000x700/1.jpeg");
	gtk_image_set_from_file(GTK_IMAGE(main_image), mn);
	memset(mn, 0, sizeof(mn));
	sprintf(fl1, "%s%s%s","./Media/regions/",region, "/240x190/1.jpeg");
	gtk_image_set_from_file(GTK_IMAGE(image1), fl1);
	memset(fl1, 0, sizeof(fl1));
	sprintf(fl2, "%s%s%s","./Media/regions/",region, "/240x190/2.jpeg");
	gtk_image_set_from_file(GTK_IMAGE(image2), fl2);
	memset(fl2, 0, sizeof(fl2));
	sprintf(fl3, "%s%s%s","./Media/regions/",region, "/240x190/3.jpeg");
	gtk_image_set_from_file(GTK_IMAGE(image3), fl3);
	memset(fl3, 0, sizeof(fl3));
	sprintf(fl4, "%s%s%s","./Media/regions/",region, "/240x190/4.jpeg");
	gtk_image_set_from_file(GTK_IMAGE(image4), fl4);
	memset(fl4, 0, sizeof(fl4));
	sprintf(fl5, "%s%s%s","./Media/regions/",region, "/240x190/5.jpeg");
	gtk_image_set_from_file(GTK_IMAGE(image5), fl5);
	memset(fl5, 0, sizeof(fl5));
	hot_btn1 = "Grand Hotel UZBEKISTAN";
	hot_btn2 = "Buyuk Hotel";
	hot_btn3 = "Grand Royal Hotel";
	hot_btn4 = "NULL";
	hot_btn5 = "NULL";
	hot_btn6 = "NULL";
	gtk_button_set_label(GTK_BUTTON(hot_but1), hot_btn1);
	gtk_button_set_label(GTK_BUTTON(hot_but2), hot_btn2);
	gtk_button_set_label(GTK_BUTTON(hot_but3), hot_btn3);
	gtk_button_set_label(GTK_BUTTON(hot_but4), hot_btn4);
	gtk_button_set_label(GTK_BUTTON(hot_but5), hot_btn5);
	gtk_button_set_label(GTK_BUTTON(hot_but6), hot_btn6);
	gtk_widget_hide(main_page);
	gtk_widget_show_all(client_service);
}

void on_nam_but_clicked(GtkButton *b){
	region = "Namangan";
	char mn[100], fl1[100], fl2[100], fl3[100], fl4[100], fl5[100];
	sprintf(mn, "%s%s%s","./Media/regions/",region, "/1000x700/1.jpeg");
	gtk_image_set_from_file(GTK_IMAGE(main_image), mn);
	memset(mn, 0, sizeof(mn));
	sprintf(fl1, "%s%s%s","./Media/regions/",region, "/240x190/1.jpeg");
	gtk_image_set_from_file(GTK_IMAGE(image1), fl1);
	memset(fl1, 0, sizeof(fl1));
	sprintf(fl2, "%s%s%s","./Media/regions/",region, "/240x190/2.jpeg");
	gtk_image_set_from_file(GTK_IMAGE(image2), fl2);
	memset(fl2, 0, sizeof(fl2));
	sprintf(fl3, "%s%s%s","./Media/regions/",region, "/240x190/3.jpeg");
	gtk_image_set_from_file(GTK_IMAGE(image3), fl3);
	memset(fl3, 0, sizeof(fl3));
	sprintf(fl4, "%s%s%s","./Media/regions/",region, "/240x190/4.jpeg");
	gtk_image_set_from_file(GTK_IMAGE(image4), fl4);
	memset(fl4, 0, sizeof(fl4));
	sprintf(fl5, "%s%s%s","./Media/regions/",region, "/240x190/5.jpeg");
	gtk_image_set_from_file(GTK_IMAGE(image5), fl5);
	memset(fl5, 0, sizeof(fl5));
	
	hot_btn1 = "Grand Sherdor Bouteque Hotel";
	hot_btn2 = "Shedevr Plaza Hotel";
	hot_btn3 = "Diyor Hotel";
	hot_btn4 = "Oydin Plaza Hotel";
	hot_btn5 = "NULL";
	hot_btn6 = "NULL";
	gtk_button_set_label(GTK_BUTTON(hot_but1), hot_btn1);
	gtk_button_set_label(GTK_BUTTON(hot_but2), hot_btn2);
	gtk_button_set_label(GTK_BUTTON(hot_but3), hot_btn3);
	gtk_button_set_label(GTK_BUTTON(hot_but4), hot_btn4);
	gtk_button_set_label(GTK_BUTTON(hot_but5), hot_btn5);
	gtk_button_set_label(GTK_BUTTON(hot_but6), hot_btn6);
	
	gtk_widget_hide(main_page);
	gtk_widget_show_all(client_service);
}

void on_nav_but_clicked(GtkButton *b){
	region = "Navoiy";
	char mn[100], fl1[100], fl2[100], fl3[100], fl4[100], fl5[100];
	sprintf(mn, "%s%s%s","./Media/regions/",region, "/1000x700/1.jpeg");
	gtk_image_set_from_file(GTK_IMAGE(main_image), mn);
	memset(mn, 0, sizeof(mn));
	sprintf(fl1, "%s%s%s","./Media/regions/",region, "/240x190/1.jpeg");
	gtk_image_set_from_file(GTK_IMAGE(image1), fl1);
	memset(fl1, 0, sizeof(fl1));
	sprintf(fl2, "%s%s%s","./Media/regions/",region, "/240x190/2.jpeg");
	gtk_image_set_from_file(GTK_IMAGE(image2), fl2);
	memset(fl2, 0, sizeof(fl2));
	sprintf(fl3, "%s%s%s","./Media/regions/",region, "/240x190/3.jpeg");
	gtk_image_set_from_file(GTK_IMAGE(image3), fl3);
	memset(fl3, 0, sizeof(fl3));
	sprintf(fl4, "%s%s%s","./Media/regions/",region, "/240x190/4.jpeg");
	gtk_image_set_from_file(GTK_IMAGE(image4), fl4);
	memset(fl4, 0, sizeof(fl4));
	sprintf(fl5, "%s%s%s","./Media/regions/",region, "/240x190/5.jpeg");
	gtk_image_set_from_file(GTK_IMAGE(image5), fl5);
	memset(fl5, 0, sizeof(fl5));
	
	hot_btn1 = "Zarafshon Hotel";
	hot_btn2 = "Grand M Hotel";
	hot_btn3 = "Kamilla Otel";
	hot_btn4 = "Tinchlik Plaza Hotel";
	hot_btn5 = "Firdavs Hotel";
	hot_btn6 = "Biryuza Hotel";
	gtk_button_set_label(GTK_BUTTON(hot_but1), hot_btn1);
	gtk_button_set_label(GTK_BUTTON(hot_but2), hot_btn2);
	gtk_button_set_label(GTK_BUTTON(hot_but3), hot_btn3);
	gtk_button_set_label(GTK_BUTTON(hot_but4), hot_btn4);
	gtk_button_set_label(GTK_BUTTON(hot_but5), hot_btn5);
	gtk_button_set_label(GTK_BUTTON(hot_but6), hot_btn6);
	
	gtk_widget_hide(main_page);
	gtk_widget_show_all(client_service);
}

void on_qash_but_clicked(GtkButton *b){
	region = "Qashqadaryo";
	char mn[100], fl1[100], fl2[100], fl3[100], fl4[100], fl5[100];
	sprintf(mn, "%s%s%s","./Media/regions/",region, "/1000x700/1.jpeg");
	gtk_image_set_from_file(GTK_IMAGE(main_image), mn);
	memset(mn, 0, sizeof(mn));
	sprintf(fl1, "%s%s%s","./Media/regions/",region, "/240x190/1.jpeg");
	gtk_image_set_from_file(GTK_IMAGE(image1), fl1);
	memset(fl1, 0, sizeof(fl1));
	sprintf(fl2, "%s%s%s","./Media/regions/",region, "/240x190/2.jpeg");
	gtk_image_set_from_file(GTK_IMAGE(image2), fl2);
	memset(fl2, 0, sizeof(fl2));
	sprintf(fl3, "%s%s%s","./Media/regions/",region, "/240x190/3.jpeg");
	gtk_image_set_from_file(GTK_IMAGE(image3), fl3);
	memset(fl3, 0, sizeof(fl3));
	sprintf(fl4, "%s%s%s","./Media/regions/",region, "/240x190/4.jpeg");
	gtk_image_set_from_file(GTK_IMAGE(image4), fl4);
	memset(fl4, 0, sizeof(fl4));
	sprintf(fl5, "%s%s%s","./Media/regions/",region, "/240x190/5.jpeg");
	gtk_image_set_from_file(GTK_IMAGE(image5), fl5);
	memset(fl5, 0, sizeof(fl5));
	hot_btn1 = "Sultan Hotel";
	hot_btn2 = "Hayot Hotel";
	hot_btn3 = "Nasaf Trevel Hotel";
	hot_btn4 = "Surbon Hotel";
	hot_btn5 = "Afrosiyob Hotel";
	hot_btn6 = "Afrosiyob Hotel";
	gtk_button_set_label(GTK_BUTTON(hot_but1), hot_btn1);
	gtk_button_set_label(GTK_BUTTON(hot_but2), hot_btn2);
	gtk_button_set_label(GTK_BUTTON(hot_but3), hot_btn3);
	gtk_button_set_label(GTK_BUTTON(hot_but4), hot_btn4);
	gtk_button_set_label(GTK_BUTTON(hot_but5), hot_btn5);
	gtk_button_set_label(GTK_BUTTON(hot_but6), hot_btn6);
	gtk_widget_hide(main_page);
	gtk_widget_show_all(client_service);
}


void on_sam_but_clicked(GtkButton *b){
	region = "Samarqand";
	char mn[100], fl1[100], fl2[100], fl3[100], fl4[100], fl5[100];
	sprintf(mn, "%s%s%s","./Media/regions/",region, "/1000x700/1.jpeg");
	gtk_image_set_from_file(GTK_IMAGE(main_image), mn);
	memset(mn, 0, sizeof(mn));
	sprintf(fl1, "%s%s%s","./Media/regions/",region, "/240x190/1.jpeg");
	gtk_image_set_from_file(GTK_IMAGE(image1), fl1);
	memset(fl1, 0, sizeof(fl1));
	sprintf(fl2, "%s%s%s","./Media/regions/",region, "/240x190/2.jpeg");
	gtk_image_set_from_file(GTK_IMAGE(image2), fl2);
	memset(fl2, 0, sizeof(fl2));
	sprintf(fl3, "%s%s%s","./Media/regions/",region, "/240x190/3.jpeg");
	gtk_image_set_from_file(GTK_IMAGE(image3), fl3);
	memset(fl3, 0, sizeof(fl3));
	sprintf(fl4, "%s%s%s","./Media/regions/",region, "/240x190/4.jpeg");
	gtk_image_set_from_file(GTK_IMAGE(image4), fl4);
	memset(fl4, 0, sizeof(fl4));
	sprintf(fl5, "%s%s%s","./Media/regions/",region, "/240x190/5.jpeg");
	gtk_image_set_from_file(GTK_IMAGE(image5), fl5);
	memset(fl5, 0, sizeof(fl5));
	
	hot_btn1 = "Registan Plaza";
	hot_btn2 = "Ideal Hotel";
	hot_btn3 = "Emirkan Hotel";
	hot_btn4 = "Malika Hotel";
	hot_btn5 = "Hotel DiliMah Hotel";
	hot_btn6 = "Alexander Hotel";
	gtk_button_set_label(GTK_BUTTON(hot_but1), hot_btn1);
	gtk_button_set_label(GTK_BUTTON(hot_but2), hot_btn2);
	gtk_button_set_label(GTK_BUTTON(hot_but3), hot_btn3);
	gtk_button_set_label(GTK_BUTTON(hot_but4), hot_btn4);
	gtk_button_set_label(GTK_BUTTON(hot_but5), hot_btn5);
	gtk_button_set_label(GTK_BUTTON(hot_but6), hot_btn6);
	
	gtk_widget_hide(main_page);
	gtk_widget_show_all(client_service);
}

void on_sir_but_clicked(GtkButton *b){
	region = "Sirdaryo";
	char mn[100], fl1[100], fl2[100], fl3[100], fl4[100], fl5[100];
	sprintf(mn, "%s%s%s","./Media/regions/",region, "/1000x700/1.jpeg");
	gtk_image_set_from_file(GTK_IMAGE(main_image), mn);
	memset(mn, 0, sizeof(mn));
	sprintf(fl1, "%s%s%s","./Media/regions/",region, "/240x190/1.jpeg");
	gtk_image_set_from_file(GTK_IMAGE(image1), fl1);
	memset(fl1, 0, sizeof(fl1));
	sprintf(fl2, "%s%s%s","./Media/regions/",region, "/240x190/2.jpeg");
	gtk_image_set_from_file(GTK_IMAGE(image2), fl2);
	memset(fl2, 0, sizeof(fl2));
	sprintf(fl3, "%s%s%s","./Media/regions/",region, "/240x190/3.jpeg");
	gtk_image_set_from_file(GTK_IMAGE(image3), fl3);
	memset(fl3, 0, sizeof(fl3));
	sprintf(fl4, "%s%s%s","./Media/regions/",region, "/240x190/4.jpeg");
	gtk_image_set_from_file(GTK_IMAGE(image4), fl4);
	memset(fl4, 0, sizeof(fl4));
	sprintf(fl5, "%s%s%s","./Media/regions/",region, "/240x190/5.jpeg");
	gtk_image_set_from_file(GTK_IMAGE(image5), fl5);
	memset(fl5, 0, sizeof(fl5));
	
	hot_btn1 = "NULL";
	hot_btn2 = "NULL";
	hot_btn3 = "NULL";
	hot_btn4 = "NULL";
	hot_btn5 = "NULL";
	hot_btn6 = "NULL";
	gtk_button_set_label(GTK_BUTTON(hot_but1), hot_btn1);
	gtk_button_set_label(GTK_BUTTON(hot_but2), hot_btn2);
	gtk_button_set_label(GTK_BUTTON(hot_but3), hot_btn3);
	gtk_button_set_label(GTK_BUTTON(hot_but4), hot_btn4);
	gtk_button_set_label(GTK_BUTTON(hot_but5), hot_btn5);
	gtk_button_set_label(GTK_BUTTON(hot_but6), hot_btn6);
	
	gtk_widget_hide(main_page);
	gtk_widget_show_all(client_service);
}

void on_sur_but_clicked(GtkButton *b){
	region = "Surxondaryo";
	char mn[100], fl1[100], fl2[100], fl3[100], fl4[100], fl5[100];
	sprintf(mn, "%s%s%s","./Media/regions/",region, "/1000x700/1.jpeg");
	gtk_image_set_from_file(GTK_IMAGE(main_image), mn);
	memset(mn, 0, sizeof(mn));
	sprintf(fl1, "%s%s%s","./Media/regions/",region, "/240x190/1.jpeg");
	gtk_image_set_from_file(GTK_IMAGE(image1), fl1);
	memset(fl1, 0, sizeof(fl1));
	sprintf(fl2, "%s%s%s","./Media/regions/",region, "/240x190/2.jpeg");
	gtk_image_set_from_file(GTK_IMAGE(image2), fl2);
	memset(fl2, 0, sizeof(fl2));
	sprintf(fl3, "%s%s%s","./Media/regions/",region, "/240x190/3.jpeg");
	gtk_image_set_from_file(GTK_IMAGE(image3), fl3);
	memset(fl3, 0, sizeof(fl3));
	sprintf(fl4, "%s%s%s","./Media/regions/",region, "/240x190/4.jpeg");
	gtk_image_set_from_file(GTK_IMAGE(image4), fl4);
	memset(fl4, 0, sizeof(fl4));
	sprintf(fl5, "%s%s%s","./Media/regions/",region, "/240x190/5.jpeg");
	gtk_image_set_from_file(GTK_IMAGE(image5), fl5);
	memset(fl5, 0, sizeof(fl5));
	
	hot_btn1 = "Surxan Hotel";
	hot_btn2 = "Asson Hotel";
	hot_btn3 = "Meridian Hotel";
	hot_btn4 = "Guliston Grand Hotel";
	hot_btn5 = "Grand Hotel";
	hot_btn6 = "Inrourist Hotel";
	gtk_button_set_label(GTK_BUTTON(hot_but1), hot_btn1);
	gtk_button_set_label(GTK_BUTTON(hot_but2), hot_btn2);
	gtk_button_set_label(GTK_BUTTON(hot_but3), hot_btn3);
	gtk_button_set_label(GTK_BUTTON(hot_but4), hot_btn4);
	gtk_button_set_label(GTK_BUTTON(hot_but5), hot_btn5);
	gtk_button_set_label(GTK_BUTTON(hot_but6), hot_btn6);
	
	gtk_widget_hide(main_page);
	gtk_widget_show_all(client_service);
}

void on_tash_but_clicked(GtkButton *b){
	region = "Tashkent";
	char mn[100], fl1[100], fl2[100], fl3[100], fl4[100], fl5[100];
	sprintf(mn, "%s%s%s","./Media/regions/",region, "/1000x700/1.jpeg");
	gtk_image_set_from_file(GTK_IMAGE(main_image), mn);
	memset(mn, 0, sizeof(mn));
	sprintf(fl1, "%s%s%s","./Media/regions/",region, "/240x190/1.jpeg");
	gtk_image_set_from_file(GTK_IMAGE(image1), fl1);
	memset(fl1, 0, sizeof(fl1));
	sprintf(fl2, "%s%s%s","./Media/regions/",region, "/240x190/2.jpeg");
	gtk_image_set_from_file(GTK_IMAGE(image2), fl2);
	memset(fl2, 0, sizeof(fl2));
	sprintf(fl3, "%s%s%s","./Media/regions/",region, "/240x190/3.jpeg");
	gtk_image_set_from_file(GTK_IMAGE(image3), fl3);
	memset(fl3, 0, sizeof(fl3));
	sprintf(fl4, "%s%s%s","./Media/regions/",region, "/240x190/4.jpeg");
	gtk_image_set_from_file(GTK_IMAGE(image4), fl4);
	memset(fl4, 0, sizeof(fl4));
	sprintf(fl5, "%s%s%s","./Media/regions/",region, "/240x190/5.jpeg");
	gtk_image_set_from_file(GTK_IMAGE(image5), fl5);
	memset(fl5, 0, sizeof(fl5));
	
	hot_btn1 = "Michelin Hotel";
	hot_btn2 = "WYNDHAM Hotel";
	hot_btn3 = "Hayatt Regency Hotel";
	hot_btn4 = "Simma Hotel";
	hot_btn5 = "Uzbekistan Hotel";
	hot_btn6 = "Hilton Hotel";
	gtk_button_set_label(GTK_BUTTON(hot_but1), hot_btn1);
	gtk_button_set_label(GTK_BUTTON(hot_but2), hot_btn2);
	gtk_button_set_label(GTK_BUTTON(hot_but3), hot_btn3);
	gtk_button_set_label(GTK_BUTTON(hot_but4), hot_btn4);
	gtk_button_set_label(GTK_BUTTON(hot_but5), hot_btn5);
	gtk_button_set_label(GTK_BUTTON(hot_but6), hot_btn6);
	
	gtk_widget_hide(main_page);
	gtk_widget_show_all(client_service);
}

void on_xor_but_clicked(GtkButton *b){
	region = "Xorazm";
	char mn[100], fl1[100], fl2[100], fl3[100], fl4[100], fl5[100];
	sprintf(mn, "%s%s%s","./Media/regions/",region, "/1000x700/1.jpeg");
	gtk_image_set_from_file(GTK_IMAGE(main_image), mn);
	memset(mn, 0, sizeof(mn));
	sprintf(fl1, "%s%s%s","./Media/regions/",region, "/240x190/1.jpeg");
	gtk_image_set_from_file(GTK_IMAGE(image1), fl1);
	memset(fl1, 0, sizeof(fl1));
	sprintf(fl2, "%s%s%s","./Media/regions/",region, "/240x190/2.jpeg");
	gtk_image_set_from_file(GTK_IMAGE(image2), fl2);
	memset(fl2, 0, sizeof(fl2));
	sprintf(fl3, "%s%s%s","./Media/regions/",region, "/240x190/3.jpeg");
	gtk_image_set_from_file(GTK_IMAGE(image3), fl3);
	memset(fl3, 0, sizeof(fl3));
	sprintf(fl4, "%s%s%s","./Media/regions/",region, "/240x190/4.jpeg");
	gtk_image_set_from_file(GTK_IMAGE(image4), fl4);
	memset(fl4, 0, sizeof(fl4));
	sprintf(fl5, "%s%s%s","./Media/regions/",region, "/240x190/5.jpeg");
	gtk_image_set_from_file(GTK_IMAGE(image5), fl5);
	memset(fl5, 0, sizeof(fl5));
	hot_btn1 = "Fayz Hotel";
	hot_btn2 = "Islambek Hotel";
	hot_btn3 = "Xorezm Palas Hotel";
	hot_btn4 = "Uzbekistan Hotel";
	hot_btn5 = "Asia Khiva Hotel";
	hot_btn6 = "Malika Khiva Hotel";
	gtk_button_set_label(GTK_BUTTON(hot_but1), hot_btn1);
	gtk_button_set_label(GTK_BUTTON(hot_but2), hot_btn2);
	gtk_button_set_label(GTK_BUTTON(hot_but3), hot_btn3);
	gtk_button_set_label(GTK_BUTTON(hot_but4), hot_btn4);
	gtk_button_set_label(GTK_BUTTON(hot_but5), hot_btn5);
	gtk_button_set_label(GTK_BUTTON(hot_but6), hot_btn6);
	gtk_widget_hide(main_page);
	gtk_widget_show_all(client_service);
}

void on_img_but1_clicked(GtkButton *b){
	char file[100];
	sprintf(file, "%s%s%s","./Media/regions/",region, "/1000x700/1.jpeg");
	gtk_image_set_from_file(GTK_IMAGE(main_image), file);
}
void on_img_but2_clicked(GtkButton *b){
	char file[100];
	sprintf(file, "%s%s%s","./Media/regions/",region, "/1000x700/2.jpeg");
	gtk_image_set_from_file(GTK_IMAGE(main_image), file);
}

void on_img_but3_clicked(GtkButton *b){
	char file[100];
	sprintf(file, "%s%s%s","./Media/regions/",region, "/1000x700/3.jpeg");
	gtk_image_set_from_file(GTK_IMAGE(main_image), file);
}
void on_img_but4_clicked(GtkButton *b){
	char file[100];
	sprintf(file, "%s%s%s","./Media/regions/",region, "/1000x700/4.jpeg");
	gtk_image_set_from_file(GTK_IMAGE(main_image), file);
}
void on_img_but5_clicked(GtkButton *b){
	char file[100];
	sprintf(file, "%s%s%s","./Media/regions/",region, "/1000x700/5.jpeg");
	gtk_image_set_from_file(GTK_IMAGE(main_image), file);
}


void on_back_clicked(GtkButton *b){
	gtk_widget_hide(client_service);
	gtk_widget_show(main_page);
}
//hotel buttons
void on_hot_but1_clicked(GtkButton *b){
	char file[100];
	sprintf(file, "%s%s%s","./Media/hotels/",region,"/1.jpg");
	printf("hotel path: %s\n", file);
	gtk_image_set_from_file(GTK_IMAGE(hotel_image), file);
}
void on_hot_but2_clicked(GtkButton *b){
	char file[100];
	sprintf(file, "%s%s%s","./Media/hotels/",region,"/2.jpg");
	gtk_image_set_from_file(GTK_IMAGE(hotel_image), file);
}
void on_hot_but3_clicked(GtkButton *b){
	char file[100];
	sprintf(file, "%s%s%s","./Media/hotels/",region,"/3.jpg");
	gtk_image_set_from_file(GTK_IMAGE(hotel_image), file);
}
void on_hot_but4_clicked(GtkButton *b){
	char file[100];
	sprintf(file, "%s%s%s","./Media/hotels/",region,"/4.jpg");
	gtk_image_set_from_file(GTK_IMAGE(hotel_image), file);
}
void on_hot_but5_clicked(GtkButton *b){
	char file[100];
	sprintf(file, "%s%s%s","./Media/hotels/",region,"/5.jpg");
	gtk_image_set_from_file(GTK_IMAGE(hotel_image), file);
}
void on_hot_but6_clicked(GtkButton *b){
	char file[100];
	sprintf(file, "%s%s%s","./Media/hotels/",region,"/6.jpg");
	gtk_image_set_from_file(GTK_IMAGE(hotel_image), file);
}

void on_fill_form_clicked(GtkButton *b){
	gtk_widget_hide(client_service);
	gtk_widget_show_all(form);
}

void on_cancel_clicked(GtkButton *b){
	gtk_widget_hide(form);
	gtk_widget_show(main_page);
}

void on_submit_clicked(GtkButton *b){
	//submiting form
	char buffer[1024];
	time_t current_time = time(NULL);
        struct tm *tm = localtime(&current_time);
	int id_num;
	id_num  = rand() % (9999+ 1 - 1000) + 1000;
	sprintf(buffer, "%d,%s,%s,%s,%s,%s,%s,%s,%s,%s", id_num, 
	gtk_entry_get_text(GTK_ENTRY(full_name)),
	gtk_entry_get_text(GTK_ENTRY(addr_live)),
	gtk_entry_get_text(GTK_ENTRY(phone_number)),
	gtk_entry_get_text(GTK_ENTRY(email)),
	gtk_entry_get_text(GTK_ENTRY(regions)),
	gtk_entry_get_text(GTK_ENTRY(gr_fml_al)),
	gtk_entry_get_text(GTK_ENTRY(sour)),
	gtk_entry_get_text(GTK_ENTRY(date)),
	asctime(tm));	
	send(clientSocket, buffer, sizeof(buffer), 0);
	gtk_widget_hide(form);
	gtk_widget_show(finish);
	
	
}
void on_destroy(){
	gtk_main_quit();
}
void on_finish_clicked(GtkButton *b){
	gtk_main_quit();
}


