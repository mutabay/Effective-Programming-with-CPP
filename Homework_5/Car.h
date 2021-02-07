//
// Created by tyyp- on 12/18/2020.
//

#ifndef HOMEWORK_5_CAR_H
#define HOMEWORK_5_CAR_H

#include <iostream>

using namespace std;

class Car {
private:
    char * brand;
    char * model;
    int year;
public:
    Car():brand("Mitsubishi"),model( "Eclipse"),year(1998){};

    Car( char * brand, char * model, int year)
    :brand(brand), model(model), year(year){};

    ~Car()
    {
        brand = NULL;
        model = NULL;
        delete brand;
        delete model;
        cout << "Destroying Car of model:" << model << "!" << endl;
    }

    void SetCarFields(char * brand, char * model, int year)
    {
        this->brand = brand;
        this->model = model;
        this->year = year;
    }

    friend ostream& operator<< (ostream& out, const Car& car)
    {
        out << " Brand = " << car.brand << "| Model = " << car.model << "| Year = " << car.year << endl;
        return out;
    }
};

#endif //HOMEWORK_5_CAR_H
