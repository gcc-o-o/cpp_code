//rtti2.cpp -- use runtime type identification dynamic_cast operator
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <typeinfo>
using std::cout;
using std::endl;

class Grand{
private:
	int hold;
public:
	Grand(int h) : hold(h) {}
	virtual void Speak() const {cout << "I am a Grand class!\n";}
	virtual int Value() const {return hold;}
};

class Superb : public Grand {
public:
	Superb(int h) : Grand(h) {}
	virtual void Speak() const {cout << "I am a Superb class!\n";}
	virtual void Say() const {cout << "I hold Superb value of " << Value() << '\n';}
};

class Magnificent : public Superb {
private:
	char key;
public:
	Magnificent(int h, char k) : Superb(h), key(k) {}
	virtual void Speak() const {cout << "I am a Magnificent class!\n";}
	virtual void Say() const {cout << "I hold Magnificent value of " << key << " and " << Grand::Value() << '\n';}
};

Grand* GetOne();	//generate one of three class objects randomly

int main(){
	std::srand(std::time(0));
	Grand* pg;
	Superb* ps;
	for (int i = 0; i < 5; i++){
		pg = GetOne();
		cout << "Now processing type " << typeid(*pg).name() << endl;
		pg->Speak();
		if (ps = dynamic_cast<Superb*>(pg))
			ps->Say();
		if(typeid(*pg) == typeid(Magnificent))
			cout << "Yes, you are really magnificent.\n";
	}
	return 0;
}

Grand* GetOne(){
	Grand* pg = nullptr;
	switch(std::rand() % 3){
		case 0: pg = new Grand(std::rand() % 100); break;
		case 1: pg = new Superb(std::rand() % 100); break;
		case 2: pg = new Magnificent(std::rand() % 100, 'A' + std::rand() % 26); break;
	}
	return pg;
}
