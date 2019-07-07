#include <stdio.h>
#include <stdlib.h>

// employee database


//Global variables

typedef struct empl_record
{
	char empl_first_name[10];
	char empl_middl_name[10];
	char empl_last_name[10];
	char empl_ss_no[11];
	char empl_birth_dt[10];
	char empl_marital_stat;
	int  empl_number;
	char empl_title[10];
	char empl_hiring_dt[10];
	int  empl_currnt_salary;
	int  dept_no;
} EMPL_STRUCT;

	EMPL_STRUCT empl_db[50];
   // employee database is an array of EMPL_STRUCT's
   
	int empl_total=0;
	int empl_number;
	int db_index, idx = 0;
	
	//initialize the header
	
	char *header1="\n \t	DAVES Computers, Inc.";
	char *header2="\n \t\t  Employee Database ";
	
	//Initialize the menu
	
	char *menu1 = "\n\n\t Add an employee		     ....1";
	char *menu2 = "\n\t Delete an employee                  ....2";
	char *menu3 = "\n\t Modify an employee                  ....3";
	char *menu4 = "\n\t Display an employee                 ....4";
	char *menu5 = "\n\t Exit               		     ....5";
	

int print_menu_hdr(char *header)
{

        system("clear");
        printf("\n\t\t\t*****************************************************\n");
        printf("\t\t\t\t EMPLOYEE %s MENU \n", header);
        printf("\t\t\t*****************************************************\n");
}
                                


//display menu function
int display_menu()
{
	system("clear");
	printf(header1);
	printf(header2);
	printf(menu1);
	printf(menu2);
	printf(menu3);
	printf(menu4);
	printf(menu5);
}

//search for an employee

int search_empl()
{
	int i;
	
	for(i=0;i<empl_total;i++)
	{
		if(empl_number == empl_db[i].empl_number);
		return(i);
	}
	
	printf("\n\n Search failed: No match found \n\n");
	return -1;

}


//add employee

int add_empl()
{
	print_menu_hdr("ADD");
	
	printf("\nEnter Employee's First name:   ");
	scanf("%s", &empl_db[idx].empl_first_name);
	
	printf("\nEnter Employee's Middle  name:   ");
	scanf("%s", &empl_db[idx].empl_middl_name);
	        
	printf("\nEnter Employee's Last name:   ");
	scanf("%s", &empl_db[idx].empl_last_name);
	        
	printf("\nEnter Employee's Social Security Number:   ");
	scanf("%s", &empl_db[idx].empl_ss_no);
	        
	printf("\nEnter Employee's Birthdate:   ");
	scanf("%s", &empl_db[idx].empl_birth_dt);
	        
	printf("\nEnter Employee's Marital Status:   ");
	scanf("%s", &empl_db[idx].empl_marital_stat);
	        
	printf("\nEnter Employee's Number:   ");
	scanf("%d", &empl_db[idx].empl_number);
	        
	printf("\nEnter Employee's Hiring Date:   ");
	scanf("%s", &empl_db[idx].empl_hiring_dt);
	        
	printf("\nEnter Employee's Current Salary:   ");
	scanf("%d", &empl_db[idx].empl_currnt_salary);
	        
	printf("\nEnter Employee's Department Number:   ");
	scanf("%d", &empl_db[idx].dept_no);
	        
	printf("\nEnter Employee's Title:   ");
	scanf("%s", &empl_db[idx].empl_title);
	        
	        
	idx++;			//increment the index 
	empl_total=idx;		//set a new total number of employess index

}


//Delete an employee

int delete_empl()
{
	print_menu_hdr("DELETE");
	printf("\n Menu2: Delete is not implemented.");


}


//modify an employee

int modify_empl()
{

	print_menu_hdr("MODIFY");
	printf("\n Menu3: Modify is not implemented.");
}

//search and display an employee

int srch_display_empl()
{

	int db_index;	//assigned if search succeeds
	char c;
	
	print_menu_hdr("DISPLAY");
	printf("\n\n Enter employee number:  ");
	scanf("%d", &empl_number);
	
	db_index=search_empl(empl_number);
	if(db_index == -1)
	{
		printf("\n display_empl: ERROR: Employee is not in database.");
		return(0);
	}
	
	//Do display
	
	printf("\n\nFor Employee number:   %d", empl_db[db_index].empl_number);
	printf("\n Employee's First name:   		%s", empl_db[db_index].empl_first_name);
	printf("\n Employee's Middle name:   		%s", empl_db[db_index].empl_middl_name);
	printf("\n Employee's Last name:   		%s", empl_db[db_index].empl_last_name);
	printf("\n Employee's Social Security Number:   %s", empl_db[db_index].empl_ss_no);
	printf("\n Employee's Birthdate:   		%s", empl_db[db_index].empl_birth_dt);
	printf("\n Employee's Marital Status:   	%c", empl_db[db_index].empl_marital_stat);
	printf("\n Employee's Hiring Date:   		%s", empl_db[db_index].empl_hiring_dt);
	printf("\n Employee's Current Salary:   	%d", empl_db[db_index].empl_currnt_salary);
	printf("\n Employee's Department number:   	%d", empl_db[db_index].dept_no);
	printf("\n Employee's Job Title:   		%s", empl_db[db_index].empl_title);
	
	printf("\n\nHit y to continue...  ");
	
	while( (c=getchar()) != 'y');
	
	
}


// Quit database

int quit_db()
{

	printf("Exiting from Employee Database......\n\n");
	system("clear");
	exit(0);

}


//process menu choice

int process_choice()
{
        int choice;
        
        do{
              printf("\n\n Enter your choice (1-5):  ");
              scanf("%d", &choice);
                                               
              }while(choice < 1 || choice > 5);
                                                                
        switch(choice)
        {
              case 1:
                      add_empl();  //add an employee into the database
                      break;
              case 2:
                      delete_empl();
                      break;
              case 3:
                      modify_empl();
                      break;
              case 4:
                      srch_display_empl();
                      break;
              case 5:
              default:
                      quit_db();
         }
}



	
	//main() -- Employee Database
	
int main()
{
	int forever = 1;
	
	while(forever)
	{
		display_menu();
		process_choice();
	}

}
	
	
	
	
	
