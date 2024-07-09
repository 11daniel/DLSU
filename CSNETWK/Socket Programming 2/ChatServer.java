import java.net.*;
import java.io.*;

/* Group:
 * Clemente, Daniel Gavrie
 * Yanga, Ian Matthew
 */

public class ChatServer
{
	public static void main(String[] args)
	{
		String[][] details = new String[2][3];
		ServerSocket serverSocket;
		Socket client1;
		Socket client2;

		try 
		{
			int nPort = Integer.parseInt(args[0]);
			serverSocket = new ServerSocket(nPort);
			
			System.out.println("Server: Listening on port " + args[0] + "...");
			client1 = serverSocket.accept();
			
			DataInputStream dis1 = new DataInputStream(client1.getInputStream());
			DataOutputStream dos1 = new DataOutputStream(client1.getOutputStream());
			
			System.out.println("Server: New client connected: " + client1.getRemoteSocketAddress());
			
			String name = dis1.readUTF();
			String message = dis1.readUTF();
			String socketadd = dis1.readUTF();
			details[0][0] = name;
			details[0][1] = message;
			details[0][2] = socketadd;
			
			dos1.writeUTF(details[0][0] + ": Connected to Server at " + details[0][2]);
			
			System.out.println("Server: Listening on port " + args[0] + "...");
			client2 = serverSocket.accept();

			DataInputStream dis2 = new DataInputStream(client2.getInputStream());
			DataOutputStream dos2 = new DataOutputStream(client2.getOutputStream());
			
			System.out.println("Server: New client connected: " + client2.getRemoteSocketAddress());
			
			name = dis2.readUTF();
			message = dis2.readUTF();
			socketadd = dis2.readUTF();
			details[1][0] = name;
			details[1][1] = message;
			details[1][2] = socketadd;
			
			dos2.writeUTF(details[1][0] + ": Connected to Server at " + details[1][2]);
			
			dos1.writeUTF("Message from " + details[1][0] + ": " + details[1][1]);
			dos2.writeUTF("Message from " + details[0][0] + ": " + details[0][1]);
			
			client1.close();
			client2.close();
		
			serverSocket.close();
		}
		catch (Exception e)
		{
			e.printStackTrace();
		}
		finally
		{
			System.out.println("Server: Connection is terminated.");
		}
	}
}