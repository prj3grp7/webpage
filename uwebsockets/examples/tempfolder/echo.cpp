#include <iostream>
#include <string_view>
#include <uWS/uWS.h>

int main()
{
    uWS::Hub h;

    h.onMessage([](uWS::WebSocket<uWS::SERVER> *ws, char *message, size_t length, uWS::OpCode opCode) {
        std::cout << "Data: " << std::string_view(message, length) << std::endl;
        ws->send(message, length, opCode);
    });

    if (h.listen(3000)) {
        h.run();
    }
}
