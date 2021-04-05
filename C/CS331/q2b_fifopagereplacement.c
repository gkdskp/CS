/* Implement the FIFO page replacement algorithm */

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

int main() {
	int no_of_frames;
	char page_ref_stream[MAX_PAGEREF_LENGTH];
	char * frames;

	int page_faults = 0;
	int fifo_idx = 0;

	printf("Enter number of page frames: ");
	scanf("%d%*c", &no_of_frames);

	frames = malloc(sizeof(char) * no_of_frames);

	printf("Enter the page reference stream: ");
	scanf("%[^\n]%*c", page_ref_stream);

	for(int i = 0; page_ref_stream[i] != '\0'; i++) {
		if(find_in_frame(frames, no_of_frames, page_ref_stream[i]) == -1) {
			printf("Page fault for %c\n", page_ref_stream[i]);
			page_faults++;
			frames[fifo_idx] = page_ref_stream[i];
			fifo_idx = (fifo_idx + 1) % no_of_frames;
		} else {
			printf("Page hit for %c\n", page_ref_stream[i]);
		}


		printf("Curr frames: ");
		for(int j = 0; j < no_of_frames; j++) printf("%c ", frames[j]);
		printf("\n");
	}

	printf("\nNumber of page faults = %d\n", page_faults);
	return 0;
}