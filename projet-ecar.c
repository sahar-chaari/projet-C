#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define Nvoitures 100
#define Nhistorique 150
#define MaxLoueur 100

typedef struct
{
    int identifiant_voiture;
    char matricule_voiture[20] ;
    char modele[20];
    char marque[20];
    char couleur[20];
    char date_fabrication[20];
    char energie[20];
    int kilometrage;
    int nb_chevaux;
    int prix_location_jour;
    int disponibilite;       // 1 = "disponible" et 0 = "louee"
    int etat;               // 1 = "en marche" et 0 = "en panne"
} voiture ;

typedef struct
{
    int identifiant_voiture;
    int identifiant_location;
    char nom_loueur[20];
    char date_location[10];
    char date_retour[10];
    char reclamation[100];
} historique_location;

typedef struct
{
    char nom_prenom[20];
    char nom_utilisateur[20];
    char mot_de_passe[20];
    char Num_tell[12];
    char adresse[50];
}loueur ;

voiture voitures[Nvoitures];
historique_location historique[Nhistorique];
loueur loueurs[MaxLoueur];
int iL=0;
int Lvoitures=0;
int Lhistorique=0;

void Menu();
void ajouter_voiture();
void location_voiture();
void description_voiture();
void supprimer_voiture_en_panne();
void modifier_description_etat();
void historique_location_jour();
void historique_location_mois();
void retour_voiture();
void inscription_loueur();
void connexion();
void loueur_historique();

int main(void)
{
    printf("\n Bienvenue A E-car \n");

    printf("Avez vous un compte (tapez 1 si oui et 0 si non): ");
    int reponse;
    scanf("%d",&reponse);
    while (reponse != 0 && reponse != 1)
    {
    printf("Reponse invalide. Veuillez reessayer : ");
    scanf("%d",&reponse);
    }

    if (reponse==1)
        connexion();
    else if (reponse==0)
    {
        inscription_loueur();
        connexion();
    }

    int choix;
    do {
        Menu();
        printf("Entrez votre choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                ajouter_voiture();
                break;
            case 2:
                location_voiture();
                break;
            case 3:
                description_voiture();
                break;
            case 4:
                supprimer_voiture_en_panne();
                break;
            case 5:
                modifier_description_etat();
                break;
            case 6:
                historique_location_jour();
                break;
            case 7:
                historique_location_mois();
                break;
            case 8:
                retour_voiture();
                break;
            case 9:
                loueur_historique();
                break;
            case 10:
                printf("Sortie du programme.\n");
                break;
            default:
                printf("Choix invalide. Veuillez reessayer.\n");
        }
    } while (choix != 10);

    return 0;
}

void Menu()
{
    printf("\n  Menu \n");
    printf("1. Ajouter une voiture\n");
    printf("2. Louer une voiture\n");
    printf("3. Afficher la description d'une voiture\n");
    printf("4. Supprimer une voiture en panne\n");
    printf("5. Modifier la description et l'etat d'une voiture\n");
    printf("6. Afficher l'historique des locations par jour\n");
    printf("7. Afficher l'historique des locations par mois\n");
    printf("8. Retour d'une voiture\n");
    printf("9. Afficher l'historique du loueur \n");
    printf("10. Quitter\n");
}

void ajouter_voiture()
{
    printf("Entrez l'identifiant de la voiture : \n",voitures[Lvoitures].identifiant_voiture);
    scanf("%d", &voitures[Lvoitures].identifiant_voiture);
    printf("Entrez le modele de la voiture : \n",voitures[Lvoitures].modele);
    scanf("%s", voitures[Lvoitures].modele);
    printf("Entrez la marque de la voiture : \n",voitures[Lvoitures].marque);
    scanf("%s", voitures[Lvoitures].marque);
    printf("Entrez le couleur de la voiture : \n",voitures[Lvoitures].couleur);
    scanf("%s", voitures[Lvoitures].couleur);
    printf("Entrez le date de fabrication de la voiture : \n",voitures[Lvoitures].date_fabrication);
    scanf("%s", voitures[Lvoitures].date_fabrication);
    printf("Entrez l'energie de la voiture : \n",voitures[Lvoitures].energie);
    scanf("%s", voitures[Lvoitures].energie);
    printf("Entrez la matricule de la voiture : \n",voitures[Lvoitures].matricule_voiture);
    scanf("%s", voitures[Lvoitures].matricule_voiture);
    printf("Entrez le kilometrage de la voiture : \n",voitures[Lvoitures].kilometrage);
    scanf("%d", &voitures[Lvoitures].kilometrage);
    printf("Entrez le nombre de chevaux de la voiture : \n",voitures[Lvoitures].nb_chevaux);
    scanf("%d", &voitures[Lvoitures].nb_chevaux);
    printf("Entrez le prix de location par jour de la voiture : \n",voitures[Lvoitures].prix_location_jour);
    scanf("%d", &voitures[Lvoitures].prix_location_jour);
    printf("Entrez la disponibilite de la voiture : \n",voitures[Lvoitures].disponibilite);
    scanf("%d", &voitures[Lvoitures].disponibilite);
    printf("Entrez l'etat de la voiture : \n",voitures[Lvoitures].etat);
    scanf("%d", &voitures[Lvoitures].etat);
    Lvoitures++;
    printf("Voiture ajoutee avec succees");
}


