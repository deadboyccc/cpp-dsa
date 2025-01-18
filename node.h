
#pragma once
#include <vector>
class node
{
public:
    int data;
    node *next;
    node *first;
    node(int d) : data(d), next(nullptr), first(this) {}
    node *create_linked(std::vector<int> a)
    {
        node *head = nullptr;
        node *last = nullptr;
        for (auto item : a)
        {
            node *new_node = new node(item);
            if (head == nullptr)
            {
                head = new_node;
                last = new_node;
            }
            else
            {
                last->next = new_node;
                last = new_node;
            }
        }
        return head;
    }
    node *create_linked(int a[], int n)
    {
        node *head = nullptr;
        node *last = nullptr;
        for (int i = 0; i < n; i++)
        {
            node *new_node = new node(a[i]);
            if (head == nullptr)
            {
                head = new_node;
                last = new_node;
            }
            else
            {
                last->next = new_node;
                last = new_node;
            }
        }
        return head;
    }
    void display()
    {
        node *head = first;
        std::cout << "[The BEGINNING]";
        while (head != nullptr)
        {
            std::cout << head->data << "-> ";
            head = head->next;
            if (head == nullptr)
            {
                std::cout << "[THE END]" << std::endl;
            }
        }
    }
    void recursive_display(node *p)
    //? by swapping print with the recursive call, you print the linked list backwards
    //? at returning time
    {
        if (p != nullptr)
        {
            recursive_display(p->next);
            std::cout << p->data << "-> ";
        }
    }
    void count()
    {
        node *p = this;
        unsigned int count = 0;
        while (p)
        {
            count++;
            p = p->next;
        }
        std::cout << count << std::endl;
    }
    int rcount(node *ptr)
    {
        if (ptr == nullptr)
            return 0;
        else
        {
            return 1 + rcount(ptr->next);
        }
    }
    void sum()
    {
        node *head = this;
        int sum = 0;
        while (head)
        {
            sum += head->data;
            head = head->next;
        }
        std::cout << "sum= " << sum;
    }
    int rsum(node *ptr)
    {
        if (ptr == nullptr)
            return 0;
        else
        {
            return ptr->data + rsum(ptr->next);
        }
    }
    void max()
    {
        int max = INT_MIN;
        node *ptr = this;
        while (ptr)
        {
            if (ptr->data > max)
                max = ptr->data;
            ptr = ptr->next;
        }
        std::cout << "max=" << max << std::endl;
    }
    void lsearch(int key)
    {
        // [][] -> [][] -> [][]
        node *ptr = this;
        node *prev = this;
        while (ptr)
        {
            if (ptr->data == key)
            {
                // move the element to the beginning
                prev->next = ptr->next;
                ptr->next = this;
                first = ptr;

                std::cout << "found" << std::endl;
                break;
            }
            prev = ptr;
            ptr = ptr->next;
        }
    }

