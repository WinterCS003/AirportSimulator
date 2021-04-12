#ifndef QUEUE_H
#define QUEUE_H

const int SIZE = 10000;

template <class T>
class Queue{
    private:
        int _count; // IN - number of elements in the array
        int _head;  // IN - head of Queue
        int _tail;  // IN - tail of Queue
        T* _queue;  // IN - Queue implemented as an array

    public:
        /********************************
         ** CONSTRUCTORS & DESTRUCTORS **
         ********************************/
        Queue();
        ~Queue();

        /**************
         ** MUTATORS **
         **************/
        bool insert(T); // IN - value to insert
        bool remove();
        void incrementObjects();

        /***************
         ** ACCESSORS **
         ***************/
        bool isEmpty() const;
        bool isFull() const;
        int size() const;
        T& head() const;
};

/****************************************************************
 * Queue Class
 *   This class represents a queue implemented using a dynamic
 *   array. It manages 4 attributes, the size of the array,
 *   an index to the head, an index to the tail, and the
 *   queue array itself.
 ***************************************************************/


/******************************
 ** CONSTRUCTOR & DESTRUCTOR **
 ******************************/

/****************************************************************
 * Queue();
 *   Constructor; Creates and null initializes an empty Queue.
 *   Parameters: none
 *   Return: none
 ***************************************************************/
template <class T>
Queue<T>::Queue()
{
    _count = 0;
    _head = _tail = 0;
    _queue = new T[SIZE];
}

/****************************************************************
 * ~Queue();
 *   Destructor; Deletes the dynamic array
 *   Parameters: none
 *   Return: none
 ***************************************************************/
template <class T>
Queue<T>::~Queue()
{
    delete [] _queue;
}

/**************
 ** MUTATORS **
 **************/

/*******************************************************************
 * bool insert(T value);
 *
 *   Mutator; This method will insert a value into the queue if
 *   it is not already full.
 *------------------------------------------------------------------
 *   Parameter:value (T) // IN – the value to insert
 *------------------------------------------------------------------
 *   Return: true on success, false otherwise
 *******************************************************************/
template <class T>
bool Queue<T>::insert(T value) // IN - value to insert
{
    if(isFull()){
        throw "Queue is full";
        return false;
    }

    _queue[_tail] = value;
    _count++;

    if(_tail == SIZE-1){
        _tail = 0;
    } else{
        _tail++;
    }

    return true;
}

/*******************************************************************
 * bool remove();
 *
 *   Mutator; This method will delete the value at the head of the
 *   array.
 *------------------------------------------------------------------
 *   Parameter: none
 *------------------------------------------------------------------
 *   Return: true on success, false otherwise
 *******************************************************************/
template <class T>
bool Queue<T>::remove()
{
    if(isEmpty()){
        throw "Queue is empty";
        return false;
    }

    _count--;
    if(_head == SIZE-1){
        _head = 0;
    } else{
        _head++;
    }

    return true;
}

/*******************************************************************
 * void incrementObjects()
 *
 *   Mutator; This method will increment all objects in the array
 *   by 1.
 *------------------------------------------------------------------
 *   Parameter: none
 *------------------------------------------------------------------
 *   Return: none.
 *******************************************************************/
template <class T>
void Queue<T>::incrementObjects()
{
    for(int i = _head; i != _tail; i++){
        if(i == SIZE - 1){
            i = 0;
        }
        ++_queue[i];
    }
}


 /***************
  ** ACCESSORS **
  ***************/

/****************************************************************
 * bool isEmpty() const;
 *
 *   Accessor; This method will return true if the array is empty
 *   false otherwise
 * --------------------------------------------------------------
 *   Parameters: none
 * --------------------------------------------------------------
 *   Return: bool - true if the array is empty false otherwise
 ***************************************************************/
template <class T>
bool Queue<T>::isEmpty() const
{
    return _count == 0;
}

/****************************************************************
 * bool isFull() const;
 *
 *   Accessor; This method will return true if the array is full
 *   false otherwise
 * --------------------------------------------------------------
 *   Parameters: none
 * --------------------------------------------------------------
 *   Return: bool - true if the array is full false otherwise
 ***************************************************************/
template <class T>
bool Queue<T>::isFull() const
{
    return _count == SIZE;
}

/****************************************************************
 * bool size() const;
 *
 *   Accessor; This method will return the number of elements
 *   in the array
 * --------------------------------------------------------------
 *   Parameters: none
 * --------------------------------------------------------------
 *   Return: int - size of array
 ***************************************************************/
template <class T>
int Queue<T>::size() const
{
    return _count;
}

/****************************************************************
 * bool head() const;
 *
 *   Accessor; This method will return the element at the head
 *   of the array. This is the first element to be removed
 * --------------------------------------------------------------
 *   Parameters: none
 * --------------------------------------------------------------
 *   Return: reference to the element at the head.
 ***************************************************************/
template <class T>
T& Queue<T>::head() const
{
    if(isEmpty()){
        throw "Queue is empty";
    }

    return _queue[_head];
}

#endif // QUEUE_H
