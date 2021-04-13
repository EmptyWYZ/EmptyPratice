#include <iostream>
using namespace std;
class Solution{
    public:
        int sorting(int arr[], int len){//冒泡

            if(len == 0) return NULL;

            for(int i = 0;i < len - 1; i++){
                int tmp = 0;
                for(int j = 0; j < len - i - 1; j++){
                    if(arr[j] > arr[j + 1]){
                        tmp = arr[j];
                        arr[j] = arr[j + 1];
                        arr[j + 1] =tmp;
                    }
                }
            }
            for(int i = 0; i < len - 1; i++){
                cout << arr[i] << endl;
            }
            return 0;
        }

};
int main() {

    char str1[] = "hello world";
    cout << str1 << endl;

    string str = "hello";

    return 0;
}