#include <stdio.h>
#include <Windows.h>

int main( ) {
	// �ϐ��錾&������
	int cnt = 1;
	bool flag = true;

	// �L�[���͏�񃊃Z�b�g
	rewind(stdin);

	// �G���^�[�L�[ or Esc�L�[�ŏI��
	while(!GetAsyncKeyState(VK_ESCAPE) && !GetAsyncKeyState(VK_RETURN) ) {
		// 3�̔{����Fizz�\��
		if(cnt % 3 == 0) {
			printf("Fizz");
			flag = false;
		}

		// 5�̔{����Buzz�\��
		if(cnt % 5 == 0) {
			printf("Buzz");
			flag = false;
		}

		// 3�̔{���ł�5�̔{���ł��Ȃ���ΐ��l�\��
		if(flag) {
			printf("%d", cnt);
		}

		// ���s
		printf("\n");

		Sleep(500);
		cnt++;
		// �t���O���Z�b�g
		flag  = true;
	}
}