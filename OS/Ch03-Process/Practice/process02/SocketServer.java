import java.net.*;
import java.io.*;

/* Socket : IP와 Port로 바인딩된 Pipe */

public class DateServer {
    public static void main(String[] args) throws Exception {
        ServerSocket server = new ServerSocket('port');

        /* Now listen for connections */
        while (true) {
            System.out.println("Listen");

            Socket client = server.accept();
            PrintWriter pout = new PrintWriter(client.getOutputStream(), true);
            
            System.out.println("Connect");

            /* write the Date to the socket */
            pout.println(new java.util.Date().toString());

            /* close the socket and resume listening for connections */
            client.close();
        }
    }
}