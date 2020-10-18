#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>


char enter; // deklarasi untuk jawaban peserta seperti ya lanjut
int n; // deklarasi untuk linear search
int A,B,C,D,E,F,G,H; // deklarasi untuk jawaban suit peserta seperti ibu jari
int sbp1=0,sbp2=0,sbp3=0,sbp4=0,ssf1=0,ssf2=0; // deklarasi score penyisihan
char na[20],nb[20],nc[20],nd[20],ne[20],nf[20],ng[20],nh[20]; // deklarasi nama peserta
char bp1[20],bp2[20],bp3[20],bp4[20],sf1[20],sf2[20],f[10],f2,f3; // deklarasi nama pemenang  
int sa=0,sb=0,sc=0,sd=0,se=0,sf=0,sg=0,sh=0; // deklarasi score pamain			
int index=0;
char nama[10][10];
int jk[10];

void swap (int *a, int *b){       // membantu tugas sort angka
   int temp = *a;
   *a = *b; *b=temp;}
   
void swapstr(char *arrA, char *arrB)       // membantu tugas sort kata
{
  char temp[1000];
  strcpy(temp, arrA);
  strcpy(arrA, arrB);
  strcpy(arrB, temp);
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

int linearSearch() {          // search untuk menemukan pemenang turnamen apa ada yang sama/tdk
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

void edit()		// penambahan nama pemenang yang tdk ada di data load
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

void papan(){      // memamngil papan turnamen
printf("\n------------------------------------------------------------------------------------");
printf("\n-----------------------           TOURNAMENT BOARD           -----------------------");
printf("\n------------------------------------------------------------------------------------\n");
printf("\n%.3s\t-----",na);
printf("\n    \t    |");
printf("\n    \t    |-------- %.3s\t----",bp1);
printf("\n    \t    |                      |");
printf("\n%.3s\t-----                      |",nb);
printf("\n                                   |-------- %.3s\t-----",sf1);
printf("\n%.3s\t-----                      |                        |",nc);
printf("\n    \t    |                      |                        |");
printf("\n    \t    |-------- %.3s\t----                        |",bp2);
printf("\n    \t    |                                               |");
printf("\n%.3s\t-----                                               | ",nd);
printf("\n                                                            |---------- %.3s\t",f);
printf("\n%.3s\t-----                                               | ",ne);
printf("\n    \t    |                                               |");
printf("\n    \t    |-------- %.3s\t----                        |",bp3);
printf("\n    \t    |                      |                        |");
printf("\n%.3s\t-----                      |                        |",nf);
printf("\n                                   |-------- %.3s\t-----",sf2);
printf("\n%.3s\t-----                      |",ng);
printf("\n    \t    |                      |");
printf("\n    \t    |-------- %.3s\t----",bp4);
printf("\n    \t    |");
printf("\n%.3s\t-----",nh);
}

void clrscr(){system("@cls||clear");}

int main(){                          // MULAI GAME
	
printf("		rule\n");
printf("----------------------------------------");
printf("\nThumb VS Index Finger VS Little finger\n");
printf("\nThumb           <     Little Finger");
printf("\nLittle Finger   <     Index Finger");
printf("\nIndex Finger    <     Thumb\n");
printf("\nIndex Finger    =     1");
printf("\nThumb           =     2");
printf("\nLittle Finger   =     3");

printf("\n\n Want to see tournament record\n1. yes = press y\n2. no = press n\n");   // lihat data
enter=getch();
while(enter=='y'){
load();
do{
clrscr();
printf("\nhow do you want??");
printf("\n\n1. alphabetic sort (press a)\n2. score sort (press s)\n3. quit (press other key)");
enter=getch();
if(enter=='a'){ 		// pengurutan berdasarkan alfabetik
clrscr();
sort();
clrscr();
cetak();}
else if(enter=='s'){          // pengurutan berdasrkan angka kemengangan
clrscr();
bubble();
clrscr();
cetak();
}
printf("\n\ndone ?? (press a)\n");
enter=getch();
}while(enter!='a');
}
clrscr();
do{
printf("\nSTART ?? (press y)\n");        
enter=getch();
}while(enter!='y');
clrscr();
printf("\nplayer 1 NAME        :   ");	// input nama
scanf("%s", &na);
printf("player 2 NAME        :   ");
scanf("%s", &nb);
printf("player 3 NAME        :   ");
scanf("%s", &nc);
printf("player 4 NAME        :   ");
scanf("%s", &nd);
printf("player 5 NAME        :   ");
scanf("%s", &ne);
printf("player 6 NAME        :   ");
scanf("%s", &nf);
printf("player 7 NAME        :   ");
scanf("%s", &ng);
printf("player 8 NAME        :   ");
scanf("%s", &nh);
clrscr();

papan();

do{
printf("\n\nSTART ?? (press y)\n");
enter=getch();
}while(enter!='y');

do{
clrscr();
do{							// input suit
printf("\nIndex Finger    =     1");
printf("\nThumb           =     2");
printf("\nLittle Finger   =     3\n\n");
printf("%s turn:   ",na);
scanf("%d", &A);
}while(A<1||A>3);
	clrscr();
do{							// input suit
printf("\nIndex Finger    =     1");
printf("\nThumb           =     2");
printf("\nLittle Finger   =     3\n\n");
printf("%s turn:   ",nb);
scanf("%d", &B);
}while(B<1||B>3);
	clrscr();
		printf("--------------------------------");
		printf("\n--           RESULT           --");
		printf("\n--------------------------------\n");
		if(A==1&&B==1){			// mencari yang lebih besar
		printf("%s \t\tVS\t %s",na,nb);
		printf("\nindex Finger \tVS\t index Finger");
		printf("\n\nDRAW");}
		else if(A==2&&B==2){
		printf("%s \t\tVS\t %s",na,nb);
		printf("\nThumb \tVS\t Thumb");
		printf("\n\nDRAW");}
		else if(A==3&&B==3){
		printf("%s \t\tVS\t %s",na,nb);
		printf("\nLittle Finger \tVS\t Little Finger");
		printf("\n\nDRAW");}
		
		else if(A==1&&B==3){
		printf("%s \t\tVS\t %s",na,nb);
		printf("\nindex Finger \tVS\t Little Finger");
		printf("\n\n%s win the score ",na);
		sa++;}
		else if(A==3&&B==1){
		printf("%s \t\tVS\t %s",na,nb);
		printf("\nLittle Finger \tVS\t index Finger");
		printf("\n\n%s win the score ",nb);
		sb++;}
		
		else if(A==1&&B==2){
		printf("%s \t\tVS\t %s",na,nb);
		printf("\nindex Finger \tVS\t thumb");
		printf("\n\n%s win the score ",nb);
		sb++;}
		else if(A==2&&B==1){
		printf("%s \t\tVS\t %s",na,nb);
		printf("\nthumb \t\tVS\t index Finger");
		printf("\n\n%s win the score ",na);
		sa++;}
		
		else if(A==2&&B==3){
		printf("%s \t\tVS\t %s",na,nb);
		printf("\nthumb \t\tVS\t Little Finger");
		printf("\n\n%s win the score ",nb);
		sb++;}
		else if(A==3&&B==2){
		printf("%s \t\tVS\t %s",na,nb);
		printf("\nLittle Finger \tVS\t thumb");
		printf("\n\n%s win the score ",na);
		sa++;}
printf("\n\n\n\n--------------------------");
printf("\n--      YOUR SCORE      --");
printf("\n--------------------------");
printf("\n\nscore %s\t :%d",na,sa);
printf("\nscore %s\t :%d",nb,sb);
do{
printf("\n\nNEXT ?? (press y)\n");
enter=getch();
}while(enter!='y');
}while(sa<3&&sb<3);

if (sa==3){
printf("\n%s WIN THE GAME AND GO TO SEMIFINAL",na);
strcpy(bp1,na);				// copy nama pemenang ke tempat babak lanjutan
papan();
do{
printf("\n\nNEXT ?? (press y)\n");
enter=getch();
}while(enter!='y');}

if (sb==3){
printf("\n%s WIN THE GAME AND GO TO SEMIFINAL",nb);
strcpy(bp1,nb);			// copy nama pemenang ke tempat babak lanjutan
papan();
do{
printf("\n\nNEXT ?? (press y)\n");
enter=getch();
}while(enter!='y');}


do{
clrscr();
do{
printf("\nIndex Finger    =     1");
printf("\nThumb           =     2");
printf("\nLittle Finger   =     3\n\n");
printf("%s turn:   ",nc);
scanf("%d", &A);
}while(A<1||A>3);
	clrscr();
do{
printf("\nIndex Finger    =     1");
printf("\nThumb           =     2");
printf("\nLittle Finger   =     3\n\n");
printf("%s turn:   ",nd);
scanf("%d", &B);
}while(B<1||B>3);
	clrscr();
		printf("--------------------------------");
		printf("\n--           RESULT           --");
		printf("\n--------------------------------\n");
		if(A==1&&B==1){
		printf("%s \t\tVS\t %s",nc,nd);
		printf("\nindex Finger \tVS\t index Finger");
		printf("\n\nDRAW");}
		else if(A==2&&B==2){
		printf("%s \t\tVS\t %s",nc,nd);
		printf("\nThumb \tVS\t Thumb");
		printf("\n\nDRAW");}
		else if(A==3&&B==3){
		printf("%s \t\tVS\t %s",nc,nd);
		printf("\nLittle Finger \tVS\t Little Finger");
		printf("\n\nDRAW");}
		
		else if(A==1&&B==3){
		printf("%s \t\tVS\t %s",nc,nd);
		printf("\nindex Finger \tVS\t Little Finger");
		printf("\n\n%s win the score ",nc);
		sc++;}
		else if(A==3&&B==1){
		printf("%s \t\tVS\t %s",nc,nd);
		printf("\nLittle Finger \tVS\t index Finger");
		printf("\n\n%s win the score ",nd);
		sd++;}
		
		else if(A==1&&B==2){
		printf("%s \t\tVS\t %s",nc,nd);
		printf("\nindex Finger \tVS\t thumb");
		printf("\n\n%s win the score ",nd);
		sd++;}
		else if(A==2&&B==1){
		printf("%s \t\tVS\t %s",nc,nd);
		printf("\nthumb \t\tVS\t index Finger");
		printf("\n\n%s win the score ",nc);
		sc++;}
		
		else if(A==2&&B==3){
		printf("%s \t\tVS\t %s",nc,nd);
		printf("\nthumb \t\tVS\t Little Finger");
		printf("\n\n%s win the score ",nd);
		sd++;}
		else if(A==3&&B==2){
		printf("%s \t\tVS\t %s",nc,nd);
		printf("\nLittle Finger \tVS\t thumb");
		printf("\n\n%s win the score ",nc);
		sc++;}
printf("\n\n\n\n--------------------------");
printf("\n--      YOUR SCORE      --");
printf("\n--------------------------");
printf("\n\nscore %s\t :%d",nc,sc);
printf("\nscore %s\t :%d",nd,sd);
do{
printf("\n\nNEXT ?? (press y)\n");
enter=getch();
}while(enter!='y');
}while(sc<3&&sd<3);

if (sc==3){
printf("\n%s WIN THE GAME AND GO TO SEMIFINAL",nc);
strcpy(bp2,nc);
papan();
do{
printf("\n\nNEXT ?? (press y)\n");
enter=getch();
}while(enter!='y');}

if (sd==3){
printf("\n%s WIN THE GAME AND GO TO SEMIFINAL",nd);
strcpy(bp2,nd);
papan();
do{
printf("\n\nNEXT ?? (press y)\n");
enter=getch();
}while(enter!='y');}


do{
clrscr();
do{
printf("\nIndex Finger    =     1");
printf("\nThumb           =     2");
printf("\nLittle Finger   =     3\n\n");
printf("%s turn:   ",ne);
scanf("%d", &A);
}while(A<1||A>3);
	clrscr();
do{
printf("\nIndex Finger    =     1");
printf("\nThumb           =     2");
printf("\nLittle Finger   =     3\n\n");
printf("%s turn:   ",nf);
scanf("%d", &B);
}while(B<1||B>3);
	clrscr();
		printf("--------------------------------");
		printf("\n--           RESULT           --");
		printf("\n--------------------------------\n");
		if(A==1&&B==1){
		printf("%s \t\tVS\t %s",ne,nf);
		printf("\nindex Finger \tVS\t index Finger");
		printf("\n\nDRAW");}
		else if(A==2&&B==2){
		printf("%s \t\tVS\t %s",ne,nf);
		printf("\nThumb \tVS\t Thumb");
		printf("\n\nDRAW");}
		else if(A==3&&B==3){
		printf("%s \t\tVS\t %s",ne,nf);
		printf("\nLittle Finger \tVS\t Little Finger");
		printf("\n\nDRAW");}
		
		else if(A==1&&B==3){
		printf("%s \t\tVS\t %s",ne,nf);
		printf("\nindex Finger \tVS\t Little Finger");
		printf("\n\n%s win the score ",ne);
		se++;}
		else if(A==3&&B==1){
		printf("%s \t\tVS\t %s",ne,nf);
		printf("\nLittle Finger \tVS\t index Finger");
		printf("\n\n%s win the score ",nf);
		sf++;}
		
		else if(A==1&&B==2){
		printf("%s \t\tVS\t %s",ne,nf);
		printf("\nindex Finger \tVS\t thumb");
		printf("\n\n%s win the score ",nf);
		sf++;}
		else if(A==2&&B==1){
		printf("%s \t\tVS\t %s",ne,nf);
		printf("\nthumb \t\tVS\t index Finger");
		printf("\n\n%s win the score ",ne);
		se++;}
		
		else if(A==2&&B==3){
		printf("%s \t\tVS\t %s",ne,nf);
		printf("\nthumb \t\tVS\t Little Finger");
		printf("\n\n%s win the score ",nf);
		sf++;}
		else if(A==3&&B==2){
		printf("%s \t\tVS\t %s",ne,nf);
		printf("\nLittle Finger \tVS\t thumb");
		printf("\n\n%s win the score ",ne);
		se++;}
printf("\n\n\n\n--------------------------");
printf("\n--      YOUR SCORE      --");
printf("\n--------------------------");
printf("\n\nscore %s\t :%d",ne,se);
printf("\nscore %s\t :%d",nf,sf);
do{
printf("\n\nNEXT ?? (press y)\n");
enter=getch();
}while(enter!='y');
}while(se<3&&sf<3);

if (se==3){
printf("\n%s WIN THE GAME AND GO TO SEMIFINAL",ne);
strcpy(bp3,ne);
papan();
do{
printf("\n\nNEXT ?? (press y)\n");
enter=getch();
}while(enter!='y');}

if (sf==3){
printf("\n%s WIN THE GAME AND GO TO SEMIFINAL",nf);
strcpy(bp3,nf);
papan();
do{
printf("\n\nNEXT ?? (press y)\n");
enter=getch();
}while(enter!='y');}


do{
clrscr();
do{
printf("\nIndex Finger    =     1");
printf("\nThumb           =     2");
printf("\nLittle Finger   =     3\n\n");
printf("%s turn:   ",ng);
scanf("%d", &A);
}while(A<1||A>3);
	clrscr();
do{
printf("\nIndex Finger    =     1");
printf("\nThumb           =     2");
printf("\nLittle Finger   =     3\n\n");
printf("%s turn:   ",nh);
scanf("%d", &B);
}while(B<1||B>3);
	clrscr();
		printf("--------------------------------");
		printf("\n--           RESULT           --");
		printf("\n--------------------------------\n");
		if(A==1&&B==1){
		printf("%s \t\tVS\t %s",ng,nh);
		printf("\nindex Finger \tVS\t index Finger");
		printf("\n\nDRAW");}
		else if(A==2&&B==2){
		printf("%s \t\tVS\t %s",ng,nh);
		printf("\nThumb \tVS\t Thumb");
		printf("\n\nDRAW");}
		else if(A==3&&B==3){
		printf("%s \t\tVS\t %s",ng,nh);
		printf("\nLittle Finger \tVS\t Little Finger");
		printf("\n\nDRAW");}
		
		else if(A==1&&B==3){
		printf("%s \t\tVS\t %s",ng,nh);
		printf("\nindex Finger \tVS\t Little Finger");
		printf("\n\n%s win the score ",ng);
		sg++;}
		else if(A==3&&B==1){
		printf("%s \t\tVS\t %s",ng,nh);
		printf("\nLittle Finger \tVS\t index Finger");
		printf("\n\n%s win the score ",nh);
		sh++;}
		
		else if(A==1&&B==2){
		printf("%s \t\tVS\t %s",ng,nh);
		printf("\nindex Finger \tVS\t thumb");
		printf("\n\n%s win the score ",nh);
		sh++;}
		else if(A==2&&B==1){
		printf("%s \t\tVS\t %s",ng,nh);
		printf("\nthumb \t\tVS\t index Finger");
		printf("\n\n%s win the score ",ng);
		sg++;}
		
		else if(A==2&&B==3){
		printf("%s \t\tVS\t %s",ng,nh);
		printf("\nthumb \t\tVS\t Little Finger");
		printf("\n\n%s win the score ",nh);
		sh++;}
		else if(A==3&&B==2){
		printf("%s \t\tVS\t %s",ng,nh);
		printf("\nLittle Finger \tVS\t thumb");
		printf("\n\n%s win the score ",ng);
		sg++;}
printf("\n\n\n\n--------------------------");
printf("\n--      YOUR SCORE      --");
printf("\n--------------------------");
printf("\n\nscore %s\t :%d",ng,sg);
printf("\nscore %s\t :%d",nh,sh);
do{
printf("\n\nNEXT ?? (press y)\n");
enter=getch();
}while(enter!='y');
}while(sg<3&&sh<3);

if (sg==3){
printf("\n%s WIN THE GAME AND GO TO SEMIFINAL",ng);
strcpy(bp4,ng);
papan();
do{
printf("\n\nNEXT ?? (press y)\n");
enter=getch();
}while(enter!='y');}

if (sh==3){
printf("\n%s WIN THE GAME AND GO TO SEMIFINAL",nh);
strcpy(bp4,nh);
papan();
do{
printf("\n\nNEXT ?? (press y)\n");
enter=getch();
}while(enter!='y');}

do{
clrscr();                      // pemenang pertama dan kedua dilombakan
do{
printf("\nIndex Finger    =     1");
printf("\nThumb           =     2");
printf("\nLittle Finger   =     3\n\n");
printf("%s turn:   ",bp1);
scanf("%d", &A);
}while(A<1||A>3);
	clrscr();
do{
printf("\nIndex Finger    =     1");
printf("\nThumb           =     2");
printf("\nLittle Finger   =     3\n\n");
printf("%s turn:   ",bp2);
scanf("%d", &B);
}while(B<1||B>3);
	clrscr();
		printf("--------------------------------");
		printf("\n--           RESULT           --");
		printf("\n--------------------------------\n");
		if(A==1&&B==1){
		printf("%s \t\tVS\t %s",bp1,bp2);
		printf("\nindex Finger \tVS\t index Finger");
		printf("\n\nDRAW");}
		else if(A==2&&B==2){
		printf("%s \t\tVS\t %s",bp1,bp2);
		printf("\nThumb \tVS\t Thumb");
		printf("\n\nDRAW");}
		else if(A==3&&B==3){
		printf("%s \t\tVS\t %s",bp1,bp2);
		printf("\nLittle Finger \tVS\t Little Finger");
		printf("\n\nDRAW");}
		
		else if(A==1&&B==3){
		printf("%s \t\tVS\t %s",bp1,bp2);
		printf("\nindex Finger \tVS\t Little Finger");
		printf("\n\n%s win the score ",bp1);
		sbp1++;}
		else if(A==3&&B==1){
		printf("%s \t\tVS\t %s",bp1,bp2);
		printf("\nLittle Finger \tVS\t index Finger");
		printf("\n\n%s win the score ",bp2);
		sbp2++;}
		
		else if(A==1&&B==2){
		printf("%s \t\tVS\t %s",bp1,bp2);
		printf("\nindex Finger \tVS\t thumb");
		printf("\n\n%s win the score ",bp2);
		sbp2++;}
		else if(A==2&&B==1){
		printf("%s \t\tVS\t %s",bp1,bp2);
		printf("\nthumb \t\tVS\t index Finger");
		printf("\n\n%s win the score ",bp1);
		sbp1++;}
		
		else if(A==2&&B==3){
		printf("%s \t\tVS\t %s",bp1,bp2);
		printf("\nthumb \t\tVS\t Little Finger");
		printf("\n\n%s win the score ",bp2);
		sbp2++;}
		else if(A==3&&B==2){
		printf("%s \t\tVS\t %s",bp1,bp2);
		printf("\nLittle Finger \tVS\t thumb");
		printf("\n\n%s win the score ",bp1);
		sbp1++;}
printf("\n\n\n\n--------------------------");
printf("\n--      YOUR SCORE      --");
printf("\n--------------------------");
printf("\n\nscore %s\t :%d",bp1,sbp1);
printf("\nscore %s\t :%d",bp2,sbp2);
do{
printf("\n\nNEXT ?? (press y)\n");
enter=getch();
}while(enter!='y');
}while(sbp1<3&&sbp2<3);

if (sbp1==3){
printf("\n%s WIN THE GAME AND GO TO FINAL",bp1);
strcpy(sf1,bp1);
papan();
do{
printf("\n\nNEXT ?? (press y)\n");
enter=getch();
}while(enter!='y');}

if (sbp2==3){
printf("\n%s WIN THE GAME AND GO TO FINAL",bp2);
strcpy(sf1,bp2);
papan();
do{
printf("\n\nNEXT ?? (press y)\n");
enter=getch();
}while(enter!='y');}

do{
clrscr();
do{
printf("\nIndex Finger    =     1");
printf("\nThumb           =     2");
printf("\nLittle Finger   =     3\n\n");
printf("%s turn:   ",bp3);
scanf("%d", &A);
}while(A<1||A>3);
	clrscr();
do{
printf("\nIndex Finger    =     1");
printf("\nThumb           =     2");
printf("\nLittle Finger   =     3\n\n");
printf("%s turn:   ",bp4);
scanf("%d", &B);
}while(B<1||B>3);
	clrscr();
		printf("--------------------------------");
		printf("\n--           RESULT           --");
		printf("\n--------------------------------\n");
		if(A==1&&B==1){
		printf("%s \t\tVS\t %s",bp3,bp4);
		printf("\nindex Finger \tVS\t index Finger");
		printf("\n\nDRAW");}
		else if(A==2&&B==2){
		printf("%s \t\tVS\t %s",bp3,bp4);
		printf("\nThumb \tVS\t Thumb");
		printf("\n\nDRAW");}
		else if(A==3&&B==3){
		printf("%s \t\tVS\t %s",bp3,bp4);
		printf("\nLittle Finger \tVS\t Little Finger");
		printf("\n\nDRAW");}
		
		else if(A==1&&B==3){
		printf("%s \t\tVS\t %s",bp3,bp4);
		printf("\nindex Finger \tVS\t Little Finger");
		printf("\n\n%s win the score ",bp3);
		sbp3++;}
		else if(A==3&&B==1){
		printf("%s \t\tVS\t %s",bp3,bp4);
		printf("\nLittle Finger \tVS\t index Finger");
		printf("\n\n%s win the score ",bp4);
		sbp4++;}
		
		else if(A==1&&B==2){
		printf("%s \t\tVS\t %s",bp3,bp4);
		printf("\nindex Finger \tVS\t thumb");
		printf("\n\n%s win the score ",bp4);
		sbp4++;}
		else if(A==2&&B==1){
		printf("%s \t\tVS\t %s",bp3,bp4);
		printf("\nthumb \t\tVS\t index Finger");
		printf("\n\n%s win the score ",bp3);
		sbp3++;}
		
		else if(A==2&&B==3){
		printf("%s \t\tVS\t %s",bp3,bp4);
		printf("\nthumb \t\tVS\t Little Finger");
		printf("\n\n%s win the score ",bp4);
		sbp4++;}
		else if(A==3&&B==2){
		printf("%s \t\tVS\t %s",bp3,bp4);
		printf("\nLittle Finger \tVS\t thumb");
		printf("\n\n%s win the score ",bp3);
		sbp3++;}
printf("\n\n\n\n--------------------------");
printf("\n--      YOUR SCORE      --");
printf("\n--------------------------");
printf("\n\nscore %s\t :%d",bp3,sbp3);
printf("\nscore %s\t :%d",bp4,sbp4);
do{
printf("\n\nNEXT ?? (press y)\n");
enter=getch();
}while(enter!='y');
}while(sbp3<3&&sbp4<3);

if (sbp3==3){
printf("\n%s WIN THE GAME AND GO TO FINAL",bp3);
strcpy(sf2,bp3);
papan();
do{
printf("\n\nNEXT ?? (press y)\n");
enter=getch();
}while(enter!='y');}

if (sbp4==3){
printf("\n%s WIN THE GAME AND GO TO FINAL",bp4);
strcpy(sf2,bp4);
papan();
do{
printf("\n\nNEXT ?? (press y)\n");
enter=getch();
}while(enter!='y');}

do{
clrscr();
do{
printf("\nIndex Finger    =     1");
printf("\nThumb           =     2");
printf("\nLittle Finger   =     3\n\n");
printf("%s turn:   ",sf1);
scanf("%d", &A);
}while(A<1||A>3);
	clrscr();
do{
printf("\nIndex Finger    =     1");
printf("\nThumb           =     2");
printf("\nLittle Finger   =     3\n\n");
printf("%s turn:   ",sf2);
scanf("%d", &B);
}while(B<1||B>3);
	clrscr();
		printf("--------------------------------");
		printf("\n--           RESULT           --");
		printf("\n--------------------------------\n");
		if(A==1&&B==1){
		printf("%s \t\tVS\t %s",sf1,sf2);
		printf("\nindex Finger \tVS\t index Finger");
		printf("\n\nDRAW");}
		else if(A==2&&B==2){
		printf("%s \t\tVS\t %s",sf1,sf2);
		printf("\nThumb \tVS\t Thumb");
		printf("\n\nDRAW");}
		else if(A==3&&B==3){
		printf("%s \t\tVS\t %s",sf1,sf2);
		printf("\nLittle Finger \tVS\t Little Finger");
		printf("\n\nDRAW");}
		
		else if(A==1&&B==3){
		printf("%s \t\tVS\t %s",sf1,sf2);
		printf("\nindex Finger \tVS\t Little Finger");
		printf("\n\n%s win the score ",sf1);
		ssf1++;}
		else if(A==3&&B==1){
		printf("%s \t\tVS\t %s",sf1,sf2);
		printf("\nLittle Finger \tVS\t index Finger");
		printf("\n\n%s win the score ",sf2);
		ssf2++;}
		
		else if(A==1&&B==2){
		printf("%s \t\tVS\t %s",sf1,sf2);
		printf("\nindex Finger \tVS\t thumb");
		printf("\n\n%s win the score ",sf2);
		ssf2++;}
		else if(A==2&&B==1){
		printf("%s \t\tVS\t %s",sf1,sf2);
		printf("\nthumb \t\tVS\t index Finger");
		printf("\n\n%s win the score ",sf1);
		ssf1++;}
		
		else if(A==2&&B==3){
		printf("%s \t\tVS\t %s",sf1,sf2);
		printf("\nthumb \t\tVS\t Little Finger");
		printf("\n\n%s win the score ",sf2);
		ssf2++;}
		else if(A==3&&B==2){
		printf("%s \t\tVS\t %s",sf1,sf2);
		printf("\nLittle Finger \tVS\t thumb");
		printf("\n\n%s win the score ",sf1);
		ssf1++;}
printf("\n\n\n\n--------------------------");
printf("\n--      YOUR SCORE      --");
printf("\n--------------------------");
printf("\n\nscore %s\t :%d",sf1,ssf1);
printf("\nscore %s\t :%d",sf2,ssf2);
do{
printf("\n\nNEXT ?? (press y)\n");
enter=getch();
}while(enter!='y');
}while(ssf1<3&&ssf2<3);

if (ssf1==3){
printf("\n%s WIN THE GAME",sf1);
printf("\n%s be the second winner",sf2);
strcpy(f,sf1);
papan();
do{
printf("\n\nNEXT ?? (press y)\n");
enter=getch();
}while(enter!='y');}

if (ssf2==3){
printf("\n%s WIN THE GAME",sf2);
printf("\n%s be the second winner",sf1);
strcpy(f,sf2);
papan();
do{
printf("\n\nNEXT ?? (press y)\n");
enter=getch();
}while(enter!='y');}


sort();				// sort berdasarkan nama 
n=linearSearch();		// mencari nama data load yang yang sama dengan nama pemenang
if(n==(-1)){			// jika tidak ada nama pemenang baru akan ditambahkan ke data load
edit();
}
else{				// jika ada jumlah kemengan ditambah 1
++jk[n];
}
clrscr();


printf("\n%s be the first winner\ncongrats!!!",f);
do{
printf("\n\nnext?? (press y to continue)\n");
enter=getch();
}while(enter!='y');
clrscr();

cetak();			// mencetak hasil load yang talah diubah diatas
do{
printf("\n\nnext?? (press s to continue)\n");
enter=getch();
}while(enter!='s');
save();				// saving
}

