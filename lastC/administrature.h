#ifndef ADMINISTRATURE_H_INCLUDED
#define ADMINISTRATURE_H_INCLUDED
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <conio.h>

#define TAILLE_MATRICULE 20
#define TAILLE_DATE 20



int daysInMonth(int year, int month)
{
    const int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (month == 2 && isLeapYear(year))
    {
        return 29;
    }

    return days[month];
}

int isValidDate(int year, int month, int day)
{
    if (year < 1 || month < 1 || month > 12 || day < 1 || day > daysInMonth(year, month))
    {
        return 0;
    }
    return 1;
}
char matricule[20];
char Nom[30];
char prix[10];

 void modifier_password(char oldpassword[10]){
     char newpssword[10];
     int n = 1;
     while (n)
     {
         n = 0;
         printf("entrer  the new password (< 10 digit): ");
         scanf("%s", newpssword);
         if (strcmp(newpssword, oldpassword) == 0){
             printf("its the same as the old !! \n");
             n = 1;
         }


     }


     FILE *p =fopen("pasword.bin", "wb");
     if(p==NULL){
         exit(EXIT_FAILURE);
     }
    if(fwrite(newpssword, sizeof(char),10, p)!=0){
        printf("update succefuly");
    }

    fclose(p);
 }
void supression_voiture()
{
    char matricule1[10];
    FILE *p = fopen("voiture.txt", "r");
    FILE *p1 = fopen("voiture-temp.txt", "w");
    FILE *p2 = fopen("date_dispo-temp.txt", "w");
    FILE *p3 = fopen("dispnible_dates.txt", "r");

    if (p == NULL || p1 == NULL)
    {
        printf("ereur");
        exit(1);
    }
    char NUM[50], num[20];
    int n = 0,chek=0;
    printf("entrer le matricule du voiture");
    scanf("%s", matricule1);

    while (fgets(NUM, 50, p3) != 0)
    {
        if (strstr(NUM, matricule1) != NULL)
        {   chek=1;
            n = 0;
            while (fgets(NUM, 50, p3) != 0)
            {
                chek=2;
                rewind(p);
                while (fgets(num, 20, p) != 0)
                {
                    if (strcmp(NUM, num) == 0)
                    {
                        n = 1;
                    }
                }
                if (n == 1 )
                    break;
                ;
            }
            if(chek==1){
                break;
            }
        }

        fputs(NUM, p2);
    }


    fclose(p3);
    fclose(p2);


    if (chek==0){

         remove("date_dispo-temp.txt");
         printf("la voiture n'exist pas!!!!");
         printf("\n\npress any key to return : ?");
        scanf("%d",&n);
        return;



    }
      remove("dispnible_dates.txt");
     rename("date_dispo-temp.txt","dispnible_dates.txt");

    rewind(p);
    while (fgets(matricule, 20, p) != 0 && fgets(Nom, 30, p) != 0 && fgets(prix,10,p)!= 0)
    {
        if (strstr(matricule, matricule1) != NULL)
        {
            continue;
        }
        fputs(matricule, p1);
        fputs(Nom, p1);
        fputs(prix,p1);
    }

    fclose(p1);
    fclose(p);
     int  t;
    t=remove("voiture.txt");
    rename("voiture-temp.txt", "voiture.txt");
    if(t!=0){
        printf("il ya une erreur la voiture nest pa suprimer !!!");
        remove("voiture-temp.txt");
         printf("\n\npress any key to return : ?");
        scanf("%d",&t);
        return;
    }
      printf("  la voiture est suprimer");
        supprimer(matricule1);
        printf("\n\npress any key to return : ?");
        scanf("%d",&t);
        return;


}
void ajouter_voitur()
{
    int fday, fmonth, fyear;
    int tday, tmonth, tyear;
    char pmtr[30];
    int chek=0;
    printf("entrer le matricule : ");
    gets(matricule);
     FILE *p = fopen("voiture.txt", "r");

     while(fgets(pmtr,30,p)!=0){
        if(strstr(pmtr,matricule)!=NULL){
            chek=1;
        }



     }
    fclose(p);
    if(chek==1){
        printf("\n\nla voiture deja exist !!!! ");
        printf("\n\npress any key to return  :  ");
        scanf("%d",&chek);
        return;
    }

       p = fopen("voiture.txt", "a+");
    FILE *p1 = fopen("dispnible_dates.txt", "a");

    if (p == NULL)
    {
        printf("ereur");
        exit(1);
    }

    printf("entrer le Nom : ");
    gets(Nom);
    printf("entrer le prix par jour : ");
    gets(prix);

    int n1=0,n2=0;
    while(n1!=3 || n2!=3 || !isValidDate(fyear,fmonth,fday) || !isValidDate(tyear,tmonth,tday)){
        system("cls");
     printf("entrer une date valable ou la voiture est disponible:  \n");
     printf("from JJ/MM/YY: ");
     n1=scanf("%d/%d/%d",&fday,&fmonth,&fyear);
     printf("TO JJ/MM/YY : ");
     n2=scanf("%d/%d/%d",&tday,&tmonth,&tyear);

    }

    fprintf(p, "%s\n",matricule);
    fprintf(p, "%s\n",Nom);
    fprintf(p, "%s\n",prix);


    fputs(matricule, p1);
    fprintf(p1, "\n");
    fprintf(p1, "%d %d %d  %d %d %d\n",fday,fmonth,fyear,tday,tmonth,tyear);
    fclose(p);
    fclose(p1);
    ajouter(matricule);

}

