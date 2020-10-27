# ofxAsio

A wrapper to simplify using the Asio library for asynchronous networking in openFrameworks. 

## Requirements

### Linux
This code has been tested using openFrameworks 0.11.0 on Ubuntu 20.04
You'll need to add the Asio library to your system, e.g. "sudo apt install libasio-dev". Use the supplied qtCreator projects, or just type 'make'.

### Windows
This project is currently not configured for Windows but should work with some configuration. Happy to take pull requests.

### OSX
This project is currently not configured for MacOS but should work with some configuration. Happy to take pull requests.

## Usage
`ofxAsio` is a a relatively minimal wrapper around the Asio library to try to make networking easier.  There are two main classes, one for sending UDP messages (`UdpSender`) and one for receiving UDP messages (`UdpReceiver`).

Both should be created as such:

     std::shared_ptr<ofxAsio::UdpSender> mUdpSender = std::make_shared<ofxAsio::UdpSender>();
     std::shared_ptr<ofxAsio::UdpReceiver> mUdpReceiver = std::make_shared<ofxAsio::UdpReceiver>("0.0.0.0", 8080);
     
For both classes, you'll need to familiarize yourself with the `Datagram` class.  A datagram is the combination of a udp message and an endpoint; in `ofxAsio` we've encapsulated the endpoint as an `Endpoint` class that contains an IP address and a port number.  The message itself lives in the `Datagram` class, represented as a `std::vector`.

The `Datagram` class is meant to be versatile to meet most possible needs, which means that it should be able to accept strings as the message, but it should also be able to accept data packets (which would typically be buffers of `unsigned char`, or bytes).  As such, `Datagram` has several ways to set the message:

    void setData(char* data, std::size_t length);
    void setData(std::string message);
    void setData(std::vector<unsigned char> data);

All three accepted data types (`char*`, `std::vector<unsigned char>`, and `std::string`) are also accepted in the constructor.

In addition, just like a normal `std::vector`, you can `push_back()` into the `Datagram`, as well as get an iterator with `begin()` and `end()`.

Both `UdpSender` and `UdpReceiver` send and receive asynchronously, so the preferred way to deal with the results is to use callbacks.  With both classes you can attach a function callback that accepts a `std::shared_ptr<Datagram>` via the functions `addOnReceiveFn()` and `addOnSendFn()`.  If you're not sure what I'm talking about, check out the examples.

## Examples
* `example-udpSender` shows how to send messages repeatedly.
* `example-udpReceiver` shows how to asynchronously wait for and print messages.
* `example-tcpClient` shows an asynchronous sending of Tcp messages.
* `example-tcpServer` shows asynchronous receipt of messages with callbacks.

## More Information
* [Asio Homepage](http://think-async.com/)
