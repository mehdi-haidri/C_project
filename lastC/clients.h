#ifndef CLIENTS_H_INCLUDED
#define CLIENTS_H_INCLUDED
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

int isLeapYear(int year)
{
    return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
}





void date_retrival(char matricule6[],int prix_count){
    fflush(stdin);
    FILE *p;
    char matricule1[50];
    p = fopen("test.txt", "r");
    int fday, fmonth, fyear;
    int tday, tmonth, tyear;
    int pfday, pfmonth, pfyear;
    int ptday, ptmonth, ptyear;

    int n1=0,n2=0;
    while(n1!=3 || n2!=3 || !isValidDate(fyear,fmonth,fday) || !isValidDate(tyear,tmonth,tday)){
            fflush(stdin);
    printf("entrer une date cerrect disponible :  \n");
    printf("from JJ/MM/YY: ");
    n1=scanf("%d/%d/%d",&fday,&fmonth,&fyear);
    printf("TO JJ/MM/YY : ");
    n2=scanf("%d/%d/%d",&tday,&tmonth,&tyear);
    }
    int n = 0;
    while (fscanf(p, "%d %d %d  %d %d %d", &pfday, &pfmonth, &pfyear, &ptday, &ptmonth, &ptyear) ==6)

    {
        if (pfyear <= fyear)
        {
            if (pfyear == fyear)
            {
                if (pfmonth <= fmonth)
                {
                    if (pfmonth == fmonth)
                    {
                        if (pfday <= fday)
                        {
                            n++;
                        }
                    }
                    else
                    {
                        n++;
                    }
                }
            }
            else
            {
                n++;
            }
        }
        if (ptyear >= tyear)
        {
            if (ptyear == tyear)
            {
                if (ptmonth >= tmonth)
                {
                    if (ptmonth == tmonth)
                    {
                        if (ptday >= tday)
                        {
                            n++;
                        }
                    }
                    else
                    {
                        n++;
                    }
                }
            }
            else
            {
                n++;
            }
        }
        if (n == 2)
        {
            break;
        }
        n = 0;
    }
    if(n==0){
        fclose(p);
        printf("!!!!!!!la date n'est pas diponible !!!!!!!!! \n\n");
        date_retrival(matricule6,prix_count);
    }
       fclose(p);
       FILE *p4 = fopen("text2.txt", "w+");
       fprintf(p4,"%d %d %d  %d %d %d\n", pfday, pfmonth, pfyear, ptday, ptmonth, ptyear);
       rewind(p4);
       char date[50];
       fgets(date,50,p4);
       FILE *p2 = fopen("dispnible_dates.txt", "r");
       FILE *p3 = fopen("dispnible_dates-temp.txt", "w");

       while (fgets(matricule1, 50, p2) != 0)
       {
           fflush(stdin);
           if (strstr(matricule1, matricule6) != NULL)
           {
             fputs(matricule1, p3);
               while (fgets(matricule1,50,p2)!=0)
               {
                   if (strcmp(matricule1,date)==0)
                   {
                       if(pfmonth!=fmonth || pfday!=fday || pfyear!=fyear) {

                          if(fday==1 && (fmonth-1==0|| fmonth-1==1 ||fmonth-1==3 ||fmonth-1==5 || fmonth-1==7||fmonth-1==8 || fmonth-1==10|| fmonth-1==12) ){
                             if(fmonth-1==0)fprintf(p3, "%d %d %d  %d %d %d\n", pfday, pfmonth, pfyear, 31, 12, fyear-1);
                              else fprintf(p3, "%d %d %d  %d %d %d\n", pfday, pfmonth, pfyear, 31, fmonth-1, fyear);
                          }else if(fday==1 && (fmonth-1==4 ||fmonth-1==6 || fmonth-1==9 || fmonth-1==11)){
                             fprintf(p3, "%d %d %d  %d %d %d\n", pfday, pfmonth, pfyear, 30, fmonth-1, fyear);
                             }
                           if(fmonth-1==2){
                               if( fday==1 && isLeapYear(tyear)){
                                 fprintf(p3, "%d %d %d  %d %d %d\n", pfday, pfmonth, pfyear, 29, fmonth-1, fyear);
                               }else if(fday==1 && !isLeapYear(tyear)){
                                 fprintf(p3, "%d %d %d  %d %d %d\n", pfday, pfmonth, pfyear, 28, fmonth-1, fyear);
                                }else{
                                fprintf(p3, "%d %d %d  %d %d %d\n", pfday, pfmonth, pfyear, fday-1, fmonth, fyear);
                                 }
                           }
                             if((fmonth -1 )!= 2 && fday !=1){
                                fprintf(p3, "%d %d %d  %d %d %d\n", pfday, pfmonth, pfyear, fday-1, fmonth, fyear);

                            }
                            }

                          if(ptmonth!=tmonth || ptday!=tday || ptyear!=tyear){

                          if((tday==30)&& (fmonth==1 ||fmonth==3 ||fmonth==5 || fmonth==7||fmonth==8 || fmonth==10|| fmonth==12)){
                             fprintf(p3, "%d %d %d  %d %d %d\n", 31, tmonth, tyear, ptday, ptmonth, ptyear);
                          }else if((tday==30 ) && (fmonth==4 ||fmonth==6 || fmonth==9 || fmonth==11)){
                           fprintf(p3, "%d %d %d  %d %d %d\n", 1, tmonth+1, tyear, ptday, ptmonth, ptyear);
                           }
                           else if(tday==31){
                                if(fmonth==12) fprintf(p3, "%d %d %d  %d %d %d\n", 1, 1, tyear+1, ptday, ptmonth, ptyear);
                                else fprintf(p3, "%d %d %d  %d %d %d\n", 1, tmonth+1, tyear, ptday, ptmonth, ptyear);
                           }
                           if(tmonth==2){
                           if( tday==28 && isLeapYear(tyear)){
                                 fprintf(p3, "%d %d %d  %d %d %d\n", 29, tmonth, tyear, ptday, ptmonth, ptyear);
                              }else if(tday==28 && !isLeapYear(tyear)){
                               fprintf(p3, "%d %d %d  %d %d %d\n", 1, tmonth+1, tyear, ptday, ptmonth, ptyear);
                               }else if(tday==29){
                                  fprintf(p3, "%d %d %d  %d %d %d\n", 1, tmonth+1, tyear, ptday, ptmonth, ptyear);
                                 }else{
                                     fprintf(p3, "%d %d %d  %d %d %d\n", tday+1, tmonth, tyear, ptday, ptmonth, ptyear);
                                 }
                           }

                            if(tmonth != 2 && tday !=30 && tday !=31 ){

                                fprintf(p3, "%d %d %d  %d %d %d\n", tday+1, tmonth, tyear, ptday, ptmonth, ptyear);
                            }}

                       continue;
                   }
                   fputs(matricule1, p3);
               }
               break;
           }
           fputs(matricule1, p3);
    }
    fclose(p2);
    fclose(p3);
    fclose(p4);
    char confermer[5];
    int chek;
    float total ;
    total =(tranform_and_count( fday,  fmonth, fyear, tday,  tmonth, tyear)+1)*prix_count;
    printf("your toutal is  %.2f DH \n\n",total);
    printf("are you sure you want to continue yes/no : ");
    scanf("%s",confermer);
    if(strcmp("yes",confermer)==0){
     getInfo_clients(fyear,fmonth,fday,tyear,tmonth,tday,matricule6,prix_count,&total);
     chek=remove("dispnible_dates.txt");
     if(chek!=0){
          remove("dispnible_dates-temp.txt");
          system("cls");
          printf("!!!!!erreur la riservation n'est pas efectue !!!!!! ");
          exit(1);
     }
      rename("dispnible_dates-temp.txt", "dispnible_dates.txt");
    }else{
       remove("dispnible_dates-temp.txt");
    }

}




