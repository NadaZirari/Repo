#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define NB_DEPARTEMENTS 6


struct Datenaissance {

int j;
int m;
int a;

};

struct Etudiant{
    int numero;
    char nom[50];
    char prenom[50];
    struct  Datenaissance date;
    char departement[100];
    float note_generale;
    };
struct Etudiant e[100];

char departements[NB_DEPARTEMENTS][100] = {"informatique", "maths","physique", "economie", "biologie", "chimie"};

int nbretudiant=0;
int id = 1;

// Fonctiond de vérification si un étudiant existe déjà ou non
int etudiantExiste(int num) {
    for(int i = 0; i < nbretudiant; i++)
        if(e[i].numero == num)
            return i;
    return -1;
}

// Fonction pour ajouter un étudiant
void ajouter_etudiant() {

    int n;

    printf("Combien des etudiants voulez-vous ajouter?");
    scanf("%d",&n);

    while(n <= 0) {
        printf("Erreur!!!: Veuillez entrez un nombre strictement positif!!!! ");
        scanf("%d", &n);
    }
    for(int i=0;i<n;i++){
    e[nbretudiant].numero = id++;
    printf("Nom: ");
    scanf(" %[^\n]s", e[nbretudiant].nom);
     getchar();
    printf("Prenom: ");
    scanf(" %[^\n]s", e[nbretudiant].prenom);
    getchar();
    printf("Saisir la date de naissance:\n");
    printf("entrer le Jour");
    scanf("%d", &e[nbretudiant].date.j);
     getchar();
    printf(" entrer le Mois  ");
    scanf("%d", &e[nbretudiant].date.m);
    getchar();
    printf("entrer l'Année ");
    scanf("%d", &e[nbretudiant].date.a);
    getchar();
    printf("Departement: ");
    scanf("%[^\n]s", e[nbretudiant].departement);
    getchar();
    printf("entrer la Note generale: ");
    scanf("%f", &e[nbretudiant].note_generale);

    printf(" le %d Etudiant ajoute avec succes!\n",i+1);
    nbretudiant++;
    }
}
   
// Fonction pour modifier un étudiant
void modifier_etudiant() {
    int num;
    printf("Entrez le numero unique de l'etudiant a modifier: ");
    scanf("%d", &num);
  while(etudiantExiste(num) == -1) {
        printf("Erreur!!!: Etudiant non trouvé, veuillez saisir un autre numéro ===> ");
        scanf("%d", &num);
    }
    int choix;
    int cnt = 0;
    int index = etudiantExiste(num);
    printf("Voulez-vous modifier le nom? 1 ===> ");
    printf("Voulez-vous modifier le prénom? 2 ===> ");
    printf("Voulez-vous modifier la date de naissance? 3 ===> ");
    printf("Voulez-vous modifier le département? 4 ===> ");
    printf("Voulez-vous modifier la note générale?5===> ");
    scanf(" %d", &choix);
    switch (choix)
    {
    case 1:
         printf("Saisir le nouveau nom ===> ");
        scanf(" %[^\n]s", e[index].nom);
        cnt++;
        break;
     case 2:
     printf("Saisir le nouveau prénom ===> ");
        scanf(" %[^\n]s", e[index].prenom);
        cnt++;
     break;
     case 3:
      printf("Jour ===> ");
        scanf("%d", &e[index].date.j);
        printf("Mois ===> ");
        scanf("%d", &e[index].date.m);
        printf("Année ===> ");
        scanf("%d", &e[index].date.a);
        cnt++;
     break;
     case 4:
      printf("Saisir le nouveau département ===> ");
        scanf(" %[^\n]s", e[index].departement);
        cnt++;
     break;
     case 5:
     printf("Saisir la nouvelle note ===> ");
        scanf("%f", &e[index].note_generale);
        cnt++;
     break;
    default:
     printf("Choix invalide. Veuillez réessayer.\n");
        break;
    }
   
   
   
   

    if(cnt != 0) {
        printf("Etudiant modifié avec succès!\n");
    }else
    printf("Modification annulée.");

   
}


