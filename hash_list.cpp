#include "hash_list.h"

hash_list::hash_list() {}

/**-----------------------------------------------------------------------------------
 * START Part 1
 *------------------------------------------------------------------------------------*/

void hash_list::insert(int key, float value) 
{
	node * curr = head;

        while (curr)
        {
            if(curr -> key == key)
            {
                curr -> value = value;
                return;
            }
            curr = curr -> next;
        }

        node* nHead = new node{key, value, head};
        head = nHead;
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
	bool remove(int key){
        if(!head)
        {
            return nullptr;
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
}

size_t hash_list::get_size() const { return 0; }

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
