#include<stdio.h>
#include<conio.h>
#include<cmath>

int main()

{
	int n,i,snt=0;
	printf("Nhap so: ");
	scanf("%d",&n);
	

		for(i=2;i<sqrt(n);i++){
			if(n%i==0)
				snt=1;			
			else snt;
		}
		if(snt==0 && n>=2) {
		printf("So %d la so nguyen to.",n);}
		else {
		printf("So %d khong phai la so nguyen to.",n);}

	getch();
}
