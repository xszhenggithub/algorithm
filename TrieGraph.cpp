#include<iostream>
#include<queue>
using namespace std;

struct TrieNode{
	int count;//以当前字符为末字符的字符串的数
	TrieNode* fail;//匹配失败的跳转指针
	//若有一个包含当前字符的字符串的最长前后缀匹配，跳转到该前缀的末字符的节点
	//如果没有,则跳转到前缀树的根节点
	TrieNode* next[26];//指向下一个字符的指针

	TrieNode(){
		count=0;
		fail=NULL;
		for(int i=0;i<26;i++) next[i]=NULL;
	}
};

class Trie{
	TrieNode* root;//前缀树根节点，不表示任何字符，仅作为前缀树的进入
public:
	Trie(){
		root=new TrieNode();//输出化为一个空树
	}

	void insert(string &str){
		TrieNode* p=root;
		for(auto ch:str){//依次插入每个字符
			if(p->next[ch-'a']==NULL){//若对应节点不存在，则需要创建
				p->next[ch-'a']=new TrieNode();
			}
			p=p->next[ch-'a'];
		}
		p->count++;//末字符计数自增，表示又有一个以该字符结尾的字符串
	}

	void buildGraph(){
		TrieNode* const border=new TrieNode();//前缀树的边界
		for(auto &ptr:border->next) ptr=root;//并将其所有的next指向root
		root->fail=border;//root的失败指针指向root;

		queue<TrieNode*> que;//层次遍历前缀树来构造前缀图
		que.push(root);//根节点入队

/*
		//或直接处理根节点
		queue<TrieNode*> que;

        for(auto &ptr:root->next){
            if(ptr==NULL) ptr=root;
            else{
                ptr->fail=root;
                que.push(ptr);
            }
        }
*/

		while(!que.empty()){
			TrieNode *p=que.front();//访问队首节点
			que.pop();
			for(int i=0;i<26;i++){
				if(p->next[i]){//如果下一个节点存在，设置下一个节点的相关内容
					TrieNode* pt=p->fail;
					p->next[i]->fail=pt->next[i];//匹配的最大前后缀的前缀的末字符节点
					p->next[i]->count+=pt->next[i]->count;//更新计数，这样可以计算相同的后缀，或用指针实现，依次遍历也可
					que.push(p->next[i]);//以后访问该子树
				}else{//不存在，则跳转到匹配的前后缀的前缀末字符的节点
					p->next[i]=p->fail->next[i]; 
				}
			}
		}

		root->fail=NULL;//释放掉边界并抹除指向其的指针
		delete border;
	}

	int countString(string &str){//遍历并计数
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
	
	//依次输入n个模式串，输入到前缀树中
	cin>>n;
	while(n--){
		cin>>str;
		g.insert(str);
	}

	//根据前缀树构造前缀图
	g.buildGraph();

	//输入主串并输出所有模式串出现的个数
	cin>>str;
	cout<<g.countString(str)<<endl;

	return 0;
}
