#include <iostream>
using namespace std;


template<class T>
class vector
{
public:
    vector()
    {
        init_size = 0;
        init_array = new T[init_size];

    }


    vector(unsigned int size, T element)
    {
        init_size = size;
        init_array = new T[init_size];
        for (int i = 0; i < init_size; i++)
        {
            init_array[i] = element;
        }
    }


    void pop_back()
    {
        T* tmp = init_array;
        init_size--;
        init_array = new T[init_size];
        for (int i = 0 ; i < init_size ; i++)
        {
            init_array[i] = tmp [i];
        }
    }


    void push_back(T element)
    {
        T* tmp = init_array;
        init_size++;
        init_array = new T[init_size];
        for (int i = 0 ; i < init_size - 1 ; i++)
        {
            init_array[i] = tmp [i];
        }
        init_array[init_size-1] = element;
    }


    void print()
    {
        if (init_size > 0) {
            cout << "{";
            for (int i = 0; i < (init_size - 1); i++)
            {
                cout << init_array[i] << ",";
            }
            cout << init_array[init_size - 1] << "}" << endl;
        }
        else
        {
            cout << "invalid input";
        }
    }


    unsigned int size()
    {
        return init_size;
    }


    void resize (int new_size  , T new_element){
        if(new_size>=init_size){
            for(int i = init_size ; i < new_size; i++){
                push_back(new_element);
            }
        }
        else{

            for(int i = init_size ; i > new_size; i--){
                pop_back();
            }

        }
    }


    T operator [](unsigned int index)
    {
        if (index < init_size)
            return init_array[index];
        else
            return nullptr;
    }


    void remove(unsigned int index)
    {
        T* temp = init_array;
        init_size--;
        init_array = new T [init_size];
        for (unsigned int i = 0; i < index; i++)
        {
            init_array[i] = temp[i];
        }
        for (unsigned int i = index; i < init_size - 1; i++)
        {
            init_array[i] = temp[i + 1];
        }
    }


    void insert(unsigned int index, T val)
    {
        T* temp = init_array;
        init_size++;
        init_array = new T [init_size];
        for (unsigned int i = 0; i < index; i++)
        {
            init_array[i] = temp[i];
        }
        init_array[index] = val;
        for (unsigned int i = index; i < init_size - 1; i++)
        {
            init_array[i + 1] = temp[i];
        }
    }


    int sizeof_()
    {
        T temp [init_size];
        for(int i = 0 ; i < init_size ; i++)
        {
            temp[i] = init_array[i];
        }
        return sizeof (temp);
    }


    ~vector()
    {
        delete[] init_array;
        init_array = nullptr;
    }

private:
    unsigned int init_size;
    T* init_array;
};
