#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
typedef struct voter_information
{
    char aadhar[20];
    char name[50];
    char birth_date[15];
    struct voter_information *next;
} node;

node *head;
node *space,*start=NULL;
node *search(char x[],char y[],char z[],node *,int *);
node *voter_insert(node *);
node *logs(node *);
 void admin();
 void winner();
 	void exi();
 	void voting();
 	void not_again();
 	void stop();
 	void show();


int count=0,R=3,vote=0;
int vote1=0,vote2=0,vote3=0,vote4=0,vote5=0;
int main()
{
	while(1){

    system("cls");
    printf("\n\n\n");
    printf("* * * WELCOME TO THE ONLINE VOTING PORTAL * * * *\n\n\n");

    printf("*   *   *   *   *   *   *   *   *   *   *   *   *\n\n\n");
    printf("Please Enter One(1) for logging vote main Logs \n\n\n");
    int one;

    scanf("%d",&one);
    if(one==1)
    {
      start=logs(start);
    }

}
    return 0;
}

node *logs(node *start)
{
    system("cls");
    printf("\n\n\n");
    printf("1. FOR VOTE ENTRY     \n");
    Sleep(300);
    printf("2. FOR ADMIN PANEL    \n");
    Sleep(300);
    printf("3. FOR WINNER         \n");

     printf("4. FOR EXITING         \n\n\n");
    printf("IF YOUR CREDENTIALS MATCHES WITH THOSE IN THE VOTER LIST THEN ONLY YOU CAN GIVE YOUR VOTE OTHERWISE YOU CAN NOT    \n\n\n");
    Sleep(500);
    printf("Enter your choice: ");
    int choice;
    scanf("%d",&choice);
    if(choice==1)
    {
       start= voter_insert(start);
    }
    if(choice==2)
    {
      admin();
    }
    if(choice==3)
    {
      winner();
    }
    if(choice==4)
    {
        exi();
    }
    if(choice!=1 && choice!=2 && choice!=3 && choice!=4)
    {
    	logs(start);
	}


    return start;
}


node *voter_insert(node *start)
{
	int UNIVERSAL=0;
    int *z;
    z = &UNIVERSAL;
    node *temp;
    char name[50],birth_date[15],aadhar[20];
    system("cls");
    printf("\n\n\n");
    printf("IF AADHAR ID, YOUR NAME AND YOUR DATE OF BIRTH MATCHES THEN YOU CAN GIVE YOUR VOTE OTHERWISE NOT\n\n");
    Sleep(300);
    printf("IF YOUR ENTRY IS INCORRECT %d TIMES, THE PORTAL WILL BE CLOSED AUTOMATICALLY\n\n\n",R);
    Sleep(300);
    printf("Please \n");
    Sleep(300);
    printf("Enter your AADHAR ID number:                    ");
    gets(aadhar);
    gets(aadhar);
    printf("Enter Your NAME:                                ");
    gets(name);
    printf("Enter Your BIRTH DATE  in dd-mm-yyyy format:    ");
    gets(birth_date);
    temp=(node *)malloc(sizeof(node));
    strcpy(temp->aadhar,aadhar);
    strcpy(temp->name,name);
    strcpy(temp->birth_date,birth_date);
    temp->next=NULL;
    head=temp;
    while(temp!=NULL)
    {
        if((strcmp(temp->aadhar,"1001")==0&& strcmp(temp->name,"Amrutha")==0 &&strcmp(temp->birth_date,"05-06-2004")==0) ||
        (strcmp(temp->aadhar,"1002")==0&& strcmp(temp->name,"Megha")==0 &&strcmp(temp->birth_date,"07-02-2004")==0)||
        (strcmp(temp->aadhar,"1003")==0&& strcmp(temp->name,"Sreya")==0 &&strcmp(temp->birth_date,"25-01-2005")==0)||
        (strcmp(temp->aadhar,"1004")==0&& strcmp(temp->name,"Jeevan")==0 &&strcmp(temp->birth_date,"12-11-2004")==0)||
        (strcmp(temp->aadhar,"1005")==0&& strcmp(temp->name,"Daniel")==0 &&strcmp(temp->birth_date,"04-12-2003")==0)||
        (strcmp(temp->aadhar,"1006")==0&& strcmp(temp->name,"Devaraj")==0 &&strcmp(temp->birth_date,"01-01-2005")==0)||
        (strcmp(temp->aadhar,"1007")==0&& strcmp(temp->name,"Vaibhav")==0 &&strcmp(temp->birth_date,"08-04-2004")==0)||
        (strcmp(temp->aadhar,"1008")==0&& strcmp(temp->name,"Lizy")==0 &&strcmp(temp->birth_date,"31-08-2004")==0)||
        (strcmp(temp->aadhar,"1009")==0&& strcmp(temp->name,"Rachitha")==0 &&strcmp(temp->birth_date,"06-11-2004")==0)||
        (strcmp(temp->aadhar,"1010")==0&& strcmp(temp->name,"Ankith")==0 &&strcmp(temp->birth_date,"29-10-2004")==0))

        {
         	R=3;
         	start=search(temp->aadhar,temp->name,temp->birth_date,start,&UNIVERSAL);

         	if(UNIVERSAL==0)
            {
            	voting();
			}
            else
            {
             	not_again();
			}
        }
        
        else
        {
            R--;
            if(R==0)
            {
                stop();
                break;
            }
            printf("\n\n");
            printf("Your AADHAR ID or NAME or DATE OF BIRTH is wrong\n\n");
            Sleep(300);
            printf("Please Re-Enter\n\n");
            Sleep(300);
            system("pause");
            start= logs(start);
        }
        temp=temp->next;
    }
    return start;
}


