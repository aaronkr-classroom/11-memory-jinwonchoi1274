#include <stdio.h>
#include <string.h>
#include <stdlib.h> //rand(),srand()
#include <time.h> //time()

#define LENGTH 3 //길이
#define FACES 6 //면

//전역 변수 선언
char* colors[FACES] = { "white","red","blue","green","orange","yellow" };
char letters[FACES] = { 'W','R','B','G','O','Y'};
int hexColors[FACES] = { 0xFFF,0xF00,0x00F,0x0F0,0xFA0,0xFF0 };

//3x3x6배열로 큐브 상태 정의
int cube[LENGTH][LENGTH][FACES];

//프린트 모드 선택
enum Printmode {STRING, LETTERS, HEX};

//큐브 초기화 함수
void intCube() {
	for (int i = 0; i < FACES; i++) {
		for (int j = 0; j < LENGTH; j++) {
			for (int k = 0; k < LENGTH; k++) {
				cube[i][j][k] = i;
			}
				
		}
	}
}

//큐브 프린트 함수
void printCube(enum Printmode mode) {
	const char* labels[FACES] = {
		"UP","Left","Front","Right","Back","Down"
	};
	for (int i = 0; i < FACES; i++) {
		printf("%s face:\n", labels[i]);
		for (int j = 0; j < LENGTH; j++) {
			for (int k = 0; k < LENGTH; k++) {
				switch (mode) {
				case STRING:
					printf("%-7s", colors[cube[i][j][k]]);
					break;
				case LETTERS:
					printf("%c", letters[cube[i][j][k]]);
					break;
				case HEX:
					printf("%#05X", hexColors[cube[i][j][k]]);
					break;
				}
			}
			printf("\n"); //다음행으로
		}
		printf("\n");
	}
}
//90도 시계 방향 회전
void rotateFace(int face) {
	int temp[LENGTH][LENGTH]; //임시 변수에서 저장
	for (int i = 0; i < LENGTH; i++) {
		for (int j = 0; j < LENGTH; j++) {
			temp[i][j] = cube[face][i][j];
		}
	}
	for (int i = 0; i < LENGTH; i++) {
		for (int j = 0; j < LENGTH; j++) {
			cube[face][j][2 - i] = temp[i][j];
		}
	}
}

//큐브 섞기 함수 (랜덤 회전)
void scrambleCube() {
	printf("Scrambling...\n");
	srand(time(0));
	for (int i = 0; i < 15; i++) {
		int face = rand() % FACES;
		switch (face) {
		case 0: rotateFace(0); printf("U "); break;
		case 1: rotateFace(1); printf("L "); break;
		case 2: rotateFace(2); printf("F "); break;
		case 3: rotateFace(3); printf("R "); break;
		case 4: rotateFace(4); printf("B "); break;
		case 5: rotateFace(5); printf("D "); break;

		}
	}
}

void rotateRight() {
	int temp[LENGTH];
	//오른쪽 면 시계 방향 회전
	for (int i = 0; i < LENGTH; i++)temp[i] = cube[3][i][2];
	for (int i = 0; i < LENGTH; i++)cube[3][i][2] = cube[0][2][2-i];
	for (int i = 0; i < LENGTH; i++)cube[0][2][2-i] = cube[1][2-i][0];
	for (int i = 0; i < LENGTH; i++)cube[1][i][0] = cube[5][0][i];
	for (int i = 0; i < LENGTH; i++)cube[5][0][i] = temp[i];
}

void easyScamble() {
	printf("Scrambling...\n");
	for (int i = 0; i < 5; i++) {
		rotateRight();
	}
}

int main(void) {
	//초기화
	intCube();
	printf("initral cube:\n");
	printCube(STRING);
	//섞기
	for (int i = 1;i <=4;i++){
		easyScamble();
		printCube(LETTERS);
	}
	

	return 0;
}