#include <Novice.h>
#include<Function.h>
const char kWindowTitle[] = "LE2B_29_ヨシダタケル";

	
static const int kRowHeight = 20;
static const int kColumnWidth = 60;
void MatrixScreenPrintf(int x, int y, Matrix4x4 matrix) {
	for (int row = 0; row < 4; ++row) {
		for (int column = 0; column < 4; ++column) {
			Novice::ScreenPrintf(
			    x + column * kColumnWidth, y + row * kRowHeight, "%.02f", matrix.m[row][column]);
		}
	}
}

// void VectorScreenPrintf(int x, int y, Vector3 vector) {
//	Novice::ScreenPrintf(x, y, "%.02f", vector.x);
//	Novice::ScreenPrintf(x + kColumnWidth, y, "%.02f", vector.y);
// }
// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);
	Matrix4x4 m1 =
	{
	    3.2f,0.7f,9.6f,4.4f,
	    5.5f,1.3f,7.8f,2.1f,
	    6.9f,8.0f,2.6f,1.0f,
	    0.5f,7.2f,5.1f,3.3f,
	};

	Matrix4x4 m2 =
	{
	4.1f,6.5f,3.3f,2.2f,
	8.8f,0.6f,9.9f,7.7f,
	1.1f,5.5f,6.6f,0.0f,
	3.3f,9.9f,8.8f,2.2f
	};
	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///
		
		Matrix4x4 resultAdd = Add(m1, m2);
		Matrix4x4 resultSudtract = Sudtract(m1, m2);
		Matrix4x4 resultMultiply = Multiply(m1, m2);
		Matrix4x4 resultinVerseM1 = inVerseM1(m1);
		Matrix4x4 resultinVerseM2 = inVerseM2(m2);
		Matrix4x4 resulttransposeM1 = transposeM1(m1);
		Matrix4x4 resulttransposeM2 = transposeM2(m2);
		Matrix4x4 identity = MakeIdentity4x4(m1);
		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///
	   MatrixScreenPrintf(0, kRowHeight * 0, resultAdd);
	   MatrixScreenPrintf(0, kRowHeight * 5, resultSudtract);
	   MatrixScreenPrintf(0, kRowHeight * 10, resultMultiply);
	   MatrixScreenPrintf(0, kRowHeight * 15, resultinVerseM1);
	   MatrixScreenPrintf(0, kRowHeight * 20, resultinVerseM2);
	   MatrixScreenPrintf(0, kRowHeight * 25, resulttransposeM1);
	   MatrixScreenPrintf(0, kRowHeight * 30, resulttransposeM2);
	   MatrixScreenPrintf(600, kRowHeight * 0, identity);
		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
