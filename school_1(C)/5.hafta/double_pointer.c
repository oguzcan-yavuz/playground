#include <stdio.h>

int main() {

	int i, *p, **q;
	i = 5;
	p = &i;
	q = &p;

	printf("%d\n%d\n%d\n", i, *p, **q);

	return 0;

}