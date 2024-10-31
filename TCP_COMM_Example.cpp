#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <boost/asio.hpp>

void send_request(const std::string& ip, int port) {
    using boost::asio::ip::tcp;

    try {
        boost::asio::io_context io_context;

        // TCP socket létrehozása
        tcp::socket socket(io_context);
        tcp::resolver resolver(io_context);
        auto endpoints = resolver.resolve(ip, std::to_string(port));

        // Kapcsolódás
        boost::asio::connect(socket, endpoints);

        // Küldjük a "*ASK\r\n" üzenetet
        std::string request = "*ASK\r\n";
        boost::asio::write(socket, boost::asio::buffer(request));

        // Válasz olvasása
        char response[1024];
        size_t length = socket.read_some(boost::asio::buffer(response));
        
        // A válasz stringgé alakítása
        std::string response_str(response, length);

        // Válasz feldolgozása
        std::cout << "Received response: " << response_str << std::endl;

        // Értékek tárolása vektorban
        std::vector<std::string> values;
        std::stringstream ss(response_str);
        std::string item;

        while (std::getline(ss, item, ',')) {
            values.push_back(item);
        }

        // Kiírás a vektor tartalmáról
        std::cout << "Values in array:" << std::endl;
        for (const auto& value : values) {
            std::cout << value << std::endl;
        }

    } catch (std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

int main() {
    std::string ip = "192.168.1.1";
    int port = 23;

    send_request(ip, port);

    return 0;
}
