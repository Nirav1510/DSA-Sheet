#include <bits/stdc++.h>
using namespace std;

vector<int> factorial(int n)
{
    vector<int> v;
    v.push_back(1);
    int carry = 0;

    for (int i = 2; i <= n; i++)
    {
        for (int j = v.size() - 1; j >= 0; j--)
        {
            int product = (v[j] * i) + carry;
            carry = product / 10;
            v[j] = product % 10;
        }
        if (carry == 0)
            continue;

        while (carry)
        {
            v.insert(v.begin(), carry % 10);
            carry /= 10;
        }
        carry = 0;
    }
    return v;
}

int main(){
    int n;
    cin>>n;
    vector<int> res = factorial(n);

    for(int i : res){
        cout<<i;
    } 
    return 0;
}