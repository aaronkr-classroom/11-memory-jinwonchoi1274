#include <stdio.h>


#define SIZE 10
int main(void) {
	char data[SIZE] = { 1,2,3,4,5,6,7,8,9,10 };

	int result = 0, i; //합산에 사용할 result 변수

	char *p = data;

	for (i = 0; i < SIZE; i++) { //data[9]까지
		printf("지금 result: %d\n", result);
		//포인터 p가 가리키는 대상의 값을 합산함
		result = result + *p;
		//data 배열의 다음항목으로 이동함
		p++;
	}

	printf("마지막 result 합:%d\n",result);

	return 0;
}