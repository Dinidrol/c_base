#include <cstring>
#include <iostream>

struct nodes {
    char data[100];
    nodes* next;
};


class list {
    public:
        void insert(char* str);
        void del_next();
        void go_next();
        void go_first();
        const char* show();
        int size();

        list();
        ~list();

    private:
        nodes* head;
        nodes* position;
        int count_element;
        void free();
};

list::list(){
    head = NULL;
    count_element = 0;
    go_first();
}

list::~list(){
    free();
}

void list::insert(char* str){
    nodes * new_node = new nodes;
    strcpy(new_node->data,str);
    if (position != NULL){
        new_node -> next = position -> next;
        position -> next = new_node;
    }else{
        new_node -> next = new_node;
        position = head = new_node;
    }
    count_element++;
}

void list::del_next(){
    if(position != NULL){
        nodes* tmp = position -> next;
        position -> next = position -> next -> next;
        if(tmp == head){
            head = tmp -> next;
        }
        delete tmp;
    }
    count_element --;
}

void list::go_next(){
    if(position != NULL){
        position = position -> next;
    }
}

void list::go_first(){
    position = head;
}

const char* list::show(){
    if (position != NULL){
        return position -> data;
    }else{
        return nullptr;
    }
}

int list::size(){
    return count_element;
}

void list::free(){
    go_first();
    while (head -> next != head){
        del_next();
    }
    del_next();   
}

int main(){
    char name1[] = "Dima";
    char name2[] = "Petro";
    char name3[] = "Gnaj";

    list student_list;
    
    
    student_list.insert(name1);
    student_list.insert(name2);
    student_list.insert(name3);
 
    
    student_list.go_first();
    for(int i = 1; i <= student_list.size(); i++){
        std::cout << student_list.show() << std::endl;
        student_list.go_next();
    }
 
    
    student_list.go_first();
    student_list.go_next();
    student_list.go_next();
    student_list.del_next();
    
    
    student_list.go_first();    
    for(int i = 1; i<=student_list.size(); i++){
        std::cout << student_list.show() << std::endl;
        student_list.go_next();
    }
    
    return 0;
}