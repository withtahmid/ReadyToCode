#include<bits/stdc++.h>
using namespace std;
#define boost ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define endl "\n"
#define ll  long long
#define test_case int t, c = 0; cin>>t; while(t--)
#define int_vector int n; cin>>n; vector<int>v(n); for(int& i : v) cin>>i;
#define ll_vector long long n; cin>>n; vector<long long>v(n); for(long long& i : v) cin>>i;
#define n_loop for(int i = 0; i<n; i++)
#define str_loop string str; cin>>str; for (int i = 0; i < str.size(); ++i)
#define string_str string str; cin>>str;
// Double Precission
const double ESP = 1e-9;
bool isEqual(double a, double b)
{
	return abs(a-b) <= ESP;
}
bool isSmaller(double a, double b)
{
	return b - a > ESP;
}
bool isGreater(double a, double b)
{
	return a - b > ESP;
}

double SQRT(double n){
	double low = 0.0, high = max (1.0, n), result = n;
	int i = 100;
	while(low <= high && i--){
		double mid = low + (high-low) / 2;
		double result = mid*mid;
		if(isEqual(result,n)){
			return mid;
		}else if(result>n){
			high = mid - ESP;
		}else{
			low = mid + ESP;
		}
	}
	return result;
}

bool isPrinmeF(int n){
	if(n<=1){
		return false;
	}
	for(int i = 2; i*i <= n; i++){
		if(n%i == 0){
			return false;
		}
	}
	return true;
}
bool bigMod(string str, int n){
	int rem = 0;
	for (int i = 0; i < str.size(); ++i){
		rem = ((rem*10) + (str[i] - '0'))%n;
	}
	return rem;
}


int GCD(int a, int b){
	if(b == 0){
		return a;
	}
	return GCD(b, a%b);
}

int LCM(int a, int b){
	return (a/__gcd(a,b))*b;
}


//activator

const int N = 1e6 + 5;
bool isPrime[N];
vector<int> primes;
void sieve(){
	for(int i = 1; i <= N; i++){
		isPrime[i] = true;
	}
	isPrime[1] = false;
	for(int i = 4; i <= N; i += 2){
		isPrime[i] = false;
	}
	for(int i = 3; i*i <= N; i+=2){
		if(isPrime[i]){
			for(int j = i*i; j<= N; j+= 2*i){
				isPrime[j] = false;
			}
		}
	}
}

vector<int> divisors;
void generateDivisors(int n){
	divisors.clear();
	for(int i = 1; i*i <= n; i++){
		if(n%i == 0){
			divisors.push_back(i);
			if( i!= (n/i)){
				divisors.push_back(n/i);
			}
		}
	}
}


int NOD[N];
void nod(){
	for(int i = 1; i <= N; i++){
		for(int j = i; j <= N; j+=i){
			NOD[j]++;
		}
	}

}

int SOD[N];
void sod(){
	for(int i = 1; i <= N; i++){
		for(int j = i; j <= N; j+=i){
			NOD[j]+=i;
		}
	}
}
///Returns the complete list of (factor, exponent) pairs
vector<pair<int, int>> prime_factorize_as_pair(int n){
	vector<pair<int, int>> result;
	for (int p : primes){
		if (p * p > n) 
			break;
        if (n % p == 0){
    		int expo = 0;
    		while (n % p == 0){
				++expo;
				n /= p;
			}
			result.push_back(make_pair(p, expo));
		}
	}
    if (n != 1) {
    	result.push_back(make_pair(n, 1));
    }
    return result;
}
///primeFactorWithPower
void primeFactorWithPower(ll n)
{
	int cnt=0;
	while(n%2==0){
		n=n/2;cnt++;
	}
	if(cnt>0)
		cout<<"2^"<<cnt<<" ";
	for(ll i=3;i*i<=n;i+=2)
	{
		int cnt=0;
		while(n%i==0)
		{
			n/=i;
			cnt++;
		}
		if(cnt>0) 
			cout<<i<<"^"<<cnt<<" ";
	}
	if(n>2)cout<<n<<"^1"<<endl;
}

vector<pair<int, int>> factorize_factorial_v2(int n) 
{
	vector<pair<int, int>> result;
	for (auto p : primes) 
	{
		if (p > n) break;
		int expo = 0;
        
        auto n_tmp = n;
        
        auto q = n_tmp / p;while (q > 0) {
           
        expo += q;
        
        n_tmp = q;

        q = n_tmp / p;
        }
        result.push_back({p, expo});
    }
    return result;
}
bool LeapYear_string(string yr)
{
    if(div(yr,400))
       return true;
       else if(div(yr,100))
            return false;
            else if(div(yr,4))
                return true;
    return false;
}

///BigMod
int Bigmod(int base, int power, int mod){
	if(power==0)
		return 1;
	else if(power%2==1){
		int a=base%mod;
		int b=(Bigmod(base, power-1,mod))%mod;
		return (a*b)%mod;
	}
	else{
		int a=(Bigmod(base,power/2,mod))%mod;
		return (a*a)%mod;
	}
}

int multiply(int x, int res[], int res_size){
    int carry = 0;
    for (int i=0; i<res_size; i++){
        int prod = res[i] * x + carry;
        res[i] = prod % 10;  
        carry  = prod/10;    
    }

    while (carry){
        res[res_size] = carry%10;
        carry = carry/10;
        res_size++;
    }
    return res_size;
}

void factorial(int n){
	int MAX = 500;
    int res[MAX];

    res[0] = 1;
    int res_size = 1;

    for (int x=2; x<=n; x++){
        res_size = multiply(x, res, res_size);
    }

    cout << "Factorial of given number is \n";
    for (int i=res_size-1; i>=0; i--)
        cout << res[i];
}



void factorial_of_any_base()
{
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

}

bool basicBinarySearch(vector<int>& v, int value)
{
	int low = 0, high = v.size()-1;
	while(low<=high)
	{
		int mid = (low+high)/2;
		if(v[mid] == value)
		{
			return true;
		}
		else if(v[mid] < value)
		{
			low  = mid+1;
		}
		else
		{
			high = mid-1;
		}
	}
	return false;
}

///Binary Search Index
int binarySearchIndx(int arr[], int l, int r, int x)
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

// Function to convert a number from given base 'b'
// to decimal

int val(char c)
{
    if (c >= '0' && c <= '9')
        return (int)c - '0';
    else return 
        (int)c - 'A' + 10;
}

int toDeci(string str, int base){
	int len = str.size(); int power = 1; // Initialize power of base
	int num = 0;  
	int i;
    for (i = len - 1; i >= 0; i--)
    {
        if (val(str[i]) >= base)
    	{
    		return -1;
    	}
    	num += val(str[i]) * power;
    	power = power * base;
    }

    return num;
}

int charToDeci(char c)
{
	return c - '0';
}



string DecimalToBinary(int n)
{
    string str;
    while(n>0)
    {
        if(n & 1)
            str += '1';
        else
            str += '0';
        n /= 2;
    }
    reverse(str.begin(), str.end());
    return str;
}

//BalancedParentheses
bool isBalancedParentheses(const string& str){
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

bool areBracketsBalanced(string expr){
    stack<char> temp;
        for(int i=0; i<expr.length(); i++)
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
        return temp.empty();
}

///largest area of same base in a Histogram
int getMaxArea(vector<int>v, int n){

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
void decToHexa(int n) 
{ 
	cout << hex << n << endl; 
}

bool isLeapYear(int year)
{

    return (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
}

///// PBDS ////
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> 
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

/////////////////
int main()
{

}