int affiche_dates()
{
    system("cls");

    FILE *voiture = fopen("voiture.txt", "r+");
char matricule[10], Nom[20],prix[10];
system("cls");

 printf("\n\n\n\n");
        printf("\t\t\t\t\t\t****************************************************************************************************************\t\t\t\t\t\n");
        printf("\t\t\t\t\t\t******************************* BIENVENUE A L'APPLICATION DE L'OCATION DE VOITURE*******************************\t\t\t\t\t\n");
        printf("\t\t\t\t\t\t****************************************************************************************************************\t\t\t\t\t\n");
        printf("\n\n\n\n");


printf("###########les voiture dismonible sont:############# \n\n");
while (fgets(matricule, 10, voiture) != 0 && fgets(Nom, 20, voiture) != 0 &&fgets(prix,10,voiture))
{

    printf("\t\t\t\t\t\t\t#  NOM : %s",Nom);
    printf("\t\t\t\t\t\t\t#  Matricule: %s",matricule);
    printf("\t\t\t\t\t\t\t#  tprix: %s",prix);
     printf("\t\t\t\t\t\t\t#####################\n\t\t\t\t\t\t\t#\n");
    }
    fclose(voiture);


    fflush(stdin);
    char date[50], num[10];
    char Num2[10];
     int n = 0,n2=0;
    FILE *p = fopen("dispnible_dates.txt", "r");
    FILE *p1 = fopen("voiture.txt", "r");
    FILE *p2 = fopen("test.txt", "w");
    if (p == NULL)
       printf("0");

    printf("\n\nentrer le Matricule  de voiture  que te a chisi : ");
    gets(Num2);
     int prix_count;
   while (fgets(matricule, 10, p1) != 0 && fgets(Nom, 20, p1) != 0 ){
                   if(strstr(matricule,Num2)!=NULL);
                   {
                       fscanf(p1,"%d",&prix_count);
                       break;
                   }
               fgets(prix,10,p1);
    }





    if(strlen(Num2)<4){
        fclose(p);
        fclose(p1);
        fclose(p2);
        return 0;
    }
     system("cls");
        printf("\n\n\n\n");
        printf("\t\t\t\t\t\t****************************************************************************************************************\t\t\t\t\t\n");
        printf("\t\t\t\t\t\t******************************* BIENVENUE A L'APPLICATION DE L'OCATION DE VOITURE*******************************\t\t\t\t\t\n");
        printf("\t\t\t\t\t\t****************************************************************************************************************\t\t\t\t\t\n");
        printf("\n\n\n\n");
   rewind(p1);
    printf("\n\n\t\t\t\t\t\t\t##############les date disponible sont:############# \n \n");
    while (fgets(date, 50, p) != 0)
    {
        if (strstr(date, Num2) != NULL )
        {
             n2=1;
            break;
        }
    }

    if(n2!=1){
    fclose(p);
    fclose(p1);
    fclose(p2);
       return 0;
    }
    while (fgets(date, 50, p) != 0)
    {
        rewind(p1);
        n = 0;
        while (fgets(num, 10, p1) != 0)
        {
            if (strcmp(date, num) == 0)
            {
                n = 1;
                break;
            }
        }
        if (n == 1)
        {
            break;
        }
        n2=2;
        printf("\t\t\t\t\t\t\t\t\t");
        puts(date);
        fputs(date, p2);
    }
    if(n2!=2){
    fclose(p);
    fclose(p1);
    fclose(p2);
        return 1;
    }

    fclose(p);
    fclose(p1);
    fclose(p2);
    printf("resirver une dates : 1\n\n");
    printf("choisi une autre voiture : 2\n\n");
     printf("exit  : 0 \n\n");
     printf("press any key to return  : ? \n\n");
     printf("resaultat : ");
     scanf("%d", &n2);
     switch (n2)
     {
     case 1:
         date_retrival(Num2,prix_count);
         break;
     case 2:
         affiche_dates();
         break;
     case 0:
         exit(1);
         break;
    default:
         break;
    }
   return 3;
}




