#include <iostream>
using namespace std;

template<typename T>
struct Node
{
    T value;
    Node<T>* next;
    Node<T>* prev;
};
template<typename T>
class Tree
{
    Node<T>* head;
    Node<T>** tmp;
    int size;
    
public:
    Tree()
    {
        this->head = NULL;
        this->size = 0;
    }
    Node<T>* getHead()
    {
        return this->head;
    }
    void Add(T value,Node<T>* tmp)
    {
        if (tmp == NULL)
        {
            tmp = new Node<T>;
            tmp->value = value;
            tmp->next = tmp->prev = NULL;
            return;
        }
        if (value > tmp->value)
        {
            Add(value, tmp->next);
        }
        else
        {
            Add(value, tmp->prev);
        }
    }
    void Show(Node<T>* iter, int n)
    {
        if (iter == NULL)
        {
            return;
        }
        else
        {
            Show(iter->prev, ++n);
            for (int i = 0; i < n; i++)
            {
                cout << "\t";
            }
            cout << iter->value << "\n\n";
            n--;
            Show(iter->next, ++n);
        }
    }
};

int main()
{
    Tree<int> list;
    list.Add(1, list.getHead());
    list.Add(11, list.getHead());
    list.Add(22, list.getHead());
    list.Add(15, list.getHead());
    list.Show(list.getHead(), 0);

}


