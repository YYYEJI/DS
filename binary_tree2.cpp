/* Traversal using binary tree
   inorder   ->  infix
   preorder  ->  prefix
   postorder ->  postfix
*/
#include <iostream>
using namespace std;
class node{
public:
    string c;
    node *left, *right;
    void set_data(string s);
};
class my_tree{                                // Binary tree
    int node_count;                           // 현재 node 수
    node *root;                               // root를 가르키는 pointer
public:
    my_tree();                                // 초기화
    int insert_root(node t);                  // root로 Node 내용 t 추가 -> empty 상태에서만 실행 가능
    int insert_left(string tname, node t);    // tname의 node 왼쪽에 t 추가
    int insert_right(string tname, node t);   // tname의 node 오른쪽에 t 추가

    void print_data_inorder();                // inorder 순서로 모든 Node의 값 출력
    void print_data_preorder();               // preorder 순서로 모든 Node의 값 출력
    void print_data_postorder();              // postorder 순서로 모든 Node의 값 출력
};
int node_insert_left(node *p, string tname, node tnode);     // tname node의 left의 new node 추가
int node_insert_right(node *p, string tname, node tnode);    // tname node의 right의 new node 추가
void inorder_print(node *p);
void preorder_print(node *p);
void postorder_print(node *p);

int main()
{
    my_tree thetree;
    node  tmp;
    tmp.set_data("+");
    thetree.insert_root(tmp);
    tmp.set_data("*");
    thetree.insert_left("+", tmp);
    tmp.set_data("/");
    thetree.insert_right("+", tmp);
    tmp.set_data("a");
    thetree.insert_left("*", tmp);
    tmp.set_data("b");
    thetree.insert_right("*", tmp);
    tmp.set_data("c");
    thetree.insert_left("/", tmp);
    tmp.set_data("d");
    thetree.insert_right("/", tmp);

    cout <<"\n Inorder Traversal Result \n";
    thetree.print_data_inorder();
    cout << "\n Preorder Traversal Result \n";
    thetree.print_data_preorder();
    cout << "\n Postorder Traversal Result \n";
    thetree.print_data_postorder();
    
    return 0;  
}
void node::set_data(string s){
    c = s;
}
my_tree::my_tree(){     // constructor: 초기 empty 상태 
    node_count = 0;
    root = NULL;
}
int my_tree::insert_root(node t){
    if(root!=NULL) return 0;        

    node *p;
    p = new node;
    (*p) = t;
    
    p->left = NULL;
    p->right =NULL;
    root = p;
    node_count ++;

    return 1;    
}
int my_tree::insert_left(string tname, node tnode){
    int result;

    result = node_insert_left(root, tname, tnode);
    if(result == 1)
        node_count++;
    return result;
}
int node_insert_left(node *p, string tname, node tnode){    // root, 찾을 Node의 name, 생성할 node의 값
    int result;

    if (p == NULL) return 0;              // root가 존재하지 않을 경우 
    if (p->c == tname) {               // root가 tname일 경우
        if (p->left != NULL) return -1;   // tname의 node를 찾았는데 left child가 있을 경우

        node *t;
        t = new node;
        (*t) = tnode;

        t->left = NULL;                   // left child NULL
        t->right = NULL;                  // right child NULL
        p->left = t;                     

        return 1;
    }
    else {
        result = node_insert_left(p->left, tname, tnode);
        if (result != 0)return result;
        return node_insert_left(p->right, tname,tnode);
    }
}
int my_tree::insert_right(string tname, node tnode){
    int result;

    result = node_insert_right(root, tname, tnode);
    if(result == 1)
        node_count++;
    return result;
}
int node_insert_right(node *p, string tname, node tnode){
    int result;
     
    if (p == NULL) return 0;
    if (p->c == tname) {
        if (p->right != NULL) return -1;

        node *t;
        t = new node;
        (*t) = tnode;

        t->left = NULL;
        t->right = NULL;
        p->right = t;

        return 1;
    }
    else {
        result = node_insert_right(p->left, tname, tnode);
        if (result != 0) return result;
        return node_insert_right(p->right, tname, tnode);
    }
}
void my_tree::print_data_inorder(){
    inorder_print(root);
}
void inorder_print(node *p){
    if(p == NULL) return ;

    inorder_print(p->left);                                                  
    cout<<p->c<<" ";
    inorder_print(p->right);
}
void my_tree::print_data_preorder(){
    preorder_print(root);
}
void preorder_print(node *p){
    if(p == NULL) return ;

    cout<<p->c<<" ";
    preorder_print(p->left);
    preorder_print(p->right);
}
void my_tree::print_data_postorder(){
    postorder_print(root);
}
void postorder_print(node *p){
    if(p == NULL) return ;

    postorder_print(p->left);
    postorder_print(p->right);
    cout<<p->c<<" ";
}