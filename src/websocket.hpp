#include <ixwebsocket/IXWebSocket.h>
#include <string>

class WebSocketReader {

    public:
        WebSocketReader(std::string &url);
        bool connect();
        void formatData();
    
    private:


};