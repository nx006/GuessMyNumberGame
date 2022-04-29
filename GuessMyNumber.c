/*
Consider the game of “Guess my number between 10 and 20.” Write and explain a program
which plays the game using function ‘rand()’ in <stdlib.h> as follows exactly. You should
check whether the input number is within range 10 ~ 20 or not.
*/


#include <stdio.h>
#include <stdlib.h>

//유저의 값을 입력받는 함수
//10부터 20의 값만 입력받는다
//10부터 20의 값이 입력되지 않았으면, 에러 메시지를 출력하고 다시 입력받는다.
int getUserNum()
{
	int userNum = 0; //사용자로부터 입력받는 값을 저장

	//10<=userNum && userNum <= 20 인 경우만 입력받고, 그렇지 않은 경우 다시 입력받는다.
	while (userNum < 10 || userNum > 20) {
		scanf_s("%d", &userNum);
		//!(10<=userNum && userNum <= 20) 인 경우 에러 메시지를 출력한다.
		if (userNum < 10 || userNum > 20) {
			printf("The answer should be between 10 to 20\n");
			printf("Try again: ");
		}
	}

	return userNum;
}

int main(void)
{
	// 10부터 20까지의 숫자를 랜덤하게 받음
	// rand()함수가 반환한 값을 11로 나눈 나머지를 받으면, 0부터 10까지의 랜덤한 수가 나온다. 
	// 여기에 10을 더해 10부터 20까지 랜덤한 수를 입력받는다.
	int randomAnswer = rand() % 11 + 10;

	int userNum = 0; //유저가 입력한 답을 저장하는 변수
	while (userNum != randomAnswer) { // userNum != randomAnswer일 때만 반복문을 돌리고, 반복문을 탈출한다.
		printf("Guess? ");
		userNum = getUserNum();
		if (userNum == randomAnswer) {
			// userNum == randomAnswer 이면 축하 메시지를 출력한다. 이후 반복문 조건에 의해 탈출된다.
			printf("Very good! My random number is %d.\n", randomAnswer);
		}
		else if (userNum > randomAnswer) {
			// 입력받은 수가 답보다 클 경우
			printf("%d is higher than my number.\n", userNum);
		}
		else if (userNum < randomAnswer) {
			// 입력받은 수가 답보다 작을 경우
			printf("%d is lower than my number.\n", userNum);
		}
		else {
			// 만약 예외 상황 발생 시 오류 메시지를 출력한다.
			printf("ERROR: %d IS NOT AN IDENTIFIED NUMBER\n", userNum);
		}
	}

	return 0;
}