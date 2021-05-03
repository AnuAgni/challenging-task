#include <iostream>
using namespace std;

class Company       //parent class and abstract class
{
    private:
        int pw;     //password to enter building and login for details 
    protected:
        int id;     //helps in attendance and maintaining payroll
    public:
        string name;
        void virtual details()=0;   //pure virtual function
};
class Department:public virtual Company     //inheritance
{
    public:
        string gen; //gender
        int ps;     //present salary
        Department(int id)  //pass by value
        {
            this->id=id;
        }
        void virtual details()
        {
            cout<<"Enter your details \n";
            cout<<"Gender (wont' influence result) ";
            cin>>gen;
        }
        void pass_back(string name,int ps)
        {
            this->name=name;
            this->ps=ps;
        }
      
};
class HRdepart      //HRdepartment
{
    public:
    string emp,name;
    int np,nd,sal,factor,appraise;      //number of projects, number of days
        HRdepart(string emp="HR")
        {
            this->emp=emp;
        }
        void appraisal(int nd)
        {
            this->nd=nd;
            factor=nd/20;
        }
        inline void enter(Department &d)
        {
            this->name=d.name;
            this->sal=d.ps;
        }
        void appraisal()      //appraise salary for HRdepartment employees   //function overloading
        {
            appraise=(factor*sal)/100;
            sal=sal+appraise;
        }
        friend void display(HRdepart h);    //friend function
};
void display(HRdepart h)
{
    cout<<"Name: "<<h.name;
    cout<<"Salary: "<<h.sal;
}

class soft:public HRdepart      //Software Department
{
    public:
        soft(int np)
        {
            this->np=np;
        }
        void appraisal(int nd)     //appraise salary for Software Department employees //funtion overriding
        {
            this->nd=nd;
            factor=nd/20;
            appraise=np*10+(factor*sal)/100;
            sal=sal+appraise;
        }
        void display()
        {
            cout<<"new salary= "<<sal;
        }
        //friend class increase_in_sal;
    
};
/*class increase_in_sal
{
  
};*/
int main()
{
    int np,id,pre,nd,final,ps;
    string emp,name;
    cout<<"Enter ID ";
    cin>>id;
    cout<<"Name: ";
    cin>>name;
    cout<<"Present salary ";
    cin>>ps;
    Company *e=new Department(id);  //dynamic object
    e->details();
    cout<<"Which Department are you from?(HR/Software) ";
    cin>>emp;
    cout<<"Number of days you came? ";
    cin>>nd;
    Department d=Department(id);
    d.pass_back(name,ps);
    if(emp=="HR" || emp=="hr")
    {
     HRdepart h=HRdepart(emp);
     h.enter(d);
     h.appraisal(nd);
     h.appraisal();
     display(h);
    }
    else
    {
        cout<<"enter number of projects done \n";
        cin>>np;
        soft s=soft(np);
        s.appraisal(nd);
        s.display();
    }    
    return 0;
}