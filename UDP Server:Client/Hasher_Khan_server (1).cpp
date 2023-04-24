/*
Hasher Khan
COSC 3360-10716
UHID: 2089907
*/

#include <bits/stdc++.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <fstream>
#include <vector>
#include <cstring>

using namespace std;

int main() {
    int server_socket, n;
    char buffer[1024];
    struct sockaddr_in server_address, client_address;
    socklen_t len = sizeof(client_address);

    string filename;
    cout << "Enter today's stolen car DB name: ";
    cin >> filename;
  
    int port_number;
    cout << "Enter server port number: ";
    cin >> port_number;
    
    ifstream file(filename);
    vector<string> database;
    string licNum;
    while (file >> licNum) {
        database.push_back(licNum);
    }

    // Create UDP socket
    server_socket = socket(AF_INET, SOCK_DGRAM, 0);

    // Set server address
    bzero(&server_address, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(port_number);

    // Bind the socket to the server address
    bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address));

    // Get the port number
    getsockname(server_socket, (struct sockaddr *)&server_address, &len);

    bool kill = true;

    while(kill){

      bzero(buffer, sizeof(buffer));
      n = recvfrom(server_socket, (char *)buffer, sizeof(buffer), MSG_WAITALL, (struct sockaddr *)&client_address, &len);
        buffer[n] = '\0';

        // Check if client wants to terminate the server
      if (strcmp(buffer, "killsvc") == 0) {
        cout << "Recieved request to terminate the server." << endl << "Bye!" << endl;
        const char *message = "Client terminates. Bye!";
        sendto(server_socket, (const char *)message, strlen(message), MSG_CONFIRM, (const struct sockaddr *)&client_address, len);
        break;
      }
      
      int check = 0;
      for(int i = 0; i < database.size(); i++){
        if(database[i] == buffer){
          check = 1;
        }
      }
      if(check == 1){
        cout << buffer << ": Reported as stolen" << endl;
        const char *message = ": Reported as stolen";
        sendto(server_socket, (const char *)message, strlen(message), MSG_CONFIRM, (const struct sockaddr *)&client_address, len);
      }
      else{
        cout << buffer << ": Not in database." << endl;
        const char *message = ": Not in database.";
        sendto(server_socket, (const char *)message, strlen(message), MSG_CONFIRM, (const struct sockaddr *)&client_address, len);
      }
    }

    // Close the socket
    close(server_socket);

    return 0;
}
