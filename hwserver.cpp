#include <zmq.h>
#include <iostream>

int main(int argc, char** argv) {
   void* context = zmq_ctx_new();
   void* responder = zmq_socket(context, ZMQ_REP);
   int rc = zmq_bind(responder, "tcp://*:35555");
   
   while (true) {
      char buffer[10];
      zmq_recv(responder, buffer, 10, 0);
      std::cout << "Received hello" << std::endl;
      zmq_send(responder, "World", 5, 0);
   }

   return 0;
}

