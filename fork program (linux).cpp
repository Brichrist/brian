#include<stdio.h>
#include<sys/types.h>
#include<stdlib.h>
#include<unistd.h>
#include<ctime>



int h,w,r1,r2;




int main(){                          // MULAI GAME
	
printf("		simple fork program\n");
printf("----------------------------------------");
do{
printf("\nheight (10-20) = ");
scanf("%d", &h);
}while(h<10||h>20);

do{
printf("\nweight (10-20) = ");
scanf("%d", &w);
}while(w<10||w>20);
srand( (unsigned)time( NULL ) );
r1 = rand() % (7) + 1;
r2 = rand() % (7) + 1;
int id = fork();

if (id==0){
	h-=r1;
	w-=r2;
	printf("\nheight - %d = %d",r1,h);
	printf("\nweight - %d = %d\n",r2,w);
	for (int hh = 0; hh<h; hh++){
		for (int ww =0;ww<w;ww++)
		{printf("*");
		}
		printf("\n");
	}
}
else{
	h+=r1;
	w+=r2;
	printf("\nheight + %d = %d",r1,h);
	printf("\nweight + %d = %d\n",r2,w);
	for (int hh = 0; hh<h; hh++){
		for (int o = h-1-hh;o>0;o--)
		{printf(" ");
		}
		for (int ww =0;ww<w;ww++)
		{printf("*");
		}
		printf("\n");
	}
	
}
return 0;
}



