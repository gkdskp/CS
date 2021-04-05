/*  Implement an absolute loader */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	FILE * objcode, * output;
	char prgrm_name[20], prgrm_name_in_file[20], * token;
	char code, start_addr[20], total[20], line[50]; 
	int i, start_addri;

	if(! (objcode = fopen("objcode.txt", "r")))
	{
		printf("Please save the object code as objcode.txt");
		exit(0);
	}

	printf("Enter program name: ");
	scanf("%s", prgrm_name);

	// Reading the header record
	fscanf(objcode, "%c^%s", &code, line);
	strcpy(prgrm_name_in_file, strtok(line, "^"));

	// Verifying program name
	if(strcmp(prgrm_name, prgrm_name_in_file) != 0)
	{
		printf("Program name does not match\n");
		exit(0);
	}
	
	while(! feof(objcode))
	{
		fscanf(objcode, "%c^%s", &code, line);
		switch (code)
		{
			case 'T':
				strcpy(start_addr, strtok(line, "^"));
				start_addri = atoi(start_addr);
				
				// Ignoring the length string
				token = strtok(NULL, "^");
				token = strtok(NULL, "^");

				while(token != NULL)
				{
					for(i = 0; i < strlen(token); i += 2)
					{
						printf(
							"00%d %c%c\n", 
							start_addri, 
							token[i], 
							token[i+1]
						);
						++start_addri;
					}

					token = strtok(NULL, "^");
				}
				break;
			
			case 'E':
				fclose(objcode);
				return 0;
		}
	}
}