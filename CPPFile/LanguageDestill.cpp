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
    
//���õĺ���----------------------�����ķָ���---------------------------
/*
    cin>>a>>b; 
    swap(a,b);//����a,b��ֵ 
    cout<<a<<" "<<b<<endl;//ʮ�������  
*/ 
    
//�������-----------------------�����ķָ���---------------------------
/*
    cin>>oct>>a>>b;//���� ��Ϊ�˽���
    cout<<hex<<a<<" "<<b<<endl;//ʮ���������
    
    cin>>hex>>a>>b;//���� ��Ϊʮ������ 
    cout<<oct<<a<<" "<<b<<endl;//�˽������ 

    char* str ="ABCDEFG";
    cout.write(str+2,4); //���CDEF 
   
    cin>>oct>>a>>hex>>b;//a�԰˽�������,b��ʮ���������� 
    cout<<a<<" "<<b<<endl; //a,b��ʮ������� 
     
    int m=1234;
    cout<<"�������: "<<endl;
    cout<<setw(3)<<m<<endl;
    cout<<setw(5)<<m<<endl;
    cout<<setw(10)<<m<<endl;
    
    int m=12;
    cout<<"��������ַ�: "<<endl;
    cout<<setfill('0')<<setw(2)<<m<<endl;
    cout<<setfill('0')<<setw(2)<<2<<endl;
    
    //����ʱ�� 
    int h=4,m=3,s=23;
    cout<<setfill('0')<<setw(2)<<h<<":"<<setw(2)<<m<<":"<<setw(2)<<s<<endl;
  
    
    double d = 11.0/3;
    cout<<setiosflags(ios::scientific)<<setprecision(4)<<d<<endl;
*/     
    
    
     
//����-----------------------�����ķָ���---------------------------
/*
    int* pa  = new int[100];
    memset(pa,1,100*sizeof(int));  //��ÿ���ֽ���Ϊ 1������a[1] =0x01010101
    for(int i=0;i<100;i++)
    {
        cout<<hex<<pa[i]<<endl;
    }
    delete []pa;
*/    
    
    
//STL -----------------------�����ķָ���---------------------------
/*  
    //===List==== 
    list<int> la;//���� 
    for(int i=0;i<10;i++)//�����ʼ�� 
    {
        la.push_front(rand());
    }
    print(la);//������� 
    la.sort();//��������
    print(la);//�������
    

    //===Stack====
    stack<int> stk;
    for(int i=0;i<10;i++) stk.push(rand() & 0xFF);//ѹջ
    cout<<"ջ��Ԫ�ظ���:" <<stk.size()<<endl; //ջ��Ԫ�ظ��� 
    while(!stk.empty())//�ǿ� 
    {
         cout<<stk.top()<<endl;//ջ��Ԫ�� 
         stk.pop();//��ջ 
    }
    
    //===Queue===
    queue<int> que;
    for(int i=0;i<20;i++) que.push(i);  //���뵽��β 
    cout<<"������Ԫ�ظ���:" <<que.size()<<endl; //������Ԫ�ظ��� 
    while(!que.empty())//�ǿ� 
    {
         cout<<que.front()<<endl;//ջ��Ԫ�� que.back();
         que.pop();//��������Ԫ�� 
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