int ajouter(char matricule[TAILLE_MATRICULE];) {
    FILE *fichier;
    fichier = fopen("informations.bin", "ab");

    if (fichier == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        return;
    }

    char dateExpirationAssurance[TAILLE_DATE];
    char dateExpirationCarteGrise[TAILLE_DATE];
    char dateExpirationVignette[TAILLE_DATE];


    printf("Entrez la date d'expiration de l'assurance : ");
    scanf("%s", dateExpirationAssurance);

    printf("Entrez la date d'expiration de la carte grise : ");
    scanf("%s", dateExpirationCarteGrise);

    printf("Entrez la date d'expiration de la vignette : ");
    scanf("%s", dateExpirationVignette);

    fprintf(fichier, "%s %s %s %s\n", matricule, dateExpirationAssurance, dateExpirationCarteGrise, dateExpirationVignette);

    fclose(fichier);

    printf("Informations ajoutées avec succès.\n");

    int c;
    scanf("%d",&c);
    return;
}





void afficher() {
    FILE *fichier;
    fichier = fopen("informations.bin", "rb");

    if (fichier == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        return;
    }

    char matriculeRecherche[TAILLE_MATRICULE];
    printf("Entrez le matricule de la voiture pour afficher les informations : ");
    scanf("%s", matriculeRecherche);

    char matricule[TAILLE_MATRICULE];
    char dateExpirationAssurance[TAILLE_DATE];
    char dateExpirationCarteGrise[TAILLE_DATE];
    char dateExpirationVignette[TAILLE_DATE];
  int c;
    while (fscanf(fichier, "%s %s %s %s", matricule, dateExpirationAssurance, dateExpirationCarteGrise, dateExpirationVignette) != EOF) {
        if (strcmp(matricule, matriculeRecherche) == 0) {
            printf("Matricule: %s\n", matricule);
            printf("Date d'expiration de l'assurance: %s\n", dateExpirationAssurance);
            printf("Date d'expiration de la carte grise: %s\n", dateExpirationCarteGrise);
            printf("Date d'expiration de la vignette: %s\n", dateExpirationVignette);
            fclose(fichier);
            printf("\n\npress any key to return : ?");
            scanf("%d",&c);
            return;
        }
    }

    printf("Aucune information trouvée pour le matricule %s.\n", matriculeRecherche);
    fclose(fichier);
    printf("\n\npress any key to return : ?");
    scanf("%d",&c);
            return;
}



