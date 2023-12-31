#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "administrature.h"
#include "clients.h"




void administrature()
{       system("cls");
        printf("\n\n\n\n");
        printf("\t\t\t\t\t\t****************************************************************************************************************\t\t\t\t\t\n");
        printf("\t\t\t\t\t\t******************************* BIENVENUE A L'APPLICATION DE L'OCATION DE VOITURE*******************************\t\t\t\t\t\n");
        printf("\t\t\t\t\t\t****************************************************************************************************************\t\t\t\t\t\n");
        printf("\n\n\n\n");
    FILE *p = fopen("pasword.bin", "rb");
    char pasword[10], pasword1[10];
    int c=3;
    fread(pasword1, sizeof(char), 10, p);
    printf("enter pasword : ");

      strcpy(pasword , createpassword());
    /*scanf("%s", pasword);*/
    while(1){
    if (strcmp(pasword1, pasword) != 0 )
    {
        c--;
        if(c==0){
            system("cls");
           printf("\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\tl'application est bloquer ('-')\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        exit(1);
        }
          system("cls");
         printf("\n\n\n\n");
        printf("\t\t\t\t\t\t****************************************************************************************************************\t\t\t\t\t\n");
        printf("\t\t\t\t\t\t******************************* BIENVENUE A L'APPLICATION DE L'OCATION DE VOITURE*******************************\t\t\t\t\t\n");
        printf("\t\t\t\t\t\t****************************************************************************************************************\t\t\t\t\t\n");
        printf("\n\n\n\n");
        printf("!!!!!incorrect il reste %d fois \n\n",c);
        printf("enter pasword : ");
        strcpy(pasword , createpassword());
        continue;
    }
     break;
     fclose(p);

    }


    int n = 20;
    while (n)
    {
        system("cls");
        printf("\n\n\n\n");
        printf("\t\t\t\t\t\t****************************************************************************************************************\t\t\t\t\t\n");
        printf("\t\t\t\t\t\t******************************* BIENVENUE A L'APPLICATION DE L'OCATION DE VOITURE*******************************\t\t\t\t\t\n");
        printf("\t\t\t\t\t\t****************************************************************************************************************\t\t\t\t\t\n");
        printf("\n\n\n\n");
         printf("!!!!!welcome!!!!!\n\n");
        printf("ajouter un vouture :                     1 \n\n");
        printf("suprimer un vouture :                    2 \n\n");
        printf("lire info duvoiture :                    3 \n\n");
        printf("modifier les info du voiture :           4 \n\n");
        printf("modifier_password :                      5 \n\n");
        printf("aficher_les_reservation :                6 \n\n");
        printf("anulle une reservation :                 7 \n\n");
        printf("exit :                                   0 \n\n");
        printf("press any key to return  :               ? \n\n");

        printf("resultat : ");
        scanf("%d", &n);
        fflush(stdin);
        switch (n)
        {
        case 1:
            ajouter_voitur();
            break;
        case 2:
            supression_voiture();
            break;
        case 3:
             afficher();
            break;
        case 4:
             modifier();
            break;
        case 5:
            modifier_password(pasword);
            break;
        case 6:
            aficher_les_reservation();
            break;
        case 7:
            modifier_date_resirvation(1);
            break;
        case 0:
            exit(1);
            break;
        default:
            n = 0;
            break;
        }
    }
}

void client()
{

    int n =1,n2 =3;

    while(n){
           system("cls");
        printf("\n\n\n\n");
        printf("\t\t\t\t\t\t****************************************************************************************************************\t\t\t\t\t\n");
        printf("\t\t\t\t\t\t******************************* BIENVENUE A L'APPLICATION DE L'OCATION DE VOITURE*******************************\t\t\t\t\t\n");
        printf("\t\t\t\t\t\t****************************************************************************************************************\t\t\t\t\t\n");
        printf("\n\n\n\n");

     if(n2==0){
        printf("la voiture n'est exist pas : \n \n");
     }else if(n2==1){
        printf("la voiture est toutalment reserver \n\n : \n \n");
     }
    printf("choisi une voiture :       1\n\n");
    printf("modifier une resirvation : 2\n\n");
    printf("voire_monreservation       3\n\n");
    printf("exit :                     0\n\n");
    printf("press any key to return  : ?\n\n");
    printf("r�saultat:  ");
    scanf("%d", &n);

    switch (n)
    {
    case 1:
        n2=affiche_dates();
        n=1;
        break;
    case 2:
        modifier_date_resirvation(0);
        n=1;
        break;
    case 3:
        voire_monreservation();
        break;
    case 0:
        exit(1);
        break;

    default:
        n=0;
        break;
}
}

}

int main()
{
      int choix;


    int n = 2;
    while (n)
    {
       system("cls");
        printf("\n\n\n\n");
        printf("\t\t\t\t\t\t****************************************************************************************************************\t\t\t\t\t\n");
        printf("\t\t\t\t\t\t******************************* BIENVENUE A L'APPLICATION DE L'OCATION DE VOITURE*******************************\t\t\t\t\t\n");
        printf("\t\t\t\t\t\t****************************************************************************************************************\t\t\t\t\t\n");
        printf("\n\n\n\n");
        printf("administrature : 1\n");
        printf("client :         2\n");
        printf("exit :           0\n");
        printf("resaultat : ");
        scanf("%d", &choix);
        n = 0;
        switch (choix)
        {

        case 1:
            administrature();
            n = 1;
            break;
        case 2:
            client();
            n=1;
            break;

        default:
            break;
        }
    }
    return 0;
}


