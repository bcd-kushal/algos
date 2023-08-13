#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data, height;
    struct node *left;
    struct node *right;
} BST;

BST *root = NULL;
int new_data_inserted;

int max(int a, int b){
    return (a>b)?a:b; 
}

int height(BST *ptr)
{
    if (!ptr)
        return 0;
    return ptr->height;
}

//--------------------------------
int height_node(BST *ptr)
{
    if (!ptr)
        return 0;
    ptr->height = 1 + max(height(ptr->left), height(ptr->right));
    return ptr->height;
}
//--------------------------------

BST *inorder(BST *ptr)
{
    if (!ptr)
    {
        printf(" ---- Empty Binary Search Tree ---- ");
        return NULL;
    }
    if (ptr->left)
        ptr->left = inorder(ptr->left);
    printf(" %d ", ptr->data);
    if (ptr->right)
        ptr->right = inorder(ptr->right);
    return ptr;
}

int getBalanceFactor(BST *ptr)
{
    return height(ptr->left) - height(ptr->right);
}

/* =====================[ ROTATIONS ]===================== */
// A=node; B=r_child / l_child; C=r_child->left etc..

BST *RR_rotation(BST *parent, BST *node, BST *right_child)
{
    printf("\n\t\t\t| Executing RR rotation..");
    if (!parent)
    {
        root = right_child;
    }
    else
    {
        if (parent->left == node)
            parent->left = right_child;
        else
            parent->right = right_child;
    }

    BST *temp = right_child->left;
    right_child->left = node;
    node->right = temp;
    node->height = 1 + max(height(node->left), height(node->right));
    right_child->height = 1 + max(height(right_child->left), height(right_child->right));

    if (!parent)
        return root;
    return parent;
}

BST *LL_rotation(BST *parent, BST *node, BST *left_child)
{
    printf("\n\t\t\t| Executing LL rotation..");

    if (!parent)
    {
        root = left_child;
    }
    else
    {
        if (parent->left == node)
            parent->left = left_child;
        else
            parent->right = left_child;
    }

    BST *temp = left_child->right;
    left_child->right = node;
    node->left = temp;

    node->height = 1 + max(height(node->left), height(node->right));
    left_child->height = 1 + max(height(left_child->left), height(left_child->right));

    if (!parent)
        return root;
    return parent;
}

BST *RL_rotation(BST *parent, BST *node, BST *right_tree)
{
    printf("\n\t\t\t| Executing RL rotation..");
    BST *sub_tree = right_tree->left;

    if (!parent)
    {
        root = sub_tree;
    }
    else
    {
        if (parent->left == node)
            parent->left = sub_tree;
        else
            parent->right = sub_tree;
    }

    node->right = sub_tree->left;
    sub_tree->left = node;
    right_tree->left = sub_tree->right;
    sub_tree->right = right_tree;

    node->height = 1 + max(height(node->left), height(node->right));
    right_tree->height = 1 + max(height(right_tree->left), height(right_tree->right));
    sub_tree->height = 1 + max(height(sub_tree->left), height(sub_tree->right));

    if (!parent)
        return root;
    return parent;
}

BST *LR_rotation(BST *parent, BST *node, BST *left_tree)
{
    printf("\n\t\t\t| Executing LR rotation..");
    BST *sub_tree = left_tree->right;

    if (!parent)
    {
        root = sub_tree;
    }
    else
    {
        if (parent->left == node)
            parent->left = sub_tree;
        else
            parent->right = sub_tree;
    }

    node->left = sub_tree->right;
    sub_tree->right = node;
    left_tree->right = sub_tree->left;
    sub_tree->left = left_tree;

    node->height = 1 + max(height(node->left), height(node->right));
    left_tree->height = 1 + max(height(left_tree->left), height(left_tree->right));
    sub_tree->height = 1 + max(height(sub_tree->left), height(sub_tree->right));

    if (!parent)
        return root;
    return parent;
}

/* =====================[ INSERTION ]===================== */
BST *constructNode(int x)
{
    BST *temp = (BST *)malloc(sizeof(BST));
    temp->data = x;
    temp->height = 1;
    temp->left = temp->right = NULL;
    return temp;
}

