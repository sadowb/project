/*
this program is a login and signup system 
*/
#include<stdio.h>
#include<string.h>
#include<ctype.h> 
      // this is for using strlwr
char *strlwr(char *str)
{
  unsigned char *p = (unsigned char *)str;
                                            // this is to define stlwr for clang compilers 
while (*p) {
        *p = tolower((unsigned char)*p);
        p++;
}

return str;
}
void sign_up(int );
void sign_in(int );
void login();
void zak(int id,int counter);
    char new_lname[100],new_fname[100], new_password[50], new_email[100], new_bankaccount[30],question[100],new_reply[100];
    int  new_balance[100];
    char address[30];
    char passcode[30]; // this is the the arrays that we are using to compare with 
    char email[50][50];
    char fname[50][50];
    char lname[50][50];
    char password[50][50];
    char bank_account[50][50];
    int  balance[100]={0};
    char secret_question[50][50];
    char reply[50][50];
    char sign[7];
int main(){
    
    int count = 0;
    int i  = 0;
    int id,found=0; // found is a sentinal value
    // id is to keep track of the persons that we have 
    FILE *file;
    file = fopen("database.txt","r");
    while (!feof(file)){ 
    fscanf(file, "%s %s %s %s %s %d %s %s" , email[i],fname[i],lname[i],password[i],bank_account[i],
    &balance[i],secret_question[i],reply[i]);
    i++;
    count++;
    }
    fclose(file);
    printf("Do you want to sign in or sign up? ");
    scanf("%[^\n]",sign);
if (strcmp(sign,"sign in")==0)
{
    sign_in(count);
}
else if(strcmp(sign,"sign up")==0){
    sign_up(count);
}

}
void zak(int id,int counter)
{
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
printf("Welcome, if you want to make an order, type 'order'; if you want to change your information,type 'change': ");
    scanf("%s",word);
        if(strcmp(word,"order") == 0){
            printf("Here is the menu:\n");
            for(int i=0;i<5;i++){
                printf("%s for %d MAD\t",menu[i],price[i]);
            }
            while(strcmp(answer,"yes")==0){
                printf("\nType what you want to buy based on the menu: ");
                scanf("%s",choice);
                for(int i=0;i<7;i++){
                tolower(choice[i]);
                }
                if(strcmp(choice,"book")==0){
                    printf("How many books do you want? ");
                    scanf("%d",&amount[0]);
                    result[0]=amount[0]*200;
                }
                else if(strcmp(choice,"skincare")==0){
                    printf("How many skin care do you want? ");
                    scanf("%d",&amount[1]);
                    result[1]=amount[1]*700;
                }
                else if(strcmp(choice,"watch")==0){
                    printf("How many watches do you want? ");
                    scanf("%d",&amount[2]);
                    result[2]=amount[2]*1000;
                }
                else if(strcmp(choice,"desk")==0){
                    printf("How many desks do you want? ");
                    scanf("%d",&amount[3]);
                    result[3]=amount[3]*4000;
                }
                else if(strcmp(choice,"laptop")==0){
                    printf("How many laptops do you want? ");
                    scanf("%d",&amount[4]);
                    result[4]=amount[4]*6000;
                }
                for(int i=0;i<5;i++){
            total_amount+=result[i];
            }
                printf("\nDo you want to order anything else(type yes), or do you want to proceed to the payment?(type no)");
                scanf("%s",answer);
            }
            printf("\nThese items have been added to your cart.");
            printf("\nThe total amount to pay is %d MAD",total_amount);
        if(balance[id]>total_amount){
                balance[id]-=total_amount;
                printf("\nCongrats %s you have purchased this item you still have %d MAD",fname[id],balance[id]);
                FILE *file;
                file = fopen("database.txt","w");
                
                int i;
                
                for(i=0;i<counter;i++){ 
                fprintf(file, "%s %s %s %s %s %d %s %s\n" , email[i],fname[i],lname[i],password[i],bank_account[i],
                balance[i],secret_question[i],reply[i]);
                }
                fclose(file);
                }
                
            else if(balance[id]<total_amount){
                printf("\nYou do not have enough balance consider change your bank info");
                scanf("%s",&bank_account[id]);
            }
        
else if(strcmp(word,"change")==0){
    printf("%s %s %s %s %s %d %s %s" , email[id],fname[id],lname[id],password[id],bank_account[id],
    &balance[id],secret_question[id],reply[id]);
}
}
}

void sign_up(int count){
	int B = 0;	
    printf("Enter Your First Name\t");
    scanf("%s", new_fname);
    printf("Enter Your last Name\t");
    scanf("%s", new_lname);
    printf("Enter Your Password\t");
    scanf("%s", new_password);
    printf("Enter Your Email\t");
    scanf("%s", new_email);
    printf("Enter Bank Account Number \t");
    scanf("%s", new_bankaccount);
    printf("What is your balance ? \t");
    scanf("%d",&new_balance[B]);
    printf("Enter the serecet question \t");
    scanf("%s",question);
    printf("Enter an answer: \t");
    scanf("%s",new_reply);
    for(int i=0;i<count;i++){
        if (strcmp(new_email,email[i])==0 || strcmp(new_bankaccount,bank_account[i])==0)//checks with the arrays if the arrays
        {
        printf("\nYou already have an existant account, Please login");
        break;
    }
    else if(strcmp(new_email,email[i])!=0 || strcmp(new_bankaccount,bank_account[i])!=0)
    {   int B = 0;
        FILE *fptr=fopen("database.txt","a");
        fprintf(fptr,"\n%s %s %s %s %s %d %s %s",new_email,new_fname,new_lname,new_password,new_bankaccount,new_balance[B],question,new_reply);
        fclose(fptr);
        printf("Succesfully signed up");
        printf("\nLog in again");
        break;
        }
    }
}

void sign_in(int count)
{
    int id,found=0;
printf("\nEnter your email: ");
    scanf("%s",address);
    for(int i = 0 ; i < count ; i++)
    {
    	        if(strcmp(email[i],address)== 0)
    			{
						found = 1;
                        id = i;
						break;
						
    			}
    }
    if(found == 0)
    		{
            printf("User does not exist!");
    		}
    else if (found == 1)
    {
						printf("Enter a password: ");
				scanf("%s",passcode);
				if(strcmp(password[id],passcode)==0)
    		{
						printf("Succesfully logged in! ");
						zak(id,count);
    		}
    	
    }
   
}
