#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(void)
{
    char email[50][50];
    char fname[50][50];
    char lname[50][50];
    char  password[50][50];
    char  bank_account[50][50];
    int  balance[100];
    char secret_question[50][50];
    char answer[50][50];
    
    
  int i = 0;
  FILE *file;
  file = fopen("database.txt","r");

  
    while (!feof(file))
    { 
      fscanf(file, "%s %s %s %s %s %d %s %s"  , email[i],fname[i],lname[i],password[i],bank_account[i],
      &balance[i],secret_question[i],answer[i]);
    
    
      i++;
    }
    fclose(file);
   
    
    for (int i = 0 ;i<3 ; i++)
    {
      printf("here is the email %s\n here is the first name %s\n here is the last name %s\n here is the password %s\n here is the bank account %s\n here is the balance %d\n here is the secret question %s\n here is the answer %s \n"
      ,email[i],fname[i],lname[i],password[i],bank_account[i],balance[i],secret_question[i],answer[i]);
      printf("\n");


    }
    //balance[0] = balance[0] + 1;
    
   printf("email is %s",email[0]);
    /*email[i] = '\0';

    for (i = 0; email[i] != '\0'; i++)
      printf("%d\n", email[i]);
  }
*/
  return 0;
}