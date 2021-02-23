/*
1. Mathematics
2. Count Digits
3. Palindrome Number
4. Factorial of a Number
5. Trailing zeroes in a Factorial
6. GCD or HCF of two numbers
7. LCM of two numbers
8. Check for prime
9. Prime Factors
10. All Divisors of a Number
11. Sieve of eratosthenes
12. Computing Power
*/


// 2. Count Digits
// Finding No of Digits in a Number
int countDigit(long n)  // Iterative // Time Complexity = Theta(d)
{
    int count=0;
    while(n!=0)
    n=n/10;
    ++count;
    return count;
}


int countDigit(long n)  // Recursive
{
    if(n==0)return 0;
    return 1+countDigit(n/10);
}



int countDigit(long n)   //Logarthimic solution
{
    return floor(log10(n)+1);
}


//3. Palindrome Number ( Reverse Same )
// Time Complexity = Theta(d)
bool isPal(int n){
    int rev=0;
    int temp=n;
    while(temp!=0){
        int ld= temp%10;
        rev=rev*10+ld;
        temp/=10;
    }
    return(rev==n);
}


// 4.Factorial of a Number
// Time Complexity = Theta(N) , Auxilary Space = Theta(1)
int fact(int n){            //Iterative Solution
    int res=1;
    for(int i=2;i<=n;i++)
    res=res*i;
    return res;
}


int fact(int n){           // Recursive Solution , Auxilary Space = Theta(N)
    if(n==0)return 1;
    return n*fact(n-1);
}


//5. Trailing Zeroes in a factorial
// Iterative method
int constZero(int n){
    int fact=1;
    for(int i=2;i<=n;i++)
    fact=fact*i;
    int res=0;
    while(fact%10==0){
        res++;
        fact/=10;
    }
    return res;
}


// Another Efficient Method to Overcome with the overflows
// Time Complexity = Theta(log n)
int countTrailingZeroes(int n){
    int res=0;
    for(int i=5;i<=n;i=i*5)
    res=res+n/i;
    return res;
}


//6. GCD or HCF of two numbers
// Naive Solution, Time Complexity = O(min(a,b))
int gcd(int a,int b){
    int res=min(a,b);
    while(res>0){
        if(a%res==0 && b%res==0){
            break;
        }
        res--;
    }
    return res;
}


// Euclidean Algorithm
int gcd(int a,int b){
    while(a!=b){
        if(a>b)a=a-b;
        else b=b-a;
    }
    return a;
}


//Optimized Implementation
int gcd(int a,int b){
    if(b==0)
    return a;
    else
    return gcd(b,a%b);
}


// 7. LCM of Two Numbers
// Naive Solution
// Time Complexity = O(a*b - max(a,b))
int lcm(int a,int b){
    int res=max(a,b);
    while(true){
        if(res%a==0 && res%b==0)
            return res;
            res++;
    }
    return res;
}


// Efficient Solution
// Time Complexity = O(log(min(a,b)))
int gcd(int a,int b){
    if(b==0)return a;
    return gcd(b%a,a);
}
int lcm(int a,int b){
    return (a*b)/gcd(a,b);
}


// 8. Check for Prime
// Time Complexity = O(N)
bool isPrime(int n){
    if(n==1)return false;
    for(int i=2;i<n;i++)
    if(n%i==0)return false;
    return true;
}


// Efficient MEthod
// Time = O(Sqrt n)
bool isPrime(int n){
    if(n==1)return false;
    for(int i=2;i*i<=n;i++)
    if(n%i==0)return false;
    return true;
}


// 9. Prime Factors
// Efficient Solution
void printPrime(int n){
    if(n<=1)return ;
    for(int i=2;i*i<=n;i++){
        while(n%i==0){
            print(i);
            n/=i;
        }
    }
    if(n>1)
    print(n);
}


// 10. All divisors of a Number
// Time Complexity= O(Sqrt(n))
void printDivisors(int n){
    for(int i=1;i*i<=n;i++){
        if(n%i==0){
            print(i);
            if(i!=n/i)
            print(n/i)l
        }
    }
}


// 11. Sieve of eratosthenes
// TIme complexity= O(n* sqrt n)
void printprimes(int n){
    for(int i=2;i<=n;i++){
        if(isPrime(i))
        print(i);
    }
}


//12. Computing Power
// Time= Theta(log n), Auxilary = Theta(log n)
int power(int x,int n){
    if(n==0)return 1;
    int temp=power(x,n/2);
    temp=temp*temp;
    if(n%2==0)return temp;
    else return temp*x;
}