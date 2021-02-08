#include "stdio.h"
#include "stdlib.h"
#include "merge-sort.h"

void do_merge_sort(size_t starti, size_t row_size, int row[]);
void merge(size_t starti, size_t middlei, size_t row_size, int row[]);

void merge_sort(size_t row_size, int row[]) {

	for (size_t i = 0; i < row_size; i++) {
		printf("%d ", row[i]);
	}

	printf("\n\n");

	do_merge_sort(0, row_size, row);

	printf("\n");

	for (size_t i = 0; i < row_size; i++) {
		printf("%d ", row[i]);
	}

	printf("\n");
}

// recursive calls are a LIFO stack
// think about applicability for search algorithms on graphs
void do_merge_sort(size_t starti, size_t row_size, int row[]) {

	if (starti < row_size) {

		size_t middlei = (starti + row_size) / 2;

		do_merge_sort(starti, middlei, row);

		do_merge_sort(middlei + 1, row_size, row);

		merge(starti, middlei, row_size, row);
	}
}

void merge(size_t starti, size_t middlei, size_t row_size, int row[]) {
	printf("%zu\t%zu\t%zu\n", starti, middlei, row_size);

	printf("%zu\t%zu\t%zu\n\n", middlei - starti + 1, row_size - middlei, row_size - starti);
}