typedef struct clients{

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
     char Nom_voiture[20];
}clients;
void getInfo_clients( int fyear1, int fmonth1, int fday1,int tyear1, int tmonth1, int tday1,char mtr[],int prix_par_jour,float * totale_prix ){
    fflush(stdin);
    int n=0;
    char Nom_voiture[20];
   clients cli;
   strcpy(cli.mtr,mtr);
  system("cls");
  FILE *p =fopen ("client.bin","ab");
  FILE *p2= fopen ("voiture.txt","r");
  if(p==NULL || p2==NULL){
    printf("erreur dans la fonction get info clients");
    exit(1);
  }
  while(fgets(Nom_voiture,20,p2)!=0){
           if(strstr(Nom_voiture,mtr)!=NULL){
               fgets(Nom_voiture,20,p2)!=0;
                strcpy(cli.Nom_voiture,Nom_voiture);
                break;
           }
  }
  fclose(p2);
   cli.id_rsr=id_resirvaion();
    cli.prix_par_jour=prix_par_jour;

  printf("\nentrer votre Nom complet : ");
  gets(cli.Nom_complet);
  printf("\nentrer votre CIN : ");
  scanf("%s",cli.CIN);
  printf("\nentrer votre permit : ");
  scanf("%s",cli.permit);

  while(!n){
        fflush(stdin);
     printf("entrer votre date de naissance  jj/mm/yy : ");
      scanf ("%d/%d/%d",&cli.jn,&cli.mn,&cli.an);
      n=isValidDate(cli.an,cli.mn,cli.jn);
  }
  cli.total = *totale_prix*1.00;
  cli.fj=fday1;
  cli.fm=fmonth1;
  cli.fa=fyear1;
  cli.tj=tday1;
  cli.tm=tmonth1;
  cli.ta=tyear1;

  fwrite(&cli,sizeof(clients),1,p);
  fclose(p);
  system("cls");
   printf("\n\n\n##########la resirvation est efectuer########\n\n" );

   printf("votre id de resirvation : %d \n\n",cli.id_rsr);
  printf("press any key to return : ");
  scanf("%d",&n);
  fflush(stdin);
  fclose(p);
}