void supprimer(char matriculeRecherche[TAILLE_MATRICULE]) {
    FILE *fichierTemp;
    FILE *fichier;

    char matricule[TAILLE_MATRICULE];
    char dateExpirationAssurance[TAILLE_DATE];
    char dateExpirationCarteGrise[TAILLE_DATE];
    char dateExpirationVignette[TAILLE_DATE];


    fichier = fopen("informations.bin", "rb");
    fichierTemp = fopen("temp.bin", "wb");

    if (fichier == NULL || fichierTemp == NULL) {
        perror("Erreur lors de l'ouverture des fichiers");
        return;
    }

    int suppressionEffectuee = 0;

    while (fscanf(fichier, "%s %s %s %s", matricule, dateExpirationAssurance, dateExpirationCarteGrise, dateExpirationVignette) != EOF) {
        if (strcmp(matricule, matriculeRecherche) == 0) {
            printf("Matricule: %s\n", matricule);
            printf("Date d'expiration de l'assurance: %s\n", dateExpirationAssurance);
            printf("Date d'expiration de la carte grise: %s\n", dateExpirationCarteGrise);
            printf("Date d'expiration de la vignette: %s\n", dateExpirationVignette);

            printf("Informations supprimées avec succès.\n");
            suppressionEffectuee = 1;
        } else {
            fprintf(fichierTemp, "%s %s %s %s\n", matricule, dateExpirationAssurance, dateExpirationCarteGrise, dateExpirationVignette);
        }
    }

    fclose(fichier);
    fclose(fichierTemp);

    remove("informations.bin");
    rename("temp.bin", "informations.bin");

    if (!suppressionEffectuee) {
        printf("Aucune information trouvée pour le matricule %s.\n", matriculeRecherche);
    }
}


void modifier() {
    FILE *fichierTemp;
    FILE *fichier;
    char matriculeRecherche[TAILLE_MATRICULE];
    char matricule[TAILLE_MATRICULE];
    char dateExpirationAssurance[TAILLE_DATE];
    char dateExpirationCarteGrise[TAILLE_DATE];
    char dateExpirationVignette[TAILLE_DATE];
    char choixModification;

    printf("Entrez le matricule de la voiture pour modifier les informations : ");
    scanf("%s", matriculeRecherche);

    fichier = fopen("informations.bin", "rb");
    fichierTemp = fopen("temp.bin", "wb");

    if (fichier == NULL || fichierTemp == NULL) {
        perror("Erreur lors de l'ouverture des fichiers");
        return;
    }

    int modificationEffectuee = 0;

    while (fscanf(fichier, "%s %s %s %s", matricule, dateExpirationAssurance, dateExpirationCarteGrise, dateExpirationVignette) != EOF) {
        if (strcmp(matricule, matriculeRecherche) == 0) {
            printf("Matricule: %s\n", matricule);
            printf("Date d'expiration de l'assurance actuelle: %s\n", dateExpirationAssurance);
            printf("Date d'expiration de la carte grise actuelle: %s\n", dateExpirationCarteGrise);
            printf("Date d'expiration de la vignette actuelle: %s\n", dateExpirationVignette);

            printf("Voulez-vous modifier la date d'expiration de l'assurance (A), de la carte grise (C) ou de la vignette (V) ? ");
            scanf(" %c", &choixModification);

            if (choixModification == 'A' || choixModification == 'a') {
                printf("Entrez la nouvelle date d'expiration de l'assurance : ");
                scanf("%s", dateExpirationAssurance);
            } else if (choixModification == 'C' || choixModification == 'c') {
                printf("Entrez la nouvelle date d'expiration de la carte grise : ");
                scanf("%s", dateExpirationCarteGrise);
            } else if (choixModification == 'V' || choixModification == 'v') {
                printf("Entrez la nouvelle date d'expiration de la vignette : ");
                scanf("%s", dateExpirationVignette);
            } else {
                printf("Choix invalide. Aucune modification effectuée.\n");
                fprintf(fichierTemp, "%s %s %s %s\n", matricule, dateExpirationAssurance, dateExpirationCarteGrise, dateExpirationVignette);
                continue;
            }

            fprintf(fichierTemp, "%s %s %s %s\n", matricule, dateExpirationAssurance, dateExpirationCarteGrise, dateExpirationVignette);
            printf("Informations modifiées avec succès.\n");
            modificationEffectuee = 1;
        } else {
            fprintf(fichierTemp, "%s %s %s %s\n", matricule, dateExpirationAssurance, dateExpirationCarteGrise, dateExpirationVignette);
        }
    }

    fclose(fichier);
    fclose(fichierTemp);

    remove("informations.bin");
    rename("temp.bin", "informations.bin");

    if (!modificationEffectuee) {
        printf("Aucune information trouvée pour le matricule %s.\n", matriculeRecherche);
    }
}

