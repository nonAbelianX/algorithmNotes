# 问题描述：

给定两个数组 **inorder** 和 **postorder** 分别表示某一个二叉树的中序遍历和后续遍历，要求给出该二叉树的先序遍历。

#### 输入

```shell
2 1 4 3 5 # inorder
2 4 5 3 1 # postorder
```

#### 输出

```shell
1 2 3 4 5
```

# 分析

中序遍历顺序是  左 -> 根 -> 右  （**inorder**）

后续遍历顺序是  左 -> 右 -> 根  （**postorder**）

可以采用递归的方式来重建该二叉树。

二叉树节点结构如下：

```cpp
struct btree_node{
    btree_node* left;
    btree_node* right;
    //btree_node* root;
    int value;
}
```



递归函数需要处理的问题如下：

给定 **inorder** 和 **postorder** 将新的节点不断的连接到之前的节点中去。

- 新建一个 **num_nodes** 大小的 **btree_node** 数组，先根据 **inorder** 的值依次给每个 **btree_node** 的 **value** 变量赋值。

- 当 **inorder** 和 **postorder** 的第一个值相同时，证明它是它的父节点的左节点，判断此节点是否是最后一个节点，如果是，结束当前循环，如果不是，则 **inorder** 的下一个值一定是其父节点，设置父节点的左孩子（**left**）的值为当前节点，设置后前进一步循环判断下一个，当不满足第一个节点相等的条件时结束循环保存当前位置，进入下一步分类与递归。

- 当 **inorder** 和 **postorder** 的第一个值不同时，该值一定不是最后一个值，此时在 **postorder** 中寻找当前值的位置，当前值会将 **postorder** 分割为左右两个区域分别递归，其中左边递归前设置 **inorder** 当前值的右孩子为 **postorder** 左侧区域的根，如果分割的右侧区域不为零，则设则 **inorder** 中对应的右侧区域的第一个值的左孩子为当前值。

- 在每一个递归中维护一个最大父节点 **max_root** ，最大父节点用于用于分割时的单一右子树的情况，在递归出口返回该值。

#### 更多测试用例

```shell
# input
5
2 4 5 3 1
5 4 3 2 1
# output
1 2 3 4 5


# input
7
4 2 5 1 3 6 7
4 5 2 7 6 3 1
# output
1 2 4 5 3 6 7
```

## 代码

```cpp
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
```


