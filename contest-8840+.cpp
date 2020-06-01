#include <iostream>
#include <memory>
#include <functional>
#include <vector>

using namespace std;

typedef struct node
{
    long long i;
    node * next;
    node * befor;
} node;

int main()
{
    long long n, temp;
    int c;
    cin >> n >> c;

    if (n == 1)
    {
        while (c--)
        {
            cin >> temp;
            if (temp == 0)
            {
                cout << 1 << endl;
            }
        }

        return 0;
    }

    node * head, * tail;
    vector<node> node_pointers(n);

    for (long long i = 1; i < n - 1; ++i)
    {
        node_pointers[i].i = i + 1;
        node_pointers[i].next = &node_pointers[i + 1];
        node_pointers[i].befor = &node_pointers[i - 1];
    }

    head = &node_pointers[0];
    head->i = 1;
    head->next = &node_pointers[1];

    tail = &node_pointers[n - 1];
    tail->i = n - 1;
    tail->befor = &node_pointers[n - 2];

    head->befor = tail;
    tail->next = head;

    while (c--)
    {
        cin >> temp;
        if (temp == 0)
        {
            cout << head->i << endl;
            head = head->next;
            tail = tail->next;
        }
        else
        {
            node * iom = &node_pointers[temp - 1];

            if (iom != head)
            {
                if (iom == tail)
                {
                    head = head->befor;
                    tail = tail->befor;
                }
                else
                {
                    iom->befor->next = iom->next;
                    iom->next->befor = iom->befor;

                    iom->next = head;
                    iom->befor = tail;
                    tail->next = iom;
                    head->befor = iom;

                    head = iom;
                }
            }
        }
    }

    return 0;
}
