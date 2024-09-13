#include <iostream>
using namespace std;


struct MyCar {
private:
	int* number;
	string color;
	string model;
public:
	MyCar()
	{
		this->color = "";
		this->model = "";
		this->number = nullptr;
	}

	MyCar(int number) : MyCar()
	{
		setNumber(number);
	}
	MyCar(int number, string color) : MyCar(number)
	{
		setColor(color);
	}
	MyCar(int number, string color, string model) : MyCar(number, color)
	{
		setModel(model);
	}


	void setNumber(int number)
	{
		this->number = (this->number == nullptr) ? new int(number) : &number;
	}
	void setColor(string color)
	{
		this->color = color;
	}
	void setModel(string model)
	{
		this->model = model;
	}

	int getNumber()
	{
		return (this->number == nullptr) ? 0 : *this->number;
	}
	string getColor()
	{
		return (this->color.empty()) ? "No info" : this->color;
	}
	string getModel()
	{
		return (this->model.empty()) ? "No info" : this->model;
	}

	void print()
	{
		cout << "Number: " << getNumber() << endl;
		cout << "Color: " << getColor() << endl;
		cout << "Model: " << getModel() << endl;
	}
};

void printAllCars(MyCar* arr, int size) {
	for (int i = 0; i < size; i++) {
		arr[i].print();
		cout << endl;
	}
}

void findCarByNumber(MyCar* arr, int size, int searchNumber) {
	for (int i = 0; i < size; i++) {
		if (arr[i].getNumber() == searchNumber) {
			arr[i].print();
			return; //щоб вийти з циклу
		}
	}
	cout << "Car with number " << searchNumber << " not found" << endl;
}


void editCar(MyCar* arr, int size, int searchNumber, string newColor, string newModel) {
	for (int i = 0; i < size; i++) {
		if (arr[i].getNumber() == searchNumber) {
			arr[i].setColor(newColor);
			arr[i].setModel(newModel);
			cout << "Car with number " << searchNumber << " updated" << endl;
			return;
		}
	}
	cout << "Car with number " << searchNumber << " not found" << endl;
}

int main() {

	MyCar* arr = new MyCar[10]
	{
		MyCar(1234, "black", "bmw"),
		MyCar(2436, "red", "audi"),
		MyCar(3742, "green", "mercedes"),
		MyCar(4645, "grey", "reno"),
		MyCar(9765, "white", "volkswagen"),
		MyCar(2656, "orange", "kia"),
		MyCar(6627, "white", "mitsubishi"),
		MyCar(6548, "purple", "bmw"),
		MyCar(6349, "blue", "mercedes"),
		MyCar(6410, "black", "bmw"),
	};

	cout << "All cars:" << endl;
	printAllCars(arr, 10);
	cout << endl;

	cout << "Search cars by number:" << endl;
	findCarByNumber(arr, 10, 3742);
	cout << endl;

	cout << "Editing cars:" << endl;
	editCar(arr, 10, 3742, "red", "audi");
	cout << endl;

	cout << "Update:" << endl;
	findCarByNumber(arr, 10, 3742);
	cout << endl;

	return 0;
}