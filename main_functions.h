
char *region;
char *hot_btn1, *hot_btn2, *hot_btn3, *hot_btn4, *hot_btn5, *hot_btn6;

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
	time_t current_time = time(NULL);
        struct tm *tm = localtime(&current_time);
	int id_num;
	id_num  = rand() % (9999999999999999 + 1 - 1000000000000000) + 1000000000000000;
	printf("%d | %s | %s | %s | %s | %s | %s | %s | %s | %s", id_num, 
	gtk_entry_get_text(GTK_ENTRY(full_name)),
	gtk_entry_get_text(GTK_ENTRY(addr_live)),
	gtk_entry_get_text(GTK_ENTRY(phone_number)),
	gtk_entry_get_text(GTK_ENTRY(email)),
	gtk_entry_get_text(GTK_ENTRY(regions)),
	gtk_entry_get_text(GTK_ENTRY(date)),
	gtk_entry_get_text(GTK_ENTRY(gr_fml_al)),
	gtk_entry_get_text(GTK_ENTRY(sour)),
	asctime(tm));
	
	gtk_widget_hide(form);
	gtk_widget_show(main_page);
}