void supprimer_etudiant() {
    int numero;
   
    printf("Entrez le numero unique de l'etudiant a supprimer: ");
    scanf("%d", &numero);
 while(etudiantExiste(numero) == -1) {
        printf("Erreur: Etudiant non trouvé, veuillez saisir un autre numéro ===> ");
        scanf("%d", &numero);
    }
int index = etudiantExiste(numero);
    char choix;
    printf("Voulez-vous vraiement supprimer cet étudiant? (o/y) ===> ");
    scanf(" %c", &choix);

   if(choix == 'o') {
        for(int i = index; i < nbretudiant - 1; i++)
            e[i] = e[i + 1];
        nbretudiant--;
        printf("Etudiant(e) supprimé(e) avec succès!\n");
    } else
     printf("Suppression annulée.");
    }


// Fonction pour afficher les étudiants


void afficherTousEtudiants() {
    printf("\nListe des étudiants:\n");
    printf("Numéro \t Nom \t Prénom \t Date de Naissance \t Note Générale \t Departement\n");
    printf("---------------------------------------------------------------\n");

    for (int i = 0; i < nbretudiant; i++) {
        printf("%d \t %s \t\t %s \t %d/%d/%d \t\t %.2f\n \t%s\n",e[i].numero, e[i].nom, e[i].prenom, e[i].date.j, e[i].date.m, e[i].date.a, e[i].note_generale,e[i].departement);
    }
}


void  afficher_Un_seul_etudiant() {
    int numero;
        printf("Entrez le numero unique de l'etudiant a afficher: ");
        scanf("%d", &numero);

        for (int i = 0; i < nbretudiant; i++) {
            if (e[i].numero == numero) {
                printf("\nNumero: %d\n", e[i].numero);
                printf("Nom: %s\n", e[i].nom);
                printf("Prenom: %s\n", e[i].prenom);
                printf("Date de naissance: %d/%d/%d\n", e[i].date.j, e[i].date.m, e[i].date.a);

                printf("Departement: %s\n", e[i].departement);
                printf("Note generale: %.2f\n", e[i].note_generale);
                return;
            }
        }
        printf("Etudiant non trouve.\n");
    }
   

// Nombre d'étudiants dans un département
int nbEtudiantDepartement(char dep[]) {
    int nbetuDep = 0;
    for(int i = 0; i < nbretudiant; i++)  // Boucle sur nbretudiant
        if(strcmp(e[i].departement, dep) == 0)
            nbetuDep++;
    return nbetuDep;
}


int AfficherMenuCalcul() {
    int choix;

    printf("Que voulez vous calculer ?\n");
    printf("\t1. La moyenne generale d'un departement\n");
    printf("\t2. La moyenne generale de toute l'universite\n");

    printf("Entrez votre choix: ");
    scanf("%d", &choix);
    getchar();

    return choix;

}
int AfficherMenuDep() {
    int choix;

    printf("\tLes departements possibles: \n");
    for (int i = 0; i < 6; i++)
        printf("\t%d. %s\n", i + 1, departements[i]);

    printf("\t\nEntrez le numéro du département choisi: ");
    scanf("%d", &choix);
    getchar();

    return choix;
}
// Calcul de la moyenne générale de l'université entière
void CalculerMoyenne() {
    int choix, cpt = 0;
    float m, S = 0.0;

    choix = AfficherMenuCalcul();
   
    if (choix == 1) {
        printf("Quel departement voulez-vous calculer sa moyenne:\n");
        choix = AfficherMenuDep();

        for (int i = 0; i < nbretudiant; i++) {
            if (strcmp(e[i].departement, departements[choix - 1]) == 0) {
                S += e[i].note_generale;
                cpt++;
            }
        }
       

        if (cpt > 0) {
            m = S / cpt;
            printf("La moyenne de departement %s est: %.2f\n", departements[choix - 1], m);
        }
        else
            printf("Il n'y a aucun etudiant dans ce departement.\n");
    }
   
    else if (choix == 2) {
        for (int i = 0; i < nbretudiant; i++) {
            S += e[i].note_generale;
            cpt++;
        }
        m = (float) S / cpt;
        printf("La moyenne generale de l'universite est: %.2f\n", m);
    }

    else
        printf("Choix invalide.\n");
}



//partie 2



// Nombre d'étudiants réussi dans un département
int nbEtudReussiDep(char dep[]) {
    int nb = 0;
    for(int i = 0; i < nbretudiant; i++)
        if(strcmp(e[i].departement, dep) == 0 && e[i].note_generale >= 10)
            nb++;
    return nb;
}

void afficher_nombre_total_etudiants() {
    printf("Le nombre total d'etudiants inscrits est: %d\n", nbretudiant);
}

