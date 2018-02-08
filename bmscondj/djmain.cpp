#include "DxLib.h"

int Key[256]; // キーが押されているフレーム数を格納する
int Padin[32];
int gPlayer = 1;
int gResound = 10;
int Pad;
int key1, key2, key3, key4, key5, key6, key7, sara;
int key1p, key2p, key3p, key4p, key5p, key6p, key7p, sarap;
int p1p, p2p, p1pp, p2pp;
int m1, m2, m3, m4, m5, m6, m7, m8;

			  // キーの入力状態を更新する
int gpUpdateKey() {
	char tmpKey[256]; // 現在のキーの入力状態を格納する
	GetHitKeyStateAll(tmpKey); // 全てのキーの入力状態を得る
	for (int i = 0; i<256; i++) {
		if (tmpKey[i] != 0) { // i番のキーコードに対応するキーが押されていたら
			Key[i]++;     // 加算
		}
		else {              // 押されていなければ
			Key[i] = 0;   // 0にする
		}
	}
	return 0;
}

int gpUpdatePad() {
	Pad = GetJoypadInputState(DX_INPUT_KEY_PAD1);        //入力状態をPadに格納
	for (int i = 0; i<28; i++) {      //ボタン28個分ループ
		if (Pad & (1 << i)) {             //ボタンiの入力フラグが立っていたら
//			DrawFormatString(0, 0, GetColor(255, 255, 255), "%dのキーが押されています", i);
			Padin[i]++;
		}
		else {
			Padin[i] = 0;
		}
	}
	return 0;
}

void mainloop() {
	gpUpdateKey();
	DrawGraph(10+64, 36, key1, TRUE);
	DrawGraph(18+64, 10, key2, TRUE);
	DrawGraph(28+64, 36, key3, TRUE);
	DrawGraph(36+64, 10, key4, TRUE);
	DrawGraph(46+64, 36, key5, TRUE);
	DrawGraph(54+64, 10, key6, TRUE);
	DrawGraph(64+64, 36, key7, TRUE);
	DrawGraph(10, 10, sara, TRUE);
	DrawGraph(122, 70, p1pp, TRUE);
	DrawGraph(137, 70, p2p, TRUE);
	DrawBox(0, 0, 152, 70, GetColor(50, 50, 50), FALSE);
	DrawBox(1, 1, 151, 69, GetColor(50, 50, 50), FALSE);
	Pad = GetJoypadInputState(DX_INPUT_KEY_PAD1);

	if (Key[KEY_INPUT_Z] > 0 || Key[KEY_INPUT_COMMA] > 0 || Padin[7] > 0) {
		DrawGraph(10+64, 36, key1p, TRUE);

		if (Key[KEY_INPUT_Z] == 1 || Key[KEY_INPUT_COMMA] == 1 || Padin[7] == 1) {
			PlaySoundMem(m1, DX_PLAYTYPE_BACK,TRUE);
		}
	}

	if (Key[KEY_INPUT_S] > 0 || Key[KEY_INPUT_L] > 0 || Padin[10] > 0) {
		DrawGraph(18+64, 10, key2p, TRUE);

		if (Key[KEY_INPUT_S] == 1 || Key[KEY_INPUT_L] == 1 || Padin[10] == 1) {
			PlaySoundMem(m2, DX_PLAYTYPE_BACK,TRUE);
		}
	}

	if (Key[KEY_INPUT_X] > 0 || Key[KEY_INPUT_PERIOD] > 0 || Padin[6] > 0) {
		DrawGraph(28+64, 36, key3p, TRUE);
		if (Key[KEY_INPUT_X] == 1 || Key[KEY_INPUT_PERIOD] == 1 || Padin[6] == 1) {
			PlaySoundMem(m3, DX_PLAYTYPE_BACK, TRUE);
		}
	}

	if (Key[KEY_INPUT_D] > 0 || Key[KEY_INPUT_SEMICOLON] > 0 || Padin[11] > 0) {
		DrawGraph(36+64, 10, key4p, TRUE);
		if (Key[KEY_INPUT_D] == 1 || Key[KEY_INPUT_SEMICOLON] == 1 || Padin[11] == 1) {
			PlaySoundMem(m4, DX_PLAYTYPE_BACK, TRUE);
		}
	}

	if (Key[KEY_INPUT_C] > 0 || Key[KEY_INPUT_SLASH] > 0 || Padin[5] > 0) {
		DrawGraph(46+64, 36, key5p, TRUE);
		if (Key[KEY_INPUT_C] == 1 || Key[KEY_INPUT_SLASH] == 1 || Padin[5] == 1) {
			PlaySoundMem(m5, DX_PLAYTYPE_BACK, TRUE);
		}
	}

	if (Key[KEY_INPUT_F] > 0 || Key[KEY_INPUT_COLON] > 0 || Padin[8] > 0) {
		DrawGraph(54+64, 10, key6p, TRUE);
		if (Key[KEY_INPUT_F] == 1 || Key[KEY_INPUT_COLON] == 1 || Padin[8] == 1) {
			PlaySoundMem(m6, DX_PLAYTYPE_BACK, TRUE);
		}
	}

	if (Key[KEY_INPUT_V] > 0 || Key[KEY_INPUT_BACKSLASH] > 0 || Padin[1] > 0) {
		DrawGraph(64+64, 36, key7p, TRUE);
		if (Key[KEY_INPUT_V] == 1 || Key[KEY_INPUT_BACKSLASH] == 1 || Padin[1] == 1) {
			PlaySoundMem(m7, DX_PLAYTYPE_BACK, TRUE);
		}
	}

	if (Key[KEY_INPUT_LSHIFT] > 0 || Key[KEY_INPUT_RSHIFT] > 0 || Padin[0] > 0 || Padin[3] > 0){
		DrawGraph(10, 10, sarap, TRUE);
		if (Key[KEY_INPUT_LSHIFT] == 1 || Key[KEY_INPUT_RSHIFT] ==1 || Padin[0] == 1 || Padin[3] == 1) {
			PlaySoundMem(m8, DX_PLAYTYPE_BACK, TRUE);
		}
	}
}

