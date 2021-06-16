//
// Created by mtb on 6/5/21.
// Virtual constructor / Virtual functions

#include <iostream>

using namespace std;

class Transport{

    virtual string getCompany() = 0;

public:
    virtual ~Transport(){};

};

class Vehicle: Transport{
    private:
        double weight;

    protected:
        enum Type {
            car, train
        };
    public:
        explicit Vehicle(double w): weight{w} {}
        double getWeight() const{
            return weight;
        }
        void setWeight(double w){
            weight = w;
        }
        void printWeight() const{
            cout << weight <<endl;
        }
        virtual void print() const { // Overriding
//        void print() const {
            cout << "weight=" << weight;
        }
        virtual Type type() =0; // Abstract
        virtual Vehicle &build() = 0; // Return type relaxation with virtual

        string getCompany() {
            return string{"X"};
        }
};

class Car: public Vehicle{

    enum Size {
        small, medium, big
    } ;

    public:
        int number_of_doors;
        Size size;
        Car(int d, int s, double w): Vehicle(w), number_of_doors{d}{
            switch(s) {
                case 0:
                    size = small;
                case 1:
                    size = medium;
                case 2:
                    size = big;
                default:
                    size = small;
            }
        }
        void print() const{
            cout << "Car(doors=" << number_of_doors << ", " ;
            /* SuperSet Vehicle print() is virtual */
            Vehicle::print();
            cout << ")"  << endl;
        }
        Type type() override final{ // No more overriding by the derived classes
            return Type::car;
        }

        Car &build() override{
            return *this;
        }

        ~Car()= default;
};

class Train final: public Vehicle{
    enum Speed {
        slow, medium, fast
    };
    Speed sp;
public:
    Train( int s, double w): Vehicle(w){
        switch(s) {
            case 0:
                sp = slow;
            case 1:
                sp = medium;
            case 2:
                sp = fast;
            default:
                sp = medium;
        }
    }
    void print() const override;
    Type type() override{ // Virtual class. All the functions are virtual.
        return Type::train;
    }
    Train &build() override{
        return *this;
    }
    ~Train()= default;
};

void Train::print() const  {
    cout << "Train(speed=" << static_cast<int>(sp) << ", " ;
    /* SuperSet Vehicle print() is virtual */
    Vehicle::print();
    cout << ")" ;
}

class Ferrari: public Car {
    public:
//    Type type() override {
//        return Type::train;
//    } // Error attempting overriding
};

void printVehicle(const Vehicle &v){
    /*  Polymorphism. Try without virtual in bASE */
    v.print();
}

void t1() {
    Car c1 {2, 0, 100.0};
//    cout << c1.weight;  // Error cannot reach the private
    c1.printWeight();
    c1.print();
}

void t2() {
    Car c1 {2, 0, 100.0};
    Train t{1, 50.0};

    printVehicle(c1);
    printVehicle(t);
}

void t3() {
    Car c1 {2, 0, 100.0};
    Car c2 = c1.build();
    c2.setWeight(150.0);
    c1.setWeight(1500);
    printVehicle(c2);
    printVehicle(c1);
}

int main(int argc, char **argv){
    t3();

    return 0;
}
