/* This is the code for simple phone book application in c.Only basic functions like adding,deleting,modifying
are incorporated.For this specific program file is saved as phonebook.DAT in the drive specified.
Author : Rachana Banjade
*/









#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>



int main()
{
		FILE *fp,*ft;
		char another,choice;
		
		
		//structure for storing phone number
		struct contact
		{
			char name[40];
			int phonenumber;
			char morh[30];
		};
		struct contact e;
		
		
		
		char phonename[40];
		long int recsize = 0;
		
		
		
		
		//file to store phone numbers
		fp=fopen("phonebook.txt","r");
		
		//initializing file pointer
		
		if(fp==NULL)
		{
			fp=fopen("phonebook.txt","w");
			
			if(fp == NULL)
			{
				puts("Cannot open file");
				exit(1);
			}
		}
		
		
	recsize=sizeof(e);
	
	
	//when the file opens successfully the following code is run.
	while(1)
	{
		
		system("cls");
		
		printf("\n1.Add Contacts");
		
		printf("\n2.List Contacts");
		
		printf("\n3.Modify Contacts");
		
		printf("\n4.Delete Contacts");
		
		printf("\n0.Exit");
		
		printf("\n\nEnter your choice \t");
		
		
		
		
		fflush(stdin);
		
		choice = getche();
		
		
		
		//for selecting the choices
		
		switch (choice)
		{
			
			
			
			
			// Adding contacts on the phone book
			case '1':
				fseek(fp,0,SEEK_END);
				
				another='Y';
				
				while(another == 'Y')
				{
					printf("\nEnter Name \t");
					scanf("%s",e.name);
					
					printf("\n Enter Phonenumber \t");
					scanf("%d", &e.phonenumber);
					
					printf("\n Enter mob or home \t");
					scanf("%s", e.morh);
					
					fwrite(&e,recsize,1,fp);
					
					printf("\n Add another Record(Y/N)");
					
					fflush(stdin);
					another =  getche();
				}
				break;
				
			
			// Listing contacts on the phone book 
			case '2':
				
				rewind(fp);
				
				while(fread(&e,recsize,1,fp)==1)
				printf("\n%s\t %d \t%s",e.name,e.phonenumber,e.morh);
				
				break;
				
			
			//modifying the contacts
			
			case '3':
				another='Y';
				while(another=='Y')
				{
					printf("\nEnter contact to modify \t");
					scanf("%s",phonename);
					
					rewind(fp);
					while(fread(&e,recsize,1,fp)==1)
					{
						if(strcmp(e.name,phonename)==0)
						{
							printf("\nEnter new Contact name , phone number & mobile or home option \t");
							scanf("%s%d%f",e.name,&e.phonenumber,e.morh);
							fseek(fp,-recsize,SEEK_CUR);
							fwrite(&e,recsize,1,fp);
							break;
						}
					}	
				
				printf("\nModify another Record(Y/N) \t");
				fflush(stdin);
				another=getche();
				}
				
				break;
			
			
			
			
			
			//Code to delete record
			
			
			case '4':
			another ='Y';
			while(another =='Y')
			{		
				printf("\nEnter conctact to delete \t");
				scanf("%s",phonename);
				
				ft=fopen("TEMP.txt","wb");
				
				rewind(fp);
				
				
				
				while(fread(&e,recsize,1,fp)==1)
				{
					if(strcmp(e.name,phonename)!=0)
					 fwrite(&e,recsize,1,ft);
				}
				
				
				fclose(fp);
				fclose(ft);
				remove("phonebook.txt");
				rename("TEMP.txt","phonebook.txt");
				
				fp=fopen("phone.txt","r");
			
				
				printf("Delete another Record(Y/N)");
				fflush(stdin);
				another=getche();
			}
			break;
		
		
		
			case'0':
				fclose(fp);
				exit(0);
		}
	}
	
	
	
	return 0;
}	
		

