#include <stdio.h>
#define b break;
#define m 30000
int main(int argc, char** argv) {
	FILE* f;
	long c;
	int p = 0;
	long L[1000];
	int l = -1;
	unsigned char M[m];

	if(argc < 2) {
		printf("usage: %s (file)\n", argv[0]);
		return 1;
	}
	
	f = fopen(argv[1], "r");
	if(f == NULL) {
		printf("file %s could not be opened for reading\n", argv[1]);
		return 1;
	}

	fseek(f, 0, SEEK_END);
	c = ftell(f);
	rewind(f);
	
	char P[c];
	for(int i = 0; i < m; M[i++] = 0);
	fread(P, sizeof *P, c, f);
	fclose(f);

	for(int i = 0; i < c; i++) {
		switch(P[i]) {
			case '>': if(p >= m) p = 0; else p++; b
			case '<': if(p <= 0) p = m; p--; b
			case '+': M[p]++; b
			case '-': M[p]--; b
			case '.': putchar(M[p]); b
			case ',': M[p] = getchar(); b
			case '[':
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
				b
			case ']':
				if(M[p]) i = L[l];
				else l--;
				b
		}
	}

	printf("\n");

	return 0;
}
