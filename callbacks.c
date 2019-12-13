
#  include <config.h>


#include <gtk/gtk.h>
#include <string.h>
#include <stdlib.h>
#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "message.h" 
#define t 100
#define ta 100


void
on_button55_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{

GtkWidget *input1,*input2 ,*input3, *input4, *input5,*input6,*input7,*input8;
    Notif_G N;
    GtkTextIter start,end;
    GtkTextBuffer *buffer=0;
    int var;
		GtkWidget *output;

		output=lookup_widget(objet,"label150");
    input1=lookup_widget(objet,"combobox11");
    input4=lookup_widget(objet,"entry45");
    input2=lookup_widget(objet,"combobox10");
    input3=lookup_widget(objet,"entry46");
    input5=lookup_widget(objet,"textview3");
    input6=lookup_widget(objet,"spinbutton31");
    input7=lookup_widget(objet,"combobox12");
    input8=lookup_widget(objet,"spinbutton32");
    buffer=gtk_text_view_get_buffer(GTK_TEXT_VIEW(input5));
    gtk_text_buffer_get_start_iter (buffer,&start);
    gtk_text_buffer_get_end_iter (buffer,&end);
    strcpy(N.Id_Sms,gtk_entry_get_text(GTK_ENTRY(input3)));
    strcpy(N.Id_Sender,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input2)));
    strcpy(N.Subject,gtk_entry_get_text(GTK_ENTRY(input4)));
    strcpy(N.Id_Receiver,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input1)));
    strcpy(N.d.mois,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input7)));
    N.d.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input6));
    N.d.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input8));
    strcpy (N.Message,gtk_text_buffer_get_text(buffer,&start,&end,FALSE));

    
    var=creer_message(N);
    

}


void
on_button56_clicked                    (GtkWidget      *button,
                                        gpointer         user_data)
{
GtkWidget *list;
  list=lookup_widget(button,"clist1");
  int nbre=0,i=0,j;
  char jourchar[t][t], anneechar[t][t];
   char *p[t][5]={{" "," "," "," "," "}};
   Notif_G SMS[t], N;
  FILE *notif;
  notif=fopen("message.txt","r");
    if(notif!=NULL)
    {
      while((fscanf(notif,"%s %s %s %s %d %s %d ",N.Id_Sms,N.Id_Sender,N.Subject,N.Id_Receiver,&N.d.jour,N.d.mois,&N.d.annee)!=EOF)&&(fgets(N.Message,100,notif)!=NULL))
      {
        if(strcmp(N.Id_Sender,"Client")==0){
        strcpy(SMS[i].Id_Sms,N.Id_Sms);
        strcpy(SMS[i].Subject,N.Subject);
          strcpy(SMS[i].Id_Sender,N.Id_Sender);
        strcpy(SMS[i].Id_Receiver,N.Id_Receiver);
        SMS[i].d.jour=N.d.jour;
        strcpy(SMS[i].d.mois,N.d.mois);
        SMS[i].d.annee=N.d.annee;
        i++;
 
      }
      else if(strcmp(N.Id_Receiver,"Admin")==0){
        strcpy(SMS[i].Id_Sms,N.Id_Sms);
        strcpy(SMS[i].Subject,N.Subject);
        strcpy(SMS[i].Id_Sender,N.Id_Sender);
      strcpy(SMS[i].Id_Receiver,N.Id_Receiver);
        SMS[i].d.jour=N.d.jour;
        strcpy(SMS[i].d.mois,N.d.mois);
        SMS[i].d.annee=N.d.annee;
        i++;
      

      }

      }
      nbre=i;

    }fclose(notif);
    gtk_clist_clear(GTK_CLIST(list));
    for(i=0;i<nbre;i++)
    {
      snprintf(jourchar[i],20,"%d",SMS[i].d.jour);
      snprintf(anneechar[i],20,"%d",SMS[i].d.annee);
    }
    for(i=0;i<nbre;i++)
    {
      strcat(jourchar[i]," ");
      strcat(jourchar[i],SMS[i].d.mois);
      strcat(jourchar[i]," ");
      strcat(jourchar[i],anneechar[i]);
    }
    for(j=0;j<nbre;j++)
    {
      gtk_clist_append(GTK_CLIST(list),p[j]);
    }
    gtk_clist_set_row_height(GTK_CLIST(list),0);
      for(i=0;i<nbre;i++){
        gtk_clist_set_text(GTK_CLIST(list),i,0,SMS[i].Id_Sms);
      }
      for(i=0;i<nbre;i++){
        gtk_clist_set_text(GTK_CLIST(list),i,3,SMS[i].Subject);
      }
      for(i=0;i<nbre;i++){
        gtk_clist_set_text(GTK_CLIST(list),i,1,SMS[i].Id_Sender);
      }
      for(i=0;i<nbre;i++){
        gtk_clist_set_text(GTK_CLIST(list),i,2,SMS[i].Id_Receiver);
      }
      for(i=0;i<nbre;i++){
        gtk_clist_set_text(GTK_CLIST(list),i,4,jourchar[i]);
      }
}


