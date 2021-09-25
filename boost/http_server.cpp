#include <iostream>
#include <string>
#include <memory>
#include <boost/asio.hpp>

class HttpConnection : public std::enable_shared_from_this <HttpConnection>
{
public:
    HttpConnection(boost::asio::io_context& io) : socket_(io) {}

    void Start() {
        auto p = shared_from_this();
        boost::asio::async_read_until(socket_, boost::asio::dynamic_buffer(request_), "\r\n\r\n", 
         [p, this](const boost::system::error_code& err, size_t len) {
             if (err) {
                 std::cout << "recv err: " << err.message() << std::endl;
                 return;
             }
             std::string first_line = request_.substr(0, request_.find("\r\n")); // should be like "GET / HTTP/1.0"
             std::cout << first_line << std::endl;
             // process the request ...

             char str[] = "HTTP/1.0 200 OK\r\n\r\n"
                "<html>hello from http server</html>";
            boost::asio::async_write(socket_, boost::asio::buffer(str), [p, str, this](const boost::system::error_code& err, size_t len){
                socket_.close();
            });
         });
    }

    boost::asio::ip::tcp::socket& Socket() {
        return socket_;
    }
private:
    boost::asio::ip::tcp::socket socket_;
    std::string request_;
};

class HttpServer
{
public:
    HttpServer(boost::asio::io_context& io, boost::asio::ip::tcp::endpoint ep)
        : io_(io), acceptor_(io_, ep)
        {}

    void Start() {
        auto p = std::make_shared<HttpConnection>(io_);
        acceptor_.async_accept(p->Socket(), [p, this](const boost::system::error_code& err){
            if (err) {
                std::cout << "accept error: " << err.message() << std::endl;
                return;
            }
            p->Start();
            Start();
        });
    }
private:
    boost::asio::io_context& io_;
    boost::asio::ip::tcp::acceptor acceptor_;
};

int main(int argc, const char* argv[]) {
    if (argc != 3) {
        std::cout << "usage: httpsvr ip port\n";
        return 0;
    }
    boost::asio::io_context io;
    boost::asio::ip::tcp::endpoint ep(boost::asio::ip::make_address(argv[1]), std::stoi(argv[2]));
    HttpServer server(io, ep);
    server.Start();
    io.run();
    return 0;
}