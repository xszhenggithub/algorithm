#include<iostream>
using namespace std;

struct TrieNode{
	int count;
	TrieNode* next[26];

	TrieNode(){
		count=0;
		for(int i=0;i<26;i++) next[i]=NULL;
	}
};

class Trie{
	TrieNode* root;
public:
	Trie(){
		root=new TrieNode();
	}

	void insert(string &str){
		TrieNode* p=root;
		for(auto ch:str){
			if(p->next[ch-'a']==NULL){
				p->next[ch-'a']=new TrieNode();
			}
			p=p->next[ch-'a'];
			p->count++;
		}
	}

	int countPrefix(string &str){
		TrieNode *p=root;
		for(auto ch:str){
			if(p->next[ch-'a']==NULL) return 0;
			p=p->next[ch-'a'];
		}
		return p->count;
	}
};

int main(){
	int n;
	string str;
	Trie g;
	cin>>n;
	while(n--){
		cin>>str;
		g.insert(str);
	}

	cin>>n;
	while(n--){
		cin>>str;
		cout<<g.countPrefix(str)<<endl;
	}

	return 0;
}