/* void insertNode()
{
    int x;
    printf("\t| Enter data to insert : ");
    scanf("%d", &x);
    if (!root)
    {
        root = constructNode(x);
        printf("\t| Data inserted.");
        return;
    }
    BST *ptr = root;
    while (1)
    {
        if (x < ptr->data)
        {
            if (ptr->left)
                ptr = ptr->left;
            else
            {
                ptr->left = constructNode(x);
                printf("\t| Data entered.");
                break;
            }
        }
        else
        {
            if (ptr->right)
                ptr = ptr->right;
            else
            {
                ptr->right = constructNode(x);
                printf("\t| Data entered.");
                break;
            }
        }
    }
} */

BST *insertNodeR(BST *ptr, int x)
{
    if (!ptr)
    {
        ptr = constructNode(x);
        printf(" [ data inserted here ] }");
        return ptr;
    }

    printf("%d , ", ptr->data);

    if (x < ptr->data)
        ptr->left = insertNodeR(ptr->left, x);
    else
        ptr->right = insertNodeR(ptr->right, x);

    ptr->height = 1 + max(height(ptr->left), height(ptr->right));
    return ptr;
}


BST *preorder(BST *ptr){
    if(!ptr){
        printf(" ---- Empty Binary Search Tree ---- ");
        return NULL;
    }
    printf(" %d ",ptr->data);
    if(ptr->left)
        ptr->left = preorder(ptr->left);
    if(ptr->right)
        ptr->right = preorder(ptr->right);
    return ptr;
}



/* =====================[ AVL BALANCING ]===================== */
BST *postorder_balancing(BST *ptr, int *exit_state)
{
    static BST *node_child, *node_ptr;
    static int node_factor_tracker = 0, child_factor_tracker = 0, parent_to_unbalanced = 0, flag = 0;

    if (!ptr)
    {
        printf(" ---- Empty Binary Search Tree ---- ");
        return NULL;
    }

    if (ptr->left)
        ptr->left = postorder_balancing(ptr->left, exit_state);
    if (ptr->right)
        ptr->right = postorder_balancing(ptr->right, exit_state);
    ptr->height = 1 + max(height(ptr->left), height(ptr->right));

    if (*exit_state == 0)
    {
        if((ptr->left && ptr->left->data==new_data_inserted) || (ptr->right && ptr->right->data==new_data_inserted) || ptr->data==new_data_inserted)
            new_data_inserted = ptr->data;

        int bal_factor = getBalanceFactor(ptr);

        if (parent_to_unbalanced == 1 && ((ptr->left && ptr->left->data == node_ptr->data) || (ptr->right && ptr->right->data == node_ptr->data)))
            parent_to_unbalanced = 2;

        if (bal_factor >= -1 && bal_factor <= 1 && node_factor_tracker == 0 && ptr->data==new_data_inserted)
        {
            child_factor_tracker = bal_factor;
            node_child = ptr;
            printf("\n\t\t| Balance Factor of %d\t = %d", node_child->data, bal_factor);
        }

        if ((bal_factor == 2 || bal_factor == -2) && flag == 0)
        {
            node_factor_tracker = bal_factor;
            node_ptr = ptr;
            printf("\n\t\t| Balance Factor of %d\t = %d", node_ptr->data, bal_factor);
            parent_to_unbalanced = (ptr == root) ? -1 : 1;
            /* printf("\nparent_to_unbalanced = %d", parent_to_unbalanced); */
            flag = 1;
        }

        if (node_factor_tracker != 0 && (parent_to_unbalanced == -1 || parent_to_unbalanced == 2))
        {
            // avl rotations here
            if (parent_to_unbalanced == -1)
            {
                if (node_factor_tracker < 0 && child_factor_tracker < 0)
                    root = RR_rotation(NULL, node_ptr, node_child);
                else if (node_factor_tracker > 0 && child_factor_tracker > 0)
                    root = LL_rotation(NULL, node_ptr, node_child);
                else if (node_factor_tracker < 0 && child_factor_tracker > 0)
                    root = RL_rotation(NULL, node_ptr, node_child);
                else if (node_factor_tracker > 0 && child_factor_tracker < 0)
                    root = LR_rotation(NULL, node_ptr, node_child);
                parent_to_unbalanced = 0;
                node_factor_tracker = 0;
                child_factor_tracker = 0;
                *exit_state = 1;
                flag = 0;
                root->height = 1 + max(height(root->left), height(root->right));
                return root;
            }
            else
            {
                if (node_factor_tracker < 0 && child_factor_tracker < 0)
                    ptr = RR_rotation(ptr, node_ptr, node_child);
                else if (node_factor_tracker > 0 && child_factor_tracker > 0)
                    ptr = LL_rotation(ptr, node_ptr, node_child);
                else if (node_factor_tracker < 0 && child_factor_tracker > 0)
                    ptr = RL_rotation(ptr, node_ptr, node_child);
                else if (node_factor_tracker > 0 && child_factor_tracker < 0)
                    ptr = LR_rotation(ptr, node_ptr, node_child);
                parent_to_unbalanced = 0;
                node_factor_tracker = 0;
                child_factor_tracker = 0;
                *exit_state = 1;
                flag = 0;
                ptr->height = 1 + max(height(ptr->left), height(ptr->right));
                return ptr;
            }
        }

        if (ptr == root)
        {
            parent_to_unbalanced = 0;
            node_factor_tracker = 0;
            child_factor_tracker = 0;
            flag = 0;
        }
    }
    return ptr;
}

