#include <iostream>
#include <time.h>
#include <Windows.h>
using namespace std;
//HEHEHE XD Funny Comment// -Levy was here!!!!!// 
void pause(int dur);
double Calculate(int answer, int answer2);

double final = 0;
int question = 0;

int main() {
	int rooms = 1;
	double answer = 1;
	double answer2 = 1;
	while (question != 6) {
		switch (rooms) {
		case 1://question
			cout << "Please enter a number:" << endl;
			cout << "1 = Addition" << endl;
			cout << "2 = Subtraction" << endl;
			cout << "3 = Multiply" << endl;
			cout << "4 = Division" << endl;
			cout << "5 = Modulo" << endl;
			cout << "6 = Quit" << endl;
			cin >> question;
			rooms = 2;
			break;
		case 2:
			cout << "Input a number:" << endl;
			cin >> answer;
			cout << "Input a number:" << endl;
			cin >> answer2;
			cout << endl << endl;
			cout << "Calculating.." << endl;
			pause(1);
			cout << "Calculating.." << endl;
			pause(1);
			cout << "Calculating.." << endl;
			pause(1);
			cout << endl;
			Calculate(answer, answer2);
			cout << "The answer is: " << final << endl;
			rooms = 1;
			break;


		}// end switch
	}// end while
}//end main

double Calculate(int answer, int answer2) {
	if (question == 1){
		final = answer + answer2;
}
	if (question == 2){
		final = answer - answer2;
}
	if (question == 3){
		final = answer * answer2;
}
	if (question == 4){
		final = answer / answer2;
}
	if (question == 5) {
		final = answer % answer2;
	}
	return final;


}


void pause(int dur)
{
	int temp = time(NULL) + dur;

	while (temp > time(NULL));
}
