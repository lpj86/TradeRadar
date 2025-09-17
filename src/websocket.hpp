#include <ixwebsocket/IXWebSocket.h>
#include <string>
#include "concurrentqueue.hpp"

class WebSocketReader {

    public:
        WebSocketReader(std::string &url, ConcurrentQueue& queue);
        bool connect();
        void formatData();
        bool insertIntoQueue();
    
    private:


};