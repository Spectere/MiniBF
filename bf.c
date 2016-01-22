#include<stdio.h>
#define m 30000
#define _ P[i]==
main(int z,char** Z) {
	FILE* f;
	long c,L[1000];
	int p=0,l=-1,i=m,n=0;
	
	f=fopen(Z[1],"r");

	fseek(f,0,2);
	c=ftell(f);
	rewind(f);
	
	char P[c],M[m];
	for(;i>=0;M[--i]=0);
	fread(P,c,c,f);
	fclose(f);

	for(; i++ < c;
		n?(_ 91?n++:_ 93?n--:n)
		:(_ 43?M[p]++
		:_ 45?M[p]--
		:_ 46?putchar(M[p])
		:_ 44?M[p]=getchar()
		:_ 60?(--p<0?p=m:p)
		:_ 62?(++p==m?p=0:p)
		:_ 91?(M[p]?L[++l]=i:n++)
		:_ 93?(M[p]?i=L[l]:(l>=0?l--:l)):i));
}
