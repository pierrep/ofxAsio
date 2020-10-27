#include "UdpReceiver.h"
#include "ofMain.h"

using namespace ofxAsio;
using namespace ofxAsio::udp;

std::shared_ptr<UdpReceiver> UdpReceiver::make(int port) {
	std::shared_ptr<UdpReceiver> receiver(new UdpReceiver(port));
	return receiver;
}

std::shared_ptr<UdpReceiver> UdpReceiver::make(std::string localAddress, int port) {
	std::shared_ptr<UdpReceiver> receiver(new UdpReceiver(localAddress, port));
	return receiver;
}

UdpReceiver::UdpReceiver(int port) : UdpSocket(port) {
}

UdpReceiver::UdpReceiver(std::string localAddress, int port) : UdpSocket(localAddress, port) {

}

UdpReceiver::~UdpReceiver() {

}

void UdpReceiver::start() {
    ofLogVerbose() << "ofxAsio::sockets::UdpReceiver -- listening for messages at " << mLocalEndpoint.getIpAddress().c_str()<< ":" << mLocalEndpoint.getPort();
	receive();
}
