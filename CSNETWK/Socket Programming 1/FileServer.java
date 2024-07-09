import java.net.*;
import java.io.*;

/* Group:
 * Clemente, Daniel Gavrie
 * Yanga, Ian Matthew
 */

public class FileServer
{
	public static void main(String[] args)
	{
		int nPort = Integer.parseInt(args[0]);
		System.out.println("Server: Listening on port " + nPort + "...");
		ServerSocket serverSocket;
		Socket serverEndpoint;

		try 
		{
			serverSocket = new ServerSocket(nPort);
			serverEndpoint = serverSocket.accept();
			
			System.out.println("Server: New client connected: " + serverEndpoint.getRemoteSocketAddress());
			
			DataInputStream disReader = new DataInputStream(serverEndpoint.getInputStream());
			System.out.println(disReader.readUTF());

			
			DataOutputStream dosWriter = new DataOutputStream(serverEndpoint.getOutputStream());
			dosWriter.writeUTF("Server: Sending file \"Download.txt\" (12 bytes)");
			
			File file = new File("Download.txt");
			byte[] fileBytes = new byte[(int) file.length()];

			try (FileInputStream fis = new FileInputStream(file);
					BufferedInputStream bis = new BufferedInputStream(fis);
					OutputStream os = serverEndpoint.getOutputStream()) {

				bis.read(fileBytes, 0, fileBytes.length);
				os.write(fileBytes, 0, fileBytes.length);
				os.flush();

				System.out.println("File sent to client");
			}

			serverSocket.close();
			serverEndpoint.close();
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