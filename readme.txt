fibonacciフォルダとfizzbuzzフォルダが最初に書いたプログラムで、それぞれnewが付いているものが改善したものになります。
どちらも0.5秒毎に値を表示していき、エンターキーかEscキーを押すことで終了します。

fizzbuzzの方は多くの改善点が見つからず、同じ計算を複数の場所で行いたくなかったため、フラグを定義してそちらで3や5の倍数か否かを管理するようにしました。

fibonacciの方はint型で格納できる数値では少なく感じたため、配列を使って表示できる範囲を拡大しました。また、桁数が限界に達した場合にはそこで終了する旨を伝えて終了するようにしました。