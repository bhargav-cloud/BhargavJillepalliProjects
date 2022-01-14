#include <iostream>
using namespace std;
struct Node
{
   int x;
   Node * left;
   Node * right;
   Node(){
       left = NULL;
       right = NULL;
   }
   Node(int d, Node* l = 0, Node* r = 0)
   {
       x = d;
       left = l;
       right = r;
   }
};
//=====================================================================
class Tree
{
private:
   Node * root;
public:
   Tree()
   {
       root = NULL;
   }
//-----------------------------------------------------------------
   void insert(int x)
   {
       Node * ptr = new Node(x);
       cout << "\n-------------------------------------" << endl;
       cout << "Node Address: " << ptr << endl;
       if (root == NULL)
           root = ptr;
       else
       {
           Node * temp = root;
           while (true)
           {
               if (temp -> x > x)
               {
                   if (temp -> left == NULL) {
                       cout << "Node Parent Address: " << temp << endl;
                       cout << "Node Parent Value: " << temp -> x << endl;
                       temp -> left = ptr;
                       break;
                   } else
                       temp = temp -> left;
               } else
               {
                   if (temp -> right == NULL)
                   {
                       cout << "Node Parent Address: " << temp << endl;
                       cout << "Node Parent Value: " << temp -> x << endl;
                       temp -> right = ptr;
                       break;
                   } else
                       temp = temp -> right;
               }
           }
       }
       cout << "Root: " << root << endl;
       cout << "-------------------------------------" << endl;
   }
//-----------------------------------------------------------------
   public: void inOrder(){
       inOrder(root);
   }
   private: void inOrder(Node * temp) {
       if (temp != NULL)
       {
           inOrder(temp -> left);
           cout << temp -> x << " ";
           inOrder(temp -> right);
       }
   }
//-----------------------------------------------------------------
   public: void preOrder(){
       inOrder(root);
   }
   private: void preOrder(Node * temp)
   {
       if (temp != NULL) {
           cout << temp -> x << " ";
           preOrder(temp -> left);
           preOrder(temp -> right);
       }
   }
//-----------------------------------------------------------------
   public: void postOrder(){
       inOrder(root);
   }
   private: void postOrder(Node * temp)
   {
       if (temp != NULL) {
           postOrder(temp -> left);
           postOrder(temp -> right);
           cout << temp -> x << " ";
       }
   }
//-----------------------------------------------------------------
   public: void serial(){
       serial(root);
   }
   private: void serial(Node *n)
   {
       cout << '(';
       if (n != 0)
       {
           cout << n->x << ' ';
           serial(n->left); cout << ' ';
           serial(n->right);
       }
       cout << ')';
   }
//-----------------------------------------------------------------
   public: Node * getRoot() {
       return root;
   }
//-----------------------------------------------------------------
   public: void display(){
       display(root);
   }
   private: void display(Node * temp)
   {
       if (temp != NULL) {
           cout << endl;
           cout << "Parent: " << temp -> x << endl;
           cout << " Left Child of " << temp -> x << ": ";
           if (temp -> left == NULL)
               cout << "NULL" << endl;
           else
               cout << temp -> left -> x << endl;
           cout << " Right Child of " << temp -> x << ": ";
           if (temp -> right == NULL)
               cout << "NULL" << endl;
           else
               cout << temp -> right -> x << endl;
           display(temp -> left);
           display(temp -> right);
       }
   }
//-----------------------------------------------------------------
   bool isEmpty()
   {
       if (root == NULL)
           return true;
       return false;
   }
public:
//-----------------------------------------------------------------
   void removeAll(int value)
   {
       while (true)
       {
           Node * temp = root, * ptemp = root;
           while (temp != NULL && temp -> x != value)
           {
               ptemp = temp;
               if (temp -> x < value)
                   temp = temp -> right;
               else if (temp -> x > value)
                   temp = temp -> left;
           }
           if (temp == NULL)
           {
               cout << "All nodes cotaining " << value << " are deleted" << endl;
               break;
           } else
           {
               if (temp -> left == NULL && temp -> right == NULL)
               {
                   if (temp == root)
                       root = NULL;
                   else if (ptemp -> left == temp)
                       ptemp -> left = NULL;
                   else if (ptemp -> right == temp)
                       ptemp -> right = NULL;
               } else if (temp -> left == NULL && temp -> right != NULL)
               {
                   if (temp == root)
                       root = temp -> right;
                   else if (ptemp -> left == temp)
                       ptemp -> left = temp -> right;
                   else if (ptemp -> right == temp)
                       ptemp -> right = temp -> left;
               } else if (temp -> right == NULL && temp -> left != NULL)
               {
                   if (temp == root)
                       root = temp -> left;
                   else if (ptemp -> left == temp)
                       ptemp -> left = temp -> left;
                   else if (ptemp -> right == temp)
                       ptemp -> right = temp -> right;
               } else if (temp -> left != NULL && temp -> right != NULL)
               {
                   Node * tempHolder = temp, * ptempHolder = temp;
                   while (tempHolder -> left != NULL)
                   {
                       ptempHolder = tempHolder;
                       tempHolder = tempHolder -> left;
                   }
                   temp -> x = tempHolder -> x;
                   ptempHolder -> left = tempHolder -> right;
                   temp = tempHolder;
               }
               delete temp;
               cout << "Node Removed Successfully." << endl;
           }
       }
   }
//-----------------------------------------------------------------
   void remove(int value)
   {
       Node * temp = root, * ptemp = root;
       while (temp != NULL && temp -> x != value)
       {
           ptemp = temp;
           if (temp -> x < value)
               temp = temp -> right;
           else if (temp -> x > value)
               temp = temp -> left;
       }
       if (temp == NULL) {
           cout << "Value Not Found...." << endl;
       } else
       {
           if (temp -> left == NULL && temp -> right == NULL)
           {
               if (temp == root)
                   root = NULL;
               else if (ptemp -> left == temp)
                   ptemp -> left = NULL;
               else if (ptemp -> right == temp)
                   ptemp -> right = NULL;
           } else if (temp -> left == NULL && temp -> right != NULL)
           {
               if (temp == root)
                   root = temp -> right;
               else if (ptemp -> left == temp)
                   ptemp -> left = temp -> right;
               else if (ptemp -> right == temp)
                   ptemp -> right = temp -> left;
           } else if (temp -> right == NULL && temp -> left != NULL)
           {
               if (temp == root)
                   root = temp -> left;
               else if (ptemp -> left == temp)
                   ptemp -> left = temp -> left;
               else if (ptemp -> right == temp)
                   ptemp -> right = temp -> right;
           } else if (temp -> left != NULL && temp -> right != NULL)
           {
               Node * tempHolder = temp, * ptempHolder = temp;
               while (tempHolder -> left != NULL)
               {
                   ptempHolder = tempHolder;
                   tempHolder = tempHolder -> left;
               }
               temp -> x = tempHolder -> x;
               ptempHolder -> left = tempHolder -> right;
               temp = tempHolder;
           }
           delete temp;
           cout << "Node Removed Successfully." << endl;
       }
   }
   //-----------------------------------------------------------------
   void deleteAllNodes(Node * temp) {
       if (temp != NULL) {
           deleteAllNodes(temp -> left);
           deleteAllNodes(temp -> right);
           cout << "Address: " << temp << endl;
           cout << "Value: " << temp -> x << endl << endl;
           delete temp;
       }
   }
   ~Tree() {
       cout << "Below Nodes Deleted Successfully:" << endl;
       deleteAllNodes(root);
   }
   public: Node* find1(int val) {
       Node* ptr = root;
       while (ptr != NULL) {
           if (ptr->x > val) {
               ptr = ptr->left;
           }
           else if (ptr->x < val) {
               ptr = ptr->right;
           }
           else {
               return ptr;
           }
       }
       return NULL;
   }
// reccursive function find2
   public: Node* find2(int a){
       return find2(a,root);
   }
   private: Node* find2(int a,Node* temp){
       if(temp == NULL){
           return NULL;
       }
       if(temp->x == a){
           return temp;
       }else if(temp->x > a){
           return find2(a,temp->left);
       }
       return find2(a,temp->right);
   }
// function to find count of nodes
   public: int node_count() {
       return node_count(root);
   }

