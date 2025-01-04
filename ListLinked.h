#include <ostream>
#include "List.h"
#include "Node.h"
#ifndef LISTLINKED_H
#define LISTLINKED_H
template <typename T>
class ListLinked : public List<T> {

    private:
 
        Node<T>* first;
	int n;
    public:
	ListLinked(){
	
		first = nullptr;
		n = 0;
	}
	~ListLinked(){
		while(first != nullptr){
			Node<T>* aux = first -> next;
			delete first;
			first = aux;
		}	
	}
	void insert(int pos, T e) override{
	
		if ( pos < 0 || pos > n){
	 	throw std::out_of_range("Posición Inválida");
		}
	
		Node<T>* new_node = new Node<T>(e);
		if ( pos == 0){ 
			new_node->next = first;
			first = new_node;
		}
		else{
			Node<T>* current = first;
			for (int i = 0; i < pos - 1; ++i) {
            			current = current->next;
        		}
			new_node->next = current->next;
			current->next = new_node;
		}
		n++;
	}

	void append(T e) override{
		insert(n, e);
	}

	void prepend( T e) override{
       	 	insert( 0, e);
	}

	T remove(int pos) override{
	
		if ( pos < 0 || pos >= n){
			throw std::out_of_range("Posición Inválida");
		}
		Node<T>* current = first;
		T removed_data;
		if ( pos==0){
			removed_data = first->data;
			Node<T>* temp = first;
			first = first->next;
			delete temp;
		}
		else{
			for ( int i = 0; i < pos - 1; i++){
				current = current->next;
			}
			Node<T>* temp = current->next;
			removed_data = temp->data;
			current->next = temp->next;
			delete temp;
		}
		n--;
		return removed_data;
	
	}
	T get(int pos) const override{
	
		if ( pos < 0 || pos >= n){
			throw std::out_of_range("Posición Inválida");
	}	Node<T>* current = first;
                for ( int i = 0; i < pos; i++){
                        current = current->next;
                        }
                        	
		T value = current-> data;
		return value;
	}
	int search(T e) const override{ 
		int pos = 0;
		Node<T>* current = first;
		while( current != nullptr){
		    
			if (current-> data == e){
				return pos;
			}
			current = current->next;
			++pos;
		}
		
		return -1;
	}
	bool empty() const override{
	 	return first == nullptr;
	
	}
	int size() const override{
		return n;
	
	}
        T operator[](int pos){                                               
		if ( pos < 0 || pos >= n){
		       	throw std::out_of_range("Posición Inválida");
        }
	       return get(pos);	
	}

	friend std::ostream& operator<<(std::ostream &out, const ListLinked<T> &list){
	Node<T>* current = list.first;
	out<<"[";

	while (current != nullptr){
		out << current->data;
		if ( current->next != nullptr){
			out << ",";
		}
		current = current->next;
	}
	out << "]";
	return out;
	}

 };

#endif
