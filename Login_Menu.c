#include <stdio.h> 
#include <string.h> 

 
int main() 
{ 
    char usrname[10]; 
    char passwrd[10];

    printf("Enter your username:\n"); 
    scanf("%s",&usrname); 
 
    printf("Enter your password:\n"); 
    scanf("%s",&passwrd); 
 
    if(strcmp(usrname,"********")==0){ 
        if(strcmp(passwrd,"********")==0){ 
        printf("\nYou have been loged in!"); 
    }else{ 
    printf("\n Wrong Password"); 
    } 
    }else{
    printf("\n User doesn't exist"); 
} 
    if (strncmp())







   return 0; 
 
}