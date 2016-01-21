#include <stdio.h>
#define MEM_SIZE 30000
#define MAX_STACK 1000

int main(int argc, char** argv) {
	FILE* in_file;
	long len;
	int ptr = 0;
	long loop_stack[MAX_STACK];
	int loop_stack_ptr = -1;
	unsigned char mem[MEM_SIZE];

	if(argc < 2) {
		printf("usage: %s (file)\n", argv[0]);
		return 1;
	}
	
	in_file = fopen(argv[1], "r");
	if(in_file == NULL) {
		printf("file %s could not be opened for reading\n", argv[1]);
		return 1;
	}

	fseek(in_file, 0, SEEK_END);
	len = ftell(in_file);
	rewind(in_file);
	
	char prog[len];
	for(int i = 0; i < MEM_SIZE; mem[i++] = 0);
	fread(prog, sizeof *prog, len, in_file);
	fclose(in_file);

	for(int i = 0; i < len; i++) {
		switch(prog[i]) {
			case '>': if(ptr >= MEM_SIZE) ptr = 0; else ptr++; break;
			case '<': if(ptr <= 0) ptr = MEM_SIZE; ptr--; break;
			case '+': mem[ptr]++; break;
			case '-': mem[ptr]--; break;
			case '.': putchar(mem[ptr]); break;
			case ',': mem[ptr] = getchar(); printf("%c", mem[ptr]); break;
			case '[':
				if(!mem[ptr]) {
					int nest = 1;
					while(nest) {
						char a = prog[++i];
						if(a == '[') nest++;
						if(a == ']') nest--;
					}
				} else {
					loop_stack[++loop_stack_ptr] = i;
				}
				break;
			case ']':
				if(mem[ptr]) i = loop_stack[loop_stack_ptr];
				else loop_stack_ptr--;
				break;
		}
	}

	printf("\n");

	return 0;
}
