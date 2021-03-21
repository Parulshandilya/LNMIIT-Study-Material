#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct employee{
	char eid[20];
	char fname[20];
	char lname[20];
	char gen[10];
	char dob[20];
	int age;
	char mobile[20];
	char email[50];
	char jdate[10];
	float salary;
	char dept[20];
};

typedef struct employee employee;

void display_employee_details();
int main(){

	
	employee e1 = {"sarthak891", "Sarthak", "Saxena", "Male", "09-01-1996", 20, "9462767891", "sarthaksaxena09@gmail.com", "09-01-2015", 50000,"PR"};
	employee e2 = {"karan615", "Karan", "Tatiwala", "Male", "25-09-1996", 20, "9680848615", "karantatiwala25@gmail.com", "25-09-2015", 120000,"TECH"};
	employee e3 = {"sumit852", "Sumit", "Madhwani", "Male", "02-09-1996", 20, "8619511852", "sumitmadhwani96@gmail.com", "02-09-2015", 120000,"TECH"};
	employee e4 = {"harshit205", "Harshit", "Bishnoi", "Male", "09-09-1996", 20, "9414791205", "harshit.bishnoi96@gmail.com", "09-09-2015", 70000,"HR"};
	employee e5 = {"shubham152", "Shubham", "Kothari", "Male", "08-06-1997", 19, "9828787152", "shubhamkothari08@gmail.com", "08-06-2015", 120000,"TECH"};
	employee e6 = {"yash194", "Yash", "Soni", "Male", "15-02-1996", 20, "9468797194", "yashsoni15@gmail.com", "15-02-2015", 50000,"PR"};
	employee e7 = {"akshay920", "Akshay", "Maheshwari", "Male", "09-05-1997", 19, "8769257920", "akshaymaheshwari09@gmail.com", "09-05-2015", 120000,"TECH"};
	employee e8 = {"naman153", "Naman", "Khandelwal", "Male", "20-12-1996", 20, "8696124153", "namankhandelwal20@gmail.com", "20-12-2015", 70000,"HR"};
	employee e9 = {"abhishek590", "Abhishek", "Mantri", "Male", "26-08-1996", 20, "9602055590", "ahbishekmantri26@gmail.com", "26-08-2015", 70000,"HR"};
	employee e10 = {"priyansh567", "Priyansh", "Jain", "Male", "13-11-1996", 20, "8291234567", "priyanshjain13@gmail.com", "13-11-2015", 50000,"PR"};

	FILE* f1;
	f1 = fopen("employee_details.dat", "w");
	int s = sizeof(employee);
	fwrite(&e1, s, 1, f1);
	fwrite(&e2, s, 1, f1);
	fwrite(&e3, s, 1, f1);
	fwrite(&e4, s, 1, f1);
	fwrite(&e5, s, 1, f1);
	fwrite(&e6, s, 1, f1);
	fwrite(&e7, s, 1, f1);
	fwrite(&e8, s, 1, f1);
	fwrite(&e9, s, 1, f1);
	fwrite(&e10, s, 1, f1);		
	fclose(f1);
	display_employee_details();

	return 0;
}

void display_employee_details(){

	printf("\nenter the employee id to see the details\n");
	char s[20];
	scanf("%s", s);
	FILE* f;
	employee e;
	f = fopen("employee_details.dat", "r");

	if(f == NULL){
		printf("Error opening file. Please make sure file exists.");
		exit(1);
	}
	
	while(fread(&e, sizeof(employee), 1, f)){
		if(strcmp(e.eid, s) == 0){
			printf("first name = %s\nlast name = %s\ngender = %s\nDate of birth = %s\nage = %d\n", e.fname, e.lname, e.gen, e.dob, e.age);
			printf("mobile = %s\nemail = %s\njoining date = %s\nsalary = %.2f\ndepartment = %s\n", e.mobile, e.email, e.jdate, e.salary, e.dept);
			break;
		}
		
	}
}