void mainloop2() {
	gpUpdateKey();
	DrawGraph(10, 36, key1, TRUE);
	DrawGraph(18, 10, key2, TRUE);
	DrawGraph(28, 36, key3, TRUE);
	DrawGraph(36, 10, key4, TRUE);
	DrawGraph(46, 36, key5, TRUE);
	DrawGraph(54, 10, key6, TRUE);
	DrawGraph(64, 36, key7, TRUE);
	DrawGraph(94, 10, sara, TRUE);
	DrawGraph(122, 70, p1p, TRUE);
	DrawGraph(137, 70, p2pp, TRUE);
	DrawBox(0, 0, 152, 70, GetColor(50, 50, 50), FALSE);
	DrawBox(1, 1, 151, 69, GetColor(50, 50, 50), FALSE);

	if (Key[KEY_INPUT_Z] > 0 || Key[KEY_INPUT_COMMA] > 0 || Padin[7] > 0) {
		DrawGraph(10, 36, key1p, TRUE);

		if (Key[KEY_INPUT_Z] == 1 || Key[KEY_INPUT_COMMA] == 1 || Padin[7] == 1) {
			PlaySoundMem(m1, DX_PLAYTYPE_BACK, TRUE);
		}
	}

	if (Key[KEY_INPUT_S] > 0 || Key[KEY_INPUT_L] > 0 || Padin[10] > 0) {
		DrawGraph(18, 10, key2p, TRUE);

		if (Key[KEY_INPUT_S] == 1 || Key[KEY_INPUT_L] == 1 || Padin[10] == 1) {
			PlaySoundMem(m2, DX_PLAYTYPE_BACK, TRUE);
		}
	}

	if (Key[KEY_INPUT_X] > 0 || Key[KEY_INPUT_PERIOD] > 0 || Padin[6] > 0) {
		DrawGraph(28, 36, key3p, TRUE);
		if (Key[KEY_INPUT_X] == 1 || Key[KEY_INPUT_PERIOD] == 1 || Padin[6] == 1) {
			PlaySoundMem(m3, DX_PLAYTYPE_BACK, TRUE);
		}
	}

	if (Key[KEY_INPUT_D] > 0 || Key[KEY_INPUT_SEMICOLON] > 0 || Padin[11] > 0) {
		DrawGraph(36, 10, key4p, TRUE);
		if (Key[KEY_INPUT_D] == 1 || Key[KEY_INPUT_SEMICOLON] == 1 || Padin[11] == 1) {
			PlaySoundMem(m4, DX_PLAYTYPE_BACK, TRUE);
		}
	}

	if (Key[KEY_INPUT_C] > 0 || Key[KEY_INPUT_SLASH] > 0 || Padin[5] > 0) {
		DrawGraph(46, 36, key5p, TRUE);
		if (Key[KEY_INPUT_C] == 1 || Key[KEY_INPUT_SLASH] == 1 || Padin[5] == 1) {
			PlaySoundMem(m5, DX_PLAYTYPE_BACK, TRUE);
		}
	}

	if (Key[KEY_INPUT_F] > 0 || Key[KEY_INPUT_COLON] > 0 || Padin[8] > 0) {
		DrawGraph(54, 10, key6p, TRUE);
		if (Key[KEY_INPUT_F] == 1 || Key[KEY_INPUT_COLON] == 1 || Padin[8] == 1) {
			PlaySoundMem(m6, DX_PLAYTYPE_BACK, TRUE);
		}
	}

	if (Key[KEY_INPUT_V] > 0 || Key[KEY_INPUT_BACKSLASH] > 0 || Padin[1] > 0) {
		DrawGraph(64, 36, key7p, TRUE);
		if (Key[KEY_INPUT_V] == 1 || Key[KEY_INPUT_BACKSLASH] == 1 || Padin[1] == 1) {
			PlaySoundMem(m7, DX_PLAYTYPE_BACK, TRUE);
		}
	}

	if (Key[KEY_INPUT_LSHIFT] > 0 || Key[KEY_INPUT_RSHIFT] > 0 || Padin[0] > 0 || Padin[3] > 0) {
		DrawGraph(94, 10, sarap, TRUE);
		if (Key[KEY_INPUT_LSHIFT] == 1 || Key[KEY_INPUT_RSHIFT] == 1 || Padin[0] == 1 || Padin[3] == 1) {
			PlaySoundMem(m8, DX_PLAYTYPE_BACK, TRUE);
		}
	}
}

