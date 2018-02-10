#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
using namespace std;

int setRand( void );

int main() {
	srand((unsigned int) time(NULL));

	vector<int> number(10);
	for ( int i = 0; i < 10; i++ ) {
		number[i] = setRand();
		cout << i << ":\t" << number[i] << endl;
	}
	cout << "追加後:" << endl;
	for ( int i = 0; i < 2; i++ ) {
		number.push_back(setRand());
	}
	for ( int i = 0; i < number.size(); i++ ) {
		cout << i << ":\t" << number[i] << endl;
	}
	return 0;
}

int setRand() {
	return rand() % 10;
}

/*
vectorのメモ(using namespace std;)
《宣言》
・vector<型> 変数名;
	変数名が実際はオブジェクト名。要素数は0で、使うときにデータを追加する必要がある。
・vector<型> 変数名(個数);
	最初の要素数がわかっていればこちらを使い、処理を少なくする。
	実際は(個数)はコンストラクタの引数。
	# 通常ならば「型 変数名[個数];」。
・vector<型> 変数名(個数, 一律の値);
	個数(個)の変数を、すべて一律の値で初期化する。
・vector<型> 変数名 = {値0, 値1, ..., 値n-1};
	1要素ずつ値を指定して初期化。
	# 通常ならば「型 変数名[個数]　= {値,値,..};」
《動的配列のコピー》
・vector<型> 変数名(別の変数名);
	別の動的配列をコピーする。
	実際はコピーする役割を担うコンストラクタ「コピーコンストラクタ」が動作している。
《２次元の動的配列》
・vector<vector<型>> 変数名{{値,値,..},{値,値,..}};
	vectorを入れ子にしている。
	参照は普通に「変数名[x][y]」で可能。
《代入》
・b = a;
	vectorでも型が同じならば可能
・変数名.assign(&配列[a], &配列[b]);
	配列[a]から配列[b]までの値を一挙に代入する。
・変数名.assign(要素数, 値);
	初期化代わりになる。
	宣言時に同じ挙動をするのは「vector<型> 変数名(個数, 一律の値);」?
《参照》
・変数名[n]
	普通の配列と同じ
・変数名.at(n)
	参照も代入もできる
	data.at(20) = 20;	// forループで応用
・イテレータ
	vector<int>::iterator itr;
	itr = 変数名.begin();	// end()でも
	cout << *itr << endl;	// *itrは値
	*itr = 値;	// 普通のポインタ変数と扱いは変わらない
	vector<int>::iteratorの代わりにautoをよく使う。
《追加》
・変数名.push_back(末尾に追加する値);
・型がクラスの時は別の書き方
・変数名.insert(変数名.begin() + n, 値);

《削除》
《そのほか》
・変数名.size()	要素数

参考URL: http://vivi.dyndns.org/tech/cpp/vector.html
*/

