/***********************************\
| Title:	COMP2340 Project 2   	|
|									|
| Date:	15/03/2011					|
|									|
| Programmer: 620057694         	|
|									|
| File:								|
\***********************************/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
#include <string.h>

int  menu();
FILE *openFile();
void duplicate();
//void loadFile();

void  close();




char txtfile[512];
int recordsize=22;
char id[9];
char inFileName[12];
char outFileName[12];
int fileLoaded=0, fileEncrypted=0, numrecords=0, currentrec=0;
int c;


//time_t  timer = time(NULL);




// /a :beep
int main ()
{
	int option=0;
	time_t  timer = time(NULL);
	
	printf("Date and time:\t%s\n\n\n\n", ctime(&timer));
	system("color F3");

	option=menu();
	switch(option)
    {
           case 1:	system("cls");
					system("color F5");
					openFile();
					break;
       
           case 2:	//processFile();
					break;
                     
           case 3:	close();
					break;
                 
           default:	printf("Invalid Choice");
					break;
    }
	

}  /*end main*/

 
int menu ()
{
	int option=0;
	printf("\t M A I N    M E N U \n\n");
    printf("Choose from the options\n\n");

	puts("**************************************\n");
    printf("  1-	Open File\n");
    printf("  2-	Process File\n");
    printf("  3-	Exit\n\n");
	puts("**************************************\n");
	printf("--> ");
    scanf ("%i", &option);
	
    while (option< 0 && option> 3)
    {
          printf ("Invalid option please re-enter");
          scanf ("%i", &option);
    }
    return option;
}



FILE *openFile ()
{
	FILE *fp;
	char fileName[15];
	char fileCopy[15]="Copy";
	
	printf ("File name: ");
    scanf ("%s", fileName);

	fp = fopen(fileName,"r");
	if ( fp == NULL ) 
	{
		perror ( "Unable to open file" );
		printf("-%s-",fileName);

		getch();
		exit ( EXIT_FAILURE );
	 }
	 else
	 {
		 printf("\n\n==> %s opened",fileName);
		 
		 strcat(fileCopy, fileName);		 
		 duplicate(fileCopy);
		 
		 getch();
	}
	fclose(fp);
	
	return fp;
}

void duplicate(fileCopy)
{
	FILE *copy;

	copy = fopen(fileCopy,"w");

	printf("\n\n File Copied");

	fprintf(copy,"620057694");
	//fprintf("Date and time:\t%s\n\n\n\n", ctime(&timer));
	fclose(copy);
}


void  close()
{
	int i;
	printf("-----Goodbye-----");
	for (i=0; i<20; i++);
	{
		printf("*");
		
	}
	exit(2);

	getch();
	system("pause");
}