void location_voiture()
{
    char msg[100];
    char nom[20];
    char date[10];
    int l=-1;
    int identif_voiture;
    printf("Entrez l'identifiant de la voiture que vous souhaitez louer : ");
    scanf("%d", &identif_voiture);
    for (int i=0; i<Lvoitures; i++)
    {
        if(identif_voiture==voitures[i].identifiant_voiture)
        {
            if ( voitures[i].disponibilite==1)
            {
                printf("Cette voiture est disponible pour location, Veuillez completer les procedures de location \n");
                printf("Entrez votre nom d'utilisateur: ");
                scanf("%s",nom);
                strcpy(historique[Lhistorique].nom_loueur, nom);
                printf("Entrez la date de debut de location (sous la forme'JJ/MM/AAAA') : \n");
                scanf("%s",date);
                strcpy(historique[Lhistorique].date_location,date);
                voitures[i].disponibilite=0;
                historique[Lhistorique].identifiant_voiture=identif_voiture;
                historique[Lhistorique].identifiant_location=Lhistorique;
                printf("Location reussite, votre identifiant de location est %d . Bienvenue!", Lhistorique);
                Lhistorique++;
                l++;
                break;
            }
            else if( voitures[i].disponibilite==0)
            {
            strcpy(msg,"Cette voirture n'est pas disponible.\n");
            break;
            }
        }
        else{
           strcpy(msg,"Identif de voiture invalide.\n");
        }
    }
    if (l==-1)
        printf("%s",msg);
}

void description_voiture()
{
    int identif;
    char msg[100];
    int j=-1;
    printf("Entrez l'identifiant de la voiture dont vous souhaitez voir la description : ");
    scanf("%d", &identif);
    for (int i=0; i<Lvoitures; i++)
    {
        if (identif==voitures[i].identifiant_voiture)
        {
            printf("Modele : %s \n", voitures[i].modele);
            printf("Marque : %s \n", voitures[i].marque);
            printf("Couleur : %s \n", voitures[i].couleur);
            printf("Date de fabrication : %s \n", voitures[i].date_fabrication);
            printf("Energie : %s \n", voitures[i].energie);
            printf("Disponibilite (Disponible=1/Louee=0) : %d \n", voitures[i].disponibilite);
            printf("Etat (en marche=1/en panne=0) : %d \n", voitures[i].etat);
            printf("Matricule : %s \n", voitures[i].matricule_voiture);
            printf("Kilometrage : %d ", voitures[i].kilometrage);
            printf("klm. \n");
            printf("Nombres de chevaux : %d \n", voitures[i].nb_chevaux);
            printf("Prix de location par jour : %d ", voitures[i].prix_location_jour);
            printf("dt. \n");
            j=0;
            break ;
        }
        else
            strcpy(msg,"Identif de voiture invalide.\n");
    }
    if(j==-1)
        printf("%s",msg);

}

void supprimer_voiture_en_panne()
{
   int panne=-1;
   for (int i=0; i<Lvoitures; i++)
   {
       if (voitures[i].etat==0)
       {
        printf("la voiture d'identifiant %d de la marque %s est supprimee a cause d'une panne \n", voitures[i].identifiant_voiture, voitures[i].marque);
        Lvoitures--;
        panne++;
        for (int j=i; j<Lvoitures-1; j++)
        {
            voitures[j]=voitures[j+1];
        }
       }
   }
   if (panne==-1)
       printf("Aucune voiture en panne");

}