void modifier_date_resirvation(int anuler){
    /*char Nom[20];
    char CIN[20];
    char matricule[20];*/
    clients cli;
     char date[50], num[10];

     int n = 0,n2=0;
    int refr,chekrfr=0;
    FILE *pcli =fopen ("client.bin","rb");
     if(pcli== NULL)exit(1);
    printf("entrer la referece : ");
    scanf("%d",&refr);
  /* printf("entrer votre Nom  : ");
   gets(Nom);
   printf("entrer la matricule du voiture : ");
   gets(matricule);
   printf("entrer votre CIN : ");
   gets(CIN);*/

   while(fread(&cli,sizeof(clients),1,pcli)!=0){
         printf("gggg");
        if(cli.id_rsr==refr){
                chekrfr=1;
            break;
        }

   }
   fclose(pcli);
   if(chekrfr==0){
    printf("aucun reservatin avec cette reference !!!!!\n\n");
     printf("press any key to return : ");
      scanf("%d",&chekrfr);
       return;
   }


    FILE *p = fopen("dispnible_dates.txt", "r");
    FILE *p1 = fopen("voiture.txt", "r");
    FILE *p2 = fopen("test.txt", "w+");





     while (fgets(date, 50, p) != 0)
    {
        if (strstr(date, cli.mtr) != NULL )
        {
             n2=1;
            break;
        }
    }

    if(n2!=1){
      printf("la voiture n'est pas disponible au momoent");
      exit (1);
    }
int c=0;
     while (fgets(date, 50, p) != 0)
    {
        rewind(p1);
        n = 0;
        while (fgets(num, 10, p1) != 0)
        {
            if (strcmp(date, num) == 0)
            {
                n = 1;
                break;
            }
        }
        if (n == 1)
        {
            break;
        }
        n2=2;
        fputs(date, p2);
        c++;
    }
     rewind(p2);
     FILE *p3 = fopen("text_temp.txt", "w");

    struct tm pdatef = {0}; // Initialize to all zeros
    struct tm pdatet = {0};
    struct tm datef = {0}; // Initialize to all zeros
    struct tm datet = {0};

    datef.tm_year = cli.fa - 1900; // years since 1900
    datef.tm_mon = cli.fm;           // months (0-11, where 0 is January)
    datef.tm_mday = cli.fj;          // day of the month

    datet.tm_year = cli.ta - 1900;
    datet.tm_mon = cli.tm;
    datet.tm_mday = cli.tj;

    int pfy ,pty;
    int chek_date=2;
      n = 0;
    while (fscanf(p2,"%d %d %d  %d %d %d\n",&pdatef.tm_mday, &pdatef.tm_mon,&pfy,&pdatet.tm_mday, &pdatet.tm_mon,& pty)==6)
    {

        pdatef.tm_year = pfy - 1900;
         pdatet.tm_year = pty - 1900;

        if( compareDates(datet,pdatef)< 0  && n==0){
            if(count_days(datet,pdatef)==1){
                   fprintf(p3, "%d %d %d  %d %d %d\n", datef.tm_mday, datef.tm_mon, datef.tm_year+1900,  pdatet.tm_mday, pdatet.tm_mon, pty);
                    n = 1;
                continue;
            }
            else
                fprintf(p3, "%d %d %d  %d %d %d\n", datef.tm_mday, datef.tm_mon, datef.tm_year+1900, datet.tm_mday, datet.tm_mon, datet.tm_year+1900);

            n = 1;
        }

        if(count_days(pdatet,datef)==1){
            datef.tm_mday = pdatef.tm_mday;
            datef.tm_mon = pdatef.tm_mon;
            datef.tm_year = pdatef.tm_year;
            chek_date=0;
            continue;
        }

      chek_date=1;
        fprintf(p3, "%d %d %d  %d %d %d\n", pdatef.tm_mday, pdatef.tm_mon, pfy, pdatet.tm_mday, pdatet.tm_mon, pty);

    }
    if(n==0 && compareDates(datef,pdatet)> 0 ){
        fprintf(p3, "%d %d %d  %d %d %d\n", datef.tm_mday, datef.tm_mon, datef.tm_year+1900, datet.tm_mday, datet.tm_mon, datet.tm_year+1900) ;
        chek_date=1;
    }

     if(n==0 && chek_date==0 )
          fprintf(p3, "%d %d %d  %d %d %d\n", datef.tm_mday, datef.tm_mon, datef.tm_year+1900, datet.tm_mday, datet.tm_mon, datet.tm_year+1900) ;

    fclose(p2);
    fclose(p3);
    remove("test.txt");
    rename("text_temp.txt","test.txt");

     p2 = fopen("test.txt", "r");



    rewind(p);

  if(  anuler == 0){
         printf("##############les date disponible sont:############# \n \n");
        while(fgets(date,50,p2)!=0){
                puts(date);
            }


    char answer[5];
      printf("contunue  yes/no : ");
      scanf("%s",answer);
      if(strcasecmp(answer,"yes")!=0){
         fclose(p2);
         fclose(p);
         return 0;
      }

  }


     FILE *p4=fopen("dispnible_dates_temp.txt", "w");
       rewind(p2);
    while (fgets(date, 50, p) != 0)
    {
        if(strstr(date,cli.mtr)!=NULL){
                fputs(date,p4);
            while(fgets(date,50,p2)!=0){
                fputs(date,p4);

            }
            n=15;
            fgets(date, 50, p);
        }
        if(c!=0 && n==15){
             c--;
            continue;
        }
         fputs(date,p4);
    }
    fclose(p4);
    fclose(p);
    fclose(p1);
    remove("dispnible_dates.txt");
    rename("dispnible_dates_temp.txt","dispnible_dates.txt");
    supprimer_resirvation(cli);

          fclose(p2);

          if(anuler == 1){
              printf("la reservation est anulleé avec succes");
               return 0;
          }
          date_retrival(cli.mtr,cli.prix_par_jour);
          fclose(p2);

    /*rewind(p2);
    printf("##############les date disponible sont:############# \n \n");
        while(fgets(date,50,p2)!=0){
                puts(date);
            }
             fclose(p2);
          date_retrival(cli.mtr,cli.prix_par_jour);
          fclose(p2);*/

}

