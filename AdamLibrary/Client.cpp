//#include <iostream>
//#include <WS2tcpip.h>
//
//#pragma comment(lib, "ws2_32.lib") // ?
//
//#include "Client.h"
//
//#define DEF_PORT Network::Client::DEFAULT_PORT;
//
//using namespace std;
//using namespace Network;
//
//// initialize winsock
//// create a socket
//// bind the socket to an ip address & port
////// 
////void Network::Client::connect(int* port){
////	int sockfd = socket(AF_INET, SOCK_STREAM, IP); // ipV4
////}
//////
//////void Client::close(int* port) {
////	int sockfd = socket(AF_INET, SOCK_STREAM, IP); // ipV4
////}
//
//#include <iostream>
//#include <WS2tcpip.h>
//
//#pragma comment(lib, "ws2_32.lib") // ?
//
//#include "Server.h"
//
//#define DEF_PORT Network::Server::DEFAULT_PORT
//
//using namespace std;
//using namespace Network;
////
////void Network::Server::connect(int* port) {
////	int sockfd = socket(AF_INET, SOCK_STREAM, IP); // ipV4
////}
////
////void Server::close(int* port) {
////	int sockfd = socket(AF_INET, SOCK_STREAM, IP); // ipV4
////}
//
///*
//code with a help from: https://www.youtube.com/watch?v=WDn-htpBlnU
//*/
//int main(void) {
//	// initialize winsock
//	WSADATA wsData; // structure
//	WORD ver = MAKEWORD(2, 2);
//	int wsOk = WSAStartup(ver, &wsData);
//	if (wsOk != 0) {
//		cerr << "Can't Initialize Winsock! Quitting" << std::endl;
//		return 0;
//	}
//	// create a socket
//	SOCKET serverSoc = socket(AF_INET, SOCK_STREAM, 0); // AF_INET6 for ipV6 , AF_INET for ipV4
//	if (serverSoc == INVALID_SOCKET) {
//		cerr << "Can't create a socket! Quitting" << std::endl;
//		return 0;
//	}
//	// bind the ip address & port to a socket
//	/*networking is big endian, pc's are little endian*/
//	sockaddr_in hint;
//	hint.sin_family = AF_INET;
//	hint.sin_port = htons(DEF_PORT); // htons - host to network short
//	hint.sin_addr.S_un.S_addr = INADDR_ANY; // could also use inet_pton
//
//	//bind(listening, (sockaddr*)(&hint), sizeof(hint)); // (sockaddr*)&hint
//	// tell Winsock the socket is for listening
//	//listen(listening, SOMAXCONN);
//	// wait for a connection
//	sockaddr_in client;
//	int clientSize = sizeof(client);
//
//	int clientsocket = connect(serverSoc, (sockaddr*)(&hint), sizeof(hint)); // (sockaddr*)(&client)
//	/*if(clientsocket == INVALID_SOCKET) do something, handle situation*/
//
//	char host[NI_MAXHOST]; // Client's remote name
//	char service[NI_MAXSERV]; // Service (i.e. port) the client is connected to
//
//	ZeroMemory(host, NI_MAXHOST); // same as memset(host, NI_MAXHOST)
//	ZeroMemory(service, NI_MAXSERV);
//
//	// DNS lookup on the client information
//	if (getnameinfo((sockaddr*)&client, sizeof(client), host, NI_MAXHOST, service, NI_MAXSERV, 0) == 0) {
//		cout << host << " connected on port " << service << endl;
//	}
//	else {
//		inet_ntop(AF_INET, &client.sin_addr, host, NI_MAXHOST); // get ip address
//		cout << host << " connected on port " << ntohs(client.sin_port) << endl;
//	}
//	// close listening socket
//	//closesocket(listening);
//	// while(true) accept & echo message back to client
//	char buffer[4096] = "hellow my dear server\n"; // 4k , should be maximum amount possible
//	//while (true) { // 1
//		ZeroMemory(buffer, sizeof(buffer));
//		// wait for client to send data
//		//int bytesReceived = recv(clientsocket, buffer, sizeof(buffer), 0);
//		//if (bytesReceived == SOCKET_ERROR) {
//		//	cerr << "Error in recv(). Quitting" << endl;
//		//	//break;
//		//}
//		//if (bytesReceived == 0) {
//		//	cout << "client disconnected" << endl;
//		//	//break;
//		//}
//		// echo message back to client
//		/*when we recive a message the terminating zero (null character) is not in the message, because of that we need +1*/
//		int charNum = send(clientsocket, buffer, sizeof(buffer) + 1, 0); // charNum - number of characters(bytes) that where sent
//	//}
//	// close the sock
//	closesocket(clientsocket);
//	// shutdown Winsock
//	WSACleanup();
//	return 0;
//}