#include <stdio.h>
#include <stdlib.h>
 
typedef struct Node
{
    int data;
    Node* left;
    Node* right;
} node_t;
 
 
 
void Free( node_t* root )
{
    if ( root == NULL )
        return;
 
    Free( root->left );
    Free( root->right );
    free( root );
}
 
int LeftOf( const int value, const node_t* root )
{
    // Nếu bạn muốn cây BST cho phép giá trị trùng lặp, hãy sử dụng dòng code thứ 2
    return value < root->data;
//    return value <= root->data;
}
 
int RightOf( const int value, const node_t* root )
{
    return value > root->data;
}
 
node_t* Insert( node_t* root, const int value )
{
    if ( root == NULL )
    {
        node_t* node = (node_t*)malloc( sizeof( node_t ) );
        node->left = NULL;
        node->right = NULL;
        node->data = value;
        return node;
    }
    if ( LeftOf( value, root ) )
        root->left = Insert( root->left, value );
    else if ( RightOf( value, root ) )
        root->right = Insert( root->right, value );
    return root;
}
 
// bool Search( const node_t* root, int value )
// {
//     if ( root == NULL ){
//         return false;
//     }
//     if(root->data == value){
//         return true;
//     }
//     else if ( LeftOf( value, root ) ){
//         return Search( root->left, value );
//     }
//     else if( RightOf( value, root ) ){
//         return Search( root->right, value );
//     }
//     return 0;
// }
 
int LeftMostValue( const node_t* root )
{
    while ( root->left != NULL )
        root = root->left;
    return root->data;
}
 
// node_t* Delete( node_t* root, int value )
// {
//     if ( root == NULL )
//         return root;
//     if ( LeftOf( value, root ) )
//         root->left = Delete( root->left, value );
//     else if ( RightOf( value, root ) )
//         root->right = Delete( root->right, value );
//     else
//     {
//         // root->data == value, delete this node
//         if ( root->left == NULL )
//         {
//             node_t* newRoot = root->right;
//             free( root );
//             return newRoot;
//         }
//         if ( root->right == NULL )
//         {
//             node_t* newRoot = root->left;
//             free( root );
//             return newRoot;
//         }
//         root->data = LeftMostValue( root->right );
//         root->right = Delete( root->right, root->data );
//     }
//     return root;
// }
 
void PreOrder(node_t* root){
    if(root != NULL)
    {
        printf("%d ", root->data);
        PreOrder(root->left);
        PreOrder(root->right);
    }
}
 
void InOrder(node_t* root){
    if(root != NULL)
    {
        InOrder(root->left);
        printf("%d ", root->data);
        InOrder(root->right);
    }
}
 
void PostOrder(node_t* root){
    if(root != NULL)
    {
        PostOrder(root->left);
        PostOrder(root->right);
        printf("%d ", root->data);
    }
}

node_t* InputBTree(node_t *root){
    int n,data,i=0;
    printf("Nhap so luong phan tu: ");
    scanf("%d",&n);
    while(i<n){
        printf("Nhap phan tu thu %d: ",i+1);
        scanf("%d",&data);
        root=Insert( root, data );
        i++;
    }
    return root;
}

int SumBTree(node_t *root){
    if(root!=NULL){
        int a=SumBTree(root->left);
        int b=SumBTree(root->right);
        return root->data + a + b;
    }
    return 0;
}

int SumLeBTree(node_t *root){
    if(root!=NULL){
        int a=SumLeBTree(root->left);
        int b=SumLeBTree(root->right);
        if(root->data % 2 != 0){
            return 1 + a + b;
        }
        return a + b;
        
    }
    return 0;
}


int main()
{
    node_t* root = NULL;
 
    root=InputBTree(root);
    
    printf("\nDuyet preorder : ");
    PreOrder(root);
    printf("\nDuyet inorder  : ");
    InOrder(root);
    printf("\nDuyet postorder:");
    PostOrder(root);

    printf("\nTong cac nut trong cay la: %d.",SumBTree(root));

    printf("\nTong cac nut le trong cay la: %d.",SumLeBTree(root));
    // printf("\nDuyet postorder:");
    // PostOrder(root);
 
    // printf("\n==Thu them phan tu 15 vao BTS==\n");
    // Insert(root, 15);
    // printf("\nDuyet preorder : ");
    // PreOrder(root);
    // printf("\nDuyet inorder  : ");
    // InOrder(root);
    // printf("\nDuyet postorder:");
    // PostOrder(root);
 
 
    // printf("\n==Thu xoa phan tu 50 khoi BTS==\n");
    // Delete(root, 50);
    // printf("\nDuyet preorder : ");
    // PreOrder(root);
    // printf("\nDuyet inorder  : ");
    // InOrder(root);
    // printf("\nDuyet postorder:");
    // PostOrder(root);
 
 
 
 
    Free( root );
    root = NULL;
    return 0;
}