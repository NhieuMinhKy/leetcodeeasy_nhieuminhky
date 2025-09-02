//
/*#include<iostream>
#include<cstring>
using namespace std;


	bool isValid(string word) {
		int nguyenam=0,phuam=0,letters=0;
		for(int i=0;i<word.length();i++){
			if((word[i]>=65 && word[i]<=90) || (word[i]>=97 && word[i]<=122) || (word[i]>=48 && word[i]<=57)){
				letters++;
			if(strchr("UEOAIueoai",word[i])!=NULL) nguyenam=1;
			else if((strchr("UEOAIueoai",word[i])==NULL) && ((word[i]>=65 && word[i]<=90) || (word[i]>=97 && word[i]<=122))) phuam=1;
			}
			else return false;
		}
		if(letters>=3 && nguyenam==phuam==1)
			return true;
			return false;
	}


int main(){
	string s;
	cin>>s;
	if(isValid(s)) cout <<"true";
	else cout<<"false";
}*/

//------------------------------------------------------------------------------


/*
#include<iostream>
#include<cstring>
using namespace std;

void xoaspace(string &s,int &n){
	int j=0;
	for(int i=0;i<n;i++){
		if(s[i]!=' ')
		s[j++]=s[i];
	}
	s.resize(j);
	n=j;
}
int myAtoi(string s) {
	  long long ans=0;
	  int n=s.length();
	  if(s[0]==' ') xoaspace(s,n);

	  if(s[0]=='-' && (s[1]>=48&&s[1]<=57)){
		for(int i=1;i<s.length();i++){
			if(s[i]<48||s[i]>57) return -ans;
			else
			ans=ans*10+(s[i]-'0');
		  }
		  return -ans;
	  }

	  else if(s[0]>=48&&s[0]<=57){
		for(int i=0;i<s.length();i++){
			if(s[i]<48||s[i]>57) return ans;
			ans=ans*10+(s[i]-'0');
		  }
		  return ans;
	  }

	  else return ans;

}

int main(){
	string s="-91283472332";  int n=s.length();
	xoaspace(s,n);

	int x=myAtoi(s);
	cout<<x;
}*/

//------------------------------------------------------------------------------
//#9.Palindrome Number.
/*
#include<iostream>
#include<string>
#include <algorithm>
using namespace std;
bool isPalindrome(int x){
	if(x<0) return false;
	int y=0;
	int z=x;
	while(x!=0){
		y=y*10+x%10;
		x/=10;
	}
	cout<<y;
	if (z==y) return true;
	return false;
}

int main(){
	int x=-121;
	if(isPalindrome(x)) cout<<"True";
	else cout<<"False";
}
*/


//--------------------------------------------------------------------------------------
//#13.Roman to Interger.
/*
#include<iostream>
#include<string>
using namespace std;

int romanToInt(string s) {
  int n=s.length();
  int a[n]={};
  int j=0;
  for(int i=0;i<n;i++){
	switch(s[i]){
		case 'I':
			a[j++]=1;
			break;
		case 'V':
			a[j++]=5;
			break;
		case 'X':
			a[j++]=10;
			break;
		case 'L':
			a[j++]=50;
			break;
		case 'C':
			a[j++]=100;
			break;
		case 'D':
			a[j++]=500;
			break;
		case 'M':
			a[j++]=1000;
			break;
	  }
  }
  long long ans=0;a[j]=0;
  for(int i=0;i<j;i++){
	if(a[i]>=a[i+1]) ans+=a[i];
	else ans-=a[i];
  }
  cout <<ans;
  return ans;
}

int main(){
	string s="XIV";
	long long ans=romanToInt(s);
	//cout<<ans;
}*/



//--------------------------------------------------------------------------------------------
//#14.Longest Common Prefix.
/*#include<iostream>
#include<string>
#include<vector>
using namespace std;

string longestCommonPrefix(vector<string>& strs) {
	string ans="";
		if(strs[0]=="")return ans;
	int n=strs.size();
	for(int i=0;i<strs[0].size();i++){
		char curchar=strs[0][i];
		for(int j=1;j<n;j++){
			if(curchar!=strs[j][i] || i>=strs[j].size())  return ans;
		}
		ans+=curchar;
	}
	return ans;
}

int main(){
	vector<string> strs;
strs.push_back("flower");
strs.push_back("flower");
strs.push_back("flower");
	string a=longestCommonPrefix(strs);
	cout<<a;
}*/