   private: int node_count(Node* node) {
       if (node == NULL) {
           return 0;
       }
       else {
           return (1 + node_count(node->left) + node_count(node->right));
       }
   }


   // to find depth of Tree
   public: int depth() {

return maxDepth(root);

}

int maxDepth(struct Node* node) {

if (node==NULL) {

return(0);

}

else {

// compute the depth of each subtree

int lDepth = maxDepth(node->left);

int rDepth = maxDepth(node->right);

// use the larger one

if (lDepth > rDepth) return(lDepth+1);

else return(rDepth+1);

}

}
};
//=====================================================================
int main(){
   Tree T, S;
   T.insert(50);
   T.insert(20);
   T.insert(80);
   T.insert(60);
   T.insert(90);
   T.insert(100);
   T.display();
   if(T.find1(20)!=NULL){
       cout<<endl<<"Address of 20 "<< " is" << T.find1(20)<<endl;
   }else{
       cout<<endl<<"NOT FOUND"<<endl;
   }
   if(T.find2(20)!=NULL){
       cout<<endl<<"Address of 20 "<<" is "<<T.find2(20)<<endl;
   }else{
       cout<<endl<<"NOT FOUN"<<endl;
   }
   cout<<endl;
   cout<<"NO of elements are "<<T.node_count();
   cout<<endl;
   cout<<" Depth is "<<T.depth()<<endl;
   cout<<endl;
  // T.serial(); cout << endl;
   //S = T;
   //S.serial(); cout << endl;
  // T.insert(100);
   //cout << "After insert 100\n";
  // T.serial(); cout << endl;
  // S.serial(); cout << endl;
   system("pause");
   return 0;
}