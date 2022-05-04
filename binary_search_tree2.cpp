// Menu-driven version
#include <iostream>
using namespace std;
#define INSERT               1
#define SHOW_ONE_ELEMENT     2
#define SHOW_ALL_ELEMENT     3
#define QUIT                 4

class bst_node{
public:
    string birth;             // Birth day
    string name;              // name
    double height;            // height
    double weight;            // weight
    bst_node *left, *right;   // left node, right node
    bst_node();               // constructor 1
    bst_node(string s1, string s2, double n1, double n2);        // constructor 2
    void set_data(string s1, string s2, double n1, double n2);   // accessor
};
class bst_tree{
    bst_node* root;           // root node
    int csize;                // number of nodes
public:
    bst_tree();              
    bool empty();
    int size();
    void insert_node();
    void show_inorder();
    void search(string tid);   
};
int get_a_menu();
void inorder_print(bst_node *p);

int main(){
    bst_tree t;
    int menu;
    string id;

    do{
        menu = get_a_menu();
        switch(menu){
            case INSERT : t.insert_node();
                break;
            case SHOW_ONE_ELEMENT : 
                cout << "\nEnter your birthday > ";
                cin >> id;
                t.search(id);
                break;
            case SHOW_ALL_ELEMENT : t.show_inorder();
                break;
            case QUIT:
                cout<<"Bye!!\n\n";
                break;
        }
    }while(menu!=QUIT);

    return 0;
}
int get_a_menu(){
    int n;
    cout<<"\n*** Choose what you want ***\n";
    cout<<"\n1.  insert a information\n";
    cout<<"2.  Show the information you want\n";
    cout<<"3.  Show the all information\n";
    cout<<"4.  Quit\n";
    cout<<"    Selet a command: ";

    cin>>n;
    return n;
}

bst_node::bst_node(){
    left = NULL;
    right = NULL;
}
bst_node::bst_node(string s1, string s2, double n1, double n2){
    birth = s1;
    name = s2;
    height = n1;
    weight = n2;
    left = NULL;
    right = NULL;

}
void bst_node::set_data(string s1, string s2, double n1, double n2){
    birth = s1;
    name = s2;
    height = n1;
    weight = n2;
}

bst_tree::bst_tree(){
    root = NULL;
    csize = 0;
}
bool bst_tree::empty(){
    if(csize == 0) return true;
    else return false;
}
int bst_tree::size(){
    return csize;
}
void bst_tree::insert_node(){
    bst_node* p;      // To find the t
    bst_node t;      
    bst_node* tmp;    // To return the t
    string b, n;      // birthday, name
    double h, w;      // height, weight

    tmp = new bst_node;

    cout << "Enter your birthday > ";
    cin >> b;
    cout << "Enter your name > ";
    cin >> n;
    cout << "Enter your height > ";
    cin >> h;
    cout << "Enter your weight > ";
    cin >> w;

    t.set_data(b, n, h,w);
 
    *tmp = t;
    tmp -> left = NULL;      // left node
    tmp -> right = NULL;     // left node

    if(root == NULL){
        root = tmp;
        return;
    }

    p = root;
    while(1){
        if(p->birth == t.birth){
            cout<<"Insertion Failed : the Key "<<t.birth<<"already exists."<<endl;
            return ;
        }
        if(p->birth<t.birth){
            if(p->right == NULL){
                p->right = tmp;
                return;
            }
            else 
                p=p->right;
        }
        else{
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
    cout<<"\n< Information List >\n";
    cout<<"----------------------\n";
    inorder_print(root);
    cout << endl;
}
void inorder_print(bst_node *p){
    if(p == NULL) return ;

    inorder_print(p->left);
    cout<<" - Birthday: " << p->birth<<endl;
    cout<<" - Name: " << p->name<<endl;
    cout<<" - Height: " << p->height<<endl;
    cout<<" - Weight: " << p->weight<<"\n";
    cout<<"----------------------\n";
    inorder_print(p->right);
}
void bst_tree::search(string tid){
    bst_node* p;
    p = root;
    
    // bst_node tmp;           
    // tmp.set_data("00000000", "None", -1);

    if(root == NULL){
        cout<<"The key "<<tid<<" does not exist.\n";
        return ;
    }
    while(1){
        if(p->birth == tid){
            cout<<" - Birthday: " << p->birth<<endl;
            cout<<" - Name: " << p->name<<endl;
            cout<<" - Height: " << p->height<<endl;
            cout<<" - Weight: " << p->weight<<"\n";
            return ;
        }
        if(p->birth < tid){
            if(p->right == NULL){
                cout<<"The key "<<tid<<" does not exist.\n";
                return ;                
            }
            else 
                p = p->right;
        }
        else if(p->birth > tid){
            if(p->left == NULL){
                cout<<"The key "<<tid<<" does not exist.\n";
                return ;                 
            }
            else    
                p = p->left;
        }
    }

}