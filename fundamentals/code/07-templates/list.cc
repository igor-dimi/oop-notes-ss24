#include "list.hh"
#include <string>

template <typename T>
typename List<T>::Iterator List<T>::begin()
{
    Iterator it;
    it.position = first;
    it.container = this;
    return it;
}

template <typename T>
typename List<T>::Iterator List<T>::end()
{
    List::Iterator it;
    it.position = nullptr;
    it.container = this;
    return it;
}

template <typename T>
void List<T>::Iterator::operator++(int dummy)
{
    position = position->next;
}


template <typename T>
void List<T>::Iterator::operator++()
{
    position = position->next;
}

template <typename T>
void List<T>::Iterator::operator--(int dummy)
{
    if (position == nullptr)
        position = container->last;
    else
        position = position->prev;
}

template <typename T>
const T& List<T>::Iterator::operator*() const
{
    return position->data;
}

template <typename T>
bool List<T>::Iterator::operator==(const Iterator& other) const
{
    return position == other.position;
}

template <typename T>
bool List<T>::Iterator::operator!=(const Iterator& other) const
{
    return !(*this == other);
}


template <typename T>
void List<T>::push_back(const T& val) 
{
    Node* node = new Node(val);
    if (last == nullptr) { // list empty
        first = last = node;
    }
    else {
        node->prev = last;
        last->next = node;
        last = node;
    }
}


template <typename T>
void List<T>::insert(const Iterator& it, const T& val)
{
    Node* np = new Node(val);
    if (it.position == nullptr || last == nullptr){// insert at the end or list empty
        push_back(val); 
    }
    else if (it == begin()) { // inserting at the beginning of the list
        np->next = first;
        first->prev = np;
        first = np;
    }
    else {
        it.position->prev->next = np;
        np->prev = it.position->prev;
        np->next = it.position;
        it.position->prev = np;
    }

}

template <typename T>
typename List<T>::Iterator List<T>::erase(const Iterator& it)
{
    if (first == last) { //contains single element
        first = last = nullptr;
        List::Iterator ret;
        ret.container = this;
        return ret;
    } else if (it.position == first) { // removing first element
        it.position->next->prev = nullptr;
        first = it.position->next; 
        delete it.position;
        List::Iterator ret;
        ret.position = first;
        ret.container = this;
        return ret;
    } else if (it.position == last) { // removing last element
        it.position->prev->next = nullptr;
        last = it.position->prev;
        delete it.position;
        List::Iterator ret;
        ret.container = this;
        return ret;
    } else {
        it.position->prev->next = it.position->next;
        it.position->next->prev = it.position->prev;
        Node* nxt = it.position->next;
        delete it.position;
        List::Iterator ret;
        ret.position = nxt;
        ret.container = this;
        return ret;
    }
}


template <typename T>
void List<T>::free()
{
    Node* del;
    while (del != nullptr) {
        Node* del_next = del->next;
        delete del;
        del = del->next;
    }
}

template <typename T>
void List<T>::copy(const List<T>& other)
{
    Node* copied = nullptr;
    Node* copy_next = other.first;
    first = last = nullptr;
    while (copy_next != nullptr) {
        Node* np = new Node(copy_next->data);
        np->prev = copied;
        if (copied == nullptr) 
            first = np;
        else 
            copied->next = np;

        if (copy_next == other.last) last = np;
        copy_next = copy_next->next;
        copied = np;
    }
}

template <typename T>
List<T>::List(const List<T>& other)
{
    copy(other);
}

template <typename T>
List<T>::~List() {free();}

template <typename T>
List<T>& List<T>::operator=(const List<T>& other)
{
    if (this != &other) {
        free();
        copy(other);
    }
}

template <typename T>
List<T>::Node::Node(const T& val)
{
    data = val;
    prev = next = nullptr;
}

template <typename T>
List<T>::Iterator::Iterator()
{
    position = nullptr;
    container = nullptr;
}

template <typename T>
List<T>::List() {first = last = nullptr;}