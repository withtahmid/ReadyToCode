#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define I_am_starting_in_the_name_of_Allah ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define pi acos(-1)
#define fast_io ios_base::sync_with_stdio(false), cin.tie(NULL),cout.tie(NULL)

///71.3814
cout<<fixed<<setprecision(2)<<endl;
///Reseult 71.38

///G - Etruscan Warriors Never Play Chess
ll fin = (sqrt(n*8+1)-1)/2;

///Precission Handeling
const double EPS = (double) 1e-9;
bool isEqual(double a, double b)
{
    return abs(a - b) <= EPS;
}

bool isSmaller(double a, double b)
{
    return b - a > EPS;
}

bool isGreater(double a, double b)
{
    return a - b > EPS;
}

///Sqrt with Precission Handleing
const double EPS = (double) 1e-9;
double squareRoot(double x) // 10
{
    double l = 0.0, r = max(1.0, x), sqr = x, steps = 100;
    while(l <= r && steps--)
    {
        double mid = l + (r - l) / 2; // 3.203125
        double sq = mid * mid; // 10.26....
//        cout << l << " " << r << " " << mid << " " << sq << “\n”;
        if(sq - x > EPS)
        {
            r = mid; // 3.28125
        }
        else if(x - sq > EPS)
        {
            l = mid; // 3.125
            sqr = mid; // 3.125
        }
        else
        {
            return mid;
        }
    }
    return sqr;
}

/// //// ////////////////////////////////////////////////////


const int N=1e7+5;
int main()
{

///MAP
   Map <int, int>mp; mp.insert(pair<int, int>(4,10));
   sort(rbegin(), rend()); myvector1.swap(myvector2); minimum element=*min(v.begin(),v.end());

///SET



///Prime_Checker
bool IsPrime(int n){if(n <= 1){return false;}for(int i = 2; i * i <= n; i++){if(n % i == 0){return false;}}return true;}


///Checking the divisibility
bool divisible(string s, int n){int rem = 0, len = s.size();for(int i = 0; i < len; i++){int dig = s[i] - '0'; rem = (rem * 10) + dig;rem = rem % n;}if(rem == 0){return true;}return false;}


///ReverseAnIntergerNumber
int Reverse(int n){int rem=0;while(n!=0){rem=rem*10+(n%10);n=n/10;}return rem;}


///GCD
int gcd(int a, int b) {if (b == 0)return a;return gcd(b, a % b);}

///LCM
int lcm(int a, int b) {return (a / gcd(a, b)) * b;}

///DivisorGenerator
void generate_divisors(int n){divisors.clear();for(int i = 1; i * i <= n; i++){if(n % i == 0){divisors.push_back(i);int j = n / i;if(i != j){divisors.push_back(j);}}}}

///NOD (Number of Divisor)
const int N=1e6
int NOD[N+5];void generateNOD(){for(int i=1; i<=N; i++){for(int j=i; j<=N; j+=i){NOD[j]++;}}}

///SOD (Sum of Divisor)
const int N=1e6
int SOD[N+5];void generateSOD(){for(int i=1; i<=N; i++){for(int j=i; j<=N; j+=i){SOD[j]+=i;}}}

///Sieve()
const int N=1e6;
bool isPrime[N+1];
vector<int> primes;
void sieve(){for(int i=1; i<=N; i++){isPrime[i] = true;}isPrime[1] = false;for(int i = 4; i<=N; i+=2){isPrime[i] = false;}for(int i=3; i*i <= N; i+=2){if(isPrime[i]){for(int j=i*i; j<=N; j+=2*i){isPrime[j] = false;}}
}for(int i=2; i<=N; i++){if(isPrime[i]) primes.push_back(i);}}


///prime Factorization
vector<int> prime_factorize2(int n) {vector<int> result;for (int p : primes) {if (p * p > n) break;while (n % p == 0) {n /= p;result.push_back(p);
        }}if (n != 1) {result.push_back(n);}return result;}


///Returns the complete list of (factor, exponent) pairs
vector<pair<int, int>> prime_factorize_as_pair(int n) {vector<pair<int, int>> result;for (int p : primes) {if (p * p > n) break;
        if (n % p == 0) {int expo = 0;while (n % p == 0) {++expo;n /= p;}result.push_back(make_pair(p, expo));}}
    if (n != 1) {result.push_back(make_pair(n, 1));}return result;}


///primeFactorWithPower
void primeFactorWithPower(ll n)
{int cnt=0;while(n%2==0){n=n/2;cnt++;}if(cnt>0)cout<<"2^"<<cnt<<" ";
for(ll i=3;i*i<=n;i+=2){int cnt=0;while(n%i==0){n/=i;cnt++;}if(cnt>0) cout<<i<<"^"<<cnt<<" ";}if(n>2)cout<<n<<"^1"<<endl;}

///Prime-factorization of factorial
vector<pair<int, int>> factorize_factorial_v2(int n) {
    vector<pair<int, int>> result;
    for (auto p : primes) {
        if (p > n)
         break;
        int expo = 0;
        // copy n to a temporary variable
        auto n_tmp = n;
        // get occurence-count of p^1
        auto q = n_tmp / p;
        while (q > 0) {
            // add current occurence-count
            expo += q;
            // update "temporary n" to current quotient
            n_tmp = q;
            // divide "temporary n" and get the quotient
            // which is the next occurence-count
            q = n_tmp / p;
        }
        result.push_back({p, expo});
    }
    return result;
}


///Binary Search 2
int binary2Search(int val) {int lo = 0, hi = v.size() - 1, first_idx = -1;while (lo <= hi) {int mid = (lo + hi) / 2;if (v[mid] == val) {
            first_idx = mid;hi = mid - 1;} else if (v[mid] > val) {hi = mid - 1;} else if (v[mid] < val) {lo = mid + 1;}}return first_idx;
}


///Upper Bound
int *ptr = upper_bound(a,a+n,x); //it returns its shortest elder value;
int *ptr = upper_bound(a+4,a+n,x);
auto it = upper_bound(a.begin(),a.end(),x);
if(ptr==a+n) cout<<"not found";
if(it=a.end()) cout<<"not found";
///Lower Bound
*ptr = lower_bound(a,a+n,x); //if x exist then it will return x but it is not it returns it shortest elder value;
*ptr = lower_bound(a+4,a+n,x);


///BigMod
int Bigmod(int base, int power, int mod)
{if(power==0)return 1;else if(power%2==1){int a=base%mod;int b=(Bigmod(base, power-1,mod))%mod;return (a*b)%mod;}else
    {int a=(Bigmod(base,power/2,mod))%mod;return (a*a)%mod;}}

///Product Of Digit

ll Nezuko (ll n)
{if(n>=0 && n<=9)return n;stack <ll> DemonArt;for(ll i=9;i>=2 && n>1;i--){while(n%i==0)
       {DemonArt.push(i);n/=i;}}if(n!=1)return -1;ll Zenitsu=0;while(!DemonArt.empty())
   {Zenitsu = Zenitsu*10 + DemonArt.top();DemonArt.pop();}return Zenitsu;
}return 0;}


