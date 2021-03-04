#include "stdio.h"
#include "string.h"
#include "insertion-sort.h"
#include "merge-sort.h"

int main(int argc, char *argv[]) {

	// printf("\n------------\nstage 1\n------------\n");
	// printf("Welcome to my beautiful C program. Brought to you by Bell Labs and Addison-Wesley.");

	// int j = 0;
	// for (int i = 0; i < argc; i++) {
	// 	printf("\n%s - %X -%s", argv[i], argv[i], *( argv + i ));

	// 	while (argv[i][j] != '\0') {
	// 		printf("\n%c", argv[i][j]);
	// 		j++;
	// 	}

	// 	j = 0;
	// }

	// printf("\n------------\nstage 2\n------------\n");
	// printf("%s\n", *(argv + 0));
	// printf("%s\n", *(argv + 1));
	// printf("%s\n", *(argv + 2));
	// printf("%s\n", *(argv + 3));
	// printf("%s\n", *(argv + 4));
	//printf("%s\n", *(argv + 5));
	//printf("%s\n", *(argv + 6));


	// char a = 'c';
	// char *b = &a;

	// structs in msvc pad out by the largest member
	// ex:
	// long long x; -> 8
	// char a1; -> 16
	// ...
	// char a8; -> 16
	// char a9; -> 24
	// struct mstruct {
	// 	char _a;
		// int a;
		// int b;
		// int c;
		// long long x;
		// char d;
		// char e;
		// char f;
		// char g;
		// char h;
		// long long x;
		// char a1;
		// char a2;
		// char a3;
		// char a4;
		// char a5;
		// char a6;
		// char a7;
		// char a8;
		// char a9;
		// char a10;
		// char a11;
		// char a12;
		// char a13;
	// };

	// struct mstruct ma;
	// struct mstruct *mb = &ma;

	// printf("\n------------\nstage 3\n------------\n");
	// printf("sizeof char %d\n", sizeof(char));
	// printf("sizeof int %d\n", sizeof(int));
	// printf("sizeof uint %d\n", sizeof(unsigned int));
	// printf("sizeof *argv %d\n", sizeof(*argv));
	// printf("sizeof *(argv + 0) %d\n", sizeof(*(argv + 0)));
	// printf("sizeof *(argv + 1) %d\n", sizeof(*(argv + 1)));
	// printf("sizeof ((*(argv + 1)) + 2) %c\n", *((*(argv + 1)) + 2) );
	// printf("sizeof *((*(argv + 1)) + 0) %d\n", sizeof( *((*(argv + 1)) + 0) ));
	// printf("sizeof ((*(argv + 1)) + 2) %d\n", sizeof( ((*(argv + 1)) + 2) ));
	// printf("sizeof a %d\n", sizeof(a));
	// printf("sizeof *b %d\n", sizeof(*b));
	// printf("sizeof b %d\n", sizeof(b));
	// printf("sizeof long %d\n", sizeof(long));
	// printf("sizeof long long %d\n", sizeof(long long));
	// printf("sizeof long long int %d\n", sizeof(long long int));
	// printf("sizeof struct mstruct %d\n", sizeof(struct mstruct));
	// printf("sizeof struct ma %d\n", sizeof(ma));
	// printf("sizeof struct *mb %d\n", sizeof(*mb));
	// printf("sizeof struct mb %d\n", sizeof(mb));

	printf("\n------------\nstage 4\n------------\n");

	printf("preamble\n");

	// TODO bitmap (gradient map, representation map) for chars and the like
	if (strcmp("insertion-sort", argv[1]) == 0) {
		// ok we told the compiler to alloc 5; how come it doesnt remember even statically? at compile time?
		int row[5] = {2, 3, 1, 8, 6};
		printf("def row: %p, sizeof: %zd, dsizeof: %zd\n\n", row, sizeof(row), sizeof(row[0]));
		insertion_sort(5, row);
	}

	if (strcmp("merge-sort", argv[1]) == 0) {
		int row[13] = {2, 3, 1, 8, 6, 12, 21, 14, 98, 34, 100, 2003, 449};
		// int row[13] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
		// int row[13] = {13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
		printf("def row: %p, sizeof: %zd, dsizeof: %zd\n\n", row, sizeof(row), sizeof(row[0]));
		merge_sort(13, row);
	}

	return 0;
}