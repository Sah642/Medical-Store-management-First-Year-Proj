#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<math.h>
#include<dos.h>
#include<time.h>
#include<ctype.h>
#include<windows.h>

COORD coord = {0, 0};
void gotoxy(int x, int y)
{
 COORD coord;
 coord.X = x;
 coord.Y = y;
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void main_menu();
void main_box();
void bill();
void medicine();
void medi_sale();
void stock();
void medi_entry();

int i=0;
int main ()
{
	system("cls");
    main_menu();

}

struct medical
{
	int id;
	char medi_name[20];
	int quantity;
	float sell;
	float total;
	float unit;
	float cost;
	float bye;
	int qty;
	char exp_date[15];
	char manu_date[15];
	int bill_no;
	int billno;
 };

struct medical temp;
struct medical x[20];
FILE *ptr;

FILE *ptr1;


struct bill
{
	int billno;
	char mediname[30];
	int medi_qty;
	float medi_rate;
	float total;
	int day;
	int month;
	int year;

};
struct bill bil;
FILE *ptrbill;

void main_menu()
{
  char ch;

	do
	{
		system("cls");
		gotoxy(4,5);
		printf("1)Medicine");
		gotoxy(20,5);
		printf("2)Billing");
		gotoxy(50,5);
		printf("3)Exit");
 
		main_box();
		gotoxy(30,10);
		printf("Welcome To Medical Store ");
	
		gotoxy(10,25);
		printf("Press First Character for further Menu  ");
int c;

        scanf("%d",&c); 
		switch(c)
		{

			case 1:medicine();
				 break;
			case 2:bill();
				 break;
			case 3:gotoxy(23,20);
			printf("Do you want to exit? Y(1)/N(0):");
			Sleep(100);

            int c1;
             scanf("%d",&c1);
			if(c1==1)
			{
				system("cls");
				gotoxy(35,20);
				printf(" Please wait.....");
				Sleep(2000);
				exit(0);
			}
			else
			{
				main_menu();
			}

		}
	}while(ch!=3);
}

void main_box()
{
	int i;
	gotoxy(1,6);
	printf("%c",201);
	for(i=1;i<79;i++)
	{
		gotoxy(1+i,6);
		printf("%c",205);
	}
	gotoxy(80,6);
	printf("%c",187);
	gotoxy(1,6);
	for(i=5;i<30;i++)
	{
		gotoxy(1,2+i);
		printf("%c",186);
	}
	gotoxy(1,32);
	printf("%c",200);
	for(i=1;i<79;i++)
	{
		gotoxy(1+i,32);
		printf("%c",205);
	}
	gotoxy(80,32);
	printf("%c",188);
	gotoxy(80,6);
	for(i=5;i<30;i++)
	{
		gotoxy(80,2+i);
		printf("%c",186);
	}
}

//=========================For Medicine ===========================
void medicine()
{
	char ch;
	int c;
	do
	{
	  system("cls");

	  gotoxy(34,3);
	 
	  printf("---------------");
	  gotoxy(35,4);
	  printf("Medicine Menu.");
	  gotoxy(34,5);
	  printf("---------------");
	  gotoxy(25,15);
	
	  printf("1]Purchase New Medicine");
      gotoxy(25,17);
	  printf("2]Sell Medicine");
      gotoxy(25,19);
	  printf("3]Stock of Medicine");
     gotoxy(25,23);
	  printf("4]Main Menu");
	  main_box();

	  gotoxy(10,40);
	  
	  printf("Press First Character for further Operations  ");



scanf("%d",&c);
	  switch(c)
	  {
		case 1:medi_entry();
			 break;
		case 2:medi_sale();
			 break;
		case 3:stock();
			 break;
		case 4:main_menu();
			 break;
		default:
			gotoxy(11,34);
			printf("Plese Enter right character ONLY (1,2,3,4).");
			getch();
	  }
	}while(c!=4);

}
//========================for bill =============================
void bill()
{

    time_t td = time(0);   
    struct tm * now = localtime( & td );

	   FILE *ptrbill;
	   int id=0;
	   int j=1,d1,m,y,k,c=0;
	   float netamt=0.0;
	   
	   d1=now->tm_mday;
	   m=now->tm_mon;
	   y=now->tm_year;
	   system("cls");
	   ptrbill=fopen("dbbill.dat","r");
	   gotoxy(13,4);
	   printf("Enter bill no : ");
	   scanf("%d",&id);
	   system("cls");
	   gotoxy(25,3);
	   printf("***** 24 Hour medic *****");
	   gotoxy(7,7);
	   printf("Bill No: ");
	   printf("%d",id);
	   gotoxy(50,7);
	   printf("Date : ");
	   printf("%d-%d-%d",d1,m,y);
	   gotoxy(7,12);
	   printf("Sr.No   Medicine Name       Qty          Rate         Total ");
	   gotoxy(6,14);
	   printf("---------------------------------------------------------------------");

	   int i=15;
	   while(fscanf(ptrbill,"%d %s %d %f %f %d %d %d",&bil.billno,bil.mediname,&bil.medi_qty,&bil.medi_rate,&bil.total,&bil.day,&bil.month,&bil.year)!=EOF)
	   {

		       do
		       {
			if(id==bil.billno)
			{
				gotoxy(7,i);
				printf(" %d",j);
				gotoxy(14,i);
				printf(" %s",bil.mediname);
				gotoxy(35,i);
				printf(" %d",bil.medi_qty);
				gotoxy(47,i);
				printf(" %.2f",bil.medi_rate);
				gotoxy(60,i);
				printf(" %.2f",bil.total);
				netamt=netamt+bil.total;
				i++;
				j++;
				gotoxy(35,32);
				printf("                                ");
				gotoxy(20,50);
			
				printf("Press (1) key to go to  MENU ...........");
			}
		}while(feof(ptrbill));
	   }


	   gotoxy(6,35);
	   printf("---------------------------------------------------------------------");
	   gotoxy(50,37);
	   printf("Net Amount : ");
	   printf("%.2f",netamt);

	   fclose(ptrbill);
	   getch();
}

void medi_entry()
{
  char ch;
  int c;
  int ids;
  int f;
  FILE *fp;
  system("cls");

	 
	   ch='Y';
	  while(ch=='Y')
	  {
		system("cls");
		gotoxy(30,8);
		printf(" MEDICINE PURSHASE  ");
		
			gotoxy(7,11);
			printf("MEDICINE ID    : ");
			gotoxy(40,11);
			printf("MEDICINE NAME  : ");
			gotoxy(7,21);
			printf("UNIT COST   Rs.:  ");
			gotoxy(40,21);
			printf("Sell COST   Rs.: ");
			gotoxy(7,24);
			printf("QUANTITY       :  ");
			gotoxy(7,27);
			printf("MFG.DATE(dd-mm-yyyy): ");
			gotoxy(7,29);
			printf("EXP.DATE(dd-mm-yyyy): ");
			int flag=0;
			//////////////
			gotoxy(25,11);
			scanf("%d",&ids);
//			ptr1=fopen("medical.dat","r");
//			while((fread(&temp,sizeof(temp),1,ptr1))==1){
//				if(temp.id==id)
//				{
//					
//					printf("id already exist");
//					flag=1;
//					getch();
//					break;
//				}
//			}
//			fclose(ptr1);
			if(flag==0){
				
			ptr=fopen("medical.dat","a+b");
			
            temp.id=ids;
			gotoxy(58,11);
			scanf("%s",temp.medi_name);
			gotoxy(25,21);
			scanf("%f",&temp.unit);
			gotoxy(58,21);
			scanf("%f",&temp.sell);
			gotoxy(25,24);
			scanf("%d",&temp.quantity);
			gotoxy(29,27);
            scanf("%s",temp.manu_date);
			gotoxy(29,29);
            scanf("%s",temp.exp_date);
			gotoxy(7,31);
			printf("==========================================================");
			temp.total=temp.quantity*(temp.sell);
			gotoxy(10,33);
			printf("TOTAL SALE COST = Rs. %.2f",temp.total);
			temp.cost=(temp.unit*temp.quantity);
			gotoxy(40,33);
			printf("TOTAL UNIT COST = Rs. %.2f",temp.cost);
		 
		gotoxy(20,35);
		gotoxy(21,35);
		printf("1]Save");
		gotoxy(28,35);
		printf("2]Cancel");
		gotoxy(18,38);
		printf("Press First charecter for the operation : ");
		scanf("%d",&c);
		if(c==1)
		{ 
			fwrite(&temp,sizeof(temp),1,ptr);
			fflush(stdin);
			system("cls");
			gotoxy(20,20);
			printf("Medicine Added sucessfully!!!!!!");
				gotoxy(20,25);
			printf("More entries  [y/n]");
			ch=toupper(getche());
//		       	if(ch=='Y')
//			{
//				system("cls");
//				medi_entry();
//		}
//		else{
//           getch();
//			main_menu();
//		}

}
	   

}
}
fclose(ptr);
}
//===========FOR MEDICINE SALE=========================
void medi_sale()
{
  struct bill bil;
  time_t t = time(0);   // get time now
    struct tm * now = localtime( & t );
  int j,n,i,a,billno;
  int d1,m,y;
  float netamt;
  netamt=0.0;
  float b,total,rate;
  char ch,mediname[30],c_name[30],cname[30];
  FILE *fp,*fpc;
  int count=0;
  d1=now->tm_mday;
  m=now->tm_mon;
  y=now->tm_year;
	   ch='y';
	   while(ch=='y')
	   {
		fp = fopen("dbbill.dat","a+");
		
		system("cls");

		gotoxy(52,7);
		printf("med_ID    med_Name   qty_avail.");
//		fscanf(ptr,"%d %s",&temp.id,temp.medi_name);
		int l=9;
		ptr1 = fopen("medical.dat","r");
		while((fread(&temp,sizeof(temp),1,ptr1))==1)
		{
			gotoxy(53,l);
			printf("%d",temp.id);
			gotoxy(64,l);
			printf("%s",temp.medi_name);
			gotoxy(75,l);
			printf("%d",temp.quantity);
			l++;
		}
fclose(ptr1);
ptr = fopen("medical.dat","r");
		gotoxy(9,7);
		printf("ENTER MEDICINE ID TO BE SOLD  : ");
	    int tar;
		scanf("%d",&tar);
		j=0;
		
		while((fread(&temp,sizeof(temp),1,ptr))==1)
		{
			if(temp.id!=tar)
			{
				x[j] = temp;
				j++;
			
			}

          else if(temp.id==tar)
			{

				gotoxy(8,10);
				printf(" Medicine Name        : %s",temp.medi_name);
				gotoxy(8,12);
				printf(" Quantity in stock    : %d",temp.quantity);
				gotoxy(8,14);
				printf(" Sales price          : %.2f",temp.sell);
				gotoxy(8,16);
				printf("bill number     : ");
				

				scanf("%s",&bil.billno);
				gotoxy(8,20);
				printf("Quantity want to sale : ");
				
				scanf("%d",&a);
				x[j]=temp;
				x[j].quantity=(x[j].quantity-a);
				x[j].total=(x[j].quantity*temp.sell);
				x[j].cost=(x[j].quantity*temp.unit);
				x[j].bye=(x[j].sell*a);
				b=x[j].bye;
				x[j].qty=a;
				j++;
				count++;
				strcpy(bil.mediname,temp.medi_name);
				bil.medi_qty=a;
				bil.medi_rate=temp.sell;
				bil.total=temp.sell*a;
				bil.day=d1;
				bil.month=m;
				bil.year=y;

				fprintf(fp,"%d %s %d %.2f %.2f %d %d %d\n",bil.billno-48,bil.mediname,bil.medi_qty,bil.medi_rate,bil.total,bil.day,bil.month,bil.year);
				fflush(stdin);

				fclose(fp);
                 fflush(stdin);

			}
		}
		if (count==0)
		{
			system("cls");
			gotoxy(33,10);
			printf("Not in stock!!!!!");
			getch();
			return;
		}
		
		fclose(ptr);
		n = j;
		system("cls");
		ptr=fopen("medical.dat","wb");
		for(i=0; i<n; i++)
		fwrite(&x[i],sizeof(x[i]),1,ptr);
		fclose(ptr);
		system("cls");
//		box();
		gotoxy(8,15);
		printf("* Price paid by customer = %.2f",b);
		gotoxy(8,17);
		printf("* Quantity sold          = %d",a);
		getch();
		gotoxy(10,20);
		printf("more enteries=(y/n) :");
		ch=getche();
		
	}

		
	   }


//===========================MEDICINE STOCK=====================================
void stock()
{
  char ch;
  int i,c;
	   do
	   {
		system("cls");
		ptr1=fopen("medical.dat","r");
		if(ptr1==NULL)
		{
			printf("\n\t Can not open File! ");
			exit(1);
		}
		system("cls");
//		box();
//		lbox();
		
		gotoxy(30,8);
		
		printf(" STOCK OF MEDICINE ");
		
		i=14;
		gotoxy(9,10);
		printf("ID.   MEDICINE NAME.    QTY      Exp.Date");
		gotoxy(9,12);
		printf("==================================================================\n");

		while((fread(&temp,sizeof(temp),1,ptr1)==1))
		{
			
			gotoxy(9,i);
			printf("%d",temp.id);
			gotoxy(15,i);
			printf("%s",temp.medi_name);
			gotoxy(32,i);
			printf("%d",temp.quantity);
			gotoxy(60,i);
			printf("%s",temp.exp_date);
			i++;
			
			
		}
		gotoxy(10,42);
		printf(" [0] for main menu ");
		c = (getche());
		switch (c)
		{
			case '0':
				 main_menu();
				 break;
			
		}

	   }while(c != '1');
	   getche();
}



