#include <iostream>

using namespace std;

#define A_SIZE 2

int
main(void)
{
	float score[A_SIZE], sum;

	for (int i = 0; i < A_SIZE; ++i) {
		cin >> score[i];
		cout << "the student" << i << "s score is " << score[i] << endl; 
	}
	
	for (int i = 0; i < A_SIZE; ++i) {
		sum += score[i];
	}

	cout << "The sum is " << sum << endl;

	int average = (int) (sum / A_SIZE + 0.5);

	cout << "The average is " << average << endl;

	return 0;
}
