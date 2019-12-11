
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>


int hamming_distance(unsigned x, unsigned y)
{
    return __builtin_popcount(x ^ y);
}

int hamming_distance_word(const char* a, const char* b) {

	int l = strlen(a);

	if( l != strlen(b) ) {
		// strings must be equal in length 
		return -1;
	}

	int distance = 0;
	for(int i=0; i<l; i++) {
		if( 0 != hamming_distance(a[i], b[i])) {
			distance++;
		}
	}
	return distance;
}

int main() {

	char* hotzenplotz = "hotzenplotz";

	FILE* fp = fopen("/usr/share/dict/words", "r");
	if(fp == NULL) {
		fprintf(stderr, "%s\n", strerror(errno));
		return -1;
	}

	int* summary = malloc(strlen(hotzenplotz) * sizeof(int));
	int no_length_match = 0;
	for(int i=0; i<strlen(hotzenplotz); i++) {
		summary[i] = 0;
	}

	char* word = NULL;
	size_t len = 0;
	ssize_t read;
	int dist;
	while ((read = getline(&word, &len, fp)) != -1) {

		// getline returns the trailing '\n'
		// remove it
		word[ strlen(word)-1 ] = '\0';

		dist = hamming_distance_word(hotzenplotz, word);
		if( dist == -1 ) {
			no_length_match++;
		} else {

			summary[dist] ++;

			printf("%s <-> %s : %d\n", hotzenplotz, word, dist);
		}
	}

	printf("Summary:\n");
	printf("    Strings of different length:%d\n", no_length_match);
	for(int i=0; i<strlen(hotzenplotz); i++) {
		printf("    Strings of Hamming distance %d:%d\n", i, summary[i]);
	}

	fclose(fp);

	return 0;
}
