
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>


int hamming_distance(unsigned x, unsigned y)
{
    return __builtin_popcount(x ^ y);
}

void hamming_distance_word(const char* a, const char* b) {

	int l = strlen(a);

	if( l != strlen(b) ) {
		// strings must be equal in length 
		return;
	}

	int distance = 0;
	for(int i=0; i<l; i++) {
		if( 0 != hamming_distance(a[i], b[i])) {
			distance++;
		}
	}
	printf("%s <-> %s : %d\n", a, b, distance);
}

int main() {

	char* hotzenplotz = "hotzenplotz";

	FILE* fp = fopen("/usr/share/dict/words", "r");
	if(fp == NULL) {
		fprintf(stderr, "%s\n", strerror(errno));
		return -1;
	}

	//char line[256];
	char* word = NULL;
	size_t len = 0;
	ssize_t read;
	while ((read = getline(&word, &len, fp)) != -1) {

		// getline returns the trailing '\n'
		// remove it
		word[ strlen(word)-1 ] = '\0';

		hamming_distance_word(hotzenplotz, word);
	}

	fclose(fp);

	return 0;
}
