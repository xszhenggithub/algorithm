#include<iostream>
#include<fstream>
#include<list>
#include<stack>
#include<queue>
#include<iomanip>
using namespace std;

void print(list<int> la)
{
     list<int>::const_iterator p;
     for( p = la.begin();p != la.end();p++)
          cout<< *p<<endl;
          cout<<endl;
 }


int main()
{
    int a,b;
    
//有用的函数----------------------华丽的分割线---------------------------
/*
    cin>>a>>b; 
    swap(a,b);//交换a,b的值 
    cout<<a<<" "<<b<<endl;//十进制输出  
*/ 
    
//输入输出-----------------------华丽的分割线---------------------------
/*
    cin>>oct>>a>>b;//输入 视为八进制
    cout<<hex<<a<<" "<<b<<endl;//十六进制输出
    
    cin>>hex>>a>>b;//输入 视为十六进制 
    cout<<oct<<a<<" "<<b<<endl;//八进制输出 

    char* str ="ABCDEFG";
    cout.write(str+2,4); //输出CDEF 
   
    cin>>oct>>a>>hex>>b;//a以八进制输入,b以十六进制输入 
    cout<<a<<" "<<b<<endl; //a,b以十进制输出 
     
    int m=1234;
    cout<<"设置域宽: "<<endl;
    cout<<setw(3)<<m<<endl;
    cout<<setw(5)<<m<<endl;
    cout<<setw(10)<<m<<endl;
    
    int m=12;
    cout<<"设置填充字符: "<<endl;
    cout<<setfill('0')<<setw(2)<<m<<endl;
    cout<<setfill('0')<<setw(2)<<2<<endl;
    
    //设置时间 
    int h=4,m=3,s=23;
    cout<<setfill('0')<<setw(2)<<h<<":"<<setw(2)<<m<<":"<<setw(2)<<s<<endl;
  
    
    double d = 11.0/3;
    cout<<setiosflags(ios::scientific)<<setprecision(4)<<d<<endl;
*/     
    
    
     
//数组-----------------------华丽的分割线---------------------------
/*
    int* pa  = new int[100];
    memset(pa,1,100*sizeof(int));  //将每个字节置为 1，所以a[1] =0x01010101
    for(int i=0;i<100;i++)
    {
        cout<<hex<<pa[i]<<endl;
    }
    delete []pa;
*/    
    
    
//STL -----------------------华丽的分割线---------------------------
/*  
    //===List==== 
    list<int> la;//链表 
    for(int i=0;i<10;i++)//链表初始化 
    {
        la.push_front(rand());
    }
    print(la);//输出链表 
    la.sort();//链表排序
    print(la);//输出链表
    

    //===Stack====
    stack<int> stk;
    for(int i=0;i<10;i++) stk.push(rand() & 0xFF);//压栈
    cout<<"栈中元素个数:" <<stk.size()<<endl; //栈中元素个数 
    while(!stk.empty())//非空 
    {
         cout<<stk.top()<<endl;//栈顶元素 
         stk.pop();//弹栈 
    }
    
    //===Queue===
    queue<int> que;
    for(int i=0;i<20;i++) que.push(i);  //插入到队尾 
    cout<<"队列中元素个数:" <<que.size()<<endl; //队列中元素个数 
    while(!que.empty())//非空 
    {
         cout<<que.front()<<endl;//栈顶元素 que.back();
         que.pop();//弹出队首元素 
    }
*/    
    
//============================
    char c;
    ifstream fin("f:\\acm\\Dualpal.txt");
    ofstream fout("f:\\out.txt");
    if(!fin) return 1;
    while(!fin.eof())
    {
         fin>>c;
         fout<<c;
    }
    
    cin>>a;
    return 0;
}
