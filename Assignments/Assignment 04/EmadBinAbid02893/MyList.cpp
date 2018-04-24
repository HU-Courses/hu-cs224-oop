#include"MyList.h"

MyList::MyList()
{
    this->head=nullptr;
}

MyList::MyList(int value)
{
    MyList newMyList;

    for(int i=0; i<value; i++)
        newMyList.Append(123456789123456789);                   ///Appending arbitrary value
}

MyList::MyList(const MyList& passedMyList)
{
    this->head=nullptr;

    MyList interimMyList;
    Node* temp=passedMyList.head;
    while(temp!=nullptr)
    {
        interimMyList.Append(temp->data);
        temp=temp->next;
    }

    temp=nullptr;

    Node* temp2=interimMyList.head;
    while(temp2!=nullptr)
    {
        this->Append(temp2->data);
        temp2=temp2->next;
    }
}

MyList::~MyList()
{
    ///cout<< "MyList destructor called."<< endl;
    while(head!=nullptr)
    {
        this->Pop();
    }
    head=nullptr;
}

void MyList::Append(int data)
{
    if(head==nullptr)
    {
        head=new Node;
        head->data=data;
        head->next=nullptr;
    }
    else
    {
        Node* temp=head;
        head=new Node;
        head->data=data;
        head->next=temp;
    }
}

int MyList::Pop()
{
    if(head!=nullptr)
    {
        Node* temp=head;
        head=head->next;

        int data=temp->data;

        delete temp;
        temp=nullptr;

        return data;
    }
    return 123456789123456789;                      ///returning arbitrary value to indicate list is empty
}

int MyList::PopAt(int index)
{
    if(index==GetLength())
    {
        this->Pop();
    }
    else
    {
        if(index<this->GetLength())
        {
            Node* temp=head;
            Node* temp2=nullptr;

            if(head!=nullptr)
            {
                for(int i=0; i<GetLength()-index; i++)
                {
                    temp2=temp;
                    temp=temp->next;
                }
            }
            temp2->next=temp->next;
            int data=temp->data;
            delete temp;
            return data;
        }

    }
    return 123456789123456789;
}

int MyList::GetLength()
{
    int length=0;
    Node* temp=head;
    while(temp!=nullptr)
    {
        length++;
        temp=temp->next;
    }
    return length;
}

void MyList::Show()
{
    Node* temp=head;
    while(temp!=nullptr)
    {
        cout<< temp->data<<endl;
        temp=temp->next;
    }
}

MyList MyList::operator=(const MyList& passedMyList)
{
    /*MyList newMyList(passedMyList);
    //*this=newMyList;
    //return *this;
    return newMyList;*/
    //this->head=nullptr;
    this->~MyList();
    delete this;                    ///Important

    MyList interimMyList;
    Node* temp=passedMyList.head;
    while(temp!=nullptr)
    {
        interimMyList.Append(temp->data);
        temp=temp->next;
    }

    temp=nullptr;

    Node* temp2=interimMyList.head;
    while(temp2!=nullptr)
    {
        this->Append(temp2->data);
        temp2=temp2->next;
    }
    return *this;
}

MyList MyList::operator+(int data)
{
    MyList copyList=*this;

    copyList.Append(data);
    return copyList;
}

MyList MyList::operator+(const MyList& passedMyList)
{
    MyList copyList=*this;

    MyList newList1;
    //cout<<"HI";
    newList1=passedMyList;

    MyList newList2;

    while(newList1.head)
        newList2.Append(newList1.Pop());

    while(newList2.head)
        copyList.Append(newList2.Pop());

    return copyList;
}

MyList MyList::operator-(int value)
{
    int counter=0;
    Node* temp=head;

    while(temp)
    {
        if(temp->data==value)
        {
            this->PopAt(counter);
            temp=head;
            counter=0;
        }

        temp=temp->next;
        counter++;
    }
    return *this;
}

int& MyList::operator[](int index)
{
    if(this->GetLength()!=0)
    {
        if((index%this->GetLength())==0)
        {

            Node* temp=head;

            int data;
            while(temp)
            {
                data=temp->data;
                temp=temp->next;
            }

            return data;
        }
        /*else if(index<0)
        {
            return this->head->data;
        }*/
        else
        {
            int counter=0;
            Node* temp=head;

            if(index>0)
            {
                while(temp)
                {
                    if(counter==GetLength()-(index%GetLength())-1)
                    {
                        return temp->data;
                    }
                    temp=temp->next;
                    counter++;
                }
            }
            else if(index<0)
            {
                while(temp)
                {
                    if(counter==(GetLength()-(index%GetLength())-1-GetLength()))
                    {
                        return temp->data;
                    }
                    temp=temp->next;
                    counter++;
                }
            }

        }
    }
    else
    {
        for(int i=0; i<=index; i++)
            this->Append(0);          /**if it is an empty list, accessing members of it will create a new list of length index+1
                                        My custom implementation**/
        return this->head->data;
    }

}

ostream& operator<<(ostream& out, const MyList& passedMyList)
{
    MyList newList1;
    newList1=passedMyList;

    MyList newList2;

    while(newList1.head)
        newList2.Append(newList1.Pop());

    out<< "{";

    while(newList2.head)
    {
        out<< newList2.Pop();
        if(newList2.head!=nullptr)
        out<< ", ";
    }
    out<< "}";

    return out;
}

bool MyList::operator==(MyList& passedMyList)
{
    if(this->GetLength()==passedMyList.GetLength())
    {
        Node* temp1=this->head;
        Node* temp2=passedMyList.head;

        while(temp1)
        {
            if(temp1->data!=temp2->data)
                return false;
            temp1=temp1->next;
        }
        return true;
    }
    return false;
}


















