#include "hash_list.h"

hash_list::hash_list() {
    size = 0;
    head = nullptr;
}

/**-----------------------------------------------------------------------------------
 * START Part 1
 *------------------------------------------------------------------------------------*/

void hash_list::insert(int key, float value) {
    if(!head) { //if linked list doesnt exist yet
        node * new_node = new node;
        new_node -> key = key;
        new_node -> value = value;
        new_node -> next = nullptr;
        head = new_node;
        size++;
        return;
    }

    node * curr = head;
    node * prev = nullptr;

    while(curr) { //iterate through list and check if key already exists
        if(curr -> key == key) {
            curr -> value = value;
            return;
        }
        prev = curr;
        curr = curr -> next;
    }

    node * new_node = new node;
    new_node -> key = key;
    new_node -> value = value;
    new_node -> next = nullptr;
    prev -> next = new_node;
    size++;
}

std::optional<float> hash_list::get_value(int key) const
{ 
	node * current = head;
        while(current)
        {
            if (current -> key == key)
            {
                return current -> value;
            }
            current = current -> next;
        }
	return std::nullopt;
}

bool hash_list::remove(int key) {
    if(!head)
    {
        return false;
    }
    
    node * curr = head;
    node * prev = nullptr;

    while (curr) {
        if(curr -> key == key) {
            if (prev){
                prev -> next = curr -> next;
            }
            else {
                head = curr -> next;
            }
            delete curr;
            size--;
            return true;
        }
        prev = curr;
        curr = curr -> next;
    }
    return false;
}

size_t hash_list::get_size() const { return size; }

hash_list::~hash_list() 
{
	node * curr = head;
        while (curr)
        {
            node * temp = curr;
            curr = curr -> next;
            delete temp;
        }
}

/**-----------------------------------------------------------------------------------
 * END Part 1
 *------------------------------------------------------------------------------------*/


/**-----------------------------------------------------------------------------------
 * START Part 2
 *------------------------------------------------------------------------------------*/

hash_list::hash_list(const hash_list &other) {}

hash_list &hash_list::operator=(const hash_list &other) { return *this; }

void hash_list::reset_iter() {}


void hash_list::increment_iter() {}


std::optional<std::pair<const int *, float *>> hash_list::get_iter_value() { return std::nullopt; }


bool hash_list::iter_at_end() { return false; }
/**-----------------------------------------------------------------------------------
 * END Part 2
 *------------------------------------------------------------------------------------*/
