#include <ixwebsocket/IXWebSocket.h>
#include <iostream>
#include "websocket.hpp"
#include <string>




WebSocketReader::WebSocketReader(std::string &url)
{
    std::cout<<"constructor loaded " << url;
    auto &ws = webSocket;
    webSocket.setUrl(url);
    std::cout<<"websocket loaded " << &ws;

    webSocket.setOnMessageCallback(
        [&ws](const ix::WebSocketMessagePtr& msg)
        {
            if (msg->type == ix::WebSocketMessageType::Open)
            {
                std::cout << "Koblet til: " << msg->openInfo.uri << std::endl;
                // Send melding via webSocket-objektet
                //ws.send("Hei fra IXWebSocket med TLS!");
            }
            else if (msg->type == ix::WebSocketMessageType::Message)
            {
                std::cout << "Mottatt melding: " << msg->str << std::endl;
            }
            else if (msg->type == ix::WebSocketMessageType::Error)
            {
                std::cerr << "Feil: " << msg->errorInfo.reason << std::endl;
            }
            else if (msg->type == ix::WebSocketMessageType::Close)
            {
                std::cout << "Forbindelsen lukket." << std::endl;
            }
        }
    );

    // Start WebSocket
    webSocket.start();    

    std::cin.get();
    webSocket.stop();
}

WebSocketReader::~WebSocketReader()
{
    
    std::cout << "Destructor call" << std::endl;
}

/*int main()
{
        //ix::WebSocket webSocket;

    // Sett TLS URL (wss://)
    

    // Callback for meldinger og hendelser


    std::cout << "Trykk Enter for å avslutte..." << std::endl;
    std::cin.get();

    webSocket.stop();
    return 0;
}*/