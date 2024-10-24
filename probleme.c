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
    printf("\nNom : %s\n", personne.nom);
    printf("Age : %d\n", personne.age);
    printf("Adresse : %s, %s, %d\n", personne.adresse.rue, personne.adresse.ville, personne.adresse.code_postal);  
}

int main() {
    struct personne personne1;

    creer(&personne1);

    afficher(personne1);

    return 0;
}
