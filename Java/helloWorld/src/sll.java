
public class sll {
	public class Node
	{
		String data;
		Node next;
		Node(String d)
		{
			data = d;
			next = null;
		}
	}
	
	private Node m_head;
	
	sll()
	{
		m_head=null;
	}
	
	void add(String msg)
	{
		if(m_head==null)
			m_head = new Node(msg);
		else
		{
			Node tra =  m_head;
			for(;tra.next!=null;tra=tra.next);
			tra.next = new Node(msg);			
		}		
	}
	
	void display()
	{
		Node tra = m_head;
		myIo obj= new myIo();
		while(tra!=null)
		{
			obj.display(tra.data);
			tra= tra.next;			
		}
	}

}


