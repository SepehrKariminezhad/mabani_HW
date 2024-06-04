#include<iostream>
using namespace std;


template<class T>
class vector
{
	public:
		vector()
        {
            init_size = 0;
            init_array = new T[init_size];
            for (int i = 0 ; i < init_size ; i++)
            {
                init_array[i] = 0;
            }
        }


		vector(unsigned int size , T element = T(0))
        {
            init_size = size;
            init_array = new T[init_size];
            for (int i = 0 ; i < init_size ; i++)
            {
                init_array[i] = element;
            }
        }


        void pup_back()
        {
            init_size--;
        }


		void push_back(T element)
        {
            init_size++;
            init_array[init_size - 1] = element;
        }


		void print()
        {
            if(init_size > 0){
            cout << "{";
            for (int i = 0 ; i < (init_size - 1) ; i++)
            {
                cout <<init_array[i]<<",";
            }
            cout << init_array[init_size - 1] <<"}"<<endl;
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


		void resize(unsigned int new_size, T new_element = T(0))
        {
            if(init_size == 0)
            {
                init_size = new_size;
                for (int i = 0; i < new_size; i++)
                {
                    init_array[i] = new_element;
                }

            }
            else if(new_size <= init_size)
            {
                T* temp = init_array;
                for(int i = 0 ; i < new_size ; i++)
                {
                    init_array[i] = temp [i];
                }
                delete[] temp;
            }
            else
            {
                int c = init_size;
                init_size = new_size;
                for(int j = c ; j < init_size ; j++)
                {
                    init_array[j] = new_element;
                }
            }
        }


        T operator [](unsigned int index)
        {
            if(index < init_size)
                return init_array[index];
            else
                return T(nullptr);
        }


      ~vector()
        {
            delete[] init_array;
        }

	private:
		unsigned int init_size;
		T* init_array;
};


int main()
{
    vector<int>sep(3 , 2);
    //sep.resize(4 , 2);
    sep.push_back(5);
    sep.push_back(6);
    sep.push_back(7);
    cout << sep.size();
    sep.print();

    return 0;
}