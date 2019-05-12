#include "libraries.h"

#if 1
class Masina
{
protected:

	static int foreign_nationality;
	static int foreign_nationality_monovolume;
	float lenght;

public:

	Masina();
	Masina(float l);
	Masina(const Masina& P);
	virtual void display() = 0;
	virtual ~Masina() {};
	static void nationality(){
		foreign_nationality++;
	}
};

class MINI : public Masina
{
private:

public:

	void display(){
		cout << "-> In the car park there is a vehicle of MINI type, with lenght of " << this->lenght << " meters\n";
	}
	MINI() :Masina() {};
	MINI(short number, float l) :Masina(l) {}
	MINI(const MINI& M) :Masina(M) {};
	~MINI() {};
	float get_lenght() { return this->lenght; };

	friend istream& operator>>(istream& in, MINI& M);
	MINI& operator=(const MINI& M);

};

class MICA : public Masina
{
private:

public:

	void display(){
		cout << "-> In the car park there is a vehicle of MICA type, with lenght of " << this->lenght << " meters\n";
	}
	MICA() :Masina() {};
	MICA(float l) :Masina(l) {}
	MICA(const MICA& M) :Masina(M) {};
	~MICA() {};
	float get_lenght() { return this->lenght; };

	friend istream& operator>>(istream& in, MICA& M);
	MICA& operator=(const MICA& M);


};

class COMPACTA : public Masina
{
private:

	short type; // 1 = hachback / 2 = combi / 3 = sedan

public:

	void display(){
		cout << "-> In the car park there is a ";
		if (this->type == 1)
			cout << "hachback vehicle of COMPACTA type, with lenght of " << this->lenght << " meters\n";
		if (this->type == 2)
			cout << "combi vehicle of COMPACTA type, with lenght of " << this->lenght << " meters\n";
		if (this->type == 3)
			cout << "sedan vehicle of COMPACTA type, with lenght of " << this->lenght << " meters\n";
	}
	COMPACTA() :Masina() { this->type = -1; }
	COMPACTA(float l) :Masina(l) { this->type = -1; }
	COMPACTA(const COMPACTA& C) :Masina(C) { this->type = C.type; }
	~COMPACTA() {}
	float get_lenght() { return this->lenght; };
	short get_type() { return this->type; };

	friend istream& operator>>(istream& in, COMPACTA& M);
	COMPACTA& operator=(const COMPACTA& M);

};

class MONOVOLUME : public Masina
{
private:

	short seats; // 5 - 7
	short condition; // 1 = new / 2 = used
	short year_discount;
	short summer_discount; // 1 - No / 2 - Yes

public:

	void display(){
		cout << "-> In the car park there is a vehicle of type MONOVOLUME with " << this->seats << " seats, ";
		if (this->condition == 1 && this->summer_discount == 10) cout << "that is in new condition and has no year discount but it has 10% summer discout\n";
		if (this->condition == 1 && this->summer_discount == 0) cout << "that is in new condition and has no year discount and also has no summer discout\n";
		if (this->condition == 2 && this->summer_discount == 0) cout << "that is in second-hand condition and has " << this->year_discount << "% year discount and has no summer discout\n";
		if (this->condition == 2 && this->summer_discount == 10) cout << "that is in second-hand condition and has " << this->year_discount << "% year discount and has 10% summer discout\n";
	}
	MONOVOLUME() :Masina() {
		this->seats = -1;
		this->condition = -1;
		this->year_discount = -1;
		this->summer_discount = -1;
	}
	MONOVOLUME(float l, short s, bool c, short y_d, short s_d) :Masina(l) {
		this->seats = s;
		this->condition = c;
		this->year_discount = y_d;
		this->summer_discount = s_d;
	}
	MONOVOLUME(const MONOVOLUME& M) :Masina(M) {
		this->seats = M.seats;
		this->condition = M.condition;
		this->year_discount = M.year_discount;
		this->summer_discount = M.seats;
	}
	~MONOVOLUME() {}
	short get_seats() { return this->seats; };
	short get_condition() { return this->condition; };
	short get_year_discount() { return this->year_discount; };
	short get_summer_discount() { return this->summer_discount; };
	float get_lenght() { return this->lenght; };

	friend istream& operator>>(istream& in, MONOVOLUME& M);
	MONOVOLUME& operator=(const MONOVOLUME& M);
};

Masina::Masina(){
	this->lenght = 0;
}

Masina::Masina(float l){
	this->lenght = l;
}

Masina::Masina(const Masina& P){
	this->lenght = P.lenght;
}