void supprimer_resirvation(clients cli ){

        FILE *clipf= fopen ("client.bin","rb");
         FILE *clipf_temp= fopen ("client_temp.bin","wb");
         clients clip;
       while(fread(&clip,sizeof(clients),1,clipf)!=0){

                if(clip.id_rsr!=cli.id_rsr){
                    fwrite(&clip,sizeof(clients),1,clipf_temp);
                }
       }
  fclose(clipf);
  fclose(clipf_temp);
  remove("client.bin");
  rename("client_temp.bin","client.bin");


}



 int voire_monreservation(){
   fflush(stdin);
 FILE *p_reservation = fopen("client.bin","rb");
 if(p_reservation == NULL){
    printf("client.bin erreur");
    exit(1);
 }
 clients reservation;
 int refr,chek_exist=0;
 printf("entrer votre reference : ");
 scanf("%d",&refr);

 while(fread(&reservation,sizeof(clients),1,p_reservation)!=0)

        if(reservation.id_rsr ==refr){
            chek_exist =1;
            break;
        }
 fclose(p_reservation);
  fflush(stdin);
  char g[5];
  if(chek_exist ==0){
    system("cls");
    printf("la reservation n'exist pas !!");
    printf("press any key to return ? : ");
    gets(g);
    return 0;
  }
    system("cls");
    printf("Nom : %s\n\n",reservation.Nom_complet);
    printf("Nom du voiture : %s\n\n",reservation.Nom_voiture);
    printf("CIN : %s\n\n",reservation.CIN);
    printf("from : %d/%d/%d \n\n",reservation.fj,reservation.fm,reservation.fa);
     printf("to : %d/%d/%d \n\n",reservation.tj,reservation.tm,reservation.ta);
     printf(" your totale is : %.2f\n\n\n",reservation.total);
     printf("press any key to return ? : ");
    gets(g);
    return 0;







 }



