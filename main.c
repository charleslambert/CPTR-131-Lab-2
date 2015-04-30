#include "scheduler.h"

int main() {
	char mode;

	printf("If you would like interactive mode type I\n");
	printf("If you would like file mode type F\n");
	printf("input?: ");
	scanf("%c", &mode);

	//Checks for mode desired by user
	if (mode == 'I') { 
		i_mode();
		return 0;
	}
	else if (mode == 'F') {
		f_mode();
		return 0;
	}
	else {
		printf("\nInvalid Command");
		return 1;
	}

	return 0;
}