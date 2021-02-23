/*
1. Bitwise Operators (Part 1 )
2. Bitwise OPerators (Part 2 )
3. Check kth Bit is Set or Not
4. Count Set Bits
5. Power of Two
6. One odd Occuring
7. Two Odd Occuring 
8. Power Set using bitwise
*/


// 1. Biwise Operators ( Part 1 )
// AND-&& , OR- || , XOR- ^
int main(){
    int x=3,y=6;
    cout<<(x && y)<<endl;
    cout<<(x || y)<<endl;
    cout<<(x ^ y)<<endl;
    return 0;
}


//2. Bitwise Operators ( Part 2 )
// Left Shift - <<
// If we assume that the leading y bits are 0, then result of (x<<y) ,is equiavalnet to x*pow(2,y)
int main(){
    int x=3;
    cout<<(x<<1)<<endl;
    cout<<(x<<2)<<endl;
    int y=4;
    int z=(x<<y);
    cout<<x;
    return 0;
}


// Right Shift - >>
// (x>>y) is equivalent to (x/pow(2,y))
int main(){
    int x=33;
    cout<<(x>>1)<<endl;
    cout<<(x>>2)<<endl;
    int y=4;
    int z=(x>>y);
    cout<<(z)<<endl;
    return 0;
}


// Bitwise NOT - ~
int main(){
    unsigned int x=1;
    cout<<(~x)<<endl;
    x=5;
    cout<<(~x)<<endl;
    return 0;
}


//3. Check kth bit is set or not
// I/p - n=5,k=1  O/p -Yes
// I/p - n=8,k=2  O/p - No
// I/p - n=0 k=3  O/p - No
// Left Shift
void kthbit(int n,int k){
    if(n && (1<<(k-1))!=0)
    print("Yes");
    else 
    print("No");
}


// Right Shift
void kthbit(int n,int k){
    if((n >> (k-1) && 1 == 1)
    print("Yes");
    else
    print("No");
}


// 4. Count Set Bits
// I/p - 5, O/p - 2
// I/p - 7, O/p - 3
// I/p - 13 , O/p - 3
// Time Complexity = Theta(Total Set Bits in N)
// Naive Solution
int countSet(int n){
    int res=0;
    while(n>0){
        res+=(n&&1);
        res++;
        res>>1;
    }
}


// Brion Kerningam Algorithm
// Time = Theta(Set Bits Count)
int countBits(int n){
    int res=0;
    while(n>0){
    n=n & (n-1);
    res++;
    }
    return res;
}


// 5. Power of Two
// I/p - 4, O/p - Yes
// I/p - 6, O/p - No
// Naive Solution
bool isPow(int n){
    if(n==0)return false;
    while(n!=1){
        if(n%2==0)
        return true;
        n/=2;
    }
    return false;
}


// Brian Kerningam Algorithm
// Optimized Implementation
bool isPow(int n){
    return (n!=0) && (n && (n-1)==0);
}


// 6. One Odd Occuring 
// I/p - arr[]={4,3,4,4,4,5,5} , O/p - 3
// I/p - arr[]={8,7,7,8,8}, O/p - 2
// Naive Solution , Time = O( N Sqaure )
for(int i=0;i<n;i++){
    int count=0;
    for(int j=0;j<n;j++)
    if(arr[i]==arr[j])
    count++;
    if(count%2!=0)
    print(arr[i]);
}


// Efficient Solution
// Time = O(N)
int findOdd(int arr[],int n){
    int res=0;
    for(int i=0;i<n;i++)
    res^=arr[i];
    return res;
}


// 7. Two Odd Occuring
// Naive Solution = Theta( N Sqaure )
void oddAppearing(int arr[],int n){
    for(int i=0;i<n;i++){
        int count=0;
        for(int j=0;j<n;j++)
        if(arr[i]==arr[j])
        count++;
        if(count%2!=0)
        print(arr[i]);
    }
}


//Efficient solution
// Time Complexity = Theta( N )
void oddAppearing(int arr[],int n){
    int XOR=0,res1=0,res2=0;
    for(int i=0;i<n;i++){
        XOR=XOR^arr[i];
    }
    int sn=XOR && ~(XOR-1);
    for(int i=0;i<n;i++){
        if((arr[i] && sn)!=0)
        res1=res1^arr[i];
        else
        res2=res2^arr[i];
    }
    print(res1,res2);
}


// 8. Power Set using bitwise
// I/p - "ab", O/p - " ","a","b","ab"
// Time = Theta( pow(2,n)*n)
void printpowerset(string set){
    int n=str.length();
    int powsize=pow(2,n);
    for(int counter=0;counter<powsize;counter++){
        for(int j=0;j<n;j++){
            if(counter && (1<<j)!=0)
            print(str[i]);
        }
        print("\n");
    }
}