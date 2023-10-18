#include <stdio.h>
int Queue[100],rear,element,choice=0,n,front=-1;
void enqueue();
int dequeue();
void display();
void main ()
{
printf("\t\t*********Queue operations using array*********\n");
printf("Enter the number of elements in the queue ");
scanf("%d",&n);
printf("\n----------------------------------------------\n");
while(choice != 4)
{
printf("Chose one from the below options...\n");
printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit");
printf("\n Enter your choice: ");
scanf("%d",&choice);
switch(choice)
{
case 1:
{
printf("Inter the element: ");
scanf("%d", &element);
enqueue(element);
break;
}
case 2:
{
dequeue();
break;
}
case 3:
{
display();
break;
}
case 4:
{
printf("Exiting....");
break;
}
default:
{
printf("Please Enter valid choice ");
}
};
}
}
void enqueue (int element)
{
if(rear == n){
printf("Queue is FULL.\n");
return;
}
if(front == -1){
front = 0;
}
rear++;
Queue[rear] = element;
}
int dequeue ()
{
if(front == -1 || front>rear){
printf("Queue is Empty.\n");
return -1;
}
int element = Queue[front];
front++;
return element;
}
void display()
{
for (int i=front+1;i<=rear;i++)
{
printf("%d\n",Queue[i]);
}
if(front == -1)
{
printf("Queue is empty...\n");
}
}
