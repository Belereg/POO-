#include "libraries.h"

class Multime
{
public:
	class nod
	{

	public:
		int data;
		nod *next;
	};
	nod *head;
	nod *last;
	nod *help;

public:
	int size;
	Multime();
	void transformare();
	void addNod(int x);
	//void delNod(int x);
	bool isPresent(Multime head, int data);
	friend ostream & operator << (ostream &out, const Multime &c);
	friend istream & operator >> (istream &in, Multime &c);
	friend Multime & operator+(Multime A, Multime B);
	friend Multime & operator*(Multime A, Multime B);
	friend Multime & operator-(Multime A, Multime B);
};

class Multime_perechi
{
public:
	class Pereche_intregi
	{
	public:
		friend class multime_perechi;
		int a, b;
		Pereche_intregi *next;
		friend ostream & operator << (ostream &out, const Pereche_intregi &c);
		friend istream & operator >> (istream &in, Pereche_intregi &c);
	};

	Pereche_intregi *head = NULL;
	Pereche_intregi *last = NULL;
	Pereche_intregi *help = NULL;

	friend ostream & operator << (ostream &out, const Multime_perechi &c);
	friend istream & operator >> (istream &in, Multime_perechi &c);
	void addPereche(int a, int b);
	Multime_perechi();
};

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

ostream & operator << (ostream &out, const Multime_perechi::Pereche_intregi &c)
{
	cout << "(" << c.a << "," << c.b << ")";
	out << endl;
	return out;
}

istream & operator >> (istream &in, Multime_perechi::Pereche_intregi &c)
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
	Multime_perechi::Pereche_intregi *test;
	test = c.head;
	while (test != NULL)
	{
		if (test == NULL)
			break;
		out << "(" << test->a << "," << test->b << ") ---> ";
		test = test->next;
	}
	out << endl;
	return out;
}

istream & operator >> (istream &in, Multime_perechi &c)
{
	Multime_perechi::Pereche_intregi pereche;
	int n, x;
	cout << "Cate perechi ?\n";
	in >> n;
	for (int i = 0; i < n; i++)
	{
		in >> pereche;
		cout << endl;
		c.addPereche(pereche.a, pereche.b);
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
	p->a = x;
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

	Multime::nod *p, *q;
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
	//cout << lista3;

	Multime_perechi Lista;
	Multime_perechi::Pereche_intregi pereche;
	cin >> Lista;
	cout << Lista;

	Multime_perechi produs1;

	produs1 = produs_cartezian(lista1, lista2);
	cout << produs1 << endl;
	system("pause");
}
