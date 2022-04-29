/*
Consider the game of ��Guess my number between 10 and 20.�� Write and explain a program
which plays the game using function ��rand()�� in <stdlib.h> as follows exactly. You should
check whether the input number is within range 10 ~ 20 or not.
*/


#include <stdio.h>
#include <stdlib.h>

//������ ���� �Է¹޴� �Լ�
//10���� 20�� ���� �Է¹޴´�
//10���� 20�� ���� �Էµ��� �ʾ�����, ���� �޽����� ����ϰ� �ٽ� �Է¹޴´�.
int getUserNum()
{
	int userNum = 0; //����ڷκ��� �Է¹޴� ���� ����

	//10<=userNum && userNum <= 20 �� ��츸 �Է¹ް�, �׷��� ���� ��� �ٽ� �Է¹޴´�.
	while (userNum < 10 || userNum > 20) {
		scanf_s("%d", &userNum);
		//!(10<=userNum && userNum <= 20) �� ��� ���� �޽����� ����Ѵ�.
		if (userNum < 10 || userNum > 20) {
			printf("The answer should be between 10 to 20\n");
			printf("Try again: ");
		}
	}

	return userNum;
}

int main(void)
{
	// 10���� 20������ ���ڸ� �����ϰ� ����
	// rand()�Լ��� ��ȯ�� ���� 11�� ���� �������� ������, 0���� 10������ ������ ���� ���´�. 
	// ���⿡ 10�� ���� 10���� 20���� ������ ���� �Է¹޴´�.
	int randomAnswer = rand() % 11 + 10;

	int userNum = 0; //������ �Է��� ���� �����ϴ� ����
	while (userNum != randomAnswer) { // userNum != randomAnswer�� ���� �ݺ����� ������, �ݺ����� Ż���Ѵ�.
		printf("Guess? ");
		userNum = getUserNum();
		if (userNum == randomAnswer) {
			// userNum == randomAnswer �̸� ���� �޽����� ����Ѵ�. ���� �ݺ��� ���ǿ� ���� Ż��ȴ�.
			printf("Very good! My random number is %d.\n", randomAnswer);
		}
		else if (userNum > randomAnswer) {
			// �Է¹��� ���� �亸�� Ŭ ���
			printf("%d is higher than my number.\n", userNum);
		}
		else if (userNum < randomAnswer) {
			// �Է¹��� ���� �亸�� ���� ���
			printf("%d is lower than my number.\n", userNum);
		}
		else {
			// ���� ���� ��Ȳ �߻� �� ���� �޽����� ����Ѵ�.
			printf("ERROR: %d IS NOT AN IDENTIFIED NUMBER\n", userNum);
		}
	}

	return 0;
}