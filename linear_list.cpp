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
    ll->capacity_ = 10;
    ll->array_    = (int*)malloc(sizeof(int) * ll->capacity_);
    ll->length_   = 0;
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
    if (ll->length_ > ll->capacity_)
    {
        ll->capacity_ = ll->capacity_ * 2;
        int* tmp      = (int*)malloc(sizeof(int) * ll->capacity_);
        memcpy(tmp, ll->array_, sizeof(int) * ll->length_);
        free(ll->array_);
        ll->array_ = tmp;
    }

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

    for (int i = 0; i < 1000000; ++i)
    {
        list_push_back(&mylist, i);
    }
    for (int i = 0; i < mylist.length_; ++i)
    {
        std::cout << mylist.array_[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
