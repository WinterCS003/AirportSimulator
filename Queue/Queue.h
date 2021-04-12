#ifndef QUEUE_H
#define QUEUE_H

const int SIZE = 100;

template <class T>
class Queue{
    private:
        int _count;
        int _head;
        int _tail;
        T* _queue;

    public:
        /********************************
         ** CONSTRUCTORS & DESTRUCTORS **
         ********************************/
        Queue();
        ~Queue();

        /**************
         ** MUTATORS **
         **************/
        bool insert(T);
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

template <class T>
Queue<T>::Queue()
{
    _count = 0;
    _head = _tail = 0;
    _queue = new T[SIZE];
}

template <class T>
Queue<T>::~Queue()
{
    delete [] _queue;
}

template <class T>
bool Queue<T>::isEmpty() const
{
    return _count == 0;
}

template <class T>
bool Queue<T>::isFull() const
{
    return _count == SIZE;
}

template <class T>
int Queue<T>::size() const
{
    return _count;
}

template <class T>
T& Queue<T>::head() const
{
    if(isEmpty()){
        throw "Queue is empty";
    }

    return _queue[_head];
}

template <class T>
bool Queue<T>::insert(T value)
{
    if(isFull()){
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

template <class T>
bool Queue<T>::remove()
{
    if(isEmpty()){
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

#endif // QUEUE_H
