//Queue using stack

import java.util.*;
public class QueueUsingTwoStacks {
	public static void main(String args[])
	{
	    //Taking input using class Scanner
		Scanner sc = new Scanner(System.in);
		
		//Taking input the number of testcases
		int t = sc.nextInt();
		while(t>0)
		{
		    //Creating a new object of class StackQueue
			StackQueue g = new StackQueue();
			
			//Taking input the total number of Queries
			int q = sc.nextInt();
			while(q>0)
			{
				int QueryTyoe = sc.nextInt();
				
				//If QueryTyoe is 1 then
				//we call the Push method
				//of class StackQueue
				//else we call the Pop method
				if(QueryTyoe == 1)
				{
					int a = sc.nextInt();
					g.Push(a);
				}else
				if(QueryTyoe == 2)
				System.out.print(g.Pop()+" ");
			q--;
				
			}
			System.out.println();
		t--;
		}
	}
}
class StackQueue
{
    Stack<Integer> s1 = new Stack<Integer>();
    Stack<Integer> s2 = new Stack<Integer>();

    /* The method insert to push element
       into the queue */
    void Push(int x)
    {
    	s1.push(x);
    }
	
    
    /* The method remove which return the
      element popped out of the queue*/
    int Pop()
    {
    	if (s1.isEmpty()) {
			return -1;
		}
    	while(!s1.isEmpty()) {
    		s2.push(s1.pop());    		
    	}
    	int x = s2.pop();
    	while(!s2.isEmpty()) {
    		s1.push(s2.pop());    		
    	}
    	return x;
    }
}
