#include <stdio.h>

int main() {

	char s[10];
	scanf("%s", s); // s = address of the 0th element of the array
	// s = &s[0]
	printf("%s\n", s);
	return 0;
}
