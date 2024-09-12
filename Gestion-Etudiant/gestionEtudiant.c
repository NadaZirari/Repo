#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int nb = 0;         // Nombre total d'étudiants
int nbdep[4] = {0};// // Nombre d'étudiants par département

// Structure représentant un étudiant
typedef struct {
    int ID;
    char Nom[30];
    char Prenom[15];
    char DateN[30];
    char Departement[20];
    float Note;
} Etudiant;

// Tableau contenant tous les etudiants
Etudiant e[500];
//sizeof(etudiant)/sizeof(etudiant[0])
// Tableaux pour les départements
char dep[4][50] = {"Mathematique", "Informatique", "Chimie","Economie"};



void AjouterEtudiant();
int AfficherMenuDep();
void ModifierEtudiant();
void AfficherMenuModifier();
void AfficherInfos(int i);
void CalculerMoyenne();
int AfficherMenuCalcul();
void RechercherEtudiant();
int AfficherMenuRecherche();
void MenuTri();
void TriNomCroissant();
void TriNomDecroissant();
void TriMoyenneCroissant();
void TriMoyenneDecroissant();
void Statistiques();
void ReussiteDep();
void MeilleurNote();
void EtudientParDep();
void Menu();
void EtudiantParSeuil();
void Informations();



// Affiche les informations d'un étudiant donné par son index dans le tableau

void AfficherInfos(int i) {

    printf("\tEtudiant %d:\n\t\tId: %d | Nom: %s | Prenom: %s | Date de naissance: %s | Departement: %s | Note generale: %.2f\n",
     i + 1, e[i].ID, e[i].Nom, e[i].Prenom, e[i].DateN, e[i].Departement, e[i].Note);
}


// Affiche le menu de calcul des moyennes

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


// Affiche le menu des départements disponibles

int AfficherMenuDep() {
    int choix;

    printf("\tLes departements possibles: \n");
    for (int i = 0; i < 4; i++) 
        printf("\t%d. %s\n", i + 1, dep[i]);

    printf("\t\nEntrez le numéro du département choisi: ");
    scanf("%d", &choix);
    getchar();

    return choix;
}


// Affiche le menu de modification des informations d'un étudiant

void AfficherMenuModifier() {

    printf("Quelle information souhaitez-vous modifier ?\n");
    printf("\t1. Nom\n\t2. Prenom\n\t3. Date de naissance\n\t4. Departement\n\t5. Note\n\t6. Tout modifier\n");

}


// Affiche le menu de recherche d'un étudiant

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

// Ajoute un ou plusieurs étudiants

void AjouterEtudiant() {
    int n, choix;

    printf("Combien d'etudiants voulez-vous ajouter: ");
    scanf("%d", &n);
    getchar();

    for (int i = 0; i < n; i++) {
        printf("Etudiant %d:\n", i + 1);
        printf("\tL'id de l'etudiant %d: %d\n", i + 1, nb+1);
        e[nb].ID = nb + 1;

        printf("\tEntrer le nom de l'etudiant %d: ", i + 1);
        scanf("%[^\n]", e[nb].Nom);
        getchar();

        printf("\tEntrer le prenom de l'etudiant %d: ", i + 1);
        scanf("%[^\n]", e[nb].Prenom);
        getchar();

        printf("\tEntrer la date de naissance de l'etudiant %d (jj-mm-aaaa): ", i + 1);
        scanf("%[^\n]", e[nb].DateN);
        getchar();

        
        printf("\tEntrer le departement de l'etudiant %d:\n", i + 1);
        choix = AfficherMenuDep();
        

        if (choix >= 1 && choix <= 12) {
            strcpy(e[nb].Departement, dep[choix - 1]);
            nbdep[choix - 1]++;     // Incrémenter le nombre d'étudiants pour le département sélectionné
        }
        else {
            printf("Choix invalide.\n");
            i--;    // Répète l'entrée pour l'étudiant actuel
            continue;
        }

        printf("\tEntrer la note generale de l'etudiant %d: ", i + 1);
        scanf("%f", &e[nb].Note);
        getchar();

        

        printf("Etudiant ajoute avec succss!\n");
        AfficherInfos(nb);

        nb++;
    }
}

