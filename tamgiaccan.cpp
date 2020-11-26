#include<stdio.h>
#include<conio.h>

int main()

{
	int n,q=0;
	printf("Nhap vao chieu cao: ");
	scanf("%d",&n);
	
	while(n>0)
	{
	
		for(int i=1;i<n;i++) printf("%c",' ');
	
		for(int k=0;k<=q;k++) printf("%c",'*');
		
		for(int k=0;k<q;k++) printf("%c",'*');
		
		n--;
		q++;
		
		printf("\n");
			
	}
	printf("Huy dep trai qua di thoi");
	getch();
}
