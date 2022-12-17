#include <websocketpp/client.hpp>
#include <websocketpp/config/asio_client.hpp>

using Client = websocketpp::client<websocketpp::config::asio_tls_client>;
using ConnectionHdl = websocketpp::connection_hdl;
using SslContext = websocketpp::lib::asio::ssl::context;
using websocketpp::lib::placeholders::_1;
using websocketpp::lib::placeholders::_2;

/*
 * This handler is for initialize TLS connection
 */
websocketpp::lib::shared_ptr<SslContext> on_tls_init() {
	auto ctx = websocketpp::lib::make_shared<SslContext>(boost::asio::ssl::context::sslv23);
	return ctx;
}

/*
 *
 */
void on_open(Client* client, ConnectionHdl hdl) {
	// "{\"action\":\"sub\",\"subscriptions\":[{\"channel\":\"book\",\"market\":\"btctwd\",\"depth\":1},{\"channel\":\"trade\",\"market\":\"btctwd\"}],\"id\":\"client1\"}"
	std::string msg{"{\"action\":\"sub\",\"subscriptions\":[{\"channel\":\"book\",\"market\":\"btctwd\",\"depth\":1},{\"channel\":\"trade\",\"market\":\"btctwd\"}],\"id\":\"client1\"}"};
	std::cout << "on_open: send " << msg << std::endl;
	client->send(hdl, msg, websocketpp::frame::opcode::text);
}

void on_fail(Client* client, websocketpp::connection_hdl hdl) {
	std::cout << "on_fail" << std::endl;
	client->get_alog().write(websocketpp::log::alevel::app, "Connection Failed");
}

void on_close(Client* client, websocketpp::connection_hdl hdl) {
	std::cout << "on_close" << std::endl;
	client->get_alog().write(websocketpp::log::alevel::app, "Connection Closed");
}

/*
 *
 */
void on_message(Client* client, ConnectionHdl hdl, websocketpp::config::asio_client::message_type::ptr msg) {
	std::cout << "on_message: " << msg->get_payload() << std::endl;
}

int main(int argc, char* argv[]) {
	std::string uri = "wss://max-stream.maicoin.com:443/ws";
	Client c;
	
	try {
		/* set logging policy if needed */
		c.clear_access_channels(websocketpp::log::alevel::frame_header);
		c.clear_access_channels(websocketpp::log::alevel::frame_payload);
		// c.clear_access_channels(websocketpp::log::alevel::all);
		// c.clear_error_channels(websocketpp::log::elevel::all);
		
		/* Initialize ASIO */
		c.init_asio();
		
		/* Register handlers */
		c.set_tls_init_handler(bind(&on_tls_init));
		c.set_open_handler(bind(&on_open, &c, ::_1));
		c.set_fail_handler(bind(&on_fail, &c, ::_1));
		c.set_message_handler(bind(&on_message, &c, ::_1, ::_2));
		c.set_close_handler(bind(&on_close, &c, ::_1));
		
		// Create a connection to the given URI and queue it for connection once
		// the event loop starts
		websocketpp::lib::error_code ec;
		Client::connection_ptr con = c.get_connection(uri, ec);
		c.connect(con);
		
		/* Start the ASIO io_service run loop */
		c.run();
	} catch (const std::exception & e) {
		std::cerr << e.what() << std::endl;
	} catch (websocketpp::lib::error_code e) {
		std::cerr << e.message() << std::endl;
	} catch (...) {
		std::cerr << "Other Exception" << std::endl;
	}
}

/**********************************************/

/*
 * To close the connection:
 * client->close(hdl, websocketpp::close::status::normal, "done");
 */
