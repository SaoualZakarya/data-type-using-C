//                                       ########exercice 1##############
// #include <stdio.h>
// #include <math.h>
// #include <stdlib.h>
// #include <string.h>

// struct ville {
//     char name[30];
//     float number;
// };

// int main() {
//     int p, n, i, j;
//     struct ville t[100];

//    printf("Enter the number of villages: \n");
//    scanf("%d", &n);

//    for (i = 0; i < n; i++) {
//       printf("Enter the name of village %d: \n", i + 1);
//       scanf("%s", t[i].name);
//       printf("Enter the number of inhabitants for village %d: \n", i + 1);
//       scanf("%f", &t[i].number);
//    }

//    for (i = 0; i < n; i++) {
//       for (j = i; j < n - 1; j++) {
//          if (t[i].number > t[j + 1].number) {
//             p = t[i].number;
//             t[i].number = t[j + 1].number;
//             t[j + 1].number = p;
//          }
//       }
//    }

//    for (i = 0; i < n; i++) {
//       printf("%d - The name of the village is: %s , The number of habitants for the village is: %.0f \n ", i + 1, t[i].name,t[i].number);
//    }

//    return 0;
// }



//                                     ########## exercice 02 #########
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

struct student {
   char name[30];
   float score;
};

int main() {
   int n, i, j;
   float temp;
   struct student t[100];

   printf("Enter the number of students: \n");
   scanf("%d", &n);

   for (i = 0; i < n; i++) {
      printf("Enter the name of student %d: \n", i + 1);
      scanf("%s", t[i].name);
      printf("Enter the score of student %d: \n", i + 1);
      scanf("%f", &t[i].score);
   }

   for (i = 0; i < n; i++) {
      if (t[i].score < 10) {
            t[i].score = t[i].score + 1;
         } else if ((t[i].score >= 10) && (t[i].score < 15)) {
            t[i].score = t[i].score + 0.5;
      }
   }

   for (i = 0; i < n; i++) {
      for (j = i; j < n; j++) {
         if (t[i].score < t[j].score) {
            temp = t[i].score;
            t[i].score = t[j].score;
            t[j].score = temp;
         }
      }
   }

   printf("The scores in ascending order are: \n");
   for (i = 0; i < n; i++) {
      printf("The new score of %s is: %.2f,\n", t[i].name, t[i].score);
   }

   return 0;
}
