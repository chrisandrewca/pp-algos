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

	printf("shuffle\n\n");

	int some_integers[5] = {1, 2, 3, 4, 5};
	size_t select = 0;
	for (size_t i = 0; i < 5; i++) {
		int store = some_integers[i];
		some_integers[i] = some_integers[select];
		some_integers[select] = store;
		select++;
	}

	for (size_t i = 0; i < 5; i++) {
		printf(" %d ", some_integers[i]);
	}
	printf("\n\n");

	some_integers[0] = 1;
	some_integers[1] = 2;
	some_integers[2] = 3;
	some_integers[3] = 4;
	some_integers[4] = 5;

	select = 3;
	for (size_t i = 0; i < 5; i++) {

		int store = some_integers[i];
		some_integers[i] = some_integers[select];
		some_integers[select] = store;
		select++;

		if (select >= 4) {
			select = 0;
		}
	}

	for (size_t i = 0; i < 5; i++) {
		printf(" %d ", some_integers[i]);
	}
}

// recursive calls are a LIFO stack
// think about applicability for search algorithms on graphs
void do_merge_sort(size_t starti, size_t row_size, int row[]) {

	if (starti < row_size) {

		size_t middlei = (starti + row_size) / 2;

		// printf("%zu, %zu, %zu\n", starti, middlei, row_size);

		do_merge_sort(starti, middlei, row);

		do_merge_sort(middlei + 1, row_size, row);

		merge(starti, middlei, row_size, row);
	}
}

void merge(size_t starti, size_t middlei, size_t row_size, int row[]) {

	// we've seen that i <= j
	size_t i = starti;
	size_t j = middlei;
	printf("ith: %zu, jth: %zu\n", i, j);

	// we've seen ilimit and rlimit are not always

	//size_t ilimit = middlei - starti + 1;
	//size_t rlimit = row_size - middlei;

	// size_t ilimit = middlei;
	// size_t rlimit = row_size - middlei;
	// printf("ilimit: %zu, rlimit: %zu, rs: %zu\n", ilimit, rlimit, row_size);

	// we've seen rs = jth + rlimit.. but in terms of # of copies...
	/*
		ith: 2, jth: 2
		ilimit: 1, rlimit: 1, rs: 3
	*/
	// it seems considered elements < # of copies = free elements being copied - perf/hooks?
	// in algo's book - once L || R at limit + 1 -> infinity -> ith || jth not increased again / fallthrough

	// int *copy = malloc(row_size * sizeof(int));

	// Q: Do we need to limit the number of additional permutations to 0?
		// aka - does this recursive algorithm rely on guarantee of permutations of length N to be interpreted
			// in sorted order by some N steps of work?

	// "do left"
	// "do right"
	// "do remainder" <-

	int range[100];
	for (size_t n = 0; n < 100; n++) {
		range[n] = -14;
	}

	int nth_value = 0;
	// when i/j cant move its infinity so that 8/8 > i/j
	for (size_t n = starti; n < row_size; n++) { // cannot limit j here to row_size in case i still accessing elements

		// int storage = row[n];

		// it seems i <= j
		if (i > j) {
			printf("i > j, %zu, %zu\n", i, j);
		}

		// it seems i < middlei || row_size
		if (i > middlei || i > row_size) {
			printf("i > middlei || row_size, %zu, %zu, %zu\n", i, middlei, row_size);
		}

		// it seems j > row_size
		if (j > row_size) {
			// printf("j > row_size, %zu, %zu\n", j, row_size);
		}

		if (row[i] < row[j]) {
			nth_value = row[n];
			row[n] = row[i];
			row[i] = nth_value; // stale?

			if (row[i] > row[i + 1]) {
				row[i] = row[i + 1];
				row[i + 1] = nth_value;
			}

			range[n] = row[i];

			i++;
		} else {
			nth_value = row[n];
			row[n] = row[j];
			row[j] = nth_value; // stale?

			if (row[j] > row[j + 1]) {
				row[j] = row[j + 1];
				row[j + 1] = nth_value;
			}

			range[n] = row[j];

			j++;
		}
	}

	for (size_t n = 0; n < row_size; n++) {
		printf(" %d ", range[n]);
	}

	for (size_t n = 0; n < 100; n++) {
		range[n] = -14;
	}

	printf("\n\n");
	

	// for (size_t n = starti; n < row_size; n++) {
	// 	if (row[i] <= row[j]) {
	// 		row[n] = row[i++];
	// 	} else {
	// 		row[n] = row[j++];
	// 	}
	// }

	// for (size_t i = 0; i < row_size; i++) {
	// 	printf("%d ", copy[i]);
	// }

	// printf("\n");
	// free(copy);
}