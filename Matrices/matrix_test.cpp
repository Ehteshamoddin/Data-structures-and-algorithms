#include<iostream>
using namespace std;
class matrix_test
{
private:
    int *a;
    int n;
public:
    matrix_test(){
        n=2;
        a=new int[n];
    }
    matrix_test(int n){
        this->n=n;
        a=new int[n];
    }
    ~matrix_test(){
        delete []a;
    }
};


int main(){
    
    return 0;
}