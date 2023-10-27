#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct TreeNode {
    int inf;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* createNode(int inf) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->inf = inf;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct TreeNode* insertNode(struct TreeNode* root, int inf) {
    if (root == NULL) {
        return createNode(inf);
    }

    if (inf < root->inf) {
        root->left = insertNode(root->left, inf);
    } else if (inf > root->inf) {
        root->right = insertNode(root->right, inf);
    } else {
        printf("Value %d already exists in the binary tree. Duplicate values are not allowed.\n", inf);
    }

    return root;
}

void in_order(struct TreeNode* root) {
    if (root != NULL) {
        in_order(root->left);
        printf("%d ", root->inf);
        in_order(root->right);
    }
}
void pre_order(struct TreeNode* root) {
    if (root != NULL) {
        printf("%d ", root->inf);
        pre_order(root->left);
        pre_order(root->right);
    }
}

void post_order(struct TreeNode* root) {
    if (root != NULL) {
        post_order(root->left);
        post_order(root->right);
        printf("%d ", root->inf);
    }
}
//calculate the number of element
int calculate(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    return calculate(root->left) + calculate(root->right) + 1;
}
// check if element is leaf
bool is_leaf(struct TreeNode* root, int target) {
    if (root == NULL) {
        return false;
    }

    if (root->left == NULL && root->right == NULL) {
        return root->inf == target;
    }

    bool foundLeft = is_leaf(root->left, target);
    bool foundRight = is_leaf(root->right, target);

    return foundLeft || foundRight;
}
void print_leaf(struct TreeNode* root){
    if (root != NULL) {
        if (root->left == NULL && root->right == NULL  )
        {
            printf("%d ",root->inf);
        }
        print_leaf(root->left);
        print_leaf(root->right);
    }
}
int hauteur(struct TreeNode* root){
    if (root == NULL) return -1 ;
    int hauteur_left = hauteur(root->left) ;
    int hauteur_right = hauteur(root->right) ;
    int height = ( hauteur_left > hauteur_right) ? hauteur_left : hauteur_right;
    return height + 1 ;
}
int main() {
    struct TreeNode* root = NULL;

    int value,val;
    char choice;

    printf("Binary Tree - User Interface\n");
        printf("\n");
        printf("1. Add a value\n");
        printf("2. Print in-order traversal\n");
        printf("3. Print pre-order traversal\n");
        printf("4. Print post-order traversal\n");
        printf("5. Print the number of element in tree\n");
        printf("6. Check if element is leaf\n");
        printf("7. Height of the tree\n");
        printf("8. Exit\n");
        
    do {
        printf("Enter your choice: ");
        scanf(" %c", &choice);
        switch (choice) {
            case '1':
                printf("Enter a value to add to the binary tree: ");
                scanf("%d", &value);
                root = insertNode(root, value);
                break;
            case '2':
                printf("In-order Traversal: ");
                in_order(root);
                printf("\n");
                break;
            case '3':
                printf("pre-order Traversal: ");
                pre_order(root);
                printf("\n");
                break;
            case '4':
                printf("post-order Traversal: ");
                post_order(root);
                printf("\n");
                break;
            case '5':
                printf("the number of element is :%d \n",calculate(root));
                break;
            case '6':
            printf("enter the value to check if is a leaf:");
            scanf("%d",&val);
                if (is_leaf(root,val) == true)
                {
                    printf("Your element is leaf \n");
                }else {
                    printf("Your element is not leaf \n");
                }
                break;
            case '7':
                printf("Height of the tree: %d \n", hauteur(root));
                break;
            case '8':
                printf("Exiting the program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != '8');

    return 0;
}