BST *rightInorderSuccessor(BST *ptr)
{
    while (ptr->left)
        ptr = ptr->left;
    return ptr;
}

/* =====================[ DELETION ]===================== */
BST *deleteNodeR(BST *ptr, int x)
{
    if (!ptr)
    {
        printf("\t| Tree does not contain %d", x);
        return ptr;
    }

    if (x < ptr->data)
    {
        if (!ptr->left)
        {
            printf("\t| Tree does not contain %d, nothing to delete.", x);
            return ptr;
        }
        ptr->left = deleteNodeR(ptr->left, x);
    }
    else if (x > ptr->data)
    {
        if (!ptr->right)
        {
            printf("\t| Tree does not contain %d, nothing to delete.", x);
            return ptr;
        }
        ptr->right = deleteNodeR(ptr->right, x);
    }
    else
    {
        BST *tempVar;
        // case 1 and 2
        if (!ptr->left)
        {
            tempVar = ptr->right;
            printf("\t| Data deleted successfully.");
            free(ptr);
            return tempVar;
        }
        else if (!ptr->right)
        {
            tempVar = ptr->left;
            printf("\t| Data deleted successfully.");
            free(ptr);
            return tempVar;
        }

        // case 3
        tempVar = rightInorderSuccessor(ptr->right);
        ptr->data = tempVar->data;
        root->right = deleteNodeR(ptr->right, tempVar->data);
    }
    return ptr;
}

BST *findNodeToDelete(BST *ptr, int x, int *direction)
{ // case_1()
    if (!ptr)
        return NULL;
    BST *temp;

    while (ptr)
    {
        if (x < ptr->data)
        {
            temp = ptr->left;
            if (!temp)
            {
                *direction = -1;
                printf("\t| Tree does not contain %d, nothing to delete. %d", x, ptr->data);
                return NULL;
            }
            if (temp->data == x)
            {
                *direction = 0; // 0 = left; 1 = right; -1 = node to delete doesnt exist
                return ptr;
            }
            ptr = temp;
        }
        if (x >= ptr->data)
        {
            temp = ptr->right;
            if (!temp)
            {
                *direction = -1;
                printf("\t| Tree does not contains %d, nothing to delete.", x);
                return NULL;
            }
            if (temp->data == x)
            {
                *direction = 1; // 0 = left; 1 = right
                return ptr;
            }
            ptr = temp;
        }
    }
}

BST *findInorderSuccessor(int *direction, BST *ptr)
{ // case_2()
    BST *temp = ptr->right;

    // when right subtree has only one left node
    if (!temp->left)
    {
        *direction = 1;
        return ptr;
    }

    ptr = temp;
    temp = ptr->left;

    while (temp->left)
    {
        ptr = ptr->left;
        temp = temp->left;
    }

    *direction = 0;
    return ptr;
}

