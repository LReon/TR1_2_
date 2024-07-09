#include <Novice.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <stdlib.h>
#include "Vector2.h"
#include <cstdlib>

const char kWindowTitle[] = "LE2C_23_フジワラ_リオ";

//float easeOut(float x) {
//
//	return x * x;
//} 




// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	float posX = 0.0f;
	float posY = 0.0f;

	//float xSpeed = 5.0f;

	float gravity = 1.0f;

	float acceleration = 0.9f;

	float XMove = 30.0f;

	float time = 0.0f;

	float radius = 0.0f;

	int flag = 0;

	//float posX = { 0.0f };
	//float posY = { 0.0f };

	//float startX = { 0.0f };
	//float startY = { 0.0f };
	//float endX = { 0.0f };
	//float endY = { 0.0f };

	//float x = 0;

	//float endFrame = 50.0f;

	//float frame = 0.0f;
	//
	//int flag = 0;

	//
	//float radius = 5.0f;

	//float scale = 0.0f;
	

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



		if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {
			flag = 1;
			posX = float(rand() % 300 + 1);
			posY = float(rand() % 300 + 1);
			radius = 5.0f;
			gravity = 0.98f;
			XMove = 30.0f;
		}

		if (flag == 1) {
			gravity += acceleration;
			posX += XMove;
			posY += gravity;
			radius -= 0.2f;

		}

		if (radius <= 0) {
			flag = 0;
			time = 0;
		}



		//if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {

		//	if (flag == 0) {
		//		flag = 1;
		//		frame = 0.0f;
		//	}
		//	
		//		startX = float(rand() % 1280 + 1);
		//		startY = float(rand() % 720 + 1);
		//		endX = float(rand() % 1280 + 1);
		//		endY = float(rand() % 720 + 1);
		//		radius = float(rand() % 10 + 1);
		//		//scale = float(rand() % 1 + 1);
		//		//endFrame = float(rand() % 50 + 1);
		//		//radius[i] = int(rand() % 10 + 1);
		//	


		//}

		//if (flag == 1) {
		//	frame++;
		//	radius -= 0.1f;



		//	x = frame / endFrame;

		//	
		//		posX = startX + (endX - startX) * easeOut(x);
		//		posY = startY + (endY - startY) * easeOut(x);
		//	
		//	if (frame == endFrame) {
		//		flag = 0;
		//		radius = 5.0f;
		//	}


		//}

		

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///
		/// 
		
		Novice::DrawBox(0, 0, 1280, 720, 0.0f, BLACK, kFillModeSolid);

		
		if (radius >= 0) {

			Novice::DrawEllipse(int(posX), int(posY), int(radius), int(radius), 0.0f, WHITE, kFillModeSolid);
		}
		
		Novice::DrawBox(0, 0, 300, 300, 0.0f, WHITE, kFillModeWireFrame);
		
		Novice::ScreenPrintf(0, 0, "%f", XMove);

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
