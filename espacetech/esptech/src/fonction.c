

#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>
#include <gtk/gtk.h>
#include <string.h>
#include"fonction.h"


void capteur_ajouter(capteur c)
{
FILE*f;

char ID[30];
f=fopen("capteur.txt","a+");

if (f!=NULL)
{

fprintf(f,"%s %s %s %s \n",c.ID,c.type,c.etat,c.valeur);
}
fclose(f);

}
void capteur_modifier(capteur c ,char ID[])

{

    capteur c1;
    FILE *f;
    FILE *f2;
    f=fopen("capteur.txt","r");
    f2=fopen("capteur1.txt","w");

       while
        (fscanf(f,"%s %s %s %s \n",c1.ID,c1.type,c1.etat,c1.valeur)!=EOF)
        {

            if
            (strcmp(c1.ID,ID)==0)
             
            {

fprintf(f2,"%s %s %s %s  \n",c.ID,c.type,c.etat,c.valeur);}
else /*rien ne change*/
            
fprintf(f2,"%s %s %s %s \n",c1.ID,c1.type,c1.etat,c1.valeur);       
  }  
        fclose(f);    
        fclose(f2);
        remove("capteur.txt");
        rename("capteur1.txt","capteur.txt");
    
}

void capteur_supprimer(char ID[])
{
     capteur c;

    FILE*f=NULL;
    FILE*f1=NULL;

    f=fopen("capteur.txt","r");
    f1=fopen("capteur1.txt","a+");
if(f==NULL || f1==NULL)
{ 
return;
}
else
{
    
 while(fscanf(f,"%s %s %s %s  \n",c.ID,c.type,c.etat,c.valeur)!=EOF)
        {
            if(strcmp(ID,c.ID)!=0)
fprintf(f1,"%s %s %s %s  \n",c.ID,c.type,c.etat,c.valeur);
}
        fclose(f);
        fclose(f1);
        remove("capteur.txt");
        rename("capteur1.txt","capteur.txt");
    
    }
}

 
/*bool reche (char ID1[])
{//debut
capteur c;
char ID [30];
char type[30];
char etat[30];
char valeur[30] ;
char reche=false;

    FILE*f=NULL;

    f=fopen("capteur.txt","r");

if(f==NULL)
{ 
return;
}
else
{//else
    
 while(fscanf(f,"%s %s %s %s \n",ID,type,etat,valeur)!=EOF)
        {//while
            if(strcmp(ID1,ID)==0){
           reche=true;}
            
}//else
        
 
fclose(f);
}
return (reche);
}//fin*/

void capteur_recherche(GtkWidget *liste,char ID[])
{
enum
{
	id,         
        TYPE,
     	ETAT,  
        VALEUR,
	
	COLUMNS
};
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;	
GtkListStore *store;
/*
char type[30];
char etat[30];
char valeur[30] ;
*/

store =NULL;

FILE *f;

store=gtk_tree_view_get_model(liste);
if(store==NULL)
{
	renderer=gtk_cell_renderer_text_new();
	
	column=gtk_tree_view_column_new_with_attributes("ID",renderer,"text",id,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("type",renderer,"text",TYPE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);
	
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("etat",renderer,"text",ETAT,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	
	
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("valeur",renderer,"text",VALEUR,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	
	

char id1[100];
char etat1[100];
char valeur1[100];
char type1[100];
	


	store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

	f=fopen("capteur.txt","r");

	
	
	
		while(fscanf(f,"%s %s %s %s \n",id1,type1,etat1,valeur1)!=EOF)
                       {
			if (strcmp(ID,id1)==0){ 
			gtk_list_store_append(store,&iter);
			gtk_list_store_set(store,&iter,id,id1,TYPE,type1,ETAT,etat1,VALEUR,valeur1,-1);
		}
	   fclose(f);
	gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
	
	
}
}
}



void capteur_affiche(GtkWidget *liste )
{

enum
{
	id,         
        TYPE,
     	ETAT,  
        VALEUR,
	
	COLUMNS
};

GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;	
GtkListStore *store;

char ID [30];
char type[30];
char etat[30];
char valeur[30] ;

store =NULL;

FILE *f;

store=gtk_tree_view_get_model(liste);
if(store==NULL)
{
	renderer=gtk_cell_renderer_text_new();
	
	column=gtk_tree_view_column_new_with_attributes("ID",renderer,"text",id,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("type",renderer,"text",TYPE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);
	
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("etat",renderer,"text",ETAT,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	
	
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("valeur",renderer,"text",VALEUR,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	
	

       
	


	store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

	f=fopen("capteur.txt","r");

	if(f==NULL)
	{
		return;
	}
	else
	
	{ 
	f=fopen("capteur.txt","a+");
		while(fscanf(f,"%s %s %s %s \n",ID,type,etat,valeur)!=EOF)
		{
			gtk_list_store_append(store,&iter);
			gtk_list_store_set(store,&iter,id,ID,TYPE,type,ETAT,etat,VALEUR,valeur,-1);
		}
	   fclose(f);
	gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
	
	}
}
}

 
/*void capteurdef()
{
FILE *f,*g;
f=fopen("temperature.txt","r");
g=fopen("capteurdefectueux.txt","a+");
temperature t,T[5000];
int i=0,n=0,nb=0;
if(f!=NULL)
{
while(!feof(f))
{
fscanf(f,"%d %d %d %f\n",&t.jour,&t.heure,&t.numcap,&t.valucap);
T[i].jour=t.jour;
T[i].heure=t.heure;
T[i].numcap=t.numcap;
T[i].valucap=t.valucap;
i++;
}
fclose(f);
n=i;
}
for(i=0;i<n;i++)
{
if (T[i].valucap<0 || T[i].valucap>30)
{
fprintf(g,"%d %d %d %f\n",T[i].jour,T[i].heure,T[i].numcap,T[i].valucap);
nb++;
}
}
printf("le nombre des capteurs defectueux est:%d/%d\n",nb,n);
}*/
void afficherrr(GtkWidget *liste)
{



GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;
enum
{
	JOUR,         
        HEURE,
     	NUMERO,  
        VALEUR,
		
	COLUMNS
};

char jjj[30];
char hhh[30];
char numr[30];
char vale[30];


store =NULL;

FILE *FL;
//FILE *f;

store=gtk_tree_view_get_model(liste);
if(store==NULL)
{
	renderer=gtk_cell_renderer_text_new();

	
	
	
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("JOUR",renderer,"text",jjj,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	
	
	
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("HEURE",renderer,"text",hhh,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("NUMERO",renderer,"text",numr,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("VALEUR",renderer,"text",vale,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	
	

       
	


	store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

	FL=fopen("temp.txt","r");

	if(FL==NULL)
	{
		return;
	}
	else
	
	{ 
	FL=fopen("temp.txt","r");
		while(fscanf(FL,"%s %s %s %s\n",jjj,hhh,numr,vale)!=EOF)
		{
			gtk_list_store_append(store,&iter);
			gtk_list_store_set(store,&iter, jjj,JOUR,hhh,HEURE,numr,NUMERO,vale,VALEUR,-1);}

		fclose(FL);
	gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
	g_object_unref(store);
	}}}