///Prefix Sum

int arr[N + 1], sum[N + 1];
void generateSum(int n)
{sum[0] = arr[0];for(int i = 1; i < n; i++)
    {sum[i] = sum[i - 1] + arr[i];}
}

/// Base Convertion Algorithm (any base to Decilmal)
int val(char c)
{
    if (c >= '0' && c <= '9')
        return (int)c - '0';
    else return 
        (int)c - 'A' + 10;
}

// Function to convert a number from given base 'b'
// to decimal
int toDeci(string str, int base)
{int len = str.size(); int power = 1; // Initialize power of base
int num = 0;  // Initialize result
int i;// Decimal equivalent is str[len-1]*1 +
    // str[len-2]*base + str[len-3]*(base^2) + ...
    for (i = len - 1; i >= 0; i--)
    {
        // A digit in input number must be
        // less than number's base
        if (val(str[i]) >= base){printf("Invalid Number");return -1;}num += val(str[i]) * power;power = power * base;}

    return num;
}





///Large Number Factorial


const int MAX=1e5;
int multiply(int x, int res[], int res_size)
{
    int carry = 0;  // Initialize carry

    // One by one multiply n with individual digits of res[]
    for (int i=0; i<res_size; i++)
    {
        int prod = res[i] * x + carry;

        // Store last digit of 'prod' in res[]
        res[i] = prod % 10;

        // Put rest in carry
        carry  = prod/10;
    }

    // Put carry in res and increase result size
    while (carry)
    {
        res[res_size] = carry%10;
        carry = carry/10;
        res_size++;
    }
    return res_size;
}

