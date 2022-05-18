/* Binary tree application example
1. inorder traversal - iterative version (loop) 
2. level-order traversal algorithm 
3. tree copy
4. equality test
*/
#include <iostream>
#include <string>
using namespace std;
#define SIZE 100

class node{
public:
    node *left, *right;
    string name;
    double score;
    void set_data(string n , double s);
};
class my_tree{
    public :
    int node_count;                               // 현재 node 수
    node *root;                                   // root를 가리키는 Pointer
    
    my_tree();                                    // 초기화
    int insert_root(node t);                      // root로 내용 t추가
    int insert_left(string tname, node t);        // tname의 왼쪽에 t추가
    int insert_right(string tname, node t);       // tname의 오른쪽에 t추가
    double score_sum();                           // 모든 node의 score 합
    double score_average();                       // 모든 node의 score 평균
    void print_data_inorder();                    // inorder 순서로 모든 node의 값 출력
    void print_data_preorder();                   // preorder 순서로 모든 node의 값 출력
    void print_data_postorder();                  // postorder 순서로 모든 node의 값 출력
    
    void nonrecursive_inorder();                  //non-recursive inorder traversal
    void print_data_levelorder();
};
class nstack{                        // stack의 용도 : stack에 tree의 주소값을 저장해서 사용        
    node* s[SIZE];
    int top;
public:
    nstack();
    void push(node * a);
    node* pop();
    bool stack_full();
    bool stack_empty();
    
};
node * make_copy(node *p);
bool equal_test (my_tree t1 , my_tree t2);
void copy_tree (my_tree & t1, my_tree t2);
int main(){
    my_tree thetree;
    node tmp;
    
    tmp.set_data("Kim", 8.1);
    thetree.insert_root(tmp);
    tmp.set_data("Lee", 6.5);
    thetree.insert_left("Kim",tmp);
    tmp.set_data("Park", 8.3);
    thetree.insert_right("Kim",tmp);
    tmp.set_data("Choi", 7.2);
    thetree.insert_left("Lee", tmp);
    tmp.set_data("Ryu" , 9.0);
    thetree.insert_right("Lee", tmp);
    tmp.set_data("Cho", 7.7);
    thetree.insert_right("Park", tmp);
    cout << "\nNon-recursive Inorder Result \n";
    thetree.nonrecursive_inorder();
    cout<< "\n Level - Order traversal Result \n";
    thetree.print_data_levelorder();
    my_tree tree2;
    copy_tree(tree2, thetree);
    cout<<"\nThe inorder tracersal Result of the new tree \n";
    tree2.print_data_inorder();
    if(equal_test(tree2,thetree))
        cout<< "Yes\n";
    else
        cout<<"No\n";
    tmp.set_data("Youn", 7.7);
    thetree.insert_right("Cho", tmp);
    if(equal_test(tree2, thetree))
        cout << "Yes\n";
    else
        cout<<"No\n";
    return 0;
    
    
}

void node::set_data(string n, double s){
    name = n;
    score = s;
}
my_tree::my_tree(){
    node_count = 0 ;
    root = NULL;
}
nstack::nstack(){
    top = 0;
}
void nstack::push(node *a){
    if (!stack_full()){
        s[top] = a;
        top ++;
    }
}
node* nstack::pop(){
    if(!stack_empty()){
        top --;
        return s[top];
    }
    else
        return NULL;
}
bool nstack::stack_full(){
    if(top >= SIZE)
        return true;
    else
        return false;
}
bool nstack::stack_empty(){
    if(top == 0)
        return true;
    else
        return false;
}
class my_queue{
    node *q[SIZE];
    int rear , front;
public :
    my_queue();
    void insert_q(node *a);
    node* delete_q();
    bool q_empty();
    bool q_full();
};

my_queue::my_queue(){
    rear = 0;
    front = 0;
}
bool my_queue::q_full(){
    if(front == (rear+1)%SIZE)
        return true;
    else
        return false;
}

bool my_queue::q_empty(){
    if (rear == front)
        return true;
    else
        return false;
}
void my_queue::insert_q(node*a){
    if(!q_full()){
        q[rear] = a;
        rear = (rear+1)%SIZE;
    }
}

node* my_queue::delete_q(){
    node * tmp;
    if(!q_empty()){
        tmp = q[front];
        front = (front+1)%SIZE;
        return tmp;
    }
    else
        return NULL;
}

void my_tree::nonrecursive_inorder(){
    nstack s1;
    node *t;
    
    t = root;
    while(1)
    {
        while(t != NULL){
            s1.push(t);
            t = t->left;
        }
        while(t==NULL){
            if(s1.stack_empty())
                return;
            t= s1.pop();
        }
        cout<<t->name <<":" << t-> score << endl;
        t = t->right;
    }
}


//level-order traversal algorithm

