#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <cstdint>

using namespace std;

struct Requirement {
    uint32_t artist_id;
    uint32_t location_id;
    uint32_t ticket_price;
    uint32_t category;
    uint32_t available_seats;
};

struct Ticket {
    uint32_t artist_id;
    uint32_t location_id;
    uint32_t ticket_price;
    uint32_t category;
    uint32_t available_seats;
    int index = 0;
    bool complete = false;
};

unordered_map<uint32_t, Ticket> tickets;
// vector<Requirement> requirements;
unordered_map<uint32_t, vector<Requirement>> requirements;
queue<uint32_t> orderQueue;
bool waitingForSeats = false;
uint32_t currentOrderMessageId = 0;

void OnNewRequirement(uint32_t artist_id, uint32_t location_id, uint32_t ticket_price, uint32_t category, uint32_t available_seats) {
    requirements[artist_id].push_back({artist_id, location_id, ticket_price, category, available_seats});
}

uint32_t ProcessData(uint32_t messageId, uint32_t data) {
    if (messageId == 0) {
        return 0;
    }

    if (tickets.find(messageId) == tickets.end()) {
        tickets[messageId] = Ticket();
    }

    Ticket& ticket = tickets[messageId];

    if (!ticket.complete) {
        int packetIndex = ticket.index;
        switch (packetIndex) {
            case 0: ticket.artist_id = data; break;
            case 1: ticket.location_id = data; break;
            case 2: ticket.ticket_price = data; break;
            case 3: ticket.category = data; break;
            case 4: ticket.available_seats = data; ticket.complete = true; break;
        }
        ticket.index++;
    }

    if (ticket.complete && !waitingForSeats) {
        if(requirements.find(ticket.artist_id) != requirements.end()) {
            for (auto it = requirements[ticket.artist_id].rbegin(); it != requirements[ticket.artist_id].rend(); ++it) {
                if (ticket.artist_id == it->artist_id &&
                    ticket.location_id == it->location_id &&
                    ticket.ticket_price <= it->ticket_price &&
                    ticket.category >= it->category &&
                    ticket.available_seats >= it->available_seats) {
                    orderQueue.push(messageId);
                    orderQueue.push(it->available_seats);
                    requirements[ticket.artist_id].erase(next(it).base());
                    currentOrderMessageId = messageId;
                    waitingForSeats = true;
                    return messageId;
                }
            }
        }
    }

    if (waitingForSeats && messageId == currentOrderMessageId) {
        waitingForSeats = false;
        return orderQueue.front();
    }

    return 0;
}

int main() {
    int n;
    cin >> n;
    string command;

    for (int i = 0; i < n; ++i) {
        cin >> command;
        if (command == "REQUIREMENT") {
            uint32_t artist_id, location_id, ticket_price, category, available_seats;
            cin >> artist_id >> location_id >> ticket_price >> category >> available_seats;
            OnNewRequirement(artist_id, location_id, ticket_price, category, available_seats);
        } else if (command == "DATA") {
            uint32_t messageId, data;
            cin >> messageId >> data;
            cout << ProcessData(messageId, data) << endl;
        }
    }

    return 0;
}
