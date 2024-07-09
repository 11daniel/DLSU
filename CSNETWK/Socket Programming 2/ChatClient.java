import java.net.*;
import java.io.*;

/* Group:
 * Clemente, Daniel Gavrie
 * Yanga, Ian Matthew
 */

public class ChatClient
{
	public static void main(String[] args)
	{
		String sServerAddress = args[0];
		int nPort = Integer.parseInt(args[1]);
		
		try
		{
			Socket clientEndpoint = new Socket(sServerAddress, nPort);
			
			System.out.println(args[2] + ": Connecting to server at " + clientEndpoint.getRemoteSocketAddress());
			
			DataOutputStream dosWriter = new DataOutputStream(clientEndpoint.getOutputStream());
			DataInputStream disReader = new DataInputStream(clientEndpoint.getInputStream());
			
			dosWriter.writeUTF(args[2]);
			dosWriter.writeUTF(args[3]);
			dosWriter.writeUTF(clientEndpoint.getRemoteSocketAddress().toString());

			System.out.println(disReader.readUTF());	//connected

			System.out.println(disReader.readUTF());	//message
			
			clientEndpoint.close();
		}
		catch (Exception e)
		{
			e.printStackTrace();
		}
		finally
		{
			System.out.println(args[2] + ": Connection is terminated.");
		}
	}
}