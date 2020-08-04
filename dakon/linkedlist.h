#include <iostream>
using namespace std;

template<class temp>
class Node{
private:
	temp val;
	Node<temp> *next;
public:
	Node(){ next=NULL; }
	void setValue(temp v){
		val=v;
	}
	temp getValue(){
		return val;
	}
	void setNext(Node<temp> *l){
		next=l;
	}
	Node<temp>* getNext(){
		return next;
	}
	temp* getdata(){
		return &val;
	}
};

template <class temp>
class LList{
private:
	Node<temp> *head;
	Node<temp> *tail;
public:
	LList(){
		head=NULL;
		tail=NULL;
	}
	void add(temp value){
		Node<temp> *tmp= new Node<temp>();
		tmp->setValue(value);
		if(head==NULL){
			head=tmp;
			tail=tmp;
		} else {
			tail->setNext(tmp);
			tail = tmp;
			tail->setNext(head);
		}
	}
	Node<temp>* gethead(){
		return head;
	}
};

//#include <iostream>
//using namespace std;
//
//template<class type>
//class node {
//private:
//	type data;
//	node<type> *next, *prev;
//public:
//	node() { next = NULL; }
//
//	//PAM Data
//	void setData(type newData) { data = newData; }
//	type getData() { return data; }
//	type *getD() { return &data; }
//
//	//PAM Node
//	void setNext(node<type> *newNext) { next = newNext; }
//	void setPrev(node<type> *newPrev) { prev = newPrev; }
//	node<type> *getNext() { return next; }
//	node<type> *getPrev() { return prev; }
//};
//
//template<class type>
//class cdll {
//private:
//	node<type> *head, *tail;
//public:
//	cdll() { head = NULL, tail = NULL; }
//	node<type>* getHead() {
//		return head;
//	}
//	//Add Data paling blkg
//	void addBack(type data) {
//		node<type> *baru = new node<type>();
//		baru->setData(data);
//
//		//Apakah list masih kosong?
//		if(head == NULL) {
//			head = baru;
//			tail = baru;
//		}
//		else {
//			//Kalau list tidak kosong
//			tail->setNext(baru);
//			baru->setPrev(tail);
//			tail = baru;
//			head->setPrev(tail);
//			tail->setNext(head);
//		}
//	}
//
//	//Delete by index
//	void delIndex(int n) {
//		node<type> *i = head;
//		int j = 0;
//		//cek kalau index 0
//		if(n == 0) {
//			head = i->getNext();
//			tail->setNext(head);
//			delete i;
//		} 
//		//selain index 0
//		else {
//			do {
//				if(j + 1 == n) {
//					node<type> *temp = i->getNext();
//					node<type> *temp2 = temp->getNext();
//					i->setNext(temp->getNext());
//					temp2->setPrev(i);
//					delete temp;
//					break;
//				}
//				j++;
//				i = i->getNext();
//			} while (i != head);
//		}
//	}
//
//	//View semua data
//	void viewFront() {
//		node<type> *i = head;
//		do {
//			cout << i->getData() << " ";
//			i = i->getNext();
//		} while(i != head);
//		cout << endl;
//	}
//
//	void viewBack() {
//		node<type> *i = tail;
//		do {
//			cout << i->getData() << " ";
//			i = i->getPrev();
//		} while(i != tail);
//		cout << endl;
//	}
//};