void modifier_description_etat()
{
    int id;
    printf("Entrez l'identifiant de la voiture dont vous souhaitez modifier la description ou l'etat : ");
    scanf("%d", &id);
    for (int i=0; i<Lvoitures; i++)
    {
        if (id==voitures[i].identifiant_voiture)
        {
            int choix2;
            do {
                printf("1. Modele \n");
                printf("2. Marque \n");
                printf("3. Couleur \n");
                printf("4. Date de fabrication \n");
                printf("5. Energie \n");
                printf("6. Kilométrage \n");
                printf("7. Nombres de chevaux \n");
                printf("8. Prix de location par jour \n");
                printf("9. Disponibilité \n");
                printf("10. Etat \n");
                printf("11. Sortie du programme \n");
                printf("Entrez le numéro de description que vous desirez modifier : \n");
                scanf("%d", &choix2);

            switch (choix2) {
            case 1:
                printf("Entrez le nouveau modele de la voiture (ancien modele : %s) : ",voitures[i].modele);
                scanf("%s", voitures[i].modele);
                break;
            case 2:
                printf("Entrez la nouvelle marque de la voiture (ancienne marque : %s) : ",voitures[i].marque);
                scanf("%s", voitures[i].marque);
                break;
            case 3:
                printf("Entrez le nouveau couleur de la voiture (ancien couleur : %s) : ",voitures[i].couleur);
                scanf("%s", voitures[i].couleur);
                break;
            case 4:
                printf("Entrez la nouvelle date de fabrication de la voiture (ancienne date : %s) : ",voitures[i].date_fabrication);
                scanf("%s", voitures[i].date_fabrication);
                break;
            case 5:
                printf("Entrez la nouvelle energie de la voiture (ancienne energie : %s) : ",voitures[i].energie);
                scanf("%s", voitures[i].energie);
                break;
            case 6:
                printf("Entrez le nouveau kilometrage de la voiture (ancien kilometrage : %d) : ",voitures[i].kilometrage);
                scanf("%d", &voitures[i].kilometrage);
                break;
            case 7:
                printf("Entrez le nouveau nombre de chevaux de la voiture (ancien nombre de chevaux : %d) : ",voitures[i].nb_chevaux);
                scanf("%d", &voitures[i].nb_chevaux);
                break;
            case 8:
                printf("Entrez le nouveau prix de location par jour de la voiture (ancien prix de location par jour : %d) : ",voitures[i].prix_location_jour);
                scanf("%d", &voitures[i].prix_location_jour);
                break;
            case 9:
                printf("Entrez la nouvelle disponibilite de la voiture (Disponible=1/Louée=0) : ");
                scanf("%d", &voitures[i].disponibilite);
                break;
            case 10:
                printf("Entrez le nouvel etat de la voiture (en marche=1/en panne=0) : ");
                scanf("%d", &voitures[i].etat);
                break;
            case 11:
                printf("Sortie du programme.\n");
                break;
            default:
                printf("Choix invalide. Veuillez reessayer.\n");
            }
            } while (choix2 != 11);


        }
    }
}

void historique_location_jour()
{
    int l=0;
    if (Lhistorique==0)
        printf("Aucune location enregistree.\n");
    else
    {
        char date[10];
        printf("Entrez la date pour afficher l'historique quotidien (sous la forme: JJ/MM/AAAA): \n");
        scanf("%s", date);
        printf("Historique des locations pour la date %s :\n", date);
        for (int i=0;i<Lhistorique;i++)
        {
            if(strcmp(historique[i].date_location, date) == 0)
            {
                printf("identifiant du location: %d, identifiant de voiture louee : %d , nom loueur : %s\n", historique[i].identifiant_location,historique[i].identifiant_voiture,historique[i].nom_loueur);
                l++;
            }
        }
        if(l==0)
            printf("Aucune location enregistree dans ce jour.\n");
    }
}

