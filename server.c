
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/time.h>
#include "libpq-fe.h"
#define PORT 7777

#define BUFSIZE 4096
char *dbs = "./DataBase/DB.ods";

void insert_details(char data[1024]){
	
	FILE *db;
	db = fopen(dbs, "a+");
	if(db==NULL){
	printf("error dbs\n");
	}
	fprintf(db, "%s", data);
	fclose(db);
	
}


void display_client(){

	FILE *db;
	db = fopen(dbs, "r");
	char line[2048];
	int in=0;
	char *token;
	if(db==NULL){
		printf("ERROR\n");
	}
	char *client_id; 
	char *full_name; 
	char *addr_live; 
	char *phone_number; 
	char *email; 
	char *region;
	char *gr_fml_al; 
	char *package; 
	char *date_visit;
	char *date_create;
	while(fgets(line, sizeof(line), db)){		
			if(in!=0){
			token = strtok(line, ",");
			client_id = token;
		
			token = strtok(NULL, ",");
			full_name = token;
			
			token = strtok(NULL, ",");
			addr_live = token;
			
			token = strtok(NULL, ",");
			phone_number = token;
			
			token = strtok(NULL, ",");
			email = token;
			
			token = strtok(NULL, ",");
			region = token;
			
			token = strtok(NULL, ",");
			gr_fml_al = token;
			
			token = strtok(NULL, ",");
			package = token;
			
			token = strtok(NULL, ",");
			date_visit = token;
			
			token = strtok(NULL, ",");
			date_create = token;
			printf("%s | %s | %s | %s | %s | %s | %s | %s | %s | %s\n", client_id, full_name, addr_live, phone_number, email, region, gr_fml_al, package, date_visit, date_create);
			}
			in++;
			
	}
	memset(line, 0, sizeof(line));
	fclose(db);
}


void send_to_all(int j, int i, int sockfd, int nbytes_recvd, char *recv_buf, fd_set *master)
{
	if (FD_ISSET(j, master)){
		if (j != sockfd && j != i) {
			if (send(j, recv_buf, nbytes_recvd, 0) == -1) {
				perror("send");
				}
			}
		}
	}

	char send_buf[BUFSIZE];
	void send_recv(int i, fd_set *master, int sockfd, int fdmax)
	{

		int nbytes_recvd, j;
		char recv_buf[BUFSIZE], buf[BUFSIZE];

		if ((nbytes_recvd = recv(i, recv_buf, BUFSIZE, 0)) <= 0) {
			if (nbytes_recvd == 0) {
				printf("socket %d hung up\n", i);
			}
			else {
				perror("recv");
			}
			close(i);
			FD_CLR(i, master);
		}
		else { 
			recv_buf[nbytes_recvd] = '\0';


			printf("%s\n", recv_buf);

			for(j = 0; j <= fdmax; j++){
				send_to_all(j, i, sockfd, nbytes_recvd, recv_buf, master );
			}
			fflush(stdout);
		}  
	}

	void connection_accept(fd_set *master, int *fdmax, int sockfd, struct sockaddr_in *client_addr)
	{
		socklen_t addrlen;
		int newsockfd;

		addrlen = sizeof(struct sockaddr_in);
		if((newsockfd = accept(sockfd, (struct sockaddr *)client_addr, &addrlen)) == -1) {
			perror("accept");
			exit(1);
		}
		else {
			FD_SET(newsockfd, master);
			if(newsockfd > *fdmax){
			*fdmax = newsockfd;
			}
		printf("new connection from %s on port %d \n",inet_ntoa(client_addr->sin_addr), ntohs(client_addr->sin_port));
		}
		send(newSocket, "1", sizeof("1"), 0);
	}

	void connect_request(int *sockfd, struct sockaddr_in *my_addr)
	{
		int yes = 1;

		if ((*sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
		perror("Socket");
		exit(1);
	}

	my_addr->sin_family = AF_INET;
	my_addr->sin_port = htons(7777);
	my_addr->sin_addr.s_addr = INADDR_ANY;
	memset(my_addr->sin_zero, '0', sizeof my_addr->sin_zero);

	if (setsockopt(*sockfd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int)) == -1) {
		perror("setsockopt");
		exit(1);
	}

	if (bind(*sockfd, (struct sockaddr *)my_addr, sizeof(struct sockaddr)) == -1) {
		perror("Unable to bind");
		exit(1);
	}
	if (listen(*sockfd, 10) == -1) {
		perror("listen");
		exit(1);
	}
	printf("\nTCPServer Waiting for client on port %d\n",PORT);
	fflush(stdout);
	}

	int main(){

	int sockfd, ret;
	struct sockaddr_in serverAddr;

	int newSocket;
	struct sockaddr_in newAddr;

	socklen_t addr_size;

	char buffer[1024];
	pid_t childpid;

	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if(sockfd < 0){
		printf("[-]Error in connection.\n");
		exit(1);
	}
	printf("[+]Server Socket is created.\n");

	memset(&serverAddr, '\0', sizeof(serverAddr));
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(PORT);
	//serverAddr.sin_addr.s_addr = inet_addr("87.237.236.162:4444");
	serverAddr.sin_addr.s_addr = INADDR_ANY;

	ret = bind(sockfd, (struct sockaddr*)&serverAddr, sizeof(serverAddr));
	if(ret < 0){
		printf("[-]Error in binding.\n");
		exit(1);
	}
	printf("[+]Bind to port %d\n", 7777);

	if(listen(sockfd, 10) == 0){
		printf("[+]Listening....\n");
	}
	else{
		printf("[-]Error in binding.\n");
	}
	int k=0;
	int l=0;
	while(1){
		int count=0;
		bzero(buffer, sizeof(buffer));
		newSocket = accept(sockfd, (struct sockaddr*)&newAddr, &addr_size);
		if(newSocket < 0){
			exit(1);
		}
		printf("Connection accepted from %s:%d\n", inet_ntoa(newAddr.sin_addr), ntohs(newAddr.sin_port));
		k++;
		if((childpid = fork()) == 0){
		//close(sockfd);
			l++;
			int in =5;
		//while(in){
			k++;
			l++;
			recv(newSocket, buffer, sizeof(buffer), 0);
			if(strcmp(buffer, ":exit") == 0){
				printf("Disconnected from %s:%d\n", inet_ntoa(newAddr.sin_addr), ntohs(newAddr.sin_port));
				break;
			} 
			else
				{
				printf("Client: %s \t \n", buffer);
				insert_details(buffer);
				}
				
			in--;

			//}
			
		}
	}



return 0;
}
