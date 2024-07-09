import java.net.*;
import java.io.*;

/* Group:
 * Clemente, Daniel Gavrie
 * Yanga, Ian Matthew
 */

public class FileClient
{
	public static void main(String[] args)
	{
		String sServerAddress = args[0];
		int nPort = Integer.parseInt(args[1]);
		
		try
		{
			Socket clientEndpoint = new Socket(sServerAddress, nPort);
			
			System.out.println("Client: Connected to server at " + clientEndpoint.getRemoteSocketAddress());
			
			
			DataOutputStream dosWriter = new DataOutputStream(clientEndpoint.getOutputStream());
			dosWriter.writeUTF("Client: Downloaded file \"Received.txt\"");
			
			
			DataInputStream disReader = new DataInputStream(clientEndpoint.getInputStream());
			System.out.println(disReader.readUTF());
			
			byte[] buffer = new byte[4096];
            int bytesRead;
            try (InputStream is = clientEndpoint.getInputStream();
                 FileOutputStream fos = new FileOutputStream("Receive.txt");
                 BufferedOutputStream bos = new BufferedOutputStream(fos)) {
                while ((bytesRead = is.read(buffer)) != -1) {
                    bos.write(buffer, 0, bytesRead);
                }
			}
			clientEndpoint.close();
		}
		catch (Exception e)
		{
			e.printStackTrace();
		}
		finally
		{
			System.out.println("Client: Connection is terminated.");
		}
	}
}