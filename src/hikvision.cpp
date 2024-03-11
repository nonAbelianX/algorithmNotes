#include <iostream>

using namespace std;

struct btree_node{
    btree_node* left = nullptr;
    btree_node* right = nullptr;
    //btree_node* root;
    int value;
};

int find_cut_position( int* inorder, int* postorder, int num_nodes ){
    int index = 0;
    for ( ; index < num_nodes; index++ ){
        if ( inorder[0] == postorder[index] ){
            return index;
        }
    }
        cout << "数据非法或存在BUG, 执行 find_cut_position 函数失败。\n";
        return -1;
}

btree_node* btree_constructor( btree_node* btrees, int* inorder, int* postorder, int num_nodes ){ 
    btree_node* max_root = nullptr;
    int i = 0;
    for (; i < num_nodes; i++){
        if (inorder[i] == postorder[i]){
            if (i < num_nodes - 1 ){
                btrees[i+1].left = &btrees[i];
            } else {
                max_root = &btrees[ i ];
            }
        } else {
            //max_root = &btrees[i];
            int cut_position = find_cut_position( &inorder[i], &postorder[i], num_nodes - i) + i;
            btrees[i].right = btree_constructor( &btrees[ i+1 ], &inorder[ i+1 ], &postorder[ i ], cut_position - i );
            if ( cut_position < num_nodes - 1 ){
                btrees[ cut_position + 1 ].left = &btrees[ i ];
                max_root = btree_constructor( &btrees[ cut_position + 1 ], &inorder[ cut_position + 1 ], &postorder[ cut_position + 1 ], num_nodes - cut_position - 1 );
            } else {
                max_root = &btrees[ i ];
            }
            break;
        }
    }
    return max_root; 
}

void firstorder( btree_node* root ){
    printf( "%d\t", root->value );
    if ( root->left != nullptr ){
        firstorder( root->left );
    }
    if ( root->right != nullptr ){
        firstorder( root->right );
    }
}



int main(){
    int num_nodes;
    cin >> num_nodes;
    btree_node btrees[num_nodes];

    int inorder[num_nodes];
    int postorder[num_nodes];
    for (int i = 0; i < num_nodes; i++ ){
        cin >> inorder[i];
        btrees[i].value = inorder[i];
    }
    for (int i = 0; i < num_nodes; i++ ){
        cin >> postorder[i];
        
    }

    btree_node* root;
    root = btree_constructor( btrees, inorder, postorder, num_nodes );
    firstorder( root );

    //cout << inorder[num_nodes - 1] << "\t" << postorder[num_nodes - 1] << "\n";

    return 0;
}