/* Implement the LRU page replacement algorithm */

#include <stdio.h>
#include <stdlib.h>

#define MAX_PAGEREF_LENGTH 25

int find_in_frame(char * frames, int no_of_frames, char query) {
	int i;
	for(i = 0; i < no_of_frames; i++) {
		if(frames[i] == query) return i;
	}

	return -1;
}

int find_min_lru(int * recently_used, int no_of_frames) {
	int min = recently_used[0];
	int min_idx = 0;

	for(int i = 0; i < no_of_frames; i++) {
		if(recently_used[i] <= min) {
			min_idx = i;
			min = recently_used[i];
		}
	}

	return min_idx;
}

int main() {
	int no_of_frames;
	char page_ref_stream[MAX_PAGEREF_LENGTH];
	char * frames;
	int * recently_used;

	int page_faults = 0;
	int lru;

	printf("Enter number of page frames: ");
	scanf("%d%*c", &no_of_frames);

	frames = malloc(sizeof(char) * no_of_frames);
	recently_used = malloc(sizeof(int) * no_of_frames);
	int curr_idx;

	printf("Enter the page reference stream: ");
	scanf("%[^\n]%*c", page_ref_stream);

	for(int i = 0; page_ref_stream[i] != '\0'; i++) {
		if((curr_idx = find_in_frame(frames, no_of_frames, page_ref_stream[i])) == -1) {
			printf("Page fault for %c\n", page_ref_stream[i]);
			page_faults++;
			lru = find_min_lru(recently_used, no_of_frames);
			frames[lru] = page_ref_stream[i];
			recently_used[lru] = i+1;
		} else {
			printf("Page hit for %c\n", page_ref_stream[i]);
			recently_used[curr_idx] = i+1;
		}

		printf("Curr frames: ");
		for(int j = 0; j < no_of_frames; j++) printf("%c ", frames[j]);
		printf("\n");
	}

	printf("\nNumber of page faults = %d\n", page_faults);
	return 0;
}