#include <iostream>
using std::cout;

struct nodes {
    int data;
    nodes* next;
};


class list {
    private:
        nodes* head;
        nodes* tail;
    public:
        void create_node(int value);
        void insert_start(int value);
        void insert_position(int pos, int value);
        void delete_first();
        void delete_last();
        void delete_position(int pos);
        void show_all_element();
        list();

};

list::list(){
    head = nullptr;
    tail = nullptr;
}

void list::create_node(int value){
    nodes *new_node = new nodes;
    new_node ->data = value;
    new_node ->next = nullptr;

    if (tail == nullptr){
        head = new_node;
        tail = new_node;
    }else{
        tail ->next = new_node;
        tail = new_node;
    }
}

void list::insert_start(int value){
    nodes *new_node = new nodes;
    new_node ->data = value;
    new_node ->next = head;
    head = new_node;
    
}

void list::insert_position(int pos, int value){
    nodes *previous = new nodes;
    nodes *current = new nodes;
    nodes *new_node = new nodes;
    current = head;
    for(size_t i = 1; i < pos; ++i){
        previous = current;
        current = current ->next;
    }
    new_node ->data = value;
    previous ->next = new_node;
    new_node ->next = current;
}

void list::delete_first(){
    nodes *new_node = new nodes;
    new_node = head;
    head = head ->next;
    delete new_node;
}

void list::delete_last(){
    nodes *current = new nodes;
    nodes *previous = new nodes;
    current = head;
    while(current ->next != nullptr){
        previous = current;
        current = current ->next;
    }
    tail = previous;
    previous ->next = nullptr;
    delete current;
}

void list::delete_position(int pos){
    nodes *current = new nodes;
    nodes *previous = new nodes;
    current = head;
    for(size_t i = 1; i < pos; ++i){
        previous = current;
        current = current ->next;
    }
    previous ->next = current ->next;
}

void list::show_all_element(){
    nodes *new_node = new nodes;
    new_node = head;
    while (new_node != nullptr){
        cout << new_node ->data <<"\t";
        new_node = new_node ->next; 
    }
    
}

int main(){
    list node;
    node.create_node(5);
    node.create_node(20);
    node.create_node(10);
    node.create_node(15);
    cout <<"\n********************\n";
    cout <<"Display all nodes";
    cout <<"\n********************\n";
    node.show_all_element();
    cout <<"\n********************\n";
    cout <<"Insert to end";
    cout <<"\n********************\n";
    node.create_node(12);
    node.show_all_element();
    cout <<"\n********************\n";
    cout <<"Insert to start";
    cout <<"\n********************\n";
    node.insert_start(13);
    node.show_all_element();
    cout <<"\n********************\n";
    cout <<"Insert to manual position:";
    cout <<"\n********************\n";
    node.insert_position(3,45);
    node.show_all_element();
    cout <<"\n********************\n";
    cout <<"Delete to end";
    cout <<"\n********************\n";
    node.delete_last();
    node.show_all_element();
    cout <<"\n********************\n";
    cout <<"Delete to start";
    cout <<"\n********************\n";
    node.delete_first();
    node.show_all_element();
    cout <<"\n********************\n";
    cout <<"Delete to position";
    cout <<"\n********************\n";
    node.delete_position(2);
    node.show_all_element();
    
    return 0;
}