void historique_location_mois()
{
    if (Lhistorique==0)
        printf("Aucune location enregistree.\n");
    else
    {
        int mois, annee;
        printf("Entrez le mois (1-12) et l'annee (aaaa) pour afficher l'historique mensuel : ");
        scanf("%d %d", &mois, &annee);
        printf("\n Historique des locations pour le mois %d de l'annee %d :\n", mois, annee);
        int l=0;
        for (int i = 0; i < Lhistorique; i++)
        {
            int mois_location, annee_location;
            sscanf(historique[i].date_location, "%d/%*d/%d", &mois_location, &annee_location);

            if (annee_location==annee && mois_location==mois)
            {
                printf("identifiant du location: %d", historique[i].identifiant_location);
                printf("identifiant de voiture louee : %d" ,historique[i].identifiant_voiture );
                printf("nom loueur : %s",historique[i].nom_loueur);
                printf("date de location: %s",historique[i].date_location);
                printf("date de retour: %s",historique[i].date_retour);
                l++;
            }

        }
        if (l==0)
            printf("Aucune location enregistree en ce mois.\n");
    }
}

void retour_voiture()
{
    char date[10];
    char message[100];
    int id_loc;
    printf("Entrez l'ID de la location pour le retour :");
    scanf("%d",&id_loc);
    for (int i=0; i<Lhistorique; i++)
    {
        if (id_loc==historique[i].identifiant_location)
        {
            int idv=historique[i].identifiant_voiture;
            int j=0;
            while (idv!=voitures[j].identifiant_voiture)
                j++;
            if (voitures[j].disponibilite==0)
            {
                strcpy(message,"La voiture a ete retournee avec succes.\n");
                printf("Entrer la date de fin de location (sous la forme'JJ/MM/AAAA') : \n");
                scanf("%s",date);
                strcpy(historique[i].date_retour,date);
                voitures[j].disponibilite = 1;
            }
            else
                strcpy(message,"Erreur : La voiture n'est pas actuellement louee.\n");
            break;
        }
        else
            strcpy(message,"ID de location invalide.\n");
    }
    printf("%s",message);
}

void inscription_loueur()
{
    printf("Entrez votre nom et prenom (sans des espaces) : \n");
    scanf("%s", loueurs[iL].nom_prenom);
    printf("Entrez un nom d'utilisateur (sans des espaces): \n");
    scanf("%s", loueurs[iL].nom_utilisateur);
    printf("Entrez un mot de passe (sans des espaces): \n");
    scanf("%s", loueurs[iL].mot_de_passe);
    printf("Entrez votre numero de telephone : \n");
    scanf("%s", loueurs[iL].Num_tell);
    printf("Entrez votre adresse : \n");
    scanf("%s", loueurs[iL].adresse);
    printf("Inscription reussie. Bienvenue, %s! \n",loueurs[iL].nom_prenom);
    iL++;
}

void connexion()
{
    char nom_ut[20];
    char mdp[20];
    printf("Entrez votre nom d'utilisateur : \n");
    scanf("%s", nom_ut);
    printf("Entrez votre mot de passe : \n");
    scanf("%s", mdp);
    for (int i = 0; i <iL; i++)
    {
        if (strcmp(nom_ut, loueurs[i].nom_utilisateur)==0 && strcmp(mdp, loueurs[i].mot_de_passe)==0)
        {
            printf("Connexion reussie. Bienvenue, %s!\n", loueurs[i].nom_prenom);
            break;
        }
        else
        {
            printf("Echec de la connexion. Nom d'utilisateur ou mot de passe incorrect. Veuillez reessayer.\n");
            connexion();
        }
    }
}

void loueur_historique()
{
    printf("authentification");
    char nom_ut[20];
    char mdp[20];
    printf("Entrez votre nom d'utilisateur : ");
    scanf("%s", nom_ut);
    printf("Entrez votre mot de passe : ");
    scanf("%s", mdp);
    int index=-1;
    for (int i = 0; i <iL; i++)
    {
        if (strcmp(nom_ut, loueurs[i].nom_utilisateur)==0 && strcmp(mdp, loueurs[i].mot_de_passe)==0)
        {
            printf("utilisateur authentifie");
            index = i;
            break;
        }
    }
    if (index==-1)
    {
        printf("Echec de la connexion. Nom d'utilisateur ou mot de passe incorrect.\n");
        return;
    }
    printf("\n Historique de location pour l'utilisateur %s :\n", loueurs[index].nom_prenom);
    for (int i=0; i<Lhistorique; i++)
    {
        if (strcmp(loueurs[index].nom_prenom,historique[i].nom_loueur)==0)
        {
            printf("identifiant du location: %d", historique[i].identifiant_location);
            printf("identifiant de voiture louee : %d" ,historique[i].identifiant_voiture );
            printf("date de location: %s",historique[i].date_location);
            printf("date de retour: %s",historique[i].date_retour);
        }
    }
}