void voting()
{
    system("cls");
    printf("\n\n\n\n");
    printf("\t\t     * * * * * LIST OF CANDIDATES * * * * * \n\n\n");
    Sleep(300);
    printf("\t\t\t NAME     & THEIR RESPECTIVE      Symbols\n\n");
    Sleep(300);
    printf("\t\t\t 1. A                             1. A\n");
    Sleep(300);
    printf("\t\t\t 2. B                             2. B\n");
    Sleep(300);
    printf("\t\t\t 3. C                             3. C\n");
    Sleep(300);
    printf("\t\t\t 4. D                             4. D\n");
    Sleep(300);
    printf("\t\t\t 5. E                             5. E\n\n\n");



        int v,j;
        printf("Please, \n");
        printf("Enter Your Choice: ");
        for(j=1;j<=1;j++)
        {
            scanf("%d",&v);

            if(v==1)
            {
                vote1++;
                printf("\n\nYOU HAVE SUCCESSFULLY GIVEN YOUR VOTE TO A\n");
                break;

            }
            if(v==2)
            {
                vote2++;
                printf("\n\nYOU HAVE SUCCESSFULLY GIVEN YOUR VOTE TO B\n");
                break;

            }
            if(v==3)
            {
                vote3++;
                printf("\n\nYOU HAVE SUCCESSFULLY GIVEN YOUR VOTE TO C\n");
                break;

            }
            if(v==4)
            {
                vote4++;
                printf("\n\nYOU HAVE SUCCESSFULLY GIVEN YOUR VOTE TO D\n");
                break;
            }
            if(v==5)
            {
                vote5++;
                printf("\n\nYOU HAVE SUCCESSFULLY GIVEN YOUR VOTE TO E\n");
                break;
            }
            if(v!=1||v!=2||v!=3||v!=4||v!=5)
            {
           	    printf("\n--------------------INVALID CHOICE ENTERED--------------------\n");
           	    printf("\nENTER AGAIN\n");
		    }



        }
	    printf("\n\n------------------------------THANK YOU------------------------------\n\n");
	    printf("To go back press any key");
	    getch();
}   

void admin()
{
    int password;
    printf("\n\n\n\n");
    printf("Enter Your Password To Unlock The Admin Panel\n\n");
    scanf("%d",&password);
    if(password==1234)
    {
        show();

    }
    else
    {
        printf("Wrong Password\n");
    }
}

