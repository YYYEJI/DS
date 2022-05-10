// Binary search tree
#include <iostream>
using namespace std;

class bst_node{
public:
    string s_id;              // student number
    string name;              // name
    double score;             // score
    bst_node *left, *right;   // left node, right node
    bst_node();               // constructor 1
    bst_node(string s1, string s2, double n);        // constructor 2
    void set_data(string s1, string s2, double n);   // accessor
};
class bst_tree{
    bst_node* root;           // root node
    int csize;                // number of nodes
public:
    bst_tree();              
    bool empty();
    int size();
    void insert_node(bst_node t);
    void show_inorder();
    bst_node search(string tid);    // s_id
};
void inorder_print(bst_node *p);
int main(){
    bst_node temp;
    bst_tree t1;
    
    temp.set_data("21900013", "Kim", 6.5);
    t1.insert_node(temp);
    temp.set_data("21900136", "Lee", 8.8);
    t1.insert_node(temp);
    temp.set_data("21900333", "Park", 9.2);
    t1.insert_node(temp);
    temp.set_data("21800442", "Choi", 7.1);
    t1.insert_node(temp);
    temp.set_data("21900375", "Ryu", 5.4);
    t1.insert_node(temp);
    temp.set_data("21700248", "Cho", 6.3);
    t1.insert_node(temp);

    cout << "\n\n Node List : inorder sequence \n";
    t1.show_inorder();

    string s_key = "21800442";
    temp = t1.search(s_key);

    cout << "\n -- " << s_key << "'s record ---" << endl;
    cout << " Student ID   : "<< temp.s_id << endl;
    cout << " Student Name : "<< temp.name << endl;
    cout << " Score: " << temp.score << endl;
    
    return 0;
}
bst_node::bst_node(){
    left = NULL;
    right = NULL;
}
bst_node::bst_node(string s1, string s2, double n){
    s_id = s1;
    name = s2;
    score = n;
    left = NULL;
    right = NULL;
}
void bst_node::set_data(string s1, string s2, double n){
    s_id = s1;
    name = s2;
    score = n;
}
bst_tree::bst_tree(){
    root = NULL;
    csize = 0;
}
bool bst_tree::empty(){
    if(root == NULL) return true;
    else return false;
}
int bst_tree::size(){
    return csize;
}
void bst_tree::insert_node(bst_node t){
    bst_node* p;           // For root node
    bst_node* tmp;         // For create new node

    tmp = new bst_node;
    *tmp = t;                
    tmp->left = NULL;      // left node
    tmp->right = NULL;     // left node

    if(root == NULL){
        root = tmp;
        return;
    }

    p = root;
    while(1){
        if(p->s_id == t.s_id){          // key already exists.
            cout<<"Insertion Failed : the Key "<<t.s_id<<"already exists."<<endl;
            return ;
        }
        if(p->s_id<t.s_id){             // new node의 key 값이 큰 경우
            if(p->right == NULL){
                p->right = tmp;
                return;
            }
            else 
                p=p->right;
        }
        else{                           // new node의 key 값이 작은 경우
            if(p->left == NULL){
                p->left = tmp;
                return;
            }
            else 
                p = p->left;
        }
    }
}
void bst_tree::show_inorder(){
    if(root == NULL)
        return;
    inorder_print(root);
}
void inorder_print(bst_node *p){
    if(p == NULL) return ;

    inorder_print(p->left);
    cout<<p->s_id<<" : "<<p->name<<" : "<<p->score<<"\n";
    inorder_print(p->right);
}
bst_node bst_tree::search(string tid){
    bst_node* p;
    p = root;
    
    bst_node tmp;          
    tmp.set_data("00000000", "None", -1);

    if(root == NULL){
        cout<<"The key "<<tid<<" does not exist.\n";
        return tmp;
    }
    while(1){
        if(p->s_id == tid)
            return (*p);
        if(p->s_id < tid){
            if(p->right == NULL){
                cout<<"The key "<<tid<<" does not exist.\n";
                return tmp;                
            }
            else 
                p = p->right;
        }
        else if(p->s_id > tid){
            if(p->left == NULL){
                cout<<"The key "<<tid<<" does not exist.\n";
                return tmp;                 
            }
            else    
                p = p->left;
        }
    }

}