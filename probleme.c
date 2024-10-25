#include <stdio.h>

struct adresse {
    char rue[30];
    char ville[30];  
    int code_postal;
};

struct personne {
    char nom[30];
    int age;
    struct adresse adresse;
};

void creer(struct personne *personne) {
    printf("Nom : ");
    scanf("%s", personne->nom); 

    printf("Age : ");
    scanf("%d", &personne->age); 

    printf("Rue : ");
    scanf("%s", personne->adresse.rue); 

    printf("Ville : ");
    scanf("%s", personne->adresse.ville); 

    printf("Code postal : ");
    scanf("%d", &personne->adresse.code_postal); 
}

void afficher(struct personne personne) {
    printf("----------------------- Informations de %s ----------------------\n", personne.nom);
    printf("Nom : %s\n", personne.nom);
    printf("Age : %d\n", personne.age);
    printf("Adresse : %s, %s, %d\n", personne.adresse.rue, personne.adresse.ville, personne.adresse.code_postal);  
}

void modifie(struct personne *personne) {
    printf("Modifier le nom : ");
    scanf("%s", personne->nom); 

    printf("Modifier l'âge : ");
    scanf("%d", &personne->age); 

    printf("Modifier la rue : ");
    scanf("%s", personne->adresse.rue); 

    printf("Modifier la ville : ");
    scanf("%s", personne->adresse.ville); 

    printf("Modifier le code postal : ");
    scanf("%d", &personne->adresse.code_postal); 
}

void supprimer(struct personne personnes[], int *nbrpersonnes, int index) {
    for (int i = index; i < (*nbrpersonnes) - 1; i++) {
        personnes[i] = personnes[i + 1];
    }
    (*nbrpersonnes)--;
}

int main() {
    struct personne personnes[50];  
    int nbrpersonnes = 0;           
    int choix, indice;

    do {
        printf("\n------------------Menu-----------------\n");
        printf("1. Ajouter une personne\n");
        printf("2. Afficher toutes les personnes\n");
        printf("3. Mettre a jour une personne\n");
        printf("4. Supprimer une personne\n");
        printf("5. Quitter\n");
        printf("Choisissez une option : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1: 
                if (nbrpersonnes < 50) {
                    creer(&personnes[nbrpersonnes]);
                    nbrpersonnes++;
                } else {
                    printf("Erreur : Le tableau est plein.\n");
                }
                break;

            case 2: 
                if (nbrpersonnes == 0) {
                    printf("Aucune personne enregistrée.\n");
                } else {
                    printf("\nListe des personnes :\n");
                    for (int i = 0; i < nbrpersonnes; i++) {
                        afficher(personnes[i]);
                    }
                }
                break;

            case 3: 
                if (nbrpersonnes == 0) {
                    printf("Aucune personne enregistrée.\n");
                } else {
                    printf("Entrez l'indice de la personne à modifier (0 à %d) : ", nbrpersonnes - 1);
                    scanf("%d", &indice);
                    if (indice >= 0 && indice < nbrpersonnes) {
                        modifie(&personnes[indice]);
                    } else {
                        printf("Indice invalide.\n");
                    }
                }
                break;

            case 4: 
                if (nbrpersonnes == 0) {
                    printf("Aucune personne enregistrée.\n");
                } else {
                    printf("Entrez l'indice de la personne à supprimer (0 à %d) : ", nbrpersonnes - 1);
                    scanf("%d", &indice);
                    if (indice >= 0 && indice < nbrpersonnes) {
                        supprimer(personnes, &nbrpersonnes, indice);
                        printf("Personne supprimée.\n");
                    } else {
                        printf("Indice invalide.\n");
                    }
                }
                break;

            case 5: 
                printf("Au revoir!\n");
                break;

            default:
                printf("Choix invalide. Veuillez réessayer.\n");
        }
    } while (choix != 5);

    return 0;
}
