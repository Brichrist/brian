#include <iostream>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <ctime>


using namespace std;

int index=0;
char nama[10][10];
int jk[10];
int n;

void swap (int *a, int *b){       // membantu tugas sort angka
   int temp = *a;
   *a = *b; *b=temp;}
   
void swapstr(char *arrA, char *arrB)       // membantu tugas sort kata
{
  char temp[1][1000];
  strcpy(temp[0], arrA);
  strcpy(arrA, arrB);
  strcpy(arrB, temp[0]);
}
   
void bubble()                          // sort angka
{
		int i, j;
		for(i=0; i<index; i++)
			for(j=index-1; j>=i; j--)
				if(jk[j-1] > jk[j]){
	             swap(&jk[j-1],&jk[j]);
	             swapstr(nama[j-1],nama[j]);
}
}

void sort(){ 				// sort kata
for(int i=0;i<index;i++){
 
            int j,bd;
            j=i;
            for(int k=i+1;k<index;k++)
            {
                    bd=strcmp(nama[j],nama[k]);
                    if(bd==1) j=k;       
                    }
                                if(j!=i){
                             char temp[1][30];
                             int tem[1];
                             strcpy(temp[0],nama[j]);
                             tem[0]=jk[j];
                             strcpy(nama[j],nama[i]);
                             jk[j]=jk[i];
                             strcpy(nama[i],temp[0]);
							 jk[i]=tem[0];}
                    }

}



int linearSearch(char f[10]) {          // search untuk menemukan pemenang turnamen apa ada yang sama/tdk

	for (n=0; n<index; n++){	
		if (strcmp(nama[n],f)==0){
			return n;
		}	
	}
	return -1;
}




void load()  		// load
{
	FILE *pt;
	pt = fopen("soal08.txt","r");
	while(fscanf(pt,"%s %d ", &nama[index], &jk[index])!=EOF)
	index++;
	fclose(pt);
}

void cetak()		// cetak hasil data load
{
	int i;
	printf("\nNO : Nama Pemenang : Jumlah Kemenangan  \n");
	for (i=0;i<index;i++)
	printf("%-4d %-13s   %-13d\n", i+1, nama[i], jk[i]);
	
}

void edit(char f[10])		// penambahan nama pemenang yang tdk ada di data load
{
	int i;
	for (i=0;i<index;i++);
	strcpy(nama[index],f);
	jk[index]=1;
	index++;
}

void save()   	// save data
{
	int i;
	FILE *pt;
	pt = fopen("soal08.txt","w");
	for(i=0;i<index;i++)
	fprintf(pt,"%s %d\n ", nama[i], jk[i]);
	fclose(pt);
	printf("Data Berhasil Disimpan");
}


void clrscr()
{
	system("@cls||clear");
}

class memorizing {
	private :
		char array [10], jaw [10],arraybru[10];
		char nama[10];
		char temp;
	public :

		memorizing(){
			arraybru[10];
			array [10];
			jaw [10]; 
			nama[10];
			temp;
		}
	char setnama(char n[10]) {
			strcpy(nama,n);
		}
	
	char* getnama(){
			return nama;
		}
		
	char setarray(char a[10]) {
			strcpy(array,a);
		}
	
	char* getarray(){
			return array;
		}


	~memorizing(){
		cout<<"\n\nTHANK YOU FOR PLAYING THIS GAME ";
	}
	void random(){
		srand(time(NULL));
		char alphabets[36] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','1','2','3','4','5','6','7','8','9','0'};	
		int i=0;
		int a=0;
		while(array[a]!= NULL){
			a++;
		};
		while(i<=a) {
			int temp = rand() % 36;
			this->array[i] = alphabets[temp];
			i++;
		}
	}

	int wait (double second){
	clock_t endwait;
	endwait = clock () + second * CLOCKS_PER_SEC ;
	while (clock() < endwait) {}
	}

	void kerja(){
		int i=1;
		int a;
		do{
			random();
			cout<<" Hi.."<< nama <<endl<<" Let's Start the Game"<<endl;
			cout<<"\n Memorize this : "<<array;
			wait (5);
			clrscr();
			cout<<" Username : "<< nama <<endl<<" KEEP FIGHTING!! "<<endl;
			cout<<"\n Tell me again base on your memory....  :  ";
			cin>>this->jaw;
			cin.sync();
			cin.clear();
			i++;
		}while((strcmp(array,jaw)==0)&&i!=7);
	
		if(strcmp(array,jaw)==0){
			cout<<"\n You are Absolutely Cool, I'm Really Proud "<<endl;
			sort();	
			n=linearSearch(nama);		// mencari nama data load yang yang sama dengan nama pemenang
			if(n==(-1)){			// jika tidak ada nama pemenang baru akan ditambahkan ke data load
			edit(nama);
			
			}
			else{				// jika ada jumlah kemengan ditambah 1
			++jk[n];
			}
			save();
			getch();
		}
		else{
			cout<<"\n You Lost, You Got " <<i-2<<" correct from 6 memory"<<endl;
		} 
strcpy(this->array,this->arraybru);
	}
};


	int main(){
load();
		memorizing oke;
		int pil, a;
		char n[10];
do{
		
		system("cls");
	cout<<"\n  =============================================================;";
	cout<<"\n |                   Welcome to Memorizing Game                |";
	cout<<"\n  =============================================================;";
	cout<<"\n |                         HAVE FUN!!                          |";
	cout<<"\n  =============================================================;";
	cout<<"\n |                                                             |";
	cout<<"\n | 1. START THE GAME                                           |";
	cout<<"\n | 2. VIEW THE SCORE                                           |";
	cout<<"\n | 3. EXIT                                                     |";
	cout<<"\n |                                                             |";
	cout<<"\n  =============================================================";
	do{
		cout<<"\n Insert Your Choice :";
		cin>>pil;
	} while (pil>3);

	switch(pil)
	{
		case 1 : system("cls");
			cout<<"Input Your Username :";
			cin>>n;
			oke.setnama(n);
			system("cls");
			cout<<" Hai.."<< n <<endl<<" Welcome in Memorizing Game"<<endl;
        	oke.kerja();
        	
        	break;

		case 2 : cout<<"The List of Score";
			cetak();
			getch();
		case 3 : {
			break;
		}
	}

}while(pil!=3);

}
