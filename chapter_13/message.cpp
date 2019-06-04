#include <iostream>
#include "message.h"

using std::cout;
using std::endl;

// class Message
void swap(Message &lhs, Message &rhs) {
    using std::swap;
    for (auto f: lhs.folders) {
        f->remMsg(&lhs);
    }
    for (auto f: rhs.folders) {
        f->remMsg(&rhs);
    }
    swap(lhs.contents, rhs.contents);
    swap(lhs.folders, rhs.folders);
    for (auto f: lhs.folders) {
        f->addMsg(&lhs);
    }
    for (auto f: rhs.folders) {
        f->addMsg(&rhs);
    }
}

Message::Message(const std::string &str):
    contents(str) {
    cout << "Message::default constructor" << endl;
}

Message::Message(const Message &orig):
    contents(orig.contents), folders(orig.folders) {
    cout << "Message::copy constructor" << endl;
    add_to_folders(orig); // "*this" has not been constructed
}

Message&
Message::operator=(const Message &rhs) {
    cout << "Message::copy assignment operator" << endl;
    remove_from_folders();
    contents = rhs.contents;
    folders = rhs.folders;
    add_to_folders(rhs);
    return *this;
}

Message::~Message() {
    cout << "Message::destructor" << endl;
    remove_from_folders();
}

void
Message::save(Folder &f) {
    folders.insert(&f);
    f.addMsg(this);
}

void
Message::remove(Folder &f) {
    folders.erase(&f);
    f.remMsg(this);
}

void
Message::add_to_folders(const Message &m) {
    for (auto f : m.folders) {
        f->addMsg(this);
    }
}

void
Message::remove_from_folders() {
    for (auto f : folders) {
        f->remMsg(this);
    }
}

// class Folder
void
Folder::addMsg(Message *m) {
    cout << "addMsg(" << m << ")" << endl;
}

void
Folder::remMsg(Message *m) {
    cout << "remMsg(" << m << ")" << endl;
}
