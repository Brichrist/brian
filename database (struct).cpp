#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

void clrscr(){system("@cls||clear");}

struct data{
	char nama[30];
	char alamat[30];
	char kota[30];
	char no[30];
	struct data *lanjut;
	struct data *balek;
};

struct data *start=NULL;
struct data *tail=NULL;
int count=0;

void baru(){
	
	char name[30];
	char address[30];
	char city[30];
	char number[30];
	
	struct data *new_node;
	struct data *ptr;
	
	new_node=(struct data*)malloc(sizeof(struct data));
	
	ptr=start;
	
	do{
		printf("Input Company Name [5..30] :");
		scanf("%s", &name);
	}while(strlen(name)<5||strlen(name)>30);
	
	do{
		printf("Input Address [5..50] :");
		scanf("%s", &address);
	}while(strlen(address)<5||strlen(address)>50);
	
	do{
		printf("Input City [5..30] :");
		scanf("%s", &city);
	}while(strlen(city)<5||strlen(city)>30);
	
		printf("Input Phone Number :");
		scanf("%s", &number);
		
	strcpy(new_node->nama,name); 
	strcpy(new_node->alamat,address);
	strcpy(new_node->kota,city);
	strcpy(new_node->no,number);
	
	new_node->lanjut=NULL;
	
	if(start==NULL){
		new_node->balek=NULL;
		start=new_node;
		tail=new_node;
		count++;
		return;
	}
	else{
		while(ptr->lanjut!=NULL){
		ptr=ptr->lanjut;
		}
		
		ptr->lanjut=new_node;
		new_node->balek=ptr;
		tail=new_node;
		count++;
		
	return;
}
}

void print(){
	
	struct data *ptr;
	int pilih;
	printf("1. end to first\n");
	printf("2. first to end\n");
	do{
		printf("\n>> Choice : ");
		scanf("%d",&pilih);
	}while((pilih<1)||(pilih>2));
	
	if(pilih==1){
		ptr=start;
		printf("                           --- DATABASE CUSTOMER ---\n\n");
		printf("+-----+------------------+-----------------------+-----------------+----------------+\n");
		printf("| No. | Company Name     | Address               | City            | Phone Number   |\n");
		printf("+-----+------------------+-----------------------+-----------------+----------------+\n");
		if(count==0){
		}else{
			int i=1;
			while(ptr->lanjut!=NULL){
				printf("| %2i. | %16s | %21s | %15s | %14s |\n",i,ptr->nama,ptr->alamat,ptr->kota,ptr->no);
				ptr=ptr->lanjut;
				i++;
			}
			printf("| %2i. | %16s | %21s | %15s | %14s |\n",i,ptr->nama,ptr->alamat,ptr->kota,ptr->no);
		}
	}else{
		ptr=tail;
		printf("                           --- DATABASE CUSTOMER ---\n\n");
		printf("+-----+------------------+-----------------------+-----------------+----------------+\n");
		printf("| No. | Company Name     | Address               | City            | Phone Number   |\n");
		printf("+-----+------------------+-----------------------+-----------------+----------------+\n");
		if(count==0){
		}else{
			int i=1;
			while(ptr->balek!=NULL){
				printf("| %2i. | %16s | %21s | %15s | %14s |\n",i,ptr->nama,ptr->alamat,ptr->kota,ptr->no);
				ptr=ptr->balek;
				i++;
			}
			printf("| %2i. | %16s | %21s | %15s | %14s |\n",i,ptr->nama,ptr->alamat,ptr->kota,ptr->no);
		}
	}
	printf("+-----+------------------+-----------------------+-----------------+----------------+\n");
	getch();
}

int main(){
	
int input;

clrscr();

	do{
	printf("Database \n.........................\n\n1. View Customer Database\n2. Add New Customer\n3. Exit\n\n");
	do{
	printf(" Input Your Choice :");
	scanf("%d", &input);
	}while (input<1||input>3);
	
switch(input){
		case 1:{
			clrscr();
			print();
			getch();
			break;
		}
		case 2:{
			clrscr();
			baru();
			getch();
			break;
		}
	}
}while(input!=3);
}

















