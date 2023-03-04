#include <iostream>
#include "tad.h"

using namespace std;

//funcion para saber si la lista esta vacia
bool warehouse::empty(){
	return (first==NULL);
}
//funcion para agregar elementos a la lista por el final
void warehouse::add(product x){
	node *new_node = new node(x);
	if(empty()){
		first=last=new_node;
	}else{
		last->next=new_node;
		new_node->prev=last;
		last=new_node;
	}
	first->prev=last;
	last->next=first;
	size++;
}
//funcion que devuelve el numero de elementos de la lista
int warehouse::size_of(){
	return size;
}
//funcion que muestra los elementos
void warehouse::show(){
	if(!empty()){
		node *p=first;
		for(int i=0;i<size;i++){
			p->data.to_string();
			p=p->next;
		}
		printf("\n\n\n");
	}else{
		printf("La lista est%c vac%ca\n",160,161);
	}
}
//elimina el ultimo de la lista
void warehouse::delete_last(){
	if(!empty()){
		if(first==last){
			first=last=NULL;
		}else{
			node *p=last;
			last->prev->next=first;
			first->prev=last->prev;
			last=last->prev;
			delete p;
		}
		size--;
	}
}
//retorna el ultimo elemento de la lista
node* warehouse::get_last(){
	return last;
}

//elimina el primero de la lista
void warehouse::delete_first(){
	if(!empty()){
		if(first==last){
			first=last=NULL;
		}else{
			node *p=first;
			last->next=first->next;
			first->next->prev=last;
			first=first->next;
			delete p;
		}
		size--;
	}
}
//retorna el primer elemento de la lista
node* warehouse::get_first(){
	return first;
}

//intercabia el nodo del parametro con el que esta despues de el
void warehouse::switch_with_next(node *x){
	if(!empty()){
		if(!(first==last)){
			if(x==first){
				first->next->prev=last;
				last->next=first->next;
				first->next->next->prev=first;
				first->prev=first->next;
				first->next=first->prev->next;
				first->prev->next=first;
				first=last->next;
			}else{
				if(x==last){
					first->prev=last->prev;
					last->next=first->next;
					first->next->prev=last;
					last->prev->next=first;
					last->prev=first;
					first->next=last;
					node *p=last;
					last=first->prev->next;
					first=p->prev->next;
				}else{            
					x->prev->next=x->next;
					x->next->prev=x->prev;
					x->next->next->prev=x;
					x->prev=x->next;
					x->next=x->prev->next;
					x->prev->next=x;
				}
			}
		}
	}else{
		printf("La lista est%c vac%ca\n",160,161);
	}
}

//intercambia la posicionde dos nodos dentro de la lista
void warehouse::replace(node *x,node *y){
	if(!empty()){
		if(!(first==last)){
			if(y->next!=x){
				if(x->next!=y){
					if(x!=y){
						node *p=y->prev;
						node *q=x->prev;
						x->prev=y->prev;
						y->prev=q;
						p->next=x;
						q->next=y;
						q=x->next;
						p=y->next;
						x->next=y->next;
						y->next=q;
						p->prev=x;
						q->prev=y;
						if(x==first){
							first=y;
						}else{
							if(y==first){
								first=x;
							}else{
								if(x==last){
									last=y;
								}else{
									if(y==last){
										last=x;
									}
								}	
							}
						}
					}
				}else{
					switch_with_next(x);
				}
			}else{
				switch_with_next(y);
			}
		}
	}
}

//filtra la muestra de productos segun su tipo
void warehouse::show_by_type(string type){
	if(!empty()){
		node *p=first;
		for(int i=0;i<size;i++){
			if(p->data.type==type){
				p->data.to_string();
			}
			p=p->next;
		}
		printf("\n");
	}else{
		printf("La lista est%c vac%ca\n",160,161);
	}
}
//funcion que elimina un nodo segun la id del producto
void warehouse::delete_by_id(int id){
	bool found=false;
	if(!empty()){
		node *p=first;
		if(first->data.id==id){
			delete_first();	
			found=true;
		}else{
			if(last->data.id==id){
				delete_last();
				found=true;
			}else{
				do{
					if(p->data.id==id){
						p->prev->next=p->next;
						p->next->prev=p->prev;
						delete p;
						found=true;
						size--;
						break;
					}
					p=p->next;
				}while(p!=first);
			}
			if(!found) cout<<"No se encontro la ID del producto que el usuario desea eliminar.";
		}
	}
}
//funcion que vende los productos
void warehouse::sell(int id,int sold){
	if(!empty()){
		node *p=first;
		do{
			if(p->data.id==id){
				break;
			}
			p=p->next;	
		}while(p!=first);
		if(p->data.amount>=sold){
			p->data.amount-=sold;
			system("cls");
			cout<<"\n--------------------------------FACTURA--------------------------------\n";
			printf("\n\tCompra realizada con exito!");
			printf("\n\tProducto comprado: ");cout<<p->data.name;
			printf("\n\tCantidad: %d",sold);
			double to_pay=(sold*p->data.price);
			printf("\n\tPrecio a pagar: $%f",to_pay);
			cout<<"\n-----------------------------------------------------------------------\n";
			if(p->data.amount==0){
				delete_by_id(p->data.id);
			}
		}else{
			cout<<"\nLo siento, no hay la cantidad de productos que deseas comprar  .";
		}
		
	}
}
//mostrar segun la marca
void warehouse::show_by_brand(string brand){
	if(!empty()){
		node *p=first;
		for(int i=0;i<size;i++){
			if(p->data.brand==brand){
				p->data.to_string();
			}
			p=p->next;
		}
		printf("\n");
	}else{
		printf("La lista est%c vac%ca\n",160,161);
	}
}

// Mostrar la cantidad de productos por tipo:
int warehouse::size_by_type(string Type){
	int cont=0;
	if(!empty()){
		node *p = first;
		for(int i = 0; i < size; i++){
			if(p->data.type == Type){
				cont+=p->data.amount;
			}
			p = p->next;
		}
	}
	return cont;
}

// Mostrar un producto por id:
node* warehouse::search_id(int id){
	node* aux;
	aux->data.id=-1000;
	node *p = first;
	if(!empty()){
		do{
			if(p->data.id==id){
				return p;
			}
			p=p->next;
			}while(p!=first);
	} 
	return aux;
}
//muestra los ultimos 5 nodos
void warehouse::five_last_added(){
	if(!empty()){
		node *p=last;
		for(int i=0;i<5;i++){
			p->data.to_string();
			p=p->prev;
		}
		printf("\n");
	}else{
		printf("La lista est%c vac%ca\n",160,161);
	}
}










