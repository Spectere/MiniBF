#include <stdio.h>
#define m 30000
void main(int z, char** Z) {
	FILE* f;
	long c, L[1000];
	int p = 0, l = -1, i = 0;
	unsigned char M[m];

	if(z < 2)
		return;
	
	f = fopen(Z[1], "r");

	fseek(f, 0, 2);
	c = ftell(f);
	rewind(f);
	
	char P[c];
	for(; i < m; M[i++] = 0);
	fread(P, sizeof *P, c, f);
	fclose(f);

	for(i = 0; i < c; i++) {
		P[i]=='+'?M[p]++
		:P[i]=='-'?M[p]--
		:P[i]=='.'?putchar(M[p])
		:P[i]==','?M[p]=getchar()
		:P[i]=='<'?(--p<0?p=m:p)
		:P[i]=='>'?(++p==m?p=0:p):i;
		if(P[i]=='[') {
			if(!M[p]) {
				int n = 1;
				while(n) {
					char a = P[++i];
					if(a == '[') n++;
					if(a == ']') n--;
				}
			} else {
				L[++l] = i;
			}
		}
		if(P[i]==']') {
			if(M[p]) i = L[l];
			else if(l>=0) l--;
		}
	}

	printf("\n");
}
