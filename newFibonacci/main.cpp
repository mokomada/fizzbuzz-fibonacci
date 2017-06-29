#include <stdio.h>
#include <Windows.h>

int main( ) {
	// 変数の宣言
	int num[10], old[10], oldold[10]; // Fn,Fn-1,Fn-2の3つの数値を保持する変数
	int idno; // 配列を何個目まで使っているか
	int adjust = 0; // 桁繰り上がり時の補正
	int digitChk = 100000000; // 桁数チェック用
	bool endflag = false;

	// 変数の初期化
	for(int i = 0; i < 10; i++) {
		num[i] = 0;
		oldold[i] = 0;
		old[i] = 0;
	}
	old[0] = 1;
	idno = 1;

	// 固定のF0とF1を表示
	printf("%d\n", oldold[0]);
	Sleep(500);

	printf("%d\n", old[0]);
	Sleep(500);

	// キー入力クリア
	rewind(stdin);

	while( (!GetAsyncKeyState(VK_ESCAPE) && !GetAsyncKeyState(VK_RETURN) ) && !endflag) {
		for(int i = 0; i < idno; i++) {
			// 前2回の数値を足して1個前（old）と2個前（oldold）を更新
			num[i] = old[i] + oldold[i] + adjust;
			oldold[i] = old[i];
			old[i] = num[i];

			adjust = 0; // 補正値は毎回0に
			// int型の限界が20億ちょっとなので、10億を超えたら次の配列へ移動（oldも既に中身はnumなので一緒に-10億する)
			if(num[i] >= 1000000000) {
				num[i] -= 1000000000;
				old[i] -= 1000000000;
				adjust = 1; // 繰り上がっているので次の桁数を+1したいが、今増やしてもnum[i]=old[i]+oldold[i]で上書きされるのでadjustを使って補正する
				// もしまだ使っていない配列を利用したならIDNoを増やす
				if(i + 1 == idno) {
					// 配列は0～9までしかないので、idnoが9の時に桁が溢れたら終了
					if(idno < 9) {
						idno++;
					}
					else {
						endflag = true;
						printf("これ以上の桁数は表示できません。終了します\n[>PUSH ENTER");
						getchar( );
					}
				}
			}
		}

		// 数字表示
		if(!endflag) {
			for(int i = idno - 1; i >= 0; i--) {
				// 一番高い桁数以外が0スタートだった場合は0が削られる（[1]=10、[0]=000000009 だと109表示になる）ので桁数に応じて0を補正
				if(i != idno - 1) {
					digitChk = 100000000; // 桁数チェック用
					// 必要な分だけ0をprintf
					for(int j = 0; j < 8; j++) {
						if(num[i] < digitChk) {
							printf("0");
							digitChk /= 10;
						}
						// 現在のdigitChk以下でなければ、これ以降のdigitChk以下にはなり得ないのでfor分終了
						else {
							break;
						}
					}
				}
				// 上から順番に数字を表示
				printf("%d", num[i]);
			}
			// 数字を全て表示したら改行
			printf("\n");
		}
		// 0.5秒待機
		Sleep(500);
	}
}