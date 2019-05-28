#ifndef _MESSAGE_H
#define _MESSAGE_H

#include <string>
#include <set>

class Folder;

class Message {
    friend class Folder;
public:
    Message(const std::string &s = ""):
        _contents(s) { }
    Message(const Message&);
    Message& operator=(const Message&);
    ~Message();
    void save(Folder&);
    void remove(Folder&);
    std::string contents() { return _contents; }
private:
    void _add_to_Folders(const Message&);
    void _remove_from_Folders();
    std::string _contents;
    std::set<Folder*> _folders;
};

class Folder {
public:
    Folder() = default;
    ~Folder() = default;
    void addMsg(Message*);
    void remMsg(Message*);
private:
    std::set<Message*> _messages;
};

#endif // _MESSAGE_H
