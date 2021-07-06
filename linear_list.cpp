#include <string>
#include <iostream>

struct linear_list
{
    int* array_;
    int  length_;
    int  capacity_;
};

typedef linear_list linear_list_t;

void init_list(linear_list_t* ll)
{
    ll->array_    = new int[10];
    ll->length_   = 0;
    ll->capacity_ = 10;
}

void destroy_list(linear_list_t* ll)
{
}

void clear_list(linear_list_t* ll)
{
}

bool is_list_empty(linear_list_t* ll)
{
    return false;
}

int list_length(linear_list_t* ll)
{
    return 0;
}

int get_elem(linear_list_t* ll, int i)
{
    return 0;
}

int locate_elem(linear_list_t* ll, int n)
{
    return 0;
}

void list_insert(linear_list_t* ll, int i, int n)
{
}

void list_delete(linear_list_t* ll, int i)
{
}

void list_push_back(linear_list_t* ll, int n)
{
    ll->array_[ll->length_] = n;
    ll->length_++;
}

typedef void (*visit)(int n);

void list_traverse(linear_list_t* ll, visit v)
{
}

int main()
{
    linear_list_t mylist;

    init_list(&mylist);

    list_push_back(&mylist, 5);
    list_push_back(&mylist, 3);
    list_push_back(&mylist, 7);

    for (int i = 0; i < mylist.length_; ++i)
    {
        std::cout << mylist.array_[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
