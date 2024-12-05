#include <iostream>
#include <stdint.h>
#include <list>
using namespace std;

/// VECTOR
// don't know size, need to store: use vector
// vector does not change the order

/// MAP & MULTIMAP
// need to search: don't use vector, use map/tree

/// MULTISET




struct Node {
public:
    int number;
    Node* next;
    Node(int n , Node *node):number(n),next(node){};
};

//insert at the end
Node * insert_element(Node *node, int number){
    Node *new_node = new Node(number, nullptr);
    if(node == nullptr)
        return new_node;
    else{
        Node * current = node;
        while(current->next!= nullptr){
            current = current->next;
        }
        current->next = new_node;
        return node;
    }
}

void display_linked_list(Node *head){
    Node *current = head;
    while(current!= nullptr){
        std::cout << current->number << std::endl;
        current = current->next;
    }
}

//Forward Linked List
int main() {
    Node *head = nullptr;
    head = insert_element(head,8);
    head = insert_element(head,1);
    head = insert_element(head,6);
    head = insert_element(head,2);
    head = insert_element(head,5);
    head = insert_element(head,7);
    display_linked_list(head);



    std::list<int> linked_list;
    for(int i=0;i<5;++i){
        linked_list.push_front(i);
    }

    //forward iterator
    //std::forward_list<int>::iterator
    for(auto it = linked_list.begin();
        it!=linked_list.end();
        it++){
        cout << *it << endl;
    }

    //reverse iterator
    for(std::list<int>::reverse_iterator it = linked_list.rbegin();
        it != linked_list.rend();
        it++){
        cout << *it << endl;
    }

    //print linked list
    for(int &it :linked_list){
        cout << it << endl;
    }
}
