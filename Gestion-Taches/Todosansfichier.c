#include <stdio.h>
#include <string.h>

int nombreTache = 0; 

struct Date {
    
    int j;
    int m;
    int a;
};
struct Tache {
    
    int id;
    char titre [100];
    char description [100];
    char statut[100];
    struct Date deadline;

};


 struct Tache t[1000];


//ajouter une seul tache
void AjouterTache(){
printf("entrer l'id \n");
scanf("%d",&t[nombreTache].id);

printf("entrer le titre\n");
scanf("%[^\n]s",t[nombreTache].titre);

printf("entrer la description\n");
scanf("%[^\n]s",t[nombreTache].description);

printf("entrer le jour de deadline\n");
scanf("%d",&t[nombreTache].deadline.j);

printf("entrer le mois de deadline\n");
scanf("%d",&t[nombreTache].deadline.m);

printf("entrer l'annee de deadline\n");
scanf("%d",&t[nombreTache].deadline.a);

printf("entrer le statut du tache\n");
scanf("%s",t[nombreTache].statut);
nombreTache++;

}


//ajouter plusieurs  taches

void AjouterPlusieurTaches() {

    int n;

    printf("Entrer le nombre de tâches que vous voulez ajouter : ");
    scanf("%d", &n);

    for(int i = 1; i <= n; i++) {
        printf("Entrer l'id de la %dème tâche :\n", i);
        scanf("%d", &t[nombreTache].id);

        printf("Entrer le titre de la %dème tâche :\n", i);
        scanf(" %[^\n]", t[nombreTache].titre);

        printf("Entrer la description de la %dème tâche :\n", i);
        scanf(" %[^\n]", t[nombreTache].description);

        printf("Entrer le jour de la deadline de la %dème tâche :\n", i);
        scanf("%d", &t[nombreTache].deadline.j);

        printf("Entrer le mois de la deadline de la %dème tâche :\n", i);
        scanf("%d", &t[nombreTache].deadline.m);

        printf("Entrer l'année de la deadline de la %dème tâche :\n", i);
        scanf("%d", &t[nombreTache].deadline.a);

        printf("Entrer le statut de la %dème tâche :\n", i);
        scanf(" %[^\n]", t[nombreTache].statut);

        // Incrémenter nombreTache après chaque tâche ajoutée
        nombreTache++;
    }

    printf("%d tâche(s) ajoutée(s) avec succès.\n", n);
}





//rechercher tache par titre
 void RechercherTitreTache(){
char titre2[100];
int TacheTrouve=0;
int indexTacheTrouve;

for (int i = 0; i < nombreTache; i++) {
        if (strcmp(t[i].titre ,titre2 )==0){
            TacheTrouve = 1;
            indexTacheTrouve = i;
            break;
        } 
    }

}



//rechercher tache par id


void RechercherIdTache(){
int id2;
int TacheTrouve=0;
int indexTacheTrouve;

for (int i = 0; i < nombreTache; i++) {
        if (t[i].id == id2 ){
            TacheTrouve = 1;
            indexTacheTrouve = i;
            break;
        } 
    }

}
//  trier les tâches par ordre alphabétique du titre
void TrierTachesParTitre() {
    struct Tache temp;
    
    // tri à bulles
    for (int i = 0; i < nombreTache - 1; i++) {
        for (int j = i + 1; j < nombreTache; j++) {
            // Comparaison 
            if (strcmp(t[i].titre, t[j].titre) > 0) {
                // Échange
                temp = t[i];
                t[i] = t[j];
                t[j] = temp;
            }
        }
    }
    
    printf("Les tâches ont été triées par ordre alphabétique des titres.\n");
}

//   trier les tâches par deadline
void TrierTachesParDeadline() {
    struct Tache temp;

    //tri à bulles
    for (int i = 0; i < nombreTache - 1; i++) {
        for (int j = i + 1; j < nombreTache; j++) {
            // Comparaison des années
            if (t[i].deadline.a > t[j].deadline.a) {
                temp = t[i];
                t[i] = t[j];
                t[j] = temp;
            }
            // Si les années sont identiques, on compare les mois
            else if (t[i].deadline.a == t[j].deadline.a) {
                if (t[i].deadline.m > t[j].deadline.m) {
                    temp = t[i];
                    t[i] = t[j];
                    t[j] = temp;
                }
                // Si les mois sont identiques, on compare les jours
                else if (t[i].deadline.m == t[j].deadline.m) {
                    if (t[i].deadline.j > t[j].deadline.j) {
                        temp = t[i];
                        t[i] = t[j];
                        t[j] = temp;
                    }
                }
            }
        }
    }

    printf("Les tâches ont été triées par deadline.\n");
}

