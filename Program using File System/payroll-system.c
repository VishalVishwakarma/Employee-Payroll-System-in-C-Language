#include <stdio.h>
#include <conio.h>
#include <string.h>

struct emp
{
int id;
char name[20];
int basic, hra, da, ma;
int pf, insurance;
float gross, net;
};

void append();
void display();
void displayAll();
void modify();
void search();

char fname[]={"C:\\payroll-system-db.txt"};

int main()
{
int ch;

while(1)
{
      //clrscr();

      printf("==================Employee Payroll System=============\n\n");

      printf("1. Show All Records\n\n");
      printf("2. Add New Record\n\n");
      printf("3. Print Salary Slip\n\n");
      printf("4. Update\n\n");
      printf("5. Search\n\n");
      printf("6. Exit\n\n");

      printf("------------------------------------------------------\n\n");

      printf("\nPlease enter your Choice:");
      scanf("%d",&ch);

      if (ch != 6) {
            switch(ch){

                case 1: displayAll();
                break;

                case 2: append();
                break;

                case 3: display();
                break;

                case 4: modify();
                break;

                case 5: search();
                break;

                case 6: //exit();
                break;
            }
            printf("\n Do You Want To Continue(1/0):");
            scanf("%d", &ch);
            printf("\n\n");
        } else {
                ch = 0;
        }

        if (!ch) {
                break;
        }

}
return 0;
}

//Append function ==============================================================
void append()
{
FILE *fp;
struct emp t1;

fp=fopen(fname,"ab");

printf("\nEnter ID:");
scanf("%d",&t1.id);
printf("\nEnter name:");
scanf("%s",t1.name);
printf("\nEnter Basic salary:");
scanf("%d",&t1.basic);
printf("House Rent Allowance:");
scanf("%d",&t1.hra);
printf("Dearness Allowance:");
scanf("%d", &t1.da);
printf("Medical Allowance:");
scanf("%d", &t1.ma);
printf("Enter the deductions:\n");
printf("Provident Fund:");
scanf("%d", &t1.pf);
printf("Insurance:");
scanf("%d", &t1.insurance);
fwrite(&t1,sizeof(t1),1,fp);

fclose(fp);
}
//==============================================================================

// modify function =============================================================
void modify()
{
FILE *fp,*fp1;
struct emp t,t1;
int id,found=0,count=0;

fp=fopen(fname,"rb");
fp1=fopen("temp.dat","wb");

printf("\nEnter the Emp ID you want to Modify:");
scanf("%d",&id);

while(1){

        fread(&t,sizeof(t),1,fp);

        if(feof(fp))
        {
        break;
        }
        if(t.id==id)
        {
        found=1;
        printf("\nEnter Employee ID:");
        scanf("%d",&t.id);

        fflush(stdin);
        printf("\nEnter Employee Name:");
        scanf("%s",t.name);
        printf("\nEnter Basic salary:");
        scanf("%d",&t.basic);
        printf("House Rent Allowance:");
        scanf("%d",&t.hra);
        printf("Dearness Allowance:");
        scanf("%d", &t.da);
        printf("Medical Allowance:");
        scanf("%d", &t.ma);
        printf("Enter the deductions:\n");
        printf("Provident Fund:");
        scanf("%d", &t.pf);
        printf("Insurance:");
        scanf("%d", &t.insurance);
        fwrite(&t,sizeof(t),1,fp1);
        }
        else
        {
        fwrite(&t,sizeof(t),1,fp1);
        }
}

fclose(fp);
fclose(fp1);

if(found==0)
{
printf("Sorry No Record Found\n\n");
}
else
{
fp=fopen(fname,"wb");
fp1=fopen("temp.dat","rb");

while(1){
        fread(&t,sizeof(t),1,fp1);

        if(feof(fp1))
        {
        break;
      }
        fwrite(&t,sizeof(t),1,fp);
}

}
fclose(fp);
fclose(fp1);
}
//==============================================================================

//display function =============================================================
void display()
{
FILE *fp;
struct emp t;
int id,found=0;

fp=fopen(fname,"rb");

printf("\nEnter the Emp ID:");
scanf("%d",&id);

while(1)
{
fread(&t,sizeof(t),1,fp);

if(feof(fp))
{
break;
}
if(t.id==id)
{
found=1;
printf("\n===============================================================\n\n");
printf("\t\t Employee Details of %d\n\n",t.id);
printf("=================================================================\n\n");

printf("Name\tBasic\tHRA\tDA\tMA\tPF\tInsurance\n\n");

printf("%s\t",t.name);
printf("%d\t",t.basic);
printf("%d\t",t.hra);
printf("%d\t",t.da);
printf("%d\t",t.ma);
printf("%d\t",t.pf);
printf("%d\t\n\n",t.insurance);

int gross, net;

gross = t.basic + (t.hra * t.basic) / 100 + (t.da * t.basic) / 100 + (t.ma * t.basic) / 100;
net = gross - (t.pf + t.insurance);

printf("Gross Salary = %d\t\n\n",gross);
printf("Net Salary = %d\t\n\n",net);

printf("=================================================================\n\n");
}
}
if(found==0)
{
printf("\nSorry No Record Found");
}
fclose(fp);
}

void search()
{
FILE *fp;
struct emp t;
int found=0;
char name[20];

fp=fopen(fname,"rb");

printf("\nEnter the Employee Name:");
scanf("%s",&name);

while(1)
{
fread(&t,sizeof(t),1,fp);

if(feof(fp))
{
break;
}
if(strcmp(name,t.name)==0)
{
printf("\n===============================================================\n\n");
printf("\t\t Employee Details of %s\n\n",t.name);
printf("=================================================================\n\n");

printf("Name\tBasic\tHRA\tDA\tMA\tPF\tInsurance\n\n");

printf("%s\t",t.name);
printf("%d\t",t.basic);
printf("%d\t",t.hra);
printf("%d\t",t.da);
printf("%d\t",t.ma);
printf("%d\t",t.pf);
printf("%d\t\n\n",t.insurance);

printf("=================================================================\n\n");
found = 1;

}
}
if(found==0)
{
printf("\nSorry No Record Found");
}
fclose(fp);
}
//==============================================================================

//displayAll function ==========================================================
void displayAll()
{
FILE *fp;
struct emp t;

fp=fopen(fname,"rb");

printf("\n===============================================================\n\n");
printf("\t\t All Employee Details\n\n");
printf("=================================================================\n\n");

printf("ID\tName\tBasic\tHRA\tDA\tMA\tPF\tInsurance\n\n");

while(1)
{
fread(&t,sizeof(t),1,fp);

if(feof(fp))
{
break;
}
printf("%d\t",t.id);
printf("%s\t",t.name);
printf("%d\t",t.basic);
printf("%d\t",t.hra);
printf("%d\t",t.da);
printf("%d\t",t.ma);
printf("%d\t",t.pf);
printf("%d\t\n\n",t.insurance);

}
printf("=================================================================\n\n");

fclose(fp);
}
