
# include <stdio.h>
# include <stdlib.h>

// for define a node
typedef struct node
{
    int number;
    struct node *next;
}
node; // calling it "node" rather than "struct node"

// for defining fuctions bcz compiler is dumb;

void add_new_node_between(node *prevNode, node *newnode, int number);
/*
this function adds a node in between 

*/

node* add_new_node_beginning(node *newNode,int number ,node *prevNode);
void add_new_node_end(node *prevNode, node *newnode, int number);
void printLinkedList(node *nodehead);
void display_total_memory_used_by_list(node *headNode);


void clean_memory(node *nodeHead);


int main(void)
{

    // manually making nodes
    node *nodeZero = malloc(sizeof(node));
    node *nodeOne = malloc(sizeof(node));
    node *nodeTwo = malloc(sizeof(node));
    node *nodeThree = malloc(sizeof(node));

    nodeZero->number = 90;
    nodeZero->next = nodeOne;

    nodeOne->number = 20;
    nodeOne->next = nodeTwo;

    nodeTwo->number = 80;
    nodeTwo->next = nodeThree;

    nodeThree->number = 60;
    nodeThree->next = NULL;

    printf("manually enterd list : \n");
    printLinkedList(nodeZero);
    printf("\n");


// adding a new node in between
    printf("adding a node in between : \n");
    node *nodeFour;
    add_new_node_between(nodeZero,nodeFour,10);
    printLinkedList(nodeZero);
    printf("\n");


// adding a new node in the beginning
    printf("adding a node at beginning : \n");
    node *nodenew;
    nodenew = add_new_node_beginning(nodenew,20,nodeZero);
    printLinkedList(nodenew);
    printf("\n");


// adding a new node in the end
    printf("adding a node at end : \n");
    node *nodeFive;
    add_new_node_end(nodeTwo,nodeFive,11);
    printLinkedList(nodeZero);
    printf("\n");
   
    display_total_memory_used_by_list(nodeZero);
   
    // delSubseqNode(nodeZero,10);


// to free all the used up memory by malloc;
    while(nodenew != NULL)
    {
        node *temp = nodenew -> next;
        free(nodenew);
        nodenew = temp;
    }

}

void add_new_node_between(node *prevNode, node *newNode, int number)
{

    newNode = malloc(sizeof(node));
    newNode->number = number;
    newNode->next = prevNode->next;          
    prevNode->next = newNode;
}

node* add_new_node_beginning(node *newNode,int number ,node *nodeHead)
{
    newNode = malloc(sizeof(node));
    newNode->number = number;
    newNode->next = nodeHead;
    return newNode;

}

void add_new_node_end(node *prevNode, node *newnode, int number)
{
    newnode = malloc(sizeof(node));
    newnode->number = number;

    node *temp = prevNode;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    prevNode = temp;
    prevNode->next = newnode;
    newnode->next = NULL;

    
    
}

void printLinkedList(node *nodehead)    //Enter the head node of the linked list;
{

    while(nodehead != NULL)
    {
        printf("%d\t",nodehead->number);
        nodehead = nodehead->next;
    }
}

void printInvertedlinkList(node *headNode)
{
    
    node *prev = NULL;
    node *curr = headNode;
    node *nxt = NULL;

    while(curr != NULL)
    {
        nxt = curr->next;
        curr ->next = prev;
        prev = curr;
        curr = nxt;
    }
    headNode = prev;
}

void display_total_memory_used_by_list(node *headNode)
{
    int totalMemory = 0;
    for (node *temp = headNode;  temp != NULL; temp = temp->next)
    {   
        totalMemory = totalMemory + sizeof(temp);
    }
    printf("Total memory used,%i bytes\n",totalMemory);
}



    // for (node *temp = headNode;  temp != NULL; temp = temp->next)
    // {   
        
    // }
