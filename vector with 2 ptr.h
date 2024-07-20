#include <iostream>

using namespace std;
    template <class T>
    class vector_2{
    public:
        vector_2(int _N, T _Val);
        ~vector_2();
        T operator[] (int i);
        void push_back(T element);
        void insert(unsigned int index, T val);
        void remove(unsigned int index);
        int size(){
            return N;
        }
        ;
    protected:
        T** data;
        int N;
    };


    template <class T>
    vector_2<T>::vector_2(int _N, T _Val ):N(_N){
        data = new T*[N];
        for (int i{0}; i < N; i++){
            data[i] = new T(_Val);
        }
    }

    template <class T>
    vector_2<T>::~vector_2(){
        for (int i{0};i < N; i++){
            delete data[i];
        }
        delete [] data;
    }

    template <class T>
    T vector_2<T>::operator[] (int i){
        try {
            if (i>=0 && i < N){
                return *data[i];
            }
            else
                throw(i);
        }
        catch(int i){
            std::cout << "out of range, try to access "<< i << " out of " << N <<"\n";
            exit(-1);
        }
    }
    template <class T>
    void vector_2<T>::push_back(T element){
        T** tmp = data;
        N++;
        data = new T*[N];
        for (int i = 0 ; i < N - 1 ; i++)
        {
            cout <<"N" << N << endl;
            data[i] = tmp [i];
            cout << *(data[i]) << endl;       }
        data[N-1] = &element;
        cout << *(data[N-1]) << endl;
    }



template <class T>
void vector_2<T>::insert(unsigned int index, T val)
{
    T** temp = data;
    N++;
    data = new T* [N];
    for (unsigned int i = 0; i < index; i++)
    {
        data[i] = temp[i];
    }
    data[index] = &val;
    for (unsigned int i = index; i < N - 1; i++)
    {
        data[i + 1] = temp[i];
    }
}


template <class T>
void vector_2<T>::remove(unsigned int index)
{
    T** temp = data;
    N--;
    data = new T* [N];
    for (unsigned int i = 0; i < index; i++)
    {
        data[i] = temp[i];
    }
    for (unsigned int i = index; i < N - 1; i++)
    {
        data[i] = temp[i + 1];
    }
}