void factorial(int n)
{
    int res[MAX];

    // Initialize result
    res[0] = 1;
    int res_size = 1;

    // Apply simple factorial formula n! = 1 * 2 * 3 * 4...*n
    for (int x=2; x<=n; x++)
        res_size = multiply(x, res, res_size);

    cout << "Factorial of given number is \n";
    for (int i=res_size-1; i>=0; i--)
        cout << res[i];
}




/// Digits of any base factorial
vector<double> lg(int (1e6)+1,0);
    for(size_t i=1;i<=1e6;i++)
        lg[i] = lg[i-1] + log10(i);

    int tc;cin>>tc;
    int cnt=0;
    while(tc--)
    {
        int num;
        int base;cin>>num>>base;
        cout<<"Case "<<++cnt<<": "<<(ll)(lg[num]/log10(base))+1<<endl;

    }


    ///BinarySearch

    bool binarySearch(vector<int> v, int value)
{
    int low=0;
    int high=v.size()-1;
    while(low<=high)
    {
        int mid = (low+high)/2;
        if(v[mid]==value)
            return true;
        else if(v[mid]<value)
            low=mid+1;
        else
            high = mid-1;
    }
    return false;
}


///Binary Search Index
int binarySearch(int arr[], int l, int r, int x)
{
    while (l <= r) {
        int m = l + (r - l) / 2;

        if (arr[m] == x)
            return m;

        if (arr[m] < x)
            l = m + 1;
        else
            r = m - 1;
    }
    return -1;
}

///Decimal To binary

string DecimalToBinary(int n)
{
    string str;
    while(n)
    {
        if(n & 1)
            str += '1';
        else
            str += '0';
        n >>= 1;
    }
    reverse(str.begin(), str.end());
    ///next_permutation(str.begin(), str.end());
    return str;
}

///deque
deque<int>dq;
q.push_front();
q.push_back();
q.pop_back();
q.pop_front();
q.empty();
q.front();
q.back();

///Queue
queue<int>q;
q.push();
q.pop();
q.empty();
q.front();
///FIFO

///Stack
stack<int>s;
s.push();
s.pop();
s.empty();
s.top();
///LIFO


///BalancedParentheses
bool isBalancedParentheses(const string& str)
{
    int n = str.size();
    stack <char> st;
    for(int i = 0; i < n; i++)
    {
        if(str[i] == '(')
        {
            st.push(str[i]);
        }
        else
        {
            if(st.empty())
            {
                return false;
            }
            st.pop();
        }
    }
    if(st.empty())
    {
        return true;
    }
    return false;
}

///BalancedParentheses- v 2.0
bool areBracketsBalanced(string expr)
{
    stack<char> temp;
        for(int i=0;i<expr.length();i++)
        {
            if(temp.empty())
            {
                temp.push(expr[i]);
            }
            else if((temp.top()=='('&& expr[i]==')')  ||  (temp.top()=='{' && expr[i]=='}')  ||  (temp.top()=='[' && expr[i]==']'))
            {
                temp.pop();
            }
            else
            {
                temp.push(expr[i]);
            }
        }
        if(temp.empty())
        {
            return true;
        }
        return false;
}

///largest area of same base in a Histogram
int getMaxArea(vector<int>v, int n)
{

    stack<int> s;

    int max_area = 0;
    int tp;
    int area_with_top;

    int i = 0;
    while (i < n)
    {

        if (s.empty() || v[s.top()] <= v[i])
            s.push(i++);
        else
        {
            tp = s.top();
            s.pop();

            area_with_top = v[tp] * (s.empty() ? i :
                                   i - s.top() - 1);

            if (max_area < area_with_top)
                max_area = area_with_top;
        }
    }

    while (s.empty() == false)
    {
        tp = s.top();
        s.pop();
        area_with_top = v[tp] * (s.empty() ? i :
                                i - s.top() - 1);

        if (max_area < area_with_top)
            max_area = area_with_top;
    }

    return max_area;
}


/// LeapYear code
bool Leap(string yr)
{
    if(div(yr,400))
       return true;
       else if(div(yr,100))
            return false;
            else if(div(yr,4))
                return true;
    return false;
}

/// there is number N, then a sequence 1,2,3...
///Now we have to find minimum possible sum difference
/// of two sum set
/// N=3, A=(1,2,3)
/// x={1,2} = 3
/// y={3} = 3
///x-y = 0
ll rem = n%4;
    if(rem == 1 || rem==2)
        cout<<1<<endl;
    else
        cout<<0<<endl;
