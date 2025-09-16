#include "nlohmann/json.hpp"
#include <ixwebsocket/IXWebSocket.h>
#include <iostream>
//#include <IXWebSocket/ixwebsocket/IXWebSocket.h>

int main()
{
    ix::WebSocket webSocket;

    // Sett TLS URL (wss://)
    webSocket.setUrl("wss://echo.websocket.org");

    // Callback for meldinger og hendelser
    webSocket.setOnMessageCallback(
        [&webSocket](const ix::WebSocketMessagePtr& msg)
        {
            if (msg->type == ix::WebSocketMessageType::Open)
            {
                std::cout << "Koblet til: " << msg->openInfo.uri << std::endl;
                // Send melding via webSocket-objektet
                webSocket.send("Hei fra IXWebSocket med TLS!");
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

    std::cout << "Trykk Enter for å avslutte..." << std::endl;
    std::cin.get();

    webSocket.stop();
    return 0;

}