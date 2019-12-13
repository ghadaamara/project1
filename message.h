#ifndef MESSAGE_H
#define MESSAGE_H
#define taille 256
#define taille_date 20
typedef struct dater
{
  int jour;
  char mois[taille_date];
  int annee;
}Date_notif;

typedef struct Notifications_Generales
{
  char Id_Sms[taille];
  char Id_Receiver[taille];
  char Id_Sender[taille];
  char Subject[taille];
  char Message[taille];
   Date_notif d;
}Notif_G;
int creer_message(Notif_G N);
void afficher_notification();
Notif_G rechercher_message (char id_message[taille]);
void supprimer_message(char id_message[taille]);
int exp_dir_int (char ch[100]);
int date_entier(char ch[100]);
void ajout_message(Notif_G N);
void supprimer_msg(Notif_G N,char matricule[20]);
void modifier_message(char id_message[],char obj[],char text[]);

#endif /*NOTIFICATIONS_H*/
