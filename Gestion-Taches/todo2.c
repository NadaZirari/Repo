#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TACHES 100
#define MAX_TITLE 50
#define MAX_DESC 200
#define MAX_STATUS 20
#define DATE 11


typedef struct {
    int id;
    char titre[MAX_TITLE];
    char description[MAX_DESC];
    char deadline[DATE];  // Format YYYY-MM-DD
    char date_creation[DATE];  // Date de création (non modifiable)
    char statut[MAX_STATUS];  // "à réaliser", "en cours", "finalisée"
} Tache;

Tache taches[MAX_TACHES];  // Tableau statique pour stocker les tâches
int nb_taches = 0;  // Nombre de tâches actuellement enregistrées


void ajouter_tache();
void afficher_taches();
void trier_taches_alphabetiquement();
void trier_taches_par_deadline();
void afficher_taches_urgent();
void modifier_tache();
void supprimer_tache();
void rechercher_tache_par_id();
void rechercher_tache_par_titre();
void afficher_statistiques();
int jours_restants(char* deadline);
void afficher_menu();
void obtenir_date_aujourd_hui(char* date);

int main() {
    afficher_menu();
    return 0;
}

// Fonction pour afficher le menu principal
void afficher_menu() {
    int choix;
    do {
        printf("\nMenu:\n");
        printf("1. Ajouter une nouvelle tâche\n");
        printf("2. Afficher la liste de toutes les tâches\n");
        printf("3. Trier les tâches par ordre alphabétique\n");
        printf("4. Trier les tâches par deadline\n");
        printf("5. Afficher les tâches avec un deadline dans 3 jours ou moins\n");
        printf("6. Modifier une tâche\n");
        printf("7. Supprimer une tâche par identifiant\n");
        printf("8. Rechercher une tâche par identifiant\n");
        printf("9. Rechercher une tâche par titre\n");
        printf("10. Afficher les statistiques\n");
        printf("11. Quitter\n");
        printf("Choix: ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                ajouter_tache();
                break;
            case 2:
                afficher_taches();
                break;
            case 3:
                trier_taches_alphabetiquement();
                afficher_taches();
                break;
            case 4:
                trier_taches_par_deadline();
                afficher_taches();
                break;
            case 5:
                afficher_taches_urgent();
                break;
            case 6:
                modifier_tache();
                break;
            case 7:
                supprimer_tache();
                break;
            case 8:
                rechercher_tache_par_id();
                break;
            case 9:
                rechercher_tache_par_titre();
                break;
            case 10:
                afficher_statistiques();
                break;
            case 11:
                printf("Au revoir!\n");
                break;
            default:
                printf("Choix invalide!\n");
        }
    } while (choix != 11);
}

// Fonction pour ajouter une tâche
void ajouter_tache() {
    if (nb_taches >= MAX_TACHES) {
        printf("Impossible d'ajouter plus de tâches.\n");
        return;
    }

    Tache nouvelle_tache;
    nouvelle_tache.id = nb_taches + 1;

    printf("Titre: ");
    getchar(); // Consomme le '\n' laissé par scanf
    fgets(nouvelle_tache.titre, MAX_TITLE, stdin);
    strtok(nouvelle_tache.titre, "\n");

    printf("Description: ");
    fgets(nouvelle_tache.description, MAX_DESC, stdin);
    strtok(nouvelle_tache.description, "\n");

    printf("Deadline (YYYY-MM-DD): ");
    fgets(nouvelle_tache.deadline, DATE, stdin);
    strtok(nouvelle_tache.deadline, "\n");

    strcpy(nouvelle_tache.statut, "à réaliser");

    obtenir_date_aujourd_hui(nouvelle_tache.date_creation);

    taches[nb_taches] = nouvelle_tache;
    nb_taches++;
}

// Fonction pour afficher toutes les tâches
void afficher_taches() {
    if (nb_taches == 0) {
        printf("Aucune tâche disponible.\n");
    } else {
        for (int i = 0; i < nb_taches; i++) {
            printf("\nTâche #%d\n", taches[i].id);
            printf("Titre: %s\n", taches[i].titre);
            printf("Description: %s\n", taches[i].description);
            printf("Deadline: %s\n", taches[i].deadline);
            printf("Statut: %s\n", taches[i].statut);
            printf("Date de création: %s\n", taches[i].date_creation);
        }
    }
}

// Fonction pour trier les tâches par ordre alphabétique
void trier_taches_alphabetiquement() {
    Tache temp;
    for (int i = 0; i < nb_taches - 1; i++) {
        for (int j = i + 1; j < nb_taches; j++) {
            if (strcmp(taches[i].titre, taches[j].titre) > 0) {
                temp = taches[i];
                taches[i] = taches[j];
                taches[j] = temp;
            }
        }
    }
}

// Fonction pour trier les tâches par deadline
void trier_taches_par_deadline() {
    Tache temp;
    for (int i = 0; i < nb_taches - 1; i++) {
        for (int j = i + 1; j < nb_taches; j++) {
            if (strcmp(taches[i].deadline, taches[j].deadline) > 0) {
                temp = taches[i];
                taches[i] = taches[j];
                taches[j] = temp;
            }
        }
    }
}

