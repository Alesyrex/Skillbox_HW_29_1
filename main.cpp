#include <iostream>
#include <string>

class Animal
{
protected:
    std::string name;

public:
    virtual void voice(Animal* animal) = 0;
    std::string getName() { return name; }

    Animal(std::string inName)
            : name(inName)
    {
    }
};

class Dog : virtual public Animal
{
public:
    virtual void voice(Animal* animal)
    {
        if (Dog *dog = dynamic_cast<Dog*>(animal)) //Возвращается нулевой указатель если конвертация Animal в Dog не получается
            std::cout << "Woof";
        else std::cout << "Bark";
    }

    Dog(std::string inName = "Sharik")
            : Animal(inName)
    {
    }
};

class Cat : virtual public Animal
{
public:
    virtual void voice(Animal* animal)
    {
        if (Cat *cat = dynamic_cast<Cat*>(animal)) //Возвращается нулевой указатель если конвертация Animal в Cat не получается
            std::cout << "Purr";
        else std::cout << "Meow";
    }

    Cat(std::string inName = "Barsik")
            : Animal(inName)
    {
    }
};

void meeting(Animal* animal_1, Animal* animal_2)
{
    animal_1->voice(animal_2);
    std::cout << " ";
    animal_2->voice(animal_1);
    std::cout << std::endl;
}

int main() {

    Animal* a = new Cat();
    Animal* b = new Dog();
    meeting(a,b);

    return 0;
}
