#include <stdio.h>
#include <Windows.h>

int main( ) {
	// 変数宣言&初期化
	int cnt = 1;
	bool flag = true;

	// キー入力情報リセット
	rewind(stdin);

	// エンターキー or Escキーで終了
	while(!GetAsyncKeyState(VK_ESCAPE) && !GetAsyncKeyState(VK_RETURN) ) {
		// 3の倍数でFizz表示
		if(cnt % 3 == 0) {
			printf("Fizz");
			flag = false;
		}

		// 5の倍数でBuzz表示
		if(cnt % 5 == 0) {
			printf("Buzz");
			flag = false;
		}

		// 3の倍数でも5の倍数でもなければ数値表示
		if(flag) {
			printf("%d", cnt);
		}

		// 改行
		printf("\n");

		Sleep(500);
		cnt++;
		// フラグリセット
		flag  = true;
	}
}