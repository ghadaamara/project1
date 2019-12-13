#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "message.h"
#define taille 256


int creer_message(Notif_G N)
{

  FILE *notif=fopen("message.txt","a+");
  Notif_G No;
      if(notif!=NULL){


while((fscanf(notif,"%s %s %s %s %d %s %d ",No.Id_Sms,No.Id_Sender,No.Subject,No.Id_Receiver,&No.d.jour,No.d.mois,&No.d.annee)!=EOF)&&(fgets(No.Message,100,notif)!=NULL))
{
  if((strcmp(No.Id_Sms,N.Id_Sms)==0))
  return 0;
}

        fprintf(notif,"%s %s %s %s %d %s %d %s\n",N.Id_Sms,N.Id_Sender,N.Subject,N.Id_Receiver,N.d.jour,N.d.mois,N.d.annee,N.Message);
}
    fclose(notif);
  return 1;
}



void supprimer_message(char id_message[taille])
{
    Notif_G N;
      FILE *notif=fopen("message.txt","r");
      FILE *nouv_notif=fopen("message_temp","w");
      if(notif==NULL)
      printf("Impossible de lire le fichier");

while((fscanf(notif,"%s %s %s %s %d %s %d ",N.Id_Sms,N.Id_Sender,N.Subject,N.Id_Receiver,&N.d.jour,N.d.mois,&N.d.annee)!=EOF)&&(fgets(N.Message,100,notif)!=NULL))
  {
    if(strcmp(N.Id_Sms,id_message)!=0)
    {
    //  if(nouv_notif!=NULL)
  fprintf(nouv_notif,"%s %s %s %s %d %s %d %s",N.Id_Sms,N.Id_Sender,N.Subject,N.Id_Receiver,N.d.jour,N.d.mois,N.d.annee,N.Message);
}
}
      fclose(nouv_notif);
      fclose(notif);
        remove("message.txt");
        rename("message_temp","message.txt");
}
void modifier_message(char id_message[],char obj[],char text[])
{
    Notif_G N;
      FILE *notif=fopen("message.txt","r");
      FILE *nouv_notif=fopen("message_temp","w");
      if(notif==NULL)
      printf("Impossible de lire le fichier");

while((fscanf(notif,"%s %s %s %s %d %s %d ",N.Id_Sms,N.Id_Sender,N.Subject,N.Id_Receiver,&N.d.jour,N.d.mois,&N.d.annee)!=EOF)&&(fgets(N.Message,100,notif)!=NULL))
  {
    if(strcmp(N.Id_Sms,id_message)!=0)
    {
    //  if(nouv_notif!=NULL)
  fprintf(nouv_notif,"%s %s %s %s %d %s %d %s",N.Id_Sms,N.Id_Sender,N.Subject,N.Id_Receiver,N.d.jour,N.d.mois,N.d.annee,N.Message);
}
else{
    fprintf(nouv_notif,"%s %s %s %s %d %s %d %s",N.Id_Sms,N.Id_Sender,obj,N.Id_Receiver,N.d.jour,N.d.mois,N.d.annee,text);
    
}
      
}
      fclose(nouv_notif);
      fclose(notif);
        remove("message.txt");
        rename("message_temp","message.txt");
}
Notif_G rechercher_message(char id_message[taille])
{
  FILE*notif;
  Notif_G N;
  notif=fopen("message.txt","r"); // searching by JUST First and Last name
  while((fscanf(notif,"%s %s %s %s %d %s %d ",N.Id_Sms,N.Id_Sender,N.Subject,N.Id_Receiver,&N.d.jour,N.d.mois,&N.d.annee)!=EOF)&&(fgets(N.Message,100,notif)!=NULL))
    {
      if((strcmp(N.Id_Sms,id_message)==0)){
     return N;
   }
 }

  fclose (notif);
  strcpy(N.Id_Sms,"inexistant");
  strcpy(N.Id_Sender,"inexistant");
  strcpy(N.Subject,"inexistant");
  strcpy(N.Id_Receiver,"inexistant");
  strcpy(N.Message,"inexistant");
  N.d.jour=1;
  strcpy(N.d.mois,"Janvier");
  N.d.annee=2017;
  return N;
}


int exp_dir_int (char ch[100])
{
  int i;
char *tab[8]={"Sélectionner","Médecin", "Sécretraire", "Sécretaire_médical","Aide_soignant", "Résident", "Famille", "Technicien"};
for(i=0;i<9;i++)
{
  if(strcmp((tab[i]) ,ch)==0)
  {
    return i;
  }

}

}
int date_entier(char ch[100])
{
  int i;
char *tab[12]={"Janvier","Février","Mars","Avril","Mai","Juin",
"Juillet","Août","Septembre","Octobre","Novembre","Décembre"};
for(i=0;i<12;i++)
{
  if(strcmp((tab[i]) ,ch)==0)
  {return i;
}
}
}

void ajout_message(Notif_G N)
{
FILE*f;


f=fopen("message.txt","a+");
if(f!=NULL){
fprintf(f,"%s %s %s %s %d %s %d %s\n",N.Id_Sms,N.Id_Sender,N.Subject,N.Id_Receiver,N.d.jour,N.d.mois,N.d.annee,N.Message);
} 
fclose(f);

}

void supprimer_msg(Notif_G N,char matricule[20])
{
FILE*f;
FILE*t;


f=fopen("message.txt","r+");
t=fopen("tmp.txt","w+");
if(f!=NULL){
while(fscanf(f,"%s %s %s %s %d %s %d %s\n",N.Id_Sms,N.Id_Sender,N.Subject,N.Id_Receiver,N.d.jour,N.d.mois,N.d.annee,N.Message)!=EOF){
if(strcmp(matricule,N.Id_Sms)!=0){
fprintf(f,"%s %s %s %s %d %s %d %s\n",N.Id_Sms,N.Id_Sender,N.Subject,N.Id_Receiver,N.d.jour,N.d.mois,N.d.annee,N.Message);
}
}
}fclose(t);
fclose(f);
remove("message.txt");
rename("tmp.txt","message.txt");
}


