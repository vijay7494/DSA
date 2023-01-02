#include <iostream>
#define size 10
using namespace std;

 
class hashtable
{
    private:
            struct Employe 
            {
                long int no;
                string name;
                string company;
            } Employe[size];

    public:
            hashtable () 
            {
                for (int i = 0; i < 10; i++)
                    {
	                    Employe[i].no = 0;
	                    Employe[i].name = "--------";
	                    Employe[i].company = "---------";
                    } 
            } 
            long int hash_fun (long int no)
            {
                return (no % size);
            }
  
            void collision (int no, string name, string company, long int key)
            {
                key = key + 1;
                
                if (Employe[key].no == 0)
                {
	                Employe[key].no = no;
	                Employe[key].name = name;
	                Employe[key].company = company;
                }
                else
                {
	                collision (no, name, company, key);
                }
            }
  
            void insert_data ()
            {
                long int no;
                string name;
                string company;
                long int key;
    
                cout << "\nEnter your Employe number :";
                cin >> no;
                cout << "\nEnter your name :";
                cin >> name;
                cout << "\nEnter Company's name :";
                cin >> company;
    
                key = hash_fun (no);
    
                if (Employe[key].no == 0)
                {
	                Employe[key].no = no;
	                Employe[key].name = name;
	                Employe[key].company = company;
                }
                else
                {
	                collision (no, name, company, key);
                }
            }
  
            long int getKey (long int no)
            {
                long int key = hash_fun (no);
    
                for (int i = 0; i != (key - 1); i++)
                {
	                if (Employe[key].no == no)
                    {
	                    return key;
	                }
	                else
	                {
	                    return 0;
	                }
                }
            }
  
            void search_data ()
            {
                int no;
    
                cout << "\nEnter number to be searched : ";
                cin >> no;
    
                long int key = getKey (no);
    
                if (key)
                {
	            cout <<"\n\n*************************************************************";
	            cout << "\nNumber : " << Employe[key].no;
	            cout << "\nName : " << Employe[key].name;
	            cout << "\nCompany : " << Employe[key].company;
	            cout <<"\n\n*************************************************************";
                }
                else
                {
	            cout << "\nNumber does not exist";
                }
            }
  
            void display_data ()
            {
                for (int i = 0; i < size; i++)
                {
	                cout << "\nSr No " << i;
	                cout << "\nNumber : " << Employe[i].no;
	                cout << "\nName : " << Employe[i].name;
	                cout << "\nCompany : " << Employe[i].company;
                    cout <<"\n\n*************************************************************";
                } 
            } 
            void delete_data ()
            {
                int no;
                cout << "\nEnter number to be deleted : ";
                cin >> no;
    
                long int key = getKey (no);
    
                if (key)
                {	
                    Employe[key].no = 0;	
                    Employe[key].name = "------";	
                    Employe[key].company = "--------";
                }
                else
                {
	                cout << "\nNumber does not exist";
                }
            }
};

int main () 
{
    int n = 1;
    int choice;
    hashtable h;

do
    {
        cout << "\n 1.Enter new data";      
        cout << "\n 2.Display data";      
        cout << "\n 3.Search data";      
        cout << "\n 4.delete data";      
        cout << "\n 5.Exit\n";      
        cout << "\nEnter your choice : ";      
        cin >> choice;
      
        switch (choice)
	    {
            case 1:
                
            h.insert_data ();
                
            break;
                
            case 2:
                
            h.display_data ();
                
            break;
                
            case 3:
                
            h.search_data ();
                
            break;
                
            case 4:
                
            h.delete_data ();
                
            break;
                
            case 5:
                
            n = 0;
                
            break;
                
            }
    }while (n);
  
return 0;

}