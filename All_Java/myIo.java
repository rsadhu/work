import java.util.*;


public class myIo
{
    public Vector<String> arr;

    public myIo()
    {

    }
    public myIo(String argv[])
    {
	try{
        int i=0;
        while(argv[i].isEmpty()){
            arr.add(argv[i]);
            i++;
        }
	}
	catch(Exception v)
	{
	 System.out.println("constructor Exception");
	 System.out.println(v.toString());
	
	}


    }

    void display(String msg)
    {
        System.out.println(" hello world\n");
    }

    void displayAll()
    {
	try{
        Iterator it = arr.iterator();
        for (; it.hasNext();)
            System.out.println(it.next());
	}catch(Exception e)
	{
			 System.out.println("displayAll Exception");
	}
    }


}

