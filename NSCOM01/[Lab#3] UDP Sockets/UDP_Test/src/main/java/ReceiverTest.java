/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */

/**
 *
 * @author danie
 */
import java.util.Scanner;
import java.net.*;

public class ReceiverTest {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        System.out.println("starting Sender program");
        Scanner scanner = new Scanner(System.in);
        DatagramSocket UDPSock;
        int portnum = 0;

        try
        {
              UDPSock = new DatagramSocket(null);
              System.out.print("Socket created. Enter port for binding: ");
              portnum =  Integer.parseInt(scanner.next());
              UDPSock.bind(new InetSocketAddress(portnum));
        }
        catch(Exception e)
        {
              System.out.println("Error creating socket" + e.toString());
              return;
        }
        System.out.println("Socket bound to port "+ portnum);
        
        byte[] packetbuffer = new byte[100];  
        DatagramPacket datagram = new DatagramPacket(packetbuffer, 100);  

        String mesg;
        
        int i;
        for (i = 0; i < 10; i++)
        {

            try
            {         
                UDPSock.setSoTimeout(5000);
                int timeout = UDPSock.getSoTimeout();
                System.out.println("Socket will receive with timeout = " + timeout + "msec");

                UDPSock.receive(datagram);
                mesg = new String(datagram.getData());  
                System.out.println(mesg); 
                i = 10;
            }
            catch(SocketTimeoutException e)
            {
                System.out.println("Receive timeout");
            }
            catch(Exception e)
            {
                System.out.println(e.toString());
            }
            System.out.println("Done receiving. Closing socket now. ");
            UDPSock.close();
        }
        
    }
    
}
