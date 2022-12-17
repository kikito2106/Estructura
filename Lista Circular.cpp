//GABRIEL ESTRADA 29809541//
#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

int Length(struct Node *head)
{
    struct Node *t;
    int i = 0;
    if (head == NULL)
    {
        return 0;
    }

    t = head -> next;

    do
    {
        t = t -> next;
        i++;
    } while (t != head->next);
    return i;
}

struct Node *Start(struct Node *head, int data)
{
    struct Node *temp = (struct Node *) malloc(sizeof(struct Node));
    if (head == NULL)
        {
    temp -> data = data;
    head = temp;
    head -> next = head;
        }
    else
    {
    temp -> data = data;
    temp -> next = head -> next;
    head -> next = temp;
    head = temp;
    }
    return head;
}

struct Node *End(struct Node *head, int data)
{
    struct Node *temp = (struct Node *) malloc(sizeof(struct Node)), *a = head;
    if (head == NULL)
        {
    temp -> data = data;
    head = temp;
    head -> next = head;
        }
    else
    {
    do
    {
        a = a -> next;
    } while (a -> next != head);
    temp -> data = data;
    temp -> next = a -> next;
    a -> next = temp;
    }
    return head;
}

struct Node *Middle(struct Node *head, int data, int index)
{
    if (head == NULL)
    {
        cout << "La lista esta vacia" << endl;
        return NULL;
    }

    int len = Length(head);
    if (index > len || index < 0)
    {
        cout << "No es posible insertar, error en el input" << endl;
        return head;
    }
    if (index == 0)
    {
        head = Start(head,data);
        return head;
    }
    if (index == len)
    {
        head = End(head,data);
        return head;
    }
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node)), *a = head;
    do
    {
        a = a -> next;
    } while (a -> next != head);
    len = 0;
    while (1)
    {
        if (len == index)
        {
            temp -> data = data;
            temp -> next = a -> next;
            a -> next = temp;
            return head;
        }
        a = a -> next;
        len++;
    }
}

struct Node *First(struct Node* head)
{
    struct Node *prev = head, *first = head;

    if (head == NULL) {
        cout << "La lista esta vacia" << endl;
        return NULL;
    }

    if (prev->next == prev)
    {
        head = NULL;
        return head;
    }

    while (prev->next != head)
    {
        prev = prev->next;
    }

    prev->next = first->next;

    head = prev->next;
    free(first);
    return head;
}

struct Node *Last(struct Node* head)
{
    struct Node *curr = head, *temp = head, *prev;

    if (head == NULL) {
        cout << "La lista esta vacia" << endl;
        return NULL;
    }

    if (curr->next == curr)
    {
        head = NULL;
        return head;
    }

    while (curr->next != head)
    {
        prev = curr;
        curr = curr->next;
    }

    prev->next = curr->next;
    head = prev->next;
    free(curr);
    return head;
}

struct Node *Position(struct Node* head, int index)
{
    int len = Length(head);
    int count = 1;
    struct Node *prev = head, *next = head;

    if (head == NULL) {
        cout << "La lista esta vacia" << endl;
        return NULL;
    }

    if (index > len || index < 0)
    {
        cout << "Borrar es imposible, error en la data" << endl;
        return head;
    }

    if (index == 0)
    {
        First(head);
        return head;
    }

    if (index == len)
    {
        Last(head);
        return head;
    }

    while (len > 0)
    {
        if (index == count)
        {
            prev->next = next->next;
            free(next);
            return head;
        }
        prev = prev->next;
        next = prev->next;
        len--;
        count++;
    }

    return head;
}

void Display(struct Node *head)
{
    struct Node *t;
    if (head == NULL)
    {
        cout << "La lista enlazada esta vacia." << endl;
        return;
    }

    t = head;

    do
    {
        cout << t -> data << " -> ";
        t = t -> next;
    } while (t != head);
    cout<<" "<<endl;
}

int main()
{
    struct Node *head = NULL;
    int n = 0,a = 0;
    char ch;
    while (1)
    {
    cout << " 1. Añadir al principio\n 2. Añadir al final \n 3. Añadir data \n 4. Mostrar lista \n 5. Quitar del principio \n 6. Quitar del final \n 7. Quitar data \n 8. Salir" << endl;
    cin >> ch;
    switch (ch)
    {
        case '1' :  cout << "Ingresar data" << endl;
                    cin >> n;
                    head = Start(head, n);
                    break;
        case '2' :  cout << "Ingresar data" << endl;
                    cin >> n;
                    head = End(head, n);
                    break;
        case '3' :  cout << "Ingresar data" << endl;
                    cin >> n;
                    cout << "Index en el cual ingresar data" << endl;
                    cin >> a;
                    head = Middle(head, n, a);
                    break;
        case '4' :  Display(head);
                    break;
        case '5' :  head = First(head);
                    break;
        case '6' :  head = Last(head);
                    break;
        case '7' :  cout << "Index en el cual ingresar data" << endl;
                    cin >> a;
                    head = Position(head,a);
                    break;
        case '8' : exit(0);
        default : cout << "Error" << endl;
    }
    }
    return 0;
}
