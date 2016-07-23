#include<iostream>
using namespace std;

struct TrieNode{
	int count;//计算以该字符之前的字符串为前缀的出现个数
	TrieNode* next[26];

	TrieNode(){
		count=0;
		for(int i=0;i<26;i++) next[i]=NULL;
	}
};

class Trie{
	TrieNode* root;//根节点，不对应任何字符，仅作为前缀树入口
public:
	Trie(){
		root=new TrieNode();
	}

	void insert(string &str){
		TrieNode* p=root;
		for(auto ch:str){
			if(p->next[ch-'a']==NULL){//对应节点不存在，则创建
				p->next[ch-'a']=new TrieNode();
			}
			p=p->next[ch-'a'];
			p->count++;
		}
	}

	int countPrefix(string &str){
		TrieNode *p=root;
		for(auto ch:str){
			if(p->next[ch-'a']==NULL) return 0;//如果前缀过长，则返回0
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
