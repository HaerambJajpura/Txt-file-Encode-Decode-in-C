#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int pin=3;// the number by which characters will be shifted forward or backward
int MainScreen()
{
	int choice;
	system("cls");
	printf("------This is file Encoder-Decoder Program------\n\n");
	printf("It can only be used for text based files and not for any other type\n");
	printf("It can only decode the files which are encoded by this.\n");
	printf("which operation would you like to perform\n");
	printf("1. Encode\n");
	printf("2. Decode\n");
	printf("3. Exit From program\n");
	printf("Enter your choice(1/2): ");
	scanf("%d",&choice);
	return choice;
}
void enc_dec(int flag)
{
	char ch;
    char file_name[100],changed_file_name[100],first_name[100];
    char suffix1[20]="_encoded.txt";
    char suffix0[20]="_decoded.txt";
    int length,i,j;
    FILE *fp,*fp2;
    if(flag==1)
    {
    	printf("Enter a file name to encode it and do not put spaces in file names: ");
    }
    if(flag==0)
    {
    	printf("Enter a file name to decode it and do not put spaces in file names: ");
    }
    scanf("%s",file_name);
    printf("File name was: %s\n",file_name);
    fp=fopen(file_name,"r");
    suffix1[strcspn(suffix1, "\n")] = '\0';  // Remove the trailing newline character
    suffix0[strcspn(suffix0, "\n")] = '\0';
    
	for(length=0;file_name[length]!='.';length++);
    printf("The length of file name is : %d\n",length);
    for(i=0;i<length;i++)
    {
        first_name[i]=file_name[i];
    }
    first_name[strcspn(first_name, "\n")] = '\0';
	strcpy(changed_file_name,first_name);
	if(flag==1)
	{
		strcat(changed_file_name,suffix1);
	}
	if(flag==0)
	{
		strcat(changed_file_name,suffix0);
	}
	
	if(flag==1)
	{
		printf("encoded file name is %s\n",changed_file_name);
	}
    if(flag==0)
    {
    	printf("decoded file name is %s\n",changed_file_name);
    }
    fp2=fopen(changed_file_name,"w");
    ch=getc(fp);
    while(ch!=eof(fp))
    {
        printf("%c",ch);
        if(flag==1)
        {
        	putc(ch+pin,fp2);
        }
        if(flag==0)
        {
        	putc(ch-pin,fp2);
        }
        ch=getc(fp);
    }
    fclose(fp);
    fclose(fp2);
}
void execute_operation(int choice)
{
	if(choice==1)
	{
		//encode 1
		printf("--- Encode ---\n\n");
		enc_dec(1);
		system("pause");
	}
	if(choice==2)
	{
		//decode 0
		printf("--- decode ---\n\n");
		enc_dec(0);
		system("pause");
	}
	if(choice==3)
	{
		exit(0);
	}
}
void main()
{
	int choice;
	while(1)
	{
		choice=MainScreen();
   		execute_operation(choice);
	}
}
