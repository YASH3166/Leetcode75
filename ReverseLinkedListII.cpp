#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define ff                 first
#define ss                 second
#define endl               "\n"
#define ll                 long long
#define ld                 long double
#define loop(a, b, c)      for(ll (a) = (b); (a)<=(c); (a)++)
#define looprev(a, b, c)   for(ll (a) = (b); (a)>=(c); (a)--)
#define pb                 push_back
#define mp                 make_pair
#define pii                pair<ll, ll>
#define vi                 vector<ll>
#define mii                map<ll, ll>
#define ump                unordered_map<ll, ll>
#define pqb                priority_queue<ll>
#define pqs                priority_queue<int, vi, greater<ll> >
#define setbits(x)         __builtin_popcountll(x)
#define zrobits(x)         __builtin_ctzll(x)
#define mod                1000000007
#define inf                1e18
#define ps(x, y)           fixed<<setprecision(y)<<x
#define mk(arr,n,type)     type *arr = new type[n];
#define w(t)               int x; cin>>x; while(x--)
// mt19937                    rng(chrono::steady_clock::now,time_since_epoch(),count());
typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> pbds;

    
void file_i_o(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	/* #ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif */
}


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:

	ListNode* reverse(ListNode* head){
		ListNode* prev = NULL, *next = NULL, *current = head;
		while(current != NULL){
			next = current->next;
			current->next = prev;
			prev = current;
			current = next;
		}

		return prev;
	}


 //    ListNode* reverseBetween(ListNode* head, int left, int right) {
 //  		ListNode* current = head, *prev = NULL;
 //  		int count = 1;
 //  		while(count != left) {
 //  			prev = current;
 //  			current = current->next;
 //  			count++;
 //  		}      

 //  		ListNode* start = current;
 //  		while(count != right){
 //  			current = current->next;
 //  			count++;
 //  		}

 //  		ListNode* rest = current->next;
 //  		current->next = NULL;

 //  		ListNode* newHead = reverse(start);
 //  		if(prev != NULL){
 //  			prev->next = newHead;
 //  		}
 //  		current = newHead;
 //  		while(current->next != NULL){
 //  			current = current->next;
 //  		}

 //  		current->next = rest;

 //  		if(left == 1){
 //  			return newHead;
 //  		}
 //  		else{
 //  			return head;
 //  		}
 //    }



	ListNode* reverseBetween(ListNode* head, int left, int right) {
		if(head == NULL or left == right) return head;

		ListNode* prev = NULL, *tail = NULL, *temp = NULL;
		ListNode dummy(NULL);
		prev = &dummy;
		dummy.next = head;

		for(int i = 0; i < left -1; i++){
			prev = prev -> next;
		}


		tail = prev -> next;
		for(int i = 0; i < right-left; i++){
			temp = prev -> next;
			prev -> next = tail -> next;
			tail -> next = tail -> next -> next;
			prev -> next -> next = temp;
		}

		return dummy.next;
	}


};



int main(int argc, char const *argv[])
{

	file_i_o();

	clock_t start, end;
    start = clock();

	w(t){

	/*  Write Code Here  */

	}

	end = clock();
	
	double time_taken=double(end-start)/double(CLOCKS_PER_SEC);
    cerr<<"\nTime : "<<fixed<<time_taken<<setprecision(5)<<" s \n";
    cerr<<"\n"<< "Coded By : S!r Black-D3vil" <<"\n";

	return 0;
}