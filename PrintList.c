
#include"route.h" 

/*�������Ĺ��ܺ���*/
void PrintList(Node * head)
{
    Node * temp=head;
    while (temp) 
    {
        /*����ýڵ��޺�̽ڵ㣬˵���˽ڵ�����������һ���ڵ�*/
        if (temp->next==NULL) 
        {
            printf("%d\n",temp->data);
        }
        else
        {
            printf("%d->",temp->data);
        }
        temp=temp->next;
    }
}


