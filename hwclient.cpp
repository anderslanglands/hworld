#include <zmq.h>
#include <iostream>

int main(int argc, char** argv) {
   std::cout << "Connecting to hello world server..." << std::endl;
   void* context = zmq_ctx_new();
   void* requester = zmq_socket(context, ZMQ_REQ);
   zmq_connect(requester, "tcp://135.19.24.125:35555");

   for (int request_nbr = 0; request_nbr < 10; request_nbr++) {
      char buffer[10];
      std::cout << "Sending hello " << request_nbr << "..." << std::endl;
      zmq_send(requester, "Hello", 5, 0);
      zmq_recv(requester, buffer, 10, 0);
      std::cout << "Received world " << request_nbr << std::endl;
   }
   zmq_close(requester);
   zmq_ctx_destroy(context);
   return 0;
}
