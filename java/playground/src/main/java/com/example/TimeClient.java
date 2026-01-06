package com.example;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.InetSocketAddress;
import java.net.Socket;

public class TimeClient {

    private final String host;
    private final int port;

    public TimeClient(String host, int port) {
        this.host = host;
        this.port = port;
    }

    public String getTime() throws IOException {
        Socket socket = null;
        try {
            socket = new Socket();
            socket.connect(new InetSocketAddress(host, port), 5000);

            BufferedReader in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
            String time = in.readLine();

            return time;
        } finally {
            if (socket != null && !socket.isClosed()) {
                try {
                    socket.close();
                } catch (IOException e) {
                    System.err.println("Error closing socket: " + e.getMessage());
                }
            }
        }
    }

    public void displayTime() {
        try {
            String time = getTime();
            System.out.println("Current server time: " + time);
        } catch (IOException e) {
            System.err.println("Error getting time from server: " + e.getMessage());
            e.printStackTrace();
        }
    }

    public static void main(String[] args) {
        String host = "localhost";
        int port = 8080;

        if (args.length >= 2) {
            host = args[0];
            try {
                port = Integer.parseInt(args[1]);
            } catch (NumberFormatException e) {
                System.err.println("Invalid port number, using default: " + port);
            }
        } else if (args.length == 1) {
            try {
                port = Integer.parseInt(args[0]);
            } catch (NumberFormatException e) {
                host = args[0];
            }
        }

        TimeClient client = new TimeClient(host, port);
        client.displayTime();
    }
}