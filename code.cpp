#include<iostream>
using namespace std;


int main() {


	int radius;
	int height;
	int volume;

	cout << "enter the height of the cone " << endl;
	cin >> height;

	cout << "enter radius of the cone" << endl;
	cin >> radius;

	volume = 3.14*radius*radius*height /3 ;

	cout << "your volume is" << volume << endl;
}
