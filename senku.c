#include<stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

long deposit,withdraw;
long pamount=0,amount=0;
char amt[10],amt2[10];
int choice;
int k,l;
char cid[9],cpin[5];   //for userid and pin in the program
char transaction;
int digits;
FILE *id,*pass,*balance,*bal2;
int check();

void main()
{
      printf("**********WELCOME TO ATM SERVICES***********\n");
      int z=check();
      if (z==0){
        printf("Invalid ID/PIN \n");
         printf("Close the program and run it again");
      }
    while(1)
    {


            if (z==1)
                {
            printf("**********ATM SERVICES***********\n");
            printf("1.Check balance\n");
            printf("2.Withdraw cash\n");
            printf("3. Deposit Cash\n");
            printf("4. Quit\n");
            printf("Enter your choice");
            scanf("%d",&choice);

            switch(choice)
            {
                case 1:
                printf("\n Your balance in Rs:%li",amount);
                break;
                case 2:
                printf("\n Enter the amount to withdraw:");
                scanf("%li",&withdraw);
                if(withdraw%500!=0)
                {
                    printf("\n Please enter the amount in multiple of 500");
                }
                else if (withdraw>amount)
                {
                    printf("\n INSUFFICIENT BALANCE");
                }
                else
                {
                amount=amount-withdraw;
                printf("\n\n PLEASE COLLECT YOUR CASH");
                printf("\n Your current balance is:%li",amount);
                }
                break;
                case 3:
                printf("\n Enter the amount to deposit:");
                scanf("%li",&deposit);
                amount=amount + deposit;
                printf("Your current balance is:%li",amount);
                break;
                case 4:
                printf("\n THANKYOU FOR USING OUR ATM SERVICE");
                break;
                default:
                printf("\n INVALID CHOICE");
                }
                printf("\n\n\n DO YOU WISH TO PERFORM ANOTHER ACTION?(Y/N):\n");
                fflush(stdin);// To remove garbage value
                scanf("%c",&transaction);
                if (transaction =='n' || transaction== 'N')
                    break;
            }
     }

   printf("\n\n THANKS FOR USING OUR ATM SERVICE");


digits=log10(amount)+1;
fclose(balance);
balance=fopen("balance.txt","r");
bal2=fopen("balance2.txt","w");
int c=0;
while(fgets(amt,10,balance)!=NULL){
        c++;
    if(c==k){

         for(int j=9;j>digits;j--){

  fprintf(bal2,"0");


}
fprintf(bal2,"%li",amount);

    }
else{
    fputs(amt,bal2);
}
}
fclose(bal2);
bal2=fopen("balance2.txt","r");
balance=fopen("balance.txt","w");
while(fgets(amt2,10,bal2)!=NULL){
  fprintf(balance,amt2);

}
fclose(bal2);
fclose(balance);
fclose(pass);
fclose(id);





   }


int check(){


id=fopen("userid.txt","r");
pass=fopen("password.txt","r");
balance=fopen("balance.txt","rw");
int c=0,p=0;
char fid[9],fpin[5];            //stores the userid and pin from files
long fbalance;
printf("Enter your bank id");
scanf("%s",&cid);
printf("Enter your pin");
scanf("%s",&cpin);
 while(fgets(fid,9,id)!=NULL){
        c++;
   // printf("%s\n",fid);
    if(strcmp(cid,fid)==0)
    {
//          printf("found\n");
            break;

    }

  }

  while(fgets(fpin,5,pass)!=NULL){
        p++;
//      printf("%s\n",fpin);
    if(strcmp(cpin,fpin)==0){
  //   printf("found pin\n");
            break;
    }

  }

  for(int i=0;i<c;i++){


fgets(amt,10,balance);


  }
  amount=atol(amt);
   // printf("balance=%d\n",amount);
//  printf("c=%d and p=%d\n",c,p);
k=c;
if (c>19)
    return 0;
else if (c==p)
    return 1;
  else
    return 0;


}
