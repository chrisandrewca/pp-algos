#include "assert.h"
#include "limits.h"
#include "stdio.h"
#include "stdlib.h"
#include "merge-sort.h"

void do_merge_sort(int p, int r, int row[]);
void merge(int p, int q, int r, int row[]);

void merge_sort(size_t row_size, int row[]) {

	for (size_t i = 0; i < row_size; i++) {
		printf("%d ", row[i]);
	} printf("\n");

	do_merge_sort(0, row_size, row);

	printf("\n");
	for (size_t i = 0; i < row_size; i++) {
		printf("%d ", row[i]);
	} printf("\n");
}

// recursive calls are a LIFO stack
// think about applicability for search algorithms on graphs
void do_merge_sort(int p, int r, int row[]) {
	if (p < r) {
		size_t q = (p + r) / 2;

		do_merge_sort(p, q, row);

		do_merge_sort(q + 1, r, row);

		merge(p, q, r, row);
	}
}

void merge(int p, int q, int r, int row[]) {
	assert(p <= q);
	assert(q < r);

	// assert(q - p + 1 > 0);
	assert(q - p >= 0);
	assert(r - p >= 1);

	// assert(p + 0 - 1 > -2); // ?
	assert(p + 0 >= 0);
	assert(q + 0 >= 0);

	// q++;

	size_t length = r - p;
	int *copy = malloc(length * sizeof(int));

	int *left = NULL, *right = NULL;
	size_t pp = p, qq = q;

	printf("p: %d, p2: %d, q: %d, q2: %d, r: %d, length: %d \n",
		p,
		q - p,
		q,
		r - q,
		r,
		r - p);

	for (size_t n = 0; n < length; n++) {
		if (p < qq) { // up to qq?
			left = &row[p];
		} else {
			left = NULL;
		}

		if (q < r) {
			right = &row[q];
		} else {
			right = NULL;
		}

		if (left != NULL && right != NULL) {
			if (*left <= *right) {
				copy[n] = *left;
				p++;
			} else {
				copy[n] = *right;
				q++;
			}
		} else if (left != NULL) {
			copy[n] = *left;
			p++;
		} else if (right != NULL) {
			copy[n] = *right;
			q++;
		} else {
			printf(" undefined loop \n");
		}
	}

	for (size_t n = pp, k = 0; k < length; k++) {
		row[n + k] = copy[k];
	}

	// r is not a limit - its the LAST element
	// printf("p: %zu, r: %zu - ", p, r);
	// printf("q: %zu, r: %zu\n", q, r);

	free(copy);
}