void resound(int i) {
	
}

// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	SetWindowSizeChangeEnableFlag(FALSE, FALSE); // ウインドウのサイズを手動ではできず、且つウインドウのサイズに合わせて拡大もしないようにする
	SetWindowSize(152, 76);
	// メインウインドウのバックグラウンドカラーを設定する(各色0～255)
	ChangeWindowMode(TRUE);
	SetDrawScreen(DX_SCREEN_BACK);
	SetBackgroundColor(185, 185, 185);

	if (DxLib_Init() == -1)		// ＤＸライブラリ初期化処理
	{
		return -1;			// エラーが起きたら直ちに終了
	}

	key1 = LoadGraph("./dot/key.png");
	key2 = LoadGraph("./dot/key2.png");
	key3 = LoadGraph("./dot/key.png");
	key4 = LoadGraph("./dot/key2.png");
	key5 = LoadGraph("./dot/key.png");
	key6 = LoadGraph("./dot/key2.png");
	key7 = LoadGraph("./dot/key.png");
	sara = LoadGraph("./dot/sara.png");
	key1p = LoadGraph("./dot/keyp.png");
	key2p = LoadGraph("./dot/keyp.png");
	key3p = LoadGraph("./dot/keyp.png");
	key4p = LoadGraph("./dot/keyp.png");
	key5p = LoadGraph("./dot/keyp.png");
	key6p = LoadGraph("./dot/keyp.png");
	key7p = LoadGraph("./dot/keyp.png");
	sarap = LoadGraph("./dot/sarap.png");
	p1p = LoadGraph("./dot/1p.png");
	p2p = LoadGraph("./dot/2p.png");
	p1pp = LoadGraph("./dot/1pp.png");
	p2pp = LoadGraph("./dot/2pp.png");
	m1 = LoadSoundMem("./wav/m1.mp3", gResound);
	m2 = LoadSoundMem("./wav/m2.mp3", gResound);
	m3 = LoadSoundMem("./wav/m3.mp3", gResound);
	m4 = LoadSoundMem("./wav/m4.mp3", gResound);
	m5 = LoadSoundMem("./wav/m5.mp3", gResound);
	m6 = LoadSoundMem("./wav/m6.mp3", gResound);
	m7 = LoadSoundMem("./wav/m7.mp3", gResound);
	m8 = LoadSoundMem("./wav/m8.mp3", gResound);


while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0) {
	gpUpdatePad();


	if (Key[KEY_INPUT_F1] == 1) {
		gPlayer = 1;
	}
	if (Key[KEY_INPUT_F2] == 1) {
		gPlayer = 2;
	}

	if(gPlayer == 1){
		mainloop();
		}
	if (gPlayer == 2) {
		mainloop2();
	}
}

	WaitKey();
	DxLib_End();				// ＤＸライブラリ使用の終了処理
	return 0;				// ソフトの終了 
}