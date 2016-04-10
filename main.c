#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <dos.h>




typedef int bool;
#define true 1
#define false 0

struct reg_std{
	char name[20],dob[10],s[2],f_name[20],course[4],bd[10],id[10];
	int year;
}reg_st;

struct admin{
	char ad_name[30];
	char ad_pass[30];
}cd;
struct year_index{
	int year,count;
}yr,gr;


struct student{
	int year;
	char course[4],name[30],id[10];
}st;

const char temp[30],pass[10],*course_code[]={"PEB","EEB","MEB","LEB","PKB","KEB"};
FILE *fp,*FP;	


COORD coord= {0,0};
void gotoxy(int x,int y)
{
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}




void get_password(char password[])
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
    return password;
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
		
		
			
            break;	
		
		
		case 3:
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
            gotoxy(30,24);
            printf("9. Logout");
            
            break;
            
            case 4:
                    print_layout(11);
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
                    break;
	}
	return 0;
	
}


 struct reg_std* search_id(char* id){
	FP=fopen("reg_std.DAT","rb+");
	while(fread(&reg_st,sizeof(reg_st),1,FP)){
		if(!strcmp(id,reg_st.id)){
		fclose(FP);
		return &reg_st;
	}
	}
      fclose(FP);
	return NULL;
}

bool remove_std(char* id){
	int found=0;
	struct reg_std std,*r;
	r=search_id(id);
	if(r!=NULL){
	std=*r;
	FP=fopen("reg_std.DAT","wb");
	fp=fopen("temp.DAT","wb+");
	while(fread(&std,sizeof(std),1,FP)){
		if(strcmp(id,std.id)){
		fwrite(&std,sizeof(std),1,fp);	
	}
	else found=1;	
}fclose(fp);fclose(FP);
remove("reg_std.DAT");
rename("temp.DAT","reg_std.DAT");
}
     if(found)
     return true;
     else
     return false;

}


void add_unstd(){
	char a,b[3],id[10]="";
	print_layout(4);
                    
                    
            	  a=getche();
                    strcpy(st.course,course_code[a-49]);
                    system("cls");
                  
                    gotoxy(30,8);
		        printf("Enter Year");
		        gotoxy(30,10);  
                  	scanf("%d",&st.year);
                    system("cls");
                    gotoxy(30,8);
                    printf("Enter Name Of Student");
                    gotoxy(30,10);
                    scanf("%s",st.name);
                    
            	  FILE *fp,*temp;int found=0;
                 	fp=fopen("year_index.DAT","rb");
	            temp=fopen("tem.DAT","wb+");
	            gr.year=st.year;gr.count=1;
	            while(fread(&yr,sizeof(yr),1,fp))
			{
		           if(yr.year != gr.year){
		           fwrite(&yr,sizeof(yr),1,temp);
	            }
	            else
		      {
	               gr.count=yr.count;
	               found =1;
                  }
	            }
                 	if(found)
	            {
		         gr.count++;
                 	}
            	fwrite(&gr,sizeof(gr),1,temp);
            	fclose(fp);fclose(temp);
	            remove("year_index.DAT");
	           rename("tem.DAT","year_index.DAT");
	           
	           
	           snprintf(b,2,"%d",gr.year%100);
		     strcat(id,b); 
	           strcat(id,st.course);
	           snprintf(b,3,"%d",gr.count);
		     strcat(id,b);
		     strcpy(st.id,id);
	           fp=fopen("un_std.txt","r+");
	           fseek(fp,sizeof(struct student),SEEK_END);
	           fwrite(&st,sizeof(st),1,fp);
	           fclose(fp);
	
	
}

void add_rstd(){
	print_layout(11);
	gotoxy(30,8);  
			printf("Name");
            	  gotoxy(30,10);
            	  printf("DOB(dd-mm-yy)");
            	  gotoxy(30,12);
            	  printf("Sex(M/F)");
            	  gotoxy(30,14);
            	  printf("Father Nmae");
            	  gotoxy(30,16);
            	  printf("Board");
            	  gotoxy(50,8);printf(":");
            	  scanf("%s",reg_st.name);
            	  gets(reg_st.name);
            	  gotoxy(50,10);printf(":");
            	  gets(reg_st.dob);
			  gotoxy(50,12);printf(":");
			  gets(reg_st.s);
            	  gotoxy(50,14);printf(":");
            	  gets(reg_st.f_name);
			  gotoxy(50,16);printf(":");
			  gets(reg_st.bd);
            	  strcpy(reg_st.course,st.course);
            	  reg_st.year=st.year;
            	  strcpy(reg_st.id,st.id);
            	  FP=fopen("reg_std.DAT","rb+");
            	  fseek(FP,sizeof(struct reg_std),SEEK_END);
			  fwrite(&reg_st,sizeof(reg_st),1,FP);
			  fclose(FP);
			  FP=fopen("un_std.txt","rb");
			  fp=fopen("temp.txt","wb+");
			  while(fread(&st,sizeof(st),1,FP)){
			  	if(strcmp(reg_st.id,st.id))
			  	fwrite(&st,sizeof(st),1,fp);
			  }fclose(fp);fclose(FP);
			  remove("un_std.txt");
			  rename("temp.txt","un_std.txt");
            	  
}



int main(){
	char a;int check=0;
	bool match;
	
	
	while(1){
	match=false;	
		
	print_layout(0);
	a=getche();

      switch((int)a-48){
       case 1:
         print_layout(1);
         a=getche();

         switch((int)a-48){  
	   case 1:
	   	break;
	   case 2:
	   	print_layout(11);
         	gotoxy(30,8);	
              printf("Enter ID");
            gotoxy(30,10);  
		scanf("%s",temp);
		gotoxy(30,12);
		printf("Enter Password");
            gotoxy(30,14);
		get_password(pass);
		fp=fopen("un_std.txt","rb");
	        while(fread(&st,sizeof(st),1,fp)){
       		if(!strcmp(temp,st.id) && !strcmp(pass,st.name)){
       		fclose(fp);	
       		 add_rstd();
       		break;	
       			
			 }
       		
	      	match=true;
	      	
      	}
	   
	   
	   
	    
        }
         break;
         case 2:
         	print_layout(11);
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
	      	getche();
       		if(!strcmp(temp,cd.ad_name) && !strcmp(pass,cd.ad_pass))
	      	match=true;
      	}	
	      fclose(fp);
         	
	while(match){
		print_layout(3);
            a=getche();
            
            switch((int)a-48){
            	
            	case 1:
                    add_unstd();
	           
	           
                 	break;	
                 	case 2:
                 		print_layout(11);
                 		gotoxy(30,8);	
                        printf("Enter ID");
                        gotoxy(30,10);  
		            scanf("%s",temp);
                 		if(remove_std(temp)){
				     printf("Removed Successfully");
				     }
				     else {
				     printf("Student Not Removed");
				     }getche();
				     
                 	break;
                 	
                 case 9	:
                 	match=false;
                 	break;
       }
       
       
       
	}
	
}


	}
	return 0;
}
