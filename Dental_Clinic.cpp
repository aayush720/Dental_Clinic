//HEADER FILES
#include<stdio.h>//Use for standard I/O Operation
#include<windows.h>
#include<conio.h>//Use for delay(),getch(),gotoxy(),etc.
#include<ctype.h>//se for toupper(), tolower(),etc
#include<string.h>//Use for strcmp(),strcpy(),strlen(),etc
#include<stdlib.h>

char ans=0; 
int ok;
int b, valid=0;
char treat[8][22]={"","Root Canal Teeth","Pairia","Braces","Crown and Caps","Filling and Repairs","Teeth Whitening","Gum Surgery"};
char price[8][5]={"","4000","2000","5000","6000","1000","1000","2500"};
char doc[4][28]={"","Dr.Pankaj Verma","Dr.AK Gupta ","Dr.Narayan Mangla"};
char qua[4][5]={"","DMD","DMS","BDS"};
//FUNCTION DECLERATION
void WelcomeScreen(void);//WelcomeScreen function decleration
void Title(void);//Title function decleration
void MainMenu(void);//MainMenu function decleration
void Menu_Option();//just for again go in  menu
void Doctor_Name();//Doctor method
void Doct_List();//Doctor name
void Treatment_rec();//Disease record name
void Treatment_Chart();//Details mention 
void Add_rec(void);//Add_rec function declaration
void func_list();//function to list the patient details 
void Dlt_rec(void);//Dlt_rec function declaration
void Report(); //Report show for particular patient
void ex_it(void);//exit function declaration
//Defines gotoxy() for ANSI C compilers.
void gotoxy(short x, short y) 
{
COORD pos = {x, y};//sets co-ordinates in (x,y).
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

struct patient//list of global variable
{
	int age;
	char Gender;
	char First_Name[20];
	char Last_Name[20]; 
	char Contact_no[15];
	char Email[30];
	int Doctor;
	int Problem;
};

struct patient  p;

main(void)
{
	
    WelcomeScreen();//Use to call WelcomeScreen function
	Title();//Use to call Title function
   MainMenu();	
	}
/* ************************************************* Welcome Screen ********************************************* */
void WelcomeScreen(void) //function for welcome screen
{
	
	printf("\n\n\n\n\n\n\n\t\t\t\t#########################################");
	printf("\n\t\t\t\t#\t\t WELCOME TO\t\t#");
	printf("\n\t\t\t\t#\t     PANKAJ DENTAL CLINIC \t#");
	printf("\n\t\t\t\t#########################################");
	printf("\n\n\n\n\n Press ENTER KEY  to continue......\n");
	getch();//Use to holds screen for some seconds
	system("cls");//Use to clear screen
	
}
/* ************************************************* Title Screen ********************************************* */
void Title(void)//function for title screen
{
	printf("\n\n\t\t----------------------------------------------------------------------------------");
	printf("\n\t\t\t\t       DENTAL CLINIC         ");
	printf("\n\t\t----------------------------------------------------------------------------------");
}
/* ************************************************* Main Menu ********************************************* */
void MainMenu(void)//function decleration
{
	system("cls");
	int choose;
	Title();// call Title function
	
	printf("\n\n\n\n");
	printf("\n\t\t\t\t1. Doctor Details\n");
	printf("\n\t\t\t\t2. Treatment List \n");
	printf("\n\t\t\t\t3. Add Patients Record\n");
	printf("\n\t\t\t\t4. List Patients Record\n");
    printf("\n\t\t\t\t5. Patient Report\n");
	printf("\n\t\t\t\t6. Delete Patients Record\n");
	printf("\n\t\t\t\t7. Exit\n");
	printf("\n\n\n \n\t\t\t\tChoose from 1 to 7:");
	scanf("%i", &choose);
	
	switch(choose)//switch to differeht case
	{
		case 1:
			Doctor_Name();  //list of doctor with details
			break;
	case 2:
		Treatment_rec(); //List of treatment show
		break;
	
	case 3:
	Add_rec();//Add_rec function is called
    	break;
    case 4:
    	func_list();   //to display the content of patient
    	break;
	
	case 5:
		Report();  // Patient Report show
	    break;
		
	case 6:
		Dlt_rec();  	//Dlt_rec function is call
		break;
	
	case 7:
		ex_it();//ex_it function is call
    	break;

	default:
		printf("\t\t\tInvalid entry. Please enter right option :)");
		getch();//holds screen
	}//end of switch
		
	
}
/* ************************************************* Exit Screen ********************************************* */
void ex_it(void)//function to exit
{
	system("cls");
	Title();// call Title function
	printf("\n\n\n\n\n\t\t\tTHANK YOU FOR VISITING :)");

	
}

/* **************************************Doctor Name*******************************************/

void Doctor_Name()
{
	system("cls");
	Title();
	printf("\n\n\n");
Doct_List();
Menu_Option();
}

void Doct_List()
{
    printf("\n\tS.No\tDoctor Name       \t\t Fees   \t\t Timming            \t\t Degree");
	printf("\n\t1.  \tDr.Pankaj Verma   \t\t 500/-  \t\t 11 A.M. to 5P.M.   \t\t DMD");
	printf("\n\t2.  \tDr.AK Gupta       \t\t 500/-  \t\t 10 A.M. to 8P.M.   \t\t DDS");
	printf("\n\t3.  \tDr.Narayan Mangla \t\t 400/-  \t\t 11 A.M. to  6P.M.  \t\t BDS");

}
/* **************************************Treatments  Chart*******************************************/

void Treatment_Chart() 
{
	printf("\t\tS.no\tTREATEMNT\t\t\tPRICE\n");
   for(int count=1;count<=7;count++)
   {
   	printf("\t\t%d\t%-25s\t%s\n",count,treat+count,price+count);
   }
}
/* **************************************Treatments  RECORD*******************************************/


void Treatment_rec()
{
	system("cls");
	Title();
	printf("\n\n\n");
Treatment_Chart();
Menu_Option();
	
}
/* **************************************MENU OPTIONS*******************************************/

void Menu_Option()
{
	printf("\n\n\nGo to main menu press 1 \t:");

int input;
scanf("%d",&input);
if(input==1){
	MainMenu();}
else
exit(0);
}
/* **************************************ADD RECORD*******************************************/

void Add_rec(void)
{
	system("cls");
	Title();// call Title function
	//list of variables
	char ans;
	FILE*ek;//file pointer
	ek=fopen("Record2.dat","a");//open file in write mode
	printf("\n\n\t\t\t!!!!!!!!!!!!!! Add Patients Record !!!!!!!!!!!!!\n");
	
	/* **************************First Name*********************************** */
	A:
	printf("\n\t\t\tFirst Name: ");
	scanf("%s",p.First_Name);
	p.First_Name[0]=toupper(p.First_Name[0]);
	if(strlen(p.First_Name)>20||strlen(p.First_Name)<2)
	{
		printf("\n\t Invalid :( \t The max range for first name is 20 and min range is 2 :)");
		goto A;
	}
	else
	{
		for (b=0;b<strlen(p.First_Name);b++)
		{
			if (isalpha(p.First_Name[b]))
			{
				valid=1;
			}
			else
			{
				valid=0;
				break;
			}
		}
		if(!valid)
		{
			printf("\n\t\t First name contain Invalid character :(  Enter again :)");
			goto A;
		}
	}
	
	/* ********************************************** Last name ************************************************ */
	B:
	printf("\n\t\t\tLast Name: ");
    scanf("%s",p.Last_Name);
    p.Last_Name[0]=toupper(p.Last_Name[0]);
    if(strlen(p.Last_Name)>20||strlen(p.Last_Name)<2)
	{
		printf("\n\t Invalid :( \t The max range for last name is 20 and min range is 2 :)");
		goto B;
	}
	else
	{
		for (b=0;b<strlen(p.Last_Name);b++)
		{
			if (isalpha(p.Last_Name[b]))
			{
				valid=1;
			}
			else
			{
				valid=0;
				break;
			}
		}
		if(!valid)
		{
			printf("\n\t\t Last name contain Invalid character :(  Enter again :)");
			goto B;
		}
	}
/* ******************************************* Gender ************************************************************** */	    
	do
	{
	    printf("\n\t\t\tGender[F/M]: ");
		scanf(" %c",&p.Gender);
		if(toupper(p.Gender)=='M'|| toupper(p.Gender)=='F')
		{
			ok =1;
		}
		else 
		{
		ok =0;
		}
        if(!ok)
	    {
	    	printf("\n\t\t Gender contain Invalid character :(  Enter either F or M :)");
    	}
	 }	while(!ok);
/* ***************************************** Age ********************************************************************** */	
    printf("\n\t\t\tAge:");
    scanf(" %i",&p.age);

/* ******************************************* Contact no. ***************************************** */
do
{
	D:
    printf("\n\t\t\tContact No.: ");
    scanf("%s",p.Contact_no);
    if(strlen(p.Contact_no)>10||strlen(p.Contact_no)!=10)
	{
		printf("\n\t Sorry :( Invalid. Contact no. must contain 10 numbers. Enter again :)");
		goto D;
	}
	else
	{
		for (b=0;b<strlen(p.Contact_no);b++)
		{
			if (!isalpha(p.Contact_no[b]))
			{
				valid=1;
			}
			else
			{
				valid=0;
				break;
			}
		}
		if(!valid)
		{
			printf("\n\t\t Contact no. contain Invalid character :(  Enter again :)");
			goto D;
		}
	}
}while(!valid);
/* ************************************************** Email ******************************************** */
do
{
    printf("\n\t\t\tEmail: ");
    scanf("%s",p.Email);
    if (strlen(p.Email)>30||strlen(p.Email)<8)
    {
       printf("\n\t Invalid :( \t The max range for email is 30 and min range is 8 :)");	
	}
}while(strlen(p.Email)>30||strlen(p.Email)<8);
/* ********************************************************* Problem *********************************************** */
 int input_take;
  do{
  input_take=0;
   printf("\n");
    Treatment_Chart();
     printf("\n\t\t\tPlease Enter a Number According to above list  : ");
    scanf("\t\t%d",&p.Problem);
		
		if(p.Problem<1||p.Problem>7)
		{input_take=1;
				printf("\n\t\t Problem contain Invalid Number :(  Enter again :)\n");
		}
}while(input_take);


/* ********************************************** Prescribed Doctor **************************************** */	
int input_takes;	
	do{
		input_takes=0;
	printf("\n");
    Doct_List();
	printf("\n\n\t\t\tEnter a Number for Appointing Doctor in  above List:");
    scanf("%d",&p.Doctor);
   	if(p.Doctor<1||p.Doctor>3)
		{input_takes=1;
				printf("\n\t\t Doctor Appointment  contain Invalid Number :(  Enter again :)\n");
		}
}while(input_takes);
		
		fprintf(ek," %s %s %c %d %s %s  %d %d\n", p.First_Name, p.Last_Name, p.Gender, p.age, p.Contact_no, p.Email, p.Problem, p.Doctor);
    printf("\n\n\t\t\t.... Information Record Successful ...");
    fclose(ek);//ek file is closed
    sd:
    //getch();
    printf("\n\n\t\t\tDo you want to add more[Y/N]?? ");
    scanf(" %c",&ans);
    if (toupper(ans)=='Y')
	{
    	Add_rec();
	}
    else if(toupper(ans)=='N')
	{
		printf("\n\t\t Thank you :) :)");
    	//getch();
    	MainMenu();
	}
    else
    {
        printf("\n\t\tInvalid Input\n");
        goto sd;
    }
}

/* **************************************VIEW RECORD*******************************************/
void func_list()
{
	int row;
	system("cls");
	Title();
	FILE *ek;
	ek=fopen("Record2.dat","r");
	printf("\n\n\t\t\t!!!!!!!!!!!!!! List Patients Record !!!!!!!!!!!!!\n");
	gotoxy(1,15);
		printf("Full Name");
		gotoxy(20,15);
		printf("Gender");
		gotoxy(31,15);
		printf("Age");
		gotoxy(35,15);
		printf("Contact No.");
		gotoxy(47,15);
		printf("Email");
		gotoxy(70,15);
		printf("Problem");
		gotoxy(100,15);
		printf("Prescribed Doctor\n");
		printf("=================================================================================================================");
		row=17;
		while(fscanf(ek,"%s %s %c %d %s  %s %d %d\n", p.First_Name, p.Last_Name, 
					&p.Gender, &p.age, p.Contact_no, p.Email, &p.Problem, &p.Doctor)!=EOF)
		{
			gotoxy(1,row);
			printf("%s %s",p.First_Name, p.Last_Name);
			gotoxy(20,row);
			printf("%c",p.Gender);
			gotoxy(31,row);
			printf("%i",p.age);
			gotoxy(35,row);
			printf("%s",p.Contact_no);
			gotoxy(47,row);
			printf("%s",p.Email);
			gotoxy(70,row);
			printf("%s",treat[p.Problem]);
			gotoxy(100,row);
			printf("%s",doc[p.Doctor]);
			row++;
		}
		fclose(ek);
		Menu_Option();
		
		
}

/* **************************************Delete RECORD*******************************************/

void Dlt_rec()
{
	char name[20];
	int found=0;
	system("cls");
	Title();// call Title function
	FILE *ek, *ft;
	ft=fopen("temp_file2.dat","w+");
	ek=fopen("Record2.dat","r");
	printf("\n\n\t\t\t!!!!!!!!!!!!!! Delete Patients Record !!!!!!!!!!!!!\n");
	gotoxy(12,8);
	printf("\n Enter Patient Name to delete: ");
	fflush(stdin);
	gets(name);
	
	name[0]=toupper(name[0]);

	while (fscanf(ek,"%s %s %c %d %s  %s %d %d", p.First_Name, p.Last_Name, &p.Gender,
			 &p.age,  p.Contact_no, p.Email, &p.Problem, &p.Doctor)!=EOF)
	{
		if (strcmp(p.First_Name,name)!=0)
		fprintf(ft,"%s %s %c %d %s  %s %d %d\n", p.First_Name, p.Last_Name, p.Gender, p.age, p.Contact_no, p.Email, p.Problem, p.Doctor);
		else 
		{   printf("Full Name     Gender  Age   Contact No   Email          Problem      Doctor\n");
			printf("%s %s    %c     %d    %s    %s    %s   %s\n", p.First_Name, p.Last_Name, p.Gender, p.age,  p.Contact_no, p.Email, treat[p.Problem], doc[p.Doctor]);
			found=1;
		}
	}//while loop ends
	if(found==0)
	{
		printf("\n\n\t\t\t Record not found....");
		getch();
		MainMenu();
	}
	else
	{
		fclose(ek);//new file
		fclose(ft);//temp file
		remove("Record2.dat");
		rename("temp_file2.dat","Record2.dat");
		printf("\n\n\t\t\t Record deleted successfully :) ");
		getch();
		MainMenu();
	}
} 

/* **************************************Report RECORD*******************************************/

void Report()
{   char name[20];
	system("cls");
    FILE *ek;
	ek=fopen("Record2.dat","r");
	gotoxy(10,2);
	printf("Please enter a patient name:  ");
	scanf("%s",name);
	fflush(stdin);
	name[0]=toupper(name[0]);
	while(fscanf(ek,"%s %s %c %d %s %s %d %d\n", p.First_Name, p.Last_Name, &p.Gender, &p.age, p.Contact_no, p.Email, &p.Problem, &p.Doctor)!=EOF)
	{
		if(strcmp(p.First_Name,name)==0)
		{system("cls");
		printf("\n\t\t\t#########################################");
           	printf("\n\t\t\t#\t\t WELCOME TO\t\t#");
	        printf("\n\t\t\t#\t     PANKAJ DENTAL CLINIC \t#");
	        printf("\n\t\t\t#########################################");
	        for(int count=1;count<4;count++)
	        {
	        	printf("\n\t\t%s (%s)",doc[count],qua[count]);
			}
		printf("\n\n\t\t!!!!!!!!!!!!!! Patient Report !!!!!!!!!!!!!! \n");
			
			gotoxy(15,12);
			printf("Full Name : ");
			gotoxy(15,14);
			printf("Gender : ");
			gotoxy(50,14);
			printf("Age : ");
			gotoxy(15,16);
			printf("Contact No. : ");
			gotoxy(15,18);
			printf("Email : ");
			gotoxy(15,20);
			printf("Problem : ");
			gotoxy(50,20);
			printf("Payment : ");
			gotoxy(15,22);
			printf("Doctor Name : ");
		    
			gotoxy(30,12);
		    printf("%s %s",p.First_Name, p.Last_Name);
			gotoxy(30,14);
			printf("%c",p.Gender);
			gotoxy(60,14);
			printf("%d",p.age);
			gotoxy(30,16);
			printf("%s",p.Contact_no);
			gotoxy(30,18);
			printf("%s",p.Email);
			gotoxy(30,20);
			printf("%s",treat[p.Problem]);
			gotoxy(60,20);
			printf("%s",price[p.Problem]);
			gotoxy(30,22);
			printf("%s",doc[p.Doctor]);
			printf("\n");
				printf("\n\n\t\t\tTHANK YOU FOR VISITING :)");
                printf("\n\n\t\t\t\tLOVE YOUR TEETH :)");				
				
			break;
		}
	   }
	   if(strcmp(p.First_Name,name)!=0)
	   {
		gotoxy(5,5);
		printf("Record not found!");
	   }
	fclose(ek);
	L:
	
	printf("\n\n\t\t\tDo you want to view more[Y/N]??");
    scanf("%c",&ans);
    if (toupper(ans)=='Y')
    {
       Report();
    }
	else if(toupper(ans)=='N')
	{
		printf("\n\t\t Thank you :) :)");
    	MainMenu();
    }
	else
    {
    	printf("\n\tInvalid Input.\n");
    	goto L;
    }
}
