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


//Prototypes
int  menu();

void processFile();
int processFileMenu();

FILE *openingFile();
void fileOpened();
FILE *openFile();
FILE *duplicate();

void encrypt();
void decrypt();
void  close();



//Global variables

char fileName[15];
char fileCopy[15];
char encrypted[15];
char decrypted[15];

int fileEncrypted=0, numrecords=0, currentrec=0;
int FILESIZE=512;
char txtfile[512];
//int id={7,6,0,5,8,9,3,2,1};
char id[9]={"760589321"};


 

// /a :beep
int main ()
{
	FILE *copy;
	int option=0;
	char file[15];
	time_t  timer = time(NULL);
	
	printf("Date and time:\t%s\n\n\n\n", ctime(&timer));
	system("color F1");
	
	printf("File: %s",file);

	option=menu();
	switch(option)					
    {
           case 1:	system("cls");
					system("color F2");
					copy=openingFile();
					break;
       
           case 2:	system("cls");
					system("color F3");
					processFile(copy);
					break;
                     
           case 3:	system("cls");
					system("color F4");
					close();
					break;
                 
           default:	printf("Invalid Choice");
					break;
    }
	

}  /*end main*/

 
int menu ()
{
	int option=0;

	system("cls");
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

int menu2()
{
	int option=0;

	system("cls");
	printf("\t F I L E    M E N U \n\n");
    printf("Choose from the options\n\n");

	puts("**************************************\n");
    printf("  1-	Process File\n");
    printf("  2-	Exit\n\n");
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


FILE *openingFile()
{
	FILE *fp, *copy;
	char ch;
	
	puts("OPENING FILE");

	printf ("Source file name: "); //jdf.txt
    scanf ("%s", fileName);
	//strcat(fileName,"jdf.txt");
	fp=openFile(fileName, "r");	
	printf("\n==> %s opened",fileName);
	
	//fileOpened=1;
	puts("\nCOPYING FILE");

	printf ("\n\nDestination file name: "); //Copyjdf.txt
	scanf ("%s", fileCopy);
	//strcat(fileCopy,"Copyjdf.txt");

	copy =duplicate(fileCopy);		
	while((ch=getc(fp))!=EOF)
	{
		putc(ch,copy);
	}
	printf("\nCOMPLETED\a");
	getch();

	fclose(fp);

	fileOpened(fileCopy, copy);

	return copy;
}

void fileOpened(char *file, FILE *copy)
{
	int option=0;
	time_t  timer = time(NULL);
	
	printf("Date and time:\t%s\n\n\n\n", ctime(&timer));
	system("color F1");
	
	printf("File: %s",file);

	option=menu2();
	switch(option)					
    {
           case 1:	system("cls");
					system("color F3");
					processFile(copy);
					break;
       
           case 2:	system("cls");
					system("color F4");
					close();
					break;
                     
                    
           default:	printf("Invalid Choice");
					break;
    }
}

FILE *openFile(char *fileName, char *mode)
{
	FILE *fp;

	fp = fopen(fileName,mode);
	if ( fp == NULL ) 
	{
		perror ( "Unable to open file" );
		printf("-%s-",fileName);
		getch();
		exit ( EXIT_FAILURE );
	 }
	return fp;
}





FILE *duplicate(char *fileCopy)
{
	FILE *copy;
	time_t  timer = time(NULL);

	copy = fopen(fileCopy,"w");
	if (copy == NULL ) 
	{
		perror ( "Unable to open file" );
		printf("-%s-",fileCopy);
		getch();
		exit ( EXIT_FAILURE );
	 }

	printf("\n\n File Copied to: %s",fileCopy);

	fprintf(copy,"ID:\t 620057694");
	fprintf(copy,"\nDate and time:\t%s\n\n\n\n", ctime(&timer));
	
	return copy;
}

void processFile(FILE *copy)
{
	
	int option=0;

	option=processFileMenu();
	switch(option)
    {
           case 1:	system("cls");
					system("color F5");
					encrypt(copy);
					break;
       
           case 2:	system("cls");
					system("color F5");
					decrypt(copy);
					break;

			case 3:	system("cls");
					system("color F5");
					//compress();
					break;
	             
           case 4:	close();
					break;
                 
           default:	printf("Invalid Choice");
					break;
    }
}

int processFileMenu()
{
	int option=0;
	system("cls");
	printf("\t Process File \n\n");
    printf("Choose from the options\n\n");

	puts("****************************************\n");
    printf("  1-	Encrypt File\n");
	printf("  2-	Decrypt File\n");
	printf("  3-	Compress File\n");
    printf("  4-	Exit\n\n");
	puts("****************************************\n");
	printf("--> ");
    scanf ("%i", &option);
	
    while (option< 0 && option> 3)
    {
          printf ("Invalid option please re-enter");
          scanf ("%i", &option);
    }

    return option;
}
void encrypt(FILE *copy)
{
	FILE *fp;
	int i=0;
	rewind(copy);
    /*go through the file and change all characters to 1 charater after */
    printf ("\n\nDestination file name: "); //Encryptedjdf.txt
	scanf ("%s", encrypted);
	
	fp= openFile(encrypted, "w");
	puts("Loading *");
    while ((i = fgetc(copy))!=EOF )
	{
        i = i + 1;
        fseek(copy, -1, SEEK_CUR);
        fputc(i,fp);
		fprintf(fp,i);
        //fflush(file);
        //fflush not needed if going back to original position in the file
        fseek(copy, 0, SEEK_CUR);
		puts("*");
    }
	printf("Encrypted \a\a");
	fclose(copy);
	//getch();
	fileOpened(encrypted, fp);
}

//void encrypt2(FILE *copy)
//{
//	int i,shiftval;
//    currentrec = 0;
//
//	while (currentrec < FILESIZE)
//	{
//		for ( i= 0; i <= 30-1;i++)
//			{
//				shiftval = id[i % 9]-48;
//				txtfile[i]= txtfile[i] - shiftval;
//				putc(txtfile[i],copy);
//			}
//		currentrec++;
//	}


	//while((ch=getc(copy))!=EOF)
	//{
		//ch=ch+'7';
		//ch ^=*(key++);

		//printf(ch);
		//putc(ch,copy);
	//}
//	printf("Encrypted /a/a");
//	getch();
//}

void decrypt(FILE *encrypted)
{
	FILE *fp;
	int i=0;
	rewind(encrypted);
    /*go through the file and change all characters back from 1 */
    rewind(encrypted);

	printf ("\n\nDestination file name: "); //Decryptedjdf.txt
	scanf ("%s", decrypted);
	fp= openFile(decrypted, "w");
    
    while ( ( i = fgetc(encrypted) )!=EOF ){
        i = i - 1;
        fseek(encrypted, -1, SEEK_CUR);
        fputc(i,fp);
		fprintf(fp,i);
        //fflush(file);
        /* fflush not needed if going back to the original postion in the file
         use one or the other */
        fseek(encrypted, 0, SEEK_CUR);
    }
    fclose(encrypted);
	fclose(fp);

	fileOpened(decrypted,fp);
}


void  close()
{
	int i;
	printf("-----Goodbye-----\n");
	for (i=0; i<20; i++);
	{
		puts("*");
		puts("");
		
		
	}
	
	getch();
	system("pause");
	exit(3);
}