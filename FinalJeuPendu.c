#include <stdio.h> 
#include <string.h> 
#include <stdlib.h>
#include <time.h> 

#define e 10
#define randomizer srand(time(NULL))

int introduction(char * reponse);
void Pendaison(int);

int main() {
   RecommencerPartie: {
      printf("\n");
   }
   char reponse[100], //fait réference au mot caché.
   manques[100]; //recencer les mauvaises lettres
   int x = 0,
   limit = 1,
   chances = 6, //Nombre de chances
   length; //taille du mot caché
   char char_seen[length];
   int i,
   gameover = 0; //gameover initialisé à 0 pour arrêter la Partie
   int Partie = 1, // initialiser la Partie à 1 afin de démarrer.
   r = 0;

   while (Partie == 1) {
      chances = 6;
      introduction(reponse);
      length = strlen(reponse); // Taille de la réponse en locurence du mot caché
      for (i = 0; i < length; i++) //Initialize all mask value to 0.
      {
         char_seen[i] = 0;
      }
    printf("\t\t\t\t\tBienvenu dans le jeu du pendu.\n"); 
   printf("\nRègles du jeu:\n");
   printf("-> Vous devez trouver le mot caché;\n->"
      " A chaque erreur le bonhomme se rapproche de la pendaison; \n-> "
      "Vous avez droit à 6 erreurs;\n->"
      " Une fois que l'homme est pendu, vous avez perdu!\n");
        printf("\n\n");
        printf("\tJ E U  D U  P E N D U");
        printf("\n\t+------+");
        printf("\n\t|      | ");
        printf("\n\t|        ");
        printf("\n\t|        ");
        printf("\n\t|        ");
        printf("\n\t|       ");
        printf("\n\t========\n\n");

      printf("Fausses lettres:");
      while (!gameover) {
         printf("\nMot caché : ");
         int j;
         for (j = 0; j < length; ++j) {
            if (char_seen[j]) {
               printf("%c", reponse[j]); //on insère la lettre dans la chaine
            } else {
               printf("_ "); 
            }
         }
         printf("\n");

         char lettre;
         printf("Entrer une lettre:\n");
         scanf(" %c", & lettre);

         int l, match = 0;
         for (l = 0; l < length; ++l)
            if (lettre == reponse[l]) 
         {
            match = 1;                                   //juste pour vérifier que la lettre entrée match avec une lettre de la réponse
            break;
         }

         if (match == 0) {
            printf("\nFausses lettres: ");
            manques[x] = lettre;
            for (r = 0; r < limit; r++)            //le cas contraire pour montrer que la lettre entrée ne match pas avec une lettre de la réponse
               printf(" %c", manques[r]);
            x++;
            limit++;
            --chances;
            Pendaison(chances);
            printf("\nFausses lettres: ");
            for (r = 0; r < limit; r++)
               printf(" %c", manques[r]);
         }

         if (match == 1) {
            int k;
            for (k = 0; k < length; k++) {
               if (reponse[k] == lettre) {
                  if (char_seen[k]) //si vrai
                  {
                     manques[x] = lettre;
                     for (r = 0; r < limit; r++)
                        printf(" %c", manques[r]);
                     x++;
                     limit++;
                     --chances;
                     Pendaison(chances);
                     printf("\nFausses lettres: ");
                     for (r = 0; r < limit; r++)
                        printf(" %c", manques[r]);
                  }
                  char_seen[k] = 1;
               }
            }
         }

         int sea = 0;
         gameover = 1;
         for (sea = 0; sea < length; sea++) {
            if (!char_seen[sea]) {
               gameover = 0;
               break;
            }
         }

         if (chances == 0) {
            gameover = 0;
            break;
         }

      } 

      //Résultat du jeu
      if (chances == 0) {
         printf("\n\nVous avez perdu! Le mot caché est \"%s\"!\n", reponse);
      }

      if (chances > 0) {
         printf("\n\nBravo! Le mot caché est \"%s\"! Vous avez gagné!\n", reponse);
      }
      int booleen = 1; 
      while (booleen == 1) {
         printf("Voulez vous jouer encore? (oui ou non)\n");
         char say[3];
         scanf("%s", say);
         if (strcmp(say, "oui") == 0) {
            Partie = 0;
            booleen = 0;
            goto RecommencerPartie;
         } 
         else if (strcmp(say, "non") == 0) {
            Partie = 0;
            booleen = 0;
         }
         else booleen = 1;
      } 

   } 
   return 0;
} 

int introduction(char * reponse) {

   int MainMenu = 777;
   while (MainMenu == 777) {
      randomizer;
      char mots[e][8] = {
         "chat","chien","moi","lunette","voiture","python","danse","codeur","socrate","mode"
      };
      int f;
      f = rand() % 10;
      printf("\nMot généré");
      strcpy(reponse, mots[f]);
      return *reponse;
   }
}

void Pendaison(int choice) {
   switch (choice) {
   case 0:
      printf("\n\t||===== ");
      printf("\n\t||    | ");
      printf("\n\t||   %cO/", '\\');
      printf("\n\t||    |                                              VOUS AVEZ PERDU!");
      printf("\n\t||   / %c", '\\');
      printf("\n\t||      ");
      break;
   case 1:
      printf("\n\t||===== ");
      printf("\n\t||    | ");
      printf("\n\t||   %cO/", '\\');
      printf("\n\t||    | ");
      printf("\n\t||     %c", '\\');
      printf("\n\t||      ");
      break;
   case 2:
      printf("\n\t||===== ");
      printf("\n\t||    | ");
      printf("\n\t||   %cO/", '\\');
      printf("\n\t||    | ");
      printf("\n\t||      ");
      printf("\n\t||      ");
      break;
   case 3:
      printf("\n\t||===== ");
      printf("\n\t||    | ");
      printf("\n\t||   %cO/", '\\');
      printf("\n\t||      ");
      printf("\n\t||      ");
      printf("\n\t||      ");
      break;
   case 4:
      printf("\n\t||===== ");
      printf("\n\t||    | ");
      printf("\n\t||   %cO ", '\\');
      printf("\n\t||      ");
      printf("\n\t||      ");
      printf("\n\t||      ");
      break;
   case 5:
      printf("\n\t||===== ");
      printf("\n\t||    | ");
      printf("\n\t||    O ");
      printf("\n\t||      ");
      printf("\n\t||      ");
      printf("\n\t||      ");
      break;
   }
   return;
} 