void deleteNode(BST *ptr, int x)
{
    if (!ptr)
    {
        printf("\nEmpty tree.");
        return;
    }

    int dirn = -1;
    BST *parent = findNodeToDelete(ptr, x, &dirn);

    if (parent == NULL)
        return;

    BST *child;
    child = (dirn == 0) ? parent->left : parent->right;

    // if node to delete has no children
    if (!child->left && !child->right)
    {
        if (dirn == 0)
            parent->left = NULL;
        else
            parent->right = NULL;
        printf("\t| Data deleted successfully.");
        return;
    }

    // if node to delete has one child only
    if (!child->left && child->right)
    {
        if (dirn == 0)
            parent->left = child->right;
        else
            parent->right = child->right;
        printf("\t| Data deleted successfully.");
        return;
    }
    else if (child->left && !child->right)
    {
        if (dirn == 0)
            parent->left = child->left;
        else
            parent->right = child->left;
        printf("\t| Data deleted successfully.");
        return;
    }

    // if node to delete has both left and right subtrees       <- case_3()
    int inorderSuccessorDirn = -1;
    BST *var = findInorderSuccessor(&inorderSuccessorDirn, child);

    if (inorderSuccessorDirn == 1)
    {
        var = var->right;
        child->data = var->data;
        child->right = NULL;
        printf("\t| Data deleted successfully.");
        return;
    }
    else
    {
        BST *localTemp = var->left;
        child->data = localTemp->data;
        deleteNode(var, localTemp->data);
        printf("\t| Data deleted successfully.");
        return;
    }
}

BST *preorder_makeMirror(BST *ptr,BST **new_ptr){
    if(!ptr){
        printf(" ---- Empty Binary Search Tree ---- ");
        return NULL;
    }
    //preorder iterative approach
    *new_ptr = constructNode(ptr->data);
    if(ptr->left)
        ptr->left = preorder_makeMirror(ptr->left,&((*new_ptr)->right));
    if(ptr->right)
        ptr->right = preorder_makeMirror(ptr->right,&((*new_ptr)->left));
    return ptr;
}

void makeMirrorOfAVL(){
    BST *mirror_ptr;
    root = preorder_makeMirror(root,&mirror_ptr);
    printf("\t| Inorder traversal of mirror tree : [");
    mirror_ptr = inorder(mirror_ptr);
    printf("]");
    printf("\t| Preorder traversal of mirror tree : [");
    mirror_ptr = preorder(mirror_ptr);
    printf("]");
}

//--------------------------------------------------------------------

int showOptions()
{
    int x;
    printf("\n-----------------------------------------");
    printf("\n1.Insert a node\t\t2.Inorder traversal\t\t3.Preorder traversal\n4.Delete a node\t\t5.Create Mirror\t\t6.Exit\t| Input : ");
    scanf("%d", &x);
    return x;
}

int main()
{
    int choice = 0, val, m = 0;
    int x;
    while (1)
    {
        choice = showOptions();
        if (choice == 6)
            break;
        switch (choice)
        {
        case 1:
            /* insertNode(); */

            printf("\t| Enter data to insert : ");
            scanf("%d", &x);
            printf("\t| Path = { ");
            root = insertNodeR(root, x);
            new_data_inserted = x;
            root = postorder_balancing(root, &m);
            m = 0;
            break;
        case 2:
            printf("\t| Root = %d\n\t| Inorder traversal : [",root->data);
            root = inorder(root);
            printf("]");
            break;
        case 3:
            printf("\t| Root = %d\n\t| Preorder traversal : [",root->data);
            root = preorder(root);
            printf("]");
            break;
        case 4:
            printf("\t| Enter data to delete : ");
            scanf("%d", &x);
            deleteNode(root, x);
            root = postorder_balancing(root, &m);
            m = 0;
            break;
        case 5:
            makeMirrorOfAVL();
            break;
        default:
            printf("\t| Wrong input choice.");
        }
    }
    printf("\t| Exited.");

    return 0;
}