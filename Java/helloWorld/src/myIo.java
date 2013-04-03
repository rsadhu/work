
public class myIo {
	private String m_string;
	myIo(){m_string= "default";}
	myIo(String argv[])
	{
		int i=0;
		while(i< argv.length )
		{
			m_string.concat(argv[i]);		
			i++;			
		}
		
	}
	
	void displayAll()
	{
		System.out.println(m_string);
	}
	
	void display(String msg)
	{
		System.out.println(msg);
	}	

}
