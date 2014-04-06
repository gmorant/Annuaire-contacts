#include <stdio.h>
#include <stdlib.h>
#include <string.h>



 struct Contact
 {
     char nom[100];
     char prenom[100];
     char tel[14];
     char mail[100];
 };

 struct Contact utilisateur[10];


void  rechercher(char cherche[10],int i);
void  modifier (int i);
void  ajouter_contact (int i);
void  supprimer (int i);
void  afficher_contact(int i);
void  sauv_quitter();


int main()
{
    int i=0;
    FILE* fichier = NULL;
    fichier = fopen("contact.txt","r");
    for (i=0;i<=10;i++)
        {
            fscanf(fichier,"%s %s %s %s", &utilisateur[i].nom, &utilisateur[i].prenom, &utilisateur[i].tel, &utilisateur[i].mail );
        }





    char cherche[10];
    char x;
    int op;
    do
        {
            printf("gestion de contacts\n\n1 ajouter contact\n2 rechercher un contact\n3 modifier un contact\n4 supprimer un contact\n5 afficher les contacts\n6 sauvegarder et quitter\n\n");
            printf("entrer le numero de l action que vous souhaitez effectuer :");
            scanf("%d",&op);

             switch (op)
                {
                    case 1 : ajouter_contact(i);break;
                    case 2 : printf("entrer le nom ou le prenom du contact que vous souhaitez rechercher :");
                             scanf("%s",cherche);
                             rechercher(cherche,i);break;
                    case 3 : modifier (i);break;
                    case 4 :supprimer(i);break;
                    case 5 :afficher_contact(i);break;
                    case 6 :sauv_quitter();return 0;
                    default : printf("entrer un nombre entre 1 et 6 svp\n");break;

                }





            printf("voulez vous retourner au menu(o/n) ?");
            fflush (stdin);
            scanf("%c",&x);
        }while (x!='n');

}





void ajouter_contact (int i)
{

     int nombre_contact=1,j=0,sauv;
     char x;
     i=0;
     while (utilisateur[i].nom!="")
            {
                i++;printf("ff");
                nombre_contact++;
            }

     do
      {


        printf("quel est le nom du contact ?");
        scanf("%s",utilisateur[i].nom);
        printf("quel est le prenom du contact ?");
        scanf("%s",utilisateur[i].prenom);
        printf("quel est le mail du contact ?");
        scanf("%s",utilisateur[i].mail);
        printf("quel est le tel du contact ?");
        scanf("%s",utilisateur[i].tel);
        utilisateur[sauv]=utilisateur[i];
        while (strcmp(utilisateur[i].nom,utilisateur[j].nom)>0)
            {
                j++;
            }
        while(nombre_contact!=j)
                    {
                        utilisateur[nombre_contact+1]=utilisateur[nombre_contact];
                        nombre_contact--;
                    }

        utilisateur[j]=utilisateur[sauv];







        printf("voulez vous refaire le traitement (o/n) ?");
        fflush (stdin);
        scanf("%c",&x);
      }while (x!='n');

}








 void  rechercher(char cherche[10],int i)
{

    i=0;
    while (strcmp(cherche,utilisateur[i].nom)!=0&&strcmp(cherche,utilisateur[i].prenom)!=0&&i!=10)
        {
            i++;
        }
    if (i==10) printf("le contact que vous rechercher n existe pas\n");
    else  printf("num contact :%d\nNom :%s\nPrenom :%s\nmail :%s\ntel :%s\n\n",i,utilisateur[i].nom,utilisateur[i].prenom,utilisateur[i].mail,utilisateur[i].tel);


}






void modifier (int i)
{

    char cherche[10];
    char x;
    int op;
    i=0;
    printf("entrer le nom ou le prenom du contact que vous souhaitez modifier :");
    scanf("%s",cherche);
    rechercher(cherche,i);
    printf("tapez le num de contact :");
    scanf("%d",&i);

     do
      {


            printf("1changer le nom\n2changer le prenom\n3changer le mail\n4changer le numero de tel :");
            scanf("%d",&op);
            switch (op)
            {
                case 1 :printf("entrer le nouveau nom :");
                        scanf("%s",utilisateur[i].nom);break;
                case 2 :printf("entrer le nouveau prenom :");
                        scanf("%s",utilisateur[i].prenom);break;
                case 3 :printf("entrer le nouveau mail :");
                        scanf("%s",utilisateur[i].mail);break;
                case 4 :printf("entrer le nouveau tel :");
                        scanf("%s",utilisateur[i].tel);break;


            }
            printf("voulez vous refaire le traitement o/n ?");
            fflush (stdin);
            scanf("%c",&x);
       }while (x!='n');

}



void supprimer (int i)
 {
    char cherche[10];
    char x;
    int op,y;
    i=0;
    printf("entrer le nom ou le prenom du contact que vous souhaitez supprimer :");
    scanf("%s",cherche);
    rechercher(cherche,i);
    printf("tapez le num de contact :");
    scanf("%d",&i);
    for (y=i;y<9;y++)
        {
            utilisateur[i]=utilisateur[i+1];
        }

    printf("ce contact a bien ete supprimer\n\n");
 }



void afficher_contact(int i)
{

    for(i=0;i<9;i++)
    {
       printf("Nom :%s\nPrenom :%s\nmail :%s\ntel :%s\n\n",utilisateur[i].nom,utilisateur[i].prenom,utilisateur[i].mail,utilisateur[i].tel);
       printf("\n");
    }
}



void sauv_quitter()
{
     int i;
     FILE *fichier;
     fichier = fopen("contact.txt", "w");
     for(i=0;i<9;i++)
        {

            fprintf(fichier,"%s %s %s %s\n", &utilisateur[i].nom, &utilisateur[i].prenom, &utilisateur[i].tel, &utilisateur[i].mail );
        }
     fclose(fichier);



}