// Calcule et affiche la moyenne des notes

void CalculerMoyenne() {
    int choix, cpt = 0;
    float m, S = 0.0;

    choix = AfficherMenuCalcul();
    
    if (choix == 1) {
        printf("Quel departement voulez-vous calculer sa moyenne:\n");
        choix = AfficherMenuDep();

        for (int i = 0; i < nb; i++) {
            if (strcmp(e[i].Departement, dep[choix - 1]) == 0) {
                S += e[i].Note;
                cpt++;
            }
        }
        

        if (cpt > 0) {
            m = S / cpt;
            printf("La moyenne de departement %s est: %.2f\n", dep[choix - 1], m);
        }
        else
            printf("Il n'y a aucun etudiant dans ce departement.\n");
    }
    
    else if (choix == 2) {
        for (int i = 0; i < nb; i++) {
            S += e[i].Note;
            cpt++;
        }
        m = (float) S / cpt;
        printf("La moyenne generale de l'universite est: %.2f\n", m);
    }

    else
        printf("Choix invalide.\n");
}

void Informations() {

    // Remplir automatiquement la base de données avec les informations de 10 étudiants prédéfinis.
    char noms[4][50] = {"Nada", "imen", "safaa","asmaa"};
    char prenoms[4][50] = {"Zirari", "anassi", "ettalhi", "beniss"};
    char dates[4][11] = {"2000-10-12", "2001-07-25", "2002-11-24", "2003-02-23"};
    char departements[4][30] = {"Informatique", "Chimie", "Math",  "Biologie"};
    float notes[4] = {16.0, 14.0, 13.0, 15.0};

    for (int i = 0; i < 4; i++) {
        if (nb >= 500) {  
            printf("Université pleine.\n");
            return;
        }
        e[nb].ID = nb + 1;
        strcpy(e[nb].Nom, noms[i]);
        strcpy(e[nb].Prenom, prenoms[i]);
        strcpy(e[nb].DateN, dates[i]);
        strcpy(e[nb].Departement, departements[i]);
        e[nb].Note = notes[i];
        nb++;
    }
    printf("4 étudiants ajoutés avec succès.\n");
}

// Affiche les étudiants dont la note est supérieure ou égale à un seuil donné par l'utilisateur

void EtudiantParSeuil() {
    int seuil;

    printf("Entrez le seuil: ");
    scanf("%d", &seuil);
    getchar();

    for (int i = 0; i < nb; i++) {
        if (e[i].Note >= seuil)
            AfficherInfos(i);
    }
}

// Affiche le nombre d'étudiants par département et ceux ayant une note supérieure d'un seuil

void EtudientParDep() {
    int seuil;

    for (int i = 0; i < nb; i++) {
        for (int j = 0; j < 4; j++) {
            if (strcmp(e[i].Departement, dep[j]) == 0) {
                nbdep[j]++;
                break;
            }
        }
    }
    
    for (int i = 0; i < 4; i++)
        printf("%s: %d\n", dep[i], nbdep[i]);

    
}

// Trouve et affiche les trois meilleurs étudiants

void MeilleurNote() {
    int notes[3]= {-1}, ind[3] = {-1};

    // Trouver les trois meilleurs étudiants
    for (int i = 0; i < nb; i++) {      // Parcourt tous les étudiants
        for (int j = 0; j < 3; j++) {   // Parcourt les trois meilleures notes
            if (e[i].Note > notes[j]) {      // Vérifie si la note actuelle est meilleure que la note enregistrée
                for (int k = 2; k > j; k--) {
                    notes[k] = notes[k - 1];
                    ind[k] = ind[k - 1];
                }
                // Insère la nouvelle meilleure note et son index
                notes[j] = e[i].Note;
                ind[j] = i;
                break;
            }
        }
    }

    for (int i = 0; i < 3 && ind[i] != -1; i++) {
        AfficherInfos(ind[i]);
    }
}