void my_tree::print_data_levelorder(){
    my_queue a1;
    node *t;
    
    if(root == NULL)
        return;
    a1.insert_q(root);
    while(1)
    {
        if(a1.q_empty())
            return;
        t = a1.delete_q();
        cout << t->name <<":" << t->score <<"\n"; // t.name과 같지 않다. 여태껏은 t.name 이런 식으로 했음 t가 pointer 변수이기 때문
        if(t->left != NULL)
            a1.insert_q(t->left);
        if(t->right!= NULL)
            a1.insert_q(t->right);
    }
}

// 이걸 내가 생각해내서 만들 수 있을까? tree 를 copy 하는 function
node * make_copy(node *p)
{
    node *t;
    
    if(p == NULL)
        return NULL;
    t = new node;
    
    *t = *p; // data copy
    t -> left = make_copy(p->left);
    t -> right = make_copy(p -> right);
    return t;
}

void copy_tree (my_tree & t1, my_tree t2)
{
    t1.node_count = t2.node_count;
    t1.root = make_copy(t2.root);
}


// Equality Test 구현
bool equal_test(node *p1 , node *p2)
{
/*
    if((p1 == NULL) && (p2 == NULL))
        return true;
    //p1 만 NULL 이다
    if (p1 == NULL)
        return false;
    //p2만 NULL 이다.
    if (p2 == NULL)
        return false;
    if(p1->name != p2 ->name)
        return false;
    if(p1 ->score != p2 -> score)
        return false;
    if(equal_test(p1->left,p2->left) && equal_test(p1->left,p2->right))
        return true;
    else
        return false;
  */
    //확실하게 괄호를 쳐주길 원하구나
    return (((p1 == NULL) && (p2==NULL)) || ((p1!=NULL) && (p2!=NULL) && (p1->name == p2 ->name) && (p1->score == p2->score) && equal_test(p1->left,p2->left) && equal_test(p1->right , p2->right)));
}

bool equal_test (my_tree t1 , my_tree t2){
    //node count 수가 다르면 바로 false Return
    if (t1.node_count != t2.node_count)
        return false;
    return equal_test(t1.root , t2.root);
}
int my_tree::insert_root(node t){
    if(root != NULL)
        return 0;
    node *p;
    p = new node; 
    (*p) = t;
    p->left = NULL; 
    p->right = NULL; 
    root = p; 
    node_count++; 
    return 1; 
}


int node_insert_left(node *p, string tname, node tnode){
    if(p==NULL) return 0; 
    if(p->name == tname){
        if(p->left != NULL) 
            return -1;
        node *t;
        t = new node;
        (*t) = tnode;
        t->left = NULL;
        t->right = NULL;
        p->left = t;
        return 1;
    }
    else{
        int result = node_insert_left(p->left, tname, tnode);
        if(result!=0)
            return result;
        return node_insert_left(p->right,tname,tnode);
    }
}

int node_insert_right(node *p, string tname, node tnode){
    if(p==NULL) return 0;
    if(p->name == tname){
            if(p->right != NULL)
                return -1;
        node *t;
        t = new node;
        (*t) = tnode;
        t-> left = NULL;
        t-> right = NULL;
        p-> right = t;
        return 1;
    }
    else{
        int result = node_insert_right(p->left, tname, tnode);
        if(result!=0)
            return result;
        return node_insert_right(p->right,tname, tnode);
    }
}

int my_tree::insert_left(string tname, node tnode){
    
    int result;
    
    result = node_insert_left(root,tname,tnode); // member 함수가 아니다.
    if(result ==1)
        node_count ++;
    return result;
    
}


int my_tree::insert_right(string tname , node tnode){

    int result;
    
    result = node_insert_right(root, tname, tnode); 
    if(result == 1)
        node_count++;
    return result;

}

double sum_allnodes(node *p){
    if (p==NULL)
        return 0;
    return sum_allnodes(p->left) + sum_allnodes(p->right)+p->score;
}

double my_tree::score_sum(){
    return sum_allnodes(root); 
}

double my_tree::score_average(){
    return score_sum()/node_count;
}

void inorder_print(node *p)
{
    if(p==NULL) return;
    
    inorder_print(p->left);
    cout <<p->name<<" : " << p->score << "\n";
    inorder_print(p->right);
}

void my_tree::print_data_inorder(){
    inorder_print(root);
}

void preorder_print(node *p)
{
    if(p==NULL) return;
    
    cout <<p->name<<" : " << p->score << "\n";
    preorder_print(p->left);
    preorder_print(p->right);
}

void my_tree::print_data_preorder(){
    preorder_print(root);
}

void postorder_print(node *p)
{
    if(p==NULL) return;
    
    postorder_print(p->left);
    postorder_print(p->right);
    cout <<p->name<<" : " << p->score << "\n";
}

void my_tree::print_data_postorder(){
    postorder_print(root);
}

