import java.net.*;
import java.io.*;

public class Server {
	
	public static void main(String arg[]) throws IOException
	{
		int portnum=8889;
		ServerSocket serverSocket=null;
		try {
		    serverSocket = new ServerSocket();		    
		    //serverSocket.bind(new InetSocketAddress("192.168.0.1", 0));
		    System.out.println(" listening at ..."+portnum);
		} 
		catch (IOException e) {
		    System.out.println("Could not listen on port:"+portnum);
		    System.exit(-1);
		}
		
		try{
			 serverSocket.bind(new InetSocketAddress("192.168.0.1", 8889));
		}
		catch(IOException e)
		{
			System.out.println("cudnt bind to 192.168.0.1");
			System.exit(-1);
		}
		
		System.out.println(" init listening client socket");
		
		Socket clientSocket = null;
        try {
            clientSocket = serverSocket.accept();
        } catch (IOException e) {
            System.err.println("Accept failed.");
            System.exit(1);
        }
        System.out.println(" client socket init / accept done");
        
        PrintWriter out  = new PrintWriter(clientSocket.getOutputStream(), true);
        BufferedReader in = new BufferedReader(new InputStreamReader(clientSocket.getInputStream()));
        String inputLine, outputLine="hi, welcoming you";
        out.println(outputLine);
        
        while ((inputLine = in.readLine()) != null) {        		
            out.println(inputLine);            
        }
        System.out.println(" read from client");
       out.close();
       in.close();
       clientSocket.close();
       serverSocket.close();       		
	}
}
