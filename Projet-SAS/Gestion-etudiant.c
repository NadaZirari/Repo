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
    printf("Entrer le Numero unique du %d etudiant: ",i+1);
    scanf("%d", &e[nbretudiant].numero);
    while(etudiantExiste(e[nbretudiant].numero) != -1) {
        printf("Cet étudiant est déjà enregistré, Veuillez entrez un autre numéro ===> ");
        scanf("%d", &e[nbretudiant].numero);
    }
    printf("Nom: ");
    scanf(" %[^\n]s", e[nbretudiant].nom);
    printf("Prenom: ");
    scanf(" %[^\n]s", e[nbretudiant].prenom);

     printf("Saisir la date de naissance:\n");
    printf("entrer le Jour");
    scanf("%d", &e[nbretudiant].date.j);
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
    char choix;
    int cnt = 0;
    int index = etudiantExiste(num);
    printf("Voulez-vous modifier le nom? cliquer o pour modifier sinon n (o/n) ===> ");
    scanf(" %c", &choix);
    if(choix == 'o') {
        printf("Saisir le nouveau nom ===> ");
        scanf(" %[^\n]s", e[index].nom);
        cnt++;
    }
    printf("Voulez-vous modifier le prénom? cliquer o pour modifier sinon n (o/n) ===> ");
    scanf(" %c", &choix);
    if(choix == 'o') {
        printf("Saisir le nouveau prénom ===> ");
        scanf(" %[^\n]s", e[index].prenom);
        cnt++;
    }
    printf("Voulez-vous modifier la date de naissance? cliquer o pour modifier sinon n (o/n) ===> ");
    scanf(" %c", &choix);
    if(choix == 'o') {
        printf("Jour ===> ");
        scanf("%d", &e[index].date.j);
        printf("Mois ===> ");
        scanf("%d", &e[index].date.m);
        printf("Année ===> ");
        scanf("%d", &e[index].date.a);
        cnt++;
    }
    printf("Voulez-vous modifier le département? cliquer (o) pour modifier sinon (n) (o/n)! ===> ");
    scanf(" %c", &choix);
    if(choix == 'o') {
        printf("Saisir le nouveau département ===> ");
        scanf(" %[^\n]s", e[index].departement);
        cnt++;
    }
    printf("Voulez-vous modifier la note générale? cliquer (o) pour modifier sinon (n) (o/n) !===> ");
    scanf(" %c", &choix);
    if(choix == 'o') {
        printf("Saisir la nouvelle note ===> ");
        scanf("%f", &e[index].note_generale);
        cnt++;
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
    printf("Numéro \t Nom \t\t Prénom \t Date de Naissance \t Note Générale\n");
    printf("---------------------------------------------------------------\n");

    for (int i = 0; i < nbretudiant; i++) {
        printf("%d \t %s \t\t %s \t\t %d/%d/%d \t\t %.2f\n",e[i].numero, e[i].nom, e[i].prenom, e[i].date.j, e[i].date.m, e[i].date.a, e[i].note_generale);
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

// Calcul de la moyenne générale d'un département
float MGDepartement(char dep[]) {
    float sum = 0;
    for(int i = 0; i < nbretudiant; i++) {
        if(strcmp(e[i].departement, dep) == 0) {
            sum += e[i].note_generale;
        }
    }
   int nb = nbEtudiantDepartement(dep);
if(nb == 0){

 return 0;// Pour éviter la division par zéro
 }  
return sum / nb;
}

// Calcul de la moyenne générale de l'université entière

float moyenneGeneraleUniversite() {
    float sum = 0;
int totalEtudiants = 0;
for(int i = 0; i < NB_DEPARTEMENTS; i++) {
    int etudiantsDep = nbEtudiantDepartement(departements[i]);
    if(etudiantsDep > 0) {
        sum += MGDepartement(departements[i]) * etudiantsDep;
        totalEtudiants += etudiantsDep;
    }
}
if(totalEtudiants == 0) return 0;  // Aucun étudiant
return sum / totalEtudiants;
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
        if (e[i].note_generale > seuil) {
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
    printf("Numéro \t Nom \t\t Prénom \t Date de Naissance \t Note Générale\n");
    printf("---------------------------------------------------------------\n");

    for (int i = 0; i < nbretudiant; i++) {
        // Vérifier si l'étudiant appartient au département recherché
        if (strcmp(e[i].departement, departementRecherche) == 0) {
            printf("%d \t %s \t\t %s \t\t %d/%d/%d \t\t %.2f\n",
                   e[i].numero, e[i].nom, e[i].prenom, e[i].date.j, e[i].date.m, e[i].date.a, e[i].note_generale);
            trouve = 1;  // L'étudiant a été trouvé
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

// Fonction pour afficher les étudiants
void afficherEtudiants() {
    printf("\nListe des étudiants:\n");
    printf("Numéro \t Nom \t\t Prénom \t Date de Naissance \t Note Générale\n");
    printf("---------------------------------------------------------------\n");

    for (int i = 0; i < nbretudiant; i++) {
        printf("%d \t %s \t\t %s \t\t %d/%d/%d \t\t %.2f\n",
               e[i].numero, e[i].nom, e[i].prenom, e[i].date.j, e[i].date.m, e[i].date.a, e[i].note_generale);
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







void afficherMenu() {
    printf("****************Menu Principal:*******************************************\n");
    printf("1. Ajouter un étudiant\n");
    printf("2. Modifier un étudiant\n");
    printf("3. Supprimer un étudiant\n");
    printf("4. Afficher un étudiant spécifique\n");
    printf("5. Afficher tous les étudiants\n");
    printf("6. Afficher le nombre total d'étudiants\n");
    printf("7. Afficher le nombre d'étudiants dans chaque département\n");
    printf("8. Afficher les étudiants ayant une moyenne générale supérieure à un seuil\n");
    printf("9. Afficher les 3 étudiants ayant les meilleures notes\n");
    printf("10. Afficher le nombre d'étudiants ayant réussi dans chaque département\n");
    printf("11. Rechercher un étudiant par son nom\n");
    printf("12. Afficher la liste des étudiants inscrits dans un département spécifique\n");
    printf("13. Trier les étudiants par leur nom (A-Z ou Z-A)\n");
    printf("14. Trier les étudiants par moyenne générale (du plus élevé au plus faible ou inversement)\n");
    printf("15. Trier les étudiants selon leur statut de réussite\n");
    printf("0. Quitter\n");
    printf("****choisissez une option (0-15) : ");
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
                modifier_etudiant();
                break;
            case 3:
                supprimer_etudiant();
                break;
            case 4:
                afficher_Un_seul_etudiant();
                break;
            case 5:
                afficherTousEtudiants();
                break;
            case 6:
                afficher_nombre_total_etudiants();
                break;
            case 7:
                afficher_nombre_etudiants_par_departement();
                break;
            case 8:
                {
                    float seuil;
                    printf("Entrez le seuil pour la moyenne générale : ");
                    scanf("%f", &seuil);
                    afficher_etudiants_sup_seuil(seuil);
                }
                break;
            case 9:
                afficher_top_3_etudiants();
                break;
            case 10:
                afficherEtudiantsReussisParDepartement();
                break;
            case 11:
                rechercherEtudiantParNom();
                break;
            case 12:
                afficherEtudiantsParDepartement();
                break;
            
                case 13:
                {
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
                            }
                            break;
                        case 2:
                            {
                                int ordre;
                                printf("Trier par moyenne générale (0 pour croissant, 1 pour décroissant) : ");
                                scanf("%d", &ordre);
                                trierEtudiantsParMoyenneGenerale(ordre);
                            }
                            break;
                        case 3:
                            trierEtudiantsParStatutReussite();
                            break;
                        default:
                            printf("Choix invalide.\n");
                            break;
                    }
                }
                break;
            case 14:
                {
                    int ordre;
                    printf("Trier par moyenne générale (0 pour croissant, 1 pour décroissant) : ");
                    scanf("%d", &ordre);
                    trierEtudiantsParMoyenneGenerale(ordre);
                }
                break;
            case 15:
                trierEtudiantsParStatutReussite();
                break;
            case 0:
                printf("Merci d'avoir utilisé le programme. Au revoir!\n");
                break;
            default:
                printf("Choix invalide. Veuillez réessayer.\n");
                break;
        }
        
    } while (choix != 0);

    return 0;
}
