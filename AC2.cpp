#include<iostream>
#include<queue>
using namespace std;

//仅支持小写字母的字符串
struct TrieNode{
	int count;
	TrieNode *fail;//指向不匹配字符的前一字符的节点
	TrieNode *next[26];//指针为指向对应字符所在节点

	TrieNode(){
		count=0;
		fail=NULL;
		for(auto &p:next) p=NULL;
	}
};

class ACAutomation{
	TrieNode *root;//前缀树根节点
public:
	ACAutomation(){
		root=new TrieNode();//初始化前缀树根节点
	}

	//将字符串插入前缀树中
	void insert(string &s){
		TrieNode *p=root;
		for(auto &ch:s){
			int index=ch-'a';
			if(p->next[index]==NULL){
				p->next[index]=new TrieNode();
			}
			p=p->next[index];
		}
		p->count++;//末字符表示单词的结束，计数+1
	}

	// 逐层计算每一层的结点的fail指针
	// 当每个结点计算完毕，保证它所有后继都已经计算出来
	void buildACAutomation(){
		queue<TrieNode*> que;
		que.push(root);//队列初始化

		while(!que.empty()){
			TrieNode *pc=que.front();
			que.pop();//弹出栈顶节点指针并处理

			for(int i=0;i<26;i++){
				if(pc->next[i]){
					TrieNode *pt=pc->fail;
					while(pt){
					//寻找当前字符串的最大前缀==后缀
						if(pt->next[i]){
							pc->next[i]->fail=pt->next[i];
							pc->next[i]->count+=pt->next[i]->count;
							break;
						}
						pt=pt->fail;
					}
					//如果没有则执行根节点
					//根节点表示空字符串
					if(pt==NULL) pc->next[i]->fail=root;
					que.push(pc->next[i]);
				}
				//优化 匹配失败时 next[i]一定为空,可以利用起来
				else{
					pc->next[i]=(pc==root)?root:pc->fail->next[i];
				}
			}
		}
	}

	//查询并返回出现个数
	int search(string &s){
		int match=0;
		TrieNode* p=root;
		
		//优化后
		for(auto ch:s){
			int index=ch-'a';
			p=p->next[index];
			match+=p->count;
		}

		return match;
	}
};

int main(){
	ACAutomation ac;
	string str="";

	while(true){
		cin>>str;
		ac.insert(str);
		if(str=="end") break;
	}

	ac.buildACAutomation();
	
	cin>>str;
	cout<<ac.search(str)<<endl;

	return 0;
}
