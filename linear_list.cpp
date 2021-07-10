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
    free(ll->array_);
    ll->array_  = NULL;
    ll->length_ = 0;
}

void clear_list(linear_list_t* ll)
{
    ll->length_ = 0;
}

bool is_list_empty(linear_list_t* ll)
{
    if (ll->length_ != 0)
        return false;
    else
        return true;
}

int list_length(linear_list_t* ll)
{
    return ll->length_;
}

int get_elem(linear_list_t* ll, int i)
{
    return ll->array_[i];
}

/*
 * return the index which equals the number
 * otherwise return -1
 */
int locate_elem(linear_list_t* ll, int n)
{
    for (int i = 0; i < ll->length_; i++)
    {
        if (ll->array_[i] == n)
        {
            return i;
        }
    }

    return -1;
}

/**
 * @brief Insert an item into the list
 *
 * @param ll the list
 * @param i the index of which to insert
 * @param n the item to insert
 */
void list_insert(linear_list_t* ll, int i, int n)
{
    if (ll->length_ == ll->capacity_)
    {
        ll->capacity_ = ll->capacity_ + 1;
        int* tmp      = (int*)malloc(sizeof(int) * ll->capacity_);
        memcpy(tmp, ll->array_, sizeof(int) * ll->length_);
        free(ll->array_);
        ll->array_ = tmp;
    }

    for (int x = ll->length_; x > i; x--)
    {
        ll->array_[x] = ll->array_[x - 1];
    }
    ll->array_[i] = n;
    ll->length_++;
}

void list_delete(linear_list_t* ll, int i)
{
}

void list_push_back(linear_list_t* ll, int n)
{
    assert(ll->array_ != NULL);

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

    assert(is_list_empty(&mylist));

    for (int i = 0; i < 100; ++i)
    {
        list_push_back(&mylist, i + 1);
    }
    assert(!is_list_empty(&mylist));
    std::cout << list_length(&mylist) << std::endl; // should be 100
    assert(list_length(&mylist) == 100);

    assert(get_elem(&mylist, 77) == 78);

    assert(locate_elem(&mylist, 56) == 55);

    // for (int i = 0; i < mylist.length_; ++i)
    // {
    //     std::cout << mylist.array_[i] << " ";
    // }
    // std::cout << std::endl;

    // Make the list as a new one.
    clear_list(&mylist);
    assert(list_length(&mylist) == 0);
    for (int i = 0; i < 5; ++i)
    {
        list_push_back(&mylist, i + 2);
    }
    assert(list_length(&mylist) == 5);

    for (int i = 0; i < mylist.length_; ++i)
    {
        std::cout << mylist.array_[i] << " ";
    }
    std::cout << std::endl;

    list_insert(&mylist, 0, 99);
    list_insert(&mylist, 2, 77);
    list_insert(&mylist, 7, 11);

    for (int i = 0; i < mylist.length_; ++i)
    {
        std::cout << mylist.array_[i] << " ";
    }
    std::cout << std::endl;

    assert(get_elem(&mylist, 0) == 99);
    assert(get_elem(&mylist, 1) == 2);
    assert(get_elem(&mylist, 2) == 77);
    assert(get_elem(&mylist, 3) == 3);
    assert(get_elem(&mylist, 4) == 4);
    assert(get_elem(&mylist, 5) == 5);
    assert(get_elem(&mylist, 6) == 6);
    assert(get_elem(&mylist, 7) == 11);

    // After destroying the list, it cannot be used any more.
    destroy_list(&mylist);
    assert(mylist.array_ == NULL);
    // list_push_back(&mylist, i); <= No, you cannot do that.

    return 0;
}
