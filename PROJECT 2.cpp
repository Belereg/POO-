#include "libraries.h"

#if 1
class Abstract
{
public:
	virtual void add_node(char data)=0;
};
class Nod
{
	char data;
	Nod *next;

public:
	friend class Coada;
	friend class DEQUE;
	friend ostream & operator << (ostream &out, const Nod &n);
	friend istream & operator >> (istream &in, Nod &n);

	char get_data()
	{
		return data;
	}

	Nod* get_next()
	{
		return this->next;
	}

	Nod();
	Nod(char x, Nod*next);
	Nod(const Nod &n);
	~Nod();
};

class Coada: public Abstract
{
	int dim_max;
	Nod *head;
	Nod *last;
	Nod *help;

public:

	friend class Nod;
	friend class DEQUE;
	friend ostream & operator << (ostream &out, const Coada &c);
	friend istream & operator >> (istream &in, Coada &c);
	Coada & operator=(const Coada &c1);

	Coada();
	Coada(Nod * head, Nod * last, int dim_max);
	Coada(const Coada &c);
	~Coada();

	
	void pop_node();
	void add_node(char data);
	int get_dim()
	{
		return this->dim_max;
	}
};

class DEQUE : public Coada, public Abstract
{

public:
	friend class Nod;
	friend class Coada;
	friend istream & operator >> (istream &in, DEQUE &c);

	DEQUE();
	DEQUE(Nod *head, Nod *last, int dim_max);
	DEQUE(const DEQUE &dc);
	~DEQUE();


	void add_node(char data);
	void pop_node();
};

class DEQUE_MARCAJ : Coada
{
	//cu operatiile de adaugare și stergere modificate corespunzator. 
public:
	friend class Nod;
	friend class Coada;
	friend class DEQUE;
};

Nod::Nod()
{
	this->data = '/';
	this->next = NULL;
}

Nod::Nod(char x, Nod * next)
{
	this->data = x;
	this->next = next;
}

Nod::Nod(const Nod & n)
{
	this->data = n.data;
	this->next = n.next;
}

Nod::~Nod()
{
	//delete this->next;
}

istream & operator>>(istream &in, Nod &n)
{
	cout << "Nodul cu data: ";
	int x;
	cin >> x;
	n.data = x;
	return in;
}

ostream & operator<<(ostream &out, const Nod &n)
{
	cout << "Nodul detine data: " << n.data << endl;
	return out;
}

Coada::Coada()
{
	this->dim_max = 0;
	this->head = NULL;
	this->last = NULL;
	this->help = NULL;
}

Coada::Coada(Nod * head, Nod * last, int dim_max)
{
	this->dim_max = dim_max;
	this->head = head;
	this->last = last;
}

Coada::Coada(const Coada & c)
{
	this->dim_max = c.dim_max;
	this->head = c.head;
	this->last = c.last;
}

Coada::~Coada()
{
	/*Nod *p = head->next;
	while (p != last)
	{
		delete head;
		head = p;
		p = p->next;
	}*/
}

istream & operator>>(istream &in, Coada &c)
{
	cout << "Cate noduri vrei sa aiba coada?\n";
	int nr_noduri;
	char valoare_nod;
	cin >> nr_noduri;
	for (int i = 0; i < nr_noduri; i++)
	{
		cin >> valoare_nod;
		c.add_node(valoare_nod);
	}
	return in;
}

ostream & operator<<(ostream &out, const Coada & c)
{
	if (c.head == NULL || c.last == NULL)
	{
		cout << "Coada este VIDA\n";
		return out;
	}
	cout << "Coada este123 : \n";
	Coada temp;

	temp.help = c.head;
	while (temp.help != NULL)
	{
		cout << temp.help->get_data() << ' ';
		temp.help = temp.help->get_next();
	}
	cout << endl;
	return out;
}

Coada & Coada::operator=(const Coada &c1)
{
	this->dim_max = c1.dim_max;
	this->head = c1.head;
	this->last = c1.last;
	this->help = c1.help;

	return *this;
}

void Coada::add_node(char x)
{
	dim_max++;
	Nod *p = new Nod;
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

void Coada::pop_node()
{
	this->dim_max--;
	Nod *del;
	del = this->head;
	if (this->head != NULL)
	{
		head = head->next;
		delete del;
	}
}

DEQUE::DEQUE()
{
	this->dim_max = 0;
	this->head = NULL;
	this->last = NULL;
	this->help = NULL;
}

DEQUE::DEQUE(Nod * head, Nod * last, int dim_max)
{
	this->head = head;
	this->last = last;
	this->dim_max = dim_max;
}

DEQUE::DEQUE(const DEQUE & dc)
{
	this->dim_max = dc.dim_max;
	this->head = dc.head;
	this->help = dc.help;
	this->last = dc.last;
}

void DEQUE::add_node(char data)
{
	Nod *p = new Nod;
	p->next = NULL;
	p->data = data;

	cout << "Unde doresti sa adaugi nodul?\n(1) La inceput\n(2) La sfarsit\n";
	short choice;
	cin >> choice;
	switch (choice)
	{
	case 1:
	{
		if (head == NULL)
		{
			head = p;
			last = p;
		}
		else
		{
			p->next = head;
			head = p;
		}

		break;
	}
	case 2:
	{
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
		break;
	}
	default:
	{
		cout << "DE CE INCERCI ALTCEVA????\n";
		break;
	}
	}
}

void DEQUE::pop_node()
{
	this->dim_max--;
	Nod *del;

	cout << "De unde vrei sa stergi nodul?\n(1)De la inceput\n(2)De la sfarsit\n";
	short choice;
	cin >> choice;
	switch (choice)
	{
	case 1:
	{
		if (head == NULL || last == NULL)
		{
			//cout << "COADA VIDA\n";
			break;
		}
		del = this->head;
		if (this->head != NULL)
		{
			head = head->next;
			delete del;
		}
		break;
	}
	case 2:
	{
		del = this->head;
		if (head == NULL || last == NULL)
			break;
	
		else if (head->next == NULL)
		{
			delete head;
			head = NULL;
			last = NULL;
		}
		else
		{
			while (del->next != last)
				del = del->next;

			Nod *temp = last;
			last = del;
			if (last != NULL)
				last->next = NULL;
			delete temp;
		}
		break;
	}
	default:
	{
		cout << "DE CE INCERCI ALTCEVA????\n";
		break;
	}
	}

}

DEQUE::~DEQUE()
{

}
istream & operator>>(istream &in, DEQUE &dc)
{
	cout << "Cate noduri vrei sa aiba coada?\n";
	int nr_noduri;
	char valoare_nod;
	cin >> nr_noduri;
	for (int i = 0; i < nr_noduri; i++)
	{
		if (i == 0)
			cout << "\nIntrodu valoarea primului nod : ";
		else
			cout << "\nIntrodu valoarea celui de-al " << i + 1 << "-lea : ";

		cin >> valoare_nod;
		dc.add_node(valoare_nod);
	}
	return in;
}

int main()
{
	/*Coada myq;
	cout << myq.get_dim() << endl;*/
	DEQUE deq, fin;
	
	//DEQUE test(NULL, NULL, 5);
	cin >> deq;
	cout << deq;
	deq.pop_node();
	fin = deq;
	cout << fin;
	
	system("pause");
}
#endif