int compareDates(struct tm date1, struct tm date2) {
    if (date1.tm_year < date2.tm_year) return -1;
    if (date1.tm_year > date2.tm_year) return 1;

    if (date1.tm_mon < date2.tm_mon) return -1;
    if (date1.tm_mon > date2.tm_mon) return 1;

    if (date1.tm_mday < date2.tm_mday) return -1;
    if (date1.tm_mday > date2.tm_mday) return 1;

    return 0; // Dates are equal
}

int count_days(struct tm date1, struct tm date2){


// Convert struct tm to time_t (seconds since epoch)
    time_t time1 = mktime(&date1);
    time_t time2 = mktime(&date2);

    // Calculate the difference in seconds
    time_t difference = difftime(time2, time1);
   int daysDifference = difference / (60 * 60 * 24);



     return daysDifference ;


}



int  tranform_and_count(int fday, int fmonth,int fyear,int tday, int tmonth,int tyear){

    struct tm datef = {0}; // Initialize to all zeros
    struct tm datet = {0};

    datef.tm_year =  fyear - 1900; // years since 1900
    datef.tm_mon = fmonth;           // months (0-11, where 0 is January)
    datef.tm_mday = fday;          // day of the month

    datet.tm_year = tyear - 1900;
    datet.tm_mon = tmonth;
    datet.tm_mday = tday;

  return count_days(datef,datet);

}
int id_resirvaion() {
    // Seed the random number generator with the current time
    srand((unsigned int)time(NULL));

    // Generate and print a random number
    int randomNum = rand();

    return randomNum;
}



#endif // CLIENTS_H_INCLUDED
