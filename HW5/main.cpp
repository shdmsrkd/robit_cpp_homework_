#include <iostream>
#include <string>

using namespace std;

class Animal
{
protected:
    string name;
    int age;
public:
    Animal(string n, int a) : name(n), age(a) {}

    void showInfo()
    {
        cout << "Name : " << name << ", Age : " << age << endl;
    }

    virtual string makeSound() = 0;

    virtual ~Animal() {};
};


class Dog : public Animal
{
public:

    Dog(string n, int a) : Animal(n, a) {}

    string makeSound() override
    {
        return "bark";
    }


};

class Cat : public Animal
{
public:
    Cat(string n, int a) : Animal(n, a) {}


    string makeSound() override
    {
        return "Meow";
    }

};

class Bird : public Animal
{
public:

    Bird(string n, int a) : Animal(n, a) {}


    string makeSound() override
    {
        return "Chirp";
    }

};


int main()
{

    Animal * animal;

    Dog dog("Bella", 12);

    Cat cat("Chloe", 3);

    Bird bird("Leo", 6);

    animal = &dog;
    animal->showInfo();
    cout << dog.makeSound() << endl;
    cout << endl;


    animal = &cat;
    animal->showInfo();
    cout << cat.makeSound() << endl;
    cout << endl;


    animal = &bird;
    animal->showInfo();
    cout << bird.makeSound() << endl;
    cout << endl;

    return 0;
}
