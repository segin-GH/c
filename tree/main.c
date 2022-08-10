# include <stdio.h>
# include <stdlib.h>

typedef struct node
{
    int number;
    struct node* left;
    struct node* right;
}
node;


void print_tree(node* root);
void free_tree(node* root);



int main()
{

    node *tree = NULL;

    node* n = malloc(sizeof(node));
    
    if( n == NULL)
    {   
        printf("no space 1 \n");
        return 1;
    }
    n -> number  = 2;
    n -> left = NULL;
    n -> right = NULL;
    tree = n;


    n = malloc(sizeof(node));
    
    if (n == NULL)
    {
        printf("no space 2\n");
        return 1;
    }
    n -> number = 1;
    n -> left = NULL;
    n -> right = NULL;
    tree -> left = n;


    n = malloc(sizeof(node));
    if (n == NULL)
    {
        printf("no space 3 \n");
        return 1;
    }
    n -> number = 3;
    n -> left = NULL;
    n -> right = NULL;
    tree -> right = n;

    
    print_tree(tree);

    free_tree(tree);
    
     

}

void free_tree(node *root)
{
    if(root == NULL)
    {
        return;
    }
    free_tree(root -> left);
    free_tree(root -> right);
    free(root);

}


void print_tree(node *root)
{
    if (root == NULL)
    {
        return;
    }

    print_tree(root -> left);
    printf("%i\n",root -> number);
    print_tree(root -> right);

}