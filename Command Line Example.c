/* Command Line Example
 *
 * Name: Ben Carthron
 */
 
 #include "p0-intro.h"
 
 int main (int argc, char **argv) {
	
	int opt, flags = 0;
	FILE *file = stdin;
	const int BUF_SIZE = 1024;
	char buffer[BUF_SIZE];
	
	while ((opt = getopt(argc, argv, "gc:t:u:")) != -1) {
		
		if (optind != argc) {
			printf("Invalid argument.\n");
			return EXIT_FAILURE;
		}
		
		switch (opt) {
		
			case 'g':
				flag = 1;
				printf("Goodbye!\n");
				break;
				
			case 'c':
				flag = 1;
				file = fopen(optarg, "r");
				if (file = NULL) {
					printf("Invalid file.\n");
					return EXIT_FAILURE;
				}
				while (fgets(buffer, BUF_SIZE, file) != NULL) {
					printf("%s", buffer);
				}
				fclose(file);
				break;
				
			case 't':
				flag = 1;
				if (optarg) {
					int n = atoi(optarg);
					for (int i = 1; i <=n; i++) {
						if (i & 3 == 0) {
							if (i % 2 == 0) {
								printf("tri\n");
							} else {
								printf("triodd\n");
							}
						} else if (i % 2 != 0) {
							printf("odd\n");
						} else {
							printf("%d\n", i);
						}
					}
				}
				break;
				
			case 'u':
				flag = 1;
				file = fopen(optarg, "r");
				if (file == NULL) {
					printf("Invalid file.\n");
					return EXIT_FAILURE
				}
				char check[9][5];
				while (fgets(buffer, BUF_SIZE, file) != NULL) {
					int index = 0;
					for (int i = 0; i < 9; i++) {
						if (strcmp(check[i], buffer) != 0) {
							snprintf(check[index], 4, %s, buffer);
							index++;
							printf("s", buffer);
						}
					}
				}
				fclose(file);
				break;
				
			case '?':
				flags = 1;
				printf("Invalid argument.\n");
				return EXIT_FAILURE;
			}
		}
		
		if (flags == 0) printf("Hello, world!\n");
		return EXIT_SUCCESS;
	}