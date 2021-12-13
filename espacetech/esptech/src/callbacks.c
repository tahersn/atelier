#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
#include <stdbool.h>

#include "callbacks.h"
#include"fonction.h"
#include "interface.h"
#include "support.h"




void
on_button1_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{GtkWidget *window_ajout;
window_ajout=create_Ajout();
gtk_widget_show(window_ajout);
}


void
on_button2_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window_suppr;
window_suppr=create_suppression();
gtk_widget_show(window_suppr);
}


void
on_button3_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window_modif;
window_modif=create_modification();
gtk_widget_show(window_modif);
}

char ID[30];

void
on_button4_clicked                     (GtkButton       *objet,
                                        gpointer         user_data)
{GtkWidget *id,*affiche,*treeview,*affiche1; 

id=lookup_widget(objet,"entry1"); 
strcpy(ID,gtk_entry_get_text(GTK_ENTRY(id)));


affiche=lookup_widget(objet,"affiche");

affiche1=create_affiche();

gtk_widget_show(affiche1);

gtk_widget_hide(affiche);

treeview=lookup_widget(affiche1,"treeview1");

capteur_recherche(treeview,ID);


}





int typ;
int choix;
void
on_button5_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *id,*val,*warn,*windowajout;
capteur c;
char TYPE[30];
char ETAT[30];
char ID[30],type[30],etat[30],valeur[30];
id = lookup_widget (button,"entry3");
if (typ==1)
{strcpy(TYPE,"Actif");}
else if (typ==2)
{strcpy(TYPE,"Passif");}
if (choix==1)
{strcpy(ETAT,"Bonne");}
else if (choix==2)
{strcpy(ETAT,"Deffectueux");}
val = lookup_widget (button,"entry4");
strcpy(c.ID,gtk_entry_get_text(GTK_ENTRY(id)));
strcpy(c.type,TYPE);
strcpy(c.etat,ETAT);
strcpy(c.valeur,gtk_entry_get_text(GTK_ENTRY(val)));
capteur_ajouter(c);
warn=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"Capteur ajouté avec succeès");
	switch(gtk_dialog_run(GTK_DIALOG(warn)))
	{
	case GTK_RESPONSE_OK:
	gtk_widget_destroy(warn);
	break;}




}


void
on_button6_clicked                     (GtkButton       *objet,
                                        gpointer         user_data)
{

GtkWidget *Ajout;


Ajout=lookup_widget(objet,"Ajout");
gtk_widget_hide(Ajout);
}


void
on_button8_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{GtkWidget *id,*warn;
char ID[30];
id = lookup_widget (button,"entry5");
strcpy(ID,gtk_entry_get_text(GTK_ENTRY(id)));
capteur_supprimer(ID);
warn=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"Supprimé avec succeès");
	switch(gtk_dialog_run(GTK_DIALOG(warn)))
	{
	case GTK_RESPONSE_OK:
	gtk_widget_destroy(warn);
	break;
	}


}


void
on_button9_clicked                     (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *suppression;
suppression=lookup_widget(objet,"suppression");
gtk_widget_hide(suppression);



}


void
on_button7_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button10_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button11_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *id,*ii,*vv,*warn;
char ID[30];
char ee[30];
char tt [30];
capteur c;
id = lookup_widget (button,"entry6");
ii = lookup_widget (button,"entry7");
if (typ==1)
{strcpy(tt,"Actif");}
else if (typ==2)
{strcpy(tt,"Passif");}
if (choix==1)
{strcpy(ee,"Deffectueu");}
else if (choix==2)
{strcpy(ee,"Bonne");}
vv = lookup_widget (button,"entry8");
strcpy(ID,gtk_entry_get_text(GTK_ENTRY(id)));
strcpy(c.ID,gtk_entry_get_text(GTK_ENTRY(ii)));
strcpy(c.type,tt);
strcpy(c.etat,ee);
strcpy(c.valeur,gtk_entry_get_text(GTK_ENTRY(vv)));
capteur_modifier(c,ID);
warn=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"Modifié avec succeès");
	switch(gtk_dialog_run(GTK_DIALOG(warn)))
	{
	case GTK_RESPONSE_OK:
	gtk_widget_destroy(warn);
	break;
	}

}


void
on_button12_clicked                    (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *modification;
modification=lookup_widget(objet,"modification");
gtk_widget_destroy(modification);

}


void
on_afficher_clicked                    (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *affiche;
GtkWidget *treeview1;
affiche=lookup_widget(objet,"affiche");

gtk_widget_destroy(affiche);
affiche=lookup_widget(objet,"affiche");
affiche=create_affiche();
gtk_widget_show(affiche);
treeview1=lookup_widget(affiche,"treeview1");
capteur_affiche(treeview1);
}


void
on_radio1_toggled                      (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
typ=1;

}

void
on_radio2_toggled                      (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
typ=2;

}
void
on_radiobutton4_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
typ=1;

}


void
on_radiobutton5_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
typ=2;
}

int choix;

void
on_checkbutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton))
choix=1;

}


void
on_checkbutton2_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton))
choix=2;

}


void
on_checkbutton4_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton))
choix=1;

}


void
on_checkbutton3_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton))
choix=2;

}





void
on_button_actu_clicked                 (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *affiche;
GtkWidget *treeview1;
affiche=lookup_widget(objet,"affiche");

gtk_widget_destroy(affiche);
affiche=lookup_widget(objet,"affiche");
affiche=create_affiche();
gtk_widget_show(affiche);
treeview1=lookup_widget(affiche,"treeview1");
capteur_affiche(treeview1);
}


void
on_cptdef_clicked                      (GtkButton       *objet,
                                        gpointer         user_data)
{
char jjj[30];
char hhh[30];
char numr[30];
char vale[30];
int cond1=10;
int cond2=30;
int nb=0;

GtkWidget *treeview2;
GtkWidget *affiche;
GtkWidget *cptdef;
FILE *T,*FL ;
T = fopen ("temperature.txt", "r");
FL= fopen ("temp.txt", "w+");
if((FL!=NULL)&&(T!=NULL))
{
while (fscanf(T,"%s %s %s %s\n",jjj,hhh,numr,vale)!=EOF )
{
int c=atoi(vale);
if (cond1>c || c>cond2)
{

fprintf(FL,"%s %s %s %s\n",jjj,hhh,numr,vale);
//nb+=1;}

}
}
  
  fclose(T);

fclose(FL);
}


affiche=lookup_widget(objet,"affiche");
 cptdef= create_cptdef ();
  gtk_widget_show (cptdef);

treeview2=lookup_widget(cptdef,"treeview2");
afficherrr(treeview2);

}


void
on_retourcptdef_clicked                (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *cptdef;
cptdef=lookup_widget(objet,"cptdef");
gtk_widget_hide(cptdef);

}





void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
gchar* id;
capteur c;
GtkWidget *warn;
GtkWidget *window_suppr;

GtkTreeModel *Model = gtk_tree_view_get_model(treeview);
	if (gtk_tree_model_get_iter(Model,&iter,path)){
			gtk_tree_model_get(GTK_LIST_STORE(Model),&iter,0,&id,-1);
                        strcpy(c.ID,id);
warn=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_QUESTION,GTK_BUTTONS_YES_NO,"Vouler vous vraiment supprimer se produit ?");
	switch(gtk_dialog_run(GTK_DIALOG(warn)))
	{
	case GTK_RESPONSE_NO:
	gtk_widget_destroy(warn);
	break;
	case GTK_RESPONSE_YES:
	gtk_widget_destroy(warn);
	capteur_supprimer(id);
	break;
			
}

}
}

