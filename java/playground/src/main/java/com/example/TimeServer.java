package com.example;

import java.io.IOException;
import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;

public class TimeServer {

    public static class Handler implements Runnable {

        private final Socket socket;

        public Handler(Socket socket) {
            this.socket = socket;
        }

        @Override
        public void run() {
            try {

                String currentTime = LocalDateTime.now().format(DateTimeFormatter.ofPattern("yyyy-MM-dd HH:mm:ss"));

                PrintWriter out = new PrintWriter(socket.getOutputStream(), true);
                out.println(currentTime);

                socket.close();

                System.out.println("Sent time to client: " + currentTime);
            } catch (IOException e) {
                System.err.println("Error handling client connection: " + e.getMessage());
                e.printStackTrace();
            }
        }
    }

    private final int port;

    private final ServerSocket serverSocket;

    public TimeServer(int port) throws IOException {
        this.port = port;
        this.serverSocket = new ServerSocket(port);
    }

    public void start() {
        System.out.println("TimeServer starts listening on port: " + port);
        try {
            while (true) {
                Socket socket = serverSocket.accept();
                System.out.println("New client connected: " + socket.getRemoteSocketAddress());

                Thread thread = new Thread(new Handler(socket));
                thread.start();
            }
        } catch (IOException e) {
            System.err.println("Server error: " + e.getMessage());
            e.printStackTrace();
        } finally {
            stop();
        }
    }

    public void stop() {
        try {
            if (serverSocket != null && !serverSocket.isClosed()) {
                serverSocket.close();
                System.out.println("TimeServer stopped.");
            }
        } catch (IOException e) {
            System.err.println("Error closing server socket: " + e.getMessage());
        }
    }

    public static void main(String[] args) {
        int port = 8080;
        if (args.length > 0) {
            try {
                port = Integer.parseInt(args[0]);
            } catch (NumberFormatException e) {
                System.err.println("Invalid port number, using default: " + port);
            }
        }

        try {
            TimeServer server = new TimeServer(port);
            server.start();
        } catch (IOException e) {
            System.err.println("Could not start server on port " + port + ": " + e.getMessage());
            e.printStackTrace();
        }
    }
}
