#include <stdio.h>
#include <string.h>
#define MAX 200

int nombreContacts = 0; 
 struct Contact {
  char nom[MAX];
  char email[MAX];
  char telephone[MAX];
};

struct Contact contacts[MAX];


void ajouterContact() {
    printf("Entrez votre nom : ");
    scanf("%s", contacts[nombreContacts].nom);

    printf("Entrez votre email : ");
    scanf("%s", contacts[nombreContacts].email);

    printf("Entrez votre numéro de téléphone : ");
    scanf("%s", contacts[nombreContacts].telephone);
    nombreContacts++;
}


void afficherContacts() {

    printf("Liste des contacts :\n");
       for (int i = 0; i < nombreContacts; i++) {
           printf("Contact %d :\n", i + 1);
           printf("Nom : %s \n", contacts[i].nom);
           printf("Numéro de téléphone : %s \n", contacts[i].telephone);
           printf("Adresse e-mail : %s \n", contacts[i].email);
    }

}

void modifierContact() {
    char nomRecherche[MAX];
    int i, indexContactTrouve;
    int contactTrouve = 0;

    printf("Entrez le nom du contact à modifier : ");
    scanf("%s", nomRecherche);

    // Recherche du contact par nom
    for (i = 0; i < nombreContacts; i++) {
        if (strcmp(contacts[i].nom, nomRecherche) == 0) {
            contactTrouve = 1;
            indexContactTrouve = i;
            break;
        } 
    }
    if(contactTrouve==1) {
        
            printf("Contact trouvé !\n");
            printf("Nom : %s\n", contacts[indexContactTrouve].nom);
            printf("Numéro de téléphone : %s\n", contacts[indexContactTrouve].telephone);
            printf("Adresse e-mail : %s\n", contacts[indexContactTrouve].email);

            // Modifier les informations du contact
            printf("Entrez le nouveau numéro de téléphone : ");
            scanf(" %[^\n]s", &contacts[indexContactTrouve].telephone);
            
            printf("Entrez la nouvelle adresse e-mail : ");
            scanf(" %[^\n]s", &contacts[indexContactTrouve].email);

            printf("Informations mises à jour :\n");
            printf("Nom : %s\n", contacts[indexContactTrouve].nom);
            printf("Numéro de téléphone : %s\n", contacts[indexContactTrouve].telephone);
            printf("Adresse e-mail : %s\n", contacts[indexContactTrouve].email);
    } else {
        printf("Contact non Trouvé!");
    }


}

void supprimerContact() {
    char nomRecherche[MAX];
    int i, j;
    int contactTrouve = 0;

    printf("Entrez le nom du contact à supprimer : ");
    scanf("%s", nomRecherche);

    // Recherche du contact par nom
    for (i = 0; i < nombreContacts; i++) {
        if (strcmp(contacts[i].nom, nomRecherche) == 0) {
            contactTrouve = 1;

            // Suppression 
            for (j = i; j < nombreContacts - 1; j++) {
                contacts[j] = contacts[j + 1];
            }

            nombreContacts--; 
            printf("Contact '%s' supprimé \n", nomRecherche);
            break;
        }
    }
    for(i = 0; i < nombreContacts; i++) {
        
    }

    if (!contactTrouve) {
        printf("Contact '%s' non trouvé.\n", nomRecherche);
    }
}

int main() {


int choix;

    while (1) { //cad a chaqur fois
        
        printf("\nMenu :\n");
        printf("1. Ajouter un contact\n");
        printf("2. Afficher tous les contacts\n");
        printf("3. Quitter\n");
        printf("Entrez votre choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                ajouterContact();
                break;
            case 2:
                afficherContacts();
                break;
            case 3:
                ModifierContact();
                break;
            case 4:
                RechercherunContact();
                break;
            case 5:
                SupprimererunContact();
                break;
                
            default:
                printf("Choix nexiste pas");
        }

    }

    return 0;
}
