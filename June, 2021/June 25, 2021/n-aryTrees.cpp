#include <vector>
#include <iostream>
#include <queue>
using namespace std;


// TREENODE CLASS CREATION
template <typename T>
class TreeNode{
    public:
    int data;
    vector<TreeNode<int>*> children;
    TreeNode(int data){
        this->data = data;
    }
};

//TAKING INPUT A TREE RECURSIVELY
TreeNode<int>* takeInputRecursive(){
    int rootData;
    cout<<"Enter node: ";
    cin>>rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);

    int numChild;
    cout<<"Enter no. of children of node: ";
    cin>>numChild;
    for(int i=0; i<numChild; i++){
        TreeNode<int> *child = takeInputRecursive();
         //Each child node is inserted into
        // the list of children nodes.
        root->children.push_back(child);  
    }
    return root;
}

// PRINT TREE RECURSIVELY
void printRecursive(TreeNode<int>* root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<":";
    for(int i=0; i<root->children.size(); i++){
        cout<<root->children[i]->data<<" ";
    }
    cout<<endl;
    for(int i=0; i<root->children.size(); i++){
        printRecursive(root->children[i]);
    }
}

// TAKING INPUT A TREE LEVEL-WISE
TreeNode<int>* takeInputLevelWise(){
    int rootData;
    cout<<"Enter root of tree: ";
    cin>>rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);
    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);

    while(pendingNodes.size() != 0){
        TreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        int numChild;
        cout<<"Enter no. of children of node: ";
        cin>>numChild;
        for(int i=0; i<numChild; i++){
            int childData;
            cout<<"Enter child of node: ";
            cin>>childData;
            TreeNode<int> *child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }
    return root;
}

// PRINT A TREE LEVEL-WISE
void printLevelWise(TreeNode<int> *root){
    if(root == NULL){
        return;
    }
    queue<TreeNode<int>*> pendingNodes;
    TreeNode<int>* front = root;
    pendingNodes.push(front);

    while(pendingNodes.size() != 0){
        TreeNode<int> *node = pendingNodes.front();
         cout<<node->data<<":";
        pendingNodes.pop();
        for(int i=0; i< node->children.size(); i++){

            if((i+1) == node->children.size()){
                cout<<node->children[i]->data;
            }
            else{
                cout<<node->children[i]->data<<",";
            }
            pendingNodes.push(node->children[i]);
        }
        cout<<endl;
    }
}

// COUNT NODES IN A TREE
int count(TreeNode<int>* root){
    //Edge Case
    if(root == NULL){
        return 0;
    }

    int countnodes = 1;
    for(int i=0; i<root->children.size(); i++){
        countnodes = countnodes + count(root->children[i]);
    }
    return countnodes;
}

//SUM OF NODES IN A TREE
int sum(TreeNode<int> *root){
    //Edge Case
    if(root == NULL){
        return 0;
    }
    int sumnodes = root->data;
    for(int i=0; i<root->children.size(); i++){
        sumnodes = sumnodes + sum(root->children[i]);
    }
    return sumnodes;
}

//MAXIMUM DATA NODE IN A TREE
TreeNode<int>* maxNode(TreeNode<int> *root){
    //Edge Case
    if(root == NULL){
        return NULL;
    }

    TreeNode<int> *max = root;
    for(int i=0; i<root->children.size(); i++){
        TreeNode<int> *ans = maxNode(root->children[i]);
        if(ans->data > max->data){
            max = ans;
        }
    }
    return max;
}

//FIND HEIGHT OF TREE
int heightOfTree(TreeNode<int> *root){
    //Edge Case
    if(root == NULL){
        return 0;
    }

    int ans = 0;
    for(int i=0; i<root->children.size(); i++){
        int height = heightOfTree(root->children[i]);
        ans = max(ans, height);
    }
    return ans+1;
}

//COUNT LEAF NODES IN A TREE
int countLeafNodes(TreeNode<int>* root){
    if(root == NULL){
        return 0;
    }
    int count = 0;
    if(root->children.size() == 0){
        count += 1;
    }
    for(int i=0; i<root->children.size(); i++){
        count += countLeafNodes(root->children[i]);
    }
    return count;
}

//POSTORDER TRAVERSAL
void postOrderTraversal(TreeNode<int> *root){
    if(root == NULL){
        return;
    }
    for(int i=0; i<root->children.size(); i++){
        postOrderTraversal(root->children[i]);
    }
    cout<<root->data<<" ";
}

//PREORDER TRAVERSAL
void preOrderTraversal(TreeNode<int> *root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    for(int i=0; i<root->children.size(); i++){
        preOrderTraversal(root->children[i]);
    }
}

//CHECK IF X IS PRESENT IN THE TREE
bool isPresent(TreeNode<int> *root ,int x){
    if(root == NULL){
        return false;
    }
    if(root->data == x){
        return true;
    }
    for(int i=0; i<root->children.size(); i++){
        bool ans = isPresent(root->children[i], x);
        if(ans == true){
            return ans;
        }
    }
    return false;
}

//COUNT NODES WHICH CONTAIN DATA GREATER THAN X
int getLargeNodesCount(TreeNode<int> *root, int x){
    if(root == NULL){
        return 0;
    }
    int count = 0;
    if(root->data > x){
        count += 1;
    }
    for(int i=0; i<root->children.size(); i++){
        count += getLargeNodesCount(root->children[i], x);
    }
    return count;
}

//CHECK IF TWO TREES ARE STRUCTURALLY IDENTICAL
bool isIdentical(TreeNode<int> *root1, TreeNode<int> *root2){
    if(root1 == NULL || root2 == NULL){
        return false;
    }
    if(root1->children.size() != root2->children.size()){
        return false;
    }
    bool ans = false;
    if(root1->data == root2->data){
        ans = true;
    }
    for(int i=0; i<root1->children.size(); i++){
        ans = isIdentical(root1->children[i], root2->children[i]);
        // if(ans == true){
        //     return ans;
        // }
    }
    return ans;
}

int main(){
    //TreeNode<int> *root = takeInputRecursive();
    TreeNode<int> *root = takeInputLevelWise();
    //printRecursive(root);
    printLevelWise(root);
    cout<<"No. of nodes in the tree: "<< count(root)<< endl;
    cout<<"Sum of nodes in the tree: "<< sum(root)<< endl;
    cout<<"Max data node in the tree: "<< maxNode(root)->data<< endl;
    cout<<"Height of tree: "<<heightOfTree(root)<<endl;
    cout<<"Leaf nodes in the tree: "<<countLeafNodes(root)<<endl;
    cout<<"Post-Order Traversal of Tree: ";
    postOrderTraversal(root);
    cout<<"\n Pre-Order Traversal of Tree: ";
    preOrderTraversal(root);
    cout<<"\n 30 is present in Tree: "<< isPresent(root, 30)<<endl;
    cout<<"80 is present in Tree: "<< isPresent(root, 80)<<endl;
    cout<<"Nodes count which have value greater than x: "<<getLargeNodesCount(root, 5);
    cout<<"\nIdentical Trees Check: "<<isIdentical(root, root);
    return 0;
}