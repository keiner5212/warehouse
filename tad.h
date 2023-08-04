#include <iostream>
#include <string.h>
#include <windows.h>
using namespace std;
// producto que vamos a almacenar y trabajar
struct product
{
	char name[55];
	string brand;
	string type;
	int id;
	double price;
	int amount;
	void to_string()
	{
		_sleep(20);
		cout << "\n---------------------------------------------------------------------------";
		cout << "\nNombre: " << name;
		printf("\tId: %d\tPrecio: $%.1f\nDisponibles: %d", id, price, amount);
		cout << "\tTipo: " << type;
	}
};

// nodo para nuestra estructura de lista circular doble
struct node
{
	product data;
	node *next;
	node *prev;
	node(product x)
	{
		data = x;
		next = NULL;
		prev = NULL;
	}
};

// estructura de nuestro tad
class warehouse
{
	node *first = NULL;
	node *last = NULL;
	int size = 0;

public:
	// funciones basicas
	bool empty();					//
	void add(product x);			//
	int size_of();					//
	void show();					//
	void delete_last();				//
	node *get_last();				//
	void delete_first();			//
	node *get_first();				//
	void switch_with_next(node *x); //
	void replace(node *x, node *y); //
	// funciones para los requerimientos

	void delete_by_id(int id);		  //
	int size_by_type(string type);	  //
	node *search_id(int id);		  //
	void show_by_type(string type);	  //
	void show_by_brand(string brand); //
	void sell(int id, int sold);	  //
	void five_last_added();
};