void afficher_nombre_etudiants_par_departement() {
    int nombreParDepartement[NB_DEPARTEMENTS] = {0};  // Tableau pour stocker le nombre d'étudiants par département

    // Compter le nombre d'étudiants dans chaque département
    for (int i = 0; i < nbretudiant; i++) {
        for (int j = 0; j < NB_DEPARTEMENTS; j++) {
            if (strcmp(e[i].departement, departements[j]) == 0) {
                nombreParDepartement[j]++;
                break;
            }
        }
    }

    printf("Nombre d'etudiants par departement:\n");
    for (int j = 0; j < NB_DEPARTEMENTS; j++) {
        printf("%s: %d etudiants\n", departements[j], nombreParDepartement[j]);
    }
}

void afficher_etudiants_sup_seuil(float seuil) {
    int etudiantsTrouves = 0;  // Variable pour compter le nombre d'étudiants trouvés
    printf("Etudiants ayant une moyenne generale superieure à %.2f:\n", seuil);
   
    for (int i = 0; i < nbretudiant; i++) {
        if (e[i].note_generale >= seuil) {
            etudiantsTrouves = 1;
            printf("\nNumero: %d\n", e[i].numero);
            printf("Nom: %s\n", e[i].nom);
            printf("Prenom: %s\n", e[i].prenom);
            printf("Date de naissance: %d/%d/%d\n", e[i].date.j, e[i].date.m, e[i].date.a);
            printf("Departement: %s\n", e[i].departement);
            printf("Note generale: %.2f\n", e[i].note_generale);
        }
    }
   
    if (!etudiantsTrouves) {
        printf("Aucun etudiant n'a une moyenne superieure a %.2f\n", seuil);
    }
}


void afficher_top_3_etudiants() {
    if (nbretudiant < 3) {
        printf("Il y a moins de 3 etudiants inscrits.\n");
        return;
    }

    // Créer une copie du tableau d'étudiants pour pouvoir trier sans modifier l'original
    struct Etudiant temp[100];
    for (int i = 0; i < nbretudiant; i++) {
        temp[i] = e[i];
    }

    // Tri par sélection des étudiants par note générale (ordre décroissant)
    for (int i = 0; i < nbretudiant - 1; i++) {
        for (int j = i + 1; j < nbretudiant; j++) {
            if (temp[i].note_generale < temp[j].note_generale) {
                struct Etudiant etuTemp = temp[i];
                temp[i] = temp[j];
                temp[j] = etuTemp;
            }
        }
    }

    /* Tri par sélection : Utilisé pour afficher les 3 étudiants ayant les meilleures notes.
    trouve l'élément le plus petit (ou le plus grand, selon l'ordre)
    à chaque itération et en le plaçant à la bonne position.
    Afficher top 3*/
    printf("Les 3 etudiants ayant les meilleures notes sont :\n");
    for (int i = 0; i < 3; i++) {
        printf("\n%d) Numero: %d\n", i + 1, temp[i].numero);
        printf("Nom: %s\n", temp[i].nom);
        printf("Prenom: %s\n", temp[i].prenom);
        printf("Date de naissance: %d/%d/%d\n", temp[i].date.j, temp[i].date.m, temp[i].date.a);
        printf("Departement: %s\n", temp[i].departement);
        printf("Note generale: %.2f\n", temp[i].note_generale);
    }
}

void afficherEtudiantsReussisParDepartement() {
    printf("\nNombre d'étudiants ayant réussi par département:\n");
    for(int i = 0; i < NB_DEPARTEMENTS; i++) {
        int nbReussi = 0;
        for(int j = 0; j < nbretudiant; j++) {
            // Vérification du département et de la note générale
            if(strcmp(e[j].departement, departements[i]) == 0 && e[j].note_generale >= 10) {
                nbReussi++;
            }
        }
        printf("Département %s: %d étudiants ont réussi.\n", departements[i], nbReussi);
    }
}