//-----------------------------------------------------------------------------------
//#20.Valid parentheseses              STACK
/*#include<iostream>
#include<stack>
#include<string>
using namespace std;

bool isValid(string s){
	int n=s.length();
	stack<char>ans;
	for(int i=0;i<n;i++){
		if(s[i]=='(' || s[i]=='[' || s[i]=='{') ans.push(s[i]);
		else{
			if(ans.empty())return false;//   ""
			else if((s[i]==')' && ans.top()=='(') ||
					(s[i]=='}' && ans.top()=='{') ||
					(s[i]==']' && ans.top()=='[') ) ans.pop();
			else return false; // "(}"
		}
	}
	if(ans.empty()) return true;
	else return false;
}

int main(){
	string s="())";
	if(isValid(s)) cout<<"True";
	else cout<<"False";
}*/




//---------------------------------------------------------------------------------------
//#21. Merge Two Sorted Lists
#include<iostream>
using namespace std;
struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x): val(x),next(NULL){}
};

ListNode* createList(int arr[], int n) {
	if (n == 0) return NULL;
	ListNode* head = new ListNode(arr[0]);
	ListNode* tail = head;
	for (int i = 1;i < n;i++) {
		tail->next =new ListNode(arr[i]);
		tail = tail->next;
	}
	return head;
}

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
	ListNode dummy(0);//fake node
	ListNode* tail = &dummy;
	while (list1 && list2) {
		if (list1->val < list2->val) {
			tail->next = list1;
			list1 = list1->next;
		}
		else {
			tail->next = list2;
			list2 = list2->next;
		}
		tail = tail->next;
	}
	if (list1)tail->next = list1;
	else tail->next = list2;
	return dummy.next;
}

void printList(ListNode* head) {
	while (head != NULL) {
		cout << head->val;
		if (head->next) cout << "->";
		head = head->next;
	}
}

int main() {
	// Test
	int arr1[] = { 1, 2, 4 };
	int arr2[] = { 1, 3, 4 };

	ListNode* list1 = createList(arr1, 3);
	ListNode* list2 = createList(arr2, 3);
	ListNode* merged = mergeTwoLists(list1, list2);
	printList(merged);
}



//----------------------------------------------------------------------------
//#26.Remove Duplicates from sorted array
/*
#include<string>
#include<vector>
#include<iostream>
using namespace std;
int removeDuplicates(vector<int>& nums) {
		int n=nums.size();
		int k=1;//so luong phan tu cua nums sau
		int x=nums[0];
		for(int i=1;i<n;i++){
			if(nums[i]!=x){
				nums[k]=nums[i];
				k++;
				x=nums[i];
			}
			else nums[i]=NULL;
		}
	return k;
}

int main(){
	vector<int> nums(4);  // Tao vector có 4 phan tu
nums[0] = 1;
nums[1] = 1;
nums[2] = 2;
nums[3] =3 ;
	int k=removeDuplicates(nums);
	cout<<k<<","<<" nums = [";
	for(int i=0;i<k;i++){
		cout<<nums[i];
		if(i!=k-1) cout<<",";
	}
	cout<<"]";
}*/


//--------------------------------------------------------------------------
//#27.REOMVE ELEMENT
/*
#include<string>
#include<vector>
#include<iostream>
using namespace std;
int removeElement(vector<int>& nums, int val) {
	int n = nums.size();
	int k = 0;
	for (int i = 0;i < n;i++) {
		if (nums[i] != val) {
			nums[k] = nums[i];
			k++;
		}
		else nums[i] = NULL;
	}
	return k;
}

int main() {
	vector<int>nums(4);
	nums[0] = 1;
	nums[1] = 1;
	nums[2] = 2;
	nums[3] = 3;
	int k = removeElement(nums, 1);
	cout << k << ", nums = [";
	for (int i = 0;i < k;i++) {
		cout << nums[i];
		if (i != k - 1) cout << ",";
	}
	cout << "]";
}*/





//--------------------------------------------------------------------------------------------------------
//#28.FIND THE INDEX OF THE FIRST OCCURRENCE IN A STRING
/*#include<string>
#include<iostream>
using namespace std;
int strStr(string haystack, string needle) {
	unsigned int pos = haystack.find(needle);//giong strstr trong c;
	return pos;
}
int main() {
	string a = "abcd";
	string b = "cdef";
	int pos=strStr(a, b);
	cout << pos;
}*/





//----------------------------------------------------------------------------------------------------
//#35.SEARCH INSERT POSITION.
/*#include<iostream>
#include<vector>
using namespace std;
int searchInsert(vector<int>& nums, int target) {
	int n = nums.size();
	int l = 0, r = n - 1, m=0;
	if (target > nums[r]) return n;
	else if (target < nums[0]) return 0;
	while (l <= r) {
		 m = (r + l) / 2;
		if (nums[m] == target) return m;	
		else if (target > nums[m]) l = m + 1;
		else r = m - 1;
	}
	if ( target > nums[m] && target < nums[r]) return r;
	else if ( target >nums[r] && target < nums[l]) return l;
	else return l + 1;
}
int main() {
	vector<int> nums = { 1, 3, 5, 6 };
	int target = 7;
	int ans = searchInsert(nums, target);
	cout << ans;
}*/



