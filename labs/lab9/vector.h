#include <stdlib.h>
#include <iostream>
#include <exception> //base class of all built-in exceptions
#include <stdexcept> //where out_of_range lives

template <class T>
class vector {
   private:
      T *v;  //a dynamic array of elements of type T
      int s; //size
   public:
      //default constructor
      vector(){
	      this->s = 0;
	      this->v = NULL;
      }

      //copy constructor
      vector(vector &other){
         this->s = other.size();
         this->v = new T[this->s];

         for(int i = 0; i < this->s; i++){
            this->v[i] = other.v[i];
         }
      }

      //AOO
      vector& operator=(vector<T> &other){
         if(this->v != NULL){
            delete this->v;
            this->v = NULL;
         }

         this->s = other.size();
         this->v = new T[this->s];

         for(int i = 0; i < this->s; i++){
            this->v[i] = other.v[i];
         }

         return *this;
      }

      //destructor	  
      ~vector(){
	      delete [] this->v;
	      this->v = NULL;
      }

      T operator[](int x){
         return this->v[x];
      }

      T at(int x){
         try{
            if(x > this->s - 1){
               throw std::out_of_range("out of my vector bounds");
            }

            return this->v[x];
         } catch(std::out_of_range e){
            std::cout << e.what() << std::endl;
         }
      }
	
      //size function	  
      int size() {
	      return this->s;
      }

      //push_back: add an element to the end	  
      void push_back(T ele) {
         T *temp;
         temp = new T[++this->s];
         for(int i = 0; i < this->s-1; i++)
            temp[i] = this->v[i];

         if (this->v != NULL)
            delete [] this->v;

         this->v = temp;
         this->v[s-1] = ele;
      }

};