// Fonction qui affiche le menu de tri et permet à l'utilisateur de choisir le critère de tri

void MenuTri() {
    int choix;

    printf("Que voulez-vous trier ?\n");
    printf("\t1. Par nom (A a Z)\n");
    printf("\t2. Par nom (Z a A)\n");
    printf("\t3. Par moyenne (croissant)\n");
    printf("\t4. Par moyenne (decroissant)\n");
    printf("Entrez votre choix: ");
    scanf("%d", &choix);
    getchar();

    switch (choix)
    {
    case 1:
        TriNomCroissant();
        break;
    case 2:
        TriNomDecroissant();
        break;
    case 3:
        TriMoyenneCroissant();
        break;
    case 4:
        TriMoyenneDecroissant();
        break;
    default:
        printf("Choix invalide.\n");
        break;
    }
}

// Fonction pour modifier les informations d'un étudiant

void ModifierEtudiant() {
    int id, choix, choixDep;

    printf("Entrer l'id de l'etudiant que vous voulez modifier: ");
    scanf("%d", &id);
    getchar();

    // Trouver l'étudiant avec cet ID
    for (int i = 0; i < nb; i++) {
        if (e[i].ID == id) {
            AfficherMenuModifier();
            printf("Entrer votre choix : ");
            scanf("%d", &choix);
            getchar();

            switch (choix) {
                case 1:
                    printf("Entrer le nouveau nom: ");
                    scanf("%[^\n]", e[i].Nom);
                    getchar();
                    printf("Modification effectuee avec succes!\n");
                    AfficherInfos(i);
                    break;
                case 2:
                    printf("Entrer le nouveau prenom: ");
                    scanf("%[^\n]", e[i].Prenom);
                    getchar();
                    printf("Modification effectuee avec succes!\n");
                    AfficherInfos(i);
                    break;
                case 3:
                    printf("Entrer la nouvelle date de naissance: ");
                    scanf("%[^\n]", e[i].DateN);
                    printf("Modification effectuee avec succes!\n");
                    AfficherInfos(i);
                    getchar();
                    break;
                case 4:
                    printf("Entrer le nouveau département:\n");
                    choixDep = AfficherMenuDep();

                    if (choixDep >= 1 && choixDep <= 12) {
                        strcpy(e[i].Departement, dep[choixDep - 1]);
                        printf("Modification effectuée avec succès!\n");
                    } 
                    else 
                        printf("Choix de département invalide.\n");
                    
                    break;
                case 5:
                    printf("Entrer la nouvelle note: ");
                    scanf("%f", &e[i].Note);
                    getchar();
                    printf("Modification effectuee avec succes!\n");
                    AfficherInfos(i);
                    break;
                case 6:
                    printf("Entrer le nouveau nom: ");
                    scanf("%[^\n]", e[i].Nom);
                    printf("Entrer le nouveau prenom: ");
                    scanf("%[^\n]", e[i].Prenom);
                    printf("Entrer la nouvelle date de naissance: ");
                    scanf("%[^\n]", e[i].DateN);
                    printf("Entrer le nouveau departement: ");
                    choixDep = AfficherMenuDep();

                    if (choixDep >= 1 && choixDep <= 12) {
                        strcpy(e[i].Departement, dep[choixDep - 1]);
                        printf("Entrer la nouvelle note: ");
                        scanf("%f", &e[i].Note);
                        getchar();
                        printf("Modification effectuée avec succès!\n");
                    } 
                    else 
                        printf("Choix de département invalide.\n");
                    break;
                    
                default:
                    printf("Choix invalide.\n");
                    break;
            }
            AfficherInfos(i);
            return;
        }
    
    }
    printf("L'etudiant n'existe pas.\n");
}

