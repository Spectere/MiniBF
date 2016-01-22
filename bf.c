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
		n?(_'['?n++:_']'?n--:n)
		:(_'+'?M[p]++
		:_'-'?M[p]--
		:_'.'?putchar(M[p])
		:_','?M[p]=getchar()
		:_'<'?(--p<0?p=m:p)
		:_'>'?(++p==m?p=0:p)
		:_'['?(M[p]?L[++l]=i:n++)
		:_']'?(M[p]?i=L[l]:(l>=0?l--:l)):i));
}
