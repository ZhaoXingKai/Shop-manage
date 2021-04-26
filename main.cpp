#include<stdio.h>
#include<iostream>
#include<windows.h>
#include<string.h>
using namespace std;
class date
{
public:
    int year,month,day;
    date(){
    year=0;
    month=0;
    day=0;
    }
    date(int a,int b,int c)
    {
        year=a;
        month=b;
        day=c;
    }
    void out()
    {
        cout<<year<<' '<<month<<' '<<day<<endl;
    }
};
class A/*基类*/
{
public:
    char name[20];//商品名称//
    float price;//商品价格//
    int all;      //剩余数//
    A(char x[],float pp,int aa)
    {
        strcpy(name,x);
        price=pp;
        all=aa;
    }
    A(){}
    virtual void show(){}
    virtual void in(){}
};
class computer:public A//计算机类//
{
public:
    int a;//硬盘大小//
    char cpu[20];//处理器型号//
    char gpu[20];//显卡型号//
    char size[20];//显示器型号//
    computer(char x[],float pp,int aa,int qq,char ww[],char ee[],char rr[]):A(x,pp,aa)
    {
        a=qq;
        strcpy(cpu,ww);
        strcpy(gpu,ee);
        strcpy(size,rr);
    }
    computer(){}
    void show()
    {
        cout<<"计算机类:"<<' '<<name<<' '<<price<<' '<<all<<' '<<a<<' '<<cpu<<' '<<gpu<<' '<<size<<endl;
    }
};
class work:public A//办公用品类//
{
public:
     char add[200];//备注//
     work(){}
     work(char x[],float pp,int aa,char addd[]):A(x,pp,aa)
     {
         strcpy(add,addd);
     }
     void show()
     {
          cout<<"工作学习类:"<<' '<<name<<' '<<price<<' '<<all<<' '<<add<<endl;
     }
};
class life:public A//生活用品类//
{
public:
    char come[20];//产地//
    life(){}
    life(char x[],float pp,int aa,char comee[]):A(x,pp,aa)
    {
        strcpy(come,comee);
    }
    void show()
    {
        cout<<"生活用品类:"<<' '<<name<<' '<<price<<' '<<all<<' '<<come<<endl;
    }
};
class book:public A
{
public:
    char zuozhe[20];
    date a;
    book(){}
    book(char x[],float pp,int aa,date &aaa,char zzz[]):A(x,pp,aa)
    {
        a.year=aaa.year;
        a.month=aaa.year;
        a.day=aaa.day;
        strcpy(zuozhe,zzz);
    }
    void show()
    {
        cout<<"图书类:"<<' '<<name<<' '<<price<<' '<<all<<' '<<zuozhe<<' ';
      a.out();
    }
};

void fun(A &p)
{

    p.show();
}
int main()
{

    int i,j1,j2,j3,j4;
    int a12,b12,c12;
    for(int oo=10;oo<=100;oo=oo+10)
    {
    printf("欢迎来到在线商品管理系统:\n");
    printf("请输入商品种类并输入商品对应的数据：\n1.计算机商品\n2.办公用品\n3.生活用品\n4.图书\n输入0代表结束\n");
    printf("loading...\n%d%",oo);
    Sleep(500);
    system("CLS");
    }
   computer yyy1[200];
    j1=0;
    j2=0;
    j3=0;
    j4=0;

    work yyy2[200];
    life yyy3[200];
    book yyy4[200];
    printf("商品信息输入形式如 商品类 商品名 商品数据\n");
    printf("说明：\n");
    printf("形式如 1 计算机类商品 硬盘 处理器 显卡 显示器\n");
    printf("请输入商品信息,输入0为展示商品,输入5商品交易,输入6下架,输入-1结束程序：\n");
    while(1)
    {

        cin>>i;
        char a[20],b[20],c[20],d[20];
        float x;
        int y,z;
        if(i==1)
        {
            cin>>a>>x>>y>>z>>b>>c>>d;
            yyy1[j1]=computer(a,x,y,z,b,c,d);
            j1++;

        }
        if(i==2)
        {
            cin>>a>>x>>y>>d;
            yyy2[j2]=work(a,x,y,d);
            j2++;
        }
        if(i==3)
        {
            cin>>a>>x>>y>>d;
            yyy3[j3]=life(a,x,y,d);
            j3++;
        }
        if(i==4)
        {


            cin>>a>>x>>y>>d>>a12>>b12>>c12;
            date c1(a12,b12,c12);
            yyy4[j4]=book(a,x,y,c1,d);
            j4++;
        }
        if(i==5)
        {
            printf("请输入要交易的商品种类名称以及交易数：\n");
            int zhong,shuliang;
            char ming[20];
            printf("待交易商品类别：\n");
            cin>>zhong;
            printf("\n待交易商品名称：\n");
            cin>>ming;
            printf("\n待交易商品数量:\n");
            cin>>shuliang;
            cout<<endl;
            if(zhong==1)
            {
               for(int l=0;l<j1;l++)
               {
                   if(strcmp(yyy1[l].name,ming)==0)
                   {
                       yyy1[l].all+=shuliang;
                   }
               }
            }
            if(zhong==2)
            {
                 for(int l=0;l<j2;l++)
               {
                   if(strcmp(yyy2[l].name,ming)==0)
                   {
                       yyy2[l].all+=shuliang;
                   }
               }
            }
            if(zhong==3)
            {
                 for(int l=0;l<j3;l++)
               {
                   if(strcmp(yyy3[l].name,ming)==0)
                   {
                       yyy3[l].all+=shuliang;
                   }
               }
            }
            if(zhong==4)
            {
                 for(int l=0;l<j4;l++)
               {
                   if(strcmp(yyy4[l].name,ming)==0)
                   {
                       yyy4[l].all+=shuliang;
                   }
               }
            }
            printf("交易完成！\n");
        }
        if(i==6)
        {
            printf("请输入要下架的商品种类名称\n");
            int zhong;
            char ming[20];
            printf("\n待删除商品类别：\n");
            cin>>zhong;
            printf("\n待删除商品名称：\n");
            cin>>ming;
            if(zhong==1)
            {
               for(int l=0;l<j1;l++)
               {
                   if(strcmp(yyy1[l].name,ming)==0)
                   {
                      strcpy(yyy1[l].name,"SELL OUT!!!    ");
                   }
               }
            }
            if(zhong==2)
            {
                 for(int l=0;l<j2;l++)
               {
                   if(strcmp(yyy2[l].name,ming)==0)
                   {
                        strcpy(yyy2[l].name,"SELL OUT!!!   ");
                   }
               }
            }
            if(zhong==3)
            {
                 for(int l=0;l<j3;l++)
               {
                   if(strcmp(yyy3[l].name,ming)==0)
                   {
                       strcpy(yyy3[l].name,"SELL OUT!!!     ");
                   }
               }
            }
            if(zhong==4)
            {
                 for(int l=0;l<j4;l++)
               {
                   if(strcmp(yyy4[l].name,ming)==0)
                   {
                       strcpy(yyy4[l].name,"SELL OUT!!!     ");
                   }
               }
            }
            printf("下架完成\n");
        }
        if(i==0)
    {
        printf("欢迎来到商城：\n");
        for(int k=0;k<j1;k++)
    {
        fun(yyy1[k]);
    }
    for(int k=0;k<j2;k++)
    {
        fun(yyy2[k]);
    }
    for(int k=0;k<j3;k++)
    {
        fun(yyy3[k]);
    }
    for(int k=0;k<j4;k++)
    {
        fun(yyy4[k]);
    }
        }
        if(i==-1)
        {
            system("CLS");
            printf("ending....");
            Sleep(2000);
            break;
        }

    }
    return 0;
}

/*
1 iPhone 10000 13 128 cpu.01 gpu.02 size.03
2 铅笔 0.5 100 good
3 毛巾 400 100 中国
4 意林 13.2 1000 沈航 2016 7 3
1 联想1010 10000 13 128 cpu.02 gpu.02 size.03
*/
