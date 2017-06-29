#include <stdio.h>
#include <Windows.h>

int main( ) {
	int num, old, oldold;
	num = oldold = 0;
	old = 1;

	rewind(stdin);

	printf("%d\n", oldold);
	Sleep(500);

	printf("%d\n", old);
	Sleep(500);

	while(!GetAsyncKeyState(VK_ESCAPE) && !GetAsyncKeyState(VK_RETURN) ) {
		num = old + oldold;
		oldold = old;
		old = num;

		printf("%d\n", num);

		Sleep(500);
	}
}