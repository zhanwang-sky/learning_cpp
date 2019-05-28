#include "msg.h"

// Class Folder
Message::Message(const Message &orig):
    _contents(orig._contents), _folders(orig._folders) {
    _add_to_Folders(orig);
}

Message&
Message::operator=(const Message &rhs) {
    _remove_from_Folders();
    _contents = rhs._contents;
    _folders = rhs._folders;
    _add_to_Folders(rhs);
    return *this;
}

Message::~Message() {
    _remove_from_Folders();
}

void
Message::save(Folder &f) {
    _folders.insert(&f);
    f.addMsg(this);
}

void
Message::remove(Folder &f) {
    _folders.erase(&f);
    f.remMsg(this);
}

void
Message::_add_to_Folders(const Message &m) {
    for (auto f : m._folders) {
        f->addMsg(this);
    }
}

void
Message::_remove_from_Folders() {
    for (auto f : _folders) {
        f->remMsg(this);
    }
}

// Class Folder
void
Folder::addMsg(Message *p) {
    _messages.insert(p);
}

void
Folder::remMsg(Message *p) {
    _messages.erase(p);
}