void rechercherEtudiantParNom() {
    char nomRecherche[50];
    printf("Entrez le nom de l'étudiant à rechercher: ");
    scanf(" %[^\n]s", nomRecherche);  // Lire le nom avec espaces

    int trouve = 0;  // Indicateur pour savoir si l'étudiant a été trouvé

    for (int i = 0; i < nbretudiant; i++) {
        // Comparer le nom de l'étudiant avec le nom recherché
        if (strcasecmp(e[i].nom, nomRecherche) == 0) {  // Utilisation de strcasecmp pour une comparaison insensible à la casse
            printf("\nInformations sur l'étudiant:\n");
            printf("Numero: %d\n", e[i].numero);
            printf("Nom: %s\n", e[i].nom);
            printf("Prenom: %s\n", e[i].prenom);
            printf("Date de naissance: %d/%d/%d\n", e[i].date.j, e[i].date.m, e[i].date.a);
            printf("Departement: %s\n", e[i].departement);
            printf("Note generale: %.2f\n", e[i].note_generale);
            trouve = 1;  // L'étudiant a été trouvé
        }
    }

    if (!trouve) {
        printf("Aucun étudiant avec le nom '%s' n'a été trouvé.\n", nomRecherche);

    }
   
}

void afficherEtudiantsParDepartement() {
    char departementRecherche[100];
    printf("Entrez le nom du département pour afficher les étudiants: ");
    scanf(" %[^\n]s", departementRecherche);  // Lire le nom du département avec espaces

    int trouve = 0;  // Indicateur pour savoir si des étudiants ont été trouvés

    printf("\nListe des étudiants dans le département %s:\n", departementRecherche);
    printf("Numéro \t Nom \t\t Prénom \t Date de Naissance \t Note Générale \t Departement\n");
    printf("---------------------------------------------------------------\n");

    for (int i = 0; i < nbretudiant; i++) {
        // Vérifier si l'étudiant appartient au département recherché
        if (strcmp(e[i].departement, departementRecherche) == 0) {
            printf("%d \t %s \t\t %s \t\t %d/%d/%d \t\t %.2f \t %s\n",
                   e[i].numero, e[i].nom, e[i].prenom, e[i].date.j, e[i].date.m, e[i].date.a, e[i].note_generale,e[i].departement);
            trouve = 1;  // L'étudiant a été trouvé
        }void trierEtudiantsParNom(int ordreCroissant) {
    for (int i = 0; i < nbretudiant - 1; i++) {
        for (int j = 0; j < nbretudiant - i - 1; j++) {
            int comparaison;
            if (ordreCroissant) {
                comparaison = strcmp(e[j].nom, e[j + 1].nom);
            } else {
                comparaison = strcmp(e[j + 1].nom, e[j].nom);
            }

            if (comparaison > 0) {
                // Échanger les étudiants
                struct Etudiant temp = e[j];
                e[j] = e[j + 1];
                e[j + 1] = temp;
            }
        }
    }
    printf("Étudiants triés par nom.\n");
}
    }

    if (!trouve) {
        printf("Aucun étudiant inscrit dans le département '%s'.\n", departementRecherche);
    }
}
// Fonction pour trier les étudiants par nom *bulle*!!!.
void trierEtudiantsParNom(int ordreCroissant) {
    for (int i = 0; i < nbretudiant - 1; i++) {
        for (int j = 0; j < nbretudiant - i - 1; j++) {
            int comparaison;
            if (ordreCroissant) {
                comparaison = strcmp(e[j].nom, e[j + 1].nom);
            } else {
                comparaison = strcmp(e[j + 1].nom, e[j].nom);
            }

            if (comparaison > 0) {
                // Échanger les étudiants
                struct Etudiant temp = e[j];
                e[j] = e[j + 1];
                e[j + 1] = temp;
            }
        }
    }
    printf("Étudiants triés par nom.\n");
}

// Fonction pour trier les étudiants par note générale*bulle!!!*
void trierEtudiantsParMoyenneGenerale(int ordreCroissant) {
    for (int i = 0; i < nbretudiant - 1; i++) {
        for (int j = 0; j < nbretudiant - i - 1; j++) {
            int comparaison;
            if (ordreCroissant) {
                comparaison = e[j].note_generale > e[j + 1].note_generale;
            } else {
                comparaison = e[j].note_generale < e[j + 1].note_generale;
            }

            if (comparaison) {
                // Échanger les étudiants
                struct Etudiant temp = e[j];
                e[j] = e[j + 1];
                e[j + 1] = temp;
            }
        }
    }
    printf("Étudiants triés par note générale.\n");
}
void afficher_info_etudiant (){
    int choix;
    printf("voulez vous afficher 1 seul etudiant(1) ou bien tout (2)?");
    scanf("%d",&choix);
    if(choix==1){
        afficher_Un_seul_etudiant();
    }else{
 
      afficherTousEtudiants();}}
