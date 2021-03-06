#include "libraries.h"

class nod
{
	int data;
	nod *next;
public:
	friend class Multime & operator*(Multime A, Multime B);
	friend class Multime & operator+(Multime A, Multime B);
	friend ostream & operator << (ostream &out, const Multime &c);
	friend class Multime & operator*(Multime A, Multime B);
	friend class Multime;
	friend class Multime & operator-(Multime A, Multime B);
	friend class Multime_perechi produs_cartezian(Multime A, Multime B);
};

class Multime
{
	nod *head;
	nod *last;
	nod *help;
public:
	friend class nod;
	friend class Multime_perechi produs_cartezian(Multime A, Multime B);
	Multime();
	void transformare();
	void addNod(int x);
	bool isPresent(Multime head, int data);
	friend ostream & operator << (ostream &out, const Multime &c);
	friend istream & operator >> (istream &in, Multime &c);
	friend Multime & operator+(Multime A, Multime B);
	friend Multime & operator*(Multime A, Multime B);
	friend Multime & operator-(Multime A, Multime B);
};

class Pereche_intregi
{
private:
	int a, b;
	Pereche_intregi *next;
public:

	friend class Multime_perechi;
	int get_a();
	int get_b();
	Pereche_intregi *get_next();
	void set_a(int a);
	void set_b(int b);
	void set_next(Pereche_intregi *next);
	friend ostream & operator << (ostream &out, const Pereche_intregi &c);
	friend istream & operator >> (istream &in, Pereche_intregi &c);
};

class Multime_perechi
{
public:
	
	Pereche_intregi *head = NULL;
	Pereche_intregi *last = NULL;
	Pereche_intregi *help = NULL;

	friend ostream & operator << (ostream &out, const Multime_perechi &c);
	friend istream & operator >> (istream &in, Multime_perechi &c);
	void addPereche(int a, int b);
	Multime_perechi();
};
void Pereche_intregi::set_next(Pereche_intregi *next)
{
	this->next = next;
}
Pereche_intregi* Pereche_intregi::get_next()
{
	return next;
}
void Pereche_intregi::set_a(int a)
{
	this->a = a;
}

void Pereche_intregi::set_b(int b)
{
	this->b = b;
}

int	Pereche_intregi::get_a()
{
	return a;
}

int	Pereche_intregi::get_b()
{
	return b;
}
bool Multime::isPresent(Multime M, int data)
{
	Multime test;
	test.help = M.head;
	while (test.help != NULL)
	{
		if (test.help->data == data)
			return 1;
		test.help = test.help->next;
	}
	return 0;
}

Multime & operator+(Multime A, Multime B)
{
	Multime rezultat, test;
	
	test.help = A.head;
	while (test.help != NULL)
	{
		rezultat.addNod(test.help->data);
		test.help = test.help->next;
	}
	test.help = B.head;

	while (test.help != NULL)
	{
		if (rezultat.isPresent(rezultat, test.help->data) == 0)
			rezultat.addNod(test.help->data);
		test.help = test.help->next;
	}
	cout << rezultat;
	return rezultat;
}

Multime & operator*(Multime A, Multime B)
{
	Multime rezultat, test;
	test.help = A.head;
	while (test.help != NULL)
	{
		if (rezultat.isPresent(B, test.help->data))
			rezultat.addNod(test.help->data);
		test.help = test.help->next;
	}
	return rezultat;
}

Multime & operator-(Multime A, Multime B)
{
	Multime rezultat, test;
	test.help = A.head;
	while (test.help != NULL)
	{
		if (rezultat.isPresent(B, test.help->data) == 0)
			rezultat.addNod(test.help->data);

		test.help = test.help->next;
	}
	return rezultat;
}

ostream & operator << (ostream &out, const Multime &c)
{
	if (c.head == NULL)
	{
		out << "LISTA GOALA\n";
		return out;
	}

	out << "LISTA : ";
	Multime test;
	test.help = c.head;
	while (test.help != NULL)
	{
		if (test.help == NULL)
			break;
		out << test.help->data << ' ';
		test.help = test.help->next;
	}
	out << endl;
	return out;
}