void
on_button58_clicked                    (GtkWidget      *button,
                                        gpointer         user_data)
{
GtkWidget *window1,*window2;

window2=create_window2();
window1=lookup_widget(button,"window1");

gtk_widget_show(window2);
gtk_widget_hide(window1);
}


void
on_button60_clicked                    (GtkWidget       *button,
                                        gpointer         user_data)
{

char id_message[taille];
GtkWidget *input;
Notif_G N;

input=lookup_widget(button,"entry50");
strcpy(id_message,gtk_entry_get_text(GTK_ENTRY(input)));
N=rechercher_message(id_message);
if (strcmp(N.Id_Receiver,"Admin")==0 || strcmp(N.Id_Sender,"Admin")==0)
supprimer_message(id_message);

}



void
on_button59_clicked                    (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *input2,*input3,*input4,*input5,*input6,*input7,*input8,*input9;
   Notif_G N;
  char id_message[taille];
  input6=lookup_widget (button,"entry50");
  strcpy(id_message,gtk_entry_get_text (GTK_ENTRY(input6)));
  N=rechercher_message(id_message);

  GtkTextBuffer *buffer=0;
  GtkTextIter start, end;
  //input1=lookup_widget (button,"dir_sms_id_searched_entry");
  input2=lookup_widget (button,"entry51");
  input3=lookup_widget (button,"entry52");
  input4=lookup_widget (button,"textview4");
  input5=lookup_widget(button,"entry53");
  input7=lookup_widget(button,"spinbutton34");
  input8=lookup_widget(button,"combobox13");
  input9=lookup_widget(button,"spinbutton35");

  buffer=gtk_text_view_get_buffer(GTK_TEXT_VIEW(input4));
  gtk_text_buffer_get_start_iter (buffer,&start);
  gtk_text_buffer_get_end_iter (buffer,&end);
  if(strcmp(N.Id_Sms,"inexistant")!=0){
    if((strcmp(N.Id_Sender,"Admin")==0)||(strcmp(N.Id_Receiver,"Admin"))==0){
  //gtk_entry_set_text (GTK_ENTRY(input1),N.Id_Sms);
  gtk_entry_set_text (GTK_ENTRY(input2),N.Id_Sender);
  gtk_entry_set_text (GTK_ENTRY(input3),N.Id_Receiver);
  gtk_entry_set_text (GTK_ENTRY(input5),N.Subject);
  gtk_spin_button_set_value(GTK_SPIN_BUTTON(input7),N.d.jour);
  gtk_combo_box_set_active(GTK_COMBO_BOX(input8),date_entier(N.d.mois));
  gtk_spin_button_set_value(GTK_SPIN_BUTTON(input9),N.d.annee);
  gtk_text_buffer_delete (buffer,&start,&end);
  gtk_text_buffer_get_end_iter(buffer,&end);
   gtk_text_buffer_set_text(buffer,N.Message,strlen(N.Message));}
   else {
     GtkWidget *output;
     output=lookup_widget(button,"label156");
     gtk_label_set_text (GTK_LABEL(output),"Message Protégé");
   }
 }
else{
  gtk_entry_set_text (GTK_ENTRY(input2),N.Id_Sender);
  gtk_entry_set_text (GTK_ENTRY(input3),N.Id_Receiver);
  gtk_entry_set_text (GTK_ENTRY(input5),N.Subject);
  gtk_spin_button_set_value(GTK_SPIN_BUTTON(input7),N.d.jour);
  gtk_combo_box_set_active(GTK_COMBO_BOX(input8),date_entier(N.d.mois));
  gtk_spin_button_set_value(GTK_SPIN_BUTTON(input9),N.d.annee);
  gtk_text_buffer_delete (buffer,&start,&end);
  gtk_text_buffer_get_end_iter(buffer,&end);
   gtk_text_buffer_set_text(buffer,N.Message,strlen(N.Message));
}
}


