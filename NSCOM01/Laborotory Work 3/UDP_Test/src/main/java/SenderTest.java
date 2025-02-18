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

public class SenderTest {

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
        
        DatagramPacket datagram;
        int recvport;
        String mesg; 

        System.out.print("Enter recipient port number: ");
        recvport = scanner.nextInt();

        System.out.print("Type message for sending: ");
        mesg = scanner.next();

              try
        {
        datagram= new DatagramPacket(mesg.getBytes(), mesg.length(), InetAddress.getByName("127.0.0.1"), recvport); 

        UDPSock.send(datagram);
        }
        catch(Exception e)
        {
           System.out.println("Failed to send: " + e.toString());
        }

    }
    
}
