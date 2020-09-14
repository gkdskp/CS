/* Simulate the following page replacement algorithms.
	a) FIFO
	b) LRU 
	c) LFU */

#include <stdio.h>
#include <stdlib.h>

int contains(int * arr, int n, int q)
{
	for(size_t i = 0; i < n; i++)
	{
		if(arr[i] == q)
			return i;
	}

	return 0;
}

void print_arr(int * arr, int n) {
	for(size_t i = 0; i < n; i++) printf("%d\t", arr[i]);

	printf("\n");
}

void fifo(int * frames, int * pages, size_t n_frames, size_t n_pages)
{
	size_t i, queue = 0;
	int n_faults = 0, n_hits = 0;

	for(i = 0; i < n_pages; i++)
	{
		printf("\nCurrent page: %d", pages[i]);

		if(! contains(frames, n_frames, pages[i]))
		{
			frames[queue] = pages[i];
			++n_faults;
			printf("\nFault");
			queue = (queue+1) % n_frames;
		}
		else
		{
			++n_hits;
			printf("\nHit");
		}
		
		printf("\nFrames: ");
		print_arr(frames, n_frames);
	}

	printf("\nNumber of pages faults: %d\n", n_faults);
}

int find_lru(int * last_used, int n)
{
	int lru = 0, lru_count = 0;

	for(size_t i = 0; i < n; ++i)
	{
		if(last_used[i] < lru_count)
		{
			lru_count = last_used[i];
			lru = i;
		}
		++i;
	}

	return lru;
}

void lru(int * frames, int * pages, size_t n_frames, size_t n_pages)
{
	size_t i, index;
	int n_hits = 0, n_faults = 0;
	int * last_used = malloc(n_frames * sizeof(int));

	for(i = 0; i < n_frames; i++) last_used[i] = 0;

	for(i = 0; i < n_pages; i++)
	{
		printf("\nCurrent page: %d", pages[i]);

		if(!(index = contains(frames, n_frames, pages[i])))
		{
			if(i < n_frames) index = i;
			
			else {
				index = find_lru(last_used, n_frames);
			}

			++n_faults;
			printf("\nFault");
			frames[index] = pages[i];
		}
		else
		{
			++n_hits;
			printf("\nHit");
		}
		last_used[index] = n_faults + n_hits;
		printf("\nFrames: ");
		print_arr(frames, n_frames);
	}

	printf("\nNumber of faults: %d\n", n_faults);
}

int find_lfu(int * freq_used, int n)
{
	int lfu = 0, lfu_count = 0;

	for(size_t i = 0; i < n; ++i)
	{
		if(freq_used[i] < lfu_count)
		{
			lfu_count = freq_used[i];
			lfu = i;
		}
		++i;
	}

	return lfu;
}

void lfu(int * frames, int * pages, size_t n_frames, size_t n_pages)
{
	size_t i, index;
	int n_hits = 0, n_faults = 0;
	int * freq_used = malloc(n_frames * sizeof(int));

	for(i = 0; i < n_frames; i++) freq_used[i] = 0;

	for(i = 0; i < n_pages; i++)
	{
		printf("\nCurrent page: %d", pages[i]);

		if(!(index = contains(frames, n_frames, pages[i])))
		{
			if(i < n_frames) index = i;
			
			else {
				index = find_lfu(freq_used, n_frames);
			}

			++n_faults;
			printf("\nFault");
			frames[index] = pages[i];
		}
		else
		{
			++n_hits;
			printf("\nHit");
		}
		freq_used[index]++;
		printf("\nFrames: ");
		print_arr(frames, n_frames);
	}

	printf("\nNumber of faults: %d\n", n_faults);
}

void main()
{
	size_t n_frames, n_pages, i = 0;
	int * pages, * frames, choice;

	printf("Enter number of frames: ");
	scanf("%d", &n_frames);

	printf("\nEnter number of pages: ");
	scanf("%d", &n_pages);

	frames = malloc(n_frames * sizeof(int));
	pages = malloc(n_pages * sizeof(int));

	for(i = 0; i < n_frames; i++) frames[i] = -1;

	printf("\nEnter reference string: ");
	for(i = 0; i < n_pages; i++) scanf("%d", &pages[i]);

	printf(
		"\nSelect the algorithm to use:"
		"\n\t1. FIFO"
		"\n\t2. LRU"
		"\n\t3. LRU\n"
	);
	scanf("%d", &choice);

	switch(choice)
	{
		case 1:
			fifo(frames, pages, n_frames, n_pages);
			break;
		
		case 2:
			lru(frames, pages, n_frames, n_pages);
			break;

		case 3:
			lfu(frames, pages, n_frames, n_pages);
			break;

	}
}