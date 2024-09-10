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

hash_list::hash_list(const hash_list &other) {
    size = other.size;
     if(!other.head) { //is this necessary? idk if other's linked list is allowed to be null
         head = nullptr;
         iter_ptr = nullptr;
         return;
     }
    
    //create new head node
    head = new node;
    head->key = other.head-> key;
    head->value = other.head-> value;
    head->next = nullptr;

    //pointers to follow new and original linked list
    node * currentCopy = head; //follows list being CREATED
    node * currentOriginal = other.head-> next; //follows list being COPIED

    while(currentOriginal) {
        //create the new node
        node * newNode = new node;
        newNode -> key = currentOriginal -> key;
        newNode -> value = currentOriginal -> value;
        newNode -> next = nullptr;

        //attach new node to new list
        currentCopy -> next = newNode;

        //increment both currents
        currentOriginal = currentOriginal -> next;
        currentCopy = currentCopy -> next;
    }

    //check if other's iter_ptr is null and set new iter_ptr null if it is
    //set iter_ptr = head and keep going next until it equals other's iter_ptr then stop
    if(!(other.iter_ptr)) {
        iter_ptr = nullptr;
        return;
    }

    iter_ptr = head;
    node * current = other.head;

    while(current != other.iter_ptr) {
        current = current -> next;
        iter_ptr = iter_ptr -> next;
    }

}

hash_list &hash_list::operator=(const hash_list &other) {
    if(this == &other) return *this;

    // if(!other.head) { //is this necessary? idk if other's linked list is allowed to be null
    //     head = nullptr;
    //     iter_ptr = nullptr;
    //     return;
    // }

    //deallocate the linked list
    node * curr = head;
    while (curr)
    {
        node * temp = curr;
        curr = curr -> next;
        delete temp;
    }

    //delete iter_ptr;
    head = nullptr;
    iter_ptr = nullptr;

    if (!other.head) {
        size = 0;
        return *this;
    }

    size = other.size;
    //iter_ptr = other.iter_ptr;

    //create new head node
    head = new node;
    head->key = other.head-> key;
    head->value = other.head-> value;
    head->next = nullptr;

    //pointers to follow new and original linked list
    node * currentCopy = head; //follows list being CREATED
    node * currentOriginal = other.head-> next; //follows list being COPIED

    while(currentOriginal) {
        //create the new node
        node * newNode = new node;
        newNode -> key = currentOriginal -> key;
        newNode -> value = currentOriginal -> value;
        newNode -> next = nullptr;

        //attach new node to new list
        currentCopy -> next = newNode;

        //increment both currents
        currentOriginal = currentOriginal -> next;
        currentCopy = currentCopy -> next;
    }

    //check if other's iter_ptr is null and set new iter_ptr null if it is
    //set iter_ptr = head and keep going next until it equals other's iter_ptr then stop
    if(!(other.iter_ptr)) {
        iter_ptr = nullptr;
        return *this;
    }
    else{
        iter_ptr = head;
        node * current = other.head;

        while(current != other.iter_ptr) {
             current = current -> next;
             iter_ptr = iter_ptr -> next;
        }
    }
    return *this;
}


void hash_list::reset_iter() {
    //if(!iter_ptr) return;	
   // if(!head) {
     //   iter_ptr = nullptr;
       // return;
    //}

    iter_ptr = head;
}


void hash_list::increment_iter() {
    if(!iter_ptr) return;

    if(!(iter_ptr -> next)){
	iter_ptr = nullptr;
	return;
    }

    iter_ptr = iter_ptr -> next;
}


std::optional<std::pair<const int *, float *>> hash_list::get_iter_value() { 
    if(!iter_ptr) return std::nullopt;

    //int * key_ptr = &(iter_ptr -> key);
    //float * value_ptr = &(iter_ptr -> value);
    return std::make_pair(&(iter_ptr->key), &(iter_ptr ->value));
}


bool hash_list::iter_at_end() {return(!iter_ptr);}
/**-----------------------------------------------------------------------------------
 * END Part 2
 *------------------------------------------------------------------------------------*/
