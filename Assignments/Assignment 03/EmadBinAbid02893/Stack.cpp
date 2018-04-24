#include"Stack.h"

Stack::Stack()                                                   ///Constructor implementation
{
    //cout<< "Stack initialized. "<<endl;

    this->head=NULL;
    this->tail=NULL;
    this->tempShape=NULL;
    /*this->destructorCounter=NULL;
    this->pushCounter=NULL;
    this->popCounter=NULL;
    this->drawCounter=NULL;*/
}

Stack::~Stack()                                                 ///Destructor implementation
{
    cout<<"Stack destructor called. "<<endl;

    while(head!=NULL)
    {
        //cout<< destructorCounter<< " element(s) removed. "<<endl;
        //destructorCounter+=1;

        Node* temp=head;
        head=head->previous;
        delete temp;
    }
    delete tempShape;
    /*delete destructorCounter;
    cout<< "destructorCounter deleted! "<<endl;
    delete pushCounter;
    cout<< "pushCounter deleted! "<<endl;
    delete popCounter;
    cout<< "popCounter deleted! "<<endl;*/
}

void Stack::Push(Shape* shape)                                  ///Push() implementation
{
    if(shape!=NULL)
    {
        if(head==NULL)
        {
            //cout<< "In Stack::Push(Shape*)"<< endl;

            //cout<< "\t"<< pushCounter<< "th shape pushed. " <<endl;
            //pushCounter+=1;

            head=new Node;
            head->shape=shape;
            head->next=NULL;
            head->previous=NULL;
            tail=head;

            tempShape=head;
        }
        else
        {
            //cout<< endl<<"In Stack::Push(Shape*)"<< endl;

            //cout<< "\t"<< pushCounter<< "th shape pushed. "<<endl;
            //pushCounter+=1;

            head->next=new Node;
            head->next->previous=head;
            head->next->shape=shape;
            head->next->next=NULL;
            head=head->next;

            tempShape=head;
        }
    }
}

Shape* Stack::Pop()                                             ///Pop() implementation
{
    Shape* shape=NULL;
    if(head!=NULL)
    {
        //cout<<"In Stack::Pop(void)"<< endl;

        //cout<< "\t"<<popCounter<< "th shape popped. "<<endl;
        //popCounter+=1;

        Node* temp=head;
        shape=head->shape;
        head=head->previous;
        tempShape=head;
        if(head!=NULL)
        {
            head->next=NULL;
        }
        delete temp;
    }
    return shape;
}

void Stack::DrawStack(SDL_Renderer* gRenderer)                  ///DrawStack(SDL_Renderer*) implementation
{
    Node* temp=tail;

    //cout<<"In Stack::DrawStack(SDL_Renderer*)"<<endl;

    while(temp!=NULL)
    {
        //cout<< "\t"<< drawCounter<< "th shape drawn. "<<endl;
        //drawCounter+=1;

        temp->shape->Draw(gRenderer);
        temp=temp->next;
    }
    drawCounter=0;
}

void Stack::MoveDown()                                          ///MoveDown() implementation
{
    if(tempShape!=tail)
    {
        //cout<< "In Stack::MoveDown(void)"<<endl;

        Shape* temp=tempShape->shape;
        tempShape->shape=tempShape->previous->shape;
        tempShape->previous->shape=temp;

        tempShape=tempShape->previous;
    }
    else
    {
        cout<<"Tail position reached! "<<endl;
    }

}

void Stack::MoveUp()                                            ///MoveUp() implementation
{
    if(tempShape!=head)
    {
        //cout<< "In Stack::MoveUp(void)"<<endl;
        Shape* temp=tempShape->shape;
        tempShape->shape=tempShape->next->shape;
        tempShape->next->shape=temp;

        tempShape=tempShape->next;
    }
    else
    {
        cout<<"Head position reached! "<<endl;
    }
}