istream & operator >> (istream &in, Multime &c)
{
	int n, x;
	cout << "Cate noduri?\n";
	in >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "x = ";
		in >> x;
		cout << endl;
		c.addNod(x);
	}
	return in;
}

Multime::Multime()
{
	head = NULL;
	last = NULL;
}

void Multime::addNod(int x)
{
	nod *p = new nod;
	p->next = NULL;
	p->data = x;
	if (head == NULL)
	{
		head = p;
		last = p;
	}
	else
	{
		last->next = p;
		last = p;
	}
	last->next = NULL;
}

ostream & operator << (ostream &out, const Pereche_intregi &c)
{
	cout << "(" << c.a << "," << c.b << ")";
	out << endl;
	return out;
}

istream & operator >> (istream &in, Pereche_intregi &c)
{
	cout << "Perechea de intregi : ";
	in >> c.a;
	in >> c.b;
	return in;
}

ostream & operator << (ostream &out, const Multime_perechi &c)
{
	if (c.head == NULL)
	{
		out << "LISTA GOALA\n";
		return out;
	}

	out << "LISTA : ";
	Pereche_intregi *test;
	test = c.head;
	while (test != NULL)
	{
		if (test == NULL)
			break;
		out << "(" << test->get_a() << "," << test->get_b() << ") ---> ";
		test = test->get_next();
	}
	out << endl;
	return out;
}

istream & operator >> (istream &in, Multime_perechi &c)
{
	Pereche_intregi pereche;
	int n, x;
	cout << "Cate perechi ?\n";
	in >> n;
	for (int i = 0; i < n; i++)
	{
		in >> pereche;
		cout << endl;
		c.addPereche(pereche.get_a(), pereche.get_b());
	}
	return in;
}

Multime_perechi::Multime_perechi()
{
	this->head = NULL;
	this->last = NULL;
	this->help = NULL;
}

void Multime_perechi::addPereche(int x, int y)
{
	Pereche_intregi *p = new Pereche_intregi;
	p->next = NULL;
	p->set_a(x);
	p->b = y;
	if (head == NULL)
	{
		head = p;
		last = p;
	}
	else
	{
		last->next = p;
		last = p;
	}
	last->next = NULL;
}

void Multime::transformare()
{
	nod *i = NULL, *j = NULL, *temp = NULL;
	int OK = 0;

	for (i = head; i->next != NULL; i = i->next)
	{
		for (j = i->next; j->next != NULL; j = j->next)
		{
			if (i->data != j->data)
				OK = 1;

			nod *del = NULL;
			temp = i;
			while (temp->next != j)
				temp = temp->next;
			if (i->data == j->data)
			{
				temp->next = j->next;
				del = j;
				j = temp;
				delete del;
			}
		}
	}

	if (head != last)
	{
		nod *p = head;
		while (p->next != last)
			p = p->next;
		nod *pp = last;
		if (p->data == pp->data)
		{
			last = p;
			last->next = NULL;
			delete pp;
		}
	}
}

Multime_perechi produs_cartezian(Multime A, Multime B)
{
	Multime_perechi produsAxB;

	nod *p, *q;
	p = A.head;
	q = B.head;

	for (p = A.head; p != NULL; p = p->next)
		for (q = B.head; q != NULL; q = q->next)
			produsAxB.addPereche(p->data, q->data);

	return produsAxB;
}

int main()
{
	Multime lista1;
	cin >> lista1;
	lista1.transformare();
	cout << lista1;
	cout << endl;
	Multime lista2;
	cin >> lista2;
	lista2.transformare();
	cout << lista2;
	Multime lista3 = lista1 * lista2;

	Multime_perechi Lista;
	Pereche_intregi pereche;
	cin >> Lista;
	cout << Lista;

	Multime_perechi produs1;

	produs1 = produs_cartezian(lista1, lista2);
	cout << produs1 << endl;
	system("pause");
}