void
on_button61_activate                   (GtkWidget       *button,
                                        gpointer         user_data)


{
/*
GtkWidget *input1;
GtkWidget *input2;
GtkWidget *input3;
GtkWidget *input4;
GtkWidget *input5;
GtkWidget *input6;
GtkWidget *input7;
GtkWidget *input8;
GtkTextBuffer *buffer=0;
GtkTextIter start, end;
Notif_G e;
char matricule[30];

input1=lookup_widget(button,"entry51");
input2=lookup_widget(button,"entry52");
input3=lookup_widget(button,"spinbutton34");

input4=lookup_widget(button,"combobox13");
input5=lookup_widget(button,"spinbutton35");
input6=lookup_widget(button,"entry53");
input7=lookup_widget(button,"textview4");
input8=lookup_widget(button,"entry50");
buffer=gtk_text_view_get_buffer(GTK_TEXT_VIEW(input7));




strcpy(e.Id_Receiver,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(e.Id_Sender,gtk_entry_get_text(GTK_ENTRY(input2)));
e.d.jour=gtk_spin_button_get_value(GTK_SPIN_BUTTON(input3));

strcpy(e.d.mois,gtk_combo_box_get_active(GTK_COMBO_BOX(input4)));
  gtk_text_buffer_get_start_iter (buffer,&start);
  gtk_text_buffer_get_end_iter (buffer,&end);


e.d.annee=gtk_spin_button_get_value(GTK_SPIN_BUTTON(input5));
strcpy(e.Subject,gtk_entry_get_text(GTK_ENTRY(input6)));


//strcpy(e.Message,gtk_text_buffer_get_text(buffer,e.Message,strlen(e.Message)));



strcpy(e.Id_Sms,gtk_entry_get_text(GTK_ENTRY(input8)));
strcpy(matricule,gtk_entry_get_text(GTK_ENTRY(input8)));


supprimer_msg(e,matricule);
ajout_message(e);


gtk_entry_set_text(GTK_ENTRY(input8),"");

gtk_entry_set_text(GTK_ENTRY(input1),"");
gtk_entry_set_text(GTK_ENTRY(input2),"");

gtk_spin_button_set_value(GTK_SPIN_BUTTON(input3),1);

gtk_spin_button_set_value(GTK_SPIN_BUTTON(input5),2017);

*/

}



void
on_button61_clicked                    (GtkWidget       *button,
                                        gpointer         user_data)
{
    GtkWidget *input1;
GtkWidget *input2;
GtkWidget *input3;
GtkWidget *input4;
GtkWidget *input5;
GtkWidget *input6;
GtkWidget *input7;
GtkWidget *input8;

char a[20],b[20];

input7=lookup_widget(button,"textview4");
input8=lookup_widget(button,"entry50");
input5=lookup_widget(button,"entry53");

GtkTextIter start, end;
GtkTextBuffer *buffer = gtk_text_view_get_buffer (input7);
gchar *text;

gtk_text_buffer_get_bounds (buffer, &start, &end);
text = gtk_text_buffer_get_text (buffer, &start, &end, FALSE);

strcpy(a,gtk_entry_get_text(GTK_ENTRY(input8)));
strcpy(b,gtk_entry_get_text(GTK_ENTRY(input5)));



modifier_message(a,b,text);

}


void
on_button57_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *ajout;
GtkWidget *affiche;

ajout=lookup_widget(button,"window2");
gtk_widget_destroy(ajout);

affiche=lookup_widget(button,"window1");
affiche=create_window1();
gtk_widget_show(affiche);

}