void show()
{
  	int G;
    system("cls");

    printf("\n\n\n\n");
    printf("Present Vote Count :\n\n");
    Sleep(500);
    printf("A     %d Votes\n",vote1);
    Sleep(500);
    printf("B     %d Votes\n",vote2);
    Sleep(500);
    printf("C     %d Votes\n",vote3);
    Sleep(500);
    printf("D     %d Votes\n",vote4);
    Sleep(500);
    printf("E     %d Votes\n\n\n\n",vote5);
    Sleep(500);


    printf("Enter Any Key For Main Logs         OR         ENTER THE SPECIAL PASSWORD TO CLOSING VOTING PORTAL\n ");
    scanf("%d",&G);
    if(G==0000)
        exi();
    else
        logs(start);

}

   void winner()
    {
        system("cls");
        printf("\n\n\n\n");
        if(vote2<vote1 && vote3< vote1 && vote4<vote1 && vote5<vote1)
        printf("The present Winner is A and has got %d votes\n\n\n\n",vote1);

        if(vote1<vote2 && vote3< vote2 && vote4<vote2 && vote5<vote2)
        printf("The present Winner is B and has got %d votes\n\n\n\n",vote2);

        if(vote1<vote3 && vote2< vote3 && vote4<vote3 && vote5<vote3)
        printf("The present Winner is C and has got %d votes\n\n\n\n",vote3);

        if(vote1<vote4 && vote2< vote4 && vote3<vote4 && vote5<vote4)
        printf("The present Winner is D and has got %d votes\n\n\n\n",vote4);

        if(vote1<vote5 && vote2< vote5 && vote3<vote5 && vote4<vote5)
        printf("The present Winner is E and has got %d votes\n\n\n\n",vote5);

        printf("Enter Any Key for Main Log\n\n");
        getch();
        logs(start);

    }

    void stop()
    {
        system("cls");

        printf("\n\n\n\n");
        printf("SORRY YOU ENTERED WRONG CREDENTIALS FOR THREE(3) TIMES IN A ROW !!! \n\n\n");
        Sleep(500);
        printf("Please try again after some time!\n\n\n");
        Sleep(500);
        printf("--------------------------------------Thank You-------------------------------------- \n\n\n");
        Sleep(500);
        printf("To go back press any key");
        getch();

    }

    void not_again()
    {
        int A;
		system("cls");
        printf("\n\n\n\n");
        printf("-----------------------------YOU HAVE GIVEN YOUR VOTE SUCCESSFULLY-----------------------------     \n\n\n");
        Sleep(300);
        printf("-----------------------------YOU CANNOT GIVE YOUR VOTE MORE THAN ONCE----------------------------- \n\n\n");
        Sleep(300);
        printf(" If You want to see present winner Enter One(1) or Enter Any Other Key for Main  Logs\n\n");
        Sleep(300);

        scanf("%d",&A);
        if(A==1)
        {
            winner();
        }
        else
        {
            logs(start);
        }

   }

   void exi()
   {
        system("cls");

        printf("\n\n\n\n\n");
        Sleep(500);
        printf("\t\t\t        ***YOU ARE NOW EXITING THE PORTAL***       \n\n\n");
        Sleep(1000);
        printf("\t\t\t ----------Thank You For Using This ONLINE PLATFORM For VOTING------------  \n\n\n");
        Sleep(1000);
        exit(0);
   }

node *search(char x[],char y[],char z[],node *start,int *Y)
{
    *Y=0;
    node *t,*space;
    if(start==NULL)
    {
        space=(node*)malloc(sizeof(node));
        strcpy(space->aadhar,x);
        strcpy(space->name,y);
        strcpy(space->birth_date,z);
        
        start=space;
        space->next=NULL;
    }
    else
    {
        t=start;     
        while(t!=NULL)
        {          
            if((strcmp(t->aadhar,x)==0&& strcmp(t->name,y)==0 &&strcmp(t->birth_date,z)==0))          
            {
          	    *Y=1;

          	    break;
            }
                t=t->next;
    	}

        if(*Y==0)
        {

          	space=(node*)malloc(sizeof(node));

       		strcpy(space->aadhar,x);

       		strcpy(space->name,y);

       		strcpy(space->birth_date,z);
	        t=space;
    	    space->next=NULL;

    	}
    }
    return start;
 }
