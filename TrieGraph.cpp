#include<iostream>
#include<queue>
using namespace std;

struct TrieNode{
	int count;
	TrieNode* fail;
	TrieNode* next[26];

	TrieNode(){
		count=0;
		fail=NULL;
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
		}
		p->count++;
	}

	void buildGraph(){
		TrieNode* const border=new TrieNode();
		for(auto &ptr:border->next) ptr=root;
		root->fail=border;

		queue<TrieNode*> que;
		que.push(root);

		while(!que.empty()){
			TrieNode *p=que.front();
			que.pop();
			for(int i=0;i<26;i++){
				if(p->next[i]){
					TrieNode* pt=p->fail;
					p->next[i]->fail=pt->next[i];
					p->next[i]->count+=pt->next[i]->count;
					que.push(p->next[i]);
				}else{
					p->next[i]=p->fail->next[i];
				}
			}
		}

		root->fail=NULL;
		delete border;
	}

	int countString(string &str){
		int count=0;
		TrieNode *p=root;
		for(auto ch:str){
			p=p->next[ch-'a'];
			count+=p->count;
		}
		return count;
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

	g.buildGraph();

	cin>>str;
	cout<<g.countString(str)<<endl;

	return 0;
}