typedef struct clients2{

     char Nom_complet[20];
     char CIN[20];
     char mtr[20];
     int id_rsr;
     char permit[20];
     int prix_par_jour;
     int jn,mn,an;
     int fj,fm,fa;
     int tj,tm,ta;
     float total;
}clients2;
int aficher_les_reservation(){
    system("cls");
    int n;
 FILE *clipf= fopen ("client.bin","rb");
    clients2 clip;
       while(fread(&clip,sizeof(clients2),1,clipf)!=0){

               printf("\nid_res : %d",clip.id_rsr);
               printf("\nom : %s",clip.Nom_complet);

       }
  fclose(clipf);

  printf("press any key to return : ");
  scanf("%d",&n);
  return 0 ;

}





char* createpassword() {
    char* passwd = (char*)malloc(10 * sizeof(char));
    int i = 0;
    char c;
    while ((c = getch()) != 13 && i <10 - 1) {
        *(passwd + i) = c;
        if (c == 8) {
            if (i > 0) {
                putch('\b');
                putch(' ');
                putch('\b');
                i--;
            }
            continue;
        }

        printf("*");
        i++;
    }
    *(passwd + i) = '\0';
    return passwd;
}

/*typedef struct date{
    int j;
    int m;
    int a;
}date;

int AjoutLesInfosAdministrativesDeNouvelleVoiture(char matricule12[20]) {
    date e;
    printf("%s",matricule12);
    FILE *r = fopen("InfosAdministratives.dot", "ab");
    if (r == NULL) {
        printf("Echec d'ouverture du fichier InfosAdministratives.dot\n");
        return 2;
    }
    fwrite(matricule12, sizeof(char), 20, r);
    printf("Tapez la date d'expiration d'assurance de cette voiture jj/mm/aa : ");
    scanf("%d/%d/%d", &e.j, &e.m, &e.a);
    fwrite(&e, sizeof(date), 1, r);
    printf("Tapez la date de d�but de validit� de la carte grise de cette voiture jj/mm/aa : ");
    scanf("%d/%d/%d", &e.j, &e.m, &e.a);
    fwrite(&e, sizeof(date), 1, r);
    printf("Tapez la date du prochain contr�le technique de cette voiture jj/mm/aa : ");
    scanf("%d/%d/%d", &e.j, &e.m, &e.a);
    fwrite(&e, sizeof(date), 1, r);
    printf("Tapez la date d'expiration de la vignette de cette voiture jj/mm/aa : ");
    scanf("%d/%d/%d", &e.j, &e.m, &e.a);
    fwrite(&e, sizeof(date), 1, r);
    fclose(r);
    return 1;
}

int LireInfosDeVoiture() {
    fflush(stdin);
    system("cls");
    char a[20];
    char d[20];
    date e;
    FILE *r = fopen("InfosAdministratives.dot", "rb");
    if (r == NULL) {
        printf("Echec d'ouverture du fichier InfosAdministratives.dot\n");
        return 2;
    }
    printf("Tapez le matricule � chercher : ");
    scanf("%s",a);
    while (fread(d, sizeof(char), 20, r) !=0) {
        if (strcmp(a,d)==0) {
             printf("%s\n\n",d);
            fread(&e, sizeof(date), 1, r);
            printf("La date d'expiration d'assurance de cette voiture est %d/%d/%d\n", e.j, e.m, e.a);
            fread(&e, sizeof(date), 1, r);
            printf("La date de d�but de validit� de la carte grise de cette voiture est %d/%d/%d\n", e.j, e.m, e.a);
            fread(&e, sizeof(date), 1, r);
            printf("La date du prochain contr�le technique de cette voiture est %d/%d/%d\n", e.j, e.m, e.a);
            fread(&e, sizeof(date), 1, r);
            printf("La date d'expiration de la vignette de cette voiture est %d/%d/%d\n", e.j, e.m, e.a);
        }else{
          fread(&e, sizeof(date), 1, r);

            fread(&e, sizeof(date), 1, r);

            fread(&e, sizeof(date), 1, r);

            fread(&e, sizeof(date), 1, r);



        }
    }
    fclose(r);

    int n ;
    printf("pres any key to return : ");
    scanf("%d",&n);
    return 0;
}


*/

#endif // ADMINISTRATURE_H_INCLUDED
