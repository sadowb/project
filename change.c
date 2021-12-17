#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<ctype.h>
int main(void)
{   int flag;
    char passcode[30];
    char email[50][50];
    char fname[50][50];
    char lname[50][50];
    char password[50][50];
    char bank_account[50][50];
    int  balance[100];
    char secret_question[50][50];
    char reply[50][50];
    int  total_amount=0;
    int  amount[5]={0},result[5]={0};
    char word[8];
    char answer[]={"yes"},choice[10];
    char menu[5][20]={{"Book"}
        ,{"Skin Care"}
        ,{"Watch"}
        ,{"Desk"}
        ,{"Laptop"}
    };
    int price[5]={200,700,1000,4000,7000};
  int i = 0,count = 0;
  FILE *file;
  file = fopen("database.txt","r");
  while (!feof(file))
    { 
      fscanf(file, "%s %s %s %s %s %d %s %s"  , email[i],fname[i],lname[i],password[i],bank_account[i],
      &balance[i],secret_question[i],reply[i]);
    
    
      i++;
      count++;
    }
    fclose(file);
printf("Welcome, if you want to make an order, type 'order'; if you want to change your information,type 'change': ");
    scanf("%s",word);
    strlwr(word);
    
        if(strcmp(word,"order") == 0){
            printf("Here is the menu:\n");
            for(int i=0;i<5;i++){
                printf("%s for %d MAD\t",menu[i],price[i]);
            }
            while(strcmp(answer,"yes")==0){

                printf("\nType what you want to buy based on the menu: ");
                getchar();
                gets(choice);
                strlwr(choice);
                if(strcmp(choice,"book")==0 || strcmp(choice,"book ")==0 )
                {
                printf("\nType what you want to buy based on the menu: \n");
                scanf("%s",choice);
                int i=0;
                while(choice[i]!='\0')
                {
                choice[i]=tolower( choice[i]);
                i++;
                }
                if(strcmp(choice,"book")==0){

                    printf("How many books do you want? ");
                    scanf("%d",&amount[0]);
                    result[0]=amount[0]*200;
                }
                else if(strcmp(choice,"skin care")==0 || strcmp(choice,"skin care ")==0){
                    printf("How many skin care do you want? ");
                    scanf("%d",&amount[1]);
                    result[1]=amount[1]*700;
                }
                else if(strcmp(choice,"watch")==0 || strcmp(choice,"watch ")==0){
                    printf("How many watches do you want? ");
                    scanf("%d",&amount[2]);
                    result[2]=amount[2]*1000;
                }
                else if(strcmp(choice,"desk")==0 || strcmp(choice,"desk ")==0){
                    printf("How many desks do you want? ");
                    scanf("%d",&amount[3]);
                    result[3]=amount[3]*4000;
                }
                else if(strcmp(choice,"laptop")==0 || strcmp(choice,"laptop")==0){
                    printf("How many laptops do you want? ");
                    scanf("%d",&amount[4]);
                    result[4]=amount[4]*6000;
                }
                for(int i=0;i<5;i++){
                total_amount+=result[i];
            }
                printf("\nDo you want to order anything else(type yes), or do you want to proceed to the payment?(type no)\n");
                scanf("%s",answer);
            }
            printf("\nThese items have been added to your cart.");
            printf("\nThe total amount to pay is %d MAD",total_amount);
            }
        }
  else if(strcmp(word,"change")==0){

    for(int j=0;j<count;j++){
    printf("enter your password: ");
    scanf("%s",passcode);
    int value,id;
    //printf("%s",password[1]);
    for(int i = 0; i<50 ; i++)
    {
        if( strcmp(passcode,password[i])==0)
        {
          flag = 1;
          id = i;
          break;
        }
    else flag = 0;
    
    }
    if(flag == 1)
    printf("it is found at %d here is the password %s here is the email %s  ",id,password[id],email[id]);
    else printf("it isnt found");
    //if(value==0){
   /* for (int i = 0 ;i<3 ; i++)
    {
      printf("here is the email %s\n here is the first name %s\n here is the last name %s\n here is the password %s\n here is the bank account %s\n here is the balance %d\n here is the secret question %s\n here is the answer %s \n"
      ,email[i],fname[i],lname[i],password[i],bank_account[i],&balance[i],secret_question[i],reply[i]);
      printf("\n");
    }
    }
    }
  }
    //balance[0] = balance[0] + 1;
    
  printf("email is %s",email[0]);
    /*email[i] = '\0';

    for (i = 0; email[i] != '\0'; i++)
      printf("%d\n", email[i]);
  }

*/
  
    
}
    }
  return 0;
}