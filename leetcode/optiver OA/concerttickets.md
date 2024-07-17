As a long time live-music fan you have kept a bucket list of concerts you want to see. you have the means to buy as many concert tickets as you want. however, due to scalpers and resllers you struggle to actually score online tickets for a reasonable price. Thankfully a friend has alerted you to a service called BuyFirst which streams real-time data about freshly available concert tickets before anybody else. BuyFirst provides a binary data stream for fast access to their data.

You have decided to use your programming skills to sucessfully get concert tickets. Your bucket list has concerts for the artists you want to see at various locations. As an avid music fan, you're happy to see the same artist in multiple locations since they will play different sets. You also decided that you are willing to pay up to a certain ticket price, but no more. you also want a minimum seating category since you don't want to be stuck in the nosebleeds. Finally, concerts are only worth going to with friends. so you want to buy a certain number of available seats per concert. 
BuyFirst will stream AvailableTicket messages on their data feed. BuyFirst also provides an API to submit an Order to buy a ticket. Your objective is to write a program to listen on available tickets, and submit buy orders for tickets that match your criteria as soon as they become available.
Assume that:
   - there is no date/time collisions between concerts
   - you have sufficient funds to buy all the tickets matching your bucket list criteria.
Format of AvailableTicket messages
Messages from BuyFirst are not received as a whole, but packet by packet:
- packet1: message_id(4 bytes)artist_id(4bytes)
- packet2: message_id(4 bytes)location_id(4bytes)
- packet3: message_id(4 bytes)ticket_price(4bytes)
- packet4: message_id(4 bytes)category(4bytes)
- packet5: message_id(4 bytes)available_seats(4bytes)

Note the following for above messages
- the message_id is the same for all packets of same message
- the message_id is unique for each message and will not be reused
- the ordering of packets within a message is guaranteed(i.e. for a give message_id the first packet contains the artist_id, the second packet contains the location_id etc)
- once BuyFirst is streaming data from multiple sources, message packets may arrive in arbitrarily interleaved fashion. eg. you may receive the first packet of message 1, then first packet of message 2, second packet of message 2, then the second packet of message 1 etc.

Format of Order messages
When ordering tickets the message for doing so is also sent packet by packet:
- packet 1: original_message_id(4 bytes)
- packet 2: number_of_seats(4bytes)
These packets are sent continuously. they cannot be interleaved.


your task is implement the following functions:

Function Description
Your task is to implement the following functions:

OnNewRequirement(artist, location, ticket_price, category, available_seats):

This is called when a requirement is added and its parameters correspond to the fields of the AvailableTicket message.

Returns:

void
ProcessData(messageId, data):

This is called for every incoming packet of AvailableTicket message, and has the following parameters:

messageId - message identifier; 0 means "no data"
data - data payload corresponding to the ticket for messageId. It will indicate one of the artist_id, location_id, ticket_price, category, available_seats when the messageId is not 0
Returns:

data - uint_32_t type of the Order data packet to send, or 0 if there is nothing to send
The following applies to match a requirement against an AvailableTicket:

the ticket's artist_id is equal to the required artist_id
the ticket's location_id is equal to the required location_id
the ticket's ticket_price is lower than or equal to the required ticket_price
the ticket's category is higher than or equal to the required category
the ticket's available_seats is higher than or equal to the required available_seats
When sending an order, note that:

only one order can be sent per AvailableTicket message
the order must reference the message_id of the AvailableTicket message you want to buy in the original_message_id field
when returning order packets from ProcessData(): if a valid/nonzero original_message_id packet has been returned, then the number_of_seats packet must be returned from the next immediate call to complete the order
to keep things simple: a single requirement can only be fulfilled against a single AvailableTicket
requirements must be fulfilled as soon as possible
if multiple requirements can be fulfilled, the you must fulfill the last requirement given to you
newly received requirements cannot be fulfilled against already received or old AvailableTicket messages, since the buying opportunity is assumed to be gone
a requirement can be fulfilled before all packets of AvailableTicket message have arrived
Constraints

0 <= message_id < 2^32
0 <= artist_id < 2^32
0 <= location_id < 2^32
0 <= ticket_price < 2^32
0 <= category < 2^32
1 <= available_seats < 2^32
Sample Input
Input to the program is specified using a simple text format. The format and details of parsing are not relevant to answering the question. Custom input can be used to help with development and debugging.

The first line specifies the number of REQUIREMENT and DATA as follows:

REQUIREMENT [artist_id] [location_id] [ticket_price] [category] [available_seats]
corresponds to the method OnNewRequirement()
DATA [message_id] [data]
corresponds to the method ProcessData()
message_id=0 indicates that there is no valid data
16
REQUIREMENT 1 1 100 1 2
DATA 1 1
DATA 1 1
DATA 1 110
DATA 1 3
DATA 0 0
DATA 2 1
DATA 2 1
DATA 2 90
DATA 2 3
DATA 2 3
DATA 0 0
DATA 0 0
DATA 0 0
DATA 0 0
Sample Output
0
0
0
0
0
0
0
0
0
0
2
2
0
0
0
Explanation

The message with id 1 does not fulfill the requirement because the price of 110 is higher than the required 100. The message with id 2 does fulfill the requirement. The requirements is fulfilled once the number of available seats is received, so an order message for original message id 2 and 2 seats (as per requirement) is sent. At all other times, no message is being send (0).