//----------------------------------------------------------------------------------------------------
//#35.SEARCH INSERT POSITION.
/*
#include<iostream>
#include<vector>
using namespace std;
int countHillValley(vector<int>& nums) {
	int n = nums.size();
	int k = 0;
	for (int i = 0;i < n-1;i++) {
		if (nums[i] != nums[i + 1])
			nums[k++] = nums[i];
	}
	nums[k++] = nums[n - 1];//add phan tu cuoi cung
	int cnt = 0;
	for (int i = 1;i < k - 1;i++) {
		int m = i, l = m - 1, r = m + 1;
		if ((nums[m] > nums[l] && nums[m] > nums[r]) || (nums[m] < nums[l] && nums[m] < nums[r]))
			cnt++;
	}
	return cnt;
}
int main() {
	vector<int>nums = { 2,4,1,1,6,5 };
	int ans = countHillValley(nums);
	cout << ans;
}*/



//----------------------------------------------------------------------------------------------------
//#58.LENGTH OF LAST WORD.
/*
#include<iostream>
#include<string>
using namespace std;
int lengthOfLastWord(string s) {
	int n = s.length(),cnt=0;
	if (s[n - 1] == ' ') {
		while (s[n - 1] == ' ') {
			s.pop_back();
			n--;
		}
	} 
	while (n >= 1 && s[n-1] != ' '  ) {
		cnt++;
		n--;
	}
	return cnt;
}
int main(){
	string s = "aa"; 
	int ans=lengthOfLastWord(s);
	cout << ans;
}*/




//----------------------------------------------------------------------------------------------------
//#66.PLUS ONE. 
/*
#include<iostream>
#include<vector>
using namespace std;
vector<int> plusOne(vector<int>& digits) {
	unsigned int n = digits.size(); 
	for (int i = n - 1;i >= 0;i--) {
		if (digits[i] != 9) {
			digits[i]++;
			return digits;
		}
		else digits[i] = 0;
	}
	digits.insert(digits.begin(), 1);
	return digits;
}
int main() {
	vector<int>a = {1,9};
	vector<int>ans = plusOne(a);
	for (int i : ans) cout << i;
}
*/







//----------------------------------------------------------------------------------------------------
//#67.ADD BINARY. 
/*
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string addBinary(string a, string b) {
	string ans = "";
	int i = a.size() - 1, j = b.size() - 1;
	int nho = 0;
	while (i >= 0 || j >= 0 || nho != 0) {
		int sum = 0;
		sum += nho;
		if (i >= 0)sum += a[i--] - '0';
		if (j >= 0)sum += b[j--] - '0';
		ans += (sum % 2) + '0';
		nho = sum / 2;
	}
	reverse(ans.begin(), ans.end());
	return ans;
}
int main() {
	string a = "11", b = "1";
	string ans = addBinary(a, b);
	cout << ans;
}*/







//-------------------------------------------------------------------------
//69.SQRT(x).
/*
#include<iostream>
using namespace std;
int mySqrt(int x) {
	if (x == 1 || x == 0) return x;
	else if (x == 2||x==3) return 1;
	else {
		for (int i = 1;i <= x / 2;i++) {
			if (i * i == x) return i; 
			else if (i * i > x) return i - 1;
		}
	}
	return NULL;
}
int main() {
	int x = 2147483647;
	int ans = mySqrt(x);
	cout << ans;
}*/





//--------------------------------------------------------------------------
//70.CLIMBING STAIRS.
/*
#include<iostream>
#include<vector>
using namespace std;
int climbing(int n) {
	if (n <= 2) return n;
	vector<int> fib(n + 1);
	fib[1] = 1;
	fib[2] = 2;
	for (int i = 3;i <= n;i++) {
		fib[i] = fib[i - 1] + fib[i - 2];
	}
	return fib[n];
}
int main() {
	int n = 5;
	int ans = climbing(n);
	cout << ans;
}*/




//----------------------------------------------------------------------------
//88.MERGE SORTED ARRAY.                  TWO POINTERS
/*#include<iostream>
#include<vector>
using namespace std;
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
	int i = m - 1, j = n - 1, k = m + n - 1;
	while (i >= 0 && j >= 0) {
		if (nums1[i] >= nums2[j]) nums1[k--] = nums1[i--];
		else nums1[k--] = nums2[j--];
	}
	while (j >= 0) nums1[k--] = nums2[j--];
	for (int i = 0;i < m+n;i++) {
		cout << nums1[i];
	}
}
int main() {
	int m = 3, n = 3;
	vector<int>nums1 = { 1,2,3,0,0,0 };
	vector<int>nums2 = { 2,5,6 };
	merge(nums1, m, nums2, n);
}*/