// Fonction pour afficher les étudiants
void afficherEtudiants() {
    printf("\nListe des étudiants:\n");
    printf("Numéro \t Nom \t\t Prénom \t Date de Naissance \t Note Générale \t Departement\n");
    printf("---------------------------------------------------------------\n");

    for (int i = 0; i < nbretudiant; i++) {
        printf("%d \t %s \t\t %s \t\t %d/%d/%d \t\t %.2f \t\t %s \t\n",
               e[i].numero, e[i].nom, e[i].prenom, e[i].date.j, e[i].date.m, e[i].date.a, e[i].note_generale,e[i].departement);
    }
}



// Fonction pour trier les étudiants par statut de réussite
void trierEtudiantsParStatutReussite() {
    for (int i = 0; i < nbretudiant - 1; i++) {
        for (int j = 0; j < nbretudiant - i - 1; j++) {
            int reussi1 = e[j].note_generale >= 10;
            int reussi2 = e[j + 1].note_generale >= 10;

            if (reussi1 < reussi2) {
                // Échanger les étudiants
                struct Etudiant temp = e[j];
                e[j] = e[j + 1];
                e[j + 1] = temp;
            }
        }
    }
    printf("Étudiants triés par statut de réussite.\n");
    afficherEtudiants();
}
void afficher_menu_trier(){
int sousChoix;
                    printf("Choisissez le type de tri:\n");
                    printf("1. Tri alphabétique des noms (A-Z ou Z-A)\n");
                    printf("2. Tri par moyenne générale (du plus élevé au plus faible ou inversement)\n");
                    printf("3. Tri selon le statut de réussite\n");
                    printf("Votre choix : ");
                    scanf("%d", &sousChoix);
                   
                    switch(sousChoix) {
                        case 1:
                            {
                                int ordre;
                                printf("Trier par nom (0 pour A-Z, 1 pour Z-A) : ");
                                scanf("%d", &ordre);
                                trierEtudiantsParNom(ordre);
                                for (int i = 0; i < nbretudiant; i++) {
       
           printf("%d \t %s \t\t %s \t\t %d/%d/%d \t\t %.2f \t %s \t\n",
                   e[i].numero, e[i].nom, e[i].prenom, e[i].date.j, e[i].date.m, e[i].date.a, e[i].note_generale,e[i].departement);}
                            }
                            break;
                        case 2:
                            {
                                int ordre;
                                printf("Trier par moyenne générale (0 pour croissant, 1 pour décroissant) : ");
                                scanf("%d", &ordre);
                                trierEtudiantsParMoyenneGenerale(ordre);
                                for (int i = 0; i < nbretudiant; i++) {
       
           printf("%d \t %s \t\t %s \t\t %d/%d/%d \t\t %.2f \t %s \t \n",
                   e[i].numero, e[i].nom, e[i].prenom, e[i].date.j, e[i].date.m, e[i].date.a, e[i].note_generale,e[i].departement);}
                            }
                            break;
                        case 3:
                            trierEtudiantsParStatutReussite();
                            for (int i = 0; i < nbretudiant; i++) {
       
           printf("%d \t %s \t\t %s \t\t %d/%d/%d \t\t %.2f \t %s \t\n",
                   e[i].numero, e[i].nom, e[i].prenom, e[i].date.j, e[i].date.m, e[i].date.a, e[i].note_generale,e[i].departement);}
                            break;
                        default:
                            printf("Choix invalide.\n");
                            break;
                    }
                }
 
void Modifier_ou_supprimer_etudiant(){

    int choix;

    while (1)
    {
        printf("1. Modifier un etudiant\n");
        printf("2. Supprimer un etudiant\n");
        printf("3. Retour au menu principale\n");

        printf("Votre choix : ");
        scanf("%d", &choix);


        switch (choix)
        {
        case 1:
            modifier_etudiant();
            break;
        case 2:
            supprimer_etudiant();
            break;
        case 3:
            return; // Retoure au menu principale
       
        default:
            break;
        }
    }
   
}

void EtudiantParSeuil() {
    float seuil;

    printf("Entrez le seuil: ");
    scanf("%f", &seuil);
    getchar();
 afficher_etudiants_sup_seuil(seuil);
    for (int i = 0; i < nbretudiant; i++) {
        if (e[i].note_generale >= seuil)
           printf("%d \t %s \t\t %s \t\t %d/%d/%d \t\t %.2f \t %s \t\n",
                   e[i].numero, e[i].nom, e[i].prenom, e[i].date.j, e[i].date.m, e[i].date.a, e[i].note_generale,e[i].departement);
    }
}
 

