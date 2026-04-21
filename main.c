#include <stdio.h>
#include <stdlib.h>

struct Competitor
{
   char firstName[10],lastName[10];
   float scores[10],performance;
};

// Calculate performance by removing highest and lowest scores
float calculateScore(struct Competitor c)
{
   int i;
   float total=0;
   float max=0.0;
   float min=6.0;

   for(i=0;i<10;i++)
   {
     if(c.scores[i]>max)
     {
         max=c.scores[i];
     }
     if(c.scores[i]<min)
     {
         min=c.scores[i];
     }
     total+=c.scores[i];
   }
   return(total-max-min)/8;
}

int main()
{
   struct Competitor competitors[100];
   int n,winner;
   int i,j;
   float max=0.0;
   char newline;

   // Get number of competitors
   printf("Enter the number of competitors:\n");
   scanf("%d",&n);
   scanf("%c",&newline);

   for(j=0;j<n;j++)
   {
       // Get competitor info
       printf("Enter the competitor's first name:\n");
       gets(competitors[j].firstName);

       printf("Enter the competitor's last name:\n");
       gets(competitors[j].lastName);

       // Get 10 judge scores
       printf("Enter the judge scores:\n");

       for(i=0;i<10;i++)
       {
           scanf("%f",&competitors[j].scores[i]);
       }
       scanf("%c",&newline);

       // Calculate performance score
       competitors[j].performance=calculateScore(competitors[j]);

       printf("Score=%f",competitors[j].performance);

       // Track winner
       if(competitors[j].performance>max)
       {
           max=competitors[j].performance;
           winner=j;
       }

   }
   // Print winner
   printf("Competition winner:\n");
   printf("Name:%s Last Name:%s Score:%f\n",competitors[winner].firstName,competitors[winner].lastName,max);

   return 0;
}
