#include "stdio.h"
#include "insertion-sort.h"

// TODO "safe array" i < 0 = toss -> no loops
void insertion_sort(size_t row_size, int row[]) {
	printf("insertion_sort\n");

	printf("row: %p, sizeof: %zd, dsizeof: %zd\n", row, sizeof(row), sizeof(*row));

	for (size_t i = 0; i < row_size; i++) {
		printf("%d ", row[i]);
	}

	printf("\n");

	size_t position = 0;
	while (position < row_size) {
		for (size_t scani = position + 1; scani < row_size; scani++) {
			if (row[scani] < row[position]) {
				int store = row[position];
				row[position] = row[scani];
				row[scani] = store;
			}
		}
		position++;
	}

	for (size_t i = 0; i < row_size; i++) {
		printf("%d ", row[i]);
	}

	printf("\n");

	// TODO computation to get clamp/min/diff to remove loops
	// printf("%d\n", row[row_size - 1]);
	// printf("%d\n", row[row_size - 2]);
	// printf("%d\n", row[row_size - 3]);
	// printf("%d\n", row[row_size - 4]);
	// printf("%d\n", row[row_size - 5]);

	// OR UP TO row_size!
	// printf("%d\n", row[row_size - row_size]);
	// printf("%d\n", row[row_size - row_size + 1]);
	// printf("%d\n", row[row_size - row_size + 2]);
	// printf("%d\n", row[row_size - row_size + 3]);
	// printf("%d\n", row[row_size - row_size + 4]);

	// how come in this style 2 & 3 past the post always have some non-zero value
	// how come in this style we can read for around 75 iterations past the post before crash
	// when len([]) = 5 and limit is 10, 1000
	// for (int i = 0; i < 10; i++) {
	// 	printf("accessing: %d\n", i);
	// 	int n = row[i];
	// 	printf("read: %d\n", n);
	// }
}