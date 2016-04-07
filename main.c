#include<stdio.h>
#include<windows.h>


struct admin{
	char ad_name[30];
	char ad_pass[30];
}cd;
struct year_index{
	int year,count;
}yr;


struct student{
	int year;
	char *course,name[30];
}st;

const char temp[30],pass[30],*course_code[]={"PEB","EEB","MEB","LEB","PKB","KEB"};
FILE *fp,*FP;	


COORD coord= {0,0};
void gotoxy(int x,int y)
{
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}




void get_password(char* password)
{
    char p_char;
    int pass_index;
    p_char=getche();
    pass_index=0;
    while(p_char!=13)
    {
        if(p_char==8)
        {
            if(pass_index>0)
            {
                printf(" \b");
                pass_index--;
            }
            else printf(" ");
        }
        else
        {
            printf("\b*");
            password[pass_index]=p_char;
            pass_index++;
        }
        p_char=getche();
    }
    password[pass_index]='\0';
}
int print_layout(int disp)
{
		system("cls");	
		gotoxy(0,1);
		 printf("================================================================================");
            printf("\t\t\t   Student Enrollment System");
            printf("\n________________________________________________________________________________");
           
	switch(disp){
		
		
		case 0:
            gotoxy(30,8);
            printf("1. Student Login");
            gotoxy(30,10);
            printf("2. Admin Login");
            gotoxy(30,12);
            printf("3. Exit");
            break;
            
            
            
            case 1:
            gotoxy(30,8);
		printf("1. Sign In");
            gotoxy(30,10);
            printf("2. Sign Up");
            gotoxy(30,12);
            printf("3. Back TO Main Menu");
            break;
		
		
		case 2:
		
		
		gotoxy(30,8);	
              printf("Enter Name");
            gotoxy(30,10);  
		scanf("%s",temp);
		gotoxy(30,12);
		printf("Enter Password");
            gotoxy(30,14);
		get_password(pass);
		fp=fopen("adm.co","rb");
	        while(fread(&cd,sizeof(cd),1,fp)){
       		if(!strcmp(temp,cd.ad_name) && !strcmp(pass,cd.ad_pass))
	      	return 1;
      	}	
	       fclose(fp);	
            break;	
		
			
	}
	return 0;
	
}








int main(){
	char a;int check=0;
	
	
	
	while(1){
	print_layout(0);
	a=getche();

      switch((int)a-48){
       case 1:
         print_layout(1);
         
         break;
         case 2:
	if(print_layout(2)){
		system("cls");
		gotoxy(0,1);
		printf("================================================================================");
            printf("\t\t\t   Student Enrollment System");
            printf("\n________________________________________________________________________________");
            gotoxy(30,8);
		printf("1. Add Student");
            gotoxy(30,10);
            printf("2. Remove Student");
            gotoxy(30,12);
            printf("3. Add Admin");
            gotoxy(30,14);
            printf("4. Remove Admin");
            gotoxy(30,16);
            printf("5. View Pending Approval");
            gotoxy(30,18);
            printf("6. View Checked Approval");
            gotoxy(30,20);
            printf("7. View List Of Student");
            gotoxy(30,22);
            printf("8. View Log");
            
            
            a=getche();
            
            switch((int)a-48){
            	
            	case 1:ak
                  	system("cls");
		        gotoxy(0,1);
		        printf("================================================================================");
                    printf("\t\t\t   Student Enrollment System");
                    printf("\n________________________________________________________________________________");
                    gotoxy(30,8);
		        printf("Enter Year");
		        gotoxy(30,10);  
                  	scanf("%d",&st.year);
                    system("cls");
                    print_layout(4);
            	  gotoxy(30,8);
			  printf("Select Course");
            	  gotoxy(30,10);
            	  printf("1. Computer");
            	  gotoxy(30,12);
            	  printf("2. Electrical");
            	  gotoxy(30,14);
            	  printf("3. Mechnical");
            	  gotoxy(30,16);
            	  printf("4. Electronics");
            	  gotoxy(30,18);
            	  printf("5. Petrochemical");
            	  gotoxy(30,20);
            	  printf("6. Chemical");
            	  a=getche();
            	  st.course=course_code[a-49];
                    system("cls");
                    print_layout(4);
                    gotoxy(30,8);
                    printf("Enter Name Of Student");
                    gotoxy(30,10);
                    scanf("%s",st.name);
                    
            	  FP=fopen("year_index.DAT","wb+");
            	  if(FP==NULL)
            	  printf("fuck");
            	  //rewind(fp);
			  while(fread(&yr,sizeof(yr),1,FP)){
			  	printf("found");
            	  	if(st.year==2012){
            	  		yr.count++;
            	  	      check=1;	
            	  	      printf("found");
				  }	  
			  }	
			  if(check==0){
			  	yr.count=1;
			  	yr.year=st.year;
			  	fwrite(&yr,sizeof(yr),1,fp);
			  	printf("check");
			  	
			  }
			  fclose(fp);
            	
		}
            
            
	}
	
}
break;

	}
	return 0;
}
