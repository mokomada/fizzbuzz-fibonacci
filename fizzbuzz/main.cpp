#include <stdio.h>
#include <Windows.h>

int main( ) {
	int cnt = 1;

	rewind(stdin);

	while(!GetAsyncKeyState(VK_ESCAPE) && !GetAsyncKeyState(VK_RETURN) ) {
		if(cnt % 3 == 0) {
			printf("Fizz");
		}
		if(cnt % 5 == 0) {
			printf("Buzz");
		}
		if(cnt % 3 != 0 && cnt % 5 != 0) {
			printf("%d", cnt);
		}
		printf("\n");

		Sleep(500);
		cnt++;
	}
}