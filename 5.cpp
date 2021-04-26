#include <iostream>
#include <string>
using namespace std;

class Coffee
{
public:

	virtual ~Coffee() {}
	virtual int getPrice() = 0;
	virtual int Operation() = 0;
	//virtual void setPrice(int price_) = 0;
};

class Espresso : public Coffee
{
	int price = 12;
public:

	int Operation() override
	{
		cout << " Эспрессо ";
		return this->getPrice();
	}

	int getPrice() override
	{
		return  this->price;
	}
};

class Americano : public Coffee
{
	int price = 10;
public:

	int Operation() override
	{
		cout << " Американо ";
		return this->getPrice();
	}

	int getPrice() override
	{
		return  this->price;
	}
};

class Decorator : public Coffee
{
protected:

	Coffee* coffee;

public:

	Decorator(Coffee* coffee_) : coffee(coffee_) {}

	int Operation() override
	{
		return this->coffee->Operation();
	}
};

class Milk : public Decorator
{
	int price = 3;

public:

	Milk(Coffee* coffee) : Decorator(coffee) {}

	int Operation() override
	{
		cout << " Молоко ";
		return this->getPrice() + Decorator::Operation();
	}

	int getPrice() override
	{
		return  this->price;
	}
};

class Sugar : public Decorator
{
	int price = 2;

public:

	Sugar(Coffee* coffee) : Decorator(coffee) {}

	int Operation() override
	{
		cout << " Сахар ";
		return this->getPrice() + Decorator::Operation();
	}

	int getPrice() override
	{
		return  this->price;
	}
};

class Chokolate : public Decorator
{
	int price = 4;

public:

	Chokolate(Coffee* coffee) : Decorator(coffee) {}

	int Operation() override
	{
		cout << " Шоколад ";
		return this->getPrice() + Decorator::Operation();
	}

	int getPrice() override
	{
		return  this->price;
	}
};

Coffee* add_milk(Coffee* coffee)
{
	int choise;
	cout << "Добавлять молоко в кофе?" << endl;
	cout << "Да - 1" << endl;
	cout << "Нет - 2" << endl;
	cin >> choise; cout << endl;

	if (choise == 1)
	{
		coffee = new Milk(coffee);
		return coffee;
	}
	else
	{
		return coffee;
	}
}

Coffee* add_sugar(Coffee* coffee)
{
	int choise;
	cout << "Добавлять сахар в кофе?" << endl;
	cout << "Да - 1" << endl;
	cout << "Нет - 2" << endl;
	cin >> choise; cout << endl;

	if (choise == 1)
	{
		coffee = new Sugar(coffee);
		return coffee;
	}
	else
	{
		return coffee;
	}
}

Coffee* add_chokolate(Coffee* coffee)
{
	int choise;
	cout << "Добавлять шоколад в кофе?" << endl;
	cout << "Да - 1" << endl;
	cout << "Нет - 2" << endl;
	cin >> choise; cout << endl;

	if (choise == 1)
	{
		coffee = new Chokolate(coffee);
		return coffee;
	}
	else
	{
		return coffee;
	}
}

void make_a_coffee()
{
	int choise = 0;
	cout << "Какой кофе вы хотите?" << endl;
	cout << "Эспрессо - 1" << endl;
	cout << "Американо - 2" << endl;
	cin >> choise; cout << endl;


	if (choise == 1)
	{
		Coffee* coffee = new Espresso();
		coffee = add_milk(coffee);
		coffee = add_sugar(coffee);
		coffee = add_chokolate(coffee);
		cout << endl << coffee->Operation();
	}
	else if (choise == 2)
	{
		Coffee* coffee = new Americano();
		coffee = add_milk(coffee);
		coffee = add_sugar(coffee);
		coffee = add_chokolate(coffee);
		cout << endl << coffee->Operation();
	}
	else
	{
		cout << "Неправильный выбор!" << endl;
	}

}


int main()
{
	setlocale(LC_ALL, "rus");

	make_a_coffee();

	return 0;
}