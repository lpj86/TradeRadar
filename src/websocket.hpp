#include <ixwebsocket/IXWebSocket.h>
#include <string>
#include "concurrentqueue.hpp"

//template <typename T>

class WebSocketReader {

    public:
        //WebSocketReader(std::string &url, ConcurrentQueue<T>& queue);
        WebSocketReader(std::string &url);
        ~WebSocketReader();
        //bool connect();
        void formatData();
        bool pushToQueue();
    
    private:
        ix::WebSocket webSocket;

};