// Fonction pour afficher les tâches avec un deadline dans 3 jours ou moins
void afficher_taches_urgent() {
    time_t now = time(NULL);
    struct tm today = *localtime(&now);
    
    for (int i = 0; i < nb_taches; i++) {
        if (jours_restants(taches[i].deadline) <= 3) {
            printf("\nTâche #%d\n", taches[i].id);
            printf("Titre: %s\n", taches[i].titre);
            printf("Description: %s\n", taches[i].description);
            printf("Deadline: %s\n", taches[i].deadline);
            printf("Statut: %s\n", taches[i].statut);
        }
    }
}

// Fonction pour modifier une tâche
void modifier_tache() {
    int id;
    printf("Entrez l'identifiant de la tâche à modifier: ");
    scanf("%d", &id);

    for (int i = 0; i < nb_taches; i++) {
        if (taches[i].id == id) {
            printf("1. Modifier la description\n");
            printf("2. Modifier le statut\n");
            printf("3. Modifier le deadline\n");
            int choix;
            scanf("%d", &choix);
            getchar(); // Consomme '\n'

            if (choix == 1) {
                printf("Nouvelle description: ");
                fgets(taches[i].description, MAX_DESC, stdin);
                strtok(taches[i].description, "\n");
            } else if (choix == 2) {
                printf("Nouveau statut (à réaliser, en cours de réalisation, finalisée): ");
                fgets(taches[i].statut, MAX_STATUS, stdin);
                strtok(taches[i].statut, "\n");
            } else if (choix == 3) {
                printf("Nouveau deadline (YYYY-MM-DD): ");
                fgets(taches[i].deadline, DATE, stdin);
                strtok(taches[i].deadline, "\n");
            } else {
                printf("Choix invalide.\n");
            }
            return;
        }
    }
    printf("Tâche non trouvée.\n");
}

// Fonction pour supprimer une tâche
void supprimer_tache() {
    int id;
    printf("Entrez l'identifiant de la tâche à supprimer: ");
    scanf("%d", &id);

    for (int i = 0; i < nb_taches; i++) {
        if (taches[i].id == id) {
            for (int j = i; j < nb_taches - 1; j++) {
                taches[j] = taches[j + 1];
            }
            nb_taches--;
            printf("Tâche supprimée.\n");
            return;
        }
    }
    printf("Tâche non trouvée.\n");
}

// Fonction pour rechercher une tâche par ID
void rechercher_tache_par_id() {
    int id;
    printf("Entrez l'identifiant de la tâche à rechercher: ");
    scanf("%d", &id);

    for (int i = 0; i < nb_taches; i++) {
        if (taches[i].id == id) {
            printf("\nTâche #%d\n", taches[i].id);
            printf("Titre: %s\n", taches[i].titre);
            printf("Description: %s\n", taches[i].description);
            printf("Deadline: %s\n", taches[i].deadline);
            printf("Statut: %s\n", taches[i].statut);
            printf("Date de création: %s\n", taches[i].date_creation);
            return;
        }
    }
    printf("Tâche non trouvée.\n");
}

// Fonction pour rechercher une tâche par titre
void rechercher_tache_par_titre() {
    char titre[MAX_TITLE];
    printf("Entrez le titre de la tâche à rechercher: ");
    getchar();
    fgets(titre, MAX_TITLE, stdin);
    strtok(titre, "\n");

    for (int i = 0; i < nb_taches; i++) {
        if (strcmp(taches[i].titre, titre) == 0) {
            printf("\nTâche #%d\n", taches[i].id);
            printf("Titre: %s\n", taches[i].titre);
            printf("Description: %s\n", taches[i].description);
            printf("Deadline: %s\n", taches[i].deadline);
            printf("Statut: %s\n", taches[i].statut);
            printf("Date de création: %s\n", taches[i].date_creation);
            return;
        }
    }
    printf("Tâche non trouvée.\n");
}

// Fonction pour afficher des statistiques
void afficher_statistiques() {
    int total = nb_taches;
    int completes = 0, incompletes = 0;
    for (int i = 0; i < nb_taches; i++) {
        if (strcmp(taches[i].statut, "finalisée") == 0) {
            completes++;
        } else {
            incompletes++;
        }
    }

    printf("\nStatistiques:\n");
    printf("Nombre total de tâches: %d\n", total);
    printf("Nombre de tâches complètes: %d\n", completes);
    printf("Nombre de tâches incomplètes: %d\n", incompletes);

    // Nombre de jours restants pour chaque tâche
    for (int i = 0; i < nb_taches; i++) {
        printf("Tâche #%d: %d jours restants jusqu'au deadline.\n", taches[i].id, jours_restants(taches[i].deadline));
    }
}

// Fonction pour obtenir la date du jour au format YYYY-MM-DD
void obtenir_date_aujourd_hui(char* date) {
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    strftime(date, DATE_LEN, "%Y-%m-%d", t);
}

// Fonction pour calculer le nombre de jours restants jusqu'à un deadline
int jours_restants(char* deadline) {
    struct tm deadline_tm = {0};
    sscanf(deadline, "%d-%d-%d", &deadline_tm.tm_year, &deadline_tm.tm_mon, &deadline_tm.tm_mday);
    deadline_tm.tm_year -= 1900;  // Année depuis 1900
    deadline_tm.tm_mon -= 1;  // Mois 0-11

    time_t deadline_time = mktime(&deadline_tm);
    time_t now = time(NULL);

    double diff_seconds = difftime(deadline_time, now);
    return (int)(diff_seconds / (60 * 60 * 24));  // Conversion en jours
}