void Statistiques() {
    int choix=-1;
   
    printf("Statistiques:\n");
    printf("\t nombre total d'etudiants? [1]");
     printf("\n\tAfficher le nombre d'etudiants qui ont reusssi dans chaque departement  [2]\n");
     printf("\n\tLe nombre d'etudiants dans chaque departement est [3]:\n");
      printf("\n\tAfficher les 3 etudiants ayant la meilleur note [4]\n");
      printf("\tAfficher les etudiants ayant une moyenne superieure a un certain seuil [5]\n");
printf("entrer un choix:\n");
scanf("%d",&choix);
switch(choix) {
case 1:

    printf("\tLe nombre total d'etudiants est: %d\n", nbretudiant);
break;
case 2:
 afficherEtudiantsReussisParDepartement();
break;
case 3:
 afficher_nombre_etudiants_par_departement();
break;
    EtudiantParSeuil();
case 4:
afficher_top_3_etudiants();
break;
case 5:
   EtudiantParSeuil();
   break;
    afficherEtudiantsReussisParDepartement();
     default:
    printf("Choix invalide. Veuillez réessayer.\n");
  break;
}}

int AfficherMenuRecherche() {
    int choix;

    printf("Que voulez-vous rechercher ?\n");
    printf("\t1. Par nom\n");
    printf("\t2. Par departement\n");

    printf("Entrez votre choix: ");
    scanf("%d", &choix);
    getchar();

    return choix;
}

void RechercherEtudiant() {
    char nom[30], departement[50];
    int choix, cpt = 0;

    choix = AfficherMenuRecherche();

    if (choix == 1) {
        printf("Entrez le nom de l'etudiant: ");
        scanf("%[^\n]", nom);
        getchar();

        for (int i = 0; i < nbretudiant; i++) {
            if (strcmp(e[i].nom, nom) == 0) {
                printf("Etudiant %d:\n", i + 1);
                printf("%d \t %s \t\t %s \t\t %d/%d/%d \t\t %.2f \t %s \t\n",
                   e[i].numero, e[i].nom, e[i].prenom, e[i].date.j, e[i].date.m, e[i].date.a, e[i].note_generale,e[i].departement);
                cpt++;
            }
        }
        if (cpt == 0)
                printf("Etudiant non trouvé\n");
    }

    else if (choix == 2) {
        printf("Entrez le departement: ");
        scanf("%[^\n]", departement);
        getchar();

        for (int i = 0; i < nbretudiant; i++) {
            if (strcmp(e[i].departement, departement) == 0) {
                printf("Etudiant %d:\n", i + 1);
                printf("%d \t %s \t\t %s \t\t %d/%d/%d \t\t %.2f \t %s \t\n",
                   e[i].numero, e[i].nom, e[i].prenom, e[i].date.j, e[i].date.m, e[i].date.a, e[i].note_generale,e[i].departement);
                cpt++;
            }
        }
        if (cpt == 0)
            printf("Departement non trouvé\n");
    }

    else
        printf("Choix invalide.\n");

}
void afficherMenu() {
    printf("****************Menu Principal:*******************************************\n");
    printf("1. Ajouter un etudiant\n");
    printf("2. Modifier ou supprimerun etudiant\n");
    printf("3. Afficher info etudiants \n");
    printf("4. Afficher statistique etudiants \n");
    printf("5. Calculer la moyenne generale d'un departement \n");
    printf("6. Rechercher un etudiant \n");
    printf("7. Trier les etudiants par \n");
    printf("0. Quitter\n");
     printf("***************************************************************\n");
    printf("****choisissez une option (0-7) : ");
}

int main() {
    int choix;
   
    do {
        afficherMenu();
        scanf("%d", &choix);

        switch(choix) {
            case 1:
                ajouter_etudiant();
                break;
            case 2:
                Modifier_ou_supprimer_etudiant();
                break;
            case 3:
               afficher_info_etudiant();
                break;
           
            case 4:
            Statistiques();
       
                break;
                 

            case 5:
               AfficherMenuRecherche();
                break;
           
                case 6:
                AfficherMenuRecherche();
                break;
                case 7:
                afficher_menu_trier();
                break;
           
            case 0:
                printf("Merci !\n");
                break;
            default:
                printf("Choix invalide. Veuillez réessayer.\n");
                break;
        }
       
    } while (choix != 0);

    return 0;
}