    void append(int a)
    {
        node *head = this;
        while (head)
        {
            head = head->next;
            if (head->next == nullptr)
            {
                head->next = new node(a);
                break;
            }
        }
    }
    void insert_sorted(int x)
    {
        node *ptr = this;
        node *prev = nullptr;
        while (ptr && ptr->data < x)
        {
            prev = ptr;
            ptr = ptr->next;
        }
        node *new_node = new node(x);
        new_node->next = ptr;
        if (prev == nullptr)
            first = new_node;
        else
            prev->next = new_node;
    }
    void add_at_the_beginning(int a)
    {
        node *new_node = new node(a);
        new_node->next = this;
        first = new_node;
    }
    // create a function to move an existing node in the linked list to the beginning
    void delete_node(int index)
    {
        if (index == 1)
        {
            node *head = this;
            if (head == nullptr)
                return;
            first = first->next;
            std::cout << "1";
            delete head;
        }
        else
        {
            node *p = this;
            std::cout << "not one";
            node *q = nullptr;
            for (int i = 0; i < index - 1 && p != nullptr; i++)
            {
                q = p;
                p = p->next;
            }
            if (p == nullptr)
            {
                std::cout << "Invalid index" << std::endl;
                return;
            }
            else
            {
                q->next = p->next;
                delete p;
            }
        }
    }
    void insert(int index, int value)
    {
        node *new_node = new node(value);
        node *ptr = this;
        if (index == 0)
        {
            new_node->next = ptr;
            first = new_node;
            return;
        }
        for (int i = 0; i < index - 1 && ptr != nullptr; i++)
        {
            ptr = ptr->next;
        }
        if (ptr == nullptr)
        {
            std::cout << "Invalid index" << std::endl;
            delete new_node;
            return;
        }
        new_node->next = ptr->next;
        ptr->next = new_node;
    }
    void isOrdered()
    {
        int is = -1;
        node *p = this;
        while (p && p->next)
        {
            if (p->next->data > p->data)
            {
                p = p->next;
            }
            else
            {
                is = 0;
                break;
            }
        }
        std::cout << (is ? "ordered" : "not ordered");
    }
    void removeDuplicates()
    {
        //[1][1][2]
        node *ptr = this;
        while (ptr && ptr->next)
        {
            if (ptr->data == ptr->next->data)
            {
                node *temp = ptr->next;
                ptr->next = ptr->next->next;
                delete temp;
            }
            else
            {
                ptr = ptr->next;
            }
        }
    }
    void reverseLinked()
    {
        node *p = this;
        node *n;
        int i = 0;
        int a[5];
        int b[5];
        while (p)
        {
            a[i] = p->data;
            i++;
            p = p->next;
        }
        for (int i = 0; i < 5; i++)
        {
            b[i] = a[4 - i];
            std::cout << b[i] << std::endl;
        }
        for (int i = 0; i < 5; i++)
        {
            std::cout << b[i] << " ";
        }
        n = n->create_linked(b, 5);
        n->display();
    }
    void concat(node *ptr2)
    {
        node *final;
        node *ptr1 = this;
        int b[10];
        int i = 0;
        while (ptr1)
        {
            b[i] = ptr1->data;
            i++;
            ptr1 = ptr1->next;
        }
        while (ptr2)
        {
            b[i] = ptr2->data;
            i++;
            ptr2 = ptr2->next;
        }
        final = final->create_linked(b, 10);
        final->display();
    }
    void reverseElements(int a, int b)
    {
        node *p = this;
        int element1;
        node *addr1 = nullptr;
        node *addr2 = nullptr;
        while (p)
        {
            if (p->data == a)
            {
                addr1 = p;
                element1 = p->data;
            }
            else if (p->data == b)
            {
                addr2 = p;
            }

            p = p->next;
        }
        addr1->data = addr2->data;
        addr2->data = element1;
    }
    node *mergelinked(node *p2)
    {
        node *p1 = this;
        node *third, *last;
        if (p1->data < p2->data)
        {
            third = last = p1;
            p1 = p1->next;
            third->next = nullptr;
        }
        else
        {
            third = last = p2;
            p2 = p2->next;
            third->next = nullptr;
        }
        while (p1 && p2)
        {
            if (p1->data < p2->data)
            {
                last->next = p1;
                last = p1;
                p1 = p1->next;
                last->next = nullptr;
            }
            else
            {

                last->next = p2;
                last = p2;
                p2 = p2->next;
                last->next = nullptr;
            }
        }
        if (p1)
        {
            last->next = p1;
        }
        else
        {
            last->next = p2;
        }
        return third;
    }
    void isLoop()
    {
        node *p, *q = this;
        do
        {
            p = p->next;
            q = q->next;
            q = q ? q->next : q;
        } while (p && q && p != q);
        if (q == p)
        {
            std::cout << "loop";
        }
        else
        {
            std::cout << "NO loop";
        }
    }
};