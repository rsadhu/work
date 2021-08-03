
public class helloWorld {
	public  static void  main(String args[])
	{
		System.out.println("HelloWorld");
		myIo obj = new myIo(args);
		obj.displayAll();
		myIo obj1 =  new myIo();
		obj1.display("hi i am new to the java");		
		int i=0;
		sll l =  new sll();
		
		String tmp="test";
		
		while(i<10)
		{
			tmp.concat(tmp);
			l.add(tmp);		
			i++;
		}
		
		l.display();
	}

}
