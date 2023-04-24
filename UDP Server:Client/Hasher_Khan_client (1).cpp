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
#include <cstring>

using namespace std;

int main() {
    int client_socket, n;
    char buffer[1024];
    struct sockaddr_in server_address;
    socklen_t len = sizeof(server_address);

    // Get server host name and port number from user
    char host_name[100];
    int port_number;
    cout << "Enter server host name: ";
    cin >> host_name;
    cout << "Enter server port number: ";
    cin >> port_number;

    // Create UDP socket
    client_socket = socket(AF_INET, SOCK_DGRAM, 0);

    // Set server address
    bzero(&server_address, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port_number);
    inet_pton(AF_INET, host_name, &server_address.sin_addr);

    // Send message to server
    
    string licnum;
    cout << "Enter a car license plate number: ";
    cin >> licnum;
    const char *message = licnum.c_str();
    sendto(client_socket, (const char *)message, strlen(message), MSG_CONFIRM, (const struct sockaddr *)&server_address, sizeof(server_address));


    // Receive message from server
    bzero(buffer, sizeof(buffer));
    n = recvfrom(client_socket, (char *)buffer, sizeof(buffer), MSG_WAITALL, (struct sockaddr *)&server_address, &len);
    buffer[n] = '\0';
    if(licnum == "killsvc"){
      cout << buffer << endl;
    }else{
      cout << message << buffer << endl;
      }

    // Close the socket
    close(client_socket);

    return 0;
}