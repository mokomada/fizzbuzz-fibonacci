#include <stdio.h>
#include <Windows.h>

int main( ) {
	// �ϐ��̐錾
	int num[10], old[10], oldold[10]; // Fn,Fn-1,Fn-2��3�̐��l��ێ�����ϐ�
	int idno; // �z������ڂ܂Ŏg���Ă��邩
	int adjust = 0; // ���J��オ�莞�̕␳
	int digitChk = 100000000; // �����`�F�b�N�p
	bool endflag = false;

	// �ϐ��̏�����
	for(int i = 0; i < 10; i++) {
		num[i] = 0;
		oldold[i] = 0;
		old[i] = 0;
	}
	old[0] = 1;
	idno = 1;

	// �Œ��F0��F1��\��
	printf("%d\n", oldold[0]);
	Sleep(500);

	printf("%d\n", old[0]);
	Sleep(500);

	// �L�[���̓N���A
	rewind(stdin);

	while( (!GetAsyncKeyState(VK_ESCAPE) && !GetAsyncKeyState(VK_RETURN) ) && !endflag) {
		for(int i = 0; i < idno; i++) {
			// �O2��̐��l�𑫂���1�O�iold�j��2�O�ioldold�j���X�V
			num[i] = old[i] + oldold[i] + adjust;
			oldold[i] = old[i];
			old[i] = num[i];

			adjust = 0; // �␳�l�͖���0��
			// int�^�̌��E��20��������ƂȂ̂ŁA10���𒴂����玟�̔z��ֈړ��iold�����ɒ��g��num�Ȃ̂ňꏏ��-10������)
			if(num[i] >= 1000000000) {
				num[i] -= 1000000000;
				old[i] -= 1000000000;
				adjust = 1; // �J��オ���Ă���̂Ŏ��̌�����+1���������A�����₵�Ă�num[i]=old[i]+oldold[i]�ŏ㏑�������̂�adjust���g���ĕ␳����
				// �����܂��g���Ă��Ȃ��z��𗘗p�����Ȃ�IDNo�𑝂₷
				if(i + 1 == idno) {
					// �z���0�`9�܂ł����Ȃ��̂ŁAidno��9�̎��Ɍ�����ꂽ��I��
					if(idno < 9) {
						idno++;
					}
					else {
						endflag = true;
						printf("����ȏ�̌����͕\���ł��܂���B�I�����܂�\n[>PUSH ENTER");
						getchar( );
					}
				}
			}
		}

		// �����\��
		if(!endflag) {
			for(int i = idno - 1; i >= 0; i--) {
				// ��ԍ��������ȊO��0�X�^�[�g�������ꍇ��0�������i[1]=10�A[0]=000000009 ����109�\���ɂȂ�j�̂Ō����ɉ�����0��␳
				if(i != idno - 1) {
					digitChk = 100000000; // �����`�F�b�N�p
					// �K�v�ȕ�����0��printf
					for(int j = 0; j < 8; j++) {
						if(num[i] < digitChk) {
							printf("0");
							digitChk /= 10;
						}
						// ���݂�digitChk�ȉ��łȂ���΁A����ȍ~��digitChk�ȉ��ɂ͂Ȃ蓾�Ȃ��̂�for���I��
						else {
							break;
						}
					}
				}
				// �ォ�珇�Ԃɐ�����\��
				printf("%d", num[i]);
			}
			// ������S�ĕ\����������s
			printf("\n");
		}
		// 0.5�b�ҋ@
		Sleep(500);
	}
}