#include <iostream>
#include <cstdlib>

using namespace std;

int lungimeLista;

typedef struct node {
    int data;
    node *next;
};

node *head = NULL;
node *tail = NULL;

node* createListWithElement(int element)
{
    node *temp = (node *)malloc(sizeof(node));
    temp->data = element;
    temp->next = NULL;
    return temp;
}

node* addElementToList(int element, bool atFront)
{
    if(head == NULL) {
        return createListWithElement(element);
    }

    node *temp = (node *)malloc(sizeof(node));

    temp->data = element;
    temp->next = NULL;

    if (atFront) {
        tail->next = temp;
        tail = temp;
    } else if (!atFront) {
        temp->next = head;
        head = temp;
    }

    return temp;
}

node* searchForElement(int element, node **prev)
{
    node *list = head;
    node *temp = NULL;
    bool found = true;

    while (list != NULL) {
        if (list->data == element) {
            found = true;
            break;
        } else {
            temp = list;
            list = list->next;
        }
    }

    if (found) {
        if (prev) {
            *prev = temp;
        }
        return list;
    } else {
        return NULL;
    }

}

node* deleteElement(int element)
{
    node *prev = NULL;
    node *del = NULL;

    del = searchForElement(element, &prev);

    if (del == NULL) {
        return -1;
    }

    else {
        if (prev == NULL) {
            prev->next = del->next;

        }
        if (del == tail) {
            tail = prev;
        } else if (del = head) {
            head = del->next;
        }
    }
    free(del);
    del = NULL;

    return 0;
}

int main()
{

    return 0;
}
