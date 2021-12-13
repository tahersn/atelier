#include <gtk/gtk.h>
typedef struct {
 char ID[30];
 char type[30];
 char etat[30];
 char valeur[30];


} capteur;

void capteur_affiche(GtkWidget *liste);


void capteur_recherche(GtkWidget *liste,char ID[]);

void capteur_modifier(capteur c ,char ID[]);

void capteur_supprimer(char ID[]);

void capteur_ajouter(capteur c);
bool reche(char ID1[]);
void afficherrr(GtkWidget *liste);
 

typedef struct {
int jour;
int heure;
int numcap;
float valucap;
}temperature;
void capteurdef();






