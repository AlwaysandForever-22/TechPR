#include <iostream>
using namespace std;

enum DataType
{
    INT,
    CHAR,
    FLOAT,
    DOUBLE,
    BOOLEAN
};

class Node
{
public:
    DataType d;
    void *item;
    Node *next;
    Node(DataType dt, void *val) : d(dt), item(val), next(nullptr) {}
};

class HetrogenousLinkedList
{
private:
    Node *head;
    Node *tail;
    int numberOfNodes = 0;

    Node *createNode(DataType dt, void *val)
    {
        Node *node = new Node(dt, val);
        return node;
    }

public:
    HetrogenousLinkedList()
    {
        head = nullptr;
        tail = nullptr;
    }

    void add(int a) //For Integers
    {
        int *value = (int *)malloc(sizeof(int));
        *value = a;
        if (head == nullptr)
        {
            head = createNode(INT, value);
            tail = head;
            cout << *(int *)tail->item << endl;
        }
        else
        {
            tail->next = createNode(INT, value);
            tail = tail->next;
        }
        value = nullptr;
        numberOfNodes++;
    }

    void add(char a) //For Characters
    {
        char *value = (char *)malloc(sizeof(char));
        *value = a;
        if (head == nullptr)
        {
            head = createNode(CHAR, value);
            tail = head;
        }
        else
        {
            tail->next = createNode(CHAR, value);
            tail = tail->next;
        }
        value = nullptr;
        numberOfNodes++;
    }

    void add(float a) //For Float
    {
        float *value = (float *)malloc(sizeof(float));
        *value = a;
        if (head == nullptr)
        {
            head = createNode(FLOAT, value);
            tail = head;
        }
        else
        {
            tail->next = createNode(FLOAT, value);
            tail = tail->next;
        }
        value = nullptr;
        numberOfNodes++;
    }

    void add(double a) //For Double
    {
        double *value = (double *)malloc(sizeof(double));
        *value = a;
        if (head == nullptr)
        {
            head = createNode(DOUBLE, value);
            tail = head;
        }
        else
        {
            tail->next = createNode(DOUBLE, value);
            tail = tail->next;
        }
        value = nullptr;
        numberOfNodes++;
    }

    void printList()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            switch (temp->d)
            {
            case INT:
            {
                int *a;
                a = (int *)temp->item;
                cout << *a << " ";
            }
            break;
            case DOUBLE:
            {
                double *b = (double *)temp->item;
                cout << *b << " ";
            }
            break;
            case FLOAT:
            {
                float *c = (float *)temp->item;
                cout << *c << " ";
            }
            break;
            case CHAR:
            {

                cout << *(char *)temp->item << " ";
            }
            break;

            default:
            {
                cout << "not found"
                     << " ";
            }
            }
            temp = temp->next;
        }
    }
};

int main()
{

    HetrogenousLinkedList hll;
    hll.add('B');
    hll.add('G');
    hll.add('I');
    hll.add(22);

    hll.printList();

    return 0;
}
