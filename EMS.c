#include <stdio.h> 
#include <stdlib.h>
#include <conio.h>
#include <windows.h> 
#include <string.h> 

COORD coord = {0,0}; 

void gotoxy(int x,int y)
{
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

/** Main function started */

int main()
{ 
    FILE *fp, *ft; 

    struct employee
    {
        char name[40]; 
        int age; 
        float bs;
    };

    struct employee e; 
    char more, ch;
    char empname[40];

    long int recsize; 
    fp = fopen("EMPLOYEE.DAT","rb+");
    if(fp == NULL)
    {
        fp = fopen("EMPLOYEE.DAT","wb+");
        if(fp == NULL)
        {
            printf("Connot open file");
            exit(1);
        }
    }
    	system("color 30");
	int r,q;
	gotoxy(30,20);
	printf("EMPLOYEE RECORD SYSTEM");
	printf("\n                     *****************************************\n");
	gotoxy(32,36);
	printf("LOADING....");
	gotoxy(32,38);
	for(r=1;r<=25;r++)
	{for(q=0;q<=100000000;q=q+2);
	{printf("%c",177);
	}
	}
	system("color 9d");
    recsize = sizeof(e);

    while(1)
    {
        system("cls"); 
        gotoxy(25,6);
        printf("      EMPLOYEE  RECORD  SYSTEM  ");
        gotoxy(20,8);
        printf("\n=================================================================================\n");
        gotoxy(30,10); 
        printf("1. Add Record"); 
        gotoxy(30,12);
        printf("\n                          ________________________________\n");
        gotoxy(30,14);
		printf("2. List Records"); 
        gotoxy(30,16);
        printf("\n                          ________________________________\n");
		gotoxy(30,18);
        printf("3. Modify Records"); 
        gotoxy(30,20);
        printf("\n                          ________________________________\n");
        gotoxy(30,22);
        printf("4. Delete Records"); 
        gotoxy(30,24);
        printf("\n                          ________________________________\n");
        gotoxy(30,26);
		printf("5. Exit"); 
        gotoxy(30,28);
        printf("\n                          ________________________________\n");
        gotoxy(30,30);
		printf("Your Choice: "); 
        fflush(stdin); 
        ch  = getche(); 
        switch(ch)
        {
        case '1': 
            system("cls");
            system("color 6f");
            fseek(fp,0,SEEK_END); 
           

            more = 'y';
            printf("                          ADDITION OF RECORDS");
            printf("\n_______________________________________________________________________________\n");
            while(more == 'y')  
            {   
                
                printf("\nEnter name: ");
                scanf("%s",e.name);
                printf("\n---------------------------------------\n");
                
                printf("\nEnter age: ");
                scanf("%d", &e.age);
                printf("\n---------------------------------------\n");
                
                printf("\nEnter basic salary $: ");
                scanf("%f", &e.bs);
                printf("\n---------------------------------------\n");

                fwrite(&e,recsize,1,fp); 

                printf("\nAdd another record(y/n) ");
                fflush(stdin);
                more = getche();
                printf("\n-----------------------------------------------------------------------------\n");
            }
            break;
        case '2':
            system("cls");
            system("color df");
            rewind(fp); 
            printf("                               LIST  OF  ALL  RECORDS");
            printf("\n________________________________________________________________________________\n");
            while(fread(&e,recsize,1,fp)==1)  
            {
                printf("\n# name of employee=%s \n age of employee=%d \n salary of employee=$%.2f \n\n",e.name,e.age,e.bs); 
                printf("\n--------------------------------------------------------\n");
            }
            getch();
            break;

        case '3':  
            system("cls");
            system("color a4");
            more = 'y';
            printf("                              MODIFICATION   OF   RECORD");
            printf("\n_________________________________________________________________________________\n");
            while(more == 'y')
            {   
                printf("Enter the employee name to modify: ");
                scanf("%s", empname);
                printf("\n----------------------------------\n");
                rewind(fp);
                while(fread(&e,recsize,1,fp)==1)  
                {
                    if(strcmp(e.name,empname) == 0)  
                    {
                        printf("\nEnter new name,age and basic salary:\n ");
                        printf("---------------------------------\n");
                        scanf("%s%d%f",e.name,&e.age,&e.bs);
                        printf("\n----------------------------------\n");
                        fseek(fp,-recsize,SEEK_CUR); 
                        fwrite(&e,recsize,1,fp); 
                        break;
                    }
                }
                printf("\nModify another record(y/n)");
                fflush(stdin);
                more = getche();
                printf("\n------------------------------------------------------------------------------\n");
            }
            break;
        case '4':
        	system("color 65");
            system("cls");
            more = 'y';
            printf("                              DELETION  OF  RECORD");
            printf("\n__________________________________________________________________________________\n");
            while(more == 'y')
            {   
                printf("\nEnter name of employee to delete: ");
                scanf("%s",empname);
                printf("-------------------------------------\n");
                ft = fopen("Temp.dat","wb");  
                rewind(fp); 
                while(fread(&e,recsize,1,fp) == 1)  
                {
                    if(strcmp(e.name,empname) != 0) 
                    {
                        fwrite(&e,recsize,1,ft); 
                    }
                }
                fclose(fp);
                fclose(ft);
                remove("EMPLOYEE.DAT"); 
                rename("Temp.dat","EMPLOYEE.DAT"); 
                fp = fopen("EMPLOYEE.DAT", "rb+");
                
                printf("Delete another record(y/n)");
                
                fflush(stdin);
                more = getche();
                printf("\n------------------------------------------------------------------------------\n");
            }
            break;
        case '5':
            fclose(fp);  
            exit(0); 
        }
    }
    return 0;
}