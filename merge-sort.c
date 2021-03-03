#include "assert.h"
#include "limits.h"
#include "stdio.h"
#include "stdlib.h"
#include "merge-sort.h"

void do_merge_sort(size_t p, size_t r, int row[]);
void merge(size_t p, size_t q, size_t r, int row[]);

void merge_sort(size_t row_size, int row[]) {

	// todo safety checks

	printf("unsorted\n");
	for (size_t i = 0; i < row_size; i++) {
		printf("%d ", row[i]);
	} printf("\n");

	do_merge_sort(0, row_size - 1, row);

	printf("\nsorted\n");
	for (size_t i = 0; i < row_size; i++) {
		printf("%d ", row[i]);
	} printf("\n");
}

void do_merge_sort(size_t p, size_t r, int row[]) {

	if (p < r) {
		int q = (p + r) / 2;
		//printf("q: %d\n", q);
		//size_t q = p + (r - p) / 2;

		do_merge_sort(p, q, row);
		do_merge_sort(q + 1, r, row);
		merge(p, q, r, row);
	}
}

void merge(size_t p, size_t q, size_t r, int row[]) {

	size_t n1 = q - p + 1;
	size_t n2 = r - q;

	int *scratch = malloc((n1 + n2) * sizeof(int));

	size_t i = 0, j = 0, k = 0;

	while (i < n1 && j < n2) {

		if (row[p + i] <= row[q + 1 + j]) {
			scratch[k] = row[p + i];
			i++;
		} else {
			scratch[k] = row[q + 1 + j];
			j++;
		}

		k++;
	}

	while (i < n1) {

		scratch[k] = row[p + i];
		i++;
		k++;
	}

	while (j < n2) {

		scratch[k] = row[q + 1 + j];
		j++;
		k++;
	}

	for (size_t k = p, i = 0; i < n1 + n2; k++, i++) {
		row[k] = scratch[i];
	}
}

// recursive calls are a LIFO stack
// think about applicability for search algorithms on graphs

// programviz.com
// void do_merge_sort(int p, int r, int row[]);
// void merge(int p, int q, int r, int row[]);
// void do_merge_sort(int p, int r, int row[]) {

// 	if (p < r) {

// 		int q = p + (r - p) / 2;

// 		do_merge_sort(p, q, row);

// 		do_merge_sort(q + 1, r, row);

// 		merge(p, q, r, row);
// 	}
// }

// void merge(int p, int q, int r, int row[]) {

// 	int n1 = q - p + 1;
// 	int n2 = r - q;

// 	int *L = malloc(n1 * sizeof(int));
// 	int *R = malloc(n2 * sizeof(int));

// 	for (int i = 0; i < n1; i++) {
// 		L[i] = row[p + i];
// 	}

// 	for (int j = 0; j < n2; j++) {
// 		R[j] = row[q + 1 + j];
// 	}

// 	int i = 0, j = 0;
// 	int k = p;
// 	while (i < n1 && j <n2) {
// 		if (L[i] <= R[j]) {
// 			row[k] = L[i];
// 			i++;
// 		} else {
// 			row[k] = R[j];
// 			j++;
// 		}
// 		k++;
// 	}

// 	while (i < n1) {
// 		row[k] = L[i];
// 		i++;
// 		k++;
// 	}

// 	while (j < n2) {
// 		row[k] = R[j];
// 		j++;
// 		k++;
// 	}

// 	free(L);
// 	free(R);
// }