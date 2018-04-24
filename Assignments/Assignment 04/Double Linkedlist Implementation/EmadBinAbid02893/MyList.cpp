#include"MyList.h"

MyList::MyList()                                                   ///Constructor implementation
{
    this->head=NULL;
    this->tail=NULL;

}

MyList::~MyList()                                                 ///Destructor implementation
{
    cout<<"Stack destructor called. "<<endl;

    while(head!=NULL)
    {
        Node* temp=head;
        head=head->previous;
        delete temp;
    }
}

MyList::MyList(const MyList& passedList)
{
    this->head=NULL;
    this->tail=NULL;

    Node* temp=passedList.tail;
    while(temp)                             //while(temp!=NULL)
    {
        this->Append(temp->data);
        temp=temp->next;
    }

    //this->GetLength()=passedList.GetLength();
    /*Node* node = passedList.head;
    Node** tail = &head;
    while (node)
    {
    *tail = new Node;
    tail = &tail->next;
    node = node->next;
    }*/
}

void MyList::Append(int data)                                  ///Push() implementation
{
    if(this->head==NULL)
    {
        head=new Node;
        head->data=data;
        head->next=NULL;
        head->previous=NULL;
        tail=head;

    }
    else
    {
        head->next=new Node;
        head->next->previous=head;
        head->next->data=data;
        head->next->next=NULL;
        head=head->next;
    }
}

int MyList::Pop()                                             ///Pop() implementation
{
    if(head!=NULL)
    {
        Node* temp=head;
        int data=head->data;
        head=head->previous;

        if(head!=NULL)
        {
            head->next=NULL;
        }
        return data;
    }
    return 123456789123456789;
}

int MyList::PopAt(int index)
{
    //cout<<GetLength()<<endl;

    if(index<this->GetLength())
    {
        int i=0;
        Node* temp=head;
        while(i<=index)
        {
            if(i==index)
            {
                int data;
                //Node* poppedNode=temp;
                data=temp->data;

                if(temp->next==NULL)
                {
                    data=temp->data;
                    tail=tail->next;
                    return data;
                }
                else if(temp->previous==NULL)
                {
                    data=this->Pop();
                    return data;

                }
                else
                {
                    temp->next->previous=temp->previous;
                    temp->previous->next=temp->next;

                }

                delete temp;
                return data;

            }
            temp=temp->previous;
            i++;
        }

    }
    return 123456789123456789;
}

int MyList::GetLength()
{
    int length=0;

    Node* temp=head;
    while(temp)
    {
        length++;
        temp=temp->previous;
    }
    return length;
}


void MyList::Show()
{
    Node* temp=tail;
    while(temp!=NULL)
    {
        cout<< temp->data<<endl;
        temp=temp->next;
    }
}

MyList MyList::operator=(const MyList& passedMyList)
{
    //MyList copiedList;
    delete this;
    //this=NULL;

    Node* temp=passedMyList.tail;
    while(temp)                             //while(temp!=NULL)
    {
        this->Append(temp->data);
        temp=temp->next;
    }
    return *this;
}

MyList MyList::operator+(int value)
{
    this->Append(value);
    return *this;
}

MyList MyList::operator+(MyList& passedList)
{
    //delete this;

    Node* temp=passedList.head;
    while(temp)
    {
        this->Append(temp->data);
        temp=temp->previous;
    }
    return *this;
}

MyList MyList::operator-(int value)
{
    int counter=0;

    Node* temp=head;
    while(temp)
    {
        //cout<<"HI"<<endl;
        if(temp->data==value)
        {
            this->PopAt(counter);
            counter=0;
            temp=head;
        }

        temp=temp->previous;
        counter++;
    }
    return *this;
}

int MyList::operator[](int index)
{
    if(index>=this->GetLength())
    {
        return tail->data;
    }
    else if(index<0)
    {
        return head->data;
    }
    else
    {
        int i=0;

        Node* temp=tail;
        while(temp)
        {
            if(i==index)
            {
                return temp->data;
                break;
            }
            temp=temp->next;
            i++;
        }
    }
}


ostream& operator<<(ostream& out, const MyList& passedMyList)
{

    out<<"{ ";
    Node* temp=passedMyList.tail;

    while(temp)
    {
        out<< temp->data;
        if(temp!=passedMyList.head)
            out<< ", ";

        temp=temp->next;
    }
    out<< " }";
    return out;
}

bool MyList::operator==(MyList& passedMyList)
{
    if(this->GetLength()==passedMyList.GetLength())
    {
        Node* temp=this->head;
        Node* temp2=passedMyList.head;

        while(temp)
        {
            if(temp->data!=temp2->data)
            {
                return false;
            }
            temp=temp->previous;
            temp2=temp2->previous;
        }
        return true;

    }
    return false;
}







