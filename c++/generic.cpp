#include <iostream>
using namespace std;
template<class gt>
class node{
    public:gt data;
    node *link;
};
template<class gt>
class list{
    node<gt> *first;
    public: void insert_front();
    void delete_front();
};

void list::insert_front(){
    node *t=new node();
    cin>>t->data;
    t->link=NULL;

    if(first!=NULL)
        t->link;
    first=t;
}

void list::delete_front(){
    if(first==NULL){
        cout<<"empty\n";
        return;
    }
    for(node* t=first;t!=NULL;t=t->link){
        cout<<t->data;
    }
}

int main(){
    list<int> ob1;
    cout<<sizeof(ob1);
    // ob1.insert_front();
    // ob1.insert_front();
    // ob1.delete_front();
    return 0;
}