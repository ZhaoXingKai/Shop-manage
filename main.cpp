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
class A/*����*/
{
public:
    char name[20];//��Ʒ����//
    float price;//��Ʒ�۸�//
    int all;      //ʣ����//
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
class computer:public A//�������//
{
public:
    int a;//Ӳ�̴�С//
    char cpu[20];//�������ͺ�//
    char gpu[20];//�Կ��ͺ�//
    char size[20];//��ʾ���ͺ�//
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
        cout<<"�������:"<<' '<<name<<' '<<price<<' '<<all<<' '<<a<<' '<<cpu<<' '<<gpu<<' '<<size<<endl;
    }
};
class work:public A//�칫��Ʒ��//
{
public:
     char add[200];//��ע//
     work(){}
     work(char x[],float pp,int aa,char addd[]):A(x,pp,aa)
     {
         strcpy(add,addd);
     }
     void show()
     {
          cout<<"����ѧϰ��:"<<' '<<name<<' '<<price<<' '<<all<<' '<<add<<endl;
     }
};
class life:public A//������Ʒ��//
{
public:
    char come[20];//����//
    life(){}
    life(char x[],float pp,int aa,char comee[]):A(x,pp,aa)
    {
        strcpy(come,comee);
    }
    void show()
    {
        cout<<"������Ʒ��:"<<' '<<name<<' '<<price<<' '<<all<<' '<<come<<endl;
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
        cout<<"ͼ����:"<<' '<<name<<' '<<price<<' '<<all<<' '<<zuozhe<<' ';
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
    printf("��ӭ����������Ʒ����ϵͳ:\n");
    printf("��������Ʒ���ಢ������Ʒ��Ӧ�����ݣ�\n1.�������Ʒ\n2.�칫��Ʒ\n3.������Ʒ\n4.ͼ��\n����0�������\n");
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
    printf("��Ʒ��Ϣ������ʽ�� ��Ʒ�� ��Ʒ�� ��Ʒ����\n");
    printf("˵����\n");
    printf("��ʽ�� 1 ���������Ʒ Ӳ�� ������ �Կ� ��ʾ��\n");
    printf("��������Ʒ��Ϣ,����0Ϊչʾ��Ʒ,����5��Ʒ����,����6�¼�,����-1��������\n");
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
            printf("������Ҫ���׵���Ʒ���������Լ���������\n");
            int zhong,shuliang;
            char ming[20];
            printf("��������Ʒ���\n");
            cin>>zhong;
            printf("\n��������Ʒ���ƣ�\n");
            cin>>ming;
            printf("\n��������Ʒ����:\n");
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
            printf("������ɣ�\n");
        }
        if(i==6)
        {
            printf("������Ҫ�¼ܵ���Ʒ��������\n");
            int zhong;
            char ming[20];
            printf("\n��ɾ����Ʒ���\n");
            cin>>zhong;
            printf("\n��ɾ����Ʒ���ƣ�\n");
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
            printf("�¼����\n");
        }
        if(i==0)
    {
        printf("��ӭ�����̳ǣ�\n");
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
2 Ǧ�� 0.5 100 good
3 ë�� 400 100 �й�
4 ���� 13.2 1000 �� 2016 7 3
1 ����1010 10000 13 128 cpu.02 gpu.02 size.03
*/