// Fonction pour rechercher un étudiant

void RechercherEtudiant() {
    char nom[30], departement[50];
    int choix, cpt = 0;

    choix = AfficherMenuRecherche();

    if (choix == 1) {
        printf("Entrez le nom de l'etudiant: ");
        scanf("%[^\n]", nom);
        getchar();

        for (int i = 0; i < nb; i++) {
            if (strcmp(e[i].Nom, nom) == 0) {
                printf("Etudiant %d:\n", i + 1);
                AfficherInfos(i);
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

        for (int i = 0; i < nb; i++) {
            if (strcmp(e[i].Departement, departement) == 0) {
                printf("Etudiant %d:\n", i + 1);
                AfficherInfos(i);
                cpt++;
            }
        }
        if (cpt == 0)
            printf("Departement non trouvé\n");
    }

    else
        printf("Choix invalide.\n");

}

// Fonction pour afficher le nombre d'étudiants ayant réussi dans chaque département

void ReussiteDep() {
    
    for (int i = 0; i < 4; i++) {
        int cpt = 0;

        for (int j = 0; j < nb; j++) {
            if (e[j].Note >= 10 && strcmp(e[j].Departement, dep[i]) == 0)
                cpt++;
        }

        printf("%s: %d\n", dep[i], cpt);

        if (cpt == 0)
            printf("Aucun etudiant n'a reussi dans ce departement.\n");
    }
}

// Fonction pour afficher les statistiques concernant les étudiants

void Statistiques() {

    printf("Statistiques:\n");
    printf("\tLe nombre total d'etudiants est: %d\n", nb);

    printf("\n\tLe nombre d'etudiants dans chaque departement est:\n");
    EtudientParDep();   

    printf("\n\tAfficher les 3 etudiants ayant la meilleur note\n");
    MeilleurNote();

    printf("\tAfficher les etudiants ayant une moyenne superieure a un certain seuil\n");
    EtudiantParSeuil();

    printf("\n\tAfficher le nombre d'etudiants qui ont reusssi dans chaque departement\n");
    ReussiteDep();
     
}

// Fonction pour supprimer un étudiant

void SupprimerEtudiant() {
    int id, choix;

    printf("Entrer l'id de l'etudiant que vous voulez supprimer: ");
    scanf("%d", &id);
    getchar();

    printf("Voulez-vous confirmer la suppression de l'etudiant?\n");
    printf("\t1. Oui\n\t2. Non\n");
    scanf("%d", &choix);
    getchar();

    if (choix == 1) {
        for (int i = 0; i < nb; i++) {
            if (e[i].ID == id) {
                
                // Suppression de l'étudiant en décalant les éléments suivants
                for (int j = i; j < nb - 1; j++) {
                    e[j] = e[j + 1];
                }
                nb--;
                printf("Etudiant supprime avec succes!\n");
                break;
            }
        }
        printf("L'étudiant n'existe pas.\n");
    }

    else if (choix == 2) {
        printf("Suppression annulee!\n");
    }

    else   
        printf("Choix invalide.\n");
}

// Fonction pour trier les étudiants par moyenne en ordre croissant
void TriMoyenneCroissant() {

    for (int i = 0; i < nb - 1; i++) {
        for (int j = i + 1; j < nb; j++) {
            if (e[i].Note > e[j].Note) {
                Etudiant temp = e[i];
                e[i] = e[j];
                e[j] = temp;
            }
        }
    }
    // Affichage des étudiants triés
    for (int i = 0; i < nb; i++) {
        AfficherInfos(i);
    }
}

// Fonction pour trier les étudiants par moyenne en ordre décroissant
void TriMoyenneDecroissant() {

    for (int i = 0; i < nb - 1; i++) {
        for (int j = i + 1; j < nb; j++) {
            if (e[i].Note < e[j].Note) {
                Etudiant temp = e[i];
                e[i] = e[j];
                e[j] = temp;
            }
        }
    }
    // Affichage des étudiants triés
    for (int i = 0; i < nb; i++) {
        AfficherInfos(i);
    }
}

// Fonction pour trier les étudiants par nom en ordre décroissant

void TriNomCroissant() {

    for (int i = 0; i < nb - 1; i++) {
        for (int j = i + 1; j < nb; j++) {
            if (strcasecmp(e[i].Nom, e[j].Nom) > 0) {
                Etudiant temp = e[i];
                e[i] = e[j];
                e[j] = temp;
            }
        }
    }
    // Affichage des étudiants triés
    for (int i = 0; i < nb; i++) {
        AfficherInfos(i);
   }
}

// Fonction pour trier les étudiants par nom en ordre croissant
void TriNomDecroissant() {

    for (int i = 0; i < nb - 1; i++) {
        for (int j = i + 1; j < nb; j++) {
            if (strcasecmp(e[i].Nom, e[j].Nom) < 0) {
                Etudiant temp = e[i];
                e[i] = e[j];
                e[j] = temp;
            }
        }
    }
    // Affichage des étudiants triés
    for (int i = 0; i < nb; i++) {
        AfficherInfos(i);
    }
}

// Fonction pour trier les étudiants par statut de réussite
void TriStatut() {

    printf("Statut de réussite des étudiants :\n");

    printf("Mention: Échec\n");
    for (int i = 0; i < nb; i++) {
        if (e[i].Note < 10) {
            AfficherInfos(i);
        }
    }

    printf("\nMention: Passable\n");
    for (int i = 0; i < nb; i++) {
        if (e[i].Note >= 10 && e[i].Note < 12) {
            AfficherInfos(i);
        }
    }

    printf("\nMention: Assez bien\n");
    for (int i = 0; i < nb; i++) {
        if (e[i].Note >= 12 && e[i].Note < 14) {
            AfficherInfos(i);
        }
    }   
    
    printf("\nMention: Bien\n");
    for (int i = 0; i < nb; i++) {
        if (e[i].Note >= 14 && e[i].Note < 16) {
            AfficherInfos(i);
        }
    }

    printf("\nMention: Tres bien\n");
    for (int i = 0; i < nb; i++) {
        if (e[i].Note >= 16) {
            AfficherInfos(i);
        }
    }
}

// Fonction qui affiche le menu principal et permet à l'utilisateur de choisir parmi les différentes options
void Menu() {
    int choix;

    while (1) {
        printf("Menu:\n");
        printf("\t1. Ajouter un etudiant\n");
        printf("\t2. Modifier un etudiant\n");
        printf("\t3. Afficher les details d'un etudiant\n");
        printf("\t4. Calculer la moyenne generale d'un departement\n");
        printf("\t5. Rechercher un etudiant\n");
        printf("\t6. Supprimer un etudiant\n");
        printf("\t7. Trier les etudiants\n");
        printf("\t8. Afficher les statistiques\n");
        printf("\t9. Quitter\n");
        printf("Entrez votre choix: ");
        scanf("%d", &choix);
        getchar();

        switch (choix) {
            case 1:
                AjouterEtudiant();
                break;

            case 2:
                ModifierEtudiant();
                break;

            case 3:
                for (int i = 0; i < nb; i++)
                    AfficherInfos(i);
                break;

            case 4:
                CalculerMoyenne();
                break;

            case 5:
                RechercherEtudiant();
                break;

            case 6:
                SupprimerEtudiant();
                break;

            case 7:
                MenuTri();
                break;

            case 8:
                Statistiques();
                break;

            case 9:
                exit(0);
                break;

            default:
                printf("Choix invalide.\n");
                break;
        }
    }
}


int main() {
    
    // Remplit le tableau d'étudiants avec des données prédéfinies
    Informations();

    // Affiche le menu principal et permet à l'utilisateur d'interagir avec le programme
    Menu();

    return 0;
}