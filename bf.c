#include<stdio.h>
#define m 30000
main(int z,char** Z) {
	FILE* f;
	long c,L[1000];
	int p=0,l=-1,i=m,n=0;
	
	f=fopen(Z[1],"r");

	fseek(f,0,2);
	c=ftell(f);
	rewind(f);
	
	char P[c],a,M[m];
	for(;i>=0;M[--i]=0);
	fread(P,c,c,f);
	fclose(f);

	for(; i++ < c;
		n?(P[i]=='['?n++:P[i]==']'?n--:n)
		:(P[i]=='+'?M[p]++
		:P[i]=='-'?M[p]--
		:P[i]=='.'?putchar(M[p])
		:P[i]==','?M[p]=getchar()
		:P[i]=='<'?(--p<0?p=m:p)
		:P[i]=='>'?(++p==m?p=0:p)
		:P[i]=='['?(M[p]?L[++l]=i:n++)
		:P[i]==']'?(M[p]?i=L[l]:(l>=0?l--:l)):i));
}
