#include <iostream>
#include <string>
#include <cctype>
#include <chrono>
#include <thread>
using namespace std;

class Car {
private:
	int Speed_ = 0; // be consistent in variable naming, all variables should begin with lowercase
	string brand_;
	string model_;
public:
	void setBrand(string brand) { // please put '{' on the new line, that style is more readable
		brand_ = brand;
	} // put new line before new function definition, that style is more readable
	void setModel(string model) {
		model_ = model; // don't indent too much, 4 spaces or 1 tab is enough
	}
	string getBrand() {
		return brand_;
	}
	string getModel() {
		return model_;
	}
	void openDoor() {
		cout << "you can seat, the door is open" << endl;
	}
	void ignition() {
		cout << "your car is ready to drive" << endl;
	}
	int pushSpeed(){
		Speed_ = Speed_ + 5;
		return Speed_;
	}
	int pushBreak() {
		if (Speed_ > 5) { // check should be >= 5, because if the speed is 5, it won't be subtracted and the car will never stop
			Speed_ = Speed_ - 5;
		}
		else {
			cout << "Currently your car has no speed" << endl;
			Speed_ = 0;
		}
		return Speed_;
	}
};

void displayMenu() {
	cout << "\n            Car Menu          " << endl;
	cout << "-------------------------------" << endl;
	cout << "A) Push the Gas on the Car" << endl;
	cout << "B) Push the Brake on the Car" << endl;
	cout << "C) Exit the program" << endl;
	cout << "\nEnter your choice: ";
}
int main() {
	string x;
	string y;
	char choice;


	cout << "welcome to our dream autosalon" << endl;
	cout << endl;
	cout << "----------------------------" << endl;
	cout << endl;
	cout << "please enter your dream car brand" << endl;
	cout << endl;
	cin >> x;
	cout << endl;
	cout << "ok, and what about model? please enter the car model also" << endl;
	cout << endl;
	cin >> y;


	Car myCar;
	myCar.setBrand(x);
	myCar.setModel(y);
	cout << endl;
	cout << "Ok your car is ready!!! You are going to drive your new" << endl;
	cout << endl;
	cout << myCar.getBrand() << " " << myCar.getModel() << " !!!" << endl;
	cout << endl;
	cout << "Let us continue our adventure :)" << endl;
	cout << endl;
	this_thread::sleep_for(chrono::milliseconds(5000));
	cout << "I want to mention that our company created innovation systems for each car." << endl;
	cout << endl;
	cout << "And cars can automatically be opened and ignited" << endl;
	this_thread::sleep_for(chrono::milliseconds(7000));
	cout << endl;
	cout << "Count to 5" << endl;
	cout << endl;

	this_thread::sleep_for(chrono::milliseconds(7000));
	myCar.openDoor();
	cout << endl;
	myCar.ignition();
	cout << endl;
	this_thread::sleep_for(chrono::milliseconds(5000));
	cout << "Hello already from Car's salon, please wait and I will show you car's menu" << endl;
	this_thread::sleep_for(chrono::milliseconds(5000));

	do
	{
		displayMenu();
		cin >> choice;
		// you can convert the letter to upper one time and work with it afterward:
		// char choiceUpper = toupper(choice);
		// while (choiceUpper < 'A' || choiceUpper > 'C')
		// {...}
		// switch (choiceUpper)
		// {
		//     case 'A':
		//     {...}
		//     case 'B':
		//     {...}
	        // }
		//
		// This logic is simpler and easier to maintain/change in the future
		while (toupper(choice) < 'A' || toupper(choice) > 'C')
		{
			cout << "Please make a choice of A or B or C:";
			cin >> choice;
		}
		switch (choice)
		{
		case 'a':
		case 'A': 
			cout << myCar.pushSpeed() << " " << "km/h" << endl;
			break;
		case 'b':
		case 'B':
			cout << myCar.pushBreak() << " " << "km/h" << endl;
			break;
		}
	} while (toupper(choice) != 'C');

	cout << endl << "Press ENTER to exit...";
	cin.clear();
	cin.sync();
	cin.get();

	return 0;	
}