istream& operator>>(istream& in, MINI& M)
{
	cout << "\n- - - MINI - - -\n";

	MINI T;
	cout << "Does the car have foreign nationality? Y / N\n";
	char nat;
	cin >> nat;
	if (nat == 'y' || nat == 'Y')
		T.foreign_nationality++;
	
	if (!M.lenght){
		cout << "\nWhat is the lenght of the car : ";
		in >> M.lenght;
		if (M.lenght < 1 || M.lenght>4)
			throw "Lenght is not good for this type of car\n";
	}

	cout << " -Car(s) Added-\n\n";
	return in;
}

istream& operator>>(istream & in, MICA & M){
	cout << "\n- - - MICA - - -\n";

	MICA T;
	cout << "Does the car have foreign nationality? Y / N\n";
	char nat;
	cin >> nat;
	if (nat == 'y' || nat == 'Y')
		T.foreign_nationality++;

	if (!M.lenght){
		cout << "\nWhat is the lenght of the car : ";
		in >> M.lenght;
		if (M.lenght < 3.849999 || M.lenght>4.100000000001)
			throw "Lenght is not good for this type of car\n";
	}

	cout << " -Car(s) Added-\n\n";
	return in;
}

istream& operator>>(istream & in, COMPACTA & M){
	cout << "\n- - - COMPACTA - - -\n";

	COMPACTA T;
	cout << "Does the car have foreign nationality? Y / N\n";
	char nat;
	cin >> nat;
	if (nat == 'y' || nat == 'Y')
		T.foreign_nationality++;

	if (!M.lenght){
		cout << "\nWhat is the lenght of the car : ";
		in >> M.lenght;
		if (M.lenght < 4.1999 || M.lenght>4.5)
			throw "Lenght is not good for this type of car\n";
	}

	cout << "What is the car type?\n1)Hachback\n2)Combi\n3)Sedan\n";
	in >> M.type;
	if (M.type != 1 && M.type != 2 && M.type != 3)
		throw "Car type not allowed\n";

	cout << " -Car(s) Added-\n\n";
	return in;
}

istream& operator>>(istream & in, MONOVOLUME & M){
	cout << "- --MONOVOLUME - --\n";
	MONOVOLUME T;
	char nat, nat_monovolume;
	cout << "Does the car have foreign nationality? Y / N\n";
	cin >> nat;
	if (nat == 'y' || nat == 'Y'){
		cout << "Does this foreign car belong to the MONOVOLUME auto park? ";
		cin >> nat_monovolume;
		if (nat_monovolume == 'y' || nat_monovolume == 'Y')
			M.foreign_nationality_monovolume++;
		T.foreign_nationality++;
	}
	if (!M.lenght) {
		cout << "\nWhat is the lenght of the car : ";
		in >> M.lenght;
		if (M.lenght < 3 || M.lenght > 8)
			throw "Lenght is not good for this type of car\n";
	}
	if (M.seats == -1) {
		cout << "How many seats does the car have : ";
		in >> M.seats;
		if (M.seats < 5 || M.seats > 7)
			throw "The number of seats is not good for this type of car\n";
	}
	if (M.condition == -1) {
		cout << "What is the condition of the car : \n1)New\n2)Used\n";
		in >> M.condition;
		if (M.condition != 1 && M.condition != 2)
			throw "The car should be either new, either used\n";
	}
	if (M.year_discount == -1 && M.condition == 2) {
		cout << "How old is the car : ";
		in >> M.year_discount;
	}
	if (M.summer_discount == -1) {
		cout << "Is it summer and it is a promotion : \n1)No\n2)Yes\n";
		int choice;
		in >> choice;
		if (choice != 1 && choice != 2)
			throw "The car should be bought either in summer period, either not\n";
		else
		{
			if (choice)
				M.summer_discount = 10;
			else
				M.summer_discount = 0;
		}
	}

	cout << " -Car(s) Added-\n\n";
	return in;
}

MINI& MINI::operator=(const MINI & M) {
	this->lenght = M.lenght;
	return *this;
}

MICA& MICA::operator=(const MICA & M) {
	this->lenght = M.lenght;
	return *this;
}

COMPACTA& COMPACTA::operator=(const COMPACTA & M) {
	this->lenght = M.lenght;
	this->type = M.type;
	return *this;
}

MONOVOLUME& MONOVOLUME::operator=(const MONOVOLUME & M) {
	this->lenght = M.lenght;
	this->condition = M.condition;
	this->seats = M.seats;
	this->summer_discount = M.summer_discount;
	this->year_discount = M.year_discount;
	return *this;
}

template <class T>
class Sale :public Masina
{
protected:

	static short total_nr_cars;
	static short sold_cars;
	vector <T*> cars_stock;
	vector <T*> sold_cars_stock;

public:

	friend class mini;
	friend class mica;
	friend class masina;
	void display()
	{
		MINI* A;
		MICA* B;
		COMPACTA* C;
		MONOVOLUME* D;

		for (int i = 0; i < cars_stock.size(); i++)
			try {
			A = dynamic_cast<MINI*>(cars_stock[i]);
			B = dynamic_cast<MICA*>(cars_stock[i]);
			C = dynamic_cast<COMPACTA*>(cars_stock[i]);
			D = dynamic_cast<MONOVOLUME*>(cars_stock[i]);

			if (A)
				A->display();

			if (B)
				B->display();

			if (C)
				C->display();

			if (D)
				D->display();

		}
		catch (bad_cast & bc)
		{
			cerr << bc.what() << '\n';
		}
		cout << endl;
		cout << "Number of sold cars = " << this->get_sold_cars() << "\nNumber of total cars = " << this->get_total_nr_cars() << "\nNumber of foreign cars = " << this->foreign_nationality << endl;
	}
	Sale() {
		this->total_nr_cars = 0;
		this->sold_cars = 0;
	}
	Sale(T* p) {
		cars_stock.push_back(&p);
		this->total_nr_cars++;
	}
	Sale(Sale<T>& p) {
		this->cars_stock = p.cars_stock;
		this->sold_cars = p.sold_cars;
		this->sold_cars_stock = p.sold_cars_stock;
		this->total_nr_cars = p.total_nr_cars;
	}
	~Sale() {}
	Sale<T>& operator-=(T& S) {
		this->cars_stock.pop_back();
		this->total_nr_cars--;
		this->sold_cars_stock.push_back(&S);
		this->sold_cars++;
		return *this;
	}
	void add(T& p) {
		this->cars_stock.push_back(&p);
		this->total_nr_cars++;
	}
	short get_total_nr_cars() {
		return this->total_nr_cars;
	}
	short get_sold_cars() {
		return this->sold_cars;
	}
};

template <>
class Sale<unsigned> : public Masina
{
protected:

	short total_nr_cars;
	short sold_cars;
	vector <MONOVOLUME*> cars_stock;
	vector <MONOVOLUME*> sold_cars_stock;

public:

	void display() {
		MINI* A;
		MICA* B;
		COMPACTA* C;
		MONOVOLUME* D;

		for (int i = 0; i < cars_stock.size(); i++)
			try {
			A = dynamic_cast<MINI*>(cars_stock[i]);
			B = dynamic_cast<MICA*>(cars_stock[i]);
			C = dynamic_cast<COMPACTA*>(cars_stock[i]);
			D = dynamic_cast<MONOVOLUME*>(cars_stock[i]);

			if (A)
				A->display();

			if (B)
				B->display();

			if (C)
				C->display();

			if (D)
				D->display();

		}
		catch (bad_cast & bc) {
			cerr << bc.what() << '\n';
		}
		cout << endl;
		cout << "Number of sold cars = " << this->get_sold_cars() << "\nNumber of total cars = " << this->get_total_nr_cars() << "\nNumber of foreign -MONOVOLUME- cars = " << this->foreign_nationality_monovolume;
	}
	Sale() {
		//cout << "Selling()\n";
		this->total_nr_cars = 0;
		this->sold_cars = 0;
	}
	Sale(MONOVOLUME* p) {
		//cout << "Selling(T* p)\n";
		cars_stock.push_back(&*p);
		this->total_nr_cars++;
	}
	Sale(Sale<unsigned>& p) {
		this->cars_stock = p.cars_stock;
		this->sold_cars = p.sold_cars;
		this->sold_cars_stock = p.sold_cars_stock;
		this->total_nr_cars = p.total_nr_cars;
	}
	Sale<unsigned>& operator-=(MONOVOLUME& S) {
		this->cars_stock.pop_back();
		this->total_nr_cars--;
		this->sold_cars_stock.push_back(&S);
		this->sold_cars++;
		return *this;
	}
	void add(MONOVOLUME& p) {
		this->cars_stock.push_back(&p);
		this->total_nr_cars++;
	}
	short get_total_nr_cars() {
		return this->total_nr_cars;
	}
	short get_sold_cars() {
		return this->sold_cars;
	}
};

template <class T>short Sale<T>::total_nr_cars = 0;
template <class T>short Sale<T>::sold_cars = 0;
int Masina::foreign_nationality = 0;
int Masina::foreign_nationality_monovolume = 0;

int main()
{
	MINI A;
	cin >> A;
	MICA B;
	cin >> B;
	MONOVOLUME D;
	cin >> D;
	COMPACTA C;
	cin >> C;

	Sale<Masina> P;
	P.add(A);
	P.add(B);
	P.add(D);
	P.add(C);
	P -= C;
	P.display();

	Sale<unsigned> M;
	MONOVOLUME AA, CC, DD, EE, FF, GG;
	MINI BB;
	cin >> AA >> CC >> DD >> EE >> FF >> GG;

	M.add(AA);
	M.add(CC);
	M.add(DD);
	M.add(EE);
	M.add(FF);
	M.add(GG);
	M -= GG;
	M.display();

	system("pause");
}
#endif