void ModifierTache(){
    int id2;
    int TacheTrouve=0;
    int indexTacheTrouve;
printf("entrer l'id du tache que vous voulez modifier");
scanf("%d",id2);

// Recherche du tache par id
    for (int i = 0; i < nombreTache; i++) {
        if (t[i].id  == id2 ){
            TacheTrouve = 1;
            indexTacheTrouve = i;
            break;
        } 
    }
if(TacheTrouve==1) {
//afficher la tache trouvée
            printf("Tache trouvé !\n");
            printf("Titre : %s\n", t[indexTacheTrouve].titre);
            printf("Description : %s\n", t[indexTacheTrouve].description);
            printf("Le jour du Deadline : %s Le mois du Deadline : %s L'annés du Deadline : %s\n", t[indexTacheTrouve].deadline.j,t[indexTacheTrouve].deadline.m,t[indexTacheTrouve].deadline.a);
            printf("statut : %s\n", t[indexTacheTrouve].statut);

// Modifier la tache touvée
            printf("Entrez le nouveau id : \n");
            scanf(" %d", &t[indexTacheTrouve].id);
            
            printf("Entrez le nouveau  Titre : \n");
            scanf(" %[^\n]s", t[indexTacheTrouve].titre);

            printf("Entrez le nouveau  description : \n");
            scanf(" %[^\n]s", t[indexTacheTrouve].description);

            printf("Entrez le nouveau  statut :\n ");
        
            scanf(" %[^\n]s", t[indexTacheTrouve].statut);
            printf("Entrez la nouvelle date de deadline nouveau   :\n ");
            printf("Entrez le nouveau  jour du deadline :\n ");
            scanf(" %d", &t[indexTacheTrouve].deadline.j);

            printf("Entrez le nouveau  jour du deadline :\n ");
            scanf(" %d", &t[indexTacheTrouve].deadline.m);

            printf("Entrez le nouveau  jour du deadline :\n ");
            scanf(" %d", &t[indexTacheTrouve].deadline.a);

            printf("Informations Modifiées:\n");

            printf("id : %d\n", t[indexTacheTrouve].id);
            printf("titre : %s\n", t[indexTacheTrouve].titre);
            printf("statut: %s\n", t[indexTacheTrouve].statut);
            printf("description : %s\n", t[indexTacheTrouve].description);
            printf("Deadline : %d-%d-%d\n", t[indexTacheTrouve].deadline.j,t[indexTacheTrouve].deadline.m,t[indexTacheTrouve].deadline.a);
    } else {
        printf("Tache non Trouvé!");
    }
}



void SupprimerTache() {

    int id2;
    int tacheTrouvee = 0;

    printf("Entrez l'identifiant de la tâche à supprimer : ");
    scanf("%d", &id2);

    // Rechercher la tâche par identifiant
    for (int i = 0; i < nombreTache; i++) {
        if (t[i].id == id2) {
            tacheTrouvee = 1;

            // Décaler les tâches après la tâche supprimée vers la gauche
            for (int j = i; j < nombreTache - 1; j++) {
                t[j] = t[j + 1];
            }

            nombreTache--; // Réduire le nombre de tâches
            printf("Tâche avec l'identifiant %d supprimée avec succès.\n", id2);
            break;
        }
    }

    if (!tacheTrouvee) {
        printf("Tâche avec l'identifiant %d non trouvée.\n", id2);
    }
}
void AfficherNombreTotalTaches() {
    printf("Le nombre total de tâches est : %d\n", nombreTache);
}

void AfficherStatistiquesTaches() {
    int tachesCompletes = 0;
    int tachesIncompletes = 0;

    for (int i = 0; i < nombreTache; i++) {
        if (strcmp(t[i].statut, "finalisée") == 0) {
            tachesCompletes++;
        } else {
            tachesIncompletes++;
        }
    }

    printf("Nombre de tâches complètes : %d\n", tachesCompletes);
    printf("Nombre de tâches incomplètes : %d\n", tachesIncompletes);
}

void AfficherToutTaches(){

  printf("Liste des Taches :\n");
       for (int i = 0; i < nombreTache; i++) {
           printf("Tache %d :\n", i + 1);
           printf("L'id : %s \n", t[i].id);
           printf("Le titre : %s \n", t[i].titre);
           printf("La description: %s \n", t[i].description);
           printf("Le statut : %s \n", t[i].statut);
            printf("Le deadline : %s -%s-%s\n", t[i].deadline.j,t[i].deadline.m,t[i].deadline.a);

    }   
}



   int main() {

    while (1) { 
        // Affichage du menu
        printf("************* MENU ****************\n");
        printf("[1]: Ajouter une tâche\n");
        printf("[2]: Ajouter plusieurs taches \n");
        printf("[3]: Rechercher Tache par Titre\n");
        printf("[4]: Rechercher Tache par id\n");
        printf("[5]: Trier Taches Par Titre\n");
        printf("[6]: Trier Taches Par deadline\n");
        printf("[7]: Modifier une tâche\n");
        printf("[8]: Supprimer une tâche\n");
        printf("[9]: Afficher toutes les tâches\n");
        printf("[10]: Afficher Nombre Total Taches\n");
        printf("[11]: Afficher Statistiques Taches\n");
    

        int choisir;
        int op = -1;

        // Demande du choix à l'utilisateur
        printf("Entrez votre choix :\n");
        scanf("%d", &op);

        // Gestion du menu
        switch (op) {
            case 1:
               AjouterTache(); 
            case 2:
               AjouterPlusieurTaches();
                break;
            case 3:
               RechercherTitreTache();
                break;

            case 4:
                RechercherIdTache();
                break;

            case 5:
                TrierTachesParTitre();
                break;

             case 6:
                TrierTachesParDeadline();
                break;
             case 7:
                ModifierTache();
                break;
            case 8:
               SupprimerTache();
                break;
             case 9:
                AfficherToutTaches();
                break;
            case 10:
                AfficherNombreTotalTaches();
                break;
             case 11:
                AfficherStatistiquesTaches();
                break;

            case 12:
                // Quitter la boucle et terminer le programme
                printf("Au revoir !\n");
                return 0;

            default:
                printf("Choix invalide.\n");
                break;
        }
    
    }}