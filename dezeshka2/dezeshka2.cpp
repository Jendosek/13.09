#include <iostream>
using namespace std;



enum EntityType {
    BIRD,
    ANIMAL,
    HUMAN
};

union Characteristic {
    double flightSpeed;
    bool isEvenToed;      
    int iqLevel;           
};

struct LivingEntity {
private:
    EntityType type;
    string color;
    double movementSpeed;
    Characteristic characteristic;

public:
    LivingEntity() {
        this->color = "";
        this->movementSpeed = 0;
    }

    LivingEntity(EntityType type) : LivingEntity()
    {
        setType(type);
    }

    LivingEntity(EntityType type, string color) : LivingEntity(type)
    {
        setColor(color);
    }

    LivingEntity(EntityType type, string color, double movementSpeed) : LivingEntity(type, color)
    {
        setMovementSpeed(movementSpeed);
    }
    
    LivingEntity(EntityType type, string color, double movementSpeed, double flightSpeed) : LivingEntity(type, color, movementSpeed)
    {
        setCharacteristic(flightSpeed);
    }

    void setType(EntityType type) {
        this->type = type;
    }

    void setColor(string color) {
        this->color = color;
    }

    void setMovementSpeed(double speed) {
        this->movementSpeed = speed;
    }

    void setCharacteristic(double flightSpeed) {
        this->characteristic.flightSpeed = flightSpeed;
    }

    void setCharacteristic(bool isEvenToed) {
        this->characteristic.isEvenToed = isEvenToed;
    }

    void setCharacteristic(int iqLevel) {
        this->characteristic.iqLevel = iqLevel;
    }

    EntityType getType() {
        return type;
    }

    string getColor() {
        return (this->color.empty()) ? "No info" : this->color;
    }

    double getMovementSpeed() {
        return this->movementSpeed;
    }

    double getFlightSpeed() {
        return (this->type == BIRD) ? this->characteristic.flightSpeed : 0;
    }

    bool getEvenToed() {
        return (this->type == ANIMAL) ? this->characteristic.isEvenToed : false;
    }

    int getIQ() {
        return (this->type == HUMAN) ? this->characteristic.iqLevel : 0;
    }

    void print() {
        cout << "Type: " << (type == BIRD ? "Bird" : type == ANIMAL ? "Cattle" : "Human") << endl;
        cout << "Color: " << getColor() << endl;
        cout << "Move Speed: " << getMovementSpeed() << " m/s" << endl;

        if (type == BIRD) {
            cout << "Flight Speed: " << getFlightSpeed() << " m/s" << endl;
        }
        else if (type == ANIMAL) {
            cout << "Even-toed: " << (getEvenToed() ? "Yes" : "No") << endl;
        }
        else if (type == HUMAN) {
            cout << "IQ Level: " << getIQ() << endl;
        }
    }
};

void printAllEntities(LivingEntity* arr, int size) {
    for (int i = 0; i < size; i++) {
        arr[i].print();
        cout << endl;
    }
}

void editEntity(LivingEntity* arr, int size, int index, string newColor, double newSpeed, Characteristic newCharacteristic, EntityType newType) {
    if (index >= 0 && index < size) {
        arr[index].setColor(newColor);
        arr[index].setMovementSpeed(newSpeed);
        arr[index].setType(newType);

        if (newType == BIRD) {
            arr[index].setCharacteristic(newCharacteristic.flightSpeed);
        }
        else if (newType == ANIMAL) {
            arr[index].setCharacteristic(newCharacteristic.isEvenToed);
        }
        else if (newType == HUMAN) {
            arr[index].setCharacteristic(newCharacteristic.iqLevel);
        }
        cout << "Entity at index " << index << " updated." << endl;
    }
}


int main() {
    LivingEntity* arr = new LivingEntity[10]{
        LivingEntity(BIRD, "blue", 10, 20),
        LivingEntity(ANIMAL, "brown", 2, true),
        LivingEntity(HUMAN, "white", 1.5, 100 /*????*/),
    };

    cout << "All entities:" << endl;
    printAllEntities(arr, 3);
    cout << endl;

    cout << "Editing entity at index 3:" << endl;
    Characteristic newChar;
    newChar.iqLevel = 130;
    editEntity(arr, 3, 2, "black", 2.0, newChar, HUMAN);
    cout << endl;

    cout << "Update:" << endl;
    cout << "All entities:" << endl;
    printAllEntities(arr, 3);
    cout << endl;
 
    return 0;
}