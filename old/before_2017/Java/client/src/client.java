
import java.io.*;
import java.net.*;

public class client {
	public static void main(String []arg) throws IOException
	{
		Socket socket = null;
		PrintWriter out=null;
		BufferedReader in=null;
		try{
			socket = new Socket("192.168.0.1", 0);
			out = new PrintWriter(socket.getOutputStream(),true);
			in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
		} 
		catch (UnknownHostException e) 
		{
			System.out.println("Unknown host: kq6py");
			System.exit(1);
		} 
		catch  (IOException e) {
			System.out.println("No I/O");
			System.exit(1);
		}
		
		BufferedReader stdIn = new BufferedReader(new InputStreamReader(System.in));
		String userInput;

		while ((userInput = stdIn.readLine()) != null) {
			out.println(userInput);
			System.out.println("echo: " + in.readLine());
		}

		out.close();
		in.close();
		stdIn.close();
		socket